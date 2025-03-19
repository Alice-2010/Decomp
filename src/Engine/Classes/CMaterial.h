#ifndef _ENGINE_CLASSES_CMATERIAL_H
    #define _ENGINE_CLASSES_CMATERIAL_H

    #include "Engine/Interfaces/IKSerializable.h"

    class CMaterial: IKSerializable
    {
        public:
            CMaterial(): IKSerializable::IKSerializable() {};
            virtual s32 serialize();
            virtual void deserialize(void*, uint);

        private:
            /**
             * 0x0
             * The class vtable
             */
            void* __vtable;
    };

#endif
