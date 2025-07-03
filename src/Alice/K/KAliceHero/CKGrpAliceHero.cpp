#include "Alice/K/KAliceHero/CKGrpAliceHero.h"

#pragma dont_inline on

CKGrpAliceHero::CKGrpAliceHero(): IKGrpHero::IKGrpHero() {};
CKGrpAliceHero::~CKGrpAliceHero() {};
BOOL CKGrpAliceHero::isSubclass(u32 classID)
{
    if (classID == 3524)
        return TRUE;
    return IKGrpHero::isSubclass(classID);
};
s32 CKGrpAliceHero::getClassGroup()
{
    return 4;
};
s32 CKGrpAliceHero::getClassID()
{
    return 55;
};

#pragma dont_inline off
