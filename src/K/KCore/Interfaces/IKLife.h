#ifndef ENGINE_INTERFACES_IKLIFE_H
    #define ENGINE_INTERFACES_IKLIFE_H

    #include "K/Classes/EUL_CSPriorityBaseNode.h"
    #include "K/KCore/Interfaces/IKUpdatable.h"

    extern void fn_8000E7F4(s32, s32);
    extern void fn_8000F4AC(s32, s32);

    class IKLife: public IKUpdatable, public CSPriorityBaseNodeClassNameNextUpdatableLife<IKLife*>
    {
        public:
            IKLife(): IKUpdatable::IKUpdatable() {};
            virtual ~IKLife()
            {
                fn_8000E7F4((s32)this + 0xC, -1);
                fn_8000F4AC((s32)this + 0x4, 0);
            };
            virtual BOOL IsKindOfClass(u32 classID)
            {
                if (classID == 766)
                    return TRUE;
                return IKUpdatable::IsKindOfClass(classID);
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
            // unk13()
            // unk14()
            // unk15()
            // unk16()
            // unk17()
            // unk18()
            // unk19()
            // unk20()
            // unk21()
            // unk22()
            // unk23()
            // unk24()
            // unk25()
            // unk26()
            // unk27()
            // unk28()
            // unk29()
            // unk30()
    };

#endif
