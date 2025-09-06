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
    };

#endif
