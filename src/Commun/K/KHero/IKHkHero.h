#ifndef ENGINE_INTERFACES_IKHKHERO_H
    #define ENGINE_INTERFACES_IKHKHERO_H

    #include "K/KCore/Interfaces/IKHook.h"

    class IKHkHero: public IKHook
    {
        public:
            IKHkHero(): IKHook::IKHook() {};
            virtual ~IKHkHero() {};
            virtual BOOL IsKindOfClass(u32 classID)
            {
                if (classID == 13890)
                    return TRUE;
                return IKHook::IsKindOfClass(classID);
            };
            // DestroyGame() func in this vtable is for IKBaseClass
            virtual void Destroy() { return; };
            virtual s32 GetClassType() { return 2; };
            virtual s32 GetClassID() { return 217; };
            virtual s32 MessageProc() { return 1; };
            // FindNonRecreableInstances() func in this vtable is for IKBaseClass
    };

#endif
