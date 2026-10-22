#ifndef K_KCORE_SERIALIZATION_CKBUNDLELOAD_H
    #define K_KCORE_SERIALIZATION_CKBUNDLELOAD_H

    #include "K/KTypes.h"
    #include "K/KBasic/FileIO/IKFile.h"
    #include "K/KCore/Interfaces/IKSerializable.h"

    class CKIDBundleLoad
    {
        public:
            union
            {
                IKSerializable* m_pRecreableInstances;
                IKSerializable** m_ppNotRecreableInstances;
            }; // 0x0
            IKSerializable** m_apGameRecreableInstances; // 0x4
            u32 m_ui32TyIdInst; // 0x8
            s32 m_i32Seek; // 0xC
            u16 m_ui16NbInstOffset; // 0x10
            u16 m_ui16NbCommunInst; // 0x12
            u16 m_ui16NbGameInst; // 0x14
            u16 m_ui16SizeOfClass; // 0x16
            u8 m_ui8StreamType; // 0x18
            BOOL m_bIsGUID; // 0x19

            CKIDBundleLoad();
            ~CKIDBundleLoad();
            u32 LoadAllInstances(IKFile*, ESerializationType, s8, s32&);
            void PostLoadAllInstances(ESerializationType, s8);
            void DestroyAllInstances(s8, s32&);
            BOOL ReadIDChunk(IKFile*);
            BOOL IsRecreable();
            BOOL IsMergeable();
            BOOL IsGUID();
    };

    class CKTypeBundleLoad
    {
        public:
            CKIDBundleLoad* m_pID; // 0x0
            u16 m_ui16NbReadID; // 0x4
            u16 m_ui16NbCommunReadID; // 0x6
            s32 m_i32Seek; // 0x8

            CKTypeBundleLoad();
            ~CKTypeBundleLoad();
            KError LoadAllIDs(IKFile* pFile, ESerializationType iSerializationType, s8* pLoadedStream, s32& iNbStreams);
            void PostLoadAllIDs(ESerializationType iSerializationType, s8 loadedStream);
            BOOL DestroyAllIDs(s8, s32&);
            BOOL ReadTypeChunk(IKFile* pFile, s8);
    };

#endif // K_KCORE_SERIALIZATION_CKBUNDLELOAD_H
