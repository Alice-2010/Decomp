#include "Alice/Objects/Logic/CKGameSpawnPoint.h"

CKGameSpawnPoint::CKGameSpawnPoint() : IKGameObject::IKGameObject()
{

};

s32 CKGameSpawnPoint::getClassGroup()
{
    return 12;
};

s32 CKGameSpawnPoint::getClassID()
{
    return 198;
};
