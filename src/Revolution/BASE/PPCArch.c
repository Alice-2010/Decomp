#include "Revolution/BASE.h"
#include "Revolution/OS.h" // IYWU pragma: export

asm u32 PPCMfmsr(void) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mfmsr r3
        blr
    #endif // clang-format on
}

asm void PPCMtmsr(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtmsr val
        blr
    #endif // clang-format on
}

//unused
inline void PPCOrMsr() {}

//unused
inline void PPCAndMsr() {}

//unused
inline void PPCAndCMsr() {}

asm u32 PPCMfhid0(void) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mfhid0 r3
        blr
    #endif // clang-format on
}

asm void PPCMthid0(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mthid0 val
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfhid1() {}

asm u32 PPCMfl2cr(void) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mfl2cr r3
        blr
    #endif // clang-format on
}

asm void PPCMtl2cr(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtl2cr val
        blr
    #endif // clang-format on
}

asm void PPCMtdec(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtdec val
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfdec() {}

asm void PPCSync(void) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        sc
        blr
    #endif // clang-format on
}

//unused
inline void PPCEieio() {}

asm void PPCHalt(void) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        sync
    loop:
        nop
        li r3, 0
        nop
        b loop
    #endif // clang-format on
}

//unused
inline void PPCMfmmcr0() {}

asm void PPCMtmmcr0(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtmmcr0 val
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfmmcr1() {}

asm void PPCMtmmcr1(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtmmcr1 val
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfpmc1() {}

asm void PPCMtpmc1(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtpmc1 val
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfpmc2() {}

asm void PPCMtpmc2(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtpmc2 val
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfpmc3() {}

asm void PPCMtpmc3(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtpmc3 val
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfpmc4() {}

asm void PPCMtpmc4(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtpmc4 val
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfsia() {}

//unused
inline void PPCMtsia() {}

u32 PPCMffpscr(void) {
    register u64 fpscr;

    asm {
        mffs f31
        stfd f31, fpscr
    }

    return fpscr;
}

void PPCMtfpscr(register u32 val) {
    register struct {
        float tmp;
        float data;
    } fpscr;

    asm {
        li r4, 0
        stw r4, fpscr.tmp
        stw val, fpscr.data
        lfd f31, fpscr.tmp
        mtfs f31
    }
}

asm u32 PPCMfhid2(void) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mfspr r3, 0x398 //HID2
        blr
    #endif // clang-format on
}

asm void PPCMthid2(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtspr 0x398, val //HID2
        blr
    #endif // clang-format on
}

// unused
inline u32 PPCMfwpar(void) {}

asm void PPCMtwpar(register u32 val) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtwpar r3
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfdmaU() {}

//unused
inline void PPCMfdmaL() {}

//unused
inline void PPCMtdmaU() {}

//unused
inline void PPCMtdmaL() {}

//unused
inline void PPCMfpvr() {}

//unused
inline void PPCEnableSpeculation() {}

void PPCDisableSpeculation(void) { PPCMthid0(PPCMfhid0() | HID0_SPD); }

//unused
inline void PPCSetFpIEEEMode() {}

asm void PPCSetFpNonIEEEMode(void) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        mtfsb1 29
        blr
    #endif // clang-format on
}

//unused
inline void PPCMfhid4() {}

void PPCMthid4(register u32 val) {
    if (val & HID4_H4A) {
        asm {
            mtspr 0x3F3, val //HID4
        }
    } else {
        OSReport("H4A should not be cleared because of Broadway errata.\n");
        val |= HID4_H4A;
        asm {
            mtspr 0x3F3, val //HID4
        }
    }
}
