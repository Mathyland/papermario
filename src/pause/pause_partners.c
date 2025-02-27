#include "pause_common.h"
#include "sprite.h"
#include "sprite/npc/world_goombario.h"
#include "sprite/npc/world_kooper.h"
#include "sprite/npc/world_bombette.h"
#include "sprite/npc/world_parakarry.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/world_watt.h"
#include "sprite/npc/world_sushie.h"
#include "sprite/npc/world_lakilester.h"

extern s32 gPartnerPopupProperties[13][4];
extern s8 gPauseBufferPal1[512];
extern s8 gPauseBufferImg1[15752];
extern s8 gPauseBufferPal2[512];
extern s8 gPauseBufferImg2[15752];

void pause_partners_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_movelist(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_movelist_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_movelist_flower(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_init(MenuPanel* panel);
void pause_partners_handle_input(MenuPanel* panel);
void pause_partners_update(MenuPanel* panel);
void pause_partners_cleanup(MenuPanel* panel);

static s32 gPausePartnersIconIDs[8];
static s32 gPausePartnersSpriteIDs[8];
static s32 gPausePartnersPartnerIdx[8];
static s32 gPausePartnersCurrentPartnerIdx;
static s32 gPausePartnersSelectedMove;
static f32 gPausePartnersRotAngle;
static s32 gPausePartnersLevel;
static s32 gPausePartnersNumPartners;

HudScript* gPausePartnersIconScripts[] = {
    &HES_FPCost, &HES_StatFp_1, &HES_PartnerRank, &HES_PartnerRank,
    &HES_MoveDiamond, &HES_MoveBlueOrb, &HES_MoveGreenOrb, &HES_MoveRedOrb
};
Vp gPausePartnersViewport = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 },
    }
};
s32 gPausePartnersSpriteAnims[][4] = {
    {
        NPC_ANIM_world_goombario_normal_still,
        NPC_ANIM_world_goombario_normal_walk,
        NPC_ANIM_world_goombario_normal_talk,
        ANIM_END
    },
    {
        NPC_ANIM_world_kooper_normal_still,
        NPC_ANIM_world_kooper_normal_walk,
        NPC_ANIM_world_kooper_normal_talk,
        ANIM_END
    },
    {
        NPC_ANIM_world_bombette_normal_still,
        NPC_ANIM_world_bombette_normal_walk,
        NPC_ANIM_world_bombette_normal_idle_fast,
        ANIM_END
    },
    {
        NPC_ANIM_world_parakarry_Palette_00_Anim_0,
        NPC_ANIM_world_parakarry_Palette_00_Anim_2,
        NPC_ANIM_world_parakarry_Palette_00_Anim_6,
        ANIM_END
    },
    {
        NPC_ANIM_world_bow_Palette_00_Anim_0,
        NPC_ANIM_world_bow_Palette_00_Anim_2,
        NPC_ANIM_world_bow_Palette_00_Anim_4,
        ANIM_END
    },
    {
        NPC_ANIM_world_watt_Palette_00_Anim_0,
        NPC_ANIM_world_watt_Palette_00_Anim_2,
        NPC_ANIM_world_watt_Palette_00_Anim_4,
        ANIM_END
    },
    {
        NPC_ANIM_world_sushie_Palette_00_Anim_0,
        NPC_ANIM_world_sushie_Palette_00_Anim_2,
        NPC_ANIM_world_sushie_Palette_00_Anim_4,
        ANIM_END
    },
    {
        NPC_ANIM_world_lakilester_Palette_00_Anim_0,
        NPC_ANIM_world_lakilester_Palette_00_Anim_5,
        NPC_ANIM_world_lakilester_Palette_00_Anim_9,
        ANIM_END
    }
};
s32 gPausePartnersPartnerIDs[] = { 1, 2, 3, 4, 9, 6, 7, 8};
s32 gPausePartnersMessages[] = {
    MESSAGE_ID(0x28, 0x6), MESSAGE_ID(0x28, 0x13), MESSAGE_ID(0x28, 0x20), MESSAGE_ID(0x28, 0x2D),
    MESSAGE_ID(0x28, 0x3A), MESSAGE_ID(0x28, 0x47), MESSAGE_ID(0x28, 0x54), MESSAGE_ID(0x28, 0x61)
};
s32 gPausePartnersMoveBase[] = { MOVE_HEADBONK1, MOVE_SHELL_TOSS1, MOVE_BODY_SLAM1, MOVE_SKY_DIVE1,
                                 MOVE_SMACK1, MOVE_ELECTRO_DASH1, MOVE_BELLY_FLOP1, MOVE_SPINY_FLIP1 };
