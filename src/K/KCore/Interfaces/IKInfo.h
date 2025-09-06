#ifndef K_KCORE_INTERFACES_IKINFO_H
    #define K_KCORE_INTERFACES_IKINFO_H

    #include "types.h"
    #include "K/KCore/Interfaces/IKBaseClass.h"

    class IKInfo : public IKBaseClass
    {
        public:
            IKInfo();
            virtual ~IKInfo() {};
            virtual BOOL IsKindOfClass(u32 classID);
            virtual void Destroy();
            virtual s32 GetClassType();
            virtual s32 GetClassID();
    };

#endif // K_KCORE_INTERFACES_IKINFO_H
