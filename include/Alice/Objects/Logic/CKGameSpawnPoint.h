#include "types.h"
#include "Alice/Interfaces/IKGameObject.h"

struct CKGameSpawnPoint : IKGameObject
{
    CKGameSpawnPoint();
    virtual BOOL isSubclass(u32);
    virtual s32 getClassGroup();
    virtual s32 getClassID();
    virtual s32 serialize();
    virtual s32 deserialize(s32*, s32);
};
