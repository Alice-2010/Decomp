#ifndef K_TYPES_H
    #define K_TYPES_H

    #include "types.h"

    #define K_FULL_ID(cat, id) (cat | (id << 6))

    typedef s32 KError;
    typedef u32 KClassIdentifier;

    enum ESerializationType
    {
        K_LEVEL_PLATEFORMS,
        K_GAME_PLATEFORMS,
        K_LEVEL_LOCALIZATION,
        K_GAME_LOCALIZATION,
        K_LEVEL_MEMCARD,
        K_GAME_MEMCARD,
        K_OPTIONS_MEMCARD,
        MAX_SERIALIZATION_TYPE
    };

    enum EInfoReturnType
    {
        KINFO_RETURN_OK,
        KINFO_RETURN_NOT_PROCESSED,
        KINFO_RETURN_ERROR
    };

    enum EGetInfoRequestType
    {
        KINFO_REQUEST_ACCESSOR_POINTER
    };

    enum KMESSAGE_RETURN
    {
        KMSG_RETURN_OK,
        KMSG_RETURN_NOT_PROCESSED,
        KMSG_RETURN_INVALID_PARAMETER,
        KMSG_RETURN_ERROR
    };

#endif // K_TYPES_H
