#ifndef _REVOSDK_TRK_H
    #define _REVOSDK_TRK_H

    #include "types.h" // IWYU pragma: keep

    #ifdef __cplusplus
        extern "C" {
    #endif

    unsigned int TRKTargetContinue(void);
    void TRKTargetSetStopped(unsigned int);
    void TRKSwapAndGo();

    void UnreserveEXI2Port();
    void ReserveEXI2Port();

    #ifdef __cplusplus
        }
    #endif

#endif
