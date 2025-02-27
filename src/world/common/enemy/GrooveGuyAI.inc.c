#include "common.h"
#include "npc.h"

void N(GrooveGuyAI_02)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = 0;
    set_npc_yaw(npc, 270.0f);
    enemy->varTable[0] = 0;
    script->functionTemp[0] = 3;
}

void N(GrooveGuyAI_03)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe((s32) enemy->npcID);
    s32 phase;

    switch (enemy->varTable[0]) {
        case 0:
            enemy->varTable[0] = 1;
            enemy->varTable[1] = 0;
            npc->currentAnim.w = 0x3C000C;
            set_npc_yaw(npc, 270.0f);
            npc->rotation.y = 0.0f;
            // fallthrough
        case 1:
            phase = enemy->varTable[1] % 16;
            if (phase < 4) {
                npc->currentAnim.w = 0x3C000C;
            } else if (phase < 8) {
                npc->currentAnim.w = 0x3C000B;
            } else if (phase < 12) {
                npc->currentAnim.w = 0x3C000C;
            } else  if (phase < 16) {
                npc->currentAnim.w = 0x3C000D;
            }
            enemy->varTable[1]++;
            if (enemy->varTable[1] >= 0x41) {
                enemy->varTable[0] = 2;
            }
            break;
        case 2:
            enemy->varTable[0] = 3;
            enemy->varTable[1] = 0;
            npc->rotation.y = 0.0f;
            npc->currentAnim.w = 0x3C000C;
            // fallthrough
        case 3:
            npc->rotation.y += 35.0;
            if (npc->rotation.y > 360.0) {
                npc->rotation.y -= 360.0;
            }
            enemy->varTable[1]++;
            if (enemy->varTable[1] >= 0x2E) {
                enemy->varTable[0] = 4;
            }
            break;
    }
    if (enemy->varTable[0] == 4) {
        npc->rotation.y = 0.0f;
        set_npc_yaw(npc, 270.0f);
        script->functionTemp[0] = 0;
    }
}

ApiStatus N(GrooveGuyAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* aiSettings = (NpcAISettings*) evt_get_variable(script, *args++);
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 hitDepth;
    
    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;
    
    if (isInitialCall || enemy->aiFlags & 4) {
        script->functionTemp[0] = 0;
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
        
        if (enemy->aiFlags & 4) {
            script->functionTemp[0] = 0x63;
            script->functionTemp[1] = 0;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0] = 0xC;
        }
        enemy->aiFlags &= ~4;
        enemy->flags &= ~0x40000000;
        
        hitDepth = 100.0f;
        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth)) {
            npc->pos.y = posY;
        }
    }
    
    switch (script->functionTemp[0]) {
        case 0x0:
            basic_ai_wander_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0x1:
            basic_ai_wander(script, aiSettings, territoryPtr);
            break;
        case 0x2:
            N(GrooveGuyAI_02)(script, aiSettings, territoryPtr);
            // fallthrough
        case 0x3:
            N(GrooveGuyAI_03)(script, aiSettings, territoryPtr);
            break;
        case 0xA:
            basic_ai_found_player_jump_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0xB:
            basic_ai_found_player_jump(script, aiSettings, territoryPtr);
            break;
        case 0xC:
            basic_ai_chase_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0xD:
            basic_ai_chase(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0xE) {
                break;
            }
        case 0xE:
            basic_ai_lose_player(script, aiSettings, territoryPtr);
            break;
        case 0x63:
            basic_ai_suspend(script);
            break;
    }
    return 0;
}
