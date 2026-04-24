#include "PowerPC_EABI_Support/MetroTRK/trk.h"

void* gTRKInputPendingPtr;
static TRKFramingState gTRKFramingState;

TRKBufferID TRKTestForPacket(void)
{
    int bytes;
    int batch;
    DSError err;
    TRKBuffer* b;
    int id;

    bytes = TRKPollUART();

    if (bytes > 0) {
        TRKGetFreeBuffer(&id, &b);
        if (bytes > 0x880) {
            for (; bytes > 0; bytes -= batch) {
                batch = bytes > 0x880 ? 0x880 : bytes;
                TRKReadUARTN(b->data, batch);
            }
            TRKStandardACK(b, DSMSG_ReplyNAK, 6);
        } else {
            err = TRKReadUARTN(b->data, bytes);
            if (err == DS_NoError) {
                b->length = bytes;
                return id;
            }
        }
    }

    if (id != -1) {
        TRKReleaseBuffer(id);
    }
    return -1;
}

void TRKGetInput(void)
{
    int bufID = TRKTestForPacket();
    if (bufID != -1) {
        TRKProcessInput(bufID);
    }
}

void TRKProcessInput(TRKBufferID bufID)
{
    TRKEvent event;

    TRKConstructEvent(&event, 2);
    event.msgBufID = bufID;
    TRKPostEvent(&event);
}

DSError TRKInitializeSerialHandler(void)
{
    return 0;
}

DSError TRKTerminateSerialHandler(void)
{
    return 0;
}
