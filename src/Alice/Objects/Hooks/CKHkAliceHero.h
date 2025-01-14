#ifndef ALICE_OBJECTS_HOOKS_CKHKALICEHERO_H
    #define ALICE_OBJECTS_HOOKS_CKHKALICEHERO_H

    #include "Alice/Interfaces/IKHkHero.h"
    struct CKHkAliceHero: IKHkHero
    {
        CKHkAliceHero();
        virtual ~CKHkAliceHero();
        virtual DONT_INLINE_CLASS BOOL isSubclass(u32 classID)
        {
            if (classID == 9666)
                return TRUE;
            return IKHkHero::isSubclass(classID);
        };
        // reset() func in this vtable is for IKBaseClass
        // unk() func in this vtable is for IKHkHero
        virtual s32 getClassGroup();
        virtual s32 getClassID();
        virtual s32 sendEvent();
        // unk2() func in this vtable is for IKBaseClass
    };

#endif
