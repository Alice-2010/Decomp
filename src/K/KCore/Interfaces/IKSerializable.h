#ifndef ENGINE_INTERFACES_IKSERIALIZABLE_H
    #define ENGINE_INTERFACES_IKSERIALIZABLE_H

    #include "K/KCore/Interfaces/IKBaseClass.h"

    class IKSerializable: public IKBaseClass
    {
        public:
            IKSerializable(): IKBaseClass::IKBaseClass() {};
            virtual ~IKSerializable() {};
            virtual BOOL IsKindOfClass(u32 classID)
            {
                if (classID == 12)
                    return TRUE;
                return IKBaseClass::IsKindOfClass();
            };
            // DestroyGame() is inherited from IKBaseClass
            virtual void Destroy() { return; };
            // GetClassType() is inherited from IKBaseClass
            // GetClassID() is inherited from IKBaseClass
            // MessageProc() is inherited from IKBaseClass
            // FindNonRecreableInstances() is inherited from IKBaseClass
            virtual s32 unk3() { return 1; };
            virtual void unk4() { return; };
            virtual s32 Save() { return 1; };
            virtual s32 Load() { return 1; };
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
