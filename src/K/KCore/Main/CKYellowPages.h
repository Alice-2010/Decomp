#ifndef CKYELLOWPAGES_H
    #define CKYELLOWPAGES_H

    #include "K/KCore/Interfaces/IKSerializable.h"
    #include "K/KCore/Serialization/CKSavingManager.h"
    #include "K/KCore/Main/CKParams.h"

    class CKYellowPages
    {
        public:
            void* m_pLoadingInterface; // 0x00
            IKSerializable* m_pGraphic; // 0x04
            void* m_pScreen; // 0x08
            void* m_pRendererRootNode; // 0x0C
            void* m_pUnkRootNode; // 0x10
            void* m_pCommunSectorRootNode; // 0x14
            void* m_pInput; // 0x18
            void* m_pSound; // 0x1C
            void* m_pCoreFactory; // 0x20
            IKSerializable* m_pServiceManager; // 0x24
            void* m_pServiceLife; // 0x28
            IKSerializable* m_pCoreManager; // 0x2C
            void* m_pFileIOManager; // 0x30
            IKSerializable* m_pGameLoop; // 0x34
            void* m_pManager2d; // 0x38
            void* m_pFlashManager; // 0x3C
            void* m_pTextureManager; // 0x40
            void* m_pAnimationManager; // 0x44
            void* m_pTimeManager; // 0x48
            void* m_pLoadingManager; // 0x4C
            CKSavingManager* m_pSavingManager; // 0x50
            CKParams* m_pKParams; // 0x54
            IKSerializable* m_pSrvCollision; // 0x58
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
            void* m_pSrvNetwork; // 0xB4
            void* m_pUnk2; // 0xB8
            void* m_pSrvDynamic; // 0xBC
            void* m_pSrvInputCommands; // 0xC0
            void* m_pVirtualKeyboardManager; // 0xC4
            void* m_pErrorManager; // 0xC8

            CKYellowPages();
            ~CKYellowPages();
            BOOL FindNonRecreableInstances(u32, u32, u32, IKBaseClass***);
            static void SetServiceCamera(void*);
            void SetInstance();
            CKYellowPages* GetInstance();
            static void SetLoadingInterface(void*);
            static void SetBeaconService(void*);
            static void SetServiceAvoidance(void*);
            static void SetServiceCinematic(void*);
            static void SetServiceSekensor(void*);
            static void SetServiceShadow(void*);
            static void SetCurrentLevel(void*);
            static void SetKGameManager(void*);
            static void SetKGameUIManager(void*);
            static void SetLocManager(void*);
            static void SetGraphicModule(IKSerializable*);
            static void SetScreen(void*);
            static void SetRendererRootNode(void*);
            static void SetRootNode2(void*);
            static void SetCommunSectorRootNode(void*);
            static void SetInputModule(void*);
            static void SetSoundModule(void*);
            static void SetCoreFactory(void*);
            static void SetServiceManager(IKSerializable*);
            static void SetServiceLife(void*);
            static void SetCoreManager(IKSerializable*);
            static void SetFileIOManager(void*);
            static void SetGameLoop(IKSerializable*);
            static void SetManager2d(void*);
            static void SetTextureManager(void*);
            static void SetAnimationManager(void*);
            static void SetTimeManager(void*);
            static void SetTrcManager(void*);
            static void SetSavingManager(CKSavingManager*);
            static void SetLoadingManager(void*);
            static void SetServiceCollision(IKSerializable*);
            static void SetServicePhysics(void*);
            static void SetServicePathFinding(void*);
            static void SetServiceProjectiles(void*);
            static void SetServiceFx(void*);
            static void SetServiceBonus(void*);
            static void SetServiceCounter(void*);
            static void SetServiceTrigger(void*);
            static void SetServiceDetect(void*);
            static void SetFlashManager(void*);
            static void SetServiceMusic(void*);
            static void SetServiceInput(void*);
            static void SetVideoManager(void*);
            static void SetKParams(CKParams*);
            static void SetErrorManager(void*);
            static void SetSrvNetwork(void*);
            static void SetSrvDynamic(void*);
            static void SetServiceInputCommands(void*);
            static void SetUnk2(void*);
            static void SetVirtualKeyboardManager(void*);

            static void* GetLoadingInterface();
            static IKSerializable* GetGraphicModule();
            static void* GetScreen();
            static void* GetRendererRootNode();
            static void* GetRootNode2();
            static void* GetCommunSectorRootNode();
            static void* GetInputModule();
            static void* GetSoundModule();
            static void* GetCoreFactory();
            static IKSerializable* GetServiceManager();
            static void* GetServiceLife(); // unused + stripped?
            static IKSerializable* GetCoreManager();
            static void* GetFileIOManager();
            static IKSerializable* GetGameLoop();
            static void* GetManager2d();
            static void* GetFlashManager();
            static void* GetTextureManager();
            static void* GetAnimationManager();
            static void* GetTimeManager();
            static void* GetLoadingManager();
            static CKSavingManager* GetSavingManager();
            static CKParams* GetKParams();
            static IKSerializable* GetServiceCollision();
            static void* GetServicePhysics();
            static void* GetServiceFx();
            static void* GetServiceBonus();
            static void* GetServiceProjectiles(); // unused + stripped?
            static void* GetServicePathFinding();
            static void* GetServiceCamera();
            static void* GetServiceAvoidance();
            static void* GetServiceBeacon();
            static void* GetTrcManager();
            static void* GetServiceCinematic();
            static void* GetServiceSekensor();
            static void* GetServiceShadow();
            static void* GetKGameManager();
            static void* GetKGameUIManager();
            static void* GetCurrentLevel();
            static void* GetLocManager();
            static void* GetServiceCounter(); // unused + stripped?
            static void* GetServiceTrigger();
            static void* GetServiceDetect();
            static void* GetServiceMusic();
            static void* GetServiceInput();
            static void* GetVideoManager();
            static void* GetSrvNetwork(); // unused + stripped?
            static void* GetUnk2();
            static void* GetSrvDynamic(); // unused + stripped?
            static void* GetServiceInputCommands();
            static void* GetVirtualKeyboardManager(); // unused + stripped?
            static void* GetErrorManager(); // unused + stripped?
    };

#endif
