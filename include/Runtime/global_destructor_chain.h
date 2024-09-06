#ifndef GLOBAL_DESTRUCTOR_CHAIN_H
    #define GLOBAL_DESTRUCTOR_CHAIN_H

    typedef struct DestructorChain {
        struct DestructorChain* next;
        void* destructor;
        void* object;
    } DestructorChain;

    void __destroy_global_chain(void);

#endif
