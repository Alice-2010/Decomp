#ifndef RW_RWPLCORE_H
    #define RW_RWPLCORE_H

    #include "types.h"

    enum RwStreamType
    {
        rwNASTREAM,
        rwSTREAMFILE,
        rwSTREAMFILENAME,
        rwSTREAMMEMORY,
        rwSTREAMCUSTOM,
        rwSTREAMTYPEFORCEENUMSIZEINT = 0x7FFFFFFF
    };

    enum RwStreamAccessType
    {
        rwNASTREAMACCESS,
        rwSTREAMREAD,
        rwSTREAMWRITE,
        rwSTREAMAPPEND,
        rwSTREAMACCESSTYPEFORCEENUMSIZEINT = 0x7FFFFFFF
    };

    struct RwStreamMemory
    {
        u32 position; // 0x0
        u32 nSize; // 0x4
        u8* mem; // 0x8
    };

    union RwStreamFile
    {
        const void* fpFile; // 0x0
        const void* constfpFile; // 0x0
    };

    struct RwStreamCustom
    {
        BOOL (*sfclose)(void*); // 0x0
        u32 (*sfread)(void*, void*, u32); // 0x4
        BOOL (*sfnwrite)(void*, const void*, u32); // 0x8
        BOOL (*sfnseek)(void*, u32); // 0xC
        void* data; // 0x10
    };

    union RwStreamUnion
    {
        struct RwStreamMemory memory; // 0x0
        union RwStreamFile file; // 0x0
        struct RwStreamCustom custom; // 0x0
    };

    struct RwStream
    {
        enum RwStreamType type; // 0x0
        enum RwStreamAccessType access; // 0x4
        s32 position; // 0x8
        union RwStreamUnion Type; // 0xC
        BOOL rwOwned; // 0x10
    };

#endif // RW_RWPLCORE_H
