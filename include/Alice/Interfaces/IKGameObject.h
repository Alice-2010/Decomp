#include "types.h"
#include "Alice/Interfaces/IKSerializable.h"

struct IKGameObject : IKSerializable
{
    virtual s32 deserialize();
};
