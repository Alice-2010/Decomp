#ifndef ENGINE_INTERFACES_IKHOOK_H
    #define ENGINE_INTERFACES_IKHOOK_H

    #include "K/Classes/EUL_CSBaseNode.h"
    #include "K/KCore/Interfaces/IKLife.h"

    class IKHook: public IKLife, public CSBaseNode<IKHook*>
    {
        public:
            IKHook(): IKLife::IKLife() {};
            virtual ~IKHook() {};
            virtual BOOL IsKindOfClass(u32 classID)
            {
                if (classID == 2)
                    return TRUE;
                return IKLife::IsKindOfClass(classID);
            };
    };

#endif
