#include "K/KServices/KServiceCounter/IKCounter.h"
#include "K/KTypes.h"

IKCounter::IKCounter(): IKSerializable::IKSerializable() {}

BOOL IKCounter::IsKindOfClass(KClassIdentifier a_iClassIdentifier)
{
    if (a_iClassIdentifier == K_FULL_ID(CLASS_TYPE, CLASS_ID))
    {
        return TRUE;
    }
    return IKSerializable::IsKindOfClass(a_iClassIdentifier);
}
