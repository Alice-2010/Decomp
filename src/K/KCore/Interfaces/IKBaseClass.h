#ifndef ENGINE_INTERFACES_IKBASECLASS_H
    #define ENGINE_INTERFACES_IKBASECLASS_H

    #include "types.h"
    #include "K/KTypes.h"

    class IKBaseClass
    {
        public:
            inline IKBaseClass() {};
            virtual ~IKBaseClass() {};
            virtual BOOL IsKindOfClass() { return FALSE; };
            virtual void DestroyGame() { return; };
            virtual void Destroy() { return; };
            virtual s32 GetClassType() = 0;
            virtual s32 GetClassID() = 0;
            virtual KMESSAGE_RETURN MessageProc() { return KMSG_RETURN_NOT_PROCESSED; };
            virtual s32 FindNonRecreableInstance() { return 0; };
    };

#endif