s8 gPausePartnersGridData[] = {
    4, 5, 6, 7,
    0, 1, 2, 3
};
char* gPausePartnersAssetNames[] = { "party_kurio", "party_kameki", "party_pinki", "party_pareta", "party_resa",  "party_akari", "party_opuku", "party_pokopi", "letter_peach" };
s8* gPausePartnersImageBuffers[] = { gPauseBufferImg1, gPauseBufferImg2 };
s8* gPausePartnersPaletteBuffers[] = { gPauseBufferPal1, gPauseBufferPal2 };
s32 D_8024F74C = 0;
Gfx gPausePartnersDL[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, 1, 0, 0, 0, TEXEL0, 0, 0, 0, 1),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList()
};
s32 gPausePartnersCurrentPortraitIndex = -1;
s32 gPausePartnersNextPortraitIndex = -1;
MenuWindowBP gPausePartnersWindowBPs[] = {
    {
        .windowID = WINDOW_ID_PAUSE_PARTNERS,
        .unk_01 = 0,
        .pos = { .x = 3, .y = 16 },
        .width = 289,
        .height = 154,
        .priority = 1,
        .fpDrawContents = &pause_partners_draw_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_20 }
    }, {
        .windowID = WINDOW_ID_PAUSE_PARTNERS_TITLE,
        .unk_01 = 0,
        .pos = { .x = 8, .y = 103 },
        .width = 112,
        .height = 20,
        .priority = 0,
        .fpDrawContents = &pause_partners_draw_title,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_PARTNERS,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_22 }
    }, {
        .windowID = WINDOW_ID_PAUSE_PARTNERS_MOVELIST,
        .unk_01 = 0,
        .pos = { .x = 133, .y = 36 },
        .width = 140,
        .height = 80,
        .priority = 0,
        .fpDrawContents = &pause_partners_draw_movelist,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_PARTNERS,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { -1 }
    }, {
        .windowID = WINDOW_ID_PAUSE_PARTNERS_MOVELIST_TITLE,
        .unk_01 = 0,
        .pos = { .x = 12, .y = -6 },
        .width = 80,
        .height = 16,
        .priority = 0,
        .fpDrawContents = &pause_partners_draw_movelist_title,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_PARTNERS_MOVELIST,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { -1 }
    }, {
        .windowID = WINDOW_ID_PAUSE_PARTNERS_MOVELIST_FLOWER,
        .unk_01 = 0,
        .pos = { .x = 102, .y = -12 },
        .width = 32,
        .height = 32,
        .priority = 0,
        .fpDrawContents = &pause_partners_draw_movelist_flower,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_PARTNERS_MOVELIST,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { -1 }
    }
};
u8 gPausePartnersPortraitScrollInterpTable[] = {0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8 };
MenuPanel gPausePanelPartners = {
    .initialized = FALSE,
    .col = 0,
    .row = 1,
    .selected = 0,
    .page = 0,
    .numCols = 4,
    .numRows = 2,
    .numPages = 0,
    .gridData = gPausePartnersGridData,
    .fpInit = &pause_partners_init,
    .fpHandleInput = &pause_partners_handle_input,
    .fpUpdate = &pause_partners_update,
    .fpCleanup = &pause_partners_cleanup
};

