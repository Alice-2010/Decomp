#ifndef K_KCORE_MAIN_CKYELLOWPAGES_H
    #define K_KCORE_MAIN_CKYELLOWPAGES_H

    #include "K/Classes/EUL_CColor.h"

    class CKDisplayParams
    {
        public:
            void* m_pvDisplayID; // 0x00
            s32 m_i32Width; // 0x04
            s32 m_i32Height; // 0x08
            s32 m_i32Depth; // 0x0C
            CColor m_backColor; // 0x10
            BOOL m_bFullScreen; // 0x14
            BOOL m_bVideoModePAL; // 0x18

            CKDisplayParams();
    };

    class CKApplication
    {
        public:
            void* m_pvApplicationID; // 0x00
            void* m_pvCursorID; // 0x04
            char m_szAppName[0x28]; // 0x08
            char m_szAbrvAppName[0x14]; // 0x30
            char m_szAppCode[0x14]; // 0x44
            s32 m_i32StartGameState; // 0x58
            BOOL m_bPerformanceAnalysis; // 0x5C
    };

    // class CKANSIFunctions
    // {

    // };

    class CKParams
    {
        public:
            CKDisplayParams* m_displayParams; // 0x00
            CKApplication* m_appParams; // 0x04
            // CKANSIFunctions* m_ANSIFunctions; // 0x08
    };

#endif
