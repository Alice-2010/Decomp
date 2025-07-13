#include "types.h" // IWYU pragma: export
#include "K/KCore/Main/CKYellowPages.h"

static CKYellowPages* g_pYellowPages;

CKYellowPages::CKYellowPages()
{
    this->m_pTimeManager = NULL;
    this->m_pGraphic = NULL;
    this->m_pScreen = NULL;
    this->m_pRendererRootNode = NULL;
    this->m_pCommunSectorRootNode = NULL;
    this->m_pCoreFactory = NULL;
    this->m_pServiceManager = NULL;
    this->m_pFileIOManager = NULL;
    this->m_pCoreManager = NULL;
    this->m_pGameLoop = NULL;
    this->m_pTextureManager = NULL;
    this->m_pAnimationManager = NULL;
    this->m_pLoadingManager = NULL;
    this->m_pLoadingInterface = NULL;
    this->m_pSrvCollision = NULL;
    this->m_pSrvPathFinding = NULL;
    this->m_pSrvCamera = NULL;
    this->m_pSrvCinematic = NULL;
    this->m_pTrcManager = NULL;
    this->m_pManager2d = NULL;
    this->m_pKGameManager = NULL;
    this->m_pKGameUIManager = NULL;
    this->m_pCurrentLevel = NULL;
    this->m_pLocManager = NULL;
    this->m_pSrvBeacon = NULL;
    this->m_pInput = NULL;
    this->m_pSound = NULL;
    this->m_pServiceLife = NULL;
    this->m_pSrvAvoidance = NULL;
    this->m_pSrvSekensor = NULL;
    this->m_pSrvShadow = NULL;
    this->m_pSrvFx = NULL;
    this->m_pSrvProjectiles = NULL;
    this->m_pFlashManager = NULL;
    this->m_pSrvMusic = NULL;
    this->m_pSrvBonus = NULL;
    this->m_pUnk1 = NULL;
    this->m_pUnkRootNode = NULL;
    this->m_pSrvDetect = NULL;
    this->m_pSrvCounter = NULL;
    this->m_pSrvTrigger = NULL;
    this->m_pSrvPhysics = NULL;
    this->m_pSrvInput = NULL;
    this->m_pVideoManager = NULL;
    this->m_pUnk5 = NULL;
    this->m_pSavingManager = NULL;
    this->SetInstance();
}

CKYellowPages::~CKYellowPages() {}

extern s32 FUN_801bb454(void* pServiceManager, u32 c);
BOOL CKYellowPages::FindNonRecreableInstances(u32 a, u32 b, u32 c, s32* ppInstances)
{
    typedef BOOL (*FuncType)();
    BOOL found;
    s32 iVar2;
    u32 uVar1;
    switch(a)
    {
        case 0:
            if (b == 1)
            {
                *ppInstances = (int)this->m_pServiceManager;
            }
            else if (b == 2)
            {
                *ppInstances = (int)this->m_pGraphic;
            }
            else if (b == 3)
            {
                *ppInstances = (int)this->m_pSound;
            }
            else
            {
                if (b != 4)
                {
                    typedef u32 (*FuncType2)();
                    uVar1 = (*(FuncType2*)(*(int*)this->m_pGameLoop + 0x24))();
                    return uVar1;
                }
                *ppInstances = (int)this->m_pInput;
            }
            found = (*ppInstances != NULL);
            break;
        case 1:
            iVar2 = FUN_801bb454(this->m_pServiceManager,c);
            *ppInstances = iVar2;
            found = iVar2 != 0;
            break;
        case 2:
        case 4:
        case 12:
            found = (*(FuncType*)(*(int*)this->m_pCoreManager + 0x24))();
            break;
        case 10:
        case 13:
            found = (*(FuncType*)(*(int*)this->m_pGraphic + 0x24))();
            break;
        case 11:
            if (c == 6)
            {
                found = (*(FuncType*)(*(int*)this->m_pSrvCollision + 0x24))();
            }
            else
            {
                found = (*(FuncType*)(*(int*)this->m_pGraphic + 0x24))();
            }
        default:
            found = (c == 0);
            break;
    }
    return found;
}

void CKYellowPages::SetInstance()
{
    g_pYellowPages = this;
}

CKYellowPages* CKYellowPages::GetInstance()
{
    return g_pYellowPages;
}

void CKYellowPages::SetServiceCamera(void* pServiceCamera)
{
    g_pYellowPages->m_pSrvCamera = pServiceCamera;
}

