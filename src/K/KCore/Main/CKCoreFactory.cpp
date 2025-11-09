#include "K/KCore/Main/CKCoreFactory.h"
#include "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/printf.h" // IWYU pragma: export

CKCoreFactory::CKCoreFactory()
{

}

CKCoreFactory::~CKCoreFactory()
{

}

extern ClassInfoVector FUN_801b56d8(ClassInfoVector*);
void CKCoreFactory::AddPluginInfo(u16 a, u16 b, PFCT_K_CREATE_CLASS pfnCreateClass, PFCT_K_DELETE_CLASS pfnDeleteClass, PFCT_K_CREATE_ARRAY_CLASS pfnCreateArrayClass, PFCT_K_DELETE_ARRAY_CLASS pfnDeleteArrayClass)
{
    ClassInfoVector* pClassVectors = this[a].m_classInfos;
    ClassInfoVector pClassInfo = FUN_801b56d8(pClassVectors);
}

IKBaseClass* CKCoreFactory::CreateClass(u32 a, u32 b)
{
    CKClassInfo* pClassInfo = this->GetClassVector(a, b);
    return pClassInfo->m_pfnCreateClass();
}

void CKCoreFactory::DeleteClass(IKBaseClass* pClass)
{
    CKClassInfo* pClassInfo = this->GetClassVector(pClass->MessageProc(), pClass->FindNonRecreableInstances(0, 0, 0, null));
    pClassInfo->m_pfnDeleteClass(pClass);
}

IKBaseClass* CKCoreFactory::CreateArrayClass(u32 a, u32 b, u32 c, u16* d)
{
    CKClassInfo* pClassInfo = this->GetClassVector(a, b);
    return pClassInfo->m_pfnCreateArrayClass(c, d);
}

void CKCoreFactory::DeleteArrayClass(IKBaseClass* pClass)
{
    CKClassInfo* pClassInfo = this->GetClassVector(pClass->MessageProc(), pClass->FindNonRecreableInstances(0, 0, 0, null));
    pClassInfo->m_pfnDeleteArrayClass(pClass);
}

char* CKCoreFactory::KGetClassName(u32, u32) const
{
    sprintf("Type '%d', Id '%d'", 0, 0);
}

char* CKCoreFactory::KGetClassName(const IKBaseClass*) const
{
    sprintf("Type '%d', Id '%d'", 0, 0);
}

u32 CKCoreFactory::KGetMaxTypeID(u32)
{

}

CKClassInfo* CKCoreFactory::FUN_801b56c8(u32 a)
{
    return this->m_classInfos[a * 0x14].m_pBlock;
}

CKClassInfo* CKCoreFactory::GetClassVector(u32 a, u32 b)
{
    return (this + a * 3 + 1)->FUN_801b56c8(b);
}
