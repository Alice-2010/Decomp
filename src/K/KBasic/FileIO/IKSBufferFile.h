#ifndef K_KBASIC_FILEIO_IKSBUFFERFILE_H
    #define K_KBASIC_FILEIO_IKSBUFFERFILE_H

    #include "K/KBasic/FileIO/IKFile.h"

    class IKSBufferFile : public IKFile {
        protected:
            void* m_pvUnalignedBuffer; // 0x18
            u8* m_aui8Buffer; // 0x1C
            s32 m_i32BufferSize; // 0x20
            s32 m_i32BufferAlignement; // 0x24
            s32 m_i32CurrentPos; // 0x28
            s32 m_i32CurrentBufferPos; // 0x2C
            s32 m_i32CurrentLogicalBufferPosition; // 0x30
            s32 m_i32EOFPosition; // 0x34
            BOOL m_bNeedFlush; // 0x38

        public:
            IKSBufferFile();
            IKSBufferFile(s32, s32);
            virtual ~IKSBufferFile();
            virtual u32 Read(void*, u32);
            virtual u32 Write(const void*, u32);
            virtual s32 Seek(s32, ESeekPosition);
            virtual s32 Eof();
            virtual s32 Tell();
            virtual s32 GetFileLength();
            virtual s32 OperateBuffer(const void*, void*, s32, s32);
            virtual s32 Flush();
            BOOL BasicOpen(s32);
            BOOL BasicClose();
            s32 GetEofPosition();
            void SetEofPosition(s32);
    };

#endif // K_KBASIC_FILEIO_IKSBUFFERFILE_H
