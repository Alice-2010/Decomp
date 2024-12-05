#include "Alice/Objects/Logic/CKGameSpawnPoint.h"

s32 CKGameSpawnPoint::getClassGroup()
{
    return 12;
}

s32 CKGameSpawnPoint::getClassID()
{
    return 198;
}

s32 CKGameSpawnPoint::serialize()
{
    return 1;
}

s32 CKGameSpawnPoint::deserialize(s32* file, s32 file_id)
{
    return 1;
}
