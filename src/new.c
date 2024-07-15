#include "global.h"
#include "event_data.h"
#include "palette.h"
#include "decompress.h"
#include "random.h"
#include "bg.h"
#include "m4a.h"
#include "gpu_regs.h"
#include "script.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "event_scripts.h"
#include "event_object_movement.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// New functions
void BlendTalkingObj(void)
{
    u32 objectEventId = GetObjectEventIdByLocalIdAndMap(gSpecialVar_LastTalked, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    u32 spriteId = gObjectEvents[objectEventId].spriteId;
    u32 palNum = gSprites[spriteId].oam.paletteNum;
    u32 clr = gSpecialVar_0x8004;
    u32 coeff = gSpecialVar_0x8005;

    BlendPalettes(1 << (palNum + 16), coeff, clr);
}

void ChooseMsgForBidoofFollower(struct ScriptContext *ctx)
{
    u32 noTimes = VarGet(VAR_BIDOOF_FOLLOWER_NO_TALKS);

    // First message
    if (noTimes == 0)
    {
        ScriptCall(ctx, EventScript_BidoofFirstMsg);
    }
    else
    {
        ScriptCall(ctx, EventScript_BidoofFollowerTypicalMsg);
    }
}

static u32 GetPalsToBlend(void)
{
    u32 palNum = IndexOfSpritePaletteTag(gSprites[gSpecialVar_0x8009].data[0]);
    u32 pals = 1 | (1 << (palNum + 16));

    return ~pals;
}

void FadeAllExceptBg0AndMugshots(void)
{
    BeginNormalPaletteFade(GetPalsToBlend(), 0, 0, 16, RGB_BLACK);
}

void FadeOutAllExceptBg0AndMugshots(void)
{
    BeginNormalPaletteFade(GetPalsToBlend(), 0, 16, 0, RGB_BLACK);
}

void GlitchScreen(void)
{
    s32 i, x, y;

    for (x = 0; x < (MAP_OFFSET * 2) + 1; x++)
    {
        for (y = 0; y < (MAP_OFFSET * 2) + 1; y++)
        {
            MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + x, gSaveBlock1Ptr->pos.y + y, Random() % 0x200);
        }
    }
    DrawWholeMapView();
    for (i = 0; i < PLTT_BUFFER_SIZE; i++)
        gPlttBufferFaded[i] = Random();
}

void GlitchSound(void)
{
    m4aSongNumStart(MUS_RG_SURF);
    gMPlayInfo_BGM.tempoU = 0xabbb;
    gMPlayInfo_BGM.tempoC = 0x7999;
}
