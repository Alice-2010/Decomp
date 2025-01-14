#ifndef ALICE_INTERFACES_IKSERIALIZABLE_H
    #define ALICE_INTERFACES_IKSERIALIZABLE_H

    #include "Alice/Interfaces/IKBaseClass.h"
    struct IKSerializable: IKBaseClass
    {
        IKSerializable() {};
        virtual ~IKSerializable() {};
        virtual DONT_INLINE_CLASS BOOL isSubclass(u32 classID);
        // reset() func in this vtable is for IKBaseClass
        virtual void unk() { return; };
        // getClassGroup() func in this vtable is for IKBaseClass
        // getClassID() func in this vtable is for IKBaseClass
        // sendEvent() func in this vtable is for IKBaseClass
        // unk2() func in this vtable is for IKBaseClass
    };

#endif
