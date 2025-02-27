.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802199C0_60A470
/* 60A470 802199C0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 60A474 802199C4 AFB00020 */  sw        $s0, 0x20($sp)
/* 60A478 802199C8 0080802D */  daddu     $s0, $a0, $zero
/* 60A47C 802199CC AFBF0028 */  sw        $ra, 0x28($sp)
/* 60A480 802199D0 AFB10024 */  sw        $s1, 0x24($sp)
/* 60A484 802199D4 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 60A488 802199D8 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 60A48C 802199DC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 60A490 802199E0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 60A494 802199E4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 60A498 802199E8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 60A49C 802199EC 8E02000C */  lw        $v0, 0xc($s0)
/* 60A4A0 802199F0 0C0B1EAF */  jal       evt_get_variable
/* 60A4A4 802199F4 8C450000 */   lw       $a1, ($v0)
/* 60A4A8 802199F8 0040882D */  daddu     $s1, $v0, $zero
/* 60A4AC 802199FC 24040001 */  addiu     $a0, $zero, 1
/* 60A4B0 80219A00 1224002F */  beq       $s1, $a0, .L80219AC0
/* 60A4B4 80219A04 AE110070 */   sw       $s1, 0x70($s0)
/* 60A4B8 80219A08 2A220002 */  slti      $v0, $s1, 2
/* 60A4BC 80219A0C 10400005 */  beqz      $v0, .L80219A24
/* 60A4C0 80219A10 24020002 */   addiu    $v0, $zero, 2
/* 60A4C4 80219A14 12200009 */  beqz      $s1, .L80219A3C
/* 60A4C8 80219A18 2402008E */   addiu    $v0, $zero, 0x8e
/* 60A4CC 80219A1C 08086770 */  j         .L80219DC0
/* 60A4D0 80219A20 00000000 */   nop
.L80219A24:
/* 60A4D4 80219A24 12220085 */  beq       $s1, $v0, .L80219C3C
/* 60A4D8 80219A28 24020003 */   addiu    $v0, $zero, 3
/* 60A4DC 80219A2C 12220013 */  beq       $s1, $v0, .L80219A7C
/* 60A4E0 80219A30 2403005B */   addiu    $v1, $zero, 0x5b
/* 60A4E4 80219A34 08086770 */  j         .L80219DC0
/* 60A4E8 80219A38 00000000 */   nop
.L80219A3C:
/* 60A4EC 80219A3C 3C01430E */  lui       $at, 0x430e
/* 60A4F0 80219A40 44812000 */  mtc1      $at, $f4
/* 60A4F4 80219A44 3C01C2EC */  lui       $at, 0xc2ec
/* 60A4F8 80219A48 4481F000 */  mtc1      $at, $f30
/* 60A4FC 80219A4C 2403FF8A */  addiu     $v1, $zero, -0x76
/* 60A500 80219A50 AFA00014 */  sw        $zero, 0x14($sp)
/* 60A504 80219A54 E7A40010 */  swc1      $f4, 0x10($sp)
/* 60A508 80219A58 AE020090 */  sw        $v0, 0x90($s0)
/* 60A50C 80219A5C 2402002C */  addiu     $v0, $zero, 0x2c
/* 60A510 80219A60 AE02009C */  sw        $v0, 0x9c($s0)
/* 60A514 80219A64 24020003 */  addiu     $v0, $zero, 3
/* 60A518 80219A68 AE000094 */  sw        $zero, 0x94($s0)
/* 60A51C 80219A6C AE030098 */  sw        $v1, 0x98($s0)
/* 60A520 80219A70 AE0300A0 */  sw        $v1, 0xa0($s0)
/* 60A524 80219A74 080866AC */  j         .L80219AB0
/* 60A528 80219A78 AE0200A4 */   sw       $v0, 0xa4($s0)
.L80219A7C:
/* 60A52C 80219A7C 3C0142B6 */  lui       $at, 0x42b6
/* 60A530 80219A80 44812000 */  mtc1      $at, $f4
/* 60A534 80219A84 3C01C2EC */  lui       $at, 0xc2ec
/* 60A538 80219A88 4481F000 */  mtc1      $at, $f30
/* 60A53C 80219A8C 2402FF8A */  addiu     $v0, $zero, -0x76
/* 60A540 80219A90 AFA00014 */  sw        $zero, 0x14($sp)
/* 60A544 80219A94 E7A40010 */  swc1      $f4, 0x10($sp)
/* 60A548 80219A98 AE030090 */  sw        $v1, 0x90($s0)
/* 60A54C 80219A9C AE000094 */  sw        $zero, 0x94($s0)
/* 60A550 80219AA0 AE020098 */  sw        $v0, 0x98($s0)
/* 60A554 80219AA4 AE03009C */  sw        $v1, 0x9c($s0)
/* 60A558 80219AA8 AE0200A0 */  sw        $v0, 0xa0($s0)
/* 60A55C 80219AAC AE1100A4 */  sw        $s1, 0xa4($s0)
.L80219AB0:
/* 60A560 80219AB0 AE0000A8 */  sw        $zero, 0xa8($s0)
/* 60A564 80219AB4 AE0000B0 */  sw        $zero, 0xb0($s0)
/* 60A568 80219AB8 08086770 */  j         .L80219DC0
/* 60A56C 80219ABC AE040070 */   sw       $a0, 0x70($s0)
.L80219AC0:
/* 60A570 80219AC0 8E0200A8 */  lw        $v0, 0xa8($s0)
/* 60A574 80219AC4 8E0300A4 */  lw        $v1, 0xa4($s0)
/* 60A578 80219AC8 00431021 */  addu      $v0, $v0, $v1
/* 60A57C 80219ACC AE0200A8 */  sw        $v0, 0xa8($s0)
/* 60A580 80219AD0 2842002E */  slti      $v0, $v0, 0x2e
/* 60A584 80219AD4 14400003 */  bnez      $v0, .L80219AE4
/* 60A588 80219AD8 00000000 */   nop
/* 60A58C 80219ADC 2402002D */  addiu     $v0, $zero, 0x2d
/* 60A590 80219AE0 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80219AE4:
/* 60A594 80219AE4 C6040090 */  lwc1      $f4, 0x90($s0)
/* 60A598 80219AE8 46802120 */  cvt.s.w   $f4, $f4
/* 60A59C 80219AEC E7A40010 */  swc1      $f4, 0x10($sp)
/* 60A5A0 80219AF0 C6040094 */  lwc1      $f4, 0x94($s0)
/* 60A5A4 80219AF4 46802120 */  cvt.s.w   $f4, $f4
/* 60A5A8 80219AF8 E7A40014 */  swc1      $f4, 0x14($sp)
/* 60A5AC 80219AFC C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 60A5B0 80219B00 46806320 */  cvt.s.w   $f12, $f12
/* 60A5B4 80219B04 3C0140C9 */  lui       $at, 0x40c9
/* 60A5B8 80219B08 34210FD0 */  ori       $at, $at, 0xfd0
/* 60A5BC 80219B0C 4481D000 */  mtc1      $at, $f26
/* 60A5C0 80219B10 C61E0098 */  lwc1      $f30, 0x98($s0)
/* 60A5C4 80219B14 4680F7A0 */  cvt.s.w   $f30, $f30
/* 60A5C8 80219B18 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A5CC 80219B1C 00000000 */  nop
/* 60A5D0 80219B20 C61C009C */  lwc1      $f28, 0x9c($s0)
/* 60A5D4 80219B24 4680E720 */  cvt.s.w   $f28, $f28
/* 60A5D8 80219B28 3C0143B4 */  lui       $at, 0x43b4
/* 60A5DC 80219B2C 4481C000 */  mtc1      $at, $f24
/* 60A5E0 80219B30 C60400A0 */  lwc1      $f4, 0xa0($s0)
/* 60A5E4 80219B34 46802120 */  cvt.s.w   $f4, $f4
/* 60A5E8 80219B38 E7A40018 */  swc1      $f4, 0x18($sp)
/* 60A5EC 80219B3C 0C00A85B */  jal       sin_rad
/* 60A5F0 80219B40 46186303 */   div.s    $f12, $f12, $f24
/* 60A5F4 80219B44 46000021 */  cvt.d.s   $f0, $f0
/* 60A5F8 80219B48 3C013FF0 */  lui       $at, 0x3ff0
/* 60A5FC 80219B4C 4481B800 */  mtc1      $at, $f23
/* 60A600 80219B50 4480B000 */  mtc1      $zero, $f22
/* 60A604 80219B54 C7A40010 */  lwc1      $f4, 0x10($sp)
/* 60A608 80219B58 4620B001 */  sub.d     $f0, $f22, $f0
/* 60A60C 80219B5C 46002521 */  cvt.d.s   $f20, $f4
/* 60A610 80219B60 4620A502 */  mul.d     $f20, $f20, $f0
/* 60A614 80219B64 00000000 */  nop
/* 60A618 80219B68 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 60A61C 80219B6C 46806320 */  cvt.s.w   $f12, $f12
/* 60A620 80219B70 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A624 80219B74 00000000 */  nop
/* 60A628 80219B78 0C00A85B */  jal       sin_rad
/* 60A62C 80219B7C 46186303 */   div.s    $f12, $f12, $f24
/* 60A630 80219B80 4600E002 */  mul.s     $f0, $f28, $f0
/* 60A634 80219B84 00000000 */  nop
/* 60A638 80219B88 8E0200A8 */  lw        $v0, 0xa8($s0)
/* 60A63C 80219B8C 00021040 */  sll       $v0, $v0, 1
/* 60A640 80219B90 44826000 */  mtc1      $v0, $f12
/* 60A644 80219B94 00000000 */  nop
/* 60A648 80219B98 46806320 */  cvt.s.w   $f12, $f12
/* 60A64C 80219B9C 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A650 80219BA0 00000000 */  nop
/* 60A654 80219BA4 46000021 */  cvt.d.s   $f0, $f0
/* 60A658 80219BA8 4620A500 */  add.d     $f20, $f20, $f0
/* 60A65C 80219BAC 46186303 */  div.s     $f12, $f12, $f24
/* 60A660 80219BB0 4620A520 */  cvt.s.d   $f20, $f20
/* 60A664 80219BB4 0C00A85B */  jal       sin_rad
/* 60A668 80219BB8 E7B40010 */   swc1     $f20, 0x10($sp)
/* 60A66C 80219BBC C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 60A670 80219BC0 46806320 */  cvt.s.w   $f12, $f12
/* 60A674 80219BC4 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A678 80219BC8 00000000 */  nop
/* 60A67C 80219BCC 3C0142B4 */  lui       $at, 0x42b4
/* 60A680 80219BD0 44811000 */  mtc1      $at, $f2
/* 60A684 80219BD4 00000000 */  nop
/* 60A688 80219BD8 46020002 */  mul.s     $f0, $f0, $f2
/* 60A68C 80219BDC 00000000 */  nop
/* 60A690 80219BE0 C7A40014 */  lwc1      $f4, 0x14($sp)
/* 60A694 80219BE4 46002100 */  add.s     $f4, $f4, $f0
/* 60A698 80219BE8 46186303 */  div.s     $f12, $f12, $f24
/* 60A69C 80219BEC 0C00A85B */  jal       sin_rad
/* 60A6A0 80219BF0 E7A40014 */   swc1     $f4, 0x14($sp)
/* 60A6A4 80219BF4 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 60A6A8 80219BF8 46806320 */  cvt.s.w   $f12, $f12
/* 60A6AC 80219BFC 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A6B0 80219C00 00000000 */  nop
/* 60A6B4 80219C04 46000021 */  cvt.d.s   $f0, $f0
/* 60A6B8 80219C08 4620B581 */  sub.d     $f22, $f22, $f0
/* 60A6BC 80219C0C 4600F521 */  cvt.d.s   $f20, $f30
/* 60A6C0 80219C10 4636A502 */  mul.d     $f20, $f20, $f22
/* 60A6C4 80219C14 00000000 */  nop
/* 60A6C8 80219C18 0C00A85B */  jal       sin_rad
/* 60A6CC 80219C1C 46186303 */   div.s    $f12, $f12, $f24
/* 60A6D0 80219C20 C7A40018 */  lwc1      $f4, 0x18($sp)
/* 60A6D4 80219C24 46002002 */  mul.s     $f0, $f4, $f0
/* 60A6D8 80219C28 00000000 */  nop
/* 60A6DC 80219C2C 46000021 */  cvt.d.s   $f0, $f0
/* 60A6E0 80219C30 4620A500 */  add.d     $f20, $f20, $f0
/* 60A6E4 80219C34 0808676C */  j         .L80219DB0
/* 60A6E8 80219C38 2402002D */   addiu    $v0, $zero, 0x2d
.L80219C3C:
/* 60A6EC 80219C3C 8E0200A8 */  lw        $v0, 0xa8($s0)
/* 60A6F0 80219C40 8E0300A4 */  lw        $v1, 0xa4($s0)
/* 60A6F4 80219C44 00431021 */  addu      $v0, $v0, $v1
/* 60A6F8 80219C48 AE0200A8 */  sw        $v0, 0xa8($s0)
/* 60A6FC 80219C4C 2842005B */  slti      $v0, $v0, 0x5b
/* 60A700 80219C50 14400002 */  bnez      $v0, .L80219C5C
/* 60A704 80219C54 2402005A */   addiu    $v0, $zero, 0x5a
/* 60A708 80219C58 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80219C5C:
/* 60A70C 80219C5C C6040090 */  lwc1      $f4, 0x90($s0)
/* 60A710 80219C60 46802120 */  cvt.s.w   $f4, $f4
/* 60A714 80219C64 E7A40010 */  swc1      $f4, 0x10($sp)
/* 60A718 80219C68 C6040094 */  lwc1      $f4, 0x94($s0)
/* 60A71C 80219C6C 46802120 */  cvt.s.w   $f4, $f4
/* 60A720 80219C70 E7A40014 */  swc1      $f4, 0x14($sp)
/* 60A724 80219C74 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 60A728 80219C78 46806320 */  cvt.s.w   $f12, $f12
/* 60A72C 80219C7C 3C0140C9 */  lui       $at, 0x40c9
/* 60A730 80219C80 34210FD0 */  ori       $at, $at, 0xfd0
/* 60A734 80219C84 4481D000 */  mtc1      $at, $f26
/* 60A738 80219C88 C61E0098 */  lwc1      $f30, 0x98($s0)
/* 60A73C 80219C8C 4680F7A0 */  cvt.s.w   $f30, $f30
/* 60A740 80219C90 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A744 80219C94 00000000 */  nop
/* 60A748 80219C98 C61C009C */  lwc1      $f28, 0x9c($s0)
/* 60A74C 80219C9C 4680E720 */  cvt.s.w   $f28, $f28
/* 60A750 80219CA0 3C0143B4 */  lui       $at, 0x43b4
/* 60A754 80219CA4 4481C000 */  mtc1      $at, $f24
/* 60A758 80219CA8 C60400A0 */  lwc1      $f4, 0xa0($s0)
/* 60A75C 80219CAC 46802120 */  cvt.s.w   $f4, $f4
/* 60A760 80219CB0 E7A40018 */  swc1      $f4, 0x18($sp)
/* 60A764 80219CB4 0C00A85B */  jal       sin_rad
/* 60A768 80219CB8 46186303 */   div.s    $f12, $f12, $f24
/* 60A76C 80219CBC 46000021 */  cvt.d.s   $f0, $f0
/* 60A770 80219CC0 3C013FF0 */  lui       $at, 0x3ff0
/* 60A774 80219CC4 4481B800 */  mtc1      $at, $f23
/* 60A778 80219CC8 4480B000 */  mtc1      $zero, $f22
/* 60A77C 80219CCC C7A40010 */  lwc1      $f4, 0x10($sp)
/* 60A780 80219CD0 4620B001 */  sub.d     $f0, $f22, $f0
/* 60A784 80219CD4 46002521 */  cvt.d.s   $f20, $f4
/* 60A788 80219CD8 4620A502 */  mul.d     $f20, $f20, $f0
/* 60A78C 80219CDC 00000000 */  nop
/* 60A790 80219CE0 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 60A794 80219CE4 46806320 */  cvt.s.w   $f12, $f12
/* 60A798 80219CE8 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A79C 80219CEC 00000000 */  nop
/* 60A7A0 80219CF0 0C00A85B */  jal       sin_rad
/* 60A7A4 80219CF4 46186303 */   div.s    $f12, $f12, $f24
/* 60A7A8 80219CF8 4600E002 */  mul.s     $f0, $f28, $f0
/* 60A7AC 80219CFC 00000000 */  nop
/* 60A7B0 80219D00 8E0200A8 */  lw        $v0, 0xa8($s0)
/* 60A7B4 80219D04 00021040 */  sll       $v0, $v0, 1
/* 60A7B8 80219D08 44826000 */  mtc1      $v0, $f12
/* 60A7BC 80219D0C 00000000 */  nop
/* 60A7C0 80219D10 46806320 */  cvt.s.w   $f12, $f12
/* 60A7C4 80219D14 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A7C8 80219D18 00000000 */  nop
/* 60A7CC 80219D1C 46000021 */  cvt.d.s   $f0, $f0
/* 60A7D0 80219D20 4620A500 */  add.d     $f20, $f20, $f0
/* 60A7D4 80219D24 46186303 */  div.s     $f12, $f12, $f24
/* 60A7D8 80219D28 4620A520 */  cvt.s.d   $f20, $f20
/* 60A7DC 80219D2C 0C00A85B */  jal       sin_rad
/* 60A7E0 80219D30 E7B40010 */   swc1     $f20, 0x10($sp)
/* 60A7E4 80219D34 C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 60A7E8 80219D38 46806320 */  cvt.s.w   $f12, $f12
/* 60A7EC 80219D3C 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A7F0 80219D40 00000000 */  nop
/* 60A7F4 80219D44 3C0142B4 */  lui       $at, 0x42b4
/* 60A7F8 80219D48 44811000 */  mtc1      $at, $f2
/* 60A7FC 80219D4C 00000000 */  nop
/* 60A800 80219D50 46020002 */  mul.s     $f0, $f0, $f2
/* 60A804 80219D54 00000000 */  nop
/* 60A808 80219D58 C7A40014 */  lwc1      $f4, 0x14($sp)
/* 60A80C 80219D5C 46002100 */  add.s     $f4, $f4, $f0
/* 60A810 80219D60 46186303 */  div.s     $f12, $f12, $f24
/* 60A814 80219D64 0C00A85B */  jal       sin_rad
/* 60A818 80219D68 E7A40014 */   swc1     $f4, 0x14($sp)
/* 60A81C 80219D6C C60C00A8 */  lwc1      $f12, 0xa8($s0)
/* 60A820 80219D70 46806320 */  cvt.s.w   $f12, $f12
/* 60A824 80219D74 461A6302 */  mul.s     $f12, $f12, $f26
/* 60A828 80219D78 00000000 */  nop
/* 60A82C 80219D7C 46000021 */  cvt.d.s   $f0, $f0
/* 60A830 80219D80 4620B581 */  sub.d     $f22, $f22, $f0
/* 60A834 80219D84 4600F521 */  cvt.d.s   $f20, $f30
/* 60A838 80219D88 4636A502 */  mul.d     $f20, $f20, $f22
/* 60A83C 80219D8C 00000000 */  nop
/* 60A840 80219D90 0C00A85B */  jal       sin_rad
/* 60A844 80219D94 46186303 */   div.s    $f12, $f12, $f24
/* 60A848 80219D98 C7A40018 */  lwc1      $f4, 0x18($sp)
/* 60A84C 80219D9C 46002002 */  mul.s     $f0, $f4, $f0
/* 60A850 80219DA0 00000000 */  nop
/* 60A854 80219DA4 46000021 */  cvt.d.s   $f0, $f0
/* 60A858 80219DA8 4620A500 */  add.d     $f20, $f20, $f0
/* 60A85C 80219DAC 2402005A */  addiu     $v0, $zero, 0x5a
.L80219DB0:
/* 60A860 80219DB0 8E0300A8 */  lw        $v1, 0xa8($s0)
/* 60A864 80219DB4 14620002 */  bne       $v1, $v0, .L80219DC0
/* 60A868 80219DB8 4620A7A0 */   cvt.s.d  $f30, $f20
/* 60A86C 80219DBC AE1100B0 */  sw        $s1, 0xb0($s0)
.L80219DC0:
/* 60A870 80219DC0 C7A40010 */  lwc1      $f4, 0x10($sp)
/* 60A874 80219DC4 4600210D */  trunc.w.s $f4, $f4
/* 60A878 80219DC8 E6040084 */  swc1      $f4, 0x84($s0)
/* 60A87C 80219DCC C7A40014 */  lwc1      $f4, 0x14($sp)
/* 60A880 80219DD0 4600210D */  trunc.w.s $f4, $f4
/* 60A884 80219DD4 E6040088 */  swc1      $f4, 0x88($s0)
/* 60A888 80219DD8 4600F10D */  trunc.w.s $f4, $f30
/* 60A88C 80219DDC E604008C */  swc1      $f4, 0x8c($s0)
/* 60A890 80219DE0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 60A894 80219DE4 8FB10024 */  lw        $s1, 0x24($sp)
/* 60A898 80219DE8 8FB00020 */  lw        $s0, 0x20($sp)
/* 60A89C 80219DEC D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 60A8A0 80219DF0 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 60A8A4 80219DF4 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 60A8A8 80219DF8 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 60A8AC 80219DFC D7B60038 */  ldc1      $f22, 0x38($sp)
/* 60A8B0 80219E00 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 60A8B4 80219E04 24020002 */  addiu     $v0, $zero, 2
/* 60A8B8 80219E08 03E00008 */  jr        $ra
/* 60A8BC 80219E0C 27BD0060 */   addiu    $sp, $sp, 0x60
