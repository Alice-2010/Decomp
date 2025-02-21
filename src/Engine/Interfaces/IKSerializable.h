#ifndef ENGINE_INTERFACES_IKSERIALIZABLE_H
    #define ENGINE_INTERFACES_IKSERIALIZABLE_H

    #include "Engine/Interfaces/IKBaseClass.h"

    class IKSerializable: public IKBaseClass
    {
        public:
            IKSerializable(): IKBaseClass::IKBaseClass() {};
            virtual ~IKSerializable() {};
            virtual BOOL isSubclass(u32 classID)
            {
                if (classID == 12)
                    return TRUE;
                return IKBaseClass::isSubclass();
            };
            // reset() func in this vtable is for IKBaseClass
            virtual void unk() { return; };
            // getClassGroup() func in this vtable is for IKBaseClass
            // getClassID() func in this vtable is for IKBaseClass
            // sendEvent() func in this vtable is for IKBaseClass
            // unk2() func in this vtable is for IKBaseClass
    };

#endif
