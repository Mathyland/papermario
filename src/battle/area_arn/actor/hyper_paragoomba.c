#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/paragoomba.h"

#define NAMESPACE b_area_arn_hyper_paragoomba

extern s32 N(idleAnimations_8021C594)[];
extern s32 N(idleAnimations_8021C62C)[];
extern s32 N(idleAnimations_8021C638)[];
extern s32 N(idleAnimations_8021F05C)[];
extern EvtScript N(init_8021B564);
extern EvtScript N(idle_8021C690);
extern EvtScript N(handleEvent_8021C9C4);
extern EvtScript N(nextTurn_8021B5F4);
extern EvtScript N(takeTurn_8021C36C);
extern EvtScript N(takeTurn_8021D1DC);
extern EvtScript N(8021C94C);
extern EvtScript N(8021D9F4);
extern EvtScript N(8021E058);
extern EvtScript N(idle_8021F140);
extern EvtScript N(handleEvent_8021F41C);
extern EvtScript N(takeTurn_8021EE34);
extern EvtScript N(takeTurn_8021FE6C);
extern EvtScript N(nextTurn_8021E194);

s32 N(defenseTable_8021B2F0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(defenseTable_8021B2FC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021B308)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 100,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 80,
    STATUS_FEAR, 100,
    STATUS_STATIC, 100,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

s32 N(statusTable_8021B3B4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 80,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8021B460)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021F05C),
        .defenseTable = N(defenseTable_8021B2F0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021C594),
        .defenseTable = N(defenseTable_8021B2FC),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021C62C),
        .defenseTable = N(defenseTable_8021B2F0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021C638),
        .defenseTable = N(defenseTable_8021B2F0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_HYPER_PARAGOOMBA,
    .level = 12,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(partsTable_8021B460)),
    .partsData = N(partsTable_8021B460),
    .script = &N(init_8021B564),
    .statusTable = N(statusTable_8021B3B4),
    .escapeChance = 50,
    .airLiftChance = 95,
    .spookChance = 95,
    .baseStatusChance = 80,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 36, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_8021B518)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_hyper_aim,
    STATUS_STONE,     NPC_ANIM_paragoomba_hyper_still,
    STATUS_SLEEP,     NPC_ANIM_paragoomba_hyper_sleep,
    STATUS_POISON,    NPC_ANIM_paragoomba_hyper_aim,
    STATUS_STOP,      NPC_ANIM_paragoomba_hyper_still,
    STATUS_STATIC,    NPC_ANIM_paragoomba_hyper_aim,
    STATUS_PARALYZE,  NPC_ANIM_paragoomba_hyper_still,
    STATUS_DIZZY,     NPC_ANIM_paragoomba_hyper_dizzy,
    STATUS_FEAR,      NPC_ANIM_paragoomba_hyper_dizzy,
    STATUS_END,
};

EvtScript N(init_8021B564) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021C690)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021C9C4)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn_8021B5F4)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021C36C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021B5F4) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(SetBattleVar, 1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B678) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 10)
        EVT_CALL(PlayEffect, EFFECT_ENERGY_IN_OUT, 6, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 45, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_aim)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021B518)))
        EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_400000, 1)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_LOOP(20)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
            EVT_THREAD
                EVT_SET(LW(0), -60)
                EVT_LOOP(60)
                    EVT_ADD(LW(0), 19)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, FALSE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -60, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_400000, 0)
            EVT_THREAD
                EVT_SET(LW(0), 0)
                EVT_LOOP(30)
                    EVT_ADD(LW(0), 24)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021C594)))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -70)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, FALSE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LW(0), -70)
                EVT_LOOP(60)
                    EVT_ADD(LW(0), 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SET(LW(1), 0)
            EVT_SUB(LW(0), 70)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
            EVT_SUB(LW(0), 60)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_run)
            EVT_EXEC_WAIT(N(8021C94C))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021C594)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021C36C) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetBattleVar, 1, 1)
        EVT_EXEC_WAIT(N(takeTurn_8021D1DC))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_EXEC_WAIT(N(8021B678))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleVar, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LT(LW(0), 750)
                    EVT_CALL(SetBattleVar, 1, 2)
                    EVT_EXEC_WAIT(N(8021B678))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, 1, 1)
                    EVT_EXEC_WAIT(N(takeTurn_8021D1DC))
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LT(LW(0), 500)
                    EVT_CALL(SetBattleVar, 1, 2)
                    EVT_EXEC_WAIT(N(8021B678))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, 1, 1)
                    EVT_EXEC_WAIT(N(takeTurn_8021D1DC))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(takeTurn_8021D1DC))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(8021B678))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_8021C594)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_hyper_idle,
    STATUS_STONE,     NPC_ANIM_paragoomba_hyper_still,
    STATUS_SLEEP,     NPC_ANIM_paragoomba_hyper_sleep,
    STATUS_POISON,    NPC_ANIM_paragoomba_hyper_idle,
    STATUS_STOP,      NPC_ANIM_paragoomba_hyper_still,
    STATUS_STATIC,    NPC_ANIM_paragoomba_hyper_idle,
    STATUS_PARALYZE,  NPC_ANIM_paragoomba_hyper_still,
    STATUS_DIZZY,     NPC_ANIM_paragoomba_hyper_dizzy,
    STATUS_FEAR,      NPC_ANIM_paragoomba_hyper_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021C5E0)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_hyper_run,
    STATUS_STONE,     NPC_ANIM_paragoomba_hyper_still,
    STATUS_SLEEP,     NPC_ANIM_paragoomba_hyper_sleep,
    STATUS_POISON,    NPC_ANIM_paragoomba_hyper_idle,
    STATUS_STOP,      NPC_ANIM_paragoomba_hyper_still,
    STATUS_STATIC,    NPC_ANIM_paragoomba_hyper_run,
    STATUS_PARALYZE,  NPC_ANIM_paragoomba_hyper_still,
    STATUS_DIZZY,     NPC_ANIM_paragoomba_hyper_dizzy,
    STATUS_FEAR,      NPC_ANIM_paragoomba_hyper_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021C62C)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_hyper_left_wing_only,
    STATUS_END,
};

