#ifndef ENGINE_INTERFACES_IKSERIALIZABLE_H
    #define ENGINE_INTERFACES_IKSERIALIZABLE_H

    #include "K/KTypes.h"
    #include "K/KCore/Interfaces/IKBaseClass.h"

    class IKSerializable: public IKBaseClass
    {
        public:
            void* m_pDbgObjectInfos; // 0x4

            IKSerializable(): IKBaseClass::IKBaseClass() {};
            virtual ~IKSerializable() {};
            virtual BOOL IsKindOfClass(KClassIdentifier);
            virtual void Destroy() { return; };
            virtual KError RecursiveRegistration(ESerializationType) { return 1; };
            virtual void unk4() { return; }; // NOTE: This function doesn't seem to be called in game
            virtual KError Save() { return 1; };
            virtual KError Load() { return 1; };
            virtual KError PostLoad() { return 1; };
            BOOL IsRecreable();
            BOOL IsMergable();
            virtual u8 GetSerializationFlags() const { return 1; };
            virtual void SetDefaultState() { return; };
            virtual KError SetGameState() { return 1; };
            virtual EInfoReturnType GetInfo() { return KINFO_RETURN_NOT_PROCESSED; };
            virtual s32 unk10() { return 0; };
            virtual void unk11() { return; };
            virtual void unk12() { return; };
    };

#endif
