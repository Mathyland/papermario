.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80150A80
.word .L801313BC_C7ABC, .L801311B8_C78B8, .L80131188_C7888, .L80131188_C7888, .L801311B0_C78B0, 0

.section .text

glabel item_entity_load
/* C7828 80131128 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C782C 8013112C AFBE0030 */  sw        $fp, 0x30($sp)
/* C7830 80131130 0080F02D */  daddu     $fp, $a0, $zero
/* C7834 80131134 AFB7002C */  sw        $s7, 0x2c($sp)
/* C7838 80131138 2417FFFF */  addiu     $s7, $zero, -1
/* C783C 8013113C AFB50024 */  sw        $s5, 0x24($sp)
/* C7840 80131140 3C150001 */  lui       $s5, 1
/* C7844 80131144 AFBF0034 */  sw        $ra, 0x34($sp)
/* C7848 80131148 AFB60028 */  sw        $s6, 0x28($sp)
/* C784C 8013114C AFB40020 */  sw        $s4, 0x20($sp)
/* C7850 80131150 AFB3001C */  sw        $s3, 0x1c($sp)
/* C7854 80131154 AFB20018 */  sw        $s2, 0x18($sp)
/* C7858 80131158 AFB10014 */  sw        $s1, 0x14($sp)
/* C785C 8013115C AFB00010 */  sw        $s0, 0x10($sp)
/* C7860 80131160 87C20018 */  lh        $v0, 0x18($fp)
/* C7864 80131164 36B50FFF */  ori       $s5, $s5, 0xfff
/* C7868 80131168 00021080 */  sll       $v0, $v0, 2
/* C786C 8013116C 3C108009 */  lui       $s0, %hi(gItemEntityScripts)
/* C7870 80131170 02028021 */  addu      $s0, $s0, $v0
/* C7874 80131174 8E10DDD4 */  lw        $s0, %lo(gItemEntityScripts)($s0)
/* C7878 80131178 3C16001D */  lui       $s6, 0x1d
/* C787C 8013117C 26D6C310 */  addiu     $s6, $s6, -0x3cf0
/* C7880 80131180 AFD00024 */  sw        $s0, 0x24($fp)
/* C7884 80131184 AFD00028 */  sw        $s0, 0x28($fp)
.L80131188_C7888:
/* C7888 80131188 8E030000 */  lw        $v1, ($s0)
/* C788C 8013118C 2C620005 */  sltiu     $v0, $v1, 5
/* C7890 80131190 1040FFFD */  beqz      $v0, .L80131188_C7888
/* C7894 80131194 26100004 */   addiu    $s0, $s0, 4
/* C7898 80131198 00031080 */  sll       $v0, $v1, 2
/* C789C 8013119C 3C018015 */  lui       $at, %hi(jtbl_80150A80)
/* C78A0 801311A0 00220821 */  addu      $at, $at, $v0
/* C78A4 801311A4 8C220A80 */  lw        $v0, %lo(jtbl_80150A80)($at)
/* C78A8 801311A8 00400008 */  jr        $v0
/* C78AC 801311AC 00000000 */   nop
.L801311B0_C78B0:
/* C78B0 801311B0 0804C462 */  j         .L80131188_C7888
/* C78B4 801311B4 26100008 */   addiu    $s0, $s0, 8
.L801311B8_C78B8:
/* C78B8 801311B8 26100004 */  addiu     $s0, $s0, 4
/* C78BC 801311BC 8E060000 */  lw        $a2, ($s0)
/* C78C0 801311C0 26100004 */  addiu     $s0, $s0, 4
/* C78C4 801311C4 8E140000 */  lw        $s4, ($s0)
/* C78C8 801311C8 26100004 */  addiu     $s0, $s0, 4
/* C78CC 801311CC 8FC20000 */  lw        $v0, ($fp)
/* C78D0 801311D0 3C030004 */  lui       $v1, 4
/* C78D4 801311D4 00431024 */  and       $v0, $v0, $v1
/* C78D8 801311D8 10400002 */  beqz      $v0, .L801311E4
/* C78DC 801311DC 24120120 */   addiu    $s2, $zero, 0x120
/* C78E0 801311E0 24120200 */  addiu     $s2, $zero, 0x200
.L801311E4:
/* C78E4 801311E4 3C038015 */  lui       $v1, %hi(gHudElementCacheTableRaster)
/* C78E8 801311E8 8C6312C8 */  lw        $v1, %lo(gHudElementCacheTableRaster)($v1)
/* C78EC 801311EC 0000882D */  daddu     $s1, $zero, $zero
/* C78F0 801311F0 0220982D */  daddu     $s3, $s1, $zero
/* C78F4 801311F4 24650004 */  addiu     $a1, $v1, 4
.L801311F8:
/* C78F8 801311F8 8C620000 */  lw        $v0, ($v1)
/* C78FC 801311FC 1457001F */  bne       $v0, $s7, .L8013127C
/* C7900 80131200 00000000 */   nop
/* C7904 80131204 3C048015 */  lui       $a0, %hi(gHudElementCacheSize)
/* C7908 80131208 8C84133C */  lw        $a0, %lo(gHudElementCacheSize)($a0)
/* C790C 8013120C 3C028015 */  lui       $v0, %hi(gHudElementCacheBuffer)
/* C7910 80131210 8C421314 */  lw        $v0, %lo(gHudElementCacheBuffer)($v0)
/* C7914 80131214 AC660000 */  sw        $a2, ($v1)
/* C7918 80131218 8C830000 */  lw        $v1, ($a0)
/* C791C 8013121C 00431021 */  addu      $v0, $v0, $v1
/* C7920 80131220 ACA20000 */  sw        $v0, ($a1)
/* C7924 80131224 8C820000 */  lw        $v0, ($a0)
/* C7928 80131228 00521021 */  addu      $v0, $v0, $s2
/* C792C 8013122C 02A2102A */  slt       $v0, $s5, $v0
/* C7930 80131230 10400003 */  beqz      $v0, .L80131240
/* C7934 80131234 00D62021 */   addu     $a0, $a2, $s6
.L80131238:
/* C7938 80131238 0804C48E */  j         .L80131238
/* C793C 8013123C 00000000 */   nop
.L80131240:
/* C7940 80131240 8CA50000 */  lw        $a1, ($a1)
/* C7944 80131244 0C017D24 */  jal       nuPiReadRom
/* C7948 80131248 0240302D */   daddu    $a2, $s2, $zero
/* C794C 8013124C 3C038015 */  lui       $v1, %hi(gHudElementCacheSize)
/* C7950 80131250 8C63133C */  lw        $v1, %lo(gHudElementCacheSize)($v1)
/* C7954 80131254 8C620000 */  lw        $v0, ($v1)
/* C7958 80131258 00521021 */  addu      $v0, $v0, $s2
/* C795C 8013125C AC620000 */  sw        $v0, ($v1)
/* C7960 80131260 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C7964 80131264 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C7968 80131268 80420070 */  lb        $v0, 0x70($v0)
/* C796C 8013126C 5040000F */  beql      $v0, $zero, .L801312AC
/* C7970 80131270 AE110000 */   sw       $s1, ($s0)
/* C7974 80131274 0804C4A8 */  j         .L801312A0
/* C7978 80131278 00000000 */   nop
.L8013127C:
/* C797C 8013127C 5446000D */  bnel      $v0, $a2, .L801312B4
/* C7980 80131280 24A50008 */   addiu    $a1, $a1, 8
/* C7984 80131284 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C7988 80131288 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C798C 8013128C 80420070 */  lb        $v0, 0x70($v0)
/* C7990 80131290 14400003 */  bnez      $v0, .L801312A0
/* C7994 80131294 00000000 */   nop
/* C7998 80131298 0804C4AB */  j         .L801312AC
/* C799C 8013129C AE110000 */   sw       $s1, ($s0)
.L801312A0:
/* C79A0 801312A0 96020002 */  lhu       $v0, 2($s0)
/* C79A4 801312A4 00531025 */  or        $v0, $v0, $s3
/* C79A8 801312A8 AE020000 */  sw        $v0, ($s0)
.L801312AC:
/* C79AC 801312AC 0804C4B2 */  j         .L801312C8
/* C79B0 801312B0 26100004 */   addiu    $s0, $s0, 4
.L801312B4:
/* C79B4 801312B4 24630008 */  addiu     $v1, $v1, 8
/* C79B8 801312B8 3C020001 */  lui       $v0, 1
/* C79BC 801312BC 02629821 */  addu      $s3, $s3, $v0
/* C79C0 801312C0 0804C47E */  j         .L801311F8
/* C79C4 801312C4 26310001 */   addiu    $s1, $s1, 1
.L801312C8:
/* C79C8 801312C8 2A220100 */  slti      $v0, $s1, 0x100
/* C79CC 801312CC 14400003 */  bnez      $v0, .L801312DC
/* C79D0 801312D0 0000882D */   daddu    $s1, $zero, $zero
.L801312D4:
/* C79D4 801312D4 0804C4B5 */  j         .L801312D4
/* C79D8 801312D8 00000000 */   nop
.L801312DC:
/* C79DC 801312DC 3C038015 */  lui       $v1, %hi(gHudElementCacheTablePalette)
/* C79E0 801312E0 8C6312D0 */  lw        $v1, %lo(gHudElementCacheTablePalette)($v1)
/* C79E4 801312E4 0220902D */  daddu     $s2, $s1, $zero
/* C79E8 801312E8 24650004 */  addiu     $a1, $v1, 4
.L801312EC:
/* C79EC 801312EC 8C620000 */  lw        $v0, ($v1)
/* C79F0 801312F0 1457001F */  bne       $v0, $s7, .L80131370
/* C79F4 801312F4 00000000 */   nop
/* C79F8 801312F8 3C048015 */  lui       $a0, %hi(gHudElementCacheSize)
/* C79FC 801312FC 8C84133C */  lw        $a0, %lo(gHudElementCacheSize)($a0)
/* C7A00 80131300 3C028015 */  lui       $v0, %hi(gHudElementCacheBuffer)
/* C7A04 80131304 8C421314 */  lw        $v0, %lo(gHudElementCacheBuffer)($v0)
/* C7A08 80131308 AC740000 */  sw        $s4, ($v1)
/* C7A0C 8013130C 8C830000 */  lw        $v1, ($a0)
/* C7A10 80131310 00431021 */  addu      $v0, $v0, $v1
/* C7A14 80131314 ACA20000 */  sw        $v0, ($a1)
/* C7A18 80131318 8C820000 */  lw        $v0, ($a0)
/* C7A1C 8013131C 24420020 */  addiu     $v0, $v0, 0x20
/* C7A20 80131320 02A2102A */  slt       $v0, $s5, $v0
/* C7A24 80131324 10400003 */  beqz      $v0, .L80131334
/* C7A28 80131328 02962021 */   addu     $a0, $s4, $s6
.L8013132C:
/* C7A2C 8013132C 0804C4CB */  j         .L8013132C
/* C7A30 80131330 00000000 */   nop
.L80131334:
/* C7A34 80131334 8CA50000 */  lw        $a1, ($a1)
/* C7A38 80131338 0C017D24 */  jal       nuPiReadRom
/* C7A3C 8013133C 24060020 */   addiu    $a2, $zero, 0x20
/* C7A40 80131340 3C038015 */  lui       $v1, %hi(gHudElementCacheSize)
/* C7A44 80131344 8C63133C */  lw        $v1, %lo(gHudElementCacheSize)($v1)
/* C7A48 80131348 8C620000 */  lw        $v0, ($v1)
/* C7A4C 8013134C 24420020 */  addiu     $v0, $v0, 0x20
/* C7A50 80131350 AC620000 */  sw        $v0, ($v1)
/* C7A54 80131354 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C7A58 80131358 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C7A5C 8013135C 80420070 */  lb        $v0, 0x70($v0)
/* C7A60 80131360 5040000F */  beql      $v0, $zero, .L801313A0
/* C7A64 80131364 AE110000 */   sw       $s1, ($s0)
/* C7A68 80131368 0804C4E5 */  j         .L80131394
/* C7A6C 8013136C 00000000 */   nop
.L80131370:
/* C7A70 80131370 5454000D */  bnel      $v0, $s4, .L801313A8
/* C7A74 80131374 24A50008 */   addiu    $a1, $a1, 8
/* C7A78 80131378 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C7A7C 8013137C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C7A80 80131380 80420070 */  lb        $v0, 0x70($v0)
/* C7A84 80131384 14400003 */  bnez      $v0, .L80131394
/* C7A88 80131388 00000000 */   nop
/* C7A8C 8013138C 0804C4E8 */  j         .L801313A0
/* C7A90 80131390 AE110000 */   sw       $s1, ($s0)
.L80131394:
/* C7A94 80131394 96020002 */  lhu       $v0, 2($s0)
/* C7A98 80131398 00521025 */  or        $v0, $v0, $s2
/* C7A9C 8013139C AE020000 */  sw        $v0, ($s0)
.L801313A0:
/* C7AA0 801313A0 0804C462 */  j         .L80131188_C7888
/* C7AA4 801313A4 26100004 */   addiu    $s0, $s0, 4
.L801313A8:
/* C7AA8 801313A8 24630008 */  addiu     $v1, $v1, 8
/* C7AAC 801313AC 3C020001 */  lui       $v0, 1
/* C7AB0 801313B0 02429021 */  addu      $s2, $s2, $v0
/* C7AB4 801313B4 0804C4BB */  j         .L801312EC
/* C7AB8 801313B8 26310001 */   addiu    $s1, $s1, 1
.L801313BC_C7ABC:
/* C7ABC 801313BC 0C04C775 */  jal       item_entity_update
/* C7AC0 801313C0 03C0202D */   daddu    $a0, $fp, $zero
/* C7AC4 801313C4 8FBF0034 */  lw        $ra, 0x34($sp)
/* C7AC8 801313C8 8FBE0030 */  lw        $fp, 0x30($sp)
/* C7ACC 801313CC 8FB7002C */  lw        $s7, 0x2c($sp)
/* C7AD0 801313D0 8FB60028 */  lw        $s6, 0x28($sp)
/* C7AD4 801313D4 8FB50024 */  lw        $s5, 0x24($sp)
/* C7AD8 801313D8 8FB40020 */  lw        $s4, 0x20($sp)
/* C7ADC 801313DC 8FB3001C */  lw        $s3, 0x1c($sp)
/* C7AE0 801313E0 8FB20018 */  lw        $s2, 0x18($sp)
/* C7AE4 801313E4 8FB10014 */  lw        $s1, 0x14($sp)
/* C7AE8 801313E8 8FB00010 */  lw        $s0, 0x10($sp)
/* C7AEC 801313EC 03E00008 */  jr        $ra
/* C7AF0 801313F0 27BD0038 */   addiu    $sp, $sp, 0x38
