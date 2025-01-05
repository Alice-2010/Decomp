#ifndef ALICE_INTERFACES_IKBASECLASS_H
    #define ALICE_INTERFACES_IKBASECLASS_H

    #include "global.h"
    struct IKBaseClass
    {
        IKBaseClass();
        virtual ~IKBaseClass();
        virtual inline BOOL isSubclass();
        virtual void reset();
        virtual inline void unk();
        virtual void getClassGroup(); // NULLPTR in this class
        virtual void getClassID(); // NULLPTR in this class
        virtual s32 sendEvent();
        virtual s32 unk2();
    };
#endif
