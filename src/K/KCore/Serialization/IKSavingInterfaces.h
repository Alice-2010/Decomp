#ifndef K_IKSAVINGINTERFACES_H
    #define K_IKSAVINGINTERFACES_H

    #include "K/KTypes.h"
    #include "K/KCore/Interfaces/IKSerializable.h"

    class IKSavingInterfaces: public IKBaseClass
    {
        public:
            IKSavingInterfaces(): IKBaseClass::IKBaseClass() {};
            virtual ~IKSavingInterfaces() {};
            virtual BOOL IsKindOfClass(KClassIdentifier a_iClassIdentifier)
            {
                if (a_iClassIdentifier == 0x97E)
                    return TRUE;
                return IKBaseClass::IsKindOfClass();
            };
            virtual void RegisterSerializableObject(IKSerializable*, IKSerializable*) {};
            virtual void SetCurrentlyRegisteringStream(s8) {};
            virtual s8 GetCurrentlyRegisteringStream() { return -1; };
            virtual BOOL KUIsClassRegistered(IKSerializable*) { return FALSE; };

    };

#endif // K_IKSAVINGINTERFACES_H
