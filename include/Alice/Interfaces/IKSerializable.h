#include "types.h"
#include "Alice/Interfaces/IKBaseClass.h"

struct IKSerializable : IKBaseClass
{
    IKSerializable();
    virtual s32 serialize();
    virtual s32 deserialize(void);
};
