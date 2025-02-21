#ifndef ENGINE_INTERFACES_IKBASEGROUP_H
    #define ENGINE_INTERFACES_IKBASEGROUP_H

    #include "Engine/Interfaces/IKLife.h"

    class IKBaseGroup: public IKLife
    {
        public:
            IKBaseGroup(): IKLife::IKLife() {};
            virtual ~IKBaseGroup() {};
    };

#endif
