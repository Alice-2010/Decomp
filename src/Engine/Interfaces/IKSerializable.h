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
            // reset() is inherited from IKBaseClass
            virtual void unk() { return; };
            // getClassGroup() is inherited from IKBaseClass
            // getClassID() is inherited from IKBaseClass
            // sendEvent() is inherited from IKBaseClass
            // unk2() is inherited from IKBaseClass
            virtual s32 unk3() { return 1; };
            virtual void unk4() { return; };
            virtual s32 serialize() { return 1; };
            virtual s32 deserialize() { return 1; };
            virtual s32 unk5() { return 1; };
            virtual s32 unk6() { return 1; };
            virtual void unk7() { return; };
            virtual s32 unk8() { return 1; };
            virtual s32 unk9() { return 1; };
            virtual s32 unk10() { return 0; };
            virtual void unk11() { return; };
            virtual void unk12() { return; };
    };

#endif
