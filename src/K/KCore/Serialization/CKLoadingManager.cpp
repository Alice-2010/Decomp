#include "K/KCore/Serialization/CKLoadingManager.h"
#include "K/KCore/Main/CKYellowPages.h"
#include "K/KBasic/FileIO/CKZipStreamedFile.h"

class CKCoreManager
{
public:
    IKSerializable* GetGuidObject(CGuid* pGuid);
};

class CTexture
{
public:
    static void* ReadTexture(const char* pName);
};

extern void RwTextureDestroy(void* pTexture);
extern void fn_801A5D38(CGuid, s32 b);
extern void fn_801A5BF8(char* a, s32 b);
extern void fn_800C4C0C(CGuid, s32 b);
extern s32 fn_801BE780(CKIDBundleLoad*);

CKLoadingManager::CKLoadingManager(): IKLoadingInterfaces::IKLoadingInterfaces()
{
    fn_801A5D38(this->m_kGameGUID, 0);
    CKYellowPages::SetLoadingInterface(this);
}

CKLoadingManager::~CKLoadingManager()
{
    CKYellowPages::SetLoadingInterface(NULL);
    fn_801A5BF8(this->m_tStreamingSemaphore, -1);
    fn_800C4C0C(this->m_kGameGUID, -1);
}

BOOL CKLoadingManager::IsKindOfClass(KClassIdentifier a_iClassIdentifier)
{
    if (a_iClassIdentifier == K_FULL_ID(CLASS_TYPE, CLASS_ID)) return TRUE;
    return IKLoadingInterfaces::IsKindOfClass(a_iClassIdentifier);
}

s32 CKLoadingManager::GetClassType()
{
    return CLASS_TYPE;
}

s32 CKLoadingManager::GetClassID()
{
    return CLASS_ID;
}

void CKLoadingManager::HandleToPointer(IKSerializable** ppObject)
{
    // TODO: Finish this
    // PAL: 0x801BFECC
    u32 handle = (u32)*ppObject;
    if (handle == -1)
    {
        *ppObject = NULL;
        return;
    }
    BOOL bVar1 = FALSE;
    CKIDBundleLoad* piVar12 = NULL;
    if (this->m_iSerializationType != K_GAME_PLATEFORMS)
    {
        piVar12 = this->m_pTypeBundleLoad[(handle & 0x3F) * 3].m_pID;
        s32 a = fn_801BE780(piVar12);
        if (a == 1)
        {
            *ppObject = piVar12->m_apGameRecreableInstances[handle >> 6];
            return;
        }
        bVar1 = TRUE;
    }
    if (this->m_iSerializationType == K_LEVEL_PLATEFORMS || bVar1)
    {
        *ppObject = NULL;
    }
}

u32 CKLoadingManager::ReadHandle(IKFile* pFile, IKSerializable** ppObject)
{
    u32 bytesRead = ((CKZipStreamedFile*)(pFile))->ReadHandle(ppObject, 1);
    if ((u32)*ppObject == -3)
    {
        CGuid guid;
        guid.Load(pFile);
        *ppObject = ((CKCoreManager*)CKYellowPages::GetCoreManager())->GetGuidObject(&guid);
    }
    else
    {
        this->HandleToPointer(ppObject);
    }
    return bytesRead;
}

u32 CKLoadingManager::ReadContiguousHandles(IKFile* pFile, IKSerializable** ppObjects, s32 count)
{
    u32 totalBytesRead;
    for (s32 i = 0; i < count; ++i)
    {
        totalBytesRead += ((CKZipStreamedFile*)(pFile))->ReadHandle(ppObjects + i, 1);
        if ((u32)ppObjects[i] == -3)
        {
            CGuid guid;
            guid.Load(pFile);
            ppObjects[i] = ((CKCoreManager*)CKYellowPages::GetCoreManager())->GetGuidObject(&guid);
        }
        else
        {
            this->HandleToPointer(ppObjects + i);
        }
    }
    return totalBytesRead;
}

u32 CKLoadingManager::ReadTexture(IKFile* pFile, void** ppTexture)
{
    char name[0x20];
    u32 bytesRead = pFile->ReadString(name, sizeof(name));
    if (name[0] == '\0')
    {
        *ppTexture = 0;
    }
    else
    {
        *ppTexture = CTexture::ReadTexture(name);
        if (*ppTexture != 0)
        {
            RwTextureDestroy(*ppTexture);
        }
    }
    return bytesRead;
}

s32 CKLoadingManager::GetLevelNumber()
{
    return this->m_i32NumCurrentLevel;
}

s32 CKLoadingManager::KUInitialize()
{
    return 1;
}

void CKLoadingManager::KUDestroy()
{
    this->Destroy();
}
