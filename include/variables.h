#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "common_structs.h"
#include "types.h"
#include "macros.h"
#include "enums.h"

extern PlayerStatus* gPlayerStatusPtr;
extern CollisionStatus gCollisionStatus;
extern GameStatus gGameStatus;
extern GameStatus* gGameStatusPtr;
extern s32 gRandSeed;
extern ItemData gItemTable[365];
extern UNK_FUN_PTR(gCurrentUpdateFunction);
extern MoveData gMoveTable[185];

extern s32 gBattleState;
extern BattleStatus gBattleStatus;
extern s32 D_800DC4D0;
extern s32 D_800DC4D4;
extern s32 D_800DC4D8;
extern s32 gBattleState2;
extern s32 D_800DC4E4;
extern s32 D_800DC4E8;
extern u8 gCurrentBattleSection; // in the middle of the previous var
extern u8 D_800DC4EB; // in the middle of the previous var
extern s32 D_800DC4E0;
extern s32 D_800DC4EC;
extern s32 D_800DC4F0;
extern s32 D_800DC4F4;
extern s32 D_800DC4F8;
extern s32 gBattleDmaDest;

extern ActionCommandStatus gActionCommandStatus;

extern ScriptList gWorldScriptList;
extern ScriptList gBattleScriptList;
extern ScriptList* gCurrentScriptListPtr;

extern s32 gNumScripts;
extern s32 D_802DAC98;

extern s32 gScriptListCount;

extern s32 gScriptIdList[MAX_SCRIPTS];
extern s32 gScriptIndexList[MAX_SCRIPTS];

extern s32 gMoveScriptTable[][4];

extern EntityList gWorldEntityList;
extern EntityList gBattleEntityList;
extern EntityList* gCurrentEntityListPtr;

extern DynamicEntityList gWorldDynamicEntityList;
extern DynamicEntityList gBattleDynamicEntityList;
extern DynamicEntityList* gCurrentDynamicEntityListPtr;

extern NpcList gWorldNpcList;
extern NpcList gBattleNpcList;
extern NpcList* gCurrentNpcListPtr;

extern ShadowList gWorldShadowList;
extern ShadowList gBattleShadowList;
extern ShadowList* gCurrentShadowListPtr;

extern Camera gCameras[4];
extern s32 gCurrentCameraID;

extern CollisionData gCollisionData;

extern s8 D_800A0900;
extern f32 GravityParamsStartFall[];
extern s16 D_800F7B80;
extern u8* D_801512F0;
extern s16 D_80151308;
extern s32 gEntityHideMode;

extern s32 D_8010C92C;
extern s32 D_8010C950;
extern s32 D_801595A0;
extern Struct8015A578 D_8015A578;

extern BackgroundHeader gBackgroundImage;

extern MessagePrintState* gCurrentPrintContext;
extern s32 D_802DB264;
extern MessagePrintState* D_802DB268;

extern ShadowBlueprint CircularShadowA;
extern ShadowBlueprint CircularShadowB;
extern ShadowBlueprint SquareShadow;
extern s32 SaveBlockTutorialPrinterClosed;
extern s32 SaveBlockResultPrinterClosed;
extern MessagePrintState* SaveBlockTutorialPrinter;
extern MessagePrintState* SaveBlockResultPrinter;
extern s32 D_802E99DC;

extern Entity* SwitchToLink;
extern s32 CreateEntityVarArgBuffer[4];

extern f32 DefaultMoveSpeeds[4];

extern CollisionData gZoneCollisionData;

// Animation related
extern AnimatedMeshList* gCurrentAnimMeshListPtr;

extern PartnerAnimations gPartnerAnimations[12];

extern AnimatedModelList gBattleMeshAnimationList;
extern AnimatedModelList gWorldMeshAnimationList;
extern AnimatedModelList* gCurrentMeshAnimationListPtr;

// Triggers
extern s16 gTriggerCount;
extern TriggerList wTriggerList;
extern TriggerList bTriggerList;
extern TriggerList* gCurrentTriggerListPtr;

// Map transition data. Should probably be a struct
extern s16 gMapTransitionAlpha;
extern s8 D_800A0930;
extern s8 D_800A0931;
extern s16 D_800A0932[1];
extern s16 D_800A0942;
extern s16 D_800A0944;
extern s16 D_800A0946;
extern s16 D_800A0948;
extern s16 D_800A0954;
extern s16 D_800A0956;
extern s16 D_800A0958;
extern s16 D_800A095A;
extern u8 D_800A095B;
extern s16 D_800A095C;
extern u8 D_800A095D;
extern s16 D_800A095E;
extern u8 D_800A095F;
extern s32 D_800A0960;
extern s32 D_800A0964;
extern s8 D_800A0B94;
extern s16 D_800A0BB8;

