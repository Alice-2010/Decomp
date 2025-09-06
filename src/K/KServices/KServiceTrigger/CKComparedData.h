#ifndef K_KSERVICES_KSERVICETRIGGER_CKCOMPAREDDATA_H
    #define K_KSERVICES_KSERVICETRIGGER_CKCOMPAREDDATA_H

    #include "K/KCore/Interfaces/IKSerializable.h"

    class CKComparedData : public IKSerializable
    {
        enum CLASS_INFO
        {
            CLASS_ID = 0x8D,
            CLASS_VERSION = 0x1,
            CLASS_TYPE = 0xC
        };

        public:
            CKComparedData();
    };

#endif // K_KSERVICES_KSERVICETRIGGER_CKCOMPAREDDATA_H
