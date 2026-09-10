#include "CKIntegerCounter.h"


CKIntegerCounter::CKIntegerCounter(): IKCounter::IKCounter() {}

CKIntegerCounter::~CKIntegerCounter() {}

s32 CKIntegerCounter::GetClassID()
{
    return CLASS_ID;
}

s32 CKIntegerCounter::GetClassType()
{
    return CLASS_TYPE;
}

BOOL CKIntegerCounter::IsKindOfClass(KClassIdentifier a_iClassIdentifier)
{
    if (a_iClassIdentifier == K_FULL_ID(CLASS_TYPE, CLASS_ID))
        return TRUE;
    return IKCounter::IsKindOfClass(a_iClassIdentifier);
}

void CKIntegerCounter::ResetValue()
{
    this->m_i32CurrentValue = this->m_i32StartValue;
}

void CKIntegerCounter::ResetValueToMax()
{
    this->m_i32CurrentValue = this->m_i32MaxValue;
}

void CKIntegerCounter::ResetValueToMin()
{
    this->m_i32CurrentValue = this->m_i32MinValue;
}
