#ifndef ENGINE_INTERFACES_IKUPDATABLE_H
    #define ENGINE_INTERFACES_IKUPDATABLE_H

    #include "Engine/Interfaces/IKSerializable.h"

    class IKUpdatable: public IKSerializable
    {
        public:
            IKUpdatable(): IKSerializable::IKSerializable() {};
            virtual ~IKUpdatable() {};
            virtual BOOL isSubclass(u32 classID)
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