typedef struct PartnerPosition {
    /* 0x00 */ f32 pos;
    /* 0x04 */ s32 index;
} PartnerPosition; // size = 0x8

void pause_partners_load_portrait(s32 index) {
    s32 size;
    void* asset;

    if (gPausePartnersCurrentPortraitIndex != gPausePartnersPartnerIdx[index]) {
        gPausePartnersCurrentPortraitIndex = gPausePartnersPartnerIdx[index];
        asset = load_asset_by_name(gPausePartnersAssetNames[gPausePartnersCurrentPortraitIndex], &size);
        decode_yay0(asset, gPausePartnersPaletteBuffers[0]);
        general_heap_free(asset);
    }

    if (gPausePartnersNextPortraitIndex != gPausePartnersPartnerIdx[(index + 1) % gPausePartnersNumPartners]) {
        gPausePartnersNextPortraitIndex = gPausePartnersPartnerIdx[(index + 1) % gPausePartnersNumPartners];
        asset = load_asset_by_name(gPausePartnersAssetNames[gPausePartnersNextPortraitIndex], &size);
        decode_yay0(asset, gPausePartnersPaletteBuffers[1]);
        general_heap_free(asset);
    }
}

void pause_partners_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    Matrix4f matrix;
    Matrix4f matrix2;
    PartnerPosition partnerPositions[8];
    s32 i, j, k, index;
    s32 x1, y1, x2, y2;
    f32 currentPos, angle, scale;
    f32 offsetX, offsetY, offsetZ;
    s32 a2;
    s8 currentTab;
    s32 portraitScrollPos;
    s32 portraitScrollIndex;
    s32 tileHeight;
    s32 portraitOffsetX;
    s32 portraitIndex;

    gSPViewport(gMasterGfxPos++, &gPausePartnersViewport);
    guOrthoF(matrix, 0.0f, 320.0f, 240.0f, 0.0f, -100.0f, 100.0f, 1.0f);
    guMtxF2L(matrix, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    guTranslateF(matrix, 0.0f, 0.0f, 0.0f);
    guMtxF2L(matrix, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    for (i = 0; i < gPausePartnersNumPartners; i++) {
        currentPos = cos_deg(i * 360 / gPausePartnersNumPartners - gPausePartnersRotAngle) * 20.0f + 0.0f;

        for (j = 0; j < i; j++) {
            if (currentPos < partnerPositions[j].pos) {
                break;
            }
        }

        for (k = gPausePartnersNumPartners - 1; k > j; k--) {
            partnerPositions[k] = partnerPositions[k-1];
        }

        partnerPositions[j].index = i;
        partnerPositions[j].pos = currentPos;
    }

    for (j = 0; j < gPausePartnersNumPartners; j++) {
        portraitIndex = gPausePartnersNumPartners;
        index = partnerPositions[j].index;
        angle = index * 360 / gPausePartnersNumPartners - gPausePartnersRotAngle;
        offsetX = gPausePartnersNumPartners * 3 + 17;
        offsetX *= sin_deg(angle);
        offsetX += 42.0f;
        offsetZ = 30.0f - cos_deg(angle) * 30.0f;
        offsetY = cos_deg(angle) * 20.0f + 0.0f;
        scale = 30.0 / (offsetZ + 60.0f) + 0.5;

        guTranslateF(matrix, baseX + 22 + offsetX, baseY + 81 + offsetY, -offsetZ);
        guRotateF(matrix2, 180.0f, 0.0f, 0.0f, 1.0f);
        guMtxCatF(matrix2, matrix, matrix);
        guScaleF(matrix2, scale, scale, 1.0f);
        guMtxCatF(matrix2, matrix, matrix);

        if (offsetZ > 8.0f) {
            a2 = 160;
        } else {
            a2 = 255.0f - offsetZ * 95.0f * 0.125f;
        }
        func_802DE894(gPausePartnersSpriteIDs[gPausePartnersPartnerIdx[index]], 6, a2, a2, a2, 0xFF, 0x40);
        spr_draw_npc_sprite(gPausePartnersSpriteIDs[gPausePartnersPartnerIdx[index]], 0, 0, NULL, matrix);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

    currentTab = gPauseMenuCurrentTab;
    if (currentTab == 4) {
        if (gPausePartnersLevel == 0) {
            pause_set_cursor_pos(WINDOW_ID_PAUSE_PARTNERS, baseX + 42, baseY + 88);
        }

        if (gPauseMenuCurrentTab == currentTab && gPausePartnersLevel == 0) {
            pause_draw_menu_label(8, 18, 158);
        }
    }

    x1 = baseX + 130;
    y1 = baseY + 24;
    x2 = baseX + 280;
    y2 = baseY + 129;

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= SCREEN_WIDTH - 1 || y1 >= SCREEN_HEIGHT - 1) {
        return;
    }

    if (x2 >= SCREEN_WIDTH - 1) {
        x2 = SCREEN_WIDTH - 1;
    }
    if (y2 >= SCREEN_HEIGHT - 1) {
        y2 = SCREEN_HEIGHT - 1;
    }

    portraitScrollPos = (gPausePartnersRotAngle + 360.0f) * 15000.0f * gPausePartnersNumPartners / 360.0f;
    portraitScrollIndex = portraitScrollPos / 15000;
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);
    portraitOffsetX = (portraitScrollIndex * 15000 - portraitScrollPos);
    portraitOffsetX *= 0.01;
    portraitIndex = portraitScrollIndex;
    pause_partners_load_portrait(portraitIndex % gPausePartnersNumPartners);
    for (i = 0; i < 2; portraitOffsetX += 150, i++) {
        gSPDisplayList(gMasterGfxPos++, &gPausePartnersDL);
        gDPLoadTLUT_pal256(gMasterGfxPos++, gPausePartnersPaletteBuffers[i]);

        for (index = 0; index < 20; index++) {
            if (12 * index + 12 <= 105) {
                tileHeight = 12;
            } else {
                tileHeight = 106 - 12 * index;
            }

            gDPLoadTextureTile(gMasterGfxPos++, gPausePartnersImageBuffers[i], G_IM_FMT_CI, G_IM_SIZ_8b, 150, 0,
                                0, 12 * index, 149, 12 * index + tileHeight - 1, 0,
                                G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            pause_draw_rect((baseX + 130 + portraitOffsetX) * 4, (baseY + 24 + 12 * index) * 4, (baseX + 280 + portraitOffsetX) * 4, (baseY + 24 + 12 * index + tileHeight) * 4, 0, 0,
                            12 * index * 32, 0x400, 0x400);
            gDPPipeSync(gMasterGfxPos++);
            if (12 * index + 12 >= 105) {
                break;
            }
        }
    }
    {
        s32 x1, y1, x2, y2;
        x1 = baseX + 122;
        y1 = baseY + 16;
        x2 = baseX + 288;
        y2 = baseY + 137;

        if (x1 <= 0) {
            x1 = 1;
        }
        if (y1 <= 0) {
            y1 = 1;
        }

        if (x2 <= 0 || y2 <= 0 || x1 >= SCREEN_WIDTH - 1 || y1 >= SCREEN_HEIGHT - 1) {
            return;
        }

        if (x2 >= SCREEN_WIDTH - 1) {
            x2 = SCREEN_WIDTH - 1;
        }
        if (y2 >= SCREEN_HEIGHT - 1) {
            y2 = SCREEN_HEIGHT - 1;
        }

        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);
    }
    draw_box(0, &gPauseWS_21, baseX + 122, baseY + 16, 0, 166, 121, opacity, darkening, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, width, height, 0);
}

