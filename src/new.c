#include "global.h"
#include "event_data.h"
#include "palette.h"
#include "decompress.h"
#include "random.h"
#include "window.h"
#include "malloc.h"
#include "item.h"
#include "item_icon.h"
#include "string_util.h"
#include "bg.h"
#include "m4a.h"
#include "gpu_regs.h"
#include "script.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "util.h"
#include "menu.h"
#include "debug.h"
#include "pokemon_icon.h"
#include "event_scripts.h"
#include "event_object_movement.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "constants/species.h"
#include "constants/moves.h"

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

static const struct WindowTemplate sChooseMonsWindow =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 1,
    .width = 6,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sSpeciesOptionsWindow =
{
    .bg = 0,
    .tilemapLeft = 10,
    .tilemapTop = 1,
    .width = 8,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 144,
};

static const struct WindowTemplate sModifyWindow =
{
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 9,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 232,
};

struct ChooseMonsStruct
{
    u8 windowId;
    u8 secondWindowId;
    u8 modifyWindowId;
    u16 species[3];
    u16 chosenItem[3];
    u16 chosenAbility[3];
    u16 moves[3][MAX_MON_MOVES];
    u8 monSpriteId[3];
    bool8 secondWindowActive;
    bool8 modifyWindowActive;
    u8 monsCursor;
    u8 optionsCursor;
    u8 modifyCursor;
    u8 modifyTenPowerId;
    s32 modifyCurrValue;
    s32 modifyMaxValue;
    u16 abilities[NUM_ABILITY_SLOTS];
    bool8 abilityChosen[3];
    bool8 itemChosen[3];
    u8 itemIconSpriteId;
};

#define PAL_TAG_ICON 0x23544
#define ITEM_TAG_ICON 0x1122
#define MENU_OPTIONS_COUNT 4
#define MENU_Y_DELTA 25

static EWRAM_DATA struct ChooseMonsStruct *sChooseMonsPtr = NULL;

static void HighlightRow(const struct WindowTemplate *win, u32 index, s32 yDelta, s32 toSub)
{
    s32 y;
    s32 x = win->tilemapLeft * 8;
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(x, x + win->width * 8));
    y = win->tilemapTop * 8 + index * yDelta;
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(y, y + (yDelta - toSub)));
}

void HighlightMonRow(u32 index)
{
    HighlightRow(&sChooseMonsWindow, index, MENU_Y_DELTA, 5);
}

void HighlightSpeciesOptionRow(u32 index)
{
    HighlightRow(&sSpeciesOptionsWindow, index, 15, 0);
}

static const u8 sTextFirst[] = _("1st.");
static const u8 sTextSecond[] = _("2nd.");
static const u8 sTextThird[] = _("3rd.");
static const u8 sTextConfirm[] = _("CONFIRM");

static const u8 *const sTexts_1st2nd3d[] =
{
    sTextFirst, sTextSecond, sTextThird, sTextConfirm
};

#define MODIFY_SPECIES 0
#define MODIFY_ABILITY 1
#define MODIFY_ITEM 2
#define MODIFY_MOVES 3
#define MODIFY_COUNT 4

static const u8 *const sSecondWindowOptions[MODIFY_COUNT] =
{
    COMPOUND_STRING("SPECIES"),
    COMPOUND_STRING("ABILITY"),
    COMPOUND_STRING("ITEM"),
    COMPOUND_STRING("MOVES"),
};

static const s16 sModifyOptionMaxValues[MODIFY_COUNT] =
{
    [MODIFY_SPECIES] = NUM_SPECIES - 1,
    [MODIFY_ABILITY] = ABILITIES_COUNT - 1,
    [MODIFY_ITEM] = ITEMS_COUNT - 1,
    [MODIFY_MOVES] = MOVES_COUNT - 1,
};

void Task_InputChooseMons(u8 taskId);

static s32 CreateSpeciesIcon(s32 species, s32 id)
{
    s32 spriteId = CreateMonIconNoPersonality(species, SpriteCB_MonIcon, 52, id * MENU_Y_DELTA + 10, 0);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

static void PutOnFirstWindow(u32 windowId, s32 id, bool32 createSprites)
{
    s32 i;

    for (i = 0; i < MENU_OPTIONS_COUNT; i++)
    {
        if (createSprites && i != MENU_OPTIONS_COUNT - 1){
            sChooseMonsPtr->monSpriteId[i] = CreateSpeciesIcon(SPECIES_BULBASAUR, i);
            sChooseMonsPtr->species[i] = SPECIES_BULBASAUR;
        }
        if (id == -1 || id == i)
            AddTextPrinterParameterized(windowId, FONT_NORMAL, sTexts_1st2nd3d[i], 0, i * MENU_Y_DELTA, 0, NULL);
    }
}

static void PutOnSecondWindow(u32 windowId, s32 id)
{
    s32 i;
    for (i = 0; i < MODIFY_COUNT; i++)
    {
        if (id == -1 || i == id)
            AddTextPrinterParameterized(windowId, FONT_NORMAL, sSecondWindowOptions[i], 0, i * 15, 0, NULL);
    }
}

static void SetBldCnt(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_DARKEN);
}

