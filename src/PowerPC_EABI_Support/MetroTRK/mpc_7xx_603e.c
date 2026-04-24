#include "PowerPC_EABI_Support/MetroTRK/trk.h" // IWYU pragma: keep

asm void TRKSaveExtended1Block()
{
#ifdef __MWERKS__ // clang-format off
    nofralloc
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    mfsr r16, 0
    mfsr r17, 1
    mfsr r18, 2
    mfsr r19, 3
    mfsr r20, 4
    mfsr r21, 5
    mfsr r22, 6
    mfsr r23, 7
    mfsr r24, 8
    mfsr r25, 9
    mfsr r26, 0xa
    mfsr r27, 0xb
    mfsr r28, 0xc
    mfsr r29, 0xd
    mfsr r30, 0xe
    mfsr r31, 0xf
    stmw r16, 0x1a8(r2)
    mftb r27, 0x10c
    mftbu r28
    mfspr r29, 0x3f0
    mfspr r30, 0x3f1
    mfspr r31, 0x1b
    stmw r27, 0x1e8(r2)
    mfpvr r15
    mfibatu r16, 0
    mfibatl r17, 0
    mfibatu r18, 1
    mfibatl r19, 1
    mfibatu r20, 2
    mfibatl r21, 2
    mfibatu r22, 3
    mfibatl r23, 3
    mfdbatu r24, 0
    mfdbatl r25, 0
    mfdbatu r26, 1
    mfdbatl r27, 1
    mfdbatu r28, 2
    mfdbatl r29, 2
    mfdbatu r30, 3
    mfdbatl r31, 3
    stmw r15, 0x1fc(r2)
    mfspr r24, 560
    mfspr r25, 561
    mfspr r26, 562
    mfspr r27, 563
    mfspr r28, 564
    mfspr r29, 565
    mfspr r30, 566
    mfspr r31, 567
    stmw r24, 0x240(r2)
    mfsdr1 r22
    mfdar r23
    mfdsisr r24
    mfsprg r25, 0
    mfsprg r26, 1
    mfsprg r27, 2
    mfsprg r28, 3
    mfdec r29
    mfspr r30, IABR
    mfear r31
    stmw r22, 0x25c(r2)
    mfspr r24, DABR
    mfspr r25, PMC1
    mfspr r26, PMC2
    mfspr r27, PMC3
    mfspr r28, PMC4
    mfspr r29, SIA
    mfspr r30, MMCR0
    mfspr r31, MMCR1
    stmw r24, 0x284(r2)
    mfspr r29, 567
    mfspr r30, 568
    mfspr r31, 569
    stmw r29, 0x2a4(r2)
    mfspr r30, ICTC
    mfspr r31, L2CR
    stmw r30, 0x2b0(r2)
    mfsrr0 r16
    stw r16, 0x2b8(r2)
    mfspr r17, 570
    stw r17, 0x2bc(r2)
    mfspr r25, UMMCR0
    mfspr r26, UPMC1
    mfspr r27, UPMC2
    mfspr r28, USIA
    mfspr r29, UMMCR1
    mfspr r30, UPMC3
    mfspr r31, UPMC4
    stmw r25, 0x2c0(r2)
    mfspr r25, 571
    mfspr r26, 572
    mfspr r27, 573
    mfspr r28, 574
    mfspr r29, 575
    mfspr r30, HID2
    mfspr r31, 1011
    stmw r25, 0x2dc(r2)
    mfspr r20, GQR0
    mfspr r21, GQR1
    mfspr r22, GQR2
    mfspr r23, GQR3
    mfspr r24, GQR4
    mfspr r25, GQR5
    mfspr r26, GQR6
    mfspr r27, GQR7
    mfspr r28, HID2
    mfspr r29, WPAR
    mfspr r30, DMA_U
    mfspr r31, DMA_L
    stmw r20, 0x2fc(r2)
    blr
#endif // clang-format on
}

asm void TRKRestoreExtended1Block()
{
#ifdef __MWERKS__ // clang-format off
    nofralloc
    lis r2, gTRKCPUState@h /* 0x8044F338@h */
    ori r2, r2, gTRKCPUState@l /* 0x8044F338@l */
    lis r5, gTRKRestoreFlags@h /* 0x803D3238@h */
    ori r5, r5, gTRKRestoreFlags@l /* 0x803D3238@l */
    lbz r3, 0(r5)
    lbz r6, 1(r5)
    li r0, 0
    stb r0, 0(r5)
    stb r0, 1(r5)
    cmpwi r3, 0
    beq L1
    lwz r24, 0x1e8(r2)
    lwz r25, 0x1ec(r2)
    mttbl r24
    mttbu r25
L1:
    lmw r20, 0x2fc(r2)
    mtspr 0x390, r20
    mtspr 0x391, r21
    mtspr 0x392, r22
    mtspr 0x393, r23
    mtspr 0x394, r24
    mtspr 0x395, r25
    mtspr 0x396, r26
    mtspr 0x397, r27
    mtspr 0x398, r28
    mtspr 0x39a, r30
    mtspr 0x39b, r31
    b L2
L2:
    lmw r19, 0x284(r2)
    mtspr 0x3f5, r19
    mtspr 0x3b9, r20
    mtspr 0x3ba, r21
    mtspr 0x3bd, r22
    mtspr 0x3be, r23
    mtspr 0x3bb, r24
    mtspr 0x3b8, r25
    mtspr 0x3bc, r26
    mtspr 0x3FB, r30
    mtspr 0x3f9, r31
    b L3
L3:
    lmw r16, 0x1a8(r2)
    mtsr 0, r16
    mtsr 1, r17
    mtsr 2, r18
    mtsr 3, r19
    mtsr 4, r20
    mtsr 5, r21
    mtsr 6, r22
    mtsr 7, r23
    mtsr 8, r24
    mtsr 9, r25
    mtsr 0xa, r26
    mtsr 0xb, r27
    mtsr 0xc, r28
    mtsr 0xd, r29
    mtsr 0xe, r30
    mtsr 0xf, r31
    lmw r12, 0x1f0(r2)
    mtspr 0x3f0, r12
    mtspr 0x3f1, r13
    mtspr 0x1b, r14
    mtspr 0x11f, r15
    mtibatu 0, r16
    mtibatl 0, r17
    mtibatu 1, r18
    mtibatl 1, r19
    mtibatu 2, r20
    mtibatl 2, r21
    mtibatu 3, r22
    mtibatl 3, r23
    mtdbatu 0, r24
    mtdbatl 0, r25
    mtdbatu 1, r26
    mtdbatl 1, r27
    mtdbatu 2, r28
    mtdbatl 2, r29
    mtdbatu 3, r30
    mtdbatl 3, r31
    lmw r22, 0x25c(r2)
    mtspr 0x19, r22
    mtdar r23
    mtdsisr r24
    mtspr 0x110, r25
    mtspr 0x111, r26
    mtspr 0x112, r27
    mtspr 0x113, r28
    mtspr 0x3f2, r30
    mtspr 0x11a, r31
    blr
#endif // clang-format on
}
