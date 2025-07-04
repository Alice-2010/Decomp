#ifndef CKYELLOWPAGES_H
    #define CKYELLOWPAGES_H

    #include "types.h"

    class CKYellowPages
    {
        public:
            void* m_pLoadingInterface; // 0x00
            void* m_pGraphic; // 0x04
            void* m_pScreen; // 0x08
            void* m_pRendererRootNode; // 0x0C
            void* m_pCommunSectorRootNode; // 0x10
            void* m_pInput; // 0x14
            void* m_pSound; // 0x18
            void* m_pCoreFactory; // 0x1C
            void* m_pServiceManager; // 0x20
            void* m_pServiceLife; // 0x24
            void* m_pCoreManager; // 0x28
            void* m_pFileIOManager; // 0x2C
            void* m_pGameLoop; // 0x30
            void* m_pManager2d; // 0x34
            void* m_pFlashManager; // 0x38
            void* m_pTextureManager; // 0x3C
            void* m_pAnimationManager; // 0x40
            void* m_pTimeManager; // 0x44
            void* m_pLoadingManager; // 0x48
            void* m_pSavingManager; // 0x4C
            void* m_pKParams; // 0x50
            void* m_pSrvCollision; // 0x54
            void* m_pSrvFx; // 0x58
            void* m_pSrvProjectiles; // 0x5C
            void* m_pSrvPathFinding; // 0x60
            void* m_pSrvCamera; // 0x64
            void* m_pSrvAvoidance; // 0x68
            void* m_pSrvBeacon; // 0x6C
            void* m_pTrcManager; // 0x70
            void* m_pSrvCinematic; // 0x74
            void* m_pSrvSekensor; // 0x78
            void* m_pSrvShadow; // 0x7C
            void* m_pKGameManager; // 0x80
            void* m_pCurrentLevel; // 0x84
            void* m_pLocManager; // 0x88
            void* m_pSrvCounter; // 0x8C
            void* m_pSrvTrigger; // 0x90
            void* m_pSrvDetect; // 0x94
            void* m_pSrvMusic; // 0x98
            void* m_pVideoManager; // 0x9C
            void* m_pErrorManager; // 0xA0
            void* m_pUnk1; // 0xA4
            void* m_pUnk2; // 0xA8
            void* m_pUnk3; // 0xAC
            void* m_pUnk4; // 0xB0
            void* m_pUnk5; // 0xB4
            void* m_pUnk6; // 0xB8
            void* m_pUnk7; // 0xBC
            void* m_pUnk8; // 0xC0
            void* m_pUnk9; // 0xC4
            void* m_pUnk10; // 0xC8

            CKYellowPages();
            ~CKYellowPages();
            BOOL FindNonRecreableInstances();
            void SetInstance();
            CKYellowPages* GetInstance();
    };

#endif