extern SpriteShadingProfile* D_801512B0;
extern SpriteShadingProfile* D_80151328;

extern Window gWindows[64];

extern s32 D_802A3838;

extern s32 gGameState;
extern s16 gNpcCount;
extern s32 gOverrideFlags;
extern s16 D_8009A6A0;
extern s16 D_8009A6A2;
extern s16 D_8009A6A4;
extern s16 D_8009A6A6;

extern s8 D_800A0920;
extern s32 D_800A0924;
extern s8 D_800A0921;
extern s16 D_800A0922;
extern s32 wMapTexName;
extern char* wMapHitName;
extern s32 wMapShapeName;
extern s32* D_80210000;
extern u8 D_802D9D70; // player alpha1 copy?
extern u8 D_802D9D71; // player alpha2 copy?

extern DisplayContext D_80164000[];

extern WindowStyle gWindowStyles[];

extern MessagePrintState gMessagePrinters[3];

extern f32 gCurtainScale;
extern f32 gCurtainScaleGoal;
extern f32 gCurtainFade;
extern f32 gCurtainFadeGoal;
extern UNK_FUN_PTR(gCurtainDrawCallback);

extern s16 gCurrentDoorSoundsSet;

extern s32 D_800D9620;
extern UNK_TYPE D_800E92D8;
extern UNK_TYPE D_80147574;
extern s8 D_8014C248[];

extern UNK_FUN_PTR(D_8010C920);
extern UNK_FUN_PTR(D_8010C940);
extern Entity* TweesterTouchingPartner;
extern UNK_FUN_PTR(D_8010C958);
extern s32 D_8010C95C;
extern s32 D_8010C96C;
extern s32 D_8010C980;
extern s32 D_8010C9A0;
extern s32 D_800F7B40;
extern s32 D_800F7B44;
extern f32 D_8010C938;
extern f32 D_8010C990;
extern s32 D_8010C978;
extern Vec3s btl_actorHomePositions[];


extern SaveData gCurrentSaveFile;

extern u32* gMapFlags;
extern s32* gMapVars;

extern f32 D_80286540;

extern u32 gWorldMapVars[MAX_MAPVARS];
extern u32 gBattleMapVars[MAX_MAPVARS];

extern u32 gWorldMapFlags[MAX_MAPFLAGS];
extern u32 gBattleMapFlags[MAX_MAPFLAGS];

extern s32 D_8009A5D0;
extern s32 timeFreezeMode;
extern s32 D_8009A678;

extern u8 D_800779B0;
extern u32 D_80078174;
extern u8 D_800A0963;

extern struct EffectInstance* TriggerBlockVanishEffect;
extern UNK_TYPE D_00000094;
extern UNK_TYPE D_00000094_2; // two symbols resolve to the same addr. Required for matching
extern EntityBlueprint Entity_InertRedBlock;
extern EntityBlueprint Entity_InertYellowBlock;
extern UNK_TYPE D_802EA310;
extern EntityBlueprint Entity_HitGroundedYellowBlock;
extern EntityBlueprint Entity_HitFloatingYellowBlock;
extern EntityBlueprint Entity_HitRedBlock;

extern UNK_TYPE D_0A000328;
extern UNK_TYPE D_0A000380;
extern UNK_TYPE D_0A000750;
extern UNK_TYPE D_0A000800;
extern UNK_TYPE D_0A000808;

// Scripts
extern EvtScript SCRIPT_NpcDefeat;
extern EvtScript ShakeCam1;
extern EvtScript ShakeCamX;

extern s16 gMusicUnkVolume;
extern s16 gMusicUnkVolume2;
extern s16 gMusicCurrentVolume;
extern s16 gMusicTargetVolume;
extern MusicSettings gMusicSettings[4];
extern MusicSettings D_8014F6F0;

// OS
extern OSThread D_800A4270; // idle thread, id 1
extern OSThread D_800A4420; // id 3
extern OSDevMgr __osPiDevMgr;

// gfx
extern DisplayContext* gDisplayContext;
extern Gfx* gMasterGfxPos;
extern u16 gMatrixListPos;
extern s32 gCurrentDisplayContextIndex;