void CKYellowPages::SetLoadingInterface(void* pLoadingInterface)
{
    g_pYellowPages->m_pLoadingInterface = pLoadingInterface;
}

void CKYellowPages::SetBeaconService(void* pBeaconService)
{
    g_pYellowPages->m_pSrvBeacon = pBeaconService;
}

void CKYellowPages::SetServiceAvoidance(void* pServiceAvoidance)
{
    g_pYellowPages->m_pSrvAvoidance = pServiceAvoidance;
}

void CKYellowPages::SetServiceCinematic(void *pServiceCinematic)
{
    g_pYellowPages->m_pSrvCinematic = pServiceCinematic;
}

void CKYellowPages::SetServiceSekensor(void* pServiceSekensor)
{
    g_pYellowPages->m_pSrvSekensor = pServiceSekensor;
}

void CKYellowPages::SetServiceShadow(void* pServiceShadow)
{
    g_pYellowPages->m_pSrvShadow = pServiceShadow;
}

void CKYellowPages::SetCurrentLevel(void* pCurrentLevel)
{
    g_pYellowPages->m_pCurrentLevel = pCurrentLevel;
}

void CKYellowPages::SetKGameManager(void *pKGameManager)
{
    g_pYellowPages->m_pKGameManager = pKGameManager;
}

void CKYellowPages::SetKGameUIManager(void *pKGameUIManager)
{
    g_pYellowPages->m_pKGameUIManager = pKGameUIManager;
}

void CKYellowPages::SetLocManager(void* pLocManager)
{
    g_pYellowPages->m_pLocManager = pLocManager;
}

void CKYellowPages::SetGraphicModule(void* pGraphicModule)
{
    g_pYellowPages->m_pGraphic = pGraphicModule;
}

void CKYellowPages::SetScreen(void* pScreen)
{
    g_pYellowPages->m_pScreen = pScreen;
}

void CKYellowPages::SetRendererRootNode(void* pRendererRootNode)
{
    g_pYellowPages->m_pRendererRootNode = pRendererRootNode;
}

void CKYellowPages::SetRootNode2(void* pRootNode2)
{
    g_pYellowPages->m_pUnkRootNode = pRootNode2;
}

void CKYellowPages::SetCommunSectorRootNode(void* pCommunSectorRootNode)
{
    g_pYellowPages->m_pCommunSectorRootNode = pCommunSectorRootNode;
}

void CKYellowPages::SetInputModule(void* pInputModule)
{
    g_pYellowPages->m_pInput = pInputModule;
}

void CKYellowPages::SetSoundModule(void* pSoundModule)
{
    g_pYellowPages->m_pSound = pSoundModule;
}

void CKYellowPages::SetCoreFactory(void* pCoreFactory)
{
    g_pYellowPages->m_pCoreFactory = pCoreFactory;
}

void CKYellowPages::SetServiceManager(void* pServiceManager)
{
    g_pYellowPages->m_pServiceManager = pServiceManager;
}

void CKYellowPages::SetServiceLife(void* pServiceLife)
{
    g_pYellowPages->m_pServiceLife = pServiceLife;
}

void CKYellowPages::SetCoreManager(void* pCoreManager)
{
    g_pYellowPages->m_pCoreManager = pCoreManager;
}

void CKYellowPages::SetFileIOManager(void* pFileIOManager)
{
    g_pYellowPages->m_pFileIOManager = pFileIOManager;
}

void CKYellowPages::SetGameLoop(void* pGameLoop)
{
    g_pYellowPages->m_pGameLoop = pGameLoop;
}

void CKYellowPages::SetManager2d(void* pManager2d)
{
    g_pYellowPages->m_pManager2d = pManager2d;
}

void CKYellowPages::SetTextureManager(void* pTextureManager)
{
    g_pYellowPages->m_pTextureManager = pTextureManager;
}

void CKYellowPages::SetAnimationManager(void* pAnimationManager)
{
    g_pYellowPages->m_pAnimationManager = pAnimationManager;
}

void CKYellowPages::SetTimeManager(void* pTimeManager)
{
    g_pYellowPages->m_pTimeManager = pTimeManager;
}

void CKYellowPages::SetTrcManager(void* pTrcManager)
{
    g_pYellowPages->m_pTrcManager = pTrcManager;
}

void CKYellowPages::SetSavingManager(void* pSavingManager)
{
    g_pYellowPages->m_pSavingManager = pSavingManager;
}

