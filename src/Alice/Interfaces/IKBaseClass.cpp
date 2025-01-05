#include "Alice/Interfaces/IKBaseClass.h"

IKBaseClass::IKBaseClass() {}

IKBaseClass::~IKBaseClass() {}

BOOL IKBaseClass::isSubclass()
{
    return FALSE;
}

void IKBaseClass::reset()
{
    return;
}

void IKBaseClass::unk()
{
    return;
}

s32 IKBaseClass::sendEvent()
{
    return 1;
}

s32 IKBaseClass::unk2()
{
    return 0;
}
