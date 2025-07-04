#ifndef RVL_SDK_GX_FIFO_H
    #define RVL_SDK_GX_FIFO_H
    #include "Revolution/GX/GXInternal.h"
    #include "types.h"
    #ifdef __cplusplus
        extern "C" {
    #endif

    GX_DECL_PUBLIC_STRUCT(GXFifoObj, 128);

    void GXGetGPStatus(u8 *, u8 *, u8 *, u8 *, u8 *);
    u32 GXGetOverflowCount();
    void GXResetOverflowCount();

    void GXSetCPUFifo(GXFifoObj *);
    BOOL GXGetCPUFifo(GXFifoObj *);

    u32 GXGetFifoCount(GXFifoObj *);
    u8 GXGetFifoWrap(GXFifoObj *);

    #ifdef __cplusplus
        }
    #endif
#endif
