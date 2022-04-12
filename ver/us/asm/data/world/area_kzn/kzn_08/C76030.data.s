.include "macro.inc"

.section .data

dlabel kzn_08_varStash
.word 0x00000000

dlabel D_80244BB4_C76034
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244C1C_C7609C
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000046, 0x00000001, D_80244BB4_C76034, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8B, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, AddItem, 0xFE363C8A, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, AddBadge, 0xFE363C8A, 0xFE363C80, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244CFC_C7617C
.word 0x00000024, 0x00000002, 0xFE363C8A, 0x000000EF, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000002, 0x00000024, 0x00000002, 0xF84060AC, 0x00000001, 0x00000046, 0x00000001, D_80244C1C_C7609C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAE30, 0x00000078, 0x00000064, 0xFFFFFFC9, 0x00000000, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignChestFlag, 0xF84060AC, 0x00000043, 0x00000002, AssignScript, D_80244CFC_C7617C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel kzn_08_sixFloats
.float 4.5, 3.5, 2.6, 2.0, 1.5, 20.0

dlabel D_80244DB8_C76238
.word 0x3F4CCCCD, 0x00000064, 0x00000000, 0x42B40000, 0x00000000, 0x00000004, 0x404CCCCD, 0x0000000A, 0x00000001, 0x42C80000, 0x00000000, 0x00000001

dlabel D_80244DE8_C76268
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000096, 0x00000043, 0x00000002, kzn_08_UnkNpcAIMainFunc10, D_80244DB8_C76238, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80244DE8_C76268, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000

dlabel D_80244E84_C76304
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244F40_C763C0
.word 0x00000000, 0x0000001E, 0x0000001E, 0x43160000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244F70_C763F0
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000008, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000009, 0x00000009, 0x00000043, 0x00000003, SetSelfVar, 0x0000000A, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x0000000B, 0x00000007, 0x00000043, 0x00000003, SetSelfVar, 0x0000000C, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x0000000D, 0x0000000F, 0x00000043, 0x00000003, SetSelfVar, 0x0000000E, 0x00000012, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x0000000F, 0x00000043, 0x00000002, func_80243C90_C75110, D_80244F40_C763C0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245044_C764C4
.word 0x00000000, 0x00320024, 0x00000000, 0x00000000, D_80244F70_C763F0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000

dlabel D_80245070_C764F0
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x0000000E, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000001C, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x000020DE, 0x00000043, 0x00000001, kzn_08_UnkFunc7, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000003, GetSelfAnimationFromTable, 0x00000007, 0xFE363C80, 0x00000046, 0x00000001, 0x800936DC, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024517C_C765FC
.word 0x00000000, 0x0014001C, 0x00000000, 0x00000000, D_80245070_C764F0, 0x00000000, 0x00000000, D_80244E84_C76304, 0x00000000, 0x00000000, 0x00110000

dlabel D_802451A8_C76628
.word 0x00000000, D_80245044_C764C4, 0x42A00000, 0x00000000, 0x43070000, 0x00000500, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000050, 0x00000000, 0x00000087, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000005A, 0x00000000, 0x00000082, 0x00000082, 0x0000003C, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_8024517C_C765FC, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_802451A8_C76628, 0x16110005, 0x00000000, 0x00000000, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80243EE0_C75360, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
