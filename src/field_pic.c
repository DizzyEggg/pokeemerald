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

#define TAG_PIC 0x33333

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


static const u32 sAbraAngryGfx[] = INCBIN_U32("graphics/field_pic/abra_angry.4bpp.lz");
static const u16 sAbraAngryPal[] = INCBIN_U16("graphics/field_pic/abra_angry.gbapal");

static const u32 sAbraConcernedGfx[] = INCBIN_U32("graphics/field_pic/abra_concerned.4bpp.lz");
static const u16 sAbraConcernedPal[] = INCBIN_U16("graphics/field_pic/abra_concerned.gbapal");

static const u32 sAbraCryGfx[] = INCBIN_U32("graphics/field_pic/abra_cry.4bpp.lz");
static const u16 sAbraCryPal[] = INCBIN_U16("graphics/field_pic/abra_cry.gbapal");

static const u32 sAbraDeterminedGfx[] = INCBIN_U32("graphics/field_pic/abra_determined.4bpp.lz");
static const u16 sAbraDeterminedPal[] = INCBIN_U16("graphics/field_pic/abra_determined.gbapal");

static const u32 sAbraHappyGfx[] = INCBIN_U32("graphics/field_pic/abra_happy.4bpp.lz");
static const u16 sAbraHappyPal[] = INCBIN_U16("graphics/field_pic/abra_happy.gbapal");

static const u32 sAbraJoyGfx[] = INCBIN_U32("graphics/field_pic/abra_joy.4bpp.lz");
static const u16 sAbraJoyPal[] = INCBIN_U16("graphics/field_pic/abra_joy.gbapal");

static const u32 sAbraSeriousGfx[] = INCBIN_U32("graphics/field_pic/abra_serious.4bpp.lz");
static const u16 sAbraSeriousPal[] = INCBIN_U16("graphics/field_pic/abra_serious.gbapal");

static const u32 sAbraSurprisedGfx[] = INCBIN_U32("graphics/field_pic/abra_surprised.4bpp.lz");
static const u16 sAbraSurprisedPal[] = INCBIN_U16("graphics/field_pic/abra_surprised.gbapal");

static const u32 sAbraSweatGfx[] = INCBIN_U32("graphics/field_pic/abra_sweat.4bpp.lz");
static const u16 sAbraSweatPal[] = INCBIN_U16("graphics/field_pic/abra_sweat.gbapal");

static const u32 sAbraThinkingGfx[] = INCBIN_U32("graphics/field_pic/abra_thinking.4bpp.lz");
static const u16 sAbraThinkingPal[] = INCBIN_U16("graphics/field_pic/abra_thinking.gbapal");


static const u32 sPhanpyConfusedGfx[] = INCBIN_U32("graphics/field_pic/phanpy_confused.4bpp.lz");
static const u16 sPhanpyConfusedPal[] = INCBIN_U16("graphics/field_pic/phanpy_confused.gbapal");

static const u32 sPhanpyDeterminedGfx[] = INCBIN_U32("graphics/field_pic/phanpy_determined.4bpp.lz");
static const u16 sPhanpyDeterminedPal[] = INCBIN_U16("graphics/field_pic/phanpy_determined.gbapal");

static const u32 sPhanpySadGfx[] = INCBIN_U32("graphics/field_pic/phanpy_sad.4bpp.lz");
static const u16 sPhanpySadPal[] = INCBIN_U16("graphics/field_pic/phanpy_sad.gbapal");

static const u32 sPhanpySweatGfx[] = INCBIN_U32("graphics/field_pic/phanpy_sweat.4bpp.lz");
static const u16 sPhanpySweatPal[] = INCBIN_U16("graphics/field_pic/phanpy_sweat.gbapal");


static const u32 sSwabluAngryGfx[] = INCBIN_U32("graphics/field_pic/swablu_angry.4bpp.lz");
static const u16 sSwabluAngryPal[] = INCBIN_U16("graphics/field_pic/swablu_angry.gbapal");

