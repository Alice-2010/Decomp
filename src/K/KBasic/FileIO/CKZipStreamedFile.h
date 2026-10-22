#ifndef K_KBASIC_FILEIO_CKZIPSTREAMEDFILE_H
    #define K_KBASIC_FILEIO_CKZIPSTREAMEDFILE_H

    #include "K/KBasic/FileIO/IKSBufferFile.h"
    #include "K/KCore/Interfaces/IKSerializable.h"

    class CKZipStreamedFile : public IKSBufferFile
    {
        public:
            u32 ReadHandle(IKSerializable** ppObject, s32 count);
    };

#endif // K_KBASIC_FILEIO_CKZIPSTREAMEDFILE_H
