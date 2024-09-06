#ifndef ALICE_TYPES_H
    #define ALICE_TYPES_H

    #include "macros.h"

    typedef int BOOL;

    typedef signed char s8;
    typedef signed short s16;
    typedef signed long int s32;
    typedef signed long long int s64;
    typedef unsigned char u8;
    typedef unsigned short u16;
    typedef unsigned int uint;
    typedef unsigned long int u32;
    typedef unsigned long long int u64;

    typedef volatile u8 vu8;
    typedef volatile u16 vu16;
    typedef volatile u32 vu32;
    typedef volatile u64 vu64;
    typedef volatile s8 vs8;
    typedef volatile s16 vs16;
    typedef volatile s32 vs32;
    typedef volatile s64 vs64;

    typedef float f32;
    typedef double f64;
    typedef volatile f32 vf32;
    typedef volatile f64 vf64;

    #ifdef NULL
        #undef NULL
    #endif
    #define NULL 0

    #ifdef TRUE
        #undef TRUE
    #endif
    #define TRUE 1

    #ifdef FALSE
        #undef FALSE
    #endif
    #define FALSE 0

#endif
