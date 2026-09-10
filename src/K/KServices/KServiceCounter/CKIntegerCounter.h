#ifndef CKINTEGERCOUNTER_H
    #define CKINTEGERCOUNTER_H

    #include "IKCounter.h"
    #include "K/KServices/KServiceTrigger/CTriggerStarter.h"
    #include "K/KCore/Interfaces/IKInfo.h"

    class CKIntegerCounter: public IKCounter
    {
        enum CLASS_INFO
        {
            CLASS_ID = 0x88,
            CLASS_VERSION = 0x1,
            CLASS_TYPE = 0xC,
        };

        protected:
            s32 m_i32CurrentValue;
            s32 m_i32MaxValue;
            s32 m_i32MinValue;
            s32 m_i32StartValue;
            CTriggerStarter m_tsMaxLoopReached;
            CTriggerStarter m_tsMaxValueReached;
            CTriggerStarter m_tsMinValueReached;
            u32 m_ui32CurrentLoop;
            u32 m_ui32MaxLoop;

        public:
            CKIntegerCounter();
            virtual ~CKIntegerCounter();
            virtual BOOL IsKindOfClass(KClassIdentifier);
            virtual void Destroy();
            virtual s32 GetClassType();
            virtual s32 GetClassID();
            virtual KMESSAGE_RETURN MessageProc(u16, void*);
            virtual s32 RecursiveRegistration(ESerializationType);
            virtual KError Save(IKFile*, ESerializationType);
            virtual KError Load(IKFile*, ESerializationType);
            virtual KError PostLoad(ESerializationType);
            virtual EInfoReturnType GetInfo(IKInfo*, EGetInfoRequestType);

            void IncrementCounter(s32);
            void DecrementCounter(s32);
            void ResetValue();
            void ResetValueToMax();
            void ResetValueToMin();
            void ResetLoop();
            void Init();
            s32 GetValueAccessor(u32);
            s32 GetLoopAccessor(u32);
            u32 GetValue();
            u32 GetLoop();
            BOOL IsMaxValueReachedAccessor(u32);
            BOOL IsMaxLoopReachedAccessor(u32);
            BOOL IsMinValueReachedAccessor(u32);
            BOOL IsStartValueReachedAccessor(u32);
            BOOL IsZeroLoopReachedAccessor(u32);
            BOOL IsMaxValueReached();
            BOOL IsMinValueReached();
            BOOL IsStartValueReached();
            BOOL IsMaxLoopReached();
            BOOL IsZeroLoopReached();
    };

#endif // CKINTEGERCOUNTER_H
