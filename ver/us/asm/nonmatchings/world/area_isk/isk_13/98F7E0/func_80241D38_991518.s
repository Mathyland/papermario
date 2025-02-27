.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80242F40_992720
.double 0.7142857142857143, 0.0

.section .text

glabel func_80241D38_991518
/* 991518 80241D38 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 99151C 80241D3C AFB10014 */  sw        $s1, 0x14($sp)
/* 991520 80241D40 0080882D */  daddu     $s1, $a0, $zero
/* 991524 80241D44 AFBF0020 */  sw        $ra, 0x20($sp)
/* 991528 80241D48 AFB3001C */  sw        $s3, 0x1c($sp)
/* 99152C 80241D4C AFB20018 */  sw        $s2, 0x18($sp)
/* 991530 80241D50 AFB00010 */  sw        $s0, 0x10($sp)
/* 991534 80241D54 8E30000C */  lw        $s0, 0xc($s1)
/* 991538 80241D58 8E050000 */  lw        $a1, ($s0)
/* 99153C 80241D5C 0C0B210B */  jal       evt_get_float_variable
/* 991540 80241D60 26100004 */   addiu    $s0, $s0, 4
/* 991544 80241D64 8E050000 */  lw        $a1, ($s0)
/* 991548 80241D68 26100004 */  addiu     $s0, $s0, 4
/* 99154C 80241D6C 4600010D */  trunc.w.s $f4, $f0
/* 991550 80241D70 44132000 */  mfc1      $s3, $f4
/* 991554 80241D74 0C0B210B */  jal       evt_get_float_variable
/* 991558 80241D78 0220202D */   daddu    $a0, $s1, $zero
/* 99155C 80241D7C 8E050000 */  lw        $a1, ($s0)
/* 991560 80241D80 4600010D */  trunc.w.s $f4, $f0
/* 991564 80241D84 44122000 */  mfc1      $s2, $f4
/* 991568 80241D88 0C0B210B */  jal       evt_get_float_variable
/* 99156C 80241D8C 0220202D */   daddu    $a0, $s1, $zero
/* 991570 80241D90 0220202D */  daddu     $a0, $s1, $zero
/* 991574 80241D94 3C05FD05 */  lui       $a1, 0xfd05
/* 991578 80241D98 4600010D */  trunc.w.s $f4, $f0
/* 99157C 80241D9C 44102000 */  mfc1      $s0, $f4
/* 991580 80241DA0 0C0B1EAF */  jal       evt_get_variable
/* 991584 80241DA4 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 991588 80241DA8 0040182D */  daddu     $v1, $v0, $zero
/* 99158C 80241DAC C4600050 */  lwc1      $f0, 0x50($v1)
/* 991590 80241DB0 3C018024 */  lui       $at, %hi(D_80242F40_992720)
/* 991594 80241DB4 D4222F40 */  ldc1      $f2, %lo(D_80242F40_992720)($at)
/* 991598 80241DB8 46000021 */  cvt.d.s   $f0, $f0
/* 99159C 80241DBC 46220002 */  mul.d     $f0, $f0, $f2
/* 9915A0 80241DC0 00000000 */  nop
/* 9915A4 80241DC4 3C013FE0 */  lui       $at, 0x3fe0
/* 9915A8 80241DC8 44811800 */  mtc1      $at, $f3
/* 9915AC 80241DCC 44801000 */  mtc1      $zero, $f2
/* 9915B0 80241DD0 00000000 */  nop
/* 9915B4 80241DD4 46220002 */  mul.d     $f0, $f0, $f2
/* 9915B8 80241DD8 00000000 */  nop
/* 9915BC 80241DDC 44931000 */  mtc1      $s3, $f2
/* 9915C0 80241DE0 00000000 */  nop
/* 9915C4 80241DE4 468010A0 */  cvt.s.w   $f2, $f2
/* 9915C8 80241DE8 E4620014 */  swc1      $f2, 0x14($v1)
/* 9915CC 80241DEC 44921000 */  mtc1      $s2, $f2
/* 9915D0 80241DF0 00000000 */  nop
/* 9915D4 80241DF4 468010A1 */  cvt.d.w   $f2, $f2
/* 9915D8 80241DF8 46201080 */  add.d     $f2, $f2, $f0
/* 9915DC 80241DFC 44900000 */  mtc1      $s0, $f0
/* 9915E0 80241E00 00000000 */  nop
/* 9915E4 80241E04 46800020 */  cvt.s.w   $f0, $f0
/* 9915E8 80241E08 E460001C */  swc1      $f0, 0x1c($v1)
/* 9915EC 80241E0C 462010A0 */  cvt.s.d   $f2, $f2
/* 9915F0 80241E10 E4620018 */  swc1      $f2, 0x18($v1)
/* 9915F4 80241E14 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9915F8 80241E18 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9915FC 80241E1C 8FB20018 */  lw        $s2, 0x18($sp)
/* 991600 80241E20 8FB10014 */  lw        $s1, 0x14($sp)
/* 991604 80241E24 8FB00010 */  lw        $s0, 0x10($sp)
/* 991608 80241E28 24020002 */  addiu     $v0, $zero, 2
/* 99160C 80241E2C 03E00008 */  jr        $ra
/* 991610 80241E30 27BD0028 */   addiu    $sp, $sp, 0x28
