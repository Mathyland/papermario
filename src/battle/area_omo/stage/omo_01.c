#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo_omo_01

ApiStatus func_80218FB0_513580(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/area_omo/513580", func_80218FB0_513580);

s32 D_8022DA30_528000 = 25;

EvtScript N(8022DA34) = {
    EVT_CALL(func_80218FB0_513580)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_8022DA50) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SETF(LW(0), EVT_FLOAT(0.0))
        EVT_SETF(LW(1), EVT_FLOAT(0.0))
        EVT_LOOP(0)
            EVT_CALL(RotateModel, 23, LW(1), 0, 0, 1)
            EVT_CALL(RotateModel, 21, LW(0), 0, 0, 1)
            EVT_SUBF(LW(0), EVT_FLOAT(0.6))
            EVT_SUBF(LW(1), EVT_FLOAT(7.2))
            EVT_CALL(ClampAngleFloat, LW(0))
            EVT_CALL(ClampAngleFloat, LW(1))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC(N(8022DA34))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022DB68) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt01_shape",
    .hit = "omo_bt01_hit",
    .bg = "omo_bg",
    .preBattle = &N(beforeBattle_8022DA50),
    .postBattle = &N(afterBattle_8022DB68),
};
