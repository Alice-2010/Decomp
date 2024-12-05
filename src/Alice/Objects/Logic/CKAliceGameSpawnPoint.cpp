#include "Alice/Objects/Logic/CKAliceGameSpawnPoint.h"

extern void fn_8000E10C(s32*);
extern u32 fn_800B7A38();
extern void fn_800EF574(u32);

s32 CKAliceGameSpawnPoint::getClassGroup()
{
    return 12;
}

s32 CKAliceGameSpawnPoint::getClassID()
{
    return 484;
}

s32 CKAliceGameSpawnPoint::serialize(){
    CKGameSpawnPoint::serialize();
    return 1;
}

// TODO: type for `file` will need to be changed to a struct pointer
s32 CKAliceGameSpawnPoint::deserialize(s32* file, s32 file_id)
{
    CKGameSpawnPoint::deserialize(file, file_id);
    // NOTE: Have to invert the checks here to correctly generate `beq` instead of `bne`
    if (file_id != 8) {
        if (file_id != 0) {
            return 1;
        }
        else {
            u32 var = fn_800B7A38();
            fn_800EF574(var);
        }
    }
    else {
        fn_8000E10C(file);
    }
    return 1;
}