void pause_partners_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 msgID = gPartnerPopupProperties[gPausePartnersPartnerIDs[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]]][0];
    s32 level = get_player_data()->partners[gPausePartnersPartnerIDs[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]]].level;
    s32 msgWidth = get_msg_width(msgID, 0);
    s32 offset = 16;

    if (level != 1) {
        offset = 0;
        if (level == 2) {
            offset = 20;
        }
    }

    if (offset != 0) {
        msgWidth += 4;
    }

    draw_msg(msgID, baseX + ((width - offset - msgWidth) >> 1), baseY + 1, 255, 0, 0);

    if (level == 1) {
        hud_element_set_render_pos(gPausePartnersIconIDs[2], baseX + 95, baseY + 10);
        hud_element_draw_without_clipping(gPausePartnersIconIDs[2]);
    } else if (level == 2) {
        hud_element_set_render_pos(gPausePartnersIconIDs[2], baseX + 91, baseY + 10);
        hud_element_draw_without_clipping(gPausePartnersIconIDs[2]);
        hud_element_set_render_pos(gPausePartnersIconIDs[3], baseX + 101, baseY + 10);
        hud_element_draw_without_clipping(gPausePartnersIconIDs[3]);
    }
}

void pause_partners_draw_movelist(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 i;
    s32 moveNameID;
    s32 costFP;
    s32 msgX, msgY;
    s32 style;
    s32 level = get_player_data()->partners[gPausePartnersPartnerIDs[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]]].level;


    if (level == 2) {
        level = 4;
    } else if (level == 1) {
        level = 3;
    } else if (level == 0) {
        level = 2;
    }
    for (i = 0; i < 4; i++) {
        msgX = baseX + 21;
        msgY = baseY + 22 + i * 13;

        if (i >= level) {
            continue;
        }

        style = 1;

        if (i == 0) {
            moveNameID = gMoveTable[gPausePartnersMoveBase[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]]].nameMsg;
        } else {
            moveNameID =  gMoveTable[gPausePartnersMoveBase[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]] + 2 + i].nameMsg;
        }

        if (i > 0) {
            costFP = gMoveTable[gPausePartnersMoveBase[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]] + 2 + i].costFP;
        } else {
            costFP = 0;
        }

        draw_msg(moveNameID, msgX, msgY, 255, 10, style);
        hud_element_set_scale(gPausePartnersIconIDs[i + 4], 0.5f);
        //TODO find better match
        hud_element_set_render_pos(gPausePartnersIconIDs[i + 4], 12 - (-baseX), baseY + 28 + i * 13);
        hud_element_draw_without_clipping(gPausePartnersIconIDs[i + 4]);

        if (costFP != 0) {
            draw_number(costFP, baseX + 125, baseY + 22 + i * 13, style, 10, 255, 3);
            if (costFP > 0) {
                hud_element_set_render_pos(gPausePartnersIconIDs[0], baseX + 134, baseY + 29 + i * 13);
                hud_element_draw_without_clipping(gPausePartnersIconIDs[0]);
            }
        }
    }

    if (gPauseMenuCurrentTab == 4 && gPausePartnersLevel == 1) {
        pause_set_cursor_pos(WINDOW_ID_PAUSE_PARTNERS_MOVELIST, baseX - 2, baseY + 28 + gPausePartnersSelectedMove * 13);
    }
}