extern UNK_TYPE D_0A004350;
extern UNK_TYPE D_0A0026F0;
extern u32* D_802EAE7C;

extern s32 D_80291FA8[];
extern s32 D_80291FD0[];
extern s32 D_80291FF8[];
extern s32 D_80292020[];
extern s32 D_80292048[];
extern s32 D_80292070[];
extern s32 D_80292098[];
extern s32 D_802920C0[];
extern s32 D_802920E8[];
extern s32 D_80292110[];

extern s32 D_8029FBD0;

extern s32 KoopatrolDisguiseExtraAnims[];
extern s32 HammerBroDisguiseExtraAnims[];

//various
extern s32 D_802C05CC;

extern s16 gCurrentCamID;

extern HeapNode gSpriteHeapPtr;

extern s32 D_8029C890[10][5];

// Heap?
extern s32 D_8038F800;
extern s32 D_803B5000;

extern HeapNode heap_collisionHead;
extern HeapNode heap_generalHead;
extern HeapNode heap_battleHead;

extern u32 bMarioIdleAnims[];
extern s32 bMarioDefendAnims[];
extern s32 bPeachIdleAnims[];

// TODO: name these entity symbols
extern EntityBlueprint Entity_SavePoint; // entitySaveBlock
extern EntityBlueprint Entity_RedSwitch;
extern EntityBlueprint Entity_BlueSwitch; // entityBlueSwitch
extern EntityBlueprint Entity_HugeBlueSwitch; // entityHugeBlueSwitch
extern EntityBlueprint Entity_GreenStompSwitch;
extern EntityBlueprint Entity_ShatteringHammer1Block;
extern EntityBlueprint Entity_ShatteringHammer2Block;
extern EntityBlueprint Entity_ShatteringHammer3Block;
extern EntityBlueprint Entity_ShatteringHammer1BlockTiny;
extern EntityBlueprint Entity_ShatteringHammer2BlockTiny;
extern EntityBlueprint Entity_ShatteringHammer3BlockTiny;
extern EntityBlueprint Entity_ShatteringBrickBlock;
extern EntityBlueprint Entity_D_802EA2E0;
extern EntityBlueprint Entity_D_802EA564;
extern EntityBlueprint Entity_D_802EA0E8;
extern EntityBlueprint Entity_D_802EA10C;
extern EntityBlueprint Entity_D_802EA130;
extern EntityBlueprint Entity_D_802EA154;
extern EntityBlueprint Entity_D_802EA178;
extern EntityBlueprint Entity_D_802EA19C;
extern EntityBlueprint Entity_D_802EA588;
extern EntityBlueprint Entity_D_802EA5AC;
extern EntityBlueprint Entity_D_802EA5D0; //unused
extern EntityBlueprint Entity_D_802EA798; //unused
extern EntityBlueprint Entity_HeartBlock; //unused
extern EntityBlueprint Entity_D_802EAA30;
extern EntityBlueprint Entity_D_802EAA54;
extern EntityBlueprint Entity_D_802EA910;


extern s32 D_802EBFF0[];
extern s32 D_802EC010[];
extern s32 D_802EC030[];
extern s32 D_802EC050[];
extern s32 D_802EC070[];
extern s32 D_802EC090[];
extern s32 D_802EC0B0[];
extern s32 D_802EC0D0[];
extern s32 D_802EC0F0[];
extern s32 D_802EC110[];
extern s32 D_802EC130[];
extern s32 D_802EC150[];
extern s32 D_802EC170[];
extern s32 D_802EC190[];
extern s32 D_802EC1B0[];
extern s32 D_802EC1D0[];
extern s32 D_802EC1F0[];
extern s32 D_802EC210[];
extern s32 D_802EC230[];
extern s32 D_802EC250[];
extern s32 D_802EC270[];
extern s32 D_802EC290[];
extern s32 D_802EC2B0[];
extern s32 D_802EC2D0[];
extern s32 D_802EC2F0[];
extern s32 D_802EC310[];
extern s32 D_802EC330[];
extern s32 D_802EC350[];
extern s32 D_802EC370[];
extern s32 D_802EC390[];
extern s32 D_802EC3B0[];
extern s32 D_802EC3D0[];

extern PartnerActionStatus gPartnerActionStatus; // something with partners
extern UiStatus gUIStatus;
extern PlayerStatus gPlayerStatus;
extern PlayerSpinState gPlayerSpinState;
extern PlayerData gPlayerData;

#endif
