#ifndef RVL_SDK_DVD_H
    #define RVL_SDK_DVD_H
    #include "types.h"
    #include "Revolution/OS.h"
    #include "Revolution/ESP.h"
    #include "Revolution/DVD/dvdidutils.h"
    #ifdef __cplusplus
        extern "C" {
    #endif

    #define DVD_STATE_FATAL_ERROR -1
    #define DVD_STATE_END 0
    #define DVD_STATE_BUSY 1
    #define DVD_STATE_WAITING 2
    #define DVD_STATE_COVER_CLOSED 3 //deprecated for wii
    #define DVD_STATE_NO_DISK 4
    #define DVD_STATE_COVER_OPEN 5 //deprecated for wii
    #define DVD_STATE_WRONG_DISK 6
    #define DVD_STATE_MOTOR_STOPPED 7
    #define DVD_STATE_PAUSING 8
    #define DVD_STATE_IGNORED 9
    #define DVD_STATE_CANCELED 10
    #define DVD_STATE_RETRY 11
    #define DVD_STATE_12 12

    #define DVD_RESULT_GOOD 0
    #define DVD_RESULT_FATAL_ERROR -1
    #define DVD_RESULT_IGNORED -2
    #define DVD_RESULT_CANCELED -3

    #define DVD_DEVICE_CODE_READ 0x8000

    // Forward declarations
    typedef struct DVDCommandBlock DVDCommandBlock;
    typedef struct DVDFileInfo DVDFileInfo;

    typedef struct DVDDriveInfo {
        u16 revision;    // at 0x0
        u16 deviceCode;  // at 0x2
        u32 releaseDate; // at 0x4
        char padding[32 - 0x8];
    } DVDDriveInfo;


    typedef void (*DVDCBCallback)(s32 result, struct DVDCommandBlock* block);

    struct DVDCommandBlock {
        struct DVDCommandBlock* next; // 0x0
        struct DVDCommandBlock* prev; // 0x4
        u32 command; // 0x8
        s32 state; // 0xC
        u32 offset; // 0x10
        u32 length; // 0x14
        void* addr; // 0x18
        u32 currTransferSize; // 0x1C
        u32 transferredSize; // 0x20
        struct DVDDiskID* id; // 0x24
        DVDCBCallback callback; // 0x28
        void* userData; // 0x2C
    };

    typedef void (*DVDOptionalCommandChecker)(DVDCommandBlock* block, void (*cb)(u32));

    typedef struct DVDBB2 {
        u32 bootFilePosition;
        u32 FSTPosition;
        u32 FSTLength;
        u32 FSTMaxLength;
        void* FSTAddress;
        u32 userPosition;
        u32 userLength;
        u32 padding0;
    } DVDBB2;

    typedef struct DVDGamePartition {
        ESTicket ticket;
        u32 tmdSize;
        ESTitleMeta* tmd;
        u32 certBlobSize;
        void* certBlob;
        u8* h3Hashes;
        u8* encryptedArea;
    } DVDGamePartition;

    typedef struct DVDPartitionInfo {
        DVDGamePartition* gamePartition;
        u32 type;
    } DVDPartitionInfo;

    typedef struct DVDGameTOC {
        u32 numGamePartitions;
        DVDPartitionInfo* partitionInfos;
    } DVDGameTOC;

    typedef struct DVDPartitionParams {
        ESTicket ticket;
        u8 padding0[OSRoundUp32B(sizeof(ESTicket)) - sizeof(ESTicket)];
        ESTicketView ticketView;
        u8 padding1[OSRoundUp32B(sizeof(ESTicketView)) - sizeof(ESTicketView)];
        u32 numTmdBytes;
        u8 padding2[28];
        ESTitleMeta tmd;
        u8 padding3[OSRoundUp32B(sizeof(ESTitleMeta)) - sizeof(ESTitleMeta)];
        u32 numCertBytes;
        u8 padding4[28];
        u8 certificates[4096];
        u32 dataWordOffset;
        u8 padding5[28];
        u8 h3Hash[98304];
    } DVDPartitionParams;

    void DVDInit(void);
    BOOL DVDOpen(char* fileName, DVDFileInfo* fileInfo);
    BOOL DVDClose(DVDFileInfo* f);
    BOOL DVDInquiryAsync(DVDCommandBlock*, DVDDriveInfo*, DVDCBCallback);
    u32 __DVDGetCoverStatus(void);
    void __DVDPrepareReset(void);
    BOOL __DVDTestAlarm(const OSAlarm*);

    #ifdef __cplusplus
        }
    #endif
#endif
