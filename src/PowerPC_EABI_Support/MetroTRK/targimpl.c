#include "PowerPC_EABI_Support/MetroTRK/dstypes.h"
#include "PowerPC_EABI_Support/MetroTRK/trk.h"
#include "PowerPC_EABI_Support/MSL/MSL_C/stddef.h" // IWYU pragma: keep

typedef struct memRange {
    u8* start;
    u8* end;
    BOOL readable;
    BOOL writeable;
} memRange;

const memRange gTRKMemMap[1] = { { (u8*)0, (u8*)-1, TRUE, TRUE } };

typedef struct StopInfo_PPC {
    u32 PC;
    u32 PCInstruction;
    u16 exceptionID;
} StopInfo_PPC;
typedef struct TRKExceptionStatus {
    StopInfo_PPC exceptionInfo;
    u8 inTRK;
    u8 exceptionDetected;
} TRKExceptionStatus;
typedef struct TRKStepStatus {
    BOOL active;    // 0x0
    u8 type;        // 0x4
    u32 count;      // 0x8
    u32 rangeStart; // 0xC
    u32 rangeEnd;   // 0x10
} TRKStepStatus;

// Instruction macros
#define INSTR_NOP                                0x60000000
#define INSTR_BLR                                0x4E800020
#define DSFetch_u32(_p_)                         (*((u32*)_p_))
#define DSFetch_u64(_p_)                         (*((u64*)_p_))
#define INSTR_PSQ_ST(psr, offset, rDest, w, gqr) (0xF0000000 | (psr << 21) | (rDest << 16) | (w << 15) | (gqr << 12) | offset)
#define INSTR_PSQ_L(psr, offset, rSrc, w, gqr)   (0xE0000000 | (psr << 21) | (rSrc << 16) | (w << 15) | (gqr << 12) | offset)
#define INSTR_STW(rSrc, offset, rDest)           (0x90000000 | (rSrc << 21) | (rDest << 16) | offset)
#define INSTR_LWZ(rDest, offset, rSrc)           (0x80000000 | (rDest << 21) | (rSrc << 16) | offset)
#define INSTR_STFD(fprSrc, offset, rDest)        (0xD8000000 | (fprSrc << 21) | (rDest << 16) | offset)
#define INSTR_LFD(fprDest, offset, rSrc)         (0xC8000000 | (fprDest << 21) | (rSrc << 16) | offset)
#define INSTR_MFSPR(rDest, spr)                  (0x7C000000 | (rDest << 21) | ((spr & 0xFE0) << 6) | ((spr & 0x1F) << 16) | 0x2A6)
#define INSTR_MTSPR(spr, rSrc)                   (0x7C000000 | (rSrc << 21) | ((spr & 0xFE0) << 6) | ((spr & 0x1F) << 16) | 0x3A6)

ProcessorRestoreFlags_PPC gTRKRestoreFlags    = { FALSE, FALSE };
TRKExceptionStatus gTRKExceptionStatus = { { 0, 0, 0 }, TRUE, 0 };
TRKStepStatus gTRKStepStatus           = { FALSE, DSSTEP_IntoCount, 0, 0 };
u16 TRK_saved_exceptionID              = 0;
ProcessorState_PPC gTRKCPUState;
TRKState gTRKState;

u128 TRKvalue128_temp;

Default_PPC gTRKSaveState;
void TRKPostInterruptEvent(void);
void TRKExceptionHandler(u16 a);
void TRKUARTInterruptHandler(void);
void TRKInterruptHandlerEnableInterrupts(void);
DSError TRKPPCAccessSPR(void*, u32, BOOL);
DSError TRKPPCAccessPairedSingleRegister(void*, u32, BOOL);
DSError TRKPPCAccessFPRegister(void*, u32, BOOL);
DSError TRKPPCAccessSpecialReg(void*, u32*, BOOL);

static BOOL TRKTargetCheckStep();

asm u32 __TRK_get_MSR() {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mfmsr r3
        blr
    #endif // clang-format on
}

asm void __TRK_set_MSR(register u32 msr)
{
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtmsr msr
        blr
    #endif // clang-format on
}

