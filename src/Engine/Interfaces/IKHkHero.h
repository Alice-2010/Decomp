#ifndef ENGINE_INTERFACES_IKHKHERO_H
    #define ENGINE_INTERFACES_IKHKHERO_H

    #include "Engine/Interfaces/IKHook.h"

    class IKHkHero: public IKHook
    {
        public:
            IKHkHero(): IKHook::IKHook() {};
            virtual ~IKHkHero() {};
            virtual BOOL isSubclass(u32 classID)
            {
                if (classID == 13890)
                    return TRUE;
                return IKHook::isSubclass(classID);
            };
            // reset() func in this vtable is for IKBaseClass
            virtual void unk() { return; };
            virtual s32 getClassGroup() { return 2; };
            virtual s32 getClassID() { return 217; };
            virtual s32 sendEvent() { return 1; };
            // unk2() func in this vtable is for IKBaseClass
    };

#endif
