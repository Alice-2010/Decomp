#ifndef K_KCORE_MAIN_CKCOREFACTORY_H
    #define K_KCORE_MAIN_CKCOREFACTORY_H

    #include "K/Classes/EUL_TVector.h"
    #include "K/KCore/Interfaces/IKBaseClass.h"
    #include "K/KCore/Main/CKClassInfo.h"

    typedef TVector<CKClassInfo, 20, FALSE> ClassInfoVector;

    class CKCoreFactory
    {
        protected:
            ClassInfoVector m_classInfos[0xF];

        public:
            CKCoreFactory();
            virtual ~CKCoreFactory();
            virtual void AddPluginInfo(u16, u16, PFCT_K_CREATE_CLASS, PFCT_K_DELETE_CLASS, PFCT_K_CREATE_ARRAY_CLASS, PFCT_K_DELETE_ARRAY_CLASS);
            IKBaseClass* CreateClass(u32, u32);
            void DeleteClass(IKBaseClass*);
            IKBaseClass* CreateArrayClass(u32, u32, u32, u16*);
            void DeleteArrayClass(IKBaseClass*);
            char* KGetClassName(u32, u32) const;
            char* KGetClassName(const IKBaseClass*) const;
            u32 KGetMaxTypeID(u32);
            DONT_INLINE_CLASS CKClassInfo* FUN_801b56c8(u32);
            CKClassInfo* GetClassVector(u32, u32);
    };

#endif // K_KCORE_MAIN_CKCOREFACTORY_H
