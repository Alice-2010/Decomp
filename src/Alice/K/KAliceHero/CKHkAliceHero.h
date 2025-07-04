#ifndef GAME_OBJECTS_HOOKS_CKHKALICEHERO_H
    #define GAME_OBJECTS_HOOKS_CKHKALICEHERO_H

    #include "Commun/K/KHero/IKHkHero.h"

    class CKHkAliceHero: public IKHkHero
    {
        public:
            CKHkAliceHero();
            virtual ~CKHkAliceHero();
            virtual BOOL IsKindOfClass(u32);
            // DestroyGame() func in this vtable is for IKBaseClass
            // Destroy() func in this vtable is for IKHkHero
            virtual s32 GetClassType();
            virtual s32 GetClassID();
            virtual s32 MessageProc();
            // FindNonRecreableInstances() func in this vtable is for IKBaseClass
    };

#endif