static const u32 sSwabluYellGfx[] = INCBIN_U32("graphics/field_pic/swablu_yell.4bpp.lz");
static const u16 sSwabluYellPal[] = INCBIN_U16("graphics/field_pic/swablu_yell.gbapal");


static const u32 sFidoughSurprisedGfx[] = INCBIN_U32("graphics/field_pic/fidough_surprised.4bpp.lz");
static const u16 sFidoughSurprisedPal[] = INCBIN_U16("graphics/field_pic/fidough_surprised.gbapal");

static const u32 sApplinDeterminedGfx[] = INCBIN_U32("graphics/field_pic/applin_determined.4bpp.lz");
static const u16 sApplinDeterminedPal[] = INCBIN_U16("graphics/field_pic/applin_determined.gbapal");

static const u32 sSinisteaHappyGfx[] = INCBIN_U32("graphics/field_pic/sinistea_happy.4bpp.lz");
static const u16 sSinisteaHappyPal[] = INCBIN_U16("graphics/field_pic/sinistea_happy.gbapal");

static const u32 sVanilliteSighGfx[] = INCBIN_U32("graphics/field_pic/vanillite_sigh.4bpp.lz");
static const u16 sVanilliteSighPal[] = INCBIN_U16("graphics/field_pic/vanillite_sigh.gbapal");

static const u32 sVanilliteAngryGfx[] = INCBIN_U32("graphics/field_pic/vanillite_angry.4bpp.lz");
static const u16 sVanilliteAngryPal[] = INCBIN_U16("graphics/field_pic/vanillite_angry.gbapal");


static const u32 sHaunterInspiredGfx[] = INCBIN_U32("graphics/field_pic/haunter_inspired.4bpp.lz");
static const u16 sHaunterInspiredPal[] = INCBIN_U16("graphics/field_pic/haunter_inspired.gbapal");

static const u32 sHaunterSighGfx[] = INCBIN_U32("graphics/field_pic/haunter_sigh.4bpp.lz");
static const u16 sHaunterSighPal[] = INCBIN_U16("graphics/field_pic/haunter_sigh.gbapal");

static const u32 sHaunterYellGfx[] = INCBIN_U32("graphics/field_pic/haunter_yell.4bpp.lz");
static const u16 sHaunterYellPal[] = INCBIN_U16("graphics/field_pic/haunter_yell.gbapal");


static const u32 sTatsugiriSpecialGfx[] = INCBIN_U32("graphics/field_pic/tatsugiri_special.4bpp.lz");
static const u16 sTatsugiriSpecialPal[] = INCBIN_U16("graphics/field_pic/tatsugiri_special.gbapal");

static const u32 sSmolivCryGfx[] = INCBIN_U32("graphics/field_pic/smoliv_cry.4bpp.lz");
static const u16 sSmolivCryPal[] = INCBIN_U16("graphics/field_pic/smoliv_cry.gbapal");

static const u32 sFarfetchdDeterminedGfx[] = INCBIN_U32("graphics/field_pic/farfetchd_determined.4bpp.lz");
static const u16 sFarfetchdDeterminedPal[] = INCBIN_U16("graphics/field_pic/farfetchd_determined.gbapal");

static const u32 sNacliNormalGfx[] = INCBIN_U32("graphics/field_pic/nacli_normal.4bpp.lz");
static const u16 sNacliNormalPal[] = INCBIN_U16("graphics/field_pic/nacli_normal.gbapal");


static const u32 sTinkatonInspiredGfx[] = INCBIN_U32("graphics/field_pic/tinkaton_inspired.4bpp.lz");
static const u16 sTinkatonInspiredPal[] = INCBIN_U16("graphics/field_pic/tinkaton_inspired.gbapal");

static const u32 sTinkatonDeterminedGfx[] = INCBIN_U32("graphics/field_pic/tinkaton_determined.4bpp.lz");
static const u16 sTinkatonDeterminedPal[] = INCBIN_U16("graphics/field_pic/tinkaton_determined.gbapal");

