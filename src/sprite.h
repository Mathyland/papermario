#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "common.h"

typedef struct SpriteComponent {
    /* 0x00 */ s32 initialized;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16** readPos;
    /* 0x0C */ f32 waitTime;
    /* 0x10 */ s32 loopCounter;
    /* 0x14 */ s32 currentRaster;
    /* 0x18 */ s32 currentPalette;
    /* 0x1C */ Vec3f posOffset;
    /* 0x28 */ Vec3f compPos;
    /* 0x34 */ Vec3f rotation;
    /* 0x40 */ Vec3f scale;
    /* 0x4C */ s32 unk_4C;
} SpriteComponent; // size = 0x50

typedef struct PlayerCurrentAnimInfo {
    /* 0x00 */ SpriteComponent** componentList;
    /* 0x04 */ s32 animID;
    /* 0x08 */ s32 unk_08;
} PlayerCurrentAnimInfo; // size = 0xC

typedef struct SpriteAnimComponent {
    /* 0x00 */ s16** cmdList;
    /* 0x04 */ s16 cmdListSize;
    /* 0x08 */ Vec3s compOffset;
} SpriteAnimComponent; // size = 0xC

// TODO: consider moving to 101b90_len_8f0 (sprite_cache)
typedef struct SpriteRasterCacheEntry {
    /* 0x00 */ void* image;
    /* 0x04 */ u8 width;
    /* 0x05 */ u8 height;
    /* 0x06 */ u8 palette;
    /* 0x07 */ u8 quadCacheIndex;
} SpriteRasterCacheEntry; // size = 0x8

typedef struct SpriteHeader {
    /* 0x00 */ SpriteRasterCacheEntry* rasterList;
    /* 0x04 */ s16** paletteList;
    /* 0x08 */ s32 maxComponents;
    /* 0x0C */ s32 colorVariants;
    /* 0x10 */ SpriteAnimComponent* animListStart;
} SpriteHeader; // size = 0x14

typedef struct SpriteInstance {
    /* 0x00 */ s32 spriteIndex;
    /* 0x04 */ SpriteComponent** componentList;
    /* 0x08 */ s32 spriteData;
    /* 0x0C */ s32 currentAnimID;
    /* 0x10 */ s32 unk_10;
} SpriteInstance; // size = 0x14

typedef struct PlayerSpriteSet {
    /// Number of cache entries.
    /* 0x00 */ s32 cacheSize;

    /// Maximum raster size.
    /* 0x04 */ s32 rasterSize;

    /// Flags saying which rasters to load into the cache in spr_init_sprites(), with each bit corresponding to the Nth
    /// raster (with LSB = raster 0).
    /* 0x08 */ s32 initiallyLoaded;
} PlayerSpriteSet; // size = 0xC

/// Sprite data header.
typedef struct SpriteAnimData {
    /* 0x00 */ s32** rastersOffset;
    /* 0x04 */ u16** palettesOffset;
    /* 0x08 */ s32 maxComponents;
    /* 0x0C */ s32 colorVariations;
} SpriteAnimData; // size = 0x10

extern Vtx spr_defaultQuad[4];
extern Vp D_802DF3D0;
extern Vp D_802DF3E0;
extern Gfx D_802DF3F0[];
extern Gfx D_802DF428[];
extern Gfx D_802DF460[];
extern Gfx D_802DF490[];
extern f32 spr_animUpdateTimeScale;
extern PlayerSpriteSet spr_playerSpriteSets[7];

void spr_init_quad_cache(void);

Vtx* spr_get_cached_quad(s32* quadIndex);

void spr_make_quad_for_size(Vtx* quad, s32 width, s32 height);

Vtx* spr_get_quad_for_size(s32* quadIndex, s32 width, s32 height);

void spr_clear_quad_cache(void);

void spr_appendGfx_component_flat(
    Vtx* vertices,
    void* raster, void* palette,
    s32 width, s32 height,
    s32 arg5,
    Matrix4f mtx,
    s32 alpha
);

void spr_appendGfx_component(
    Vtx* vertices,
    void* raster, void* palette,
    s32 width, s32 height,
    s32 arg5,
    Matrix4f mtx,
    s32 alpha
);

void spr_transform_point(s32 rotX, s32 rotY, s32 rotZ, f32 inX, f32 inY, f32 inZ, f32* outX, f32* outY, f32* outZ);

void spr_draw_component(
    SpriteRasterCacheEntry* raster,
    f32 dx, f32 dy, f32 dz,
    f32 rotX, f32 rotY, f32 rotZ,
    f32 scaleX, f32 scaleY, f32 scaleZ,
    s32 opacity,
    void* palette,
    Matrix4f mtx
);

s32 spr_sign_extend_12bit(u16 val);

s32 spr_sign_extend_16bit(u16 val);

void spr_component_update_commands(SpriteComponent* comp, SpriteAnimComponent* anim);

void spr_component_update_finish(
    SpriteComponent* comp,
    SpriteComponent** compList,
    SpriteRasterCacheEntry* rasterCacheEntry,
    s32 overridePalette
);

// TODO: anim possibly should be SpriteComponentAnim*
void spr_init_component_anim_state(SpriteComponent* comp, s16*** anim);

void spr_init_anim_state(SpriteComponent** compList, s16** cmdList);

void spr_set_anim_timescale(f32 timeScale);

void spr_load_player_sprite(s32 spriteIndex);

SpriteAnimData* spr_load_sprite(s32, s32, s32);

void fold_init(void);

void spr_init_sprites(s32 playerSpriteSet);

void spr_render_init(void);

void spr_update_player_raster_cache(void);

s32 func_802DDA84(void);

s32 spr_update_player_sprite(s32 arg0, s32 arg1, f32 arg2);

s32 spr_draw_player_sprite(s32 arg0, s32 yaw, s32 arg2, s16** paletteList, Matrix4f mtx);

s32 func_802DDEC4(s32 arg0);

void func_802DDEE4(s32, s32, s32, s32, s32, s32, s32, s32);

void func_802DDFF8(s32, s32, s32, s32, s32, s32, s32);

void spr_get_player_raster_info(SpriteRasterInfo* out, s32 playerSpriteID, s32 rasterIndex);

u16** spr_get_player_palettes(s32 spriteIndex);

/// @param animID - Set MSB for tail allocation (i.e. `0x80XXYYZZ`)
s32 spr_load_npc_sprite(s32 animID, s32* extraAnimList);

s32 spr_update_sprite(s32 spriteInstanceID, s32 animID, f32 timeScale);

s32 spr_draw_npc_sprite(s32 spriteInstanceID, s32 yaw, s32 arg2, s16** paletteList, Matrix4f mtx);

s32 func_802DE5C8(s32 arg0);

s32 spr_free_sprite(s32 spriteInstanceID);

s32 func_802DE748(s32, s32); // TODO

s32 func_802DE780(s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_802DE894(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

//s32 func_802DE8DC(); // TODO

s32 spr_get_npc_raster_info(SpriteRasterInfo* out, s32 npcSpriteID, s32 rasterIndex);

u16** spr_get_npc_palettes(s32 npcSpriteID);

s32 spr_get_npc_color_variations(s32 npcSpriteID);

void render_shaded_sprite(Matrix4f mtx, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 alpha, s32);

#endif
