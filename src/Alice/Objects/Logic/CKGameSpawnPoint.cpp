#include "Alice/Objects/Logic/CKGameSpawnPoint.h"

extern BOOL fn_800E46C8(void*, u32);

extern void fn_800B7248(s32);
extern void fn_800101C8(s32);
extern void fn_800EF0C8(s32);

CKGameSpawnPoint::CKGameSpawnPoint() : IKGameObject::IKGameObject()
{
    fn_800B7248((s32)this + 0x20);
    fn_800101C8((s32)this + 0x2C);
    fn_800EF0C8((s32)this + 0x34);
};

BOOL CKGameSpawnPoint::isSubclass(u32 classID)
{
    if (classID == 12684)
        return TRUE;
    return fn_800E46C8(this, classID);
};

s32 CKGameSpawnPoint::getClassGroup()
{
    return 12;
};

s32 CKGameSpawnPoint::getClassID()
{
    return 198;
};
