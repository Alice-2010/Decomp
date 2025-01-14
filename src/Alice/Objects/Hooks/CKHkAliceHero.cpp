#include "Alice/Objects/Hooks/CKHkAliceHero.h"

CKHkAliceHero::CKHkAliceHero(): IKHkHero::IKHkHero() {}

CKHkAliceHero::~CKHkAliceHero() {}

s32 CKHkAliceHero::getClassGroup()
{
    return 2;
}

s32 CKHkAliceHero::getClassID()
{
    return 151;
}

s32 CKHkAliceHero::sendEvent()
{
    return 1;
}
