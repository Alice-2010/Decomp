#include "Alice/K/KAliceHero/CKGrpAliceHero.h"

#pragma dont_inline on

CKGrpAliceHero::CKGrpAliceHero(): IKGrpHero::IKGrpHero() {};
CKGrpAliceHero::~CKGrpAliceHero() {};
BOOL CKGrpAliceHero::IsKindOfClass(u32 classID)
{
    if (classID == 3524)
        return TRUE;
    return IKGrpHero::IsKindOfClass(classID);
};
s32 CKGrpAliceHero::GetClassType()
{
    return 4;
};
s32 CKGrpAliceHero::GetClassID()
{
    return 55;
};

#pragma dont_inline off
