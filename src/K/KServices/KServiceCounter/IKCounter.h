#ifndef K_KSERVICES_KSERVICECOUNTER_IKCOUNTER_H
    #define K_KSERVICES_KSERVICECOUNTER_IKCOUNTER_H

    #include "K/KTypes.h"
    #include "K/KCore/Interfaces/IKSerializable.h"

    class IKCounter : public IKSerializable
    {
        enum CLASS_INFO
        {
            CLASS_ID = 0x86,
            CLASS_VERSION = 0x1,
            CLASS_TYPE = 0xC
        };

        public:
            IKCounter();
            virtual ~IKCounter();
            virtual BOOL IsKindOfClass(KClassIdentifier);
            virtual KError Load();
            virtual KError Save();
    };

#endif // K_KSERVICES_KSERVICECOUNTER_IKCOUNTER_H
