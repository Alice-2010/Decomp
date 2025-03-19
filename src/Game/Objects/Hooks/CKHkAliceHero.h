#ifndef GAME_OBJECTS_HOOKS_CKHKALICEHERO_H
    #define GAME_OBJECTS_HOOKS_CKHKALICEHERO_H

    #include "Engine/Interfaces/IKHkHero.h"

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

            u32 GetNextCharacterID() { return m_nextCharacterID; }
            void SwitchCharacter(u32 newCharacterID) { m_nextCharacterID = newCharacterID; };

        private:
            /**
             * 0x0
             * The class vtable pointer
             */
            void* __vtable;
            /**
             * 0x9CC
             * The next characterID
             */
            u32 m_nextCharacterID;
            /**
             * 0x9D0
             * The current character ID
             */
            u32 m_characterID;
    };

#endif
