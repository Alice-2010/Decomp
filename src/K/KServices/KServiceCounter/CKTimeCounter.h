#ifndef K_KSERVICES_KSERVICECOUNTER_CKTIMECOUNTER_H
    #define K_KSERVICES_KSERVICECOUNTER_CKTIMECOUNTER_H

    #include "types.h"
    #include "K/KTypes.h"
    #include "K/KServices/KServiceCounter/IKCounter.h"
    #include "K/Classes/EUL_CBitArray.h"
    #include "K/KServices/KServiceTrigger/CTriggerStarter.h"
    #include "K/KCore/Interfaces/IKInfo.h"
    #include "K/KBasic/FileIO/IKFile.h"

    class CKTimeCounter : public IKCounter
    {
        enum CLASS_INFO
        {
            CLASS_ID = 0x87,
            CLASS_VERSION = 0x1,
            CLASS_TYPE = 0xC
        };

        protected:
            f32 m_fCurrentValue; // 0x8
            f32 m_fMaxValue; // 0xC
            u32 m_ui32CurrentLoop; // 0x10
            u32 m_ui32MaxLoop; // 0x14
            CBitArray m_baFlags; // 0x18
            void* unk_1C; // 0x1C
            CTriggerStarter m_tsMaxValueReached; // 0x20
            CTriggerStarter m_tsMaxLoopReached; // 0x28

        public:
            CKTimeCounter();
            virtual ~CKTimeCounter();
            virtual BOOL IsKindOfClass(KClassIdentifier);
            virtual void Destroy();
            virtual s32 GetClassType();
            virtual s32 GetClassID();
            virtual KMESSAGE_RETURN MessageProc(u16, void*);
            virtual s32 RecursiveRegistration(ESerializationType);
            virtual KError Save();
            virtual KError Load(IKFile*, ESerializationType);
            virtual KError PostLoad();
            virtual EInfoReturnType GetInfo(IKInfo*, EGetInfoRequestType);
            void Update();
            void StartTimer();
            void StopTimer();
            void ResetTimerValue();
            void ResetTimerToValue();
            void ResetTimerLoop();
            void IncrementTimerValue();
            void DecrementTimerValue();
            void Init();
            f32 GetValueAccessor();
            s32 GetLoopAccessor();
            BOOL IsMaxLoopReachedAccessor();
            BOOL IsZeroLoopReachedAccessor();
            BOOL IsNLoopReachedAccessor();
            BOOL IsRunningAccessor();
            f32 GetValue();
            f32 GetMaxValue();
            u32 GetLoop();
            u32 GetMaxLoop();
            BOOL IsMaxLoopReached();
            BOOL IsZeroLoopReached();
            BOOL GetIsRunning();
            void SetIsRunning();

        enum ECKTimeCounterFlagsOffset
        {
            CKTIMECOUNTER_FLAGS_ISRUNNING,
            CKTIMECOUNTER_FLAGS_NB
        };
    };

#endif // K_KSERVICES_KSERVICECOUNTER_CKTIMECOUNTER_H
