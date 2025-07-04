#ifndef ENGINE_INTERFACES_IKUPDATABLE_H
    #define ENGINE_INTERFACES_IKUPDATABLE_H

    #include "K/KCore/Interfaces/IKSerializable.h"

    class IKUpdatable: public IKSerializable
    {
        public:
            IKUpdatable(): IKSerializable::IKSerializable() {};
            virtual ~IKUpdatable() {};
            virtual BOOL IsKindOfClass(u32 classID)
            {
                if (classID == 1022)
                    return TRUE;
                return IKSerializable::IsKindOfClass(classID);
            };
            // DestroyGame() is inherited from IKBaseClass
            // Destroy() is inherited from IKSerializable
            // GetClassType() is inherited from IKBaseClass
            // GetClassID() is inherited from IKBaseClass
            // MessageProc() is inherited from IKBaseClass
            // FindNonRecreableInstances() is inherited from IKBaseClass
            // unk3() is inherited from IKSerializable
            // unk4() is inherited from IKSerializable
            // Save() is inherited from IKSerializable
            // Load() is inherited from IKSerializable
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
