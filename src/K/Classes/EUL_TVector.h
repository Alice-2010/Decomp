#ifndef K_CLASSES_EUL_TVECTOR_H
    #define K_CLASSES_EUL_TVECTOR_H

    #include "K/KCore/Main/CKClassInfo.h"

    template <typename T, u32 ui32Step = 0x14, BOOL bReduceSize = FALSE> class TVector
    {
        public:
            CKClassInfo* m_pBlock;
            u32 m_ui32NbElt;
            u32 m_ui32NbUsedElt;
    };

#endif // K_CLASSES_EUL_TVECTOR_H
