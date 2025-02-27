.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel breaking_junk_appendGfx
/* 40389C E011849C 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 4038A0 E01184A0 AFB700BC */  sw        $s7, 0xbc($sp)
/* 4038A4 E01184A4 0080B82D */  daddu     $s7, $a0, $zero
/* 4038A8 E01184A8 3C05DB06 */  lui       $a1, 0xdb06
/* 4038AC E01184AC 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 4038B0 E01184B0 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 4038B4 E01184B4 34A50024 */  ori       $a1, $a1, 0x24
/* 4038B8 E01184B8 3C02E700 */  lui       $v0, 0xe700
/* 4038BC E01184BC AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 4038C0 E01184C0 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 4038C4 E01184C4 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 4038C8 E01184C8 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 4038CC E01184CC AFB400B0 */  sw        $s4, 0xb0($sp)
/* 4038D0 E01184D0 AFB300AC */  sw        $s3, 0xac($sp)
/* 4038D4 E01184D4 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 4038D8 E01184D8 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 4038DC E01184DC AFB000A0 */  sw        $s0, 0xa0($sp)
/* 4038E0 E01184E0 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 4038E4 E01184E4 8CC40000 */  lw        $a0, ($a2)
/* 4038E8 E01184E8 8EE7000C */  lw        $a3, 0xc($s7)
/* 4038EC E01184EC 0080182D */  daddu     $v1, $a0, $zero
/* 4038F0 E01184F0 84FE0032 */  lh        $fp, 0x32($a3)
/* 4038F4 E01184F4 24840008 */  addiu     $a0, $a0, 8
/* 4038F8 E01184F8 AC620000 */  sw        $v0, ($v1)
/* 4038FC E01184FC AC600004 */  sw        $zero, 4($v1)
/* 403900 E0118500 AC850000 */  sw        $a1, ($a0)
/* 403904 E0118504 8EE20010 */  lw        $v0, 0x10($s7)
/* 403908 E0118508 0000882D */  daddu     $s1, $zero, $zero
/* 40390C E011850C ACC40000 */  sw        $a0, ($a2)
/* 403910 E0118510 8C43001C */  lw        $v1, 0x1c($v0)
/* 403914 E0118514 3C02DE00 */  lui       $v0, 0xde00
/* 403918 E0118518 AC820008 */  sw        $v0, 8($a0)
/* 40391C E011851C 3C028000 */  lui       $v0, 0x8000
/* 403920 E0118520 00621821 */  addu      $v1, $v1, $v0
/* 403924 E0118524 AC830004 */  sw        $v1, 4($a0)
/* 403928 E0118528 3C03E012 */  lui       $v1, %hi(D_E01187C0)
/* 40392C E011852C 8C6387C0 */  lw        $v1, %lo(D_E01187C0)($v1)
/* 403930 E0118530 24820008 */  addiu     $v0, $a0, 8
/* 403934 E0118534 ACC20000 */  sw        $v0, ($a2)
/* 403938 E0118538 AC83000C */  sw        $v1, 0xc($a0)
/* 40393C E011853C 8EE20008 */  lw        $v0, 8($s7)
/* 403940 E0118540 24840010 */  addiu     $a0, $a0, 0x10
/* 403944 E0118544 18400084 */  blez      $v0, .LE0118758
/* 403948 E0118548 ACC40000 */   sw       $a0, ($a2)
/* 40394C E011854C 4480A000 */  mtc1      $zero, $f20
/* 403950 E0118550 27B40060 */  addiu     $s4, $sp, 0x60
/* 403954 E0118554 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 403958 E0118558 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 40395C E011855C 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 403960 E0118560 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 403964 E0118564 3C130001 */  lui       $s3, 1
/* 403968 E0118568 36731630 */  ori       $s3, $s3, 0x1630
/* 40396C E011856C 00C0902D */  daddu     $s2, $a2, $zero
/* 403970 E0118570 24F0003A */  addiu     $s0, $a3, 0x3a
.LE0118574:
/* 403974 E0118574 3C0A800B */  lui       $t2, %hi(gCameras)
/* 403978 E0118578 254A1D80 */  addiu     $t2, $t2, %lo(gCameras)
/* 40397C E011857C 4405A000 */  mfc1      $a1, $f20
/* 403980 E0118580 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 403984 E0118584 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 403988 E0118588 C600FFEA */  lwc1      $f0, -0x16($s0)
/* 40398C E011858C 3C013FE0 */  lui       $at, 0x3fe0
/* 403990 E0118590 44811800 */  mtc1      $at, $f3
/* 403994 E0118594 44801000 */  mtc1      $zero, $f2
/* 403998 E0118598 00031080 */  sll       $v0, $v1, 2
/* 40399C E011859C 00431021 */  addu      $v0, $v0, $v1
/* 4039A0 E01185A0 46000021 */  cvt.d.s   $f0, $f0
/* 4039A4 E01185A4 00021080 */  sll       $v0, $v0, 2
/* 4039A8 E01185A8 46220002 */  mul.d     $f0, $f0, $f2
/* 4039AC E01185AC 00000000 */  nop
/* 4039B0 E01185B0 00431023 */  subu      $v0, $v0, $v1
/* 4039B4 E01185B4 000218C0 */  sll       $v1, $v0, 3
/* 4039B8 E01185B8 00431021 */  addu      $v0, $v0, $v1
/* 4039BC E01185BC 000210C0 */  sll       $v0, $v0, 3
/* 4039C0 E01185C0 004A1021 */  addu      $v0, $v0, $t2
/* 4039C4 E01185C4 C442006C */  lwc1      $f2, 0x6c($v0)
/* 4039C8 E01185C8 4407A000 */  mfc1      $a3, $f20
/* 4039CC E01185CC 46001087 */  neg.s     $f2, $f2
/* 4039D0 E01185D0 44061000 */  mfc1      $a2, $f2
/* 4039D4 E01185D4 46200020 */  cvt.s.d   $f0, $f0
/* 4039D8 E01185D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 4039DC E01185DC C600FFCA */  lwc1      $f0, -0x36($s0)
/* 4039E0 E01185E0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 4039E4 E01185E4 C600FFCE */  lwc1      $f0, -0x32($s0)
/* 4039E8 E01185E8 E7A00018 */  swc1      $f0, 0x18($sp)
/* 4039EC E01185EC C600FFD2 */  lwc1      $f0, -0x2e($s0)
/* 4039F0 E01185F0 27A40020 */  addiu     $a0, $sp, 0x20
/* 4039F4 E01185F4 0C080180 */  jal       shim_guPositionF
/* 4039F8 E01185F8 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 4039FC E01185FC 3C013F80 */  lui       $at, 0x3f80
/* 403A00 E0118600 44810000 */  mtc1      $at, $f0
/* 403A04 E0118604 4406A000 */  mfc1      $a2, $f20
/* 403A08 E0118608 4407A000 */  mfc1      $a3, $f20
/* 403A0C E011860C E7A00010 */  swc1      $f0, 0x10($sp)
/* 403A10 E0118610 8E05FFEE */  lw        $a1, -0x12($s0)
/* 403A14 E0118614 0C080104 */  jal       shim_guRotateF
/* 403A18 E0118618 0280202D */   daddu    $a0, $s4, $zero
/* 403A1C E011861C 0280202D */  daddu     $a0, $s4, $zero
/* 403A20 E0118620 27A50020 */  addiu     $a1, $sp, 0x20
/* 403A24 E0118624 0C080114 */  jal       shim_guMtxCatF
/* 403A28 E0118628 00A0302D */   daddu    $a2, $a1, $zero
/* 403A2C E011862C 27A40020 */  addiu     $a0, $sp, 0x20
/* 403A30 E0118630 96A50000 */  lhu       $a1, ($s5)
/* 403A34 E0118634 8EC20000 */  lw        $v0, ($s6)
/* 403A38 E0118638 00052980 */  sll       $a1, $a1, 6
/* 403A3C E011863C 00B32821 */  addu      $a1, $a1, $s3
/* 403A40 E0118640 0C080118 */  jal       shim_guMtxF2L
/* 403A44 E0118644 00452821 */   addu     $a1, $v0, $a1
/* 403A48 E0118648 3C02DA38 */  lui       $v0, 0xda38
/* 403A4C E011864C 34420002 */  ori       $v0, $v0, 2
/* 403A50 E0118650 3C09D838 */  lui       $t1, 0xd838
/* 403A54 E0118654 35290002 */  ori       $t1, $t1, 2
/* 403A58 E0118658 32280003 */  andi      $t0, $s1, 3
/* 403A5C E011865C 26310001 */  addiu     $s1, $s1, 1
/* 403A60 E0118660 00084080 */  sll       $t0, $t0, 2
/* 403A64 E0118664 8E440000 */  lw        $a0, ($s2)
/* 403A68 E0118668 96A30000 */  lhu       $v1, ($s5)
/* 403A6C E011866C 0080282D */  daddu     $a1, $a0, $zero
/* 403A70 E0118670 24840008 */  addiu     $a0, $a0, 8
/* 403A74 E0118674 AE440000 */  sw        $a0, ($s2)
/* 403A78 E0118678 ACA20000 */  sw        $v0, ($a1)
/* 403A7C E011867C 24620001 */  addiu     $v0, $v1, 1
/* 403A80 E0118680 3063FFFF */  andi      $v1, $v1, 0xffff
/* 403A84 E0118684 00031980 */  sll       $v1, $v1, 6
/* 403A88 E0118688 A6A20000 */  sh        $v0, ($s5)
/* 403A8C E011868C 8EC20000 */  lw        $v0, ($s6)
/* 403A90 E0118690 00731821 */  addu      $v1, $v1, $s3
/* 403A94 E0118694 00431021 */  addu      $v0, $v0, $v1
/* 403A98 E0118698 ACA20004 */  sw        $v0, 4($a1)
/* 403A9C E011869C 24820008 */  addiu     $v0, $a0, 8
/* 403AA0 E01186A0 AE420000 */  sw        $v0, ($s2)
/* 403AA4 E01186A4 3C02FA00 */  lui       $v0, 0xfa00
/* 403AA8 E01186A8 AC820000 */  sw        $v0, ($a0)
/* 403AAC E01186AC 9203FFF3 */  lbu       $v1, -0xd($s0)
/* 403AB0 E01186B0 9205FFF5 */  lbu       $a1, -0xb($s0)
/* 403AB4 E01186B4 9206FFF7 */  lbu       $a2, -9($s0)
/* 403AB8 E01186B8 24820010 */  addiu     $v0, $a0, 0x10
/* 403ABC E01186BC AE420000 */  sw        $v0, ($s2)
/* 403AC0 E01186C0 3C02FB00 */  lui       $v0, 0xfb00
/* 403AC4 E01186C4 AC820008 */  sw        $v0, 8($a0)
/* 403AC8 E01186C8 33C200FF */  andi      $v0, $fp, 0xff
/* 403ACC E01186CC 00031E00 */  sll       $v1, $v1, 0x18
/* 403AD0 E01186D0 00052C00 */  sll       $a1, $a1, 0x10
/* 403AD4 E01186D4 00651825 */  or        $v1, $v1, $a1
/* 403AD8 E01186D8 00063200 */  sll       $a2, $a2, 8
/* 403ADC E01186DC 00661825 */  or        $v1, $v1, $a2
/* 403AE0 E01186E0 00621825 */  or        $v1, $v1, $v0
/* 403AE4 E01186E4 AC830004 */  sw        $v1, 4($a0)
/* 403AE8 E01186E8 9203FFFB */  lbu       $v1, -5($s0)
/* 403AEC E01186EC 9205FFFD */  lbu       $a1, -3($s0)
/* 403AF0 E01186F0 9206FFFF */  lbu       $a2, -1($s0)
/* 403AF4 E01186F4 92070001 */  lbu       $a3, 1($s0)
/* 403AF8 E01186F8 2610003C */  addiu     $s0, $s0, 0x3c
/* 403AFC E01186FC 3C02DE00 */  lui       $v0, 0xde00
/* 403B00 E0118700 AC820010 */  sw        $v0, 0x10($a0)
/* 403B04 E0118704 00031E00 */  sll       $v1, $v1, 0x18
/* 403B08 E0118708 00052C00 */  sll       $a1, $a1, 0x10
/* 403B0C E011870C 00651825 */  or        $v1, $v1, $a1
/* 403B10 E0118710 00063200 */  sll       $a2, $a2, 8
/* 403B14 E0118714 00661825 */  or        $v1, $v1, $a2
/* 403B18 E0118718 00671825 */  or        $v1, $v1, $a3
/* 403B1C E011871C AC83000C */  sw        $v1, 0xc($a0)
/* 403B20 E0118720 3C03E012 */  lui       $v1, %hi(D_E01187B0)
/* 403B24 E0118724 00681821 */  addu      $v1, $v1, $t0
/* 403B28 E0118728 8C6387B0 */  lw        $v1, %lo(D_E01187B0)($v1)
/* 403B2C E011872C 24820018 */  addiu     $v0, $a0, 0x18
/* 403B30 E0118730 AE420000 */  sw        $v0, ($s2)
/* 403B34 E0118734 24020040 */  addiu     $v0, $zero, 0x40
/* 403B38 E0118738 AC890018 */  sw        $t1, 0x18($a0)
/* 403B3C E011873C AC82001C */  sw        $v0, 0x1c($a0)
/* 403B40 E0118740 AC830014 */  sw        $v1, 0x14($a0)
/* 403B44 E0118744 8EE20008 */  lw        $v0, 8($s7)
/* 403B48 E0118748 24840020 */  addiu     $a0, $a0, 0x20
/* 403B4C E011874C 0222102A */  slt       $v0, $s1, $v0
/* 403B50 E0118750 1440FF88 */  bnez      $v0, .LE0118574
/* 403B54 E0118754 AE440000 */   sw       $a0, ($s2)
.LE0118758:
/* 403B58 E0118758 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 403B5C E011875C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 403B60 E0118760 8C620000 */  lw        $v0, ($v1)
/* 403B64 E0118764 0040202D */  daddu     $a0, $v0, $zero
/* 403B68 E0118768 24420008 */  addiu     $v0, $v0, 8
/* 403B6C E011876C AC620000 */  sw        $v0, ($v1)
/* 403B70 E0118770 3C02E700 */  lui       $v0, 0xe700
/* 403B74 E0118774 AC820000 */  sw        $v0, ($a0)
/* 403B78 E0118778 AC800004 */  sw        $zero, 4($a0)
/* 403B7C E011877C 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 403B80 E0118780 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 403B84 E0118784 8FB700BC */  lw        $s7, 0xbc($sp)
/* 403B88 E0118788 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 403B8C E011878C 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 403B90 E0118790 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 403B94 E0118794 8FB300AC */  lw        $s3, 0xac($sp)
/* 403B98 E0118798 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 403B9C E011879C 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 403BA0 E01187A0 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 403BA4 E01187A4 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 403BA8 E01187A8 03E00008 */  jr        $ra
/* 403BAC E01187AC 27BD00D0 */   addiu    $sp, $sp, 0xd0
