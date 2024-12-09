#include "types.h"
#include "Alice/Interfaces/IKSerializable.h"

struct IKGameObject : IKSerializable
{
    IKGameObject();
    virtual s32 deserialize();
};
