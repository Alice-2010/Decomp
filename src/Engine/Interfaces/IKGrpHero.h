#ifndef ENGINE_INTERFACES_IKGRPHERO_H
    #define ENGINE_INTERFACES_IKGRPHERO_H

    #include "Engine/Interfaces/IKGroup.h"
    #include "Engine/Interfaces/IKHook.h"

    class IKGrpHero: public IKGroup<IKHook>
    {
        public:
            IKGrpHero(): IKGroup::IKGroup() {};
            virtual ~IKGrpHero() {};
    };

#endif
