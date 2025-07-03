#ifndef GAME_OBJECTS_GROUPS_CKGRPALICEHERO_H
    #define GAME_OBJECTS_GROUPS_CKGRPALICEHERO_H

    #include "Commun/K/KHero/IKGrpHero.h"

    class CKGrpAliceHero: public IKGrpHero
    {
        public:
            CKGrpAliceHero();
            virtual ~CKGrpAliceHero();
            virtual BOOL isSubclass(u32);
            virtual s32 getClassGroup();
            virtual s32 getClassID();
    };

#endif
