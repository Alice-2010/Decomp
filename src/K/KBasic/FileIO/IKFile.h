#ifndef K_KBASIC_FILEIO_IKFILE_H
    #define K_KBASIC_FILEIO_IKFILE_H

    #include "types.h"
    #include "K/KTypes.h"
    #include "RW/rwplcore.h"

    class IKFile
    {
        protected:
            enum EInternalOpenMode
            {
                MODE_INTERNAL_READ = 1,
                MODE_INTERNAL_WRITE = 2,
                MODE_INTERNAL_READ_WRITE = 3,
                MODE_INTERNAL_UNDEFINED = 4,
            };
            
            enum ESeekPosition
            {
                BEGIN,
                CURRENT,
                END
            };

            enum EOpenFlags
            {
                MODE_READ,
                MODE_WRITE,
                MODE_READ_WRITE,
                MODE_APPEND,
                MODE_READ_TXT,
                MODE_WRITE_TXT,
                MODE_READ_WRITE_TXT,
                MODE_APPEND_TXT,
                MODE_MAX
            };

            RwStream* m_pRwStream; // 0x4
            EInternalOpenMode m_eInternalOpenMode; // 0x8
            void* m_pSavingInterfaces; // 0xC
            void* m_pLoadingInterfaces; // 0x10
            BOOL m_bSaveAndLoadForKal; // 0x14

        public:
            EInternalOpenMode GetInternalOpenMode();
            void SetInternalOpenMode(EInternalOpenMode mode);
            BOOL IsWriteEnabled();
            BOOL IsReadEnabled();
            void* GetSavingInterface();
            void* GetLoadingInterface();
            virtual BOOL Open(const char*, EOpenFlags);
            virtual BOOL Open(const char*, EOpenFlags, s32);
            IKFile();
            virtual ~IKFile();
            virtual s32 Close();
            RwStream* GetRwStream();
            void SetRwStream(RwStream* pStream);
            virtual u32 Read(void*, u32);
            virtual u32 Write();
            virtual void Seek();
            virtual void GetString();
            virtual void PutString();
            void Printf();
            void Eof();
            virtual s32 Flush();
            void Tell();
            void GetFileLength();
            s8 ReadInt8();
            void WriteInt8(s8 value);
            u8 ReadUInt8();
            void WriteUInt8(u8 value);
            s16 ReadInt16();
            void WriteInt16(s16 value);
            u16 ReadUInt16();
            void WriteUInt16(u16 value);
            s32 ReadInt32();
            void WriteInt32(s32 value);
            u32 ReadUInt32();
            void WriteUInt32(u32 value);
            u64 ReadUInt64();
            void WriteUInt64(u64 value);
            f32 ReadFloat32(f32*, ESerializationType);
            void WriteFloat32(f32 value);
    };

#endif // K_KBASIC_FILEIO_IKFILE_H
