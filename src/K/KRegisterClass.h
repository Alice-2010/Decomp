#ifndef K_KREGISTERCLASS_H
    #define K_KREGISTERCLASS_H

    #include "K/KCore/Interfaces/IKBaseClass.h"

    typedef IKBaseClass* (*PFCT_K_CREATE_CLASS)();
    typedef void (*PFCT_K_DELETE_CLASS)(IKBaseClass*);
    typedef IKBaseClass* (*PFCT_K_CREATE_ARRAY_CLASS)(u32, u16*);
    typedef void (*PFCT_K_DELETE_ARRAY_CLASS)(IKBaseClass*);

#endif // K_KREGISTERCLASS_H
