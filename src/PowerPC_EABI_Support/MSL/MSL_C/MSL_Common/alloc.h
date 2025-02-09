#ifndef _MSL_ALLOC_H
    #define _MSL_ALLOC_H

    #include "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/size_def.h"

    #ifdef __cplusplus
        extern "C" {
    #endif

    void *malloc(size_t size);
    void *calloc(size_t nitems, size_t size);
    void *realloc(void *ptr, size_t size);
    void free(void *);

    #ifdef __cplusplus
        }
    #endif

#endif
