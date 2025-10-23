#ifndef K_CSAVINGMANAGER_H
    #define K_CSAVINGMANAGER_H

    #include "K/KCore/Serialization/IKSavingInterfaces.h"

    class CKSavingManager: public IKSavingInterfaces
    {
        protected:
            s8 m_i8CurrentStream;
    };

#endif // KCSAVINGMANAGER_H
