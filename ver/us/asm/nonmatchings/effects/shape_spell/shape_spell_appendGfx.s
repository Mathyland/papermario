.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E0024D00
.double 1.2048192771084338

.section .text

glabel shape_spell_appendGfx
/* 3396A4 E0024454 27BDFF18 */  addiu     $sp, $sp, -0xe8
/* 3396A8 E0024458 3C07DB06 */  lui       $a3, 0xdb06
/* 3396AC E002445C 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 3396B0 E0024460 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 3396B4 E0024464 34E70024 */  ori       $a3, $a3, 0x24
/* 3396B8 E0024468 AFBF00B4 */  sw        $ra, 0xb4($sp)
/* 3396BC E002446C AFBE00B0 */  sw        $fp, 0xb0($sp)
/* 3396C0 E0024470 AFB700AC */  sw        $s7, 0xac($sp)
/* 3396C4 E0024474 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 3396C8 E0024478 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 3396CC E002447C AFB400A0 */  sw        $s4, 0xa0($sp)
/* 3396D0 E0024480 AFB3009C */  sw        $s3, 0x9c($sp)
/* 3396D4 E0024484 AFB20098 */  sw        $s2, 0x98($sp)
/* 3396D8 E0024488 AFB10094 */  sw        $s1, 0x94($sp)
/* 3396DC E002448C AFB00090 */  sw        $s0, 0x90($sp)
/* 3396E0 E0024490 F7BE00E0 */  sdc1      $f30, 0xe0($sp)
/* 3396E4 E0024494 F7BC00D8 */  sdc1      $f28, 0xd8($sp)
/* 3396E8 E0024498 F7BA00D0 */  sdc1      $f26, 0xd0($sp)
/* 3396EC E002449C F7B800C8 */  sdc1      $f24, 0xc8($sp)
/* 3396F0 E00244A0 F7B600C0 */  sdc1      $f22, 0xc0($sp)
/* 3396F4 E00244A4 F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* 3396F8 E00244A8 8CA30000 */  lw        $v1, ($a1)
/* 3396FC E00244AC 8C96000C */  lw        $s6, 0xc($a0)
/* 339700 E00244B0 0060302D */  daddu     $a2, $v1, $zero
/* 339704 E00244B4 24630008 */  addiu     $v1, $v1, 8
/* 339708 E00244B8 ACA30000 */  sw        $v1, ($a1)
/* 33970C E00244BC C6C40028 */  lwc1      $f4, 0x28($s6)
/* 339710 E00244C0 3C02E700 */  lui       $v0, 0xe700
/* 339714 E00244C4 E7A4007C */  swc1      $f4, 0x7c($sp)
/* 339718 E00244C8 ACC20000 */  sw        $v0, ($a2)
/* 33971C E00244CC 24620008 */  addiu     $v0, $v1, 8
/* 339720 E00244D0 ACC00004 */  sw        $zero, 4($a2)
/* 339724 E00244D4 ACA20000 */  sw        $v0, ($a1)
/* 339728 E00244D8 AC670000 */  sw        $a3, ($v1)
/* 33972C E00244DC 24670010 */  addiu     $a3, $v1, 0x10
/* 339730 E00244E0 ACA70000 */  sw        $a3, ($a1)
/* 339734 E00244E4 8C820010 */  lw        $v0, 0x10($a0)
/* 339738 E00244E8 24660018 */  addiu     $a2, $v1, 0x18
/* 33973C E00244EC ACA60000 */  sw        $a2, ($a1)
/* 339740 E00244F0 8C44001C */  lw        $a0, 0x1c($v0)
/* 339744 E00244F4 3C02DE00 */  lui       $v0, 0xde00
/* 339748 E00244F8 AC620008 */  sw        $v0, 8($v1)
/* 33974C E00244FC 3C020900 */  lui       $v0, 0x900
/* 339750 E0024500 24421080 */  addiu     $v0, $v0, 0x1080
/* 339754 E0024504 AC62000C */  sw        $v0, 0xc($v1)
/* 339758 E0024508 3C028000 */  lui       $v0, 0x8000
/* 33975C E002450C 00822021 */  addu      $a0, $a0, $v0
/* 339760 E0024510 AC640004 */  sw        $a0, 4($v1)
/* 339764 E0024514 8EC80034 */  lw        $t0, 0x34($s6)
/* 339768 E0024518 AFA80080 */  sw        $t0, 0x80($sp)
/* 33976C E002451C C6C40014 */  lwc1      $f4, 0x14($s6)
/* 339770 E0024520 C6DA0010 */  lwc1      $f26, 0x10($s6)
/* 339774 E0024524 E7A40084 */  swc1      $f4, 0x84($sp)
/* 339778 E0024528 C6C40018 */  lwc1      $f4, 0x18($s6)
/* 33977C E002452C AFA70078 */  sw        $a3, 0x78($sp)
/* 339780 E0024530 AFA60074 */  sw        $a2, 0x74($sp)
/* 339784 E0024534 E7A40088 */  swc1      $f4, 0x88($sp)
/* 339788 E0024538 8EC80000 */  lw        $t0, ($s6)
/* 33978C E002453C AFA80070 */  sw        $t0, 0x70($sp)
/* 339790 E0024540 8EC30030 */  lw        $v1, 0x30($s6)
/* 339794 E0024544 15000018 */  bnez      $t0, .LE00245A8
/* 339798 E0024548 00031040 */   sll      $v0, $v1, 1
/* 33979C E002454C 000310C0 */  sll       $v0, $v1, 3
/* 3397A0 E0024550 00431021 */  addu      $v0, $v0, $v1
/* 3397A4 E0024554 00021080 */  sll       $v0, $v0, 2
/* 3397A8 E0024558 00431023 */  subu      $v0, $v0, $v1
/* 3397AC E002455C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3397B0 E0024560 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3397B4 E0024564 4482B000 */  mtc1      $v0, $f22
/* 3397B8 E0024568 00000000 */  nop
/* 3397BC E002456C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 3397C0 E0024570 00031080 */  sll       $v0, $v1, 2
/* 3397C4 E0024574 00431021 */  addu      $v0, $v0, $v1
/* 3397C8 E0024578 00021080 */  sll       $v0, $v0, 2
/* 3397CC E002457C 00431023 */  subu      $v0, $v0, $v1
/* 3397D0 E0024580 000218C0 */  sll       $v1, $v0, 3
/* 3397D4 E0024584 00431021 */  addu      $v0, $v0, $v1
/* 3397D8 E0024588 000210C0 */  sll       $v0, $v0, 3
/* 3397DC E002458C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 3397E0 E0024590 00220821 */  addu      $at, $at, $v0
/* 3397E4 E0024594 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 3397E8 E0024598 3C014110 */  lui       $at, 0x4110
/* 3397EC E002459C 4481C000 */  mtc1      $at, $f24
/* 3397F0 E00245A0 08009176 */  j         .LE00245D8
/* 3397F4 E00245A4 46000787 */   neg.s    $f30, $f0
.LE00245A8:
/* 3397F8 E00245A8 00431021 */  addu      $v0, $v0, $v1
/* 3397FC E00245AC 000210C0 */  sll       $v0, $v0, 3
/* 339800 E00245B0 00431021 */  addu      $v0, $v0, $v1
/* 339804 E00245B4 4482B000 */  mtc1      $v0, $f22
/* 339808 E00245B8 00000000 */  nop
/* 33980C E00245BC 4680B5A0 */  cvt.s.w   $f22, $f22
/* 339810 E00245C0 C7A4007C */  lwc1      $f4, 0x7c($sp)
/* 339814 E00245C4 3C0140C0 */  lui       $at, 0x40c0
/* 339818 E00245C8 4481C000 */  mtc1      $at, $f24
/* 33981C E00245CC 4480F000 */  mtc1      $zero, $f30
/* 339820 E00245D0 4604D682 */  mul.s     $f26, $f26, $f4
/* 339824 E00245D4 00000000 */  nop
.LE00245D8:
/* 339828 E00245D8 0000B82D */  daddu     $s7, $zero, $zero
/* 33982C E00245DC 3C1E8007 */  lui       $fp, %hi(gMatrixListPos)
/* 339830 E00245E0 27DE41F0 */  addiu     $fp, $fp, %lo(gMatrixListPos)
/* 339834 E00245E4 3C080001 */  lui       $t0, 1
/* 339838 E00245E8 35081630 */  ori       $t0, $t0, 0x1630
/* 33983C E00245EC 4480E000 */  mtc1      $zero, $f28
/* 339840 E00245F0 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* 339844 E00245F4 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* 339848 E00245F8 AFA8008C */  sw        $t0, 0x8c($sp)
.LE00245FC:
/* 33984C E00245FC 1AE00033 */  blez      $s7, .LE00246CC
/* 339850 E0024600 00000000 */   nop
/* 339854 E0024604 8FA80070 */  lw        $t0, 0x70($sp)
/* 339858 E0024608 15000013 */  bnez      $t0, .LE0024658
/* 33985C E002460C 00000000 */   nop
/* 339860 E0024610 3C01428C */  lui       $at, 0x428c
/* 339864 E0024614 44810000 */  mtc1      $at, $f0
/* 339868 E0024618 00000000 */  nop
/* 33986C E002461C 4600B581 */  sub.s     $f22, $f22, $f0
/* 339870 E0024620 C6C0001C */  lwc1      $f0, 0x1c($s6)
/* 339874 E0024624 46000000 */  add.s     $f0, $f0, $f0
/* 339878 E0024628 4600D681 */  sub.s     $f26, $f26, $f0
/* 33987C E002462C C6C00020 */  lwc1      $f0, 0x20($s6)
/* 339880 E0024630 46000000 */  add.s     $f0, $f0, $f0
/* 339884 E0024634 C7A40084 */  lwc1      $f4, 0x84($sp)
/* 339888 E0024638 46002101 */  sub.s     $f4, $f4, $f0
/* 33988C E002463C E7A40084 */  swc1      $f4, 0x84($sp)
/* 339890 E0024640 C6C00024 */  lwc1      $f0, 0x24($s6)
/* 339894 E0024644 46000000 */  add.s     $f0, $f0, $f0
/* 339898 E0024648 C7A40088 */  lwc1      $f4, 0x88($sp)
/* 33989C E002464C 46002101 */  sub.s     $f4, $f4, $f0
/* 3398A0 E0024650 080091A4 */  j         .LE0024690
/* 3398A4 E0024654 E7A40088 */   swc1     $f4, 0x88($sp)
.LE0024658:
/* 3398A8 E0024658 C6C0001C */  lwc1      $f0, 0x1c($s6)
/* 3398AC E002465C 3C01E002 */  lui       $at, %hi(D_E0024D00)
/* 3398B0 E0024660 D4224D00 */  ldc1      $f2, %lo(D_E0024D00)($at)
/* 3398B4 E0024664 46000021 */  cvt.d.s   $f0, $f0
/* 3398B8 E0024668 46220002 */  mul.d     $f0, $f0, $f2
/* 3398BC E002466C 00000000 */  nop
/* 3398C0 E0024670 46200000 */  add.d     $f0, $f0, $f0
/* 3398C4 E0024674 4600D0A1 */  cvt.d.s   $f2, $f26
/* 3398C8 E0024678 46201081 */  sub.d     $f2, $f2, $f0
/* 3398CC E002467C 3C014248 */  lui       $at, 0x4248
/* 3398D0 E0024680 44810000 */  mtc1      $at, $f0
/* 3398D4 E0024684 00000000 */  nop
/* 3398D8 E0024688 4600B581 */  sub.s     $f22, $f22, $f0
/* 3398DC E002468C 462016A0 */  cvt.s.d   $f26, $f2
.LE0024690:
/* 3398E0 E0024690 3C048080 */  lui       $a0, 0x8080
/* 3398E4 E0024694 8EC30034 */  lw        $v1, 0x34($s6)
/* 3398E8 E0024698 34848081 */  ori       $a0, $a0, 0x8081
/* 3398EC E002469C 00031040 */  sll       $v0, $v1, 1
/* 3398F0 E00246A0 00431021 */  addu      $v0, $v0, $v1
/* 3398F4 E00246A4 000210C0 */  sll       $v0, $v0, 3
/* 3398F8 E00246A8 00431021 */  addu      $v0, $v0, $v1
/* 3398FC E00246AC 00021080 */  sll       $v0, $v0, 2
/* 339900 E00246B0 00440018 */  mult      $v0, $a0
/* 339904 E00246B4 00004010 */  mfhi      $t0
/* 339908 E00246B8 01021821 */  addu      $v1, $t0, $v0
/* 33990C E00246BC 000319C3 */  sra       $v1, $v1, 7
/* 339910 E00246C0 000217C3 */  sra       $v0, $v0, 0x1f
/* 339914 E00246C4 00621823 */  subu      $v1, $v1, $v0
/* 339918 E00246C8 AFA30080 */  sw        $v1, 0x80($sp)
.LE00246CC:
/* 33991C E00246CC C7A4007C */  lwc1      $f4, 0x7c($sp)
/* 339920 E00246D0 4405E000 */  mfc1      $a1, $f28
/* 339924 E00246D4 4406F000 */  mfc1      $a2, $f30
/* 339928 E00246D8 4407E000 */  mfc1      $a3, $f28
/* 33992C E00246DC E7A40010 */  swc1      $f4, 0x10($sp)
/* 339930 E00246E0 C7A40084 */  lwc1      $f4, 0x84($sp)
/* 339934 E00246E4 E7A40018 */  swc1      $f4, 0x18($sp)
/* 339938 E00246E8 C7A40088 */  lwc1      $f4, 0x88($sp)
/* 33993C E00246EC 27A40020 */  addiu     $a0, $sp, 0x20
/* 339940 E00246F0 E7BA0014 */  swc1      $f26, 0x14($sp)
/* 339944 E00246F4 0C080180 */  jal       shim_guPositionF
/* 339948 E00246F8 E7A4001C */   swc1     $f4, 0x1c($sp)
/* 33994C E00246FC 27A40020 */  addiu     $a0, $sp, 0x20
/* 339950 E0024700 97C50000 */  lhu       $a1, ($fp)
/* 339954 E0024704 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 339958 E0024708 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 33995C E002470C 8FA8008C */  lw        $t0, 0x8c($sp)
/* 339960 E0024710 00052980 */  sll       $a1, $a1, 6
/* 339964 E0024714 00A82821 */  addu      $a1, $a1, $t0
/* 339968 E0024718 0C080118 */  jal       shim_guMtxF2L
/* 33996C E002471C 00452821 */   addu     $a1, $v0, $a1
/* 339970 E0024720 8EA20000 */  lw        $v0, ($s5)
/* 339974 E0024724 4600B306 */  mov.s     $f12, $f22
/* 339978 E0024728 0040202D */  daddu     $a0, $v0, $zero
/* 33997C E002472C 24420008 */  addiu     $v0, $v0, 8
/* 339980 E0024730 AEA20000 */  sw        $v0, ($s5)
/* 339984 E0024734 97C20000 */  lhu       $v0, ($fp)
/* 339988 E0024738 3C03DA38 */  lui       $v1, 0xda38
/* 33998C E002473C AC830000 */  sw        $v1, ($a0)
/* 339990 E0024740 24430001 */  addiu     $v1, $v0, 1
/* 339994 E0024744 3042FFFF */  andi      $v0, $v0, 0xffff
/* 339998 E0024748 00021180 */  sll       $v0, $v0, 6
/* 33999C E002474C A7C30000 */  sh        $v1, ($fp)
/* 3399A0 E0024750 8FA8008C */  lw        $t0, 0x8c($sp)
/* 3399A4 E0024754 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 3399A8 E0024758 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 3399AC E002475C 00481021 */  addu      $v0, $v0, $t0
/* 3399B0 E0024760 00621821 */  addu      $v1, $v1, $v0
/* 3399B4 E0024764 0C080140 */  jal       shim_sin_deg
/* 3399B8 E0024768 AC830004 */   sw       $v1, 4($a0)
/* 3399BC E002476C 46180502 */  mul.s     $f20, $f0, $f24
/* 3399C0 E0024770 00000000 */  nop
/* 3399C4 E0024774 0C080144 */  jal       shim_cos_deg
/* 3399C8 E0024778 4600B306 */   mov.s    $f12, $f22
/* 3399CC E002477C 46180002 */  mul.s     $f0, $f0, $f24
/* 3399D0 E0024780 00000000 */  nop
/* 3399D4 E0024784 27A40020 */  addiu     $a0, $sp, 0x20
/* 3399D8 E0024788 4407E000 */  mfc1      $a3, $f28
/* 3399DC E002478C 3C0142F0 */  lui       $at, 0x42f0
/* 3399E0 E0024790 44812000 */  mtc1      $at, $f4
/* 3399E4 E0024794 44060000 */  mfc1      $a2, $f0
/* 3399E8 E0024798 4405A000 */  mfc1      $a1, $f20
/* 3399EC E002479C 0C080108 */  jal       shim_guTranslateF
/* 3399F0 E00247A0 4604B580 */   add.s    $f22, $f22, $f4
/* 3399F4 E00247A4 27A40020 */  addiu     $a0, $sp, 0x20
/* 3399F8 E00247A8 97C30000 */  lhu       $v1, ($fp)
/* 3399FC E00247AC 3C05800A */  lui       $a1, %hi(gDisplayContext)
/* 339A00 E00247B0 8CA5A674 */  lw        $a1, %lo(gDisplayContext)($a1)
/* 339A04 E00247B4 8FA8008C */  lw        $t0, 0x8c($sp)
/* 339A08 E00247B8 3062FFFF */  andi      $v0, $v1, 0xffff
/* 339A0C E00247BC 00021180 */  sll       $v0, $v0, 6
/* 339A10 E00247C0 00481021 */  addu      $v0, $v0, $t0
/* 339A14 E00247C4 00A22821 */  addu      $a1, $a1, $v0
/* 339A18 E00247C8 24630001 */  addiu     $v1, $v1, 1
/* 339A1C E00247CC A7C30000 */  sh        $v1, ($fp)
/* 339A20 E00247D0 0C080118 */  jal       shim_guMtxF2L
/* 339A24 E00247D4 AFA50060 */   sw       $a1, 0x60($sp)
/* 339A28 E00247D8 0C080140 */  jal       shim_sin_deg
/* 339A2C E00247DC 4600B306 */   mov.s    $f12, $f22
/* 339A30 E00247E0 46180502 */  mul.s     $f20, $f0, $f24
/* 339A34 E00247E4 00000000 */  nop
/* 339A38 E00247E8 0C080144 */  jal       shim_cos_deg
/* 339A3C E00247EC 4600B306 */   mov.s    $f12, $f22
/* 339A40 E00247F0 46180002 */  mul.s     $f0, $f0, $f24
/* 339A44 E00247F4 00000000 */  nop
/* 339A48 E00247F8 27A40020 */  addiu     $a0, $sp, 0x20
/* 339A4C E00247FC 4407E000 */  mfc1      $a3, $f28
/* 339A50 E0024800 3C0142F0 */  lui       $at, 0x42f0
/* 339A54 E0024804 44812000 */  mtc1      $at, $f4
/* 339A58 E0024808 44060000 */  mfc1      $a2, $f0
/* 339A5C E002480C 4405A000 */  mfc1      $a1, $f20
/* 339A60 E0024810 0C080108 */  jal       shim_guTranslateF
/* 339A64 E0024814 4604B580 */   add.s    $f22, $f22, $f4
/* 339A68 E0024818 27A40020 */  addiu     $a0, $sp, 0x20
/* 339A6C E002481C 97C30000 */  lhu       $v1, ($fp)
/* 339A70 E0024820 3C05800A */  lui       $a1, %hi(gDisplayContext)
/* 339A74 E0024824 8CA5A674 */  lw        $a1, %lo(gDisplayContext)($a1)
/* 339A78 E0024828 8FA8008C */  lw        $t0, 0x8c($sp)
/* 339A7C E002482C 3062FFFF */  andi      $v0, $v1, 0xffff
/* 339A80 E0024830 00021180 */  sll       $v0, $v0, 6
/* 339A84 E0024834 00481021 */  addu      $v0, $v0, $t0
/* 339A88 E0024838 00A22821 */  addu      $a1, $a1, $v0
/* 339A8C E002483C 24630001 */  addiu     $v1, $v1, 1
/* 339A90 E0024840 A7C30000 */  sh        $v1, ($fp)
/* 339A94 E0024844 0C080118 */  jal       shim_guMtxF2L
/* 339A98 E0024848 AFA50064 */   sw       $a1, 0x64($sp)
/* 339A9C E002484C 0C080140 */  jal       shim_sin_deg
/* 339AA0 E0024850 4600B306 */   mov.s    $f12, $f22
/* 339AA4 E0024854 46180502 */  mul.s     $f20, $f0, $f24
/* 339AA8 E0024858 00000000 */  nop
/* 339AAC E002485C 0C080144 */  jal       shim_cos_deg
/* 339AB0 E0024860 4600B306 */   mov.s    $f12, $f22
/* 339AB4 E0024864 46180002 */  mul.s     $f0, $f0, $f24
/* 339AB8 E0024868 00000000 */  nop
/* 339ABC E002486C 0000A02D */  daddu     $s4, $zero, $zero
/* 339AC0 E0024870 3C13E002 */  lui       $s3, %hi(D_E0024CC0)
/* 339AC4 E0024874 26734CC0 */  addiu     $s3, $s3, %lo(D_E0024CC0)
/* 339AC8 E0024878 4407E000 */  mfc1      $a3, $f28
/* 339ACC E002487C 44060000 */  mfc1      $a2, $f0
/* 339AD0 E0024880 4405A000 */  mfc1      $a1, $f20
/* 339AD4 E0024884 0C080108 */  jal       shim_guTranslateF
/* 339AD8 E0024888 27A40020 */   addiu    $a0, $sp, 0x20
/* 339ADC E002488C 27A40020 */  addiu     $a0, $sp, 0x20
/* 339AE0 E0024890 97C30000 */  lhu       $v1, ($fp)
/* 339AE4 E0024894 3C05800A */  lui       $a1, %hi(gDisplayContext)
/* 339AE8 E0024898 8CA5A674 */  lw        $a1, %lo(gDisplayContext)($a1)
/* 339AEC E002489C 8FA8008C */  lw        $t0, 0x8c($sp)
/* 339AF0 E00248A0 3062FFFF */  andi      $v0, $v1, 0xffff
/* 339AF4 E00248A4 00021180 */  sll       $v0, $v0, 6
/* 339AF8 E00248A8 00481021 */  addu      $v0, $v0, $t0
/* 339AFC E00248AC 00A22821 */  addu      $a1, $a1, $v0
/* 339B00 E00248B0 24630001 */  addiu     $v1, $v1, 1
/* 339B04 E00248B4 A7C30000 */  sh        $v1, ($fp)
/* 339B08 E00248B8 0C080118 */  jal       shim_guMtxF2L
/* 339B0C E00248BC AFA50068 */   sw       $a1, 0x68($sp)
.LE00248C0:
/* 339B10 E00248C0 8EB20000 */  lw        $s2, ($s5)
/* 339B14 E00248C4 3C02DA38 */  lui       $v0, 0xda38
/* 339B18 E00248C8 0240202D */  daddu     $a0, $s2, $zero
/* 339B1C E00248CC 26520008 */  addiu     $s2, $s2, 8
/* 339B20 E00248D0 AEB20000 */  sw        $s2, ($s5)
/* 339B24 E00248D4 AC820000 */  sw        $v0, ($a0)
/* 339B28 E00248D8 00141080 */  sll       $v0, $s4, 2
/* 339B2C E00248DC 03A21021 */  addu      $v0, $sp, $v0
/* 339B30 E00248E0 8C430060 */  lw        $v1, 0x60($v0)
/* 339B34 E00248E4 26420008 */  addiu     $v0, $s2, 8
/* 339B38 E00248E8 AEA20000 */  sw        $v0, ($s5)
/* 339B3C E00248EC 3C02FA00 */  lui       $v0, 0xfa00
/* 339B40 E00248F0 AC830004 */  sw        $v1, 4($a0)
/* 339B44 E00248F4 AE420000 */  sw        $v0, ($s2)
/* 339B48 E00248F8 92640001 */  lbu       $a0, 1($s3)
/* 339B4C E00248FC 0C0090EF */  jal       func_E00243BC
/* 339B50 E0024900 92650000 */   lbu      $a1, ($s3)
/* 339B54 E0024904 92640002 */  lbu       $a0, 2($s3)
/* 339B58 E0024908 92650000 */  lbu       $a1, ($s3)
/* 339B5C E002490C 0C0090EF */  jal       func_E00243BC
/* 339B60 E0024910 0040882D */   daddu    $s1, $v0, $zero
/* 339B64 E0024914 92640003 */  lbu       $a0, 3($s3)
/* 339B68 E0024918 92650000 */  lbu       $a1, ($s3)
/* 339B6C E002491C 0C0090EF */  jal       func_E00243BC
/* 339B70 E0024920 0040802D */   daddu    $s0, $v0, $zero
/* 339B74 E0024924 00118E00 */  sll       $s1, $s1, 0x18
/* 339B78 E0024928 321000FF */  andi      $s0, $s0, 0xff
/* 339B7C E002492C 00108400 */  sll       $s0, $s0, 0x10
/* 339B80 E0024930 02308825 */  or        $s1, $s1, $s0
/* 339B84 E0024934 304200FF */  andi      $v0, $v0, 0xff
/* 339B88 E0024938 00021200 */  sll       $v0, $v0, 8
/* 339B8C E002493C 02228825 */  or        $s1, $s1, $v0
/* 339B90 E0024940 8FA80080 */  lw        $t0, 0x80($sp)
/* 339B94 E0024944 8EA30000 */  lw        $v1, ($s5)
/* 339B98 E0024948 310200FF */  andi      $v0, $t0, 0xff
/* 339B9C E002494C 02228825 */  or        $s1, $s1, $v0
/* 339BA0 E0024950 AE510004 */  sw        $s1, 4($s2)
/* 339BA4 E0024954 0060902D */  daddu     $s2, $v1, $zero
/* 339BA8 E0024958 24630008 */  addiu     $v1, $v1, 8
/* 339BAC E002495C 3C02FB00 */  lui       $v0, 0xfb00
/* 339BB0 E0024960 AEA30000 */  sw        $v1, ($s5)
/* 339BB4 E0024964 AE420000 */  sw        $v0, ($s2)
/* 339BB8 E0024968 92640001 */  lbu       $a0, 1($s3)
/* 339BBC E002496C 0C0090C9 */  jal       func_E0024324
/* 339BC0 E0024970 92650000 */   lbu      $a1, ($s3)
/* 339BC4 E0024974 92640002 */  lbu       $a0, 2($s3)
/* 339BC8 E0024978 92650000 */  lbu       $a1, ($s3)
/* 339BCC E002497C 0C0090C9 */  jal       func_E0024324
/* 339BD0 E0024980 0040882D */   daddu    $s1, $v0, $zero
/* 339BD4 E0024984 92640003 */  lbu       $a0, 3($s3)
/* 339BD8 E0024988 92650000 */  lbu       $a1, ($s3)
/* 339BDC E002498C 0C0090C9 */  jal       func_E0024324
/* 339BE0 E0024990 0040802D */   daddu    $s0, $v0, $zero
/* 339BE4 E0024994 00118E00 */  sll       $s1, $s1, 0x18
/* 339BE8 E0024998 321000FF */  andi      $s0, $s0, 0xff
/* 339BEC E002499C 00108400 */  sll       $s0, $s0, 0x10
/* 339BF0 E00249A0 02308825 */  or        $s1, $s1, $s0
/* 339BF4 E00249A4 304200FF */  andi      $v0, $v0, 0xff
/* 339BF8 E00249A8 00021200 */  sll       $v0, $v0, 8
/* 339BFC E00249AC 02228825 */  or        $s1, $s1, $v0
/* 339C00 E00249B0 363100FF */  ori       $s1, $s1, 0xff
/* 339C04 E00249B4 8EA40000 */  lw        $a0, ($s5)
/* 339C08 E00249B8 3C02DE00 */  lui       $v0, 0xde00
/* 339C0C E00249BC AE510004 */  sw        $s1, 4($s2)
/* 339C10 E00249C0 0080182D */  daddu     $v1, $a0, $zero
/* 339C14 E00249C4 24840008 */  addiu     $a0, $a0, 8
/* 339C18 E00249C8 AEA40000 */  sw        $a0, ($s5)
/* 339C1C E00249CC AC620000 */  sw        $v0, ($v1)
/* 339C20 E00249D0 8FA80070 */  lw        $t0, 0x70($sp)
/* 339C24 E00249D4 15000004 */  bnez      $t0, .LE00249E8
/* 339C28 E00249D8 24630004 */   addiu    $v1, $v1, 4
/* 339C2C E00249DC 8E640004 */  lw        $a0, 4($s3)
/* 339C30 E00249E0 0800927C */  j         .LE00249F0
/* 339C34 E00249E4 3C05D838 */   lui      $a1, 0xd838
.LE00249E8:
/* 339C38 E00249E8 8E640008 */  lw        $a0, 8($s3)
/* 339C3C E00249EC 3C05D838 */  lui       $a1, 0xd838
.LE00249F0:
/* 339C40 E00249F0 34A50002 */  ori       $a1, $a1, 2
/* 339C44 E00249F4 2673000C */  addiu     $s3, $s3, 0xc
/* 339C48 E00249F8 8EA20000 */  lw        $v0, ($s5)
/* 339C4C E00249FC 26940001 */  addiu     $s4, $s4, 1
/* 339C50 E0024A00 AC640000 */  sw        $a0, ($v1)
/* 339C54 E0024A04 24040040 */  addiu     $a0, $zero, 0x40
/* 339C58 E0024A08 0040182D */  daddu     $v1, $v0, $zero
/* 339C5C E0024A0C 24420008 */  addiu     $v0, $v0, 8
/* 339C60 E0024A10 AEA20000 */  sw        $v0, ($s5)
/* 339C64 E0024A14 2A820003 */  slti      $v0, $s4, 3
/* 339C68 E0024A18 AC650000 */  sw        $a1, ($v1)
/* 339C6C E0024A1C 1440FFA8 */  bnez      $v0, .LE00248C0
/* 339C70 E0024A20 AC640004 */   sw       $a0, 4($v1)
/* 339C74 E0024A24 8EA20000 */  lw        $v0, ($s5)
/* 339C78 E0024A28 26F70001 */  addiu     $s7, $s7, 1
/* 339C7C E0024A2C 0040182D */  daddu     $v1, $v0, $zero
/* 339C80 E0024A30 24420008 */  addiu     $v0, $v0, 8
/* 339C84 E0024A34 AEA20000 */  sw        $v0, ($s5)
/* 339C88 E0024A38 2AE20003 */  slti      $v0, $s7, 3
/* 339C8C E0024A3C AC650000 */  sw        $a1, ($v1)
/* 339C90 E0024A40 1440FEEE */  bnez      $v0, .LE00245FC
/* 339C94 E0024A44 AC640004 */   sw       $a0, 4($v1)
/* 339C98 E0024A48 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 339C9C E0024A4C 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 339CA0 E0024A50 8C430000 */  lw        $v1, ($v0)
/* 339CA4 E0024A54 0060202D */  daddu     $a0, $v1, $zero
/* 339CA8 E0024A58 24630008 */  addiu     $v1, $v1, 8
/* 339CAC E0024A5C AC430000 */  sw        $v1, ($v0)
/* 339CB0 E0024A60 3C02DF00 */  lui       $v0, 0xdf00
/* 339CB4 E0024A64 AC820000 */  sw        $v0, ($a0)
/* 339CB8 E0024A68 AC800004 */  sw        $zero, 4($a0)
/* 339CBC E0024A6C 8FA80078 */  lw        $t0, 0x78($sp)
/* 339CC0 E0024A70 3C02DE01 */  lui       $v0, 0xde01
/* 339CC4 E0024A74 AD020000 */  sw        $v0, ($t0)
/* 339CC8 E0024A78 AD030004 */  sw        $v1, 4($t0)
/* 339CCC E0024A7C 8FA80070 */  lw        $t0, 0x70($sp)
/* 339CD0 E0024A80 15000004 */  bnez      $t0, .LE0024A94
/* 339CD4 E0024A84 00000000 */   nop
/* 339CD8 E0024A88 4480F000 */  mtc1      $zero, $f30
/* 339CDC E0024A8C 080092B2 */  j         .LE0024AC8
/* 339CE0 E0024A90 00000000 */   nop
.LE0024A94:
/* 339CE4 E0024A94 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 339CE8 E0024A98 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 339CEC E0024A9C 00031080 */  sll       $v0, $v1, 2
/* 339CF0 E0024AA0 00431021 */  addu      $v0, $v0, $v1
/* 339CF4 E0024AA4 00021080 */  sll       $v0, $v0, 2
/* 339CF8 E0024AA8 00431023 */  subu      $v0, $v0, $v1
/* 339CFC E0024AAC 000218C0 */  sll       $v1, $v0, 3
/* 339D00 E0024AB0 00431021 */  addu      $v0, $v0, $v1
/* 339D04 E0024AB4 000210C0 */  sll       $v0, $v0, 3
/* 339D08 E0024AB8 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 339D0C E0024ABC 00220821 */  addu      $at, $at, $v0
/* 339D10 E0024AC0 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 339D14 E0024AC4 46000787 */  neg.s     $f30, $f0
.LE0024AC8:
/* 339D18 E0024AC8 4480A000 */  mtc1      $zero, $f20
/* 339D1C E0024ACC 3C013F80 */  lui       $at, 0x3f80
/* 339D20 E0024AD0 4481B000 */  mtc1      $at, $f22
/* 339D24 E0024AD4 4406F000 */  mfc1      $a2, $f30
/* 339D28 E0024AD8 4405A000 */  mfc1      $a1, $f20
/* 339D2C E0024ADC 4407A000 */  mfc1      $a3, $f20
/* 339D30 E0024AE0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 339D34 E0024AE4 C6C00004 */  lwc1      $f0, 4($s6)
/* 339D38 E0024AE8 27A40020 */  addiu     $a0, $sp, 0x20
/* 339D3C E0024AEC E7A00014 */  swc1      $f0, 0x14($sp)
/* 339D40 E0024AF0 C6C00008 */  lwc1      $f0, 8($s6)
/* 339D44 E0024AF4 3C100001 */  lui       $s0, 1
/* 339D48 E0024AF8 E7A00018 */  swc1      $f0, 0x18($sp)
/* 339D4C E0024AFC C6C0000C */  lwc1      $f0, 0xc($s6)
/* 339D50 E0024B00 36101630 */  ori       $s0, $s0, 0x1630
/* 339D54 E0024B04 0C080180 */  jal       shim_guPositionF
/* 339D58 E0024B08 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 339D5C E0024B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* 339D60 E0024B10 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 339D64 E0024B14 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 339D68 E0024B18 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* 339D6C E0024B1C 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* 339D70 E0024B20 96250000 */  lhu       $a1, ($s1)
/* 339D74 E0024B24 8E620000 */  lw        $v0, ($s3)
/* 339D78 E0024B28 00052980 */  sll       $a1, $a1, 6
/* 339D7C E0024B2C 00B02821 */  addu      $a1, $a1, $s0
/* 339D80 E0024B30 0C080118 */  jal       shim_guMtxF2L
/* 339D84 E0024B34 00452821 */   addu     $a1, $v0, $a1
/* 339D88 E0024B38 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 339D8C E0024B3C 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 339D90 E0024B40 8E450000 */  lw        $a1, ($s2)
/* 339D94 E0024B44 00A0202D */  daddu     $a0, $a1, $zero
/* 339D98 E0024B48 24A50008 */  addiu     $a1, $a1, 8
/* 339D9C E0024B4C AE450000 */  sw        $a1, ($s2)
/* 339DA0 E0024B50 96220000 */  lhu       $v0, ($s1)
/* 339DA4 E0024B54 3C03DA38 */  lui       $v1, 0xda38
/* 339DA8 E0024B58 AC830000 */  sw        $v1, ($a0)
/* 339DAC E0024B5C 24430001 */  addiu     $v1, $v0, 1
/* 339DB0 E0024B60 3042FFFF */  andi      $v0, $v0, 0xffff
/* 339DB4 E0024B64 00021180 */  sll       $v0, $v0, 6
/* 339DB8 E0024B68 A6230000 */  sh        $v1, ($s1)
/* 339DBC E0024B6C 8E630000 */  lw        $v1, ($s3)
/* 339DC0 E0024B70 00501021 */  addu      $v0, $v0, $s0
/* 339DC4 E0024B74 00621821 */  addu      $v1, $v1, $v0
/* 339DC8 E0024B78 AC830004 */  sw        $v1, 4($a0)
/* 339DCC E0024B7C 8FA80070 */  lw        $t0, 0x70($sp)
/* 339DD0 E0024B80 15000008 */  bnez      $t0, .LE0024BA4
/* 339DD4 E0024B84 27A40020 */   addiu    $a0, $sp, 0x20
/* 339DD8 E0024B88 24A20008 */  addiu     $v0, $a1, 8
/* 339DDC E0024B8C AE420000 */  sw        $v0, ($s2)
/* 339DE0 E0024B90 3C02DE00 */  lui       $v0, 0xde00
/* 339DE4 E0024B94 ACA20000 */  sw        $v0, ($a1)
/* 339DE8 E0024B98 8FA80074 */  lw        $t0, 0x74($sp)
/* 339DEC E0024B9C 0800930C */  j         .LE0024C30
/* 339DF0 E0024BA0 ACA80004 */   sw       $t0, 4($a1)
.LE0024BA4:
/* 339DF4 E0024BA4 3C0541F0 */  lui       $a1, 0x41f0
/* 339DF8 E0024BA8 4406A000 */  mfc1      $a2, $f20
/* 339DFC E0024BAC 0000B82D */  daddu     $s7, $zero, $zero
/* 339E00 E0024BB0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 339E04 E0024BB4 0C080104 */  jal       shim_guRotateF
/* 339E08 E0024BB8 00C0382D */   daddu    $a3, $a2, $zero
/* 339E0C E0024BBC 27A40020 */  addiu     $a0, $sp, 0x20
/* 339E10 E0024BC0 96220000 */  lhu       $v0, ($s1)
/* 339E14 E0024BC4 8E650000 */  lw        $a1, ($s3)
/* 339E18 E0024BC8 3043FFFF */  andi      $v1, $v0, 0xffff
/* 339E1C E0024BCC 00031980 */  sll       $v1, $v1, 6
/* 339E20 E0024BD0 00701821 */  addu      $v1, $v1, $s0
/* 339E24 E0024BD4 00A38021 */  addu      $s0, $a1, $v1
/* 339E28 E0024BD8 0200282D */  daddu     $a1, $s0, $zero
/* 339E2C E0024BDC 24420001 */  addiu     $v0, $v0, 1
/* 339E30 E0024BE0 0C080118 */  jal       shim_guMtxF2L
/* 339E34 E0024BE4 A6220000 */   sh       $v0, ($s1)
/* 339E38 E0024BE8 0240202D */  daddu     $a0, $s2, $zero
/* 339E3C E0024BEC 3C05DA38 */  lui       $a1, 0xda38
/* 339E40 E0024BF0 34A50001 */  ori       $a1, $a1, 1
/* 339E44 E0024BF4 3C06DE00 */  lui       $a2, 0xde00
.LE0024BF8:
/* 339E48 E0024BF8 8C830000 */  lw        $v1, ($a0)
/* 339E4C E0024BFC 26F70001 */  addiu     $s7, $s7, 1
/* 339E50 E0024C00 0060102D */  daddu     $v0, $v1, $zero
/* 339E54 E0024C04 24630008 */  addiu     $v1, $v1, 8
/* 339E58 E0024C08 AC830000 */  sw        $v1, ($a0)
/* 339E5C E0024C0C AC450000 */  sw        $a1, ($v0)
/* 339E60 E0024C10 AC500004 */  sw        $s0, 4($v0)
/* 339E64 E0024C14 24620008 */  addiu     $v0, $v1, 8
/* 339E68 E0024C18 AC820000 */  sw        $v0, ($a0)
/* 339E6C E0024C1C AC660000 */  sw        $a2, ($v1)
/* 339E70 E0024C20 8FA80074 */  lw        $t0, 0x74($sp)
/* 339E74 E0024C24 2AE2000C */  slti      $v0, $s7, 0xc
/* 339E78 E0024C28 1440FFF3 */  bnez      $v0, .LE0024BF8
/* 339E7C E0024C2C AC680004 */   sw       $t0, 4($v1)
.LE0024C30:
/* 339E80 E0024C30 3C03D838 */  lui       $v1, 0xd838
/* 339E84 E0024C34 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 339E88 E0024C38 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 339E8C E0024C3C 8C820000 */  lw        $v0, ($a0)
/* 339E90 E0024C40 34630002 */  ori       $v1, $v1, 2
/* 339E94 E0024C44 0040282D */  daddu     $a1, $v0, $zero
/* 339E98 E0024C48 24420008 */  addiu     $v0, $v0, 8
/* 339E9C E0024C4C AC820000 */  sw        $v0, ($a0)
/* 339EA0 E0024C50 ACA30000 */  sw        $v1, ($a1)
/* 339EA4 E0024C54 24030040 */  addiu     $v1, $zero, 0x40
/* 339EA8 E0024C58 ACA30004 */  sw        $v1, 4($a1)
/* 339EAC E0024C5C 24430008 */  addiu     $v1, $v0, 8
/* 339EB0 E0024C60 AC830000 */  sw        $v1, ($a0)
/* 339EB4 E0024C64 3C03E700 */  lui       $v1, 0xe700
/* 339EB8 E0024C68 AC430000 */  sw        $v1, ($v0)
/* 339EBC E0024C6C AC400004 */  sw        $zero, 4($v0)
/* 339EC0 E0024C70 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* 339EC4 E0024C74 8FBE00B0 */  lw        $fp, 0xb0($sp)
/* 339EC8 E0024C78 8FB700AC */  lw        $s7, 0xac($sp)
/* 339ECC E0024C7C 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 339ED0 E0024C80 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 339ED4 E0024C84 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 339ED8 E0024C88 8FB3009C */  lw        $s3, 0x9c($sp)
/* 339EDC E0024C8C 8FB20098 */  lw        $s2, 0x98($sp)
/* 339EE0 E0024C90 8FB10094 */  lw        $s1, 0x94($sp)
/* 339EE4 E0024C94 8FB00090 */  lw        $s0, 0x90($sp)
/* 339EE8 E0024C98 D7BE00E0 */  ldc1      $f30, 0xe0($sp)
/* 339EEC E0024C9C D7BC00D8 */  ldc1      $f28, 0xd8($sp)
/* 339EF0 E0024CA0 D7BA00D0 */  ldc1      $f26, 0xd0($sp)
/* 339EF4 E0024CA4 D7B800C8 */  ldc1      $f24, 0xc8($sp)
/* 339EF8 E0024CA8 D7B600C0 */  ldc1      $f22, 0xc0($sp)
/* 339EFC E0024CAC D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* 339F00 E0024CB0 03E00008 */  jr        $ra
/* 339F04 E0024CB4 27BD00E8 */   addiu    $sp, $sp, 0xe8
/* 339F08 E0024CB8 00000000 */  nop
/* 339F0C E0024CBC 00000000 */  nop
