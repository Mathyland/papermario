#include "hos_01.h"
#include "effects.h"

extern u8 D_80241C2F_A124AF;
extern u8 D_80241C33_A124B3;

#include "world/common/atomic/TexturePan.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_01/A11020", func_80240AAC_A1132C);

INCLUDE_ASM(s32, "world/area_hos/hos_01/A11020", func_80240B10_A11390);

INCLUDE_ASM(s32, "world/area_hos/hos_01/A11020", func_80240B64_A113E4);

void func_80240BB8_A11438(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80241C2F_A124AF);
}

INCLUDE_ASM(s32, "world/area_hos/hos_01/A11020", func_80240C08_A11488);

void func_80240C34_A114B4(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80241C33_A124B3);
}

INCLUDE_ASM(s32, "world/area_hos/hos_01/A11020", func_80240C84_A11504);

#include "world/common/SwitchToPartner.inc.c"

ApiStatus func_80240CDC_A1155C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = evt_get_variable(script, *args++);
    s32 a1 = evt_get_variable(script, *args++);
    s32 a2 = evt_get_variable(script, *args++);
    s32 a3 = evt_get_variable(script, *args++);
    s32 a4 = evt_get_variable(script, *args++);

    fx_sparkles(a0, a1, a2, a3, a4);
    return ApiStatus_DONE2;
}
