#include "common.h"
#include "effects.h"

ApiStatus N(UnkWaterFountainFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect;
    f32 temp_f28;
    f32 temp_f26;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f20_2;

    temp_f28 = evt_get_variable(script, *args++);
    temp_f26 = evt_get_variable(script, *args++);
    evt_get_variable(script, *args++);
    temp_f20 = evt_get_variable(script, *args++);
    temp_f22 = evt_get_variable(script, *args++);
    temp_f24 = evt_get_variable(script, *args++);
    temp_f20_2 = atan2(temp_f28, temp_f26, temp_f20, temp_f22 + 40.0f);

    effect = fx_water_fountain(0, temp_f20 - 10.0f, temp_f22 + 60.0f, temp_f24 + 20.0f, 2.5f, 40);
    ((WaterFountainFXData*)effect->data)->unk_38 = temp_f20_2;
    ((WaterFountainFXData*)effect->data)->unk_18 = 2;
    ((WaterFountainFXData*)effect->data)->unk_1C = 2;
    ((WaterFountainFXData*)effect->data)->unk_20 = 2;
    ((WaterFountainFXData*)effect->data)->unk_28 = 80;
    ((WaterFountainFXData*)effect->data)->unk_2C = 80;
    ((WaterFountainFXData*)effect->data)->unk_30 = 80;
    return ApiStatus_DONE2;
}
