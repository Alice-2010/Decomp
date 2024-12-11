#include "types.h"
#include "Alice/Interfaces/IKSerializable.h"

struct IKGameObject : IKSerializable
{
    IKGameObject();
    virtual BOOL isSubclass(u32);
    virtual s32 getClassGroup();
    virtual s32 getClassID();
    virtual s32 serialize();
    virtual s32 deserialize();
};