static const u32 sTinkatonAngryGfx[] = INCBIN_U32("graphics/field_pic/tinkaton_angry.4bpp.lz");
static const u16 sTinkatonAngryPal[] = INCBIN_U16("graphics/field_pic/tinkaton_angry.gbapal");

static const u32 sTinkatonHappyGfx[] = INCBIN_U32("graphics/field_pic/tinkaton_happy.4bpp.lz");
static const u16 sTinkatonHappyPal[] = INCBIN_U16("graphics/field_pic/tinkaton_happy.gbapal");

static const u32 sTinkatonSadGfx[] = INCBIN_U32("graphics/field_pic/tinkaton_sad.4bpp.lz");
static const u16 sTinkatonSadPal[] = INCBIN_U16("graphics/field_pic/tinkaton_sad.gbapal");

static const u32 sScolipedeAngryGfx[] = INCBIN_U32("graphics/field_pic/scolipede_angry.4bpp.lz");
static const u16 sScolipedeAngryPal[] = INCBIN_U16("graphics/field_pic/scolipede_angry.gbapal");

static const u32 sScolipedeWorriedGfx[] = INCBIN_U32("graphics/field_pic/scolipede_worried.4bpp.lz");
static const u16 sScolipedeWorriedPal[] = INCBIN_U16("graphics/field_pic/scolipede_worried.gbapal");

static const u32 sBlastoiseNormalGfx[] = INCBIN_U32("graphics/field_pic/blastoise_normal.4bpp.lz");
static const u16 sBlastoiseNormalPal[] = INCBIN_U16("graphics/field_pic/blastoise_normal.gbapal");

static const u32 sBlastoiseAngryGfx[] = INCBIN_U32("graphics/field_pic/blastoise_angry.4bpp.lz");
static const u16 sBlastoiseAngryPal[] = INCBIN_U16("graphics/field_pic/blastoise_angry.gbapal");

static const u32 sBlastoisePainGfx[] = INCBIN_U32("graphics/field_pic/blastoise_pain.4bpp.lz");
static const u16 sBlastoisePainPal[] = INCBIN_U16("graphics/field_pic/blastoise_pain.gbapal");


static const u32 sCradilyDarkGfx[] = INCBIN_U32("graphics/field_pic/cradily_dark.4bpp.lz");
static const u16 sCradilyDarkPal[] = INCBIN_U16("graphics/field_pic/cradily_dark.gbapal");

static const u32 sCradilyDeterminedGfx[] = INCBIN_U32("graphics/field_pic/cradily_determined.4bpp.lz");
static const u16 sCradilyDeterminedPal[] = INCBIN_U16("graphics/field_pic/cradily_determined.gbapal");


static const u32 sPhotoPiece1Gfx[] = INCBIN_U32("graphics/field_pic/photo_piece_1.4bpp.lz");
static const u16 sPhotoPiece1Pal[] = INCBIN_U16("graphics/field_pic/photo_piece_1.gbapal");

static const u32 sPhotoPiece2Gfx[] = INCBIN_U32("graphics/field_pic/photo_piece_2.4bpp.lz");
static const u16 sPhotoPiece2Pal[] = INCBIN_U16("graphics/field_pic/photo_piece_2.gbapal");

static const u32 sPhotoPiece3Gfx[] = INCBIN_U32("graphics/field_pic/photo_piece_3.4bpp.lz");
static const u16 sPhotoPiece3Pal[] = INCBIN_U16("graphics/field_pic/photo_piece_3.gbapal");

static const u32 sPhotoPiece4Gfx[] = INCBIN_U32("graphics/field_pic/photo_piece_4.4bpp.lz");
static const u16 sPhotoPiece4Pal[] = INCBIN_U16("graphics/field_pic/photo_piece_4.gbapal");

static const u32 sPhotoPiece5Gfx[] = INCBIN_U32("graphics/field_pic/photo_piece_5.4bpp.lz");
static const u16 sPhotoPiece5Pal[] = INCBIN_U16("graphics/field_pic/photo_piece_5.gbapal");

