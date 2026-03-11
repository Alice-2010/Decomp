#include "types.h"
#include "K/KCore/Main/CKYellowPages.h"
#include "Revolution/DVD.h"
#include "Revolution/OS.h"
#include "PowerPC_EABI_Support/Runtime/__mem.h"

extern "C" {
extern void* fn_8037C6E0(void);
extern void fn_80381030(void);
extern void fn_80374B00(void (*callback)(void));
extern void fn_80374BF0(void (*callback)(void));
extern void fn_802AAFC8(void);
extern void* fn_802AAFBC(void);
extern void fn_802AB168(int argc, char** argv);
extern u32 fn_802AAFCC(void);
extern u32 fn_802AB054(void);
extern void fn_802AB05C(void);
extern void fn_800C7028(void);
extern s32 fn_80282028(void);
extern void fn_8038F530(void);
extern void* fn_801A60C4(void*);
extern void fn_802FE30C(void*);
extern void fn_801B9808(void*, s32);
extern void fn_8021AC04(void*);
}

u8 lbl_805567B8[0x20];


DONT_INLINE void fn_802AE234(void) {
    fn_802FE30C(fn_801A60C4(CKYellowPages::GetGameLoop()));
    fn_801B9808(CKYellowPages::GetGameLoop(), 2);
    fn_8021AC04(CKYellowPages::GetInputModule());
}

DONT_INLINE void fn_802AE270(void) {
    fn_802FE30C(fn_801A60C4(CKYellowPages::GetGameLoop()));
    fn_801B9808(CKYellowPages::GetGameLoop(), 1);
    fn_8021AC04(CKYellowPages::GetInputModule());
}

void fn_802AE2AC(void) {
    fn_802AE234();
}

void fn_802AE2B0(void) {
    fn_802AE270();
}

int main(int argc, char** argv) {
    DVDInit();
    void* src = fn_8037C6E0();
    memcpy(lbl_805567B8, src, 0x20);
    fn_80381030();
    fn_80374B00(fn_802AE2AC);
    fn_80374BF0(fn_802AE2B0);
    fn_802AAFC8();
    char* ptr = (char*)fn_802AAFBC();
    fn_802AB168(argc, argv);
    *(s32*)(ptr + 0x04) = 0;
    *(s32*)(ptr + 0x08) = 0;
    *(s32*)(ptr + 0x0C) = 0;
    *(u8*)(ptr + 0x14) = 1;
    *(s32*)(ptr + 0x00) = 0;
    *(s32*)(ptr + 0x18) = 0;
    *(s32*)(ptr + 0x20) = 0;
    bool running = fn_802AAFCC();
    if (running == TRUE) {
        while (fn_802AB054() == TRUE) {
            fn_800C7028();
            if (fn_80282028() != 0) {
                fn_8038F530();
            }
        }
    }
    fn_802AB05C();
    OSReturnToMenu();
    return 0;
}
