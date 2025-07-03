#ifndef GAME_OBJECTS_HOOKS_CKHKALICEHERO_H
    #define GAME_OBJECTS_HOOKS_CKHKALICEHERO_H

    #include "Commun/K/KHero/IKHkHero.h"

    class CKHkAliceHero: public IKHkHero
    {
        public:
            CKHkAliceHero();
            virtual ~CKHkAliceHero();
            virtual BOOL isSubclass(u32);
            // reset() func in this vtable is for IKBaseClass
            // unk() func in this vtable is for IKHkHero
            virtual s32 getClassGroup();
            virtual s32 getClassID();
            virtual s32 sendEvent();
            // unk2() func in this vtable is for IKBaseClass
    };

#endif
