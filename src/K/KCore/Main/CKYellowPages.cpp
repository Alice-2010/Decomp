#include "K/KCore/Main/CKYellowPages.h"

CKYellowPages* g_pYellowPages;

CKYellowPages::CKYellowPages()
{
    this->m_pLoadingInterface = NULL;
    this->m_pGraphic = NULL;
    this->m_pScreen = NULL;
    this->m_pRendererRootNode = NULL;
    this->m_pAnimationManager = NULL;
    this->m_pInput = NULL;
    this->m_pServiceManager = NULL;
    this->m_pServiceLife = NULL;
    this->m_pGameLoop = NULL;
    this->m_pFileIOManager = NULL;
    this->m_pManager2d = NULL;
    this->m_pAnimationManager = NULL;
    this->m_pTimeManager = NULL;
    this->m_pSavingManager = NULL;
    this->m_pLoadingInterface = NULL;
    this->m_pSrvFx = NULL;
    this->m_pSrvBeacon = NULL;
    this->m_pTrcManager = NULL;
    this->m_pKGameManager = NULL;
    this->m_pSrvShadow = NULL;
    this->m_pFlashManager = NULL;
    this->m_pSrvCounter = NULL;
    this->m_pSrvTrigger = NULL;
    this->m_pSrvDetect = NULL;
    this->m_pSrvMusic = NULL;
    this->m_pSrvSekensor = NULL;
    this->m_pSound = NULL;
    this->m_pCoreFactory = NULL;
    this->m_pCoreManager = NULL;
    this->m_pSrvCinematic = NULL;
    this->m_pCurrentLevel = NULL;
    this->m_pLocManager = NULL;
    this->m_pSrvPathFinding = NULL;
    this->m_pSrvAvoidance = NULL;
    this->m_pTextureManager = NULL;
    this->m_pUnk2 = NULL;
    this->m_pSrvCamera = NULL;
    this->m_pUnk5 = NULL;
    this->m_pCommunSectorRootNode = NULL;
    this->m_pUnk1 = NULL;
    this->m_pVideoManager = NULL;
    this->m_pErrorManager = NULL;
    this->m_pSrvProjectiles = NULL;
    this->m_pUnk3 = NULL;
    this->m_pUnk4 = NULL;
    this->m_pUnk10 = NULL;
    this->m_pKParams = NULL;
    this->SetInstance();
}

CKYellowPages::~CKYellowPages() {}

void CKYellowPages::SetInstance()
{
    g_pYellowPages = this;
}
