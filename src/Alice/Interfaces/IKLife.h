#ifndef ALICE_INTERFACES_IKLIFE_H
    #define ALICE_INTERFACES_IKLIFE_H

    #include "Alice/Interfaces/IKUpdatable.h"
    struct IKLife: IKUpdatable
    {
        IKLife() {};
        virtual ~IKLife() {};
        virtual DONT_INLINE_CLASS BOOL isSubclass(u32 classID)
        {
            if (classID == 766)
                return TRUE;
            return IKUpdatable::isSubclass(classID);
        };
        // reset() func in this vtable is for IKBaseClass
        // unk() func in this vtable is for IKSerializable
        // getClassGroup() func in this vtable is for IKBaseClass
        // getClassID() func in this vtable is for IKBaseClass
        // sendEvent() func in this vtable is for IKBaseClass
        // unk2() func in this vtable is for IKBaseClass
    };

#endif