void pause_partners_draw_movelist_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    draw_msg(pause_get_menu_msg(0x55), baseX + 12, baseY + 1, 255, -1, 1);
}

void pause_partners_draw_movelist_flower(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    hud_element_set_render_pos(gPausePartnersIconIDs[1], baseX + 17, baseY + 16);
    hud_element_draw_without_clipping(gPausePartnersIconIDs[1]);
}

void pause_partners_init(MenuPanel* panel) {
    s32 i;
    PlayerData* playerData = get_player_data();

    gPausePartnersNumPartners = 0;
    for (i = 0; i < ARRAY_COUNT(gPausePartnersPartnerIDs); i++) {
        if (playerData->partners[gPausePartnersPartnerIDs[i]].enabled) {
            gPausePartnersPartnerIdx[gPausePartnersNumPartners] = i;
            gPausePartnersNumPartners++;
        }
    }

    if (gPausePartnersNumPartners == 0) {
        set_window_update(WINDOW_ID_PAUSE_PARTNERS, WINDOW_UPDATE_HIDE);
        panel->initialized = FALSE;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gPausePartnersSpriteAnims); i++) {
        gPausePartnersSpriteIDs[i] = spr_load_npc_sprite(gPausePartnersSpriteAnims[i][0], gPausePartnersSpriteAnims[i]);
    }

    for (i = 0; i < ARRAY_COUNT(gPausePartnersIconScripts); i++) {
        gPausePartnersIconIDs[i] = hud_element_create(gPausePartnersIconScripts[i]);
        hud_element_set_flags(gPausePartnersIconIDs[i], HUD_ELEMENT_FLAGS_80);
    }

    for (i = 0; i < ARRAY_COUNT(gPausePartnersWindowBPs); i++) {
        gPausePartnersWindowBPs[i].tab = panel;
    }
    setup_pause_menu_tab(gPausePartnersWindowBPs, ARRAY_COUNT(gPausePartnersWindowBPs));

    gPausePartnersCurrentPartnerIdx = 0;
    for (i = 0; i < gPausePartnersNumPartners; i++) {
        if (playerData->currentPartner == gPausePartnersPartnerIDs[gPausePartnersPartnerIdx[i]]) {
            gPausePartnersCurrentPartnerIdx = i;
            break;
        }
    }

    gPausePartnersSelectedMove = 0;
    gPausePartnersLevel = 0;
    gPausePartnersRotAngle = gPausePartnersCurrentPartnerIdx * 360 / gPausePartnersNumPartners;
    pause_partners_load_portrait(0);
    panel->initialized = TRUE;
}

