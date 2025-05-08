#ifndef ENGINE_INTERFACES_IKBASECLASS_H
    #define ENGINE_INTERFACES_IKBASECLASS_H

    #include "global.h"

    class IKBaseClass
    {
        public:
            IKBaseClass() {};
            virtual ~IKBaseClass() {};
            virtual BOOL isSubclass() { return FALSE; };
            virtual void reset() { return; };
            virtual void unk() { return; };
            virtual s32 getClassGroup() = 0;
            virtual s32 getClassID() = 0;
            virtual s32 sendEvent() { return 1; };
            virtual s32 unk2() { return 0; };
    };
#endif
