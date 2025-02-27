#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_2_trd_03

#include "world/common/clouds.inc.c"

EvtScript N(beforeBattle_80232888) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LW(0), 4)
    EVT_SET(LW(2), 0)
    EVT_EXEC(N(clouds1))
    EVT_SET(LW(0), 2)
    EVT_SET(LW(2), 70)
    EVT_SET(LW(3), 175)
    EVT_SET(LW(4), -170)
    EVT_EXEC(N(clouds2))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80232920) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80232930)[] = {
    0x0000000F, 0x0000000E, 0x0000000D, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt03_shape",
    .hit = "trd_bt03_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle_80232888),
    .postBattle = &N(afterBattle_80232920),
    .foregroundModelList = N(foregroundModelList_80232930),
};
