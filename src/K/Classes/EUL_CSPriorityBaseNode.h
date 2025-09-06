#ifndef ENGINE_CLASSES_CSPRORITYABASENODE_H
    #define ENGINE_CLASSES_CSPRORITYABASENODE_H

    #include "types.h"
    #include "K/KBasic/FileIO/IKFile.h"

    template <typename T> class CSPriorityBaseNodeClassNameNextUpdatableLife
    {
        protected:
            T* m_pNextUpdatableLife; // 0x0
            u32 m_ui32Priority; // 0x4

        public:
            CSPriorityBaseNodeClassNameNextUpdatableLife();
            ~CSPriorityBaseNodeClassNameNextUpdatableLife();
            u32& GetPriority() const;
            void SetPriority(u32);
            void SaveNext(IKFile*);
            void LoadNext(IKFile*);
            T* GetNextUpdatableLife() const;
            void SetNextUpdatableLife(T*);
    };

#endif