void ChooseMonsForPCChallenge(void)
{
    s32 windowId;
    sChooseMonsPtr = AllocZeroed(sizeof(*sChooseMonsPtr));

    LoadMessageBoxAndBorderGfx();
    sChooseMonsPtr->windowId = windowId = AddWindow(&sChooseMonsWindow);
    DrawStdWindowFrame(windowId, FALSE);

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL);
    SetBldCnt();
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 4);

    LoadMonIconPalettes();
    PutOnFirstWindow(windowId, -1, TRUE);

    HighlightMonRow(0);
    CreateTask(Task_InputChooseMons, 5);

    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void SwitchToSpeciesOptionsWindow(u32 cursor)
{
    s32 i, windowId;

    sChooseMonsPtr->secondWindowId = windowId = AddWindow(&sSpeciesOptionsWindow);
    DrawStdWindowFrame(windowId, FALSE);

    PutOnSecondWindow(windowId, -1);

    // Move highlight to second window
    sChooseMonsPtr->optionsCursor = 0;
    HighlightSpeciesOptionRow(0);

    // Remove all text except for the selected mon in the first window
    FillWindowPixelBuffer(sChooseMonsPtr->windowId, PIXEL_FILL(1));
    PutOnFirstWindow(sChooseMonsPtr->windowId, cursor, FALSE);
    CopyWindowToVram(sChooseMonsPtr->windowId, COPYWIN_FULL);
    for (i = 0; i < 3; i ++)
    {
        gSprites[sChooseMonsPtr->monSpriteId[i]].invisible = (i != cursor);
    }

    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void ClearRemoveWindow(u32 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    ClearWindowTilemap(windowId);
    RemoveWindow(windowId);
}

static void SwitchFromSpeciesOptionsWindow(void)
{
    s32 i;

    ClearRemoveWindow(sChooseMonsPtr->secondWindowId);

    HighlightMonRow(sChooseMonsPtr->monsCursor);
    PutOnFirstWindow(sChooseMonsPtr->windowId, -1, FALSE);
    CopyWindowToVram(sChooseMonsPtr->windowId, COPYWIN_FULL);
    for (i = 0; i < 3; i++) {
        gSprites[sChooseMonsPtr->monSpriteId[i]].invisible = FALSE;
    }
}

#define PRINT_ID_TEXT 0
#define PRINT_ID_VALUE 1
#define PRINT_NAME 2
#define PRINT_TEN_POWER 3
#define PRINT_ALL 4

static const u8 sText_NoItem[] = _("No Item");

static void DestroyItemIcon(void)
{
    if (sChooseMonsPtr->itemIconSpriteId < MAX_SPRITES)
    {
        DestroySpriteAndFreeResources(&gSprites[sChooseMonsPtr->itemIconSpriteId]);
        sChooseMonsPtr->itemIconSpriteId = MAX_SPRITES;
    }
}

static void CreateItemIcon(u32 itemId)
{
    u32 spriteId = AddItemIconSprite(ITEM_TAG_ICON, ITEM_TAG_ICON, itemId);
    gSprites[spriteId].x = 225;
    gSprites[spriteId].y = 52;
    gSprites[spriteId].oam.priority = 0;
    sChooseMonsPtr->itemIconSpriteId = spriteId;
}

static void PrintOnModifyWindow(u32 windowId, u32 which)
{
    if (which == PRINT_ALL)
        FillWindowPixelBuffer(windowId, PIXEL_FILL(1));

    if (which == PRINT_ID_TEXT || which == PRINT_ALL)
        AddTextPrinterParameterized(windowId, FONT_NORMAL, COMPOUND_STRING("ID: "), 0, 0, 0, NULL);
    if (which == PRINT_ID_VALUE || which == PRINT_ALL)
    {
        u8 str[0x11];
        ConvertIntToDecimalStringN(str, sChooseMonsPtr->modifyCurrValue, STR_CONV_MODE_LEADING_ZEROS, (sChooseMonsPtr->modifyMaxValue >= 1000) ? 4 : 3);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, str, 15, 0, 0, NULL);
    }
    if (which == PRINT_NAME || which == PRINT_ALL)
    {
        u32 font = FONT_NORMAL;
        const u8 *strPtr;
        s32 val = sChooseMonsPtr->modifyCurrValue;
        switch (sChooseMonsPtr->optionsCursor)
        {
        case MODIFY_SPECIES:
            strPtr = GetSpeciesName(val);
            break;
        case MODIFY_ABILITY:
            strPtr = gAbilitiesInfo[val].name;
            break;
        default:
        case MODIFY_ITEM:
            if (val == 0) {
                strPtr = sText_NoItem;
            }
            else
            {
                strPtr = gItemsInfo[val].name;
                if (GetStringWidth(FONT_NORMAL, strPtr, 0) >= sModifyWindow.width * 8)
                {
                    font = FONT_NARROW;
                    if (GetStringWidth(FONT_NARROW, strPtr, 0) >= sModifyWindow.width * 8)
                        font = FONT_NARROWER;
                }
            }
            break;
        }
        FillWindowPixelRect(windowId, PIXEL_FILL(1), 0, 16, sModifyWindow.width * 8, 15);
        AddTextPrinterParameterized(windowId, font, strPtr, 0, 16, 0, NULL);
    }
    if (which == PRINT_TEN_POWER || which == PRINT_ALL)
    {
        if (sChooseMonsPtr->optionsCursor != MODIFY_ABILITY)
            AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_DigitIndicator[sChooseMonsPtr->modifyTenPowerId], 0, 16 * 2, 0, NULL);
    }

}

