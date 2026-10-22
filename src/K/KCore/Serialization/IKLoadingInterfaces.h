#ifndef K_KCORE_SERIALIZATION_IKLOADINGINTERFACES_H
    #define K_KCORE_SERIALIZATION_IKLOADINGINTERFACES_H

    #include "K/KTypes.h"
    #include "K/KCore/Interfaces/IKBaseClass.h"

    class IKFile;
    class IKSerializable;

    class IKLoadingInterfaces: public IKBaseClass
    {
        enum CLASS_INFO
        {
            CLASS_ID = 0x24,
            CLASS_TYPE = 0x3E,
        };

        public:
            IKLoadingInterfaces(): IKBaseClass::IKBaseClass() {};
            virtual ~IKLoadingInterfaces() {};
            virtual BOOL IsKindOfClass(KClassIdentifier a_iClassIdentifier)
            {
                if (a_iClassIdentifier == K_FULL_ID(CLASS_TYPE, CLASS_ID)) return TRUE;
                return IKBaseClass::IsKindOfClass();
            };
            virtual u32 ReadHandle(IKFile* pFile, IKSerializable** ppObject) = 0;
            virtual u32 ReadContiguousHandles(IKFile* pFile, IKSerializable** ppObjects, s32 count) = 0;
            virtual u32 ReadTexture(IKFile* pFile, void** ppTexture) = 0;
    };

#endif // K_KCORE_SERIALIZATION_IKLOADINGINTERFACES_H
