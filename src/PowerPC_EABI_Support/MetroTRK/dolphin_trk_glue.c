#include "Revolution/DB.h" // IWYU pragma: keep
#include "PowerPC_EABI_Support/MetroTRK/trk.h"
#include "PowerPC_EABI_Support/MSL/MSL_C/stddef.h" // IWYU pragma: keep

#define BUFF_LEN 4362

u8 gWriteBuf[BUFF_LEN];
u8 gReadBuf[BUFF_LEN];
s32 _MetroTRK_Has_Framing;
s32 gReadCount;
s32 gReadPos;
s32 gWritePos;

DBCommTable gDBCommTable = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

asm void TRKLoadContext(struct OSContext* ctx, u32 a)
{
    #ifdef __MWERKS__ // clang-format off
        lwz r0, 0(r3)
        lwz r1, 4(r3)
        lwz r2, 8(r3)
        lwz r5, 0x1A2(r3)
        rlwinm. r6, r5, 0, 30, 30
        beq L1
        rlwinm r5, r5, 0, 31, 29
        sth r5, 0x1A2(r3)
        lmw r5, 0x14(r3)
        b L2
    L1:
        lmw r13, 0x34(r3)
    L2:
        mr r31, r3
        mr r3, r4
        lwz r4, 0x80(r31)
        mtcrf 255, r4
        lwz r4, 0x84(r31)
        mtlr r4
        lwz r4, 0x88(r31)
        mtctr r4
        lwz r4, 0x8C(r31)
        mtxer r4
        mfmsr r4
        rlwinm r4, r4, 0, 17, 15
        rlwinm r4, r4, 0, 31, 29
        mtmsr r4
        mtsprg 1, r2
        lwz r4, 0xC(r31)
        mtsprg 2, r4
        lwz r4, 0x10(r31)
        mtsprg 3, r4
        lwz r2, 0x198(r31)
        lwz r4, 0x19C(r31)
        lwz r31, 0x7C(r31)
        b TRKInterruptHandler
    #endif // clang-format on
}

/**
 * @TODO: Documentation
 */
void TRKEXICallBack(OSInterruptType param_0, struct OSContext* ctx)
{
	OSEnableScheduler();
	TRKLoadContext(ctx, 0x500);
}

/**
 * @TODO: Documentation
 */
int InitMetroTRKCommTable(int hwId)
{
	int result;

	if (hwId == HARDWARE_GDEV) {
		result = Hu_IsStub();

		// gDBCommTable.initialize_func      = (DBCommInitFunc)DBInitComm;
		// gDBCommTable.init_interrupts_func = (DBCommFunc)DBInitInterrupts;
		// gDBCommTable.peek_func            = (DBCommFunc)DBQueryData;
		// gDBCommTable.read_func            = (DBCommReadFunc)DBRead;
		// gDBCommTable.write_func           = (DBCommWriteFunc)DBWrite;
		// gDBCommTable.open_func            = (DBCommFunc)DBOpen;
		// gDBCommTable.close_func           = (DBCommFunc)DBClose;
	} else {
		result = AMC_IsStub();

		// gDBCommTable.initialize_func      = (DBCommInitFunc)EXI2_Init;
		// gDBCommTable.init_interrupts_func = (DBCommFunc)EXI2_EnableInterrupts;
		// gDBCommTable.peek_func            = (DBCommFunc)EXI2_Poll;
		// gDBCommTable.read_func            = (DBCommReadFunc)EXI2_ReadN;
		// gDBCommTable.write_func           = (DBCommWriteFunc)EXI2_WriteN;
		// gDBCommTable.open_func            = (DBCommFunc)EXI2_Reserve;
		// gDBCommTable.close_func           = (DBCommFunc)EXI2_Unreserve;
	}

	return result;
}

/**
 * @TODO: Documentation
 */
void TRKUARTInterruptHandler(void)
{
}

/**
 * @TODO: Documentation
 */
DSError TRKInitializeIntDrivenUART(u32 param_0, u32 param_1, u32 param_2, volatile u8** param_3)
{
	// gDBCommTable.initialize_func(param_3, TRKEXICallBack);
	return DS_NoError;
}

/**
 * @TODO: Documentation
 */
void EnableEXI2Interrupts(void)
{
	gDBCommTable.init_interrupts_func();
}

/**
 * @TODO: Documentation
 */
int TRKPollUART(void)
{
	return gDBCommTable.peek_func();
}

/**
 * @TODO: Documentation
 */
UARTError TRKReadUARTN(void* bytes, u32 length)
{
	int readErr = gDBCommTable.read_func(bytes, length);
	return readErr == 0 ? 0 : -1;
}

/**
 * @TODO: Documentation
 */
UARTError TRKWriteUARTN(const void* bytes, u32 length)
{
	int writeErr = gDBCommTable.write_func(bytes, length);
	return writeErr == 0 ? 0 : -1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
UARTError WriteUARTFlush(void)
{
	UARTError readErr = 0;

	while (gWritePos < 0x800) {
		gWriteBuf[gWritePos] = 0;
		gWritePos++;
	}
	if (gWritePos != 0) {
		readErr   = TRKWriteUARTN(gWriteBuf, gWritePos);
		gWritePos = 0;
	}
	return readErr;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00002C
 */
UARTError WriteUART1(u8 arg0)
{
	gWriteBuf[gWritePos++] = arg0;
	return 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F8
 */
UARTError TRKReadUARTPoll(u8* arg0)
{
	UARTError readErr = 4;
	s32 cnt;

	if (gReadPos >= gReadCount) {
		gReadPos = 0;
		cnt = gReadCount = TRKPollUART();
		if (cnt > 0) {
			if (cnt > BUFF_LEN) {
				gReadCount = BUFF_LEN;
			}
			readErr = TRKReadUARTN(gReadBuf, gReadCount);
			if (readErr != 0) {
				gReadCount = 0;
			}
		}
	}
	if (gReadPos < gReadCount) {
		*arg0   = gReadBuf[gReadPos++];
		readErr = 0;
	}
	return readErr;
}

/**
 * @TODO: Documentation
 */
void ReserveEXI2Port(void)
{
	gDBCommTable.open_func();
}

/**
 * @TODO: Documentation
 */
void UnreserveEXI2Port(void)
{
	gDBCommTable.close_func();
}

/**
 * @TODO: Documentation
 */
void TRK_board_display(const char* str)
{
	OSReport(str);
}
