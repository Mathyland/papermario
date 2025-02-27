// Used by:
// - Clubba + White Clubba
// - Spear Guy
// - Piranha Plant
// - Putrid Piranha + Frost Piranha

#include "common.h"
#include "npc.h"

// prerequisites
#include "world/common/enemy/MeleeHitbox.inc.c"

ApiStatus N(WanderMeleeAI_Main)(Evt *script, s32 isInitialCall) {
    #ifdef _DEAD_H_
    DeadEnemy* enemy = (DeadEnemy*)script->owner1.enemy;
    #else
    Enemy* enemy = script->owner1.enemy;
    #endif
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;
    #endif

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];

        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
        
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->functionTemp[1] = AI_STATE_WANDER_INIT;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_NONE;
    }

    if (script->AI_TEMP_STATE < AI_STATE_MELEE_HITBOX_INIT
            && enemy->AI_VAR_ATTACK_STATE == MELEE_HITBOX_STATE_NONE
            && N(MeleeHitbox_CanSeePlayer)(script)) {
        script->AI_TEMP_STATE = AI_STATE_MELEE_HITBOX_INIT;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_WANDER_INIT:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
            // fallthrough
        case AI_STATE_WANDER:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            basic_ai_loiter_init(script, npcAISettings, territoryPtr);
            // fallthrough
        case AI_STATE_LOITER:
            basic_ai_loiter(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_ALERT_INIT:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
            // fallthrough
        case AI_STATE_ALERT:
            basic_ai_found_player_jump(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
            // fallthrough
        case AI_STATE_CHASE:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            basic_ai_lose_player(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_MELEE_HITBOX_INIT:
            N(MeleeHitbox_30)(script);
            // fallthrough
        case AI_STATE_MELEE_HITBOX_PRE:
            N(MeleeHitbox_31)(script);
            if (script->AI_TEMP_STATE != AI_STATE_MELEE_HITBOX_ACTIVE) {
                break;
            }
            // fallthrough
        case AI_STATE_MELEE_HITBOX_ACTIVE:
            N(MeleeHitbox_32)(script);
            if (script->AI_TEMP_STATE != AI_STATE_MELEE_HITBOX_MISS) {
                break;
            }
            // fallthrough
        case AI_STATE_MELEE_HITBOX_MISS:
            N(MeleeHitbox_33)(script);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }

    return ApiStatus_BLOCK;
}
