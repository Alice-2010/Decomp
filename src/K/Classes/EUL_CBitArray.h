#ifndef K_CLASSES_EUL_CBITARRAY_H
    #define K_CLASSES_EUL_CBITARRAY_H

    #include "types.h"

    class CBitArray
    {
        protected:
            u32 m_ui32Bits; // 0x0

        public:
            CBitArray();
            CBitArray(u32);
            CBitArray(const CBitArray&);
            ~CBitArray();
            void ClearArray();
            u32* GetArray();
            u32 GetArray() const;
            void SetBit(u32, BOOL);
            void SetBitTrue(u32);
            void SetBitFalse(u32);
            void FlipBit(u32);
            void SetAllBits(BOOL);
            void SetValue(u32, u32, u32);
            u32 GetValue(u32, u32) const;
            void ShiftRight(u32, u32);
            void ShiftLeft(u32, u32);
            void FlipAllBits();
            BOOL IsBitTrue(u32) const;
            BOOL IsBitFalse(u32) const;
            BOOL IsBitArrayTrue() const;
            BOOL IsBitArrayFalse() const;
            CBitArray& operator =(const CBitArray&);
            CBitArray& operator &=(const CBitArray&);
            CBitArray& operator |=(const CBitArray&);
            CBitArray& operator ^=(const CBitArray&);
            BOOL operator [](u32) const;
            BOOL operator ==(const CBitArray&) const;
            BOOL operator !=(const CBitArray&) const;
    };

#endif // K_CLASSES_EUL_CBITARRAY_H