static const u32 sPhotoWholeAGfx[] = INCBIN_U32("graphics/field_pic/photo_whole_a.4bpp.lz");
static const u16 sPhotoWholeAPal[] = INCBIN_U16("graphics/field_pic/photo_whole_a.gbapal");

static const u32 sPhotoWholeBGfx[] = INCBIN_U32("graphics/field_pic/photo_whole_b.4bpp.lz");
static const u16 sPhotoWholeBPal[] = INCBIN_U16("graphics/field_pic/photo_whole_b.gbapal");


static const u32 sTinkatinkCryGfx[] = INCBIN_U32("graphics/field_pic/tinkatink_cry.4bpp.lz");
static const u16 sTinkatinkCryPal[] = INCBIN_U16("graphics/field_pic/tinkatink_cry.gbapal");

static const u32 sTinkatinkHappyGfx[] = INCBIN_U32("graphics/field_pic/tinkatink_happy.4bpp.lz");
static const u16 sTinkatinkHappyPal[] = INCBIN_U16("graphics/field_pic/tinkatink_happy.gbapal");

static const u32 sTinkatinkSadGfx[] = INCBIN_U32("graphics/field_pic/tinkatink_sad.4bpp.lz");
static const u16 sTinkatinkSadPal[] = INCBIN_U16("graphics/field_pic/tinkatink_sad.gbapal");

static const u32 sTinkatinkStunnedGfx[] = INCBIN_U32("graphics/field_pic/tinkatink_stunned.4bpp.lz");
static const u16 sTinkatinkStunnedPal[] = INCBIN_U16("graphics/field_pic/tinkatink_stunned.gbapal");

static const u32 sTinkatinkWorriedGfx[] = INCBIN_U32("graphics/field_pic/tinkatink_worried.4bpp.lz");
static const u16 sTinkatinkWorriedPal[] = INCBIN_U16("graphics/field_pic/tinkatink_worried.gbapal");

static const u32 sVenipedeAngryGfx[] = INCBIN_U32("graphics/field_pic/venipede_angry.4bpp.lz");
static const u16 sVenipedeAngryPal[] = INCBIN_U16("graphics/field_pic/venipede_angry.gbapal");

static const u32 sVenipedeDeterminedGfx[] = INCBIN_U32("graphics/field_pic/venipede_determined.4bpp.lz");
static const u16 sVenipedeDeterminedPal[] = INCBIN_U16("graphics/field_pic/venipede_determined.gbapal");

static const u32 sVenipedeSurprisedGfx[] = INCBIN_U32("graphics/field_pic/venipede_surprised.4bpp.lz");
static const u16 sVenipedeSurprisedPal[] = INCBIN_U16("graphics/field_pic/venipede_surprised.gbapal");

static const u32 sVenipedeWorriedGfx[] = INCBIN_U32("graphics/field_pic/venipede_worried.4bpp.lz");
static const u16 sVenipedeWorriedPal[] = INCBIN_U16("graphics/field_pic/venipede_worried.gbapal");

static const u32 sSquirtleDizzyGfx[] = INCBIN_U32("graphics/field_pic/squirtle_dizzy.4bpp.lz");
static const u16 sSquirtleDizzyPal[] = INCBIN_U16("graphics/field_pic/squirtle_dizzy.gbapal");

static const u32 sSquirtleNormalGfx[] = INCBIN_U32("graphics/field_pic/squirtle_normal.4bpp.lz");
static const u16 sSquirtleNormalPal[] = INCBIN_U16("graphics/field_pic/squirtle_normal.gbapal");

static const u32 sSquirtlePainGfx[] = INCBIN_U32("graphics/field_pic/squirtle_pain.4bpp.lz");
static const u16 sSquirtlePainPal[] = INCBIN_U16("graphics/field_pic/squirtle_pain.gbapal");

static const u32 sSquirtleStunnedGfx[] = INCBIN_U32("graphics/field_pic/squirtle_stunned.4bpp.lz");
static const u16 sSquirtleStunnedPal[] = INCBIN_U16("graphics/field_pic/squirtle_stunned.gbapal");

