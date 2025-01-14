#ifndef ALICE_INTERFACES_IKUPDATABLE_H
    #define ALICE_INTERFACES_IKUPDATABLE_H

    #include "Alice/Interfaces/IKSerializable.h"
    struct IKUpdatable: IKSerializable
    {
        IKUpdatable() {};
        virtual ~IKUpdatable() {};
        virtual DONT_INLINE_CLASS BOOL isSubclass(u32 classID)
        {
            if (classID == 1022)
                return TRUE;
            return IKSerializable::isSubclass(classID);
        };
        // reset() func in this vtable is for IKBaseClass
        // unk() func in this vtable is for IKSerializable
        // getClassGroup() func in this vtable is for IKBaseClass
        // getClassID() func in this vtable is for IKBaseClass
        // sendEvent() func in this vtable is for IKBaseClass
        // unk2() func in this vtable is for IKBaseClass
    };

#endif
