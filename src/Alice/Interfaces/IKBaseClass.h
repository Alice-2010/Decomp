#ifndef ALICE_INTERFACES_IKBASECLASS_H
    #define ALICE_INTERFACES_IKBASECLASS_H

    #include "global.h"
    struct IKBaseClass
    {
        IKBaseClass() {};
        virtual ~IKBaseClass() {};
        virtual BOOL isSubclass() { return FALSE; };
        virtual void reset() { return; };
        virtual void unk() { return; };
        virtual s32 getClassGroup(); // nullptr
        virtual s32 getClassID(); // nullptr
        virtual s32 sendEvent() { return 1; };
        virtual s32 unk2() { return 0; };
    };
#endif