static const u32 sSquirtleWorriedGfx[] = INCBIN_U32("graphics/field_pic/squirtle_worried.4bpp.lz");
static const u16 sSquirtleWorriedPal[] = INCBIN_U16("graphics/field_pic/squirtle_worried.gbapal");


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

    [FIELD_PIC_ABRA_ANGRY] = {sAbraAngryGfx, sAbraAngryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_CONCERNED] = {sAbraConcernedGfx, sAbraConcernedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_CRY] = {sAbraCryGfx, sAbraCryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_DETERMINED] = {sAbraDeterminedGfx, sAbraDeterminedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_HAPPY] = {sAbraHappyGfx, sAbraHappyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_JOY] = {sAbraJoyGfx, sAbraJoyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_SERIOUS] = {sAbraSeriousGfx, sAbraSeriousPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_SURPRISED] = {sAbraSurprisedGfx, sAbraSurprisedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_SWEAT] = {sAbraSweatGfx, sAbraSweatPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_ABRA_THINKING] = {sAbraThinkingGfx, sAbraThinkingPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_PHANPY_CONFUSED] = {sPhanpyConfusedGfx, sPhanpyConfusedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHANPY_DETERMINED] = {sPhanpyDeterminedGfx, sPhanpyDeterminedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHANPY_SAD] = {sPhanpySadGfx, sPhanpySadPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHANPY_SWEAT] = {sPhanpySweatGfx, sPhanpySweatPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_SWABLU_ANGRY] = {sSwabluAngryGfx, sSwabluAngryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SWABLU_YELL] = {sSwabluYellGfx, sSwabluYellPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_FIDOUGH_SURPRISED] = {sFidoughSurprisedGfx, sFidoughSurprisedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_APPLIN_DETERMINED] = {sApplinDeterminedGfx, sApplinDeterminedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SINISTEA_HAPPY] = {sSinisteaHappyGfx, sSinisteaHappyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_VANILLITE_SIGH] = {sVanilliteSighGfx, sVanilliteSighPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_VANILLITE_ANGRY] = {sVanilliteAngryGfx, sVanilliteAngryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_HAUNTER_INSPIRED] = {sHaunterInspiredGfx, sHaunterInspiredPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_HAUNTER_SIGH] = {sHaunterSighGfx, sHaunterSighPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_HAUNTER_YELL] = {sHaunterYellGfx, sHaunterYellPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_TATSUGIRI_SPECIAL] = {sTatsugiriSpecialGfx, sTatsugiriSpecialPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SMOLIV_CRY] = {sSmolivCryGfx, sSmolivCryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_FARFETCHD_DETERMINED] = {sFarfetchdDeterminedGfx, sFarfetchdDeterminedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_NACLI_NORMAL] = {sNacliNormalGfx, sNacliNormalPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_TINKATON_INSPIRED] = {sTinkatonInspiredGfx, sTinkatonInspiredPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_TINKATON_DETERMINED] = {sTinkatonDeterminedGfx, sTinkatonDeterminedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_TINKATON_ANGRY] = {sTinkatonAngryGfx, sTinkatonAngryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_TINKATON_HAPPY] = {sTinkatonHappyGfx, sTinkatonHappyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_TINKATON_SAD] = {sTinkatonSadGfx, sTinkatonSadPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SCOLIPEDE_ANGRY] = {sScolipedeAngryGfx, sScolipedeAngryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SCOLIPEDE_WORRIED] = {sScolipedeWorriedGfx, sScolipedeWorriedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_BLASTOISE_NORMAL] = {sBlastoiseNormalGfx, sBlastoiseNormalPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_BLASTOISE_ANGRY] = {sBlastoiseAngryGfx, sBlastoiseAngryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_BLASTOISE_PAIN] = {sBlastoisePainGfx, sBlastoisePainPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_CRADILY_DARK] = {sCradilyDarkGfx, sCradilyDarkPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_CRADILY_DETERMINED] = {sCradilyDeterminedGfx, sCradilyDeterminedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_PHOTO_PIECE_1] = {sPhotoPiece1Gfx, sPhotoPiece1Pal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHOTO_PIECE_2] = {sPhotoPiece2Gfx, sPhotoPiece2Pal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHOTO_PIECE_3] = {sPhotoPiece3Gfx, sPhotoPiece3Pal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHOTO_PIECE_4] = {sPhotoPiece4Gfx, sPhotoPiece4Pal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHOTO_PIECE_5] = {sPhotoPiece5Gfx, sPhotoPiece5Pal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHOTO_WHOLE_A] = {sPhotoWholeAGfx, sPhotoWholeAPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_PHOTO_WHOLE_B] = {sPhotoWholeBGfx, sPhotoWholeBPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

    [FIELD_PIC_TINKATINK_CRY] = {sTinkatinkCryGfx, sTinkatinkCryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_TINKATINK_HAPPY] = {sTinkatinkHappyGfx, sTinkatinkHappyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_TINKATINK_SAD] = {sTinkatinkSadGfx, sTinkatinkSadPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_TINKATINK_STUNNED] = {sTinkatinkStunnedGfx, sTinkatinkStunnedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_TINKATINK_WORRIED] = {sTinkatinkWorriedGfx, sTinkatinkWorriedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_VENIPEDE_ANGRY] = {sVenipedeAngryGfx, sVenipedeAngryPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_VENIPEDE_DETERMINED] = {sVenipedeDeterminedGfx, sVenipedeDeterminedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_VENIPEDE_SURPRISED] = {sVenipedeSurprisedGfx, sVenipedeSurprisedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_VENIPEDE_WORRIED] = {sVenipedeWorriedGfx, sVenipedeWorriedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SQUIRTLE_DIZZY] = {sSquirtleDizzyGfx, sSquirtleDizzyPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SQUIRTLE_NORMAL] = {sSquirtleNormalGfx, sSquirtleNormalPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SQUIRTLE_PAIN] = {sSquirtlePainGfx, sSquirtlePainPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SQUIRTLE_STUNNED] = {sSquirtleStunnedGfx, sSquirtleStunnedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},
    [FIELD_PIC_SQUIRTLE_WORRIED] = {sSquirtleWorriedGfx, sSquirtleWorriedPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), sAnimsNothing},

};

