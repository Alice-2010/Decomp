#ifndef ENGINE_INTERFACES_IKBASECLASS_H
    #define ENGINE_INTERFACES_IKBASECLASS_H

    #include "types.h"

    class IKBaseClass
    {
        public:
            inline IKBaseClass() {};
            virtual inline ~IKBaseClass() {};
            virtual inline BOOL IsKindOfClass() { return FALSE; };
            virtual inline void DestroyGame() { return; };
            virtual inline void Destroy() { return; };
            virtual inline s32 GetClassType() = 0;
            virtual inline s32 GetClassID() = 0;
            virtual inline s32 MessageProc() { return 1; };
            virtual inline s32 FindNonRecreableInstance() { return 0; };
    };
#endif
