.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spiky_white_aura_update
/* 34E144 E0038424 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 34E148 E0038428 AFB40020 */  sw        $s4, 0x20($sp)
/* 34E14C E003842C 0080A02D */  daddu     $s4, $a0, $zero
/* 34E150 E0038430 AFBF0028 */  sw        $ra, 0x28($sp)
/* 34E154 E0038434 AFB50024 */  sw        $s5, 0x24($sp)
/* 34E158 E0038438 AFB3001C */  sw        $s3, 0x1c($sp)
/* 34E15C E003843C AFB20018 */  sw        $s2, 0x18($sp)
/* 34E160 E0038440 AFB10014 */  sw        $s1, 0x14($sp)
/* 34E164 E0038444 AFB00010 */  sw        $s0, 0x10($sp)
/* 34E168 E0038448 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 34E16C E003844C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 34E170 E0038450 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 34E174 E0038454 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 34E178 E0038458 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 34E17C E003845C 8E83000C */  lw        $v1, 0xc($s4)
/* 34E180 E0038460 8C620028 */  lw        $v0, 0x28($v1)
/* 34E184 E0038464 2442FFFF */  addiu     $v0, $v0, -1
/* 34E188 E0038468 AC620028 */  sw        $v0, 0x28($v1)
/* 34E18C E003846C 8C62002C */  lw        $v0, 0x2c($v1)
/* 34E190 E0038470 8C640028 */  lw        $a0, 0x28($v1)
/* 34E194 E0038474 24450001 */  addiu     $a1, $v0, 1
/* 34E198 E0038478 04810005 */  bgez      $a0, .LE0038490
/* 34E19C E003847C AC65002C */   sw       $a1, 0x2c($v1)
/* 34E1A0 E0038480 0C080128 */  jal       shim_remove_effect
/* 34E1A4 E0038484 0280202D */   daddu    $a0, $s4, $zero
/* 34E1A8 E0038488 0800E1B3 */  j         .LE00386CC
/* 34E1AC E003848C 00000000 */   nop
.LE0038490:
/* 34E1B0 E0038490 0000882D */  daddu     $s1, $zero, $zero
/* 34E1B4 E0038494 0080982D */  daddu     $s3, $a0, $zero
/* 34E1B8 E0038498 8E820008 */  lw        $v0, 8($s4)
/* 34E1BC E003849C 1840008B */  blez      $v0, .LE00386CC
/* 34E1C0 E00384A0 00A0902D */   daddu    $s2, $a1, $zero
/* 34E1C4 E00384A4 241500FF */  addiu     $s5, $zero, 0xff
/* 34E1C8 E00384A8 2470000C */  addiu     $s0, $v1, 0xc
/* 34E1CC E00384AC 3C01E004 */  lui       $at, %hi(D_E0038A28)
/* 34E1D0 E00384B0 D4388A28 */  ldc1      $f24, %lo(D_E0038A28)($at)
/* 34E1D4 E00384B4 3C0141F0 */  lui       $at, 0x41f0
/* 34E1D8 E00384B8 4481D000 */  mtc1      $at, $f26
/* 34E1DC E00384BC 3C014040 */  lui       $at, 0x4040
/* 34E1E0 E00384C0 4481E000 */  mtc1      $at, $f28
/* 34E1E4 E00384C4 3C01E004 */  lui       $at, %hi(D_E0038A30)
/* 34E1E8 E00384C8 D4368A30 */  ldc1      $f22, %lo(D_E0038A30)($at)
.LE00384CC:
/* 34E1EC E00384CC 2A620006 */  slti      $v0, $s3, 6
/* 34E1F0 E00384D0 14400037 */  bnez      $v0, .LE00385B0
/* 34E1F4 E00384D4 2A620005 */   slti     $v0, $s3, 5
/* 34E1F8 E00384D8 C6020004 */  lwc1      $f2, 4($s0)
/* 34E1FC E00384DC 460010A1 */  cvt.d.s   $f2, $f2
/* 34E200 E00384E0 46381082 */  mul.d     $f2, $f2, $f24
/* 34E204 E00384E4 00000000 */  nop
/* 34E208 E00384E8 C6000008 */  lwc1      $f0, 8($s0)
/* 34E20C E00384EC 46000021 */  cvt.d.s   $f0, $f0
/* 34E210 E00384F0 46380002 */  mul.d     $f0, $f0, $f24
/* 34E214 E00384F4 00000000 */  nop
/* 34E218 E00384F8 C604000C */  lwc1      $f4, 0xc($s0)
/* 34E21C E00384FC 46002121 */  cvt.d.s   $f4, $f4
/* 34E220 E0038500 46382102 */  mul.d     $f4, $f4, $f24
/* 34E224 E0038504 00000000 */  nop
/* 34E228 E0038508 8E030018 */  lw        $v1, 0x18($s0)
/* 34E22C E003850C 3C01E004 */  lui       $at, %hi(D_E0038A38)
/* 34E230 E0038510 D4268A38 */  ldc1      $f6, %lo(D_E0038A38)($at)
/* 34E234 E0038514 02A31023 */  subu      $v0, $s5, $v1
/* 34E238 E0038518 44824000 */  mtc1      $v0, $f8
/* 34E23C E003851C 00000000 */  nop
/* 34E240 E0038520 46804221 */  cvt.d.w   $f8, $f8
/* 34E244 E0038524 46264202 */  mul.d     $f8, $f8, $f6
/* 34E248 E0038528 00000000 */  nop
/* 34E24C E003852C 462010A0 */  cvt.s.d   $f2, $f2
/* 34E250 E0038530 46200020 */  cvt.s.d   $f0, $f0
/* 34E254 E0038534 E6000008 */  swc1      $f0, 8($s0)
/* 34E258 E0038538 44830000 */  mtc1      $v1, $f0
/* 34E25C E003853C 00000000 */  nop
/* 34E260 E0038540 46800021 */  cvt.d.w   $f0, $f0
/* 34E264 E0038544 46202120 */  cvt.s.d   $f4, $f4
/* 34E268 E0038548 46280000 */  add.d     $f0, $f0, $f8
/* 34E26C E003854C E6020004 */  swc1      $f2, 4($s0)
/* 34E270 E0038550 E604000C */  swc1      $f4, 0xc($s0)
/* 34E274 E0038554 4620028D */  trunc.w.d $f10, $f0
/* 34E278 E0038558 44035000 */  mfc1      $v1, $f10
/* 34E27C E003855C 00000000 */  nop
/* 34E280 E0038560 000317C2 */  srl       $v0, $v1, 0x1f
/* 34E284 E0038564 00621021 */  addu      $v0, $v1, $v0
/* 34E288 E0038568 00021043 */  sra       $v0, $v0, 1
/* 34E28C E003856C 44826000 */  mtc1      $v0, $f12
/* 34E290 E0038570 00000000 */  nop
/* 34E294 E0038574 46806320 */  cvt.s.w   $f12, $f12
/* 34E298 E0038578 0C080140 */  jal       shim_sin_deg
/* 34E29C E003857C AE030018 */   sw       $v1, 0x18($s0)
/* 34E2A0 E0038580 44926000 */  mtc1      $s2, $f12
/* 34E2A4 E0038584 00000000 */  nop
/* 34E2A8 E0038588 46806320 */  cvt.s.w   $f12, $f12
/* 34E2AC E003858C 461A6302 */  mul.s     $f12, $f12, $f26
/* 34E2B0 E0038590 00000000 */  nop
/* 34E2B4 E0038594 0C080140 */  jal       shim_sin_deg
/* 34E2B8 E0038598 46000506 */   mov.s    $f20, $f0
/* 34E2BC E003859C 461CA502 */  mul.s     $f20, $f20, $f28
/* 34E2C0 E00385A0 00000000 */  nop
/* 34E2C4 E00385A4 4600A500 */  add.s     $f20, $f20, $f0
/* 34E2C8 E00385A8 E6140014 */  swc1      $f20, 0x14($s0)
/* 34E2CC E00385AC 2A620005 */  slti      $v0, $s3, 5
.LE00385B0:
/* 34E2D0 E00385B0 10400035 */  beqz      $v0, .LE0038688
/* 34E2D4 E00385B4 00000000 */   nop
/* 34E2D8 E00385B8 3C01E004 */  lui       $at, %hi(D_E0038A40)
/* 34E2DC E00385BC D4208A40 */  ldc1      $f0, %lo(D_E0038A40)($at)
/* 34E2E0 E00385C0 C6060018 */  lwc1      $f6, 0x18($s0)
/* 34E2E4 E00385C4 468031A1 */  cvt.d.w   $f6, $f6
/* 34E2E8 E00385C8 46203182 */  mul.d     $f6, $f6, $f0
/* 34E2EC E00385CC 00000000 */  nop
/* 34E2F0 E00385D0 C6040004 */  lwc1      $f4, 4($s0)
/* 34E2F4 E00385D4 46002121 */  cvt.d.s   $f4, $f4
/* 34E2F8 E00385D8 46362102 */  mul.d     $f4, $f4, $f22
/* 34E2FC E00385DC 00000000 */  nop
/* 34E300 E00385E0 C602000C */  lwc1      $f2, 0xc($s0)
/* 34E304 E00385E4 460010A1 */  cvt.d.s   $f2, $f2
/* 34E308 E00385E8 46361082 */  mul.d     $f2, $f2, $f22
/* 34E30C E00385EC 00000000 */  nop
/* 34E310 E00385F0 C6000008 */  lwc1      $f0, 8($s0)
/* 34E314 E00385F4 46000021 */  cvt.d.s   $f0, $f0
/* 34E318 E00385F8 46360002 */  mul.d     $f0, $f0, $f22
/* 34E31C E00385FC 00000000 */  nop
/* 34E320 E0038600 4620328D */  trunc.w.d $f10, $f6
/* 34E324 E0038604 E60A0018 */  swc1      $f10, 0x18($s0)
/* 34E328 E0038608 46202120 */  cvt.s.d   $f4, $f4
/* 34E32C E003860C 8E030018 */  lw        $v1, 0x18($s0)
/* 34E330 E0038610 462010A0 */  cvt.s.d   $f2, $f2
/* 34E334 E0038614 E6040004 */  swc1      $f4, 4($s0)
/* 34E338 E0038618 E602000C */  swc1      $f2, 0xc($s0)
/* 34E33C E003861C 46200020 */  cvt.s.d   $f0, $f0
/* 34E340 E0038620 000317C2 */  srl       $v0, $v1, 0x1f
/* 34E344 E0038624 00621821 */  addu      $v1, $v1, $v0
/* 34E348 E0038628 00031843 */  sra       $v1, $v1, 1
/* 34E34C E003862C 44836000 */  mtc1      $v1, $f12
/* 34E350 E0038630 00000000 */  nop
/* 34E354 E0038634 46806320 */  cvt.s.w   $f12, $f12
/* 34E358 E0038638 0C080140 */  jal       shim_sin_deg
/* 34E35C E003863C E6000008 */   swc1     $f0, 8($s0)
/* 34E360 E0038640 44926000 */  mtc1      $s2, $f12
/* 34E364 E0038644 00000000 */  nop
/* 34E368 E0038648 46806320 */  cvt.s.w   $f12, $f12
/* 34E36C E003864C 461A6302 */  mul.s     $f12, $f12, $f26
/* 34E370 E0038650 00000000 */  nop
/* 34E374 E0038654 0C080140 */  jal       shim_sin_deg
/* 34E378 E0038658 46000506 */   mov.s    $f20, $f0
/* 34E37C E003865C 461CA502 */  mul.s     $f20, $f20, $f28
/* 34E380 E0038660 00000000 */  nop
/* 34E384 E0038664 8E020018 */  lw        $v0, 0x18($s0)
/* 34E388 E0038668 02A21023 */  subu      $v0, $s5, $v0
/* 34E38C E003866C 4600A500 */  add.s     $f20, $f20, $f0
/* 34E390 E0038670 44820000 */  mtc1      $v0, $f0
/* 34E394 E0038674 00000000 */  nop
/* 34E398 E0038678 46800020 */  cvt.s.w   $f0, $f0
/* 34E39C E003867C 461A0003 */  div.s     $f0, $f0, $f26
/* 34E3A0 E0038680 4600A500 */  add.s     $f20, $f20, $f0
/* 34E3A4 E0038684 E6140014 */  swc1      $f20, 0x14($s0)
.LE0038688:
/* 34E3A8 E0038688 C606FFF8 */  lwc1      $f6, -8($s0)
/* 34E3AC E003868C C6000004 */  lwc1      $f0, 4($s0)
/* 34E3B0 E0038690 C604FFFC */  lwc1      $f4, -4($s0)
/* 34E3B4 E0038694 46003180 */  add.s     $f6, $f6, $f0
/* 34E3B8 E0038698 C6000008 */  lwc1      $f0, 8($s0)
/* 34E3BC E003869C C602000C */  lwc1      $f2, 0xc($s0)
/* 34E3C0 E00386A0 46002100 */  add.s     $f4, $f4, $f0
/* 34E3C4 E00386A4 C6000000 */  lwc1      $f0, ($s0)
/* 34E3C8 E00386A8 26310001 */  addiu     $s1, $s1, 1
/* 34E3CC E00386AC 46020000 */  add.s     $f0, $f0, $f2
/* 34E3D0 E00386B0 E606FFF8 */  swc1      $f6, -8($s0)
/* 34E3D4 E00386B4 E604FFFC */  swc1      $f4, -4($s0)
/* 34E3D8 E00386B8 E6000000 */  swc1      $f0, ($s0)
/* 34E3DC E00386BC 8E820008 */  lw        $v0, 8($s4)
/* 34E3E0 E00386C0 0222102A */  slt       $v0, $s1, $v0
/* 34E3E4 E00386C4 1440FF81 */  bnez      $v0, .LE00384CC
/* 34E3E8 E00386C8 26100030 */   addiu    $s0, $s0, 0x30
.LE00386CC:
/* 34E3EC E00386CC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 34E3F0 E00386D0 8FB50024 */  lw        $s5, 0x24($sp)
/* 34E3F4 E00386D4 8FB40020 */  lw        $s4, 0x20($sp)
/* 34E3F8 E00386D8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 34E3FC E00386DC 8FB20018 */  lw        $s2, 0x18($sp)
/* 34E400 E00386E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 34E404 E00386E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 34E408 E00386E8 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 34E40C E00386EC D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 34E410 E00386F0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 34E414 E00386F4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 34E418 E00386F8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 34E41C E00386FC 03E00008 */  jr        $ra
/* 34E420 E0038700 27BD0058 */   addiu    $sp, $sp, 0x58