DSError TRKValidMemory32(const void* addr, size_t length, ValidMemoryOptions readWriteable)
{
    DSError err = DS_InvalidMemory; /* assume range is invalid */
    const u8* start = (const u8*)addr;
    const u8* end = ((const u8*)addr + (length - 1));

    if (end < start)
        return DS_InvalidMemory;

    for (int i = 0; (i < (s32)(sizeof(gTRKMemMap) / sizeof(memRange))); i++) {
        if ((start <= (const u8*)gTRKMemMap[i].end) && (end >= (const u8*)gTRKMemMap[i].start)) {

            if (((readWriteable == VALIDMEM_Readable) && !gTRKMemMap[i].readable)
                || ((readWriteable == VALIDMEM_Writeable) && !gTRKMemMap[i].writeable)) {
                err = DS_InvalidMemory;
            } else {
                err = DS_NoError;

                if (start < (const u8*)gTRKMemMap[i].start)
                    err = TRKValidMemory32(start, (u32)((const u8*)gTRKMemMap[i].start - start), readWriteable);

                if ((err == DS_NoError) && (end > (const u8*)gTRKMemMap[i].end))
                    err = TRKValidMemory32((const u8*)gTRKMemMap[i].end, (u32)(end - (const u8*)gTRKMemMap[i].end), readWriteable);
            }

            break;
        }
    }

    return err;
}


asm void TRK_ppc_memcpy(register void* dest, register const void* src, register int n, register u32 param_4, register u32 param_5) {
    #ifdef __MWERKS__ // clang-format off
        stwu r1, -0x30(r1)
        mflr r0
        stw r0, 0x34(r1)
        stmw r24, 0x10(r1)
        mr r29, r3
        mr r30, r4
        mr r26, r5
        mr r27, r6
        mr r28, r7
        bl __TRK_get_MSR
        mr r31, r3
        li r25, 0xFF
        b L2
    L1:
        mr r3, r28
        bl __TRK_set_MSR
        clrrwi r3, r30, 2
        subf r0, r3, r30
        lwz r3, 0x0(r3)
        subfic r0, r0, 0x3
        slwi r0, r0, 3
        srw r0, r3, r0
        clrlwi r24, r0, 24
        sync
        mr r3, r27
        bl __TRK_set_MSR
        clrrwi r6, r29, 2
        subf r0, r6, r29
        lwz r5, 0x0(r6)
        subfic r3, r0, 0x3
        subfic r0, r0, 0x3
        slwi r3, r3, 3
        slwi r0, r0, 3
        slw r4, r25, r3
        slw r0, r24, r0
        andc r3, r5, r4
        and r0, r4, r0
        or r0, r3, r0
        stw r0, 0x0(r6)
        sync
        addi r30, r30, 0x1
        addi r29, r29, 0x1
        subi r26, r26, 0x1
    L2:
        cmpwi r26, 0x0
        bne L1
        mr r3, r31
        bl __TRK_set_MSR
        lmw r24, 0x10(r1)
        lwz r0, 0x34(r1)
        mtlr r0
        addi r1, r1, 0x30
        blr
    #endif // clang-format on
}

DSError TRKTargetAccessMemory(void* data, u32 start, size_t* length, MemoryAccessOptions accessOptions, BOOL read)
{
    DSError error;
    u32 target_msr;
    void* addr;
    u32 trk_msr;
    TRKExceptionStatus tempExceptionStatus = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected  = FALSE;

    addr  = (void*)TRKTargetTranslate(start);
    error = TRKValidMemory32(addr, *length, read ? VALIDMEM_Readable : VALIDMEM_Writeable);

    if (error != DS_NoError) {
        *length = 0;
    } else {
        target_msr = __TRK_get_MSR();
        trk_msr    = target_msr | gTRKCPUState.Extended1.MSR & 0x10;

        if (read) {
            TRK_ppc_memcpy(data, addr, *length, target_msr, trk_msr);
        } else {
            TRK_ppc_memcpy(addr, data, *length, trk_msr, target_msr);
            TRK_flush_cache(addr, *length);
            if ((void*)start != addr) {
                TRK_flush_cache((void*)start, *length);
            }
        }
    }

    if (gTRKExceptionStatus.exceptionDetected) {
        *length = 0;
        error = DS_CWDSException;
    }

    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}

DSError TRKTargetAccessDefault(u32 firstRegister, u32 lastRegister, TRKBuffer* b, size_t* registersLengthPtr, BOOL read)
{
    DSError error;
    u32 count;
    u32* data;
    TRKExceptionStatus tempExceptionStatus;

    if (lastRegister > 0x24) {
        return DS_InvalidRegister;
    }

    tempExceptionStatus = gTRKExceptionStatus;

    gTRKExceptionStatus.exceptionDetected = FALSE;

    data = gTRKCPUState.Default.GPR + firstRegister;

    count = (lastRegister - firstRegister) + 1;

    *registersLengthPtr = count * sizeof(u32);

    if (read) {
        error = TRKAppendBuffer_ui32(b, data, count);
    } else {
        error = TRKReadBuffer_ui32(b, data, count);
    }

    if (gTRKExceptionStatus.exceptionDetected) {
        *registersLengthPtr = 0;
        error               = DS_CWDSException;
    }

    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}