void pause_partners_handle_input(MenuPanel* panel) {
    s32 delta;
    s32 level, level2;
    s32 oldPos;

    if (gPausePartnersNumPartners >= 2 && (gPausePartnersLevel == 0 || (gPauseHeldButtons & (BUTTON_Z | BUTTON_R)))) {
        delta = 0;

        if (gPauseHeldButtons & BUTTON_STICK_LEFT) {
            delta = -1;
        }

        if (gPauseHeldButtons & BUTTON_STICK_RIGHT) {
            delta++;
        }

        if (gPauseHeldButtons & BUTTON_Z) {
            delta--;
        }

        if (gPauseHeldButtons & BUTTON_R) {
            delta++;
        }

        if (delta) {
            sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
            gPausePartnersCurrentPartnerIdx += delta;

            if (gPausePartnersCurrentPartnerIdx < 0) {
                gPausePartnersCurrentPartnerIdx = gPausePartnersNumPartners - 1;
                if (gPausePartnersRotAngle < 360.0f) {
                    gPausePartnersRotAngle += 360.0f;
                }
            } else if (gPausePartnersCurrentPartnerIdx >= gPausePartnersNumPartners) {
                gPausePartnersCurrentPartnerIdx = 0;
                if (gPausePartnersRotAngle > 0.0f) {
                    gPausePartnersRotAngle -= 360.0f;
                }
            }

            gPausePartnersSelectedMove = 0;
        }
    }

    level = get_player_data()->partners[gPausePartnersPartnerIDs[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]]].level;
    if (level == 2) {
        level = 4;
    } else if (level == 1) {
        level = 3;
    } else if (level == 0) {
        level = 2;
    }

    gWindows[WINDOW_ID_PAUSE_PARTNERS_MOVELIST].height = level * 13 + 30;

    if (gPausePartnersLevel == 1) {
        oldPos = gPausePartnersSelectedMove;

        level2 = get_player_data()->partners[gPausePartnersPartnerIDs[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]]].level;
        if (level2 == 2) {
            level2 = 4;
        } else if (level2 == 1) {
            level2 = 3;
        } else if (level2 == 0) {
            level2 = 2;
        }

        if (gPauseHeldButtons & BUTTON_STICK_UP) {
            gPausePartnersSelectedMove--;
        }
        if (gPauseHeldButtons & BUTTON_STICK_DOWN) {
            gPausePartnersSelectedMove++;
        }

        if (gPausePartnersSelectedMove < 0) {
            gPausePartnersSelectedMove = level2 - 1;
        } else if (gPausePartnersSelectedMove >= level2) {
            gPausePartnersSelectedMove = 0;
        }

        if (gPausePartnersSelectedMove != oldPos) {
            sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
        }
    }

    if ((gPausePressedButtons & BUTTON_A) && gPausePartnersLevel == 0) {
        gPausePartnersLevel = 1;
        sfx_play_sound(SOUND_MENU_NEXT);
        set_window_update(WINDOW_ID_PAUSE_PARTNERS_MOVELIST, WINDOW_UPDATE_SHOW);
        return;
    }

    if (gPausePressedButtons & BUTTON_B) {
        if (gPausePartnersLevel == 0) {
            gPauseMenuCurrentTab = 0;
            sfx_play_sound(SOUND_MENU_BACK);
            return;
        } else {
            gPausePartnersLevel = 0;
            sfx_play_sound(SOUND_MENU_BACK);
            set_window_update(WINDOW_ID_PAUSE_PARTNERS_MOVELIST, WINDOW_UPDATE_HIDE);
            return;
        }
    }

    gPauseCurrentDescIconScript = 0;

    if (gPausePartnersLevel == 0) {
        gPauseCurrentDescMsg = gPausePartnersMessages[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]];
    } else if (gPausePartnersSelectedMove == 0) {
        gPauseCurrentDescMsg = gMoveTable[gPausePartnersMoveBase[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]]].fullDescMsg;
    } else {
        gPauseCurrentDescMsg = gMoveTable[gPausePartnersMoveBase[gPausePartnersPartnerIdx[gPausePartnersCurrentPartnerIdx]] + 2 + gPausePartnersSelectedMove].fullDescMsg;
    }
}

