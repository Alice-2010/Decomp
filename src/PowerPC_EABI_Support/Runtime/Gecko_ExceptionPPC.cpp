#include "global.h"
#include "PowerPC_EABI_Support/Runtime/Gecko_ExceptionPPC.h"

extern ProcessInfo fragment_info[MAXFRAGMENTS];

s32 __register_fragment(struct __eti_init_info* info, char* TOC)
{
    ProcessInfo* f = fragment_info;
    s32 i;

    for (i = 0; i < MAXFRAGMENTS; i++, f++) {
        if (f->active == 0) {
            f->exception_info = info;
            f->TOC = TOC;
            f->active = 1;
            return i;
        }
    }

    return -1;
}

void __unregister_fragment(s32 fragmentID)
{
    ProcessInfo* f;
    if (fragmentID >= 0 && fragmentID < MAXFRAGMENTS) {
        f = &fragment_info[fragmentID];
        f->exception_info = 0;
        f->TOC = 0;
        f->active = 0;
    }
}

s32 ExPPC_FindExceptionFragment(char* returnaddr, FragmentInfo* frag)
{
    ProcessInfo* f;
    s32 i;
    __eti_init_info* eti_info;

    for (i = 0, f = fragment_info; i < MAXFRAGMENTS; ++i, ++f) {
        if (f->active) {
            eti_info = f->exception_info;
            while (1) {
                if (eti_info->code_size == 0)
                    break;
                if (returnaddr >= eti_info->code_start && returnaddr < (char*)eti_info->code_start + eti_info->code_size) {
                    frag->exception_start = (ExceptionTableIndex*)eti_info->eti_start;
                    frag->exception_end = (ExceptionTableIndex*)eti_info->eti_end;
                    frag->code_start = 0;
                    frag->code_end = 0;
                    frag->data_start = 0;
                    frag->data_end = 0;
                    frag->TOC = f->TOC;
                    frag->active = f->active;
                    return 1;
                }
                eti_info++;
            }
        }
    }

    return 0;
}