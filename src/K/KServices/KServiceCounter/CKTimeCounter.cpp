#include "K/KCore/Serialization/CKSavingManager.h"
#include "K/KTypes.h"
#include "K/KServices/KServiceCounter/CKTimeCounter.h"
#include "K/Classes/EUL_CBitArray.h"
#include "K/KBasic/FileIO/IKFile.h"
#include "K/KCore/Interfaces/IKBaseClass.h"
#include "K/KCore/Interfaces/IKInfo.h"
#include "K/KCore/Interfaces/IKSerializable.h"
#include "K/KCore/Main/CKYellowPages.h"
#include "K/KServices/KServiceCounter/IKCounter.h"
#include "K/KServices/KServiceTrigger/CTriggerStarter.h"

CKTimeCounter::CKTimeCounter(): IKCounter::IKCounter() {}

CKTimeCounter::~CKTimeCounter() {}

BOOL CKTimeCounter::IsKindOfClass(KClassIdentifier a_iClassIdentifier)
{
    if (a_iClassIdentifier == K_FULL_ID(CLASS_TYPE, CLASS_ID))
    {
        return TRUE;
    }
    return IKCounter::IsKindOfClass(a_iClassIdentifier);
}

s32 CKTimeCounter::GetClassType()
{
    return CLASS_TYPE;
}

s32 CKTimeCounter::GetClassID()
{
    return CLASS_ID;
}

extern void fn_8000E024(IKFile*, CBitArray*, ESerializationType); // IKFile::ReadCBitArray ?
KError CKTimeCounter::Load(IKFile* a_pFile, ESerializationType a_eSerializationType)
{
    IKCounter::Load();
    if (a_eSerializationType == K_LEVEL_PLATEFORMS)
    {
        a_pFile->ReadFloat32(&this->m_fCurrentValue, K_GAME_PLATEFORMS);
        a_pFile->ReadFloat32(&this->m_fMaxValue, K_GAME_PLATEFORMS);
        fn_8000E024(a_pFile, &this->m_baFlags, K_GAME_PLATEFORMS);
        this->m_tsMaxValueReached.Load(a_pFile, a_eSerializationType);
        this->m_tsMaxLoopReached.Load(a_pFile, a_eSerializationType);
    }
    return 1;
}

KError CKTimeCounter::PostLoad()
{
    IKSerializable::PostLoad();
    return 1;
}

extern s32 fn_8001D0E0(IKInfo*);
extern void fn_8000DAF4(IKInfo*, u32);
extern void fn_8001D0E8(EGetInfoRequestType, void*);
EInfoReturnType CKTimeCounter::GetInfo(IKInfo* pInfo, EGetInfoRequestType requestType)
{
    IKSerializable::GetInfo();
    u32 val = 1;
    if (requestType == KINFO_REQUEST_ACCESSOR_POINTER)
    {
        switch(fn_8001D0E0(pInfo))
        {
            case 1:
                val = 0;
                break;
            case 2:
                val = 0;
                break;
            case 4:
                val = 0;
                break;
            case 5:
                val = 0;
                break;
            case 3:
                val = 0;
                break;
            case 6:
                val = 0;
                break;
        }
    }
    fn_8000DAF4(pInfo, val);
    return KINFO_RETURN_NOT_PROCESSED;
};

extern void fn_8000db58(KMESSAGE_RETURN, u32);
extern void fn_802a4264(f32, CKTimeCounter*);
extern void fn_802a4bbc(f32, CKTimeCounter*);
extern void fn_802a43bc(CKTimeCounter*); // CKTimeCounter::??
extern void fn_802a43b0(CKTimeCounter*); // CKTimeCounter::??
extern void fn_802a4bb4(CKTimeCounter*); // CKTimeCounter::??
extern void fn_802a43a8(CKTimeCounter*); // CKTimeCounter::??
KMESSAGE_RETURN CKTimeCounter::MessageProc(u16 a_mMessage, void* a_pParam)
{
    KMESSAGE_RETURN res1 = IKBaseClass::MessageProc();
    u32 res2 = 1;
    switch ((a_mMessage >> 8) & 0xFFFF)
    {
        case 0x2100:
            fn_802a43bc(this);
            res2 = 0;
            break;
        case 0x2103:
            fn_802a43b0(this);
            res2 = 0;
            break;
        case 0x2104:
            fn_802a43b0(this);
            fn_802a43bc(this);
            res2 = 0;
            break;
        case 0x2105:
            fn_802a4bb4(this);
            res2 = 0;
            break;
        case 0x2106:
            fn_802a43bc(this);
            fn_802a4bb4(this);
            res2 = 0;
            break;
        case 0x2107:
            fn_802a43bc(this);
            fn_802a43b0(this);
            fn_802a4bb4(this);
            res2 = 0;
            break;
        case 0x2108:
            fn_802a43a8(this);
            res2 = 0;
            break;
        case 0x2109:
            fn_802a43a8(this);
            fn_802a43bc(this);
            res2 = 0;
            break;
        case 0x210A:
            fn_802a43a8(this);
            fn_802a43bc(this);
            fn_802a43b0(this);
            res2 = 0;
            break;
        case 0x210B:
            fn_802a4264(*(f32*)a_pParam, this);
            res2 = 0;
            break;
        case 0x210C:
            fn_802a4bbc(*(f32*)a_pParam, this);
            res2 = 0;
            break;
    }
    fn_8000db58(res1, res2);
    return KMSG_RETURN_NOT_PROCESSED;
}

extern void fn_802A4CA0(CTriggerStarter*); // CTriggerStarter::RecursiveRegistration
s32 CKTimeCounter::RecursiveRegistration(ESerializationType a_eSerializationType)
{
    s32 val = IKCounter::RecursiveRegistration(a_eSerializationType);
    fn_802A4CA0(&this->m_tsMaxValueReached);
    fn_802A4CA0(&this->m_tsMaxLoopReached);
    if (a_eSerializationType == K_LEVEL_PLATEFORMS)
    {
        CKSavingManager* pSavingManager = CKYellowPages::GetSavingManager();
        typedef void (*SavingManagerFunc)(void*, CKTimeCounter*, int);
        SavingManagerFunc func = *(SavingManagerFunc*)((char*)pSavingManager + 0x28);
        func(pSavingManager, this, 0);
    }
    return val;
}

KError CKTimeCounter::Save()
{
    IKCounter::Save();
    return 1;
}