static EWRAM_DATA u8 sLastPicId = 0;

#define sTag data[0]
#define sDestroy data[1]

#define MAX_CREATED_PICS 5

static u8 EWRAM_INIT sCreatedPicsSpriteIds[MAX_CREATED_PICS] = {
    [0 ... MAX_CREATED_PICS - 1] = MAX_SPRITES,
};

static void AddToCreatedPics(u32 id)
{
    s32 i;

    for (i = 0; i < MAX_CREATED_PICS; i++) {
        if (sCreatedPicsSpriteIds[i] >= MAX_SPRITES) {
            sCreatedPicsSpriteIds[i] = id;
            break;
        }
    }
}

void RemoveAllCreatedPics(void)
{
    s32 i;

    for (i = 0; i < MAX_CREATED_PICS; i++) {
        if (sCreatedPicsSpriteIds[i] < MAX_SPRITES) {
            FieldPicSpriteDestroy(&gSprites[sCreatedPicsSpriteIds[i]]);
            sCreatedPicsSpriteIds[i] = MAX_SPRITES;
        }
    }
}

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

    sLastPicId = CreateSpriteAtEnd(&spriteTempl, x, y, 0);
    AddToCreatedPics(sLastPicId);
    if (sLastPicId >= MAX_SPRITES)
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

void FieldPicSpriteDestroy(struct Sprite *sprite)
{
    u16 tag = sprite->sTag;
    DestroySprite(sprite);
    FreeSpritePaletteByTag(tag);
    FreeSpriteTilesByTag(tag);
}

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
            FieldPicSpriteDestroy(sprite);
        }
    }
}

#undef sTag
#undef sDestroy