void CKYellowPages::SetLoadingManager(void* pLoadingManager)
{
    g_pYellowPages->m_pLoadingManager = pLoadingManager;
}

void CKYellowPages::SetServiceCollision(void* pServiceCollision)
{
    g_pYellowPages->m_pSrvCollision = pServiceCollision;
}

void CKYellowPages::SetServicePhysics(void* pServicePhysics)
{
    g_pYellowPages->m_pSrvPhysics = pServicePhysics;
}

void CKYellowPages::SetServicePathFinding(void* pServicePathFinding)
{
    g_pYellowPages->m_pSrvPathFinding = pServicePathFinding;
}

void CKYellowPages::SetServiceProjectiles(void* pServiceProjectiles)
{
    g_pYellowPages->m_pSrvProjectiles = pServiceProjectiles;
}

void CKYellowPages::SetServiceFx(void* pServiceFx)
{
    g_pYellowPages->m_pSrvFx = pServiceFx;
}

void CKYellowPages::SetServiceBonus(void* pServiceBonus)
{
    g_pYellowPages->m_pSrvBonus = pServiceBonus;
}

void CKYellowPages::SetServiceCounter(void* pServiceCounter)
{
    g_pYellowPages->m_pSrvCounter = pServiceCounter;
}

void CKYellowPages::SetServiceTrigger(void* pServiceTrigger)
{
    g_pYellowPages->m_pSrvTrigger = pServiceTrigger;
}

void CKYellowPages::SetServiceDetect(void* pServiceDetect)
{
    g_pYellowPages->m_pSrvDetect = pServiceDetect;
}

void CKYellowPages::SetFlashManager(void *pFlashManager)
{
    g_pYellowPages->m_pFlashManager = pFlashManager;
}

void CKYellowPages::SetServiceMusic(void *pServiceMusic)
{
    g_pYellowPages->m_pSrvMusic = pServiceMusic;
}

void CKYellowPages::SetServiceInput(void *pServiceInput)
{
    g_pYellowPages->m_pSrvInput = pServiceInput;
}

void CKYellowPages::SetVideoManager(void* pVideoManager)
{
    g_pYellowPages->m_pVideoManager = pVideoManager;
}

void CKYellowPages::SetUnk6(void* pUnk6)
{
    g_pYellowPages->m_pUnk6 = pUnk6;
}

void CKYellowPages::SetUnk5(void* pUnk5)
{
    g_pYellowPages->m_pUnk5 = pUnk5;
}

void CKYellowPages::SetUnk1(void* pUnk1)
{
    g_pYellowPages->m_pUnk1 = pUnk1;
}

void CKYellowPages::SetUnk3(void *pUnk3)
{
    g_pYellowPages->m_pUnk3 = pUnk3;
}

void CKYellowPages::SetServiceInputCommands(void *pServiceInputCommands)
{
    g_pYellowPages->m_pSrvInputCommands = pServiceInputCommands;
}

void CKYellowPages::SetUnk2(void* pUnk2)
{
    g_pYellowPages->m_pUnk2 = pUnk2;
}

void CKYellowPages::SetUnk4(void* pUnk4)
{
    g_pYellowPages->m_pUnk4 = pUnk4;
}

void* CKYellowPages::GetLoadingInterface()
{
    return g_pYellowPages->m_pLoadingInterface;
}

void* CKYellowPages::GetGraphicModule()
{
    return g_pYellowPages->m_pGraphic;
}

void* CKYellowPages::GetScreen()
{
    return g_pYellowPages->m_pScreen;
}

void* CKYellowPages::GetRendererRootNode()
{
    return g_pYellowPages->m_pRendererRootNode;
}

void* CKYellowPages::GetRootNode2()
{
    return g_pYellowPages->m_pUnkRootNode;
}

void* CKYellowPages::GetCommunSectorRootNode()
{
    return g_pYellowPages->m_pCommunSectorRootNode;
}

void* CKYellowPages::GetInputModule()
{
    return g_pYellowPages->m_pInput;
}

void* CKYellowPages::GetSoundModule()
{
    return g_pYellowPages->m_pSound;
}

void* CKYellowPages::GetCoreFactory()
{
    return g_pYellowPages->m_pCoreFactory;
}

void* CKYellowPages::GetServiceManager()
{
    return g_pYellowPages->m_pServiceManager;
}

void* CKYellowPages::GetServiceLife()
{
    return g_pYellowPages->m_pServiceLife;
}

void* CKYellowPages::GetCoreManager()
{
    return g_pYellowPages->m_pCoreManager;
}

