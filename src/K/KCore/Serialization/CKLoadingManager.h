#ifndef K_KCORE_SERIALIZATION_CKLOADINGMANAGER_H
    #define K_KCORE_SERIALIZATION_CKLOADINGMANAGER_H

    #include "K/KCore/Serialization/IKLoadingInterfaces.h"
    #include "K/KCore/Serialization/CKBundleLoad.h"

    class CGuid
    {
    public:
        u32 m_u32Data1;
        u32 m_u32Data2;
        u32 m_u32Data3;
        u32 m_u32Data4;

        CGuid();
        void Load(IKFile* pFile);
    };

    class CKLoadingManager: public IKLoadingInterfaces
    {
        enum CLASS_INFO
        {
            CLASS_ID = 0x7,
            CLASS_TYPE = 0xC,
        };
        enum EStreamState
        {
            LOADING = 0,
            LOADED = 1,
            UNLOADING = 2,
            UNLOADED = 3,
        };

        private:
            CKTypeBundleLoad* m_pTypeBundleLoad; // 0x0
            CKIDBundleLoad* m_pIdBundleLoad; // 0x4
            IKSerializable** m_apKGameRegisteredInstances; // 0x8
            u32 m_ui32KGameNbRegisteredInstances; // 0xC
            s32 m_i32NbLoadedInstances; // 0x10
            u32 m_ui32NumPointer; // 0x14
            u32 m_ui32NbStreams; // 0x18
            s32 m_i32NumCurrentLevel; // 0x1C
            s8 m_ai8LoadedStream[4]; // 0x20
            EStreamState m_aeStreamStates[127]; // 0x24
            ESerializationType m_iSerializationType; // 0x224
            CGuid m_kGameGUID; // 0x228
            char m_tStreamingSemaphore[8]; // 0x238 - type TSemaphore
            char m_tStreamingThread[8]; // 0x240 - type TThread

        public:
            CKLoadingManager();
            virtual ~CKLoadingManager();
            virtual BOOL IsKindOfClass(KClassIdentifier);
            virtual s32 GetClassType();
            virtual s32 GetClassID();
            virtual u32 ReadHandle(IKFile*, IKSerializable**);
            virtual u32 ReadContiguousHandles(IKFile*, IKSerializable**, s32);
            virtual u32 ReadTexture(IKFile*, void**);
            virtual s32 KUInitialize();
            virtual void KUDestroy();
            s32 GetLevelNumber();
            void HandleToPointer(IKSerializable** ppObject);
    };

#endif // K_KCORE_SERIALIZATION_CKLOADINGMANAGER_H