static void SwitchToModifyWindow(u32 cursor)
{
    s32 i, j, windowId, temp, monId;

    sChooseMonsPtr->modifyWindowId = windowId = AddWindow(&sModifyWindow);
    DrawStdWindowFrame(windowId, FALSE);

    // Move highlight to new window
    HighlightRow(&sModifyWindow, 0, sModifyWindow.height * 8, 0);

    // Remove all text except for the selected option
    FillWindowPixelBuffer(sChooseMonsPtr->secondWindowId, PIXEL_FILL(1));
    PutOnSecondWindow(sChooseMonsPtr->secondWindowId, cursor);
    CopyWindowToVram(sChooseMonsPtr->secondWindowId, COPYWIN_FULL);

    sChooseMonsPtr->modifyTenPowerId = 0;
    sChooseMonsPtr->modifyCursor = 0;
    sChooseMonsPtr->modifyMaxValue = sModifyOptionMaxValues[cursor];

    monId = sChooseMonsPtr->monsCursor;
    if (cursor == MODIFY_ABILITY)
    {
        s32 species = sChooseMonsPtr->species[monId];
        for (i = 0; i < NUM_ABILITY_SLOTS; i++) {
            sChooseMonsPtr->abilities[i] = gSpeciesInfo[species].abilities[i];
        }
        // Sort
        for (i = 0; i < NUM_ABILITY_SLOTS; i++) {
            for (j = 0; j < i; j++) {
                if (sChooseMonsPtr->abilities[j] < sChooseMonsPtr->abilities[i]) {
                    SWAP(sChooseMonsPtr->abilities[j], sChooseMonsPtr->abilities[i], temp);
                }
            }
        }

        if (sChooseMonsPtr->abilityChosen[monId])
        {
            sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->chosenAbility[monId];
            for (i = 0; i < NUM_ABILITY_SLOTS; i++) {
                if (sChooseMonsPtr->abilities[sChooseMonsPtr->modifyCursor] == sChooseMonsPtr->chosenAbility[monId])
                    break;
                sChooseMonsPtr->modifyCursor++;
            }
            // Ability was for a different pokemon
            if (i == NUM_ABILITY_SLOTS) {
                sChooseMonsPtr->modifyCursor = 0;
                sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->chosenAbility[monId] = sChooseMonsPtr->abilities[0];
            }
        }
        else
        {
            sChooseMonsPtr->abilityChosen[monId] = TRUE;
            sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->chosenAbility[monId] = sChooseMonsPtr->abilities[0];
        }
    }
    else if (cursor == MODIFY_SPECIES)
    {
        sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->species[monId];
    }
    else if (cursor == MODIFY_ITEM)
    {
        sChooseMonsPtr->itemIconSpriteId = MAX_SPRITES;
        if (sChooseMonsPtr->itemChosen[monId]) {
            sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->chosenItem[monId];
            CreateItemIcon(sChooseMonsPtr->modifyCurrValue);
        }
        sChooseMonsPtr->itemChosen[monId] = TRUE;
    }
    else
    {
        sChooseMonsPtr->modifyCurrValue = 1;
    }

    PrintOnModifyWindow(windowId, PRINT_ALL);

    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void SwitchFromModifyWindow(void)
{
    ClearRemoveWindow(sChooseMonsPtr->modifyWindowId);

    if (sChooseMonsPtr->optionsCursor == MODIFY_ITEM)
        DestroyItemIcon();
    HighlightSpeciesOptionRow(sChooseMonsPtr->optionsCursor);
    PutOnSecondWindow(sChooseMonsPtr->secondWindowId, -1);
    CopyWindowToVram(sChooseMonsPtr->secondWindowId, COPYWIN_FULL);
}

void Task_InputChooseMons(u8 taskId)
{
    s32 i;
    if (sChooseMonsPtr->modifyWindowActive)
    {
        s32 monsCursor = sChooseMonsPtr->monsCursor;
        if (sChooseMonsPtr->optionsCursor == MODIFY_ABILITY)
        {
            u32 oldCursor = sChooseMonsPtr->modifyCursor;
            if (gMain.newAndRepeatedKeys & DPAD_DOWN) {
                for (i = 0; i < NUM_ABILITY_SLOTS; i++) {
                    if (sChooseMonsPtr->modifyCursor == NUM_ABILITY_SLOTS - 1)
                        sChooseMonsPtr->modifyCursor = 0;
                    else
                        sChooseMonsPtr->modifyCursor++;

                    if (sChooseMonsPtr->abilities[sChooseMonsPtr->modifyCursor] != sChooseMonsPtr->abilities[oldCursor])
                        break;
                }
            }
            else if (gMain.newAndRepeatedKeys & DPAD_UP) {
                for (i = 0; i < NUM_ABILITY_SLOTS; i++) {
                    if (sChooseMonsPtr->modifyCursor == 0)
                        sChooseMonsPtr->modifyCursor = NUM_ABILITY_SLOTS - 1;
                    else
                        sChooseMonsPtr->modifyCursor--;

                    if (sChooseMonsPtr->abilities[sChooseMonsPtr->modifyCursor] != sChooseMonsPtr->abilities[oldCursor])
                        break;
                }
            }

            if (oldCursor != sChooseMonsPtr->modifyCursor
                && sChooseMonsPtr->abilities[sChooseMonsPtr->modifyCursor] != sChooseMonsPtr->abilities[oldCursor])
            {
                sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->abilities[sChooseMonsPtr->modifyCursor];
                sChooseMonsPtr->chosenAbility[monsCursor] = sChooseMonsPtr->abilities[sChooseMonsPtr->modifyCursor];
                PrintOnModifyWindow(sChooseMonsPtr->modifyWindowId, PRINT_ALL);
            }
        }
        else if (sChooseMonsPtr->optionsCursor == MODIFY_SPECIES || sChooseMonsPtr->optionsCursor == MODIFY_ITEM) {
            u32 oldSpecies = sChooseMonsPtr->species[monsCursor];
            bool32 changed = FALSE;
            if (gMain.newAndRepeatedKeys & DPAD_LEFT) {
                if (sChooseMonsPtr->modifyTenPowerId != 0) {
                    sChooseMonsPtr->modifyTenPowerId--;
                    changed = TRUE;
                }
            }
            else if (gMain.newAndRepeatedKeys & DPAD_RIGHT) {
                if (gPowersOfTen[sChooseMonsPtr->modifyTenPowerId + 1] < sChooseMonsPtr->modifyMaxValue) {
                    sChooseMonsPtr->modifyTenPowerId++;
                    changed = TRUE;
                }
            }

            if (changed) {
                PrintOnModifyWindow(sChooseMonsPtr->modifyWindowId, PRINT_TEN_POWER);
                changed = FALSE;
            }

            if (gMain.newAndRepeatedKeys & DPAD_UP) {
                sChooseMonsPtr->modifyCurrValue += gPowersOfTen[sChooseMonsPtr->modifyTenPowerId];
                if (sChooseMonsPtr->modifyCurrValue > sChooseMonsPtr->modifyMaxValue)
                    sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->modifyMaxValue;
                changed = TRUE;
            }
            else if (gMain.newAndRepeatedKeys & DPAD_DOWN) {
                sChooseMonsPtr->modifyCurrValue -= gPowersOfTen[sChooseMonsPtr->modifyTenPowerId];
                if (sChooseMonsPtr->modifyCurrValue <= 0) {
                    if (sChooseMonsPtr->optionsCursor == MODIFY_SPECIES)
                        sChooseMonsPtr->modifyCurrValue = 1;
                    else
                        sChooseMonsPtr->modifyCurrValue = 0;
                }
                changed = TRUE;
            }

            if (changed) {
                if (sChooseMonsPtr->optionsCursor == MODIFY_SPECIES) {
                    sChooseMonsPtr->species[monsCursor] = sChooseMonsPtr->modifyCurrValue;
                    if (oldSpecies != sChooseMonsPtr->species[monsCursor]) {
                        // Change icon
                        FreeAndDestroyMonIconSprite(&gSprites[sChooseMonsPtr->monSpriteId[monsCursor]]);
                        sChooseMonsPtr->monSpriteId[monsCursor] = CreateSpeciesIcon(sChooseMonsPtr->modifyCurrValue, monsCursor);
                    }
                }
                else if (sChooseMonsPtr->optionsCursor == MODIFY_ITEM) {
                    DestroyItemIcon();
                    CreateItemIcon(sChooseMonsPtr->modifyCurrValue);
                    sChooseMonsPtr->chosenItem[monsCursor] = sChooseMonsPtr->modifyCurrValue;
                }
                PrintOnModifyWindow(sChooseMonsPtr->modifyWindowId, PRINT_NAME);
                PrintOnModifyWindow(sChooseMonsPtr->modifyWindowId, PRINT_ID_VALUE);
            }
        }

        if (gMain.newKeys & (B_BUTTON))
        {
            SwitchFromModifyWindow();
            sChooseMonsPtr->modifyWindowActive = FALSE;
            sChooseMonsPtr->secondWindowActive = TRUE;
        }
    }
    else if (sChooseMonsPtr->secondWindowActive)
    {
        u32 oldCursor = sChooseMonsPtr->optionsCursor;
        if (TEST_BUTTON(gMain.newAndRepeatedKeys, DPAD_DOWN))
        {
            if (sChooseMonsPtr->optionsCursor == MODIFY_COUNT - 1)
                sChooseMonsPtr->optionsCursor = 0;
            else
                sChooseMonsPtr->optionsCursor++;
        }
        else if (TEST_BUTTON(gMain.newAndRepeatedKeys, DPAD_UP))
        {
            if (sChooseMonsPtr->optionsCursor == 0)
                sChooseMonsPtr->optionsCursor = MODIFY_COUNT - 1;
            else
                sChooseMonsPtr->optionsCursor--;
        }

        if (oldCursor != sChooseMonsPtr->optionsCursor)
            HighlightSpeciesOptionRow(sChooseMonsPtr->optionsCursor);

        if (gMain.newKeys & (B_BUTTON | DPAD_LEFT))
        {
            SwitchFromSpeciesOptionsWindow();
            sChooseMonsPtr->secondWindowActive = FALSE;
        }
        else if (gMain.newKeys & (A_BUTTON | DPAD_RIGHT))
        {
            sChooseMonsPtr->modifyWindowActive = TRUE;
            SwitchToModifyWindow(sChooseMonsPtr->optionsCursor);
            sChooseMonsPtr->secondWindowActive = FALSE;
        }
    }
    else
    {
        u32 oldCursor = sChooseMonsPtr->monsCursor;
        if (TEST_BUTTON(gMain.newAndRepeatedKeys, DPAD_DOWN))
        {
            if (sChooseMonsPtr->monsCursor == MENU_OPTIONS_COUNT - 1)
                sChooseMonsPtr->monsCursor = 0;
            else
                sChooseMonsPtr->monsCursor++;
        }
        else if (TEST_BUTTON(gMain.newAndRepeatedKeys, DPAD_UP))
        {
            if (sChooseMonsPtr->monsCursor == 0)
                sChooseMonsPtr->monsCursor = MENU_OPTIONS_COUNT - 1;
            else
                sChooseMonsPtr->monsCursor--;
        }

        if (oldCursor != sChooseMonsPtr->monsCursor)
            HighlightMonRow(sChooseMonsPtr->monsCursor);

        if (TEST_BUTTON(gMain.newKeys, A_BUTTON))
        {
            if (sChooseMonsPtr->monsCursor != MENU_OPTIONS_COUNT - 1) // Not CONFIRM
            {
                SwitchToSpeciesOptionsWindow(sChooseMonsPtr->monsCursor);
                sChooseMonsPtr->secondWindowActive = TRUE;
            }
            else
            {

            }
        }
    }
}
