#ifndef GAME_OBJECTS_GROUPS_CKGRPALICEHERO_H
    #define GAME_OBJECTS_GROUPS_CKGRPALICEHERO_H

    #include "Commun/K/KHero/IKGrpHero.h"

    class CKGrpAliceHero: public IKGrpHero
    {
        public:
            CKGrpAliceHero();
            virtual ~CKGrpAliceHero();
            virtual BOOL IsKindOfClass(u32);
            virtual s32 GetClassType();
            virtual s32 GetClassID();
    };

#endif
