.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flame_update
/* 353450 E0040150 8C820008 */  lw        $v0, 8($a0)
/* 353454 E0040154 8C83000C */  lw        $v1, 0xc($a0)
/* 353458 E0040158 1840002B */  blez      $v0, .LE0040208
/* 35345C E004015C 0000282D */   daddu    $a1, $zero, $zero
/* 353460 E0040160 24630024 */  addiu     $v1, $v1, 0x24
/* 353464 E0040164 3C014280 */  lui       $at, 0x4280
/* 353468 E0040168 44813000 */  mtc1      $at, $f6
/* 35346C E004016C 44804000 */  mtc1      $zero, $f8
/* 353470 E0040170 3C014300 */  lui       $at, 0x4300
/* 353474 E0040174 44812000 */  mtc1      $at, $f4
.LE0040178:
/* 353478 E0040178 C462FFF8 */  lwc1      $f2, -8($v1)
/* 35347C E004017C C460FFFC */  lwc1      $f0, -4($v1)
/* 353480 E0040180 46001000 */  add.s     $f0, $f2, $f0
/* 353484 E0040184 4600303C */  c.lt.s    $f6, $f0
/* 353488 E0040188 00000000 */  nop
/* 35348C E004018C 45000003 */  bc1f      .LE004019C
/* 353490 E0040190 E460FFF8 */   swc1     $f0, -8($v1)
/* 353494 E0040194 46060001 */  sub.s     $f0, $f0, $f6
/* 353498 E0040198 E460FFF8 */  swc1      $f0, -8($v1)
.LE004019C:
/* 35349C E004019C C460FFF8 */  lwc1      $f0, -8($v1)
/* 3534A0 E00401A0 4608003C */  c.lt.s    $f0, $f8
/* 3534A4 E00401A4 00000000 */  nop
/* 3534A8 E00401A8 45000003 */  bc1f      .LE00401B8
/* 3534AC E00401AC 00000000 */   nop
/* 3534B0 E00401B0 46060000 */  add.s     $f0, $f0, $f6
/* 3534B4 E00401B4 E460FFF8 */  swc1      $f0, -8($v1)
.LE00401B8:
/* 3534B8 E00401B8 C4620000 */  lwc1      $f2, ($v1)
/* 3534BC E00401BC C4600004 */  lwc1      $f0, 4($v1)
/* 3534C0 E00401C0 46001000 */  add.s     $f0, $f2, $f0
/* 3534C4 E00401C4 4600203C */  c.lt.s    $f4, $f0
/* 3534C8 E00401C8 00000000 */  nop
/* 3534CC E00401CC 45000003 */  bc1f      .LE00401DC
/* 3534D0 E00401D0 E4600000 */   swc1     $f0, ($v1)
/* 3534D4 E00401D4 46040001 */  sub.s     $f0, $f0, $f4
/* 3534D8 E00401D8 E4600000 */  swc1      $f0, ($v1)
.LE00401DC:
/* 3534DC E00401DC C4600000 */  lwc1      $f0, ($v1)
/* 3534E0 E00401E0 4608003C */  c.lt.s    $f0, $f8
/* 3534E4 E00401E4 00000000 */  nop
/* 3534E8 E00401E8 45000003 */  bc1f      .LE00401F8
/* 3534EC E00401EC 24A50001 */   addiu    $a1, $a1, 1
/* 3534F0 E00401F0 46040000 */  add.s     $f0, $f0, $f4
/* 3534F4 E00401F4 E4600000 */  swc1      $f0, ($v1)
.LE00401F8:
/* 3534F8 E00401F8 8C820008 */  lw        $v0, 8($a0)
/* 3534FC E00401FC 00A2102A */  slt       $v0, $a1, $v0
/* 353500 E0040200 1440FFDD */  bnez      $v0, .LE0040178
/* 353504 E0040204 24630034 */   addiu    $v1, $v1, 0x34
.LE0040208:
/* 353508 E0040208 03E00008 */  jr        $ra
/* 35350C E004020C 00000000 */   nop
