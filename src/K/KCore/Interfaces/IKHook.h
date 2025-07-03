#ifndef ENGINE_INTERFACES_IKHOOK_H
    #define ENGINE_INTERFACES_IKHOOK_H

    #include "K/Classes/EUL_CSBaseNode.h"
    #include "K/KCore/Interfaces/IKLife.h"

    class IKHook: public IKLife, public CSBaseNode<IKHook*>
    {
        public:
            IKHook(): IKLife::IKLife() {};
            virtual ~IKHook() {};
            virtual BOOL isSubclass(u32 classID)
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
