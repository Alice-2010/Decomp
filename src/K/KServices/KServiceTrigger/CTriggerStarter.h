#ifndef K_KSERVICES_KSERVICETRIGGER_CTRIGGERSTARTER_H
    #define K_KSERVICES_KSERVICETRIGGER_CTRIGGERSTARTER_H

    #include "types.h"
    #include "K/KTypes.h"
    #include "K/KServices/KServiceTrigger/CKComparedData.h"
    #include "K/KBasic/FileIO/IKFile.h"

    class CTriggerStarter
    {
        protected:
            CKComparedData** m_apDatas; // 0x0
            u32 m_ui32NbDatas; // 0x8

        public:
            CTriggerStarter();
            ~CTriggerStarter();
            void Destroy();
            KError RecursiveRegistration();
            KError Save();
            KError Load(IKFile*, ESerializationType);
            KError PostLoad();
            u32 GetNbDatas();
            CKComparedData* GetData();
            void Activate();
            void Reset();
    };

#endif // K_KSERVICES_KSERVICETRIGGER_CTRIGGERSTARTER_H