DSError TRKTargetAccessFP(u32 firstRegister, u32 lastRegister, TRKBuffer* b, size_t* registersLengthPtr, BOOL read)
{
    u64 temp;
    DSError error;
    TRKExceptionStatus tempExceptionStatus;
    u32 current;

    if (lastRegister > 0x21) {
        return DS_InvalidRegister;
    }

    tempExceptionStatus                   = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = FALSE;

    __TRK_set_MSR(__TRK_get_MSR() | 0x2000);

    *registersLengthPtr = 0;
    error               = DS_NoError;

    for (current = firstRegister; (current <= lastRegister) && (error == DS_NoError); current++, *registersLengthPtr += sizeof(f64)) {
        if (read) {
            TRKPPCAccessFPRegister(&temp, current, read);
            error = TRKAppendBuffer1_ui64(b, temp);
        } else {
            TRKReadBuffer1_ui64(b, &temp);
            error = TRKPPCAccessFPRegister(&temp, current, read);
        }
    }

    if (gTRKExceptionStatus.exceptionDetected) {
        *registersLengthPtr = 0;
        error               = DS_CWDSException;
    }

    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}

DSError TRKTargetAccessExtended1(u32 firstRegister, u32 lastRegister, TRKBuffer* b, size_t* registersLengthPtr, BOOL read)
{
    TRKExceptionStatus tempExceptionStatus;
    int error;
    u32* data;
    int count;

    if (lastRegister > 0x60) {
        return DS_InvalidRegister;
    }

    tempExceptionStatus                   = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = FALSE;

    *registersLengthPtr = 0;

    if (firstRegister <= lastRegister) {
        data  = (u32*)&gTRKCPUState.Extended1 + firstRegister;
        count = lastRegister - firstRegister + 1;
        *registersLengthPtr += count * sizeof(u32);

        if (read) {
            error = TRKAppendBuffer_ui32(b, data, count);
        } else {
            if (data <= &gTRKCPUState.Extended1.TBU && (data + count - 1) >= &gTRKCPUState.Extended1.TBL) {
                gTRKRestoreFlags.TBR = 1;
            }

            if (data <= &gTRKCPUState.Extended1.DEC && (data + count - 1) >= &gTRKCPUState.Extended1.DEC) {
                gTRKRestoreFlags.DEC = 1;
            }
            error = TRKReadBuffer_ui32(b, data, count);
        }
    }
    if (gTRKExceptionStatus.exceptionDetected) {
        *registersLengthPtr = 0;
        error               = DS_CWDSException;
    }

    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}

DSError TRKTargetAccessExtended2(u32 firstRegister, u32 lastRegister, TRKBuffer* b, size_t* registerStorageSize, BOOL read)
{
    u32 value_buf[2];
    TRKExceptionStatus savedException;
    u32 i;
    DSError err;
    u32 value_buf0[1];

    if (lastRegister > 0x1f)
        return DS_InvalidRegister;

    /*
    ** Save any existing exception status and clear the exception flag.
    ** This allows detection of exceptions that occur ONLY within this
    ** function.
    */

    savedException = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = FALSE;

    TRKPPCAccessSPR(value_buf0, SPR_HID2, TRUE);

    value_buf0[0] |= 0xA0000000;
    TRKPPCAccessSPR(value_buf0, SPR_HID2, FALSE);

    value_buf0[0] = 0;
    TRKPPCAccessSPR(value_buf0, SPR_GQR0, FALSE);

    *registerStorageSize = 0;
    err                  = DS_NoError;

    for (i = firstRegister; (i <= lastRegister) && (err == DS_NoError); i++) {
        if (read) {
            err = TRKPPCAccessPairedSingleRegister((u64*)value_buf, i, read);
            err = TRKAppendBuffer1_ui64(b, *(u64*)value_buf);
        } else {
            err = TRKReadBuffer1_ui64(b, (u64*)value_buf);
            err = TRKPPCAccessPairedSingleRegister((u64*)value_buf, i, read);
        }

        *registerStorageSize += sizeof(u64);
    }

    if (gTRKExceptionStatus.exceptionDetected) {
        *registerStorageSize = 0;
        err                  = DS_CWDSException;
    }

    gTRKExceptionStatus = savedException;

    return err;
}
