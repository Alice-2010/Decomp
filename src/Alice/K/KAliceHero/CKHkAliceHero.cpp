#include "Alice/K/KAliceHero/CKHkAliceHero.h"

extern void fn_801A56EC(void*);

void operator delete(void* ptr) { fn_801A56EC(ptr); }

#pragma dont_inline on

CKHkAliceHero::CKHkAliceHero(): IKHkHero::IKHkHero() {};
CKHkAliceHero::~CKHkAliceHero() {};
BOOL CKHkAliceHero::IsKindOfClass(u32 classID)
{
    if (classID == 9666)
        return TRUE;
    return IKHkHero::IsKindOfClass(classID);
};
s32 CKHkAliceHero::GetClassType()
{
    return 2;
};
s32 CKHkAliceHero::GetClassID()
{
    return 151;
};

#pragma dont_inline off
