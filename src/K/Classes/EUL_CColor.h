#ifndef K_CLASSES_EUL_CCOLOR_H
    #define K_CLASSES_EUL_CCOLOR_H

    #include "types.h"

    class CColor
    {
        public:
            union
            {
                u32 m_ui32Color;
                u8 m_ui8Component;
                struct
                {
                    u8 m_ui8Red;
                    u8 m_ui8Green;
                    u8 m_ui8Blue;
                    u8 m_ui8Alpha;
                };
            };

            CColor();
            ~CColor();
            CColor(const CColor&);
            CColor(u8*);
            CColor(u32);
            CColor(u8, u8, u8, u8);
            void SetRGBA(u8, u8, u8, u8);
            void SetRGBA(u32);
            void SetRGBA(const CColor&);
            void SubColors(const CColor&, const CColor&);
            void AddColors(const CColor&, const CColor&);
            void IncrementScaled(const CColor&, f32);
            void ScaleColor(const CColor&, f32);
            void Scale(f32);
            void MulColors(const CColor&, const CColor&);
            void BlendColors(const CColor&, const CColor&, f32, f32, f32, f32);
            void operator=(const CColor&);
            void operator+=(const CColor&);
            void operator-=(const CColor&);
            BOOL operator==(const CColor&);
            BOOL operator!=(const CColor&);
            u8 GetRed();
            u8 GetGreen();
            u8 GetBlue();
            u8 GetAlpha();
            void SetRed(u8);
            void SetGreen(u8);
            void SetBlue(u8);
            void SetAlpha(u8);
            u32 GetRGBA();
            u32 GetRGB();
            void GetHSLValues(f32&, f32&, f32&);
            void SetHSLValues(f32, f32, f32);
    };

#endif
