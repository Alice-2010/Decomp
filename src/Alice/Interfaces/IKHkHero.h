#ifndef ALICE_INTERFACES_IKHKHERO_H
    #define ALICE_INTERFACES_IKHKHERO_H

    #include "Alice/Interfaces/IKHook.h"
    struct IKHkHero: IKHook
    {
        IKHkHero() {};
        virtual ~IKHkHero() {};
        virtual DONT_INLINE_CLASS BOOL isSubclass(u32 classID)
        {
            if (classID == 13890)
                return TRUE;
            return IKHkHero::isSubclass(classID);
        };
        // reset() func in this vtable is for IKBaseClass
        virtual void unk();
        virtual s32 getClassGroup();
        virtual s32 getClassID();
        virtual s32 sendEvent();
        // unk2() func in this vtable is for IKBaseClass
    };

#endif
