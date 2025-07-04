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

void CKYellowPages::SetServiceCamera(void* pServiceCamera)
{
    g_pYellowPages->m_pSrvCamera = pServiceCamera;
}

void CKYellowPages::SetInstance()
{
    g_pYellowPages = this;
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
