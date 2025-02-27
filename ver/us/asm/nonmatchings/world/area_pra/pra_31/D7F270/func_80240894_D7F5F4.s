.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240894_D7F5F4
/* D7F5F4 80240894 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D7F5F8 80240898 AFB20018 */  sw        $s2, 0x18($sp)
/* D7F5FC 8024089C 0080902D */  daddu     $s2, $a0, $zero
/* D7F600 802408A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* D7F604 802408A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* D7F608 802408A8 AFB10014 */  sw        $s1, 0x14($sp)
/* D7F60C 802408AC AFB00010 */  sw        $s0, 0x10($sp)
/* D7F610 802408B0 8E42000C */  lw        $v0, 0xc($s2)
/* D7F614 802408B4 0C0B1EAF */  jal       evt_get_variable
/* D7F618 802408B8 8C450000 */   lw       $a1, ($v0)
/* D7F61C 802408BC 0240202D */  daddu     $a0, $s2, $zero
/* D7F620 802408C0 3C05FD05 */  lui       $a1, 0xfd05
/* D7F624 802408C4 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7F628 802408C8 0C0B1EAF */  jal       evt_get_variable
/* D7F62C 802408CC 0040982D */   daddu    $s3, $v0, $zero
/* D7F630 802408D0 0040302D */  daddu     $a2, $v0, $zero
/* D7F634 802408D4 00131040 */  sll       $v0, $s3, 1
/* D7F638 802408D8 00531021 */  addu      $v0, $v0, $s3
/* D7F63C 802408DC 000210C0 */  sll       $v0, $v0, 3
/* D7F640 802408E0 00C21821 */  addu      $v1, $a2, $v0
/* D7F644 802408E4 AE400084 */  sw        $zero, 0x84($s2)
/* D7F648 802408E8 C4600014 */  lwc1      $f0, 0x14($v1)
/* D7F64C 802408EC 2402005A */  addiu     $v0, $zero, 0x5a
/* D7F650 802408F0 4600008D */  trunc.w.s $f2, $f0
/* D7F654 802408F4 44041000 */  mfc1      $a0, $f2
/* D7F658 802408F8 00000000 */  nop
/* D7F65C 802408FC 10820011 */  beq       $a0, $v0, .L80240944
/* D7F660 80240900 2882005B */   slti     $v0, $a0, 0x5b
/* D7F664 80240904 50400005 */  beql      $v0, $zero, .L8024091C
/* D7F668 80240908 240200B4 */   addiu    $v0, $zero, 0xb4
/* D7F66C 8024090C 10800009 */  beqz      $a0, .L80240934
/* D7F670 80240910 0000202D */   daddu    $a0, $zero, $zero
/* D7F674 80240914 0809025E */  j         .L80240978
/* D7F678 80240918 24050001 */   addiu    $a1, $zero, 1
.L8024091C:
/* D7F67C 8024091C 1082000D */  beq       $a0, $v0, .L80240954
/* D7F680 80240920 2402010E */   addiu    $v0, $zero, 0x10e
/* D7F684 80240924 1082000F */  beq       $a0, $v0, .L80240964
/* D7F688 80240928 0000202D */   daddu    $a0, $zero, $zero
/* D7F68C 8024092C 0809025E */  j         .L80240978
/* D7F690 80240930 24050001 */   addiu    $a1, $zero, 1
.L80240934:
/* D7F694 80240934 84620002 */  lh        $v0, 2($v1)
/* D7F698 80240938 84700000 */  lh        $s0, ($v1)
/* D7F69C 8024093C 0809025C */  j         .L80240970
/* D7F6A0 80240940 2451FFFF */   addiu    $s1, $v0, -1
.L80240944:
/* D7F6A4 80240944 84620000 */  lh        $v0, ($v1)
/* D7F6A8 80240948 84710002 */  lh        $s1, 2($v1)
/* D7F6AC 8024094C 0809025C */  j         .L80240970
/* D7F6B0 80240950 24500001 */   addiu    $s0, $v0, 1
.L80240954:
/* D7F6B4 80240954 84620002 */  lh        $v0, 2($v1)
/* D7F6B8 80240958 84700000 */  lh        $s0, ($v1)
/* D7F6BC 8024095C 0809025C */  j         .L80240970
/* D7F6C0 80240960 24510001 */   addiu    $s1, $v0, 1
.L80240964:
/* D7F6C4 80240964 84620000 */  lh        $v0, ($v1)
/* D7F6C8 80240968 84710002 */  lh        $s1, 2($v1)
/* D7F6CC 8024096C 2450FFFF */  addiu     $s0, $v0, -1
.L80240970:
/* D7F6D0 80240970 0000202D */  daddu     $a0, $zero, $zero
/* D7F6D4 80240974 24050001 */  addiu     $a1, $zero, 1
.L80240978:
/* D7F6D8 80240978 00C0182D */  daddu     $v1, $a2, $zero
.L8024097C:
/* D7F6DC 8024097C 50930008 */  beql      $a0, $s3, .L802409A0
/* D7F6E0 80240980 24840001 */   addiu    $a0, $a0, 1
/* D7F6E4 80240984 84620000 */  lh        $v0, ($v1)
/* D7F6E8 80240988 56020005 */  bnel      $s0, $v0, .L802409A0
/* D7F6EC 8024098C 24840001 */   addiu    $a0, $a0, 1
/* D7F6F0 80240990 84620002 */  lh        $v0, 2($v1)
/* D7F6F4 80240994 52220001 */  beql      $s1, $v0, .L8024099C
/* D7F6F8 80240998 AE450084 */   sw       $a1, 0x84($s2)
.L8024099C:
/* D7F6FC 8024099C 24840001 */  addiu     $a0, $a0, 1
.L802409A0:
/* D7F700 802409A0 28820003 */  slti      $v0, $a0, 3
/* D7F704 802409A4 1440FFF5 */  bnez      $v0, .L8024097C
/* D7F708 802409A8 24630018 */   addiu    $v1, $v1, 0x18
/* D7F70C 802409AC 06010004 */  bgez      $s0, .L802409C0
/* D7F710 802409B0 2A020009 */   slti     $v0, $s0, 9
/* D7F714 802409B4 24020001 */  addiu     $v0, $zero, 1
/* D7F718 802409B8 AE420084 */  sw        $v0, 0x84($s2)
/* D7F71C 802409BC 2A020009 */  slti      $v0, $s0, 9
.L802409C0:
/* D7F720 802409C0 14400002 */  bnez      $v0, .L802409CC
/* D7F724 802409C4 24020001 */   addiu    $v0, $zero, 1
/* D7F728 802409C8 AE420084 */  sw        $v0, 0x84($s2)
.L802409CC:
/* D7F72C 802409CC 06210004 */  bgez      $s1, .L802409E0
/* D7F730 802409D0 2A220003 */   slti     $v0, $s1, 3
/* D7F734 802409D4 24020001 */  addiu     $v0, $zero, 1
/* D7F738 802409D8 AE420084 */  sw        $v0, 0x84($s2)
/* D7F73C 802409DC 2A220003 */  slti      $v0, $s1, 3
.L802409E0:
/* D7F740 802409E0 14400002 */  bnez      $v0, .L802409EC
/* D7F744 802409E4 24020001 */   addiu    $v0, $zero, 1
/* D7F748 802409E8 AE420084 */  sw        $v0, 0x84($s2)
.L802409EC:
/* D7F74C 802409EC 8E430084 */  lw        $v1, 0x84($s2)
/* D7F750 802409F0 24020001 */  addiu     $v0, $zero, 1
/* D7F754 802409F4 14620009 */  bne       $v1, $v0, .L80240A1C
/* D7F758 802409F8 00000000 */   nop
/* D7F75C 802409FC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D7F760 80240A00 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D7F764 80240A04 804300B4 */  lb        $v1, 0xb4($v0)
/* D7F768 80240A08 24020014 */  addiu     $v0, $zero, 0x14
/* D7F76C 80240A0C 14620003 */  bne       $v1, $v0, .L80240A1C
/* D7F770 80240A10 00000000 */   nop
/* D7F774 80240A14 0C039769 */  jal       set_action_state
/* D7F778 80240A18 0000202D */   daddu    $a0, $zero, $zero
.L80240A1C:
/* D7F77C 80240A1C 8FBF0020 */  lw        $ra, 0x20($sp)
/* D7F780 80240A20 8FB3001C */  lw        $s3, 0x1c($sp)
/* D7F784 80240A24 8FB20018 */  lw        $s2, 0x18($sp)
/* D7F788 80240A28 8FB10014 */  lw        $s1, 0x14($sp)
/* D7F78C 80240A2C 8FB00010 */  lw        $s0, 0x10($sp)
/* D7F790 80240A30 24020002 */  addiu     $v0, $zero, 2
/* D7F794 80240A34 03E00008 */  jr        $ra
/* D7F798 80240A38 27BD0028 */   addiu    $sp, $sp, 0x28