s32 N(idleAnimations_8021C638)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_hyper_right_wing_only,
    STATUS_END,
};

EvtScript N(8021C644) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021D1DC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021C690)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021C9C4)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021C690) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, LW(0))
    EVT_ADD(LW(0), 80)
    EVT_LOOP(LW(0))
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021C5E0)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021C594)))
    EVT_LOOP(40)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C94C) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021C9C4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_CALL(GetEncounterState, LW(0))
                EVT_IF_EQ(LW(0), 4)
                    EVT_EXEC_WAIT(N(8021D9F4))
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_burn_pain)
            EVT_SET_CONST(LW(2), NPC_ANIM_paragoomba_hyper_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_burn_pain)
            EVT_SET_CONST(LW(2), NPC_ANIM_paragoomba_hyper_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_burn_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FALL_TRIGGER)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021D9F4))
        EVT_CASE_EQ(EVENT_15)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_burn_pain)
            EVT_SET_CONST(LW(2), NPC_ANIM_paragoomba_hyper_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021D9F4))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021C594)))
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_pain)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_dizzy)
            EVT_EXEC_WAIT(N(8021C94C))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021C594)))
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_400000, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021C594)))
            EVT_END_IF
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_run)
            EVT_EXEC_WAIT(N(8021C94C))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_run)
            EVT_SET_CONST(LW(2), NPC_ANIM_paragoomba_hyper_pain)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_paragoomba_hyper_pain)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021D1DC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 300)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_attack)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_SUB(LW(0), 80)
            EVT_SET(LW(1), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_attack)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 4)
            EVT_THREAD
                EVT_LOOP(4)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DF)
                    EVT_WAIT_FRAMES(4)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_aim)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 2, EVT_FLOAT(3.0))
            EVT_WAIT_FRAMES(10)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 2, EVT_FLOAT(1.0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_run)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(8021C94C))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 300)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_attack)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_attack)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_hyper_run)
            EVT_EXEC_WAIT(N(8021C94C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(8021D9F4) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 3, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 4, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, -9, 7, -2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 4, 11, 7, -2)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_IF_EQ(LW(0), EVENT_15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_burn_dead)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_pain)
    EVT_END_IF
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 769, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 100, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(3))
    EVT_IF_EQ(LW(3), EVENT_15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_pain)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
        EVT_ADD(LW(4), 10)
        EVT_ADD(LW(5), 5)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 10, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_LOOP(10)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LW(0))
    EVT_MOD(LW(0), 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LW(0))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_ADDR(N(statusTable_8021B308)))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_HYPER_GOOMBA)
    EVT_EXEC_WAIT(N(8021E058))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_8021DF7C)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_hyper_asleep,
    STATUS_STONE,     NPC_ANIM_goomba_hyper_still,
    STATUS_SLEEP,     NPC_ANIM_goomba_hyper_asleep,
    STATUS_POISON,    NPC_ANIM_goomba_hyper_asleep,
    STATUS_STOP,      NPC_ANIM_goomba_hyper_still,
    STATUS_STATIC,    NPC_ANIM_goomba_hyper_asleep,
    STATUS_PARALYZE,  NPC_ANIM_goomba_hyper_still,
    STATUS_DIZZY,     NPC_ANIM_goomba_hyper_dizzy,
    STATUS_FEAR,      NPC_ANIM_goomba_hyper_dizzy,
    STATUS_END,
};

