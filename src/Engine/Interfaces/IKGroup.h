#ifndef ENGINE_INTERFACES_IKGROUP_H
    #define ENGINE_INTERFACES_IKGROUP_H

    #include "Engine/Interfaces/IKBaseGroup.h"

    template <typename T> class IKGroup: public IKBaseGroup
    {
        public:
            IKGroup(): IKBaseGroup::IKBaseGroup() {};
            virtual ~IKGroup() {};
    };

#endif
