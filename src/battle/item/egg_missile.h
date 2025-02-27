#ifndef BATTLE_ITEM_EGG_MISSILE
#define BATTLE_ITEM_EGG_MISSILE

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_egg_missile

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

ApiStatus N(func_802A123C_71CF1C)(Evt* script, s32 isInitialCall);

#endif
