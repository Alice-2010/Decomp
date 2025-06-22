#include "Revolution/BASE.h" // IWYU pragma: export
#include "Revolution/OS.h" // IWYU pragma: export
#include "PowerPC_EABI_Support/MSL/MSL_C/string.h" // IWYU pragma: export

#define OS_PHYS_SYSCALL_INTR 0xC00
#define OS_INTR_SLOT_SIZE 0x100

void __OSSystemCallVectorStart(void);
void __OSSystemCallVectorEnd(void);

static asm void SystemCallVector(void) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc

        entry __OSSystemCallVectorStart
        mfhid0 r9
        ori r10, r9, HID0_ABE
        mthid0 r10
        isync
        sync

        mthid0 r9
        rfi

        entry __OSSystemCallVectorEnd
        nop
    #endif // clang-format on
}

void __OSInitSystemCall(void) {
    memcpy(OSPhysicalToCached(OS_PHYS_SYSCALL_INTR), __OSSystemCallVectorStart, (u32)__OSSystemCallVectorEnd - (u32)__OSSystemCallVectorStart);
    DCFlushRangeNoSync(OSPhysicalToCached(OS_PHYS_SYSCALL_INTR), OS_INTR_SLOT_SIZE);
    __sync();
    ICInvalidateRange(OSPhysicalToCached(OS_PHYS_SYSCALL_INTR), OS_INTR_SLOT_SIZE);
}