EvtScript N(8021DFC8) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021F140)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021F41C)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021EE34)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn_8021E194)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E058) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021F140)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021F41C)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021EE34)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn_8021E194)))
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 1)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_400000, 0)
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021E194) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(SetBattleVar, 1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E218) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 10)
        EVT_CALL(PlayEffect, EFFECT_ENERGY_IN_OUT, 6, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 45, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_run)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DD)
        EVT_CALL(N(StartRumbleWithParams), 128, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021DF7C)))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
        EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 1)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_LOOP(20)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
                    EVT_ADD(LW(0), 30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
                    EVT_IF_GT(LW(0), LW(3))
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
                EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
                EVT_WAIT_FRAMES(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_THREAD
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 80)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 271, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_WAIT_FRAMES(20)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F05C)))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 271, 0)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 80)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                EVT_SET(LW(0), 80)
                EVT_LOOP(60)
                    EVT_ADD(LW(0), 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SET(LW(1), 0)
            EVT_SUB(LW(0), 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 40)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F05C)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021EE34) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetBattleVar, 1, 1)
        EVT_EXEC_WAIT(N(takeTurn_8021FE6C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_EXEC_WAIT(N(8021E218))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleVar, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LT(LW(0), 750)
                    EVT_CALL(SetBattleVar, 1, 2)
                    EVT_EXEC_WAIT(N(8021E218))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, 1, 1)
                    EVT_EXEC_WAIT(N(takeTurn_8021FE6C))
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LT(LW(0), 500)
                    EVT_CALL(SetBattleVar, 1, 2)
                    EVT_EXEC_WAIT(N(8021E218))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, 1, 1)
                    EVT_EXEC_WAIT(N(takeTurn_8021FE6C))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(takeTurn_8021FE6C))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(8021E218))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_8021F05C)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_hyper_idle,
    STATUS_STONE,     NPC_ANIM_goomba_hyper_still,
    STATUS_SLEEP,     NPC_ANIM_goomba_hyper_asleep,
    STATUS_POISON,    NPC_ANIM_goomba_hyper_idle,
    STATUS_STOP,      NPC_ANIM_goomba_hyper_still,
    STATUS_STATIC,    NPC_ANIM_goomba_hyper_idle,
    STATUS_PARALYZE,  NPC_ANIM_goomba_hyper_still,
    STATUS_DIZZY,     NPC_ANIM_goomba_hyper_dizzy,
    STATUS_FEAR,      NPC_ANIM_goomba_hyper_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021F0A8)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_hyper_run,
    STATUS_STONE,     NPC_ANIM_goomba_hyper_still,
    STATUS_SLEEP,     NPC_ANIM_goomba_hyper_asleep,
    STATUS_POISON,    NPC_ANIM_goomba_hyper_idle,
    STATUS_STOP,      NPC_ANIM_goomba_hyper_still,
    STATUS_STATIC,    NPC_ANIM_goomba_hyper_run,
    STATUS_PARALYZE,  NPC_ANIM_goomba_hyper_still,
    STATUS_DIZZY,     NPC_ANIM_goomba_hyper_dizzy,
    STATUS_FEAR,      NPC_ANIM_goomba_hyper_dizzy,
    STATUS_END,
};

EvtScript N(8021F0F4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021FE6C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021F140)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021F41C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021F140) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, LW(0))
    EVT_ADD(LW(0), 80)
    EVT_LOOP(LW(0))
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F0A8)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F05C)))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F0A8)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F05C)))
    EVT_LOOP(80)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021F41C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_pain)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_burn_pain)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_hyper_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_burn_pain)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_hyper_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_burn_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F05C)))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_pain)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_dizzy)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F05C)))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021F05C)))
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_run)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_hyper_pain)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_hyper_pain)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/anglestuff.inc.c"

EvtScript N(takeTurn_8021FE6C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_headbonk)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 10)
            EVT_SET(LW(1), 10)
            EVT_ADD(LW(2), 3)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(0))
                EVT_SET(LW(0), 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                    EVT_CALL(N(CalculateRotationZ), LW(1), LW(2), LW(4), LW(5), LW(0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_SET(LW(1), LW(4))
                    EVT_SET(LW(2), LW(5))
                    EVT_SET(LW(3), LW(6))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_asleep)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_pain)
            EVT_WAIT_FRAMES(5)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_headbonk)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_SET(LW(0), 180)
                EVT_LOOP(4)
                    EVT_SUB(LW(0), 45)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_dizzy)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(0))
                EVT_SET(LW(0), 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                    EVT_CALL(N(CalculateRotationZ), LW(1), LW(2), LW(4), LW(5), LW(0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_SET(LW(1), LW(4))
                    EVT_SET(LW(2), LW(5))
                    EVT_SET(LW(3), LW(6))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_pre_headbonk)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
    EVT_END_SWITCH
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_idle)
            EVT_WAIT_FRAMES(3)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_hyper_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
