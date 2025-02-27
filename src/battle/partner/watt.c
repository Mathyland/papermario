#include "common.h"
#include "effects.h"

#define NAMESPACE battle_partner_watt

extern EffectInstance* D_8023C1B0;
extern EffectInstance* D_8023C1B4;
extern s32 D_8023C1B8;
extern s32 D_8023C1BC;
extern s32 D_8023C1C4;
extern s32 D_8023C1C8;
extern EffectInstance* D_8023C1CC;
extern EffectInstance* D_8023C1D0;
extern EffectInstance* D_80239A0C_7054FC;

INCLUDE_ASM(s32, "battle/partner/watt", func_80238000_703AF0);

ApiStatus func_80238370_703E60(Evt* script, s32 isInitialCall) {
    D_8023C1B8 = 0;
    if (D_8023C1CC != NULL) {
        remove_effect(D_8023C1CC);
    }
    if (D_8023C1D0 != NULL) {
        remove_effect(D_8023C1D0);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802383C0_703EB0(Evt* script, s32 isInitialCall) {
    D_8023C1BC = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802383D4_703EC4(Evt* script, s32 isInitialCall) {
    D_8023C1BC = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802383E4_703ED4(Evt* script, s32 isInitialCall) {
    D_8023C1C4 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802383F8_703EE8(Evt* script, s32 isInitialCall) {
    D_8023C1C4 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80238408_703EF8(Evt* script, s32 isInitialCall) {
    D_8023C1C8 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

ApiStatus func_802384B0_703FA0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    D_80239A0C_7054FC = fx_radial_shimmer(8, var1, var2, var3, 1.3f, 55);

    return ApiStatus_DONE2;
}

ApiStatus func_80238570_704060(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = D_80239A0C_7054FC;

    if (effect != NULL) {
        effect->flags |= 0x10;
    }
    D_80239A0C_7054FC = NULL;

    return ApiStatus_DONE2;
}

ApiStatus func_8023859C_70408C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    ThunderboltRingFXData* data;

    D_8023C1B4 = fx_thunderbolt_ring(0, var1, var2, var3, 1.0f, 10);
    data = D_8023C1B4->data;
    data->unk_30 = 3;

    return ApiStatus_DONE2;
}

ApiStatus func_80238668_704158(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* partner = gBattleStatus.partnerActor;
    f32 x = partner->currentPos.x + partner->headOffset.x;
    f32 y = partner->currentPos.y + partner->headOffset.y + partner->unk_19A + 12.0f;
    f32 z = partner->currentPos.z + partner->headOffset.z;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        fx_bulb_glow(0, x, y, z, 1.0f, &D_8023C1B0);
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        ((BulbGlowFXData*)D_8023C1B0->data)->unk_14 = 5;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238784_704274(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    ActorPart* targetActorPart = get_actor_part(targetActor, partnerActor->targetPartIndex);
    s32 statusChance = lookup_status_chance(targetActor->statusTable, 5);

    if (targetActor->transStatus == 14) {
        statusChance = 0;
    }
    if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        statusChance = 0;
    }

    script->varTable[0] = statusChance;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/watt", func_80238810_704300);

ApiStatus func_80238B3C_70462C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    ThunderboltRingFXData* data;

    D_8023C1B4 = fx_thunderbolt_ring(0, var1, var2, var3, 1.0f, 60);
    data = D_8023C1B4->data;
    data->unk_30 = 2;

    return ApiStatus_DONE2;
}

ApiStatus func_80238C08_7046F8(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = script->varTable[0];

    if (var1 > 0) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = 0;
    script->varTable[10] = var1;
    if (battleStatus->turboChargeTurnsLeft < var1) {
        battleStatus->turboChargeTurnsLeft = var1;
        battleStatus->turboChargeAmount = 1;
        battleStatus->unk_43C->unk_0C->unk_24 = battleStatus->turboChargeTurnsLeft;
    }

    if (gBattleStatus.flags2 & 2) {
        gBattleStatus.flags2 |= 0x100;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/watt", func_80238C84_704774);

ApiStatus N(AverageTargetParalyzeChance)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorPart* targetActorPart;
    s32 targetActorBlueprintBaseStatusChance;
    s32 chanceTotal = 0;
    s32 nTargets = 0;
    s32 i;

    for (i = 0; i < partnerActor->targetListLength; i++) {
        targetActor = get_actor(partnerActor->targetData[i].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[i].partID);
        targetActorBlueprintBaseStatusChance = lookup_status_chance(targetActor->statusTable, STATUS_PARALYZE);

        if (targetActor->transStatus == 14) {
            targetActorBlueprintBaseStatusChance = 0;
        }

        if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
            targetActorBlueprintBaseStatusChance = 0;
        }

        if (targetActorBlueprintBaseStatusChance > 0) {
            chanceTotal += targetActorBlueprintBaseStatusChance;
            nTargets++;
        }
    }

    if (nTargets > 0) {
        script->varTable[0] = chanceTotal / nTargets;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
