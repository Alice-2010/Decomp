#ifndef ALICE_INTERFACES_IKHOOK_H
    #define ALICE_INTERFACES_IKHOOK_H

    #include "Alice/Interfaces/IKLife.h"
    struct IKHook: IKLife
    {
        IKHook() {};
        virtual ~IKHook() {};
        virtual DONT_INLINE_CLASS BOOL isSubclass(u32 classID)
        {
            if (classID == 2)
                return TRUE;
            return IKLife::isSubclass(classID);
        };
        // reset() func in this vtable is for IKBaseClass
        // unk() func in this vtable is for IKSerializable
        // getClassGroup() func in this vtable is for IKBaseClass
        // getClassID() func in this vtable is for IKBaseClass
        // sendEvent() func in this vtable is for IKBaseClass
        // unk2() func in this vtable is for IKBaseClass
    };

#endif
