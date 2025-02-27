#include "common.h"

#ifndef CHUCK_QUIZMO_NPC_ID
#  error CHUCK_QUIZMO_NPC_ID must be defined for QuizmoData.inc.c
#endif

s32** N(Quizmo_varStash) = NULL;

EvtScript N(EVS_Quizmo_GiveItem_0) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_GiveItem_16) = {
    EVT_CALL(ShowGotItem, EVT_VAR(0), 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

u8 N(Quizmo_Answers)[64] = {
    0x02, 0x01, 0x01, 0x02, 0x02, 0x00, 0x02, 0x00,
    0x02, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x02,
    0x00, 0x02, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00,
    0x02, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01, 0x01,
    0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01,
    0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x02,
    0x01, 0x02, 0x00, 0x02, 0x02, 0x01, 0x01, 0x01,
};

QuizRequirement N(Quizmo_Requirements)[] = {
    { STORY_CH0_KAMMY_RETURNED_TO_BOWSER, 0 },
    { STORY_CH1_BEGAN_PEACH_MISSION, 10 },
    { STORY_CH2_BEGAN_PEACH_MISSION, 20 },
    { STORY_CH3_BEGAN_PEACH_MISSION, 30 },
    { STORY_CH4_BEGAN_PEACH_MISSION, 37 },
    { STORY_CH5_STAR_SPRIT_DEPARTED, 44 },
    { STORY_CH6_BEGAN_PEACH_MISSION, 52 },
    { STORY_CH7_BEGAN_PEACH_MISSION, 60 },
    { STORY_EPILOGUE, 64 },
    { 0, 64 }, // end of list
};

EvtScript N(EVS_Quizmo_Exit) = {
    EVT_CALL(N(Quizmo_ShouldQuizmoLeave))
    EVT_IF_LE(EVT_VAR(0), 1)
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 300)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_C)
        EVT_WAIT_FRAMES(40)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_SetQuizCamera) = {
    EVT_CALL(N(Quizmo_GetCamVfov), 0, EVT_ARRAY(0))
    EVT_CALL(N(Quizmo_SetCamVfov), 0, 25) //TODO
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetCamType, 0, EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamType, 0, EVT_VAR(1), 0)
    EVT_CALL(GetCamDistance, 0, EVT_VAR(0))
    EVT_IF_GT(EVT_VAR(0), 0)
        EVT_SETF(EVT_VAR(0), 370)
    EVT_ELSE
        EVT_SETF(EVT_VAR(0), -370)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, EVT_VAR(0))
    EVT_CALL(GetCamPitch, 0, EVT_VAR(0), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_FIXED(13.0))
    EVT_SETF(EVT_VAR(1), EVT_FIXED(-10.0))
    EVT_CALL(SetCamPitch, 0, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_OtherCamScript) = {
    EVT_CALL(GetNpcPos, CHUCK_QUIZMO_NPC_ID, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 30)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetCamDistance, 0, EVT_VAR(0))
    EVT_IF_GT(EVT_VAR(0), 0)
        EVT_SETF(EVT_VAR(0), 17)
    EVT_ELSE
        EVT_SETF(EVT_VAR(0), -17)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, EVT_VAR(0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetCamSpeed, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_ResetCamera) = {
    EVT_CALL(N(Quizmo_SetCamVfov), 0, EVT_ARRAY(0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MovePlayerToPodium) = {
    EVT_WAIT_FRAMES(20)
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), EVT_ARRAY(1), EVT_ARRAY(3), 83, EVT_VAR(0), EVT_VAR(1))
    EVT_THREAD
        EVT_SETF(EVT_VAR(2), 0)
        EVT_LOOP(60)
            EVT_SETF(EVT_VAR(3), EVT_VAR(0))
            EVT_SETF(EVT_VAR(4), EVT_VAR(1))
            EVT_MULF(EVT_VAR(3), EVT_VAR(2))
            EVT_MULF(EVT_VAR(4), EVT_VAR(2))
            EVT_DIVF(EVT_VAR(3), 60)
            EVT_DIVF(EVT_VAR(4), 60)
            EVT_ADDF(EVT_VAR(3), EVT_ARRAY(1))
            EVT_ADDF(EVT_VAR(4), EVT_ARRAY(3))
            EVT_CALL(SetPlayerPos, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
            EVT_ADDF(EVT_VAR(2), 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_SETF(EVT_VAR(3), EVT_VAR(0))
        EVT_SETF(EVT_VAR(4), EVT_VAR(1))
        EVT_ADDF(EVT_VAR(3), EVT_ARRAY(1))
        EVT_ADDF(EVT_VAR(4), EVT_ARRAY(3))
        EVT_CALL(SetPlayerPos, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SpinPlayer))
    EVT_CALL(func_802D2884, EVT_ARRAY(1), EVT_ARRAY(3), 0)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MovePartnerToPodium) = {
    EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), EVT_VAR(10), EVT_VAR(12), 108, EVT_VAR(0), EVT_VAR(1))
    EVT_SETF(EVT_VAR(5), EVT_ARRAY(2))
    EVT_SUBF(EVT_VAR(5), EVT_VAR(11))
    EVT_THREAD
        EVT_CALL(N(Quizmo_UpdatePartnerPosition))
        EVT_SETF(EVT_VAR(3), EVT_VAR(0))
        EVT_SETF(EVT_VAR(4), EVT_VAR(1))
        EVT_SETF(EVT_VAR(6), EVT_VAR(5))
        EVT_ADDF(EVT_VAR(3), EVT_VAR(10))
        EVT_ADDF(EVT_VAR(4), EVT_VAR(12))
        EVT_ADDF(EVT_VAR(6), EVT_VAR(11))
        EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(3), EVT_VAR(6), EVT_VAR(4))
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SpinPartner))
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MoveQuizmoToMicrophone) = {
    EVT_CALL(GetNpcPos, CHUCK_QUIZMO_NPC_ID, EVT_VAR(10), EVT_VAR(11), EVT_VAR(12))
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), EVT_VAR(10), EVT_VAR(12), -70, EVT_VAR(0), EVT_VAR(1))
    EVT_THREAD
        EVT_SETF(EVT_VAR(2), 0)
        EVT_LOOP(60)
            EVT_SETF(EVT_VAR(3), EVT_VAR(0))
            EVT_SETF(EVT_VAR(4), EVT_VAR(1))
            EVT_MULF(EVT_VAR(3), EVT_VAR(2))
            EVT_MULF(EVT_VAR(4), EVT_VAR(2))
            EVT_DIVF(EVT_VAR(3), 60)
            EVT_DIVF(EVT_VAR(4), 60)
            EVT_ADDF(EVT_VAR(3), EVT_VAR(10))
            EVT_ADDF(EVT_VAR(4), EVT_VAR(12))
            EVT_CALL(SetNpcPos, CHUCK_QUIZMO_NPC_ID, EVT_VAR(3), EVT_ARRAY(2), EVT_VAR(4))
            EVT_ADDF(EVT_VAR(2), 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(60)
    EVT_CALL(NpcFacePlayer, CHUCK_QUIZMO_NPC_ID, 0)
    EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_SetCharacterPositons) = {
    EVT_EXEC(N(EVS_Quizmo_MovePlayerToPodium))
    EVT_EXEC(N(EVS_Quizmo_MovePartnerToPodium))
    EVT_EXEC_WAIT(N(EVS_Quizmo_MoveQuizmoToMicrophone))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerThinking) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_QUESTION)
        EVT_WAIT_FRAMES(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerHitBuzzer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_THROW)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerReaction_RightAnswer) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_10002)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_BEFORE_JUMP)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), 0)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -2)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(EVT_VAR(1), -3)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPlayerAnimation, ANIM_10009)
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_ARRAY(2), EVT_VAR(2))
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerReaction_WrongAnswer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_SHOCK_STILL)
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_ReturnPlayerToOriginalPos) = {
    EVT_THREAD
        EVT_CALL(N(Quizmo_AddViewRelativeOffset), EVT_ARRAY(1), EVT_ARRAY(3), 25, EVT_VAR(0), EVT_VAR(1))
        EVT_SETF(EVT_VAR(2), EVT_ARRAY(1))
        EVT_ADDF(EVT_VAR(2), EVT_VAR(0))
        EVT_SETF(EVT_VAR(3), EVT_ARRAY(3))
        EVT_ADDF(EVT_VAR(3), EVT_VAR(1))
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_JUMP)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, EVT_VAR(2), EVT_VAR(3), 40)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, EVT_ARRAY(1), EVT_ARRAY(3), 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_RightAnswer) = {
    EVT_EXEC_GET_TID(N(EVS_Quizmo_PlayerReaction_RightAnswer), EVT_VAR(1))
    EVT_WAIT_FRAMES(60)
    EVT_KILL_THREAD(EVT_VAR(1))
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(20)
    EVT_EXEC_WAIT(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_WrongAnswer) = {
    EVT_EXEC_GET_TID(N(EVS_Quizmo_PlayerReaction_WrongAnswer), EVT_VAR(1))
    EVT_WAIT_FRAMES(60)
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), -1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(20)
    EVT_KILL_THREAD(EVT_VAR(1))
    EVT_EXEC_WAIT(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_QuizMain) = {
    EVT_IF_GT(EVT_SAVE_VAR(352), 63)
        EVT_SET(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, EVT_ARRAY(1), EVT_ARRAY(2), EVT_ARRAY(3))
    EVT_CALL(NpcFacePlayer, NPC_SELF, 16)
    EVT_IF_EQ(EVT_SAVE_VAR(352), 63)
        EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x000A))
    EVT_ELSE
        EVT_IF_EQ(EVT_SAVE_FLAG(1767), 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x0009))
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x0008))
            EVT_SET(EVT_SAVE_FLAG(1767), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x000D))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x000C))
        EVT_EXEC_WAIT(N(EVS_Quizmo_Exit))
        EVT_SET(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_SAVE_FLAG(1793), 1)
    EVT_CALL(N(Quizmo_HideEntities))
    EVT_CALL(N(Quizmo_HideWorld))
    EVT_EXEC(N(EVS_Quizmo_SetQuizCamera))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, CHUCK_QUIZMO_NPC_ID, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcFlagBits, CHUCK_QUIZMO_NPC_ID, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_EXEC_GET_TID(N(EVS_Quizmo_SetCharacterPositons), EVT_VAR(1))
    EVT_CALL(ContinueSpeech, -1, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x000B))
    EVT_CALL(PlaySound, 137)
    EVT_LOOP(0)
        EVT_IS_THREAD_RUNNING(EVT_VAR(1), EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(N(Quizmo_CreateStage))
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 1)
        EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_SET(EVT_VAR(0), MESSAGE_ID(0x2C, 0x00))
    EVT_ADD(EVT_VAR(0), EVT_SAVE_VAR(352))
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6, 0, EVT_VAR(0))
    EVT_CALL(SetPlayerAnimation, ANIM_QUESTION)
    EVT_SET(EVT_VAR(0), MESSAGE_ID(0x2D, 0x00))
    EVT_ADD(EVT_VAR(0), EVT_SAVE_VAR(352))
    EVT_CALL(PlaySound, 142)
    EVT_CALL(ShowChoice, EVT_VAR(0))
    EVT_KILL_THREAD(EVT_VAR(1))
    EVT_CALL(StopSound, 142)
    EVT_EXEC(N(EVS_Quizmo_PlayerHitBuzzer))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySound, 141)
    EVT_CALL(N(Quizmo_UnkStageEffectMode), EVT_VAR(0))
    EVT_SET(EVT_ARRAY(4), 0)
    EVT_CALL(N(Quizmo_CreateWorker))
    EVT_WAIT_FRAMES(40)
    EVT_CALL(N(Quizmo_UpdateRecords))
    EVT_THREAD
        EVT_WAIT_FRAMES(110)
        EVT_CALL(CloseChoice)
        EVT_SET(EVT_ARRAY(4), 0)
    EVT_END_THREAD
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_7)
        EVT_SET(EVT_ARRAY(4), 1)
        EVT_THREAD
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 1)
            EVT_WAIT_FRAMES(6)
            EVT_WAIT_FRAMES(6)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 2)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(PlaySound, SOUND_21C)
        EVT_END_THREAD
        EVT_CALL(PlaySound, SOUND_8A)
        EVT_CALL(N(Quizmo_SetVannaAnim_Clap))
        EVT_THREAD
            EVT_WAIT_FRAMES(15)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 50)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 83, EVT_VAR(0), EVT_VAR(2))
            EVT_CALL(PlayEffect, 0x7, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_ADD(EVT_VAR(1), -3)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 58, EVT_VAR(0), EVT_VAR(2))
            EVT_CALL(PlayEffect, 0x7, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_ADD(EVT_VAR(1), 30)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 93, EVT_VAR(0), EVT_VAR(2))
            EVT_CALL(PlayEffect, 0x7, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
        EVT_END_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_EXEC_GET_TID(N(EVS_Quizmo_RightAnswer), EVT_VAR(1))
        EVT_ADD(EVT_SAVE_VAR(352), 1)
        EVT_IF_GT(EVT_SAVE_VAR(352), 63)
            EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MESSAGE_ID(0x08, 0x0010))
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(EVT_VAR(1), EVT_VAR(0))
                EVT_IF_EQ(EVT_VAR(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5)
            EVT_SET(EVT_VAR(0), ITEM_STAR_PIECE)
            EVT_SET(EVT_VAR(1), 3)
            EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
            EVT_CALL(AddStarPieces, 1)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 15)
            EVT_CALL(N(Quizmo_SetVannaAnim_Idle))
            EVT_CALL(SetMessageValue, EVT_SAVE_VAR(352), 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x0011))
        EVT_ELSE
            EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MESSAGE_ID(0x08, 0x000E))
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_6)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(EVT_VAR(1), EVT_VAR(0))
                EVT_IF_EQ(EVT_VAR(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_5)
            EVT_SET(EVT_VAR(0), ITEM_STAR_PIECE)
            EVT_SET(EVT_VAR(1), 1)
            EVT_EXEC_WAIT(N(EVS_Quizmo_GiveItem_0))
            EVT_CALL(AddStarPieces, 1)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 15)
            EVT_CALL(N(Quizmo_SetVannaAnim_Idle))
            EVT_CALL(SetMessageValue, EVT_SAVE_VAR(352), 0)
            EVT_IF_EQ(EVT_SAVE_VAR(352), 1)
                EVT_CALL(SetMessageMsg, EVT_PTR(MessageSingular), 1)
            EVT_ELSE
                EVT_CALL(SetMessageMsg, EVT_PTR(MessagePlural), 1)
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_4, NPC_ANIM_chuck_quizmo_Palette_00_Anim_1, 0, MESSAGE_ID(0x08, 0x000F))
        EVT_END_IF
        EVT_SET(EVT_VAR(0), 1)
    EVT_ELSE
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_9)
        EVT_SET(EVT_ARRAY(4), 2)
        EVT_CALL(PlaySound, SOUND_MENU_ERROR)
        EVT_CALL(PlaySound, SOUND_8B)
        EVT_EXEC_GET_TID(N(EVS_Quizmo_WrongAnswer), EVT_VAR(1))
        EVT_CALL(GetPlayerPos, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_CALL(PlayEffect, 0x2B, 0, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4), 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MESSAGE_ID(0x08, 0x000D))
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, NPC_ANIM_chuck_quizmo_Palette_00_Anim_A)
        EVT_LOOP(0)
            EVT_IS_THREAD_RUNNING(EVT_VAR(1), EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_SET(EVT_VAR(0), 0)
    EVT_END_IF
    EVT_CALL(N(Quizmo_UnkStageEffectMode), -1)
    EVT_CALL(EnablePartnerAI)
    EVT_THREAD
        EVT_WAIT_FRAMES(30)
        EVT_CALL(PlaySound, SOUND_8F)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(45)
        EVT_CALL(StopSound, SOUND_89)
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SetVannaAnim_Wave))
    EVT_CALL(N(Quizmo_DestroyEffects))
    EVT_EXEC_WAIT(N(EVS_Quizmo_Exit))
    EVT_EXEC(N(EVS_Quizmo_ResetCamera))
    EVT_CALL(N(Quizmo_FadeInWorld))
    EVT_CALL(N(Quizmo_ShowEntities))
    EVT_SET(EVT_SAVE_FLAG(1793), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_OtherAI) = {
    EVT_CALL(N(Quizmo_ShouldAppear))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_1000000, FALSE)
    EVT_CALL(SetNpcSprite, -1, 0x00AF0001)
    EVT_CALL(N(Quizmo_RenderInit))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_Interact) = {
    EVT_USE_ARRAY(EVT_PTR(N(Quizmo_ScriptArray)))
    EVT_SET(EVT_SAVE_FLAG(1769), TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerFlagBits, PLAYER_STATUS_FLAGS_400000, 1)
    EVT_EXEC_WAIT(N(EVS_Quizmo_QuizMain))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetPlayerFlagBits, PLAYER_STATUS_FLAGS_400000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_Aux) = {
    EVT_CALL(N(Quizmo_NPC_Aux_Impl))
    EVT_RETURN
    EVT_END
};

