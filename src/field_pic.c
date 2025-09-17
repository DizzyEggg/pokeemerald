#include "global.h"
#include "event_data.h"
#include "field_pic.h"
#include "decompress.h"
#include "window.h"
#include "main.h"
#include "palette.h"
#include "script.h"
#include "text_window.h"
#include "menu.h"
#include "sprite.h"
#include "field_message_box.h"
#include "constants/field_pic.h"

#define TAG_PIC 0x3333

struct Pic
{
    const u32 *gfx;
    const u16 *pal;
    u8 shape;
    u8 size;
    const union AnimCmd *const *anims;
    SpriteCallback callback;
};

// These are example entries.
static const union AnimCmd sAnimCmdLoop[] =
{
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(64, 50),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimsLoop[] =
{
    sAnimCmdLoop
};

static const union AnimCmd sAnimCmdNothing[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnimsNothing[] =
{
    sAnimCmdNothing
};

static const u32 sBidoofNormalGfx[] = INCBIN_U32("graphics/field_pic/bidoof_normal.4bpp.lz");
static const u16 sBidoofNormalPal[] = INCBIN_U16("graphics/field_pic/bidoof_normal.gbapal");

static const u32 sBidoofUneasyGfx[] = INCBIN_U32("graphics/field_pic/bidoof_uneasy.4bpp.lz");
static const u16 sBidoofUneasyPal[] = INCBIN_U16("graphics/field_pic/bidoof_uneasy.gbapal");

static const u32 sBidoofHappyGfx[] = INCBIN_U32("graphics/field_pic/bidoof_happy.4bpp.lz");
static const u16 sBidoofHappyPal[] = INCBIN_U16("graphics/field_pic/bidoof_happy.gbapal");

static const u32 sBidoofAstonishedGfx[] = INCBIN_U32("graphics/field_pic/bidoof_astonished.4bpp.lz");
static const u16 sBidoofAstonishedPal[] = INCBIN_U16("graphics/field_pic/bidoof_astonished.gbapal");

static const u32 sBidoofSmirkyGfx[] = INCBIN_U32("graphics/field_pic/bidoof_smirky.4bpp.lz");
static const u16 sBidoofSmirkyPal[] = INCBIN_U16("graphics/field_pic/bidoof_smirky.gbapal");

static const u32 sWingullGfx[] = INCBIN_U32("graphics/field_pic/wingull.4bpp.lz");
static const u16 sWingullPal[] = INCBIN_U16("graphics/field_pic/wingull.gbapal");

static const u32 sHikerGfx[] = INCBIN_U32("graphics/field_pic/hiker.4bpp.lz");
static const u16 sHikerPal[] = INCBIN_U16("graphics/field_pic/hiker.gbapal");

static const u32 sSuicuneGfx[] = INCBIN_U32("graphics/field_pic/suicune.4bpp.lz");
static const u16 sSuicunePal[] = INCBIN_U16("graphics/field_pic/suicune.gbapal");

static const u32 sRotomGfx[] = INCBIN_U32("graphics/field_pic/rotom.4bpp.lz");
static const u16 sRotomPal[] = INCBIN_U16("graphics/field_pic/rotom.gbapal");

/* And this is an example script.
FieldPicExample_2pics:
	load_field_pic 0, 190, 98, VAR_0x8008
	load_field_pic 1, 32, 112, VAR_0x8009
	msgbox EverGrandeCity_PokemonLeague_1F_Text_229787, MSGBOX_DEFAULT
	destroy_field_pic 0, VAR_0x8008
	destroy_field_pic 1, VAR_0x8009
	return
    @ Some arguments can be omitted
FieldPicExample_1pic:
	load_field_pic 0, 190, 98
	msgbox EverGrandeCity_PokemonLeague_1F_Text_229787, MSGBOX_DEFAULT
	destroy_field_pic 0
	return
*/

static const struct Pic sPics[] =
{
    [FIELD_PIC_BIDOOF_NORMAL] = {sBidoofNormalGfx, sBidoofNormalPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_BIDOOF_UNEASY] = {sBidoofUneasyGfx, sBidoofUneasyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_BIDOOF_HAPPY] = {sBidoofHappyGfx, sBidoofHappyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_BIDOOF_ASTONISHED] = {sBidoofAstonishedGfx, sBidoofAstonishedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_BIDOOF_SMIRKY] = {sBidoofSmirkyGfx, sBidoofSmirkyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_WINGULL] = {sWingullGfx, sWingullPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_HIKER] = {sHikerGfx, sHikerPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SUICUNE] = {sSuicuneGfx, sSuicunePal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ROTOM] = {sRotomGfx, sRotomPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
};

static EWRAM_DATA u8 sLastPicId = 0;

#define sTag data[0]
#define sDestroy data[1]

u32 LoadFieldPicVars(u32 id, s16 x, s16 y)
{
    struct CompressedSpriteSheet sheet;
    struct SpritePalette palSheet;
    struct SpriteTemplate spriteTempl;
    struct OamData oam = {0};

    if (id >= ARRAY_COUNT(sPics))
        return 0xFF;

    if (GetSpriteTileStartByTag(TAG_PIC + id) == 0xFFFF)
    {
        const u8 *gfxPtr = (const u8*)(sPics[id].gfx); // To get the size, the pointer needs to be casted to u8.

        sheet.tag = TAG_PIC + id;
        sheet.data = sPics[id].gfx;
        sheet.size = (gfxPtr[3] << 16) | (gfxPtr[2] << 8) | gfxPtr[1];

        LoadCompressedSpriteSheet(&sheet);
    }

    if (IndexOfSpritePaletteTag(TAG_PIC + id) == 0xFF)
    {
        palSheet.tag = TAG_PIC + id;
        palSheet.data = sPics[id].pal;

        LoadSpritePalette(&palSheet);
    }

    oam.size = sPics[id].size;
    oam.shape = sPics[id].shape;
    oam.priority = 1;

    spriteTempl = gDummySpriteTemplate;
    spriteTempl.oam = &oam;
    spriteTempl.paletteTag = spriteTempl.tileTag = TAG_PIC + id;
    if (sPics[id].callback)
        spriteTempl.callback = sPics[id].callback;
    if (sPics[id].anims)
        spriteTempl.anims = sPics[id].anims;

    sLastPicId = CreateSprite(&spriteTempl, x, y, 0);
    if (sLastPicId == MAX_SPRITES)
        return 0xFF;

    gSprites[sLastPicId].sTag = TAG_PIC + id;

    return sLastPicId;
}

void LoadFieldPic(void)
{
    u32 id = VarGet(gSpecialVar_0x8004);
    s16 x = (s16)(VarGet(gSpecialVar_0x8005));
    s16 y = (s16)(VarGet(gSpecialVar_0x8006));

    gSpecialVar_Result = LoadFieldPicVars(id, x, y);
}

void HideFieldPic(void)
{
    u32 spriteId = VarGet(gSpecialVar_0x8004);

    if (spriteId == 0xFF)
        gSprites[sLastPicId].invisible = TRUE;
    else
        gSprites[spriteId].invisible = TRUE;
}

void ShowFieldPic(void)
{
    u32 spriteId = VarGet(gSpecialVar_0x8004);

    if (spriteId == 0xFF)
        gSprites[sLastPicId].invisible = FALSE;
    else
        gSprites[spriteId].invisible = FALSE;
}

void ChangeFieldPicFrame(void)
{
    u32 num = VarGet(gSpecialVar_0x8004);
    u32 spriteId = VarGet(gSpecialVar_0x8005);

    if (spriteId == 0xFF)
        StartSpriteAnim(&gSprites[sLastPicId], num);
    else
        StartSpriteAnim(&gSprites[spriteId], num);
}

void DestroyFieldPicVars(u32 id, u32 spriteId)
{
    if (spriteId == 0xFF)
        DestroySprite(&gSprites[sLastPicId]);
    else
        DestroySprite(&gSprites[spriteId]);

    if (id != 0xFF)
    {
        FreeSpritePaletteByTag(TAG_PIC + id);
        FreeSpriteTilesByTag(TAG_PIC + id);
    }
}

void DestroyFieldPic(void)
{
    u32 id = VarGet(gSpecialVar_0x8004);
    u32 spriteId = VarGet(gSpecialVar_0x8005);

    DestroyFieldPicVars(id, spriteId);
}

void SpiteCb_AlwaysVisible(struct Sprite *sprite)
{
    sprite->invisible = FALSE;
}

extern bool8 gScriptABPressed;

void SpriteCb_DestroyOnButonPress(struct Sprite *sprite)
{
    if (sprite->sDestroy == 0)
    {
        // The delay, so that the pic disappears along with the textbox.
        if (JOY_NEW(A_BUTTON | B_BUTTON) && gScriptABPressed == TRUE)
            sprite->sDestroy = 1;
    }
    else
    {
        if (sprite->sDestroy++ >= 3)
        {
            FreeSpritePaletteByTag(sprite->sTag);
            FreeSpriteTilesByTag(sprite->sTag);
            DestroySprite(sprite);
        }
    }
}

#undef sTag
#undef sDestroy

