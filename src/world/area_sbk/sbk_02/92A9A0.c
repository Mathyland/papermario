#include "sbk_02.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_8024091C_92ABCC);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_80240970_92AC20);

INCLUDE_ASM(s32, "world/area_sbk/sbk_02/92A9A0", func_802409A8_92AC58);

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

ApiStatus PostChapter2StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(2);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

ApiStatus N(CheckTradeEventTime)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s32)((gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600) < script->varTable[0];
    return ApiStatus_DONE2;
}


ApiStatus GetItemCount(Evt* script, s32 isInitialCall) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}
