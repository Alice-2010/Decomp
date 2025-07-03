#ifndef ENGINE_INTERFACES_IKGRPHERO_H
    #define ENGINE_INTERFACES_IKGRPHERO_H

    #include "K/KCore/Interfaces/IKGroup.h"
    #include "K/KCore/Interfaces/IKHook.h"

    class IKGrpHero: public IKGroup<IKHook>
    {
        public:
            IKGrpHero(): IKGroup::IKGroup() {};
            virtual ~IKGrpHero() {};
    };

#endif
