.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800331F8
/* E5F8 800331F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E5FC 800331FC AFB00010 */  sw        $s0, 0x10($sp)
/* E600 80033200 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* E604 80033204 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* E608 80033208 AFBF0014 */  sw        $ra, 0x14($sp)
/* E60C 8003320C 8E040000 */  lw        $a0, ($s0)
/* E610 80033210 808200AC */  lb        $v0, 0xac($a0)
/* E614 80033214 908300AC */  lbu       $v1, 0xac($a0)
/* E618 80033218 10400003 */  beqz      $v0, .L80033228
/* E61C 8003321C 2462FFFF */   addiu    $v0, $v1, -1
/* E620 80033220 0800CD02 */  j         .L80033408
/* E624 80033224 A08200AC */   sb       $v0, 0xac($a0)
.L80033228:
/* E628 80033228 3C01800A */  lui       $at, %hi(D_8009A630)
/* E62C 8003322C AC20A630 */  sw        $zero, %lo(D_8009A630)($at)
/* E630 80033230 A4800086 */  sh        $zero, 0x86($a0)
/* E634 80033234 A0800070 */  sb        $zero, 0x70($a0)
/* E638 80033238 8E020000 */  lw        $v0, ($s0)
/* E63C 8003323C 2403FFFF */  addiu     $v1, $zero, -1
/* E640 80033240 A4830088 */  sh        $v1, 0x88($a0)
/* E644 80033244 A480008C */  sh        $zero, 0x8c($a0)
/* E648 80033248 A480008E */  sh        $zero, 0x8e($a0)
/* E64C 8003324C A0400076 */  sb        $zero, 0x76($v0)
/* E650 80033250 8E020000 */  lw        $v0, ($s0)
/* E654 80033254 A0400078 */  sb        $zero, 0x78($v0)
/* E658 80033258 8E020000 */  lw        $v0, ($s0)
/* E65C 8003325C A040007D */  sb        $zero, 0x7d($v0)
/* E660 80033260 8E020000 */  lw        $v0, ($s0)
/* E664 80033264 A04300A8 */  sb        $v1, 0xa8($v0)
/* E668 80033268 8E020000 */  lw        $v0, ($s0)
/* E66C 8003326C A04000AA */  sb        $zero, 0xaa($v0)
/* E670 80033270 8E020000 */  lw        $v0, ($s0)
/* E674 80033274 A04300A9 */  sb        $v1, 0xa9($v0)
/* E678 80033278 8E020000 */  lw        $v0, ($s0)
/* E67C 8003327C 0C00AAF0 */  jal       func_8002ABC0
/* E680 80033280 A0400071 */   sb       $zero, 0x71($v0)
/* E684 80033284 0C048AA8 */  jal       func_80122AA0
/* E688 80033288 00000000 */   nop
/* E68C 8003328C 0C04A0B2 */  jal       func_801282C8
/* E690 80033290 00000000 */   nop
/* E694 80033294 0C0B0C77 */  jal       func_802C31DC
/* E698 80033298 00000000 */   nop
/* E69C 8003329C 0C00B6E1 */  jal       func_8002DB84
/* E6A0 800332A0 00000000 */   nop
/* E6A4 800332A4 0C044512 */  jal       func_80111448
/* E6A8 800332A8 0000202D */   daddu    $a0, $zero, $zero
/* E6AC 800332AC 0C049770 */  jal       func_80125DC0
/* E6B0 800332B0 00000000 */   nop
/* E6B4 800332B4 0C048D0D */  jal       func_80123434
/* E6B8 800332B8 00000000 */   nop
/* E6BC 800332BC 0C046BD5 */  jal       func_8011AF54
/* E6C0 800332C0 00000000 */   nop
/* E6C4 800332C4 0C05343C */  jal       func_8014D0F0
/* E6C8 800332C8 00000000 */   nop
/* E6CC 800332CC 0C052BAA */  jal       func_8014AEA8
/* E6D0 800332D0 00000000 */   nop
/* E6D4 800332D4 0000202D */  daddu     $a0, $zero, $zero
/* E6D8 800332D8 0C0528E6 */  jal       func_8014A398
/* E6DC 800332DC 0080282D */   daddu    $a1, $a0, $zero
/* E6E0 800332E0 0C05186C */  jal       func_801461B0
/* E6E4 800332E4 00000000 */   nop
/* E6E8 800332E8 0C0529CC */  jal       func_8014A730
/* E6EC 800332EC 00000000 */   nop
/* E6F0 800332F0 0C04A221 */  jal       func_80128884
/* E6F4 800332F4 00000000 */   nop
/* E6F8 800332F8 0C0457B2 */  jal       func_80115EC8
/* E6FC 800332FC 0000202D */   daddu    $a0, $zero, $zero
/* E700 80033300 0C04F46E */  jal       func_8013D1B8
/* E704 80033304 00000000 */   nop
/* E708 80033308 0C037F0C */  jal       func_800DFC30
/* E70C 8003330C 00000000 */   nop
/* E710 80033310 0C00E05F */  jal       func_8003817C
/* E714 80033314 00000000 */   nop
/* E718 80033318 0C039CD0 */  jal       func_800E7340
/* E71C 8003331C 00000000 */   nop
/* E720 80033320 0C01CAC4 */  jal       func_80072B10
/* E724 80033324 00000000 */   nop
/* E728 80033328 0C00F7FE */  jal       func_8003DFF8
/* E72C 8003332C 00000000 */   nop
/* E730 80033330 0C016653 */  jal       func_8005994C
/* E734 80033334 00000000 */   nop
/* E738 80033338 0C04D85C */  jal       func_80136170
/* E73C 8003333C 00000000 */   nop
/* E740 80033340 0C0528F4 */  jal       func_8014A3D0
/* E744 80033344 00000000 */   nop
/* E748 80033348 0C016B11 */  jal       func_8005AC44
/* E74C 8003334C 00000000 */   nop
/* E750 80033350 0C053F2E */  jal       func_8014FCB8
/* E754 80033354 00000000 */   nop
/* E758 80033358 0C053128 */  jal       func_8014C4A0
/* E75C 8003335C 00000000 */   nop
/* E760 80033360 0C03AD45 */  jal       func_800EB514
/* E764 80033364 00000000 */   nop
/* E768 80033368 0C0539B2 */  jal       func_8014E6C8
/* E76C 8003336C 00000000 */   nop
/* E770 80033370 0C053D77 */  jal       func_8014F5DC
/* E774 80033374 00000000 */   nop
/* E778 80033378 0C00AE80 */  jal       func_8002BA00
/* E77C 8003337C 00000000 */   nop
/* E780 80033380 0000202D */  daddu     $a0, $zero, $zero
/* E784 80033384 24060004 */  addiu     $a2, $zero, 4
/* E788 80033388 2405000F */  addiu     $a1, $zero, 0xf
/* E78C 8003338C 8E030000 */  lw        $v1, ($s0)
.L80033390:
/* E790 80033390 A4660050 */  sh        $a2, 0x50($v1)
/* E794 80033394 A4650048 */  sh        $a1, 0x48($v1)
/* E798 80033398 24840001 */  addiu     $a0, $a0, 1
/* E79C 8003339C 28820004 */  slti      $v0, $a0, 4
/* E7A0 800333A0 1440FFFB */  bnez      $v0, .L80033390
/* E7A4 800333A4 24630002 */   addiu    $v1, $v1, 2
/* E7A8 800333A8 0C00ABE6 */  jal       func_8002AF98
/* E7AC 800333AC 00000000 */   nop
/* E7B0 800333B0 3C02800E */  lui       $v0, %hi(D_800D9600)
/* E7B4 800333B4 8C429600 */  lw        $v0, %lo(D_800D9600)($v0)
/* E7B8 800333B8 14400007 */  bnez      $v0, .L800333D8
/* E7BC 800333BC 24020001 */   addiu    $v0, $zero, 1
/* E7C0 800333C0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E7C4 800333C4 8C63417C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E7C8 800333C8 0C015783 */  jal       func_80055E0C
/* E7CC 800333CC A06200AB */   sb       $v0, 0xab($v1)
/* E7D0 800333D0 0800CCFB */  j         .L800333EC
/* E7D4 800333D4 24040001 */   addiu    $a0, $zero, 1
.L800333D8:
/* E7D8 800333D8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E7DC 800333DC 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E7E0 800333E0 0C01578C */  jal       func_80055E30
/* E7E4 800333E4 A04000AB */   sb       $zero, 0xab($v0)
/* E7E8 800333E8 24040001 */  addiu     $a0, $zero, 1
.L800333EC:
/* E7EC 800333EC 3C02800A */  lui       $v0, %hi(D_8009A630)
/* E7F0 800333F0 2442A630 */  addiu     $v0, $v0, %lo(D_8009A630)
/* E7F4 800333F4 8C430000 */  lw        $v1, ($v0)
/* E7F8 800333F8 2405FFF7 */  addiu     $a1, $zero, -9
/* E7FC 800333FC 00651824 */  and       $v1, $v1, $a1
/* E800 80033400 0C00CC60 */  jal       func_80033180
/* E804 80033404 AC430000 */   sw       $v1, ($v0)
.L80033408:
/* E808 80033408 8FBF0014 */  lw        $ra, 0x14($sp)
/* E80C 8003340C 8FB00010 */  lw        $s0, 0x10($sp)
/* E810 80033410 03E00008 */  jr        $ra
/* E814 80033414 27BD0018 */   addiu    $sp, $sp, 0x18