void pause_partners_update(MenuPanel* panel) {
    s32 i;
    f32 delta;
    s32 absValue;
    f32 deltaBefore;
    s32 sgn;

    deltaBefore = gPausePartnersCurrentPartnerIdx * 360 / gPausePartnersNumPartners - gPausePartnersRotAngle;
    absValue = abs(deltaBefore);
    sgn = sign(deltaBefore);

    if (absValue >= 16) {
        delta = deltaBefore * 0.3;
    } else {
        delta = sgn * gPausePartnersPortraitScrollInterpTable[absValue];
        gPausePartnersRotAngle = (int)gPausePartnersRotAngle;
    }
    gPausePartnersRotAngle += delta;

    for (i = 0; i < gPausePartnersNumPartners; i++) {
        if (i == gPausePartnersCurrentPartnerIdx) {
            spr_update_sprite(gPausePartnersSpriteIDs[gPausePartnersPartnerIdx[i]], gPausePartnersSpriteAnims[gPausePartnersPartnerIdx[i]][1], 1.0f);
        } else {
            spr_update_sprite(gPausePartnersSpriteIDs[gPausePartnersPartnerIdx[i]], gPausePartnersSpriteAnims[gPausePartnersPartnerIdx[i]][0], 1.0f);
        }
    }
}

void pause_partners_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPausePartnersIconIDs); i++) {
        hud_element_free(gPausePartnersIconIDs[i]);
    }

    for (i = 0; i < ARRAY_COUNT(gPausePartnersSpriteIDs); i++) {
        spr_free_sprite(gPausePartnersSpriteIDs[i]);
    }
}
