#ifndef ENGINE_INTERFACES_IKLIFE_H
    #define ENGINE_INTERFACES_IKLIFE_H

    #include "Engine/Interfaces/IKUpdatable.h"

    extern void fn_8000E7F4(s32, s32);
    extern void fn_8000F4AC(s32, s32);

    class IKLife: public IKUpdatable
    {
        public:
            IKLife(): IKUpdatable::IKUpdatable() {};
            virtual ~IKLife()
            {
                fn_8000E7F4((s32)this + 0xC, -1);
                fn_8000F4AC((s32)this + 0x4, 0);
            };
            virtual BOOL isSubclass(u32 classID)
            {
                if (classID == 766)
                    return TRUE;
                return IKUpdatable::isSubclass(classID);
            };
            // reset() func in this vtable is for IKBaseClass
            // unk() func in this vtable is for IKSerializable
            // getClassGroup() func in this vtable is for IKBaseClass
            // getClassID() func in this vtable is for IKBaseClass
            // sendEvent() func in this vtable is for IKBaseClass
            // unk2() func in this vtable is for IKBaseClass
    };

#endif