NpcAISettings N(Quizmo_NpcAISettings) = {
    .moveSpeed = 0.7f,
    .moveTime = 30,
    .waitTime = 20,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_Quizmo_Npc_AI) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(Quizmo_NpcAISettings)))
    EVT_RETURN
    EVT_END
};

// primary quizmo NpcSettings
NpcSettings N(Quizmo_NpcSettings) = {
    .unk_00 = { 0x00, 0xAF, 0x00, 0x01 },
    .height = 35,
    .radius = 28,
    .otherAI = &N(EVS_Quizmo_NPC_OtherAI),
    .onInteract = &N(EVS_Quizmo_NPC_Interact),
    .aux = &N(EVS_Quizmo_NPC_Aux),
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .level = 99,
};

// alternate (unused?) variant of quizmo with AI and NPC_FLAG_100 unset
NpcSettings N(Quizmo_AltNpcSettings) = {
    .unk_00 = { 0x00, 0xAF, 0x00, 0x01 },
    .height = 35,
    .radius = 28,
    .otherAI = &N(EVS_Quizmo_NPC_OtherAI),
    .onInteract = &N(EVS_Quizmo_NPC_Interact),
    .ai = &N(EVS_Quizmo_Npc_AI),
    .aux = &N(EVS_Quizmo_NPC_Aux),
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .level = 99,
    .unk_2A = 16,
};