void* CKYellowPages::GetFileIOManager()
{
    return g_pYellowPages->m_pFileIOManager;
}

void* CKYellowPages::GetGameLoop()
{
    return g_pYellowPages->m_pGameLoop;
}

void* CKYellowPages::GetManager2d()
{
    return g_pYellowPages->m_pManager2d;
}

void* CKYellowPages::GetFlashManager()
{
    return g_pYellowPages->m_pFlashManager;
}

void* CKYellowPages::GetTextureManager()
{
    return g_pYellowPages->m_pTextureManager;
}

void* CKYellowPages::GetAnimationManager()
{
    return g_pYellowPages->m_pAnimationManager;
}

void* CKYellowPages::GetTimeManager()
{
    return g_pYellowPages->m_pTimeManager;
}

void* CKYellowPages::GetLoadingManager()
{
    return g_pYellowPages->m_pLoadingManager;
}

void* CKYellowPages::GetSavingManager()
{
    return g_pYellowPages->m_pSavingManager;
}

void* CKYellowPages::GetUnk6()
{
    return g_pYellowPages->m_pUnk6;
}

void* CKYellowPages::GetServiceCollision()
{
    return g_pYellowPages->m_pSrvCollision;
}

void* CKYellowPages::GetServicePhysics()
{
    return g_pYellowPages->m_pSrvPhysics;
}

void* CKYellowPages::GetServiceFx()
{
    return g_pYellowPages->m_pSrvFx;
}

void* CKYellowPages::GetServiceBonus()
{
    return g_pYellowPages->m_pSrvBonus;
}

void* CKYellowPages::GetServiceProjectiles()
{
    return g_pYellowPages->m_pSrvProjectiles;
}

void* CKYellowPages::GetServicePathFinding()
{
    return g_pYellowPages->m_pSrvPathFinding;
}

void* CKYellowPages::GetServiceCamera()
{
    return g_pYellowPages->m_pSrvCamera;
}

void* CKYellowPages::GetServiceAvoidance()
{
    return g_pYellowPages->m_pSrvAvoidance;
}

void* CKYellowPages::GetServiceBeacon()
{
    return g_pYellowPages->m_pSrvBeacon;
}

void* CKYellowPages::GetTrcManager()
{
    return g_pYellowPages->m_pTrcManager;
}

void* CKYellowPages::GetServiceCinematic()
{
    return g_pYellowPages->m_pSrvCinematic;
}

void* CKYellowPages::GetServiceSekensor()
{
    return g_pYellowPages->m_pSrvSekensor;
}

void* CKYellowPages::GetServiceShadow()
{
    return g_pYellowPages->m_pSrvShadow;
}

void* CKYellowPages::GetKGameManager()
{
    return g_pYellowPages->m_pKGameManager;
}

void* CKYellowPages::GetKGameUIManager()
{
    return g_pYellowPages->m_pKGameUIManager;
}

void* CKYellowPages::GetCurrentLevel()
{
    return g_pYellowPages->m_pCurrentLevel;
}

void* CKYellowPages::GetLocManager()
{
    return g_pYellowPages->m_pLocManager;
}

void* CKYellowPages::GetServiceCounter()
{
    return g_pYellowPages->m_pSrvCounter;
}

void* CKYellowPages::GetServiceTrigger()
{
    return g_pYellowPages->m_pSrvTrigger;
}

void* CKYellowPages::GetServiceDetect()
{
    return g_pYellowPages->m_pSrvDetect;
}

void* CKYellowPages::GetServiceMusic()
{
    return g_pYellowPages->m_pSrvMusic;
}

void* CKYellowPages::GetServiceInput()
{
    return g_pYellowPages->m_pSrvInput;
}

void* CKYellowPages::GetVideoManager()
{
    return g_pYellowPages->m_pVideoManager;
}

void* CKYellowPages::GetUnk1()
{
    return g_pYellowPages->m_pUnk1;
}

void* CKYellowPages::GetUnk2()
{
    return g_pYellowPages->m_pUnk2;
}

void* CKYellowPages::GetUnk3()
{
    return g_pYellowPages->m_pUnk3;
}

void* CKYellowPages::GetServiceInputCommands()
{
    return g_pYellowPages->m_pSrvInputCommands;
}

void* CKYellowPages::GetUnk4()
{
    return g_pYellowPages->m_pUnk4;
}

void* CKYellowPages::GetUnk5()
{
    return g_pYellowPages->m_pUnk5;
}
