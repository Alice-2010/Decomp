#ifndef ENGINE_INTERFACES_IKUPDATABLE_H
    #define ENGINE_INTERFACES_IKUPDATABLE_H

    #include "K/KCore/Interfaces/IKSerializable.h"

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
            // reset() is inherited from IKBaseClass
            // unk() is inherited from IKSerializable
            // getClassGroup() is inherited from IKBaseClass
            // getClassID() is inherited from IKBaseClass
            // sendEvent() is inherited from IKBaseClass
            // unk2() is inherited from IKBaseClass
            // unk3() is inherited from IKSerializable
            // unk4() is inherited from IKSerializable
            // serialize() is inherited from IKSerializable
            // deserialize() is inherited from IKSerializable
            // unk5() is inherited from IKSerializable
            // unk6() is inherited from IKSerializable
            // unk7() is inherited from IKSerializable
            // unk8() is inherited from IKSerializable
            // unk9() is inherited from IKSerializable
            // unk10() is inherited from IKSerializable
            // unk11() is inherited from IKSerializable
            // unk12() is inherited from IKSerializable
            virtual void unk13() = 0;
            virtual void unk14() { return; };
            virtual s32 unk15() { return 1; };
            virtual void unk16() { return; };
            virtual void unk17() { return; };
            virtual void unk18() { return; };
            virtual void unk19() = 0;
            virtual s32 unk20() { return 1; };
            virtual void unk21() = 0;
            virtual s32 unk22() { return 1; };
            virtual void unk23() = 0;
            virtual void unk24() = 0;
            virtual void unk25() { return; };
            virtual void unk26() { return; };
            virtual void unk27() { return; };
            virtual void unk28() { return; };
            virtual void unk29() { return; };
            virtual void unk30() { return; };
    };

#endif
