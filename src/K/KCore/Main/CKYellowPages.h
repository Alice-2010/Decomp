#ifndef CKYELLOWPAGES_H
    #define CKYELLOWPAGES_H

    class CKYellowPages
    {
        public:
            void* m_pLoadingInterface; // 0x00
            void* m_pGraphic; // 0x04
            void* m_pScreen; // 0x08
            void* m_pRendererRootNode; // 0x0C
            void* m_pUnkRootNode; // 0x10
            void* m_pCommunSectorRootNode; // 0x14
            void* m_pInput; // 0x18
            void* m_pSound; // 0x1C
            void* m_pCoreFactory; // 0x20
            void* m_pServiceManager; // 0x24
            void* m_pServiceLife; // 0x28
            void* m_pCoreManager; // 0x2C
            void* m_pFileIOManager; // 0x30
            void* m_pGameLoop; // 0x34
            void* m_pManager2d; // 0x38
            void* m_pFlashManager; // 0x3C
            void* m_pTextureManager; // 0x40
            void* m_pAnimationManager; // 0x44
            void* m_pTimeManager; // 0x48
            void* m_pLoadingManager; // 0x4C
            void* m_pSavingManager; // 0x50
            void* m_pUnk6; // 0x54 - CKParams??
            void* m_pSrvCollision; // 0x58
            void* m_pSrvPhysics; // 0x5C
            void* m_pSrvFx; // 0x60
            void* m_pSrvBonus; // 0x64
            void* m_pSrvProjectiles; // 0x68
            void* m_pSrvPathFinding; // 0x6C
            void* m_pSrvCamera; // 0x70
            void* m_pSrvAvoidance; // 0x74
            void* m_pSrvBeacon; // 0x78
            void* m_pTrcManager; // 0x7C
            void* m_pSrvCinematic; // 0x80
            void* m_pSrvSekensor; // 0x84
            void* m_pSrvShadow; // 0x88
            void* m_pKGameManager; // 0x8C
            void* m_pKGameUIManager; // 0x90
            void* m_pCurrentLevel; // 0x94
            void* m_pLocManager; // 0x98
            void* m_pSrvCounter; // 0x9C
            void* m_pSrvTrigger; // 0xA0
            void* m_pSrvDetect; // 0xA4
            void* m_pSrvMusic; // 0xA8
            void* m_pSrvInput; // 0xAC
            void* m_pVideoManager; // 0xB0
            void* m_pUnk1; // 0xB4
            void* m_pUnk2; // 0xB8
            void* m_pUnk3; // 0xBC
            void* m_pSrvInputCommands; // 0xC0
            void* m_pUnk4; // 0xC4
            void* m_pUnk5; // 0xC8

            CKYellowPages();
            ~CKYellowPages();
            static void SetServiceCamera(void* pServiceCamera);
            void SetInstance();
            CKYellowPages* GetInstance();
            static void SetLoadingInterface(void* pLoadingInterface);
            static void SetBeaconService(void* pBeaconService);
            static void SetServiceAvoidance(void* pServiceAvoidance);
            static void SetServiceCinematic(void* pServiceCinematic);
            static void SetServiceSekensor(void* pServiceSekensor);
            static void SetServiceShadow(void* pServiceShadow);
            static void SetCurrentLevel(void* pCurrentLevel);
            static void SetKGameManager(void* pKGameManager);
            static void SetKGameUIManager(void* pKGameUIManager);
            static void SetLocManager(void* pLocManager);
            static void SetGraphicModule(void* pGraphicModule);
            static void SetScreen(void* pScreen);
            static void SetRendererRootNode(void* pRendererRootNode);
            static void SetRootNode2(void* pRootNode2);
            static void SetCommunSectorRootNode(void* pCommunSectorRootNode);
            static void SetInputModule(void* pInputModule);
            static void SetSoundModule(void* pSoundModule);
            static void SetCoreFactory(void* pCoreFactory);
            static void SetServiceManager(void* pServiceManager);
            static void SetServiceLife(void* pServiceLife);
            static void SetCoreManager(void* pCoreManager);
            static void SetFileIOManager(void* pFileIOManager);
            static void SetGameLoop(void* pGameLoop);
            static void SetManager2d(void* pManager2d);
            static void SetTextureManager(void* pTextureManager);
            static void SetAnimationManager(void* pAnimationManager);
            static void SetTimeManager(void* pTimeManager);
            static void SetTrcManager(void* pTrcManager);
            static void SetSavingManager(void* pSavingManager);
            static void SetLoadingManager(void* pLoadingManager);
            static void SetServiceCollision(void* pServiceCollision);
            static void SetServicePhysics(void* pServicePhysics);
            static void SetServicePathFinding(void* pServicePathFinding);
            static void SetServiceProjectiles(void* pServiceProjectiles);
            static void SetServiceFx(void* pServiceFx);
            static void SetServiceBonus(void* pServiceBonus);
            static void SetServiceCounter(void* pServiceCounter);
            static void SetServiceTrigger(void* pServiceTrigger);
            static void SetServiceDetect(void* pServiceDetect);
            static void SetFlashManager(void* pFlashManager);
            static void SetServiceMusic(void* pServiceMusic);
            static void SetServiceInput(void* pServiceInput);
            static void SetVideoManager(void* pVideoManager);
            static void SetUnk6(void* pUnk6);
            static void SetUnk5(void* pUnk5);
            static void SetUnk1(void* pUnk1);
            static void SetUnk3(void* pUnk3);
            static void SetServiceInputCommands(void* pServiceInputCommands);
            static void SetUnk2(void* pUnk2);
            static void SetUnk4(void* pUnk4);

            static inline void* GetLoadingInterface();
            static inline void* GetGraphicModule();
            static inline void* GetScreen();
            static inline void* GetRendererRootNode();
            static inline void* GetRootNode2();
            static inline void* GetCommunSectorRootNode();
            static inline void* GetInputModule();
            static inline void* GetSoundModule();
            static inline void* GetCoreFactory();
            static inline void* GetServiceManager();
            static inline void* GetServiceLife(); // unused + stripped?
            static inline void* GetCoreManager();
            static inline void* GetFileIOManager();
            static inline void* GetGameLoop();
            static inline void* GetManager2d();
            static inline void* GetFlashManager();
            static inline void* GetTextureManager();
            static inline void* GetAnimationManager();
            static inline void* GetTimeManager();
            static inline void* GetLoadingManager();
            static inline void* GetSavingManager();
            static inline void* GetUnk6();
            static inline void* GetServiceCollision();
            static inline void* GetServicePhysics();
            static inline void* GetServiceFx();
            static inline void* GetServiceBonus();
            static inline void* GetServiceProjectiles(); // unused + stripped?
            static inline void* GetServicePathFinding();
            static inline void* GetServiceCamera();
            static inline void* GetServiceAvoidance();
            static inline void* GetServiceBeacon();
            static inline void* GetTrcManager();
            static inline void* GetServiceCinematic();
            static inline void* GetServiceSekensor();
            static inline void* GetServiceShadow();
            static inline void* GetKGameManager();
            static inline void* GetKGameUIManager();
            static inline void* GetCurrentLevel();
            static inline void* GetLocManager();
            static inline void* GetServiceCounter(); // unused + stripped?
            static inline void* GetServiceTrigger();
            static inline void* GetServiceDetect();
            static inline void* GetServiceMusic();
            static inline void* GetServiceInput();
            static inline void* GetVideoManager();
            static inline void* GetUnk1(); // unused + stripped?
            static inline void* GetUnk2();
            static inline void* GetUnk3(); // unused + stripped?
            static inline void* GetServiceInputCommands();
            static inline void* GetUnk4(); // unused + stripped?
            static inline void* GetUnk5(); // unused + stripped?
    };

#endif
