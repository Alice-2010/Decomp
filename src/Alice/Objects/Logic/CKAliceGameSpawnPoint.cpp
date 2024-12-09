#include "Alice/Objects/Logic/CKAliceGameSpawnPoint.h"

extern void fn_8000E10C(s32*);
extern u32 fn_800B7A38();
extern void fn_800EF574(u32);

extern void fn_8039462C(s32, void*, void*, s32, s32);
extern void fn_80010130(s32);
extern void fn_800B6BD4();
extern void fn_8000FD70();
extern void fn_8000F2DC();

extern void fn_800B7248(s32);
extern void fn_800101C8(s32);
extern void fn_800EF0C8(s32);

CKAliceGameSpawnPoint::CKAliceGameSpawnPoint() : CKGameSpawnPoint::CKGameSpawnPoint()
{
    fn_8039462C((s32)this + 0x40, fn_800B7248, fn_800B6BD4, 8, 3);
    fn_8039462C((s32)this + 0x58, fn_8000FD70, fn_8000F2DC, 36, 3);
    fn_80010130((s32)this + 0xC4);
};

CKGameSpawnPoint::CKGameSpawnPoint()
{
    fn_800B7248((s32)this + 0x20);
    fn_800101C8((s32)this + 0x2C);
    fn_800EF0C8((s32)this + 0x34);
};

s32 CKAliceGameSpawnPoint::getClassGroup()
{
    return 12;
}

s32 CKAliceGameSpawnPoint::getClassID()
{
    return 484;
}

s32 CKAliceGameSpawnPoint::serialize()
{
    CKGameSpawnPoint::serialize();
    return 1;
}

// TODO: type for `file` will need to be changed to a struct pointer
s32 CKAliceGameSpawnPoint::deserialize(s32* file, s32 file_id)
{
    CKGameSpawnPoint::deserialize(file, file_id);
    // NOTE: Have to invert the checks here to correctly generate `beq` instead of `bne`
    if (file_id != 8)
    {
        if (file_id != 0)
        {
            return 1;
        }
        else
        {
            u32 var = fn_800B7A38();
            fn_800EF574(var);
        }
    }
    else
    {
        fn_8000E10C(file);
    }
    return 1;
}
