#ifndef K_KCORE_MAIN_CKCLASSINFO_H
    #define K_KCORE_MAIN_CKCLASSINFO_H

    #include "K/KRegisterClass.h"

    class CKClassInfo
    {
        public:
            PFCT_K_CREATE_CLASS m_pfnCreateClass;
            PFCT_K_DELETE_CLASS m_pfnDeleteClass;
            PFCT_K_CREATE_ARRAY_CLASS m_pfnCreateArrayClass;
            PFCT_K_DELETE_ARRAY_CLASS m_pfnDeleteArrayClass;
            u16 m_i16ClassId;
            u16 m_eClassType;
    };

#endif // K_KCORE_MAIN_CKCLASSINFO_H
