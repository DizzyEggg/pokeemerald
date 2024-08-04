#include "global.h"
#include "event_data.h"
#include "palette.h"
#include "decompress.h"
#include "random.h"
#include "window.h"
#include "malloc.h"
#include "item.h"
#include "list_menu.h"
#include "item_icon.h"
#include "string_util.h"
#include "menu_specialized.h"
#include "bg.h"
#include "sound.h"
#include "m4a.h"
#include "gpu_regs.h"
#include "script.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "util.h"
#include "strings.h"
#include "menu.h"
#include "debug.h"
#include "overworld.h"
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
    .height = 9,
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
    .baseBlock = 252,
};

static const struct WindowTemplate sModifyMovesWindow =
{
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 10,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 252,
};

#define MAX_SHOWN_MOVES 150

struct ChooseMonsStruct
{
    u8 windowId;
    u8 secondWindowId;
    u8 modifyWindowId;
    u16 species[3];
    u16 chosenItem[3];
    u16 chosenAbility[3];
    u16 chosenMoves[3][MAX_MON_MOVES];
    u8 monSpriteId[3];
    bool8 secondWindowActive;
    bool8 modifyWindowActive;
    bool8 moveSwapActive;
    u16 swappingMove;
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
    u16 movesToShow[MAX_SHOWN_MOVES];
    const u8 *moveNames[MAX_SHOWN_MOVES];
    struct ListMenuItem menuItems[MAX_SHOWN_MOVES];
    u8 numMenuChoices;
    u8 numToShowAtOnce;
    u8 moveListMenuTask;
    u8 moveListScrollArrowTask;
    u8 moveDisplayArrowTask;
    u16 scrollRow;
    u16 scrollOffset;
};

struct SavedChosenMon
{
    u16 species;
    u16 ability;
    u16 item;
    u16 moves[MAX_MON_MOVES];
};

struct SavedChosenMons
{
    struct SavedChosenMon mon[3];
    bool8 teamSaved;
};

#define PAL_TAG_ICON 0x23544
#define ITEM_TAG_ICON 0x1122
#define MENU_OPTIONS_COUNT 4
#define MENU_Y_DELTA 25

static EWRAM_DATA struct ChooseMonsStruct *sChooseMonsPtr = NULL;
static EWRAM_DATA struct SavedChosenMons sChosenTeam = {0};

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
    [MODIFY_SPECIES] = SPECIES_EEVEE_PARTNER,
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
            if (sChooseMonsPtr->species[i] == SPECIES_NONE)
                sChooseMonsPtr->species[i] = SPECIES_BULBASAUR;
            sChooseMonsPtr->monSpriteId[i] = CreateSpeciesIcon(sChooseMonsPtr->species[i], i);
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
        {
            s32 y = i * 15;
            if (id == MODIFY_MOVES) // Add for moves viewing
                y += 15;
            AddTextPrinterParameterized(windowId, FONT_NORMAL, sSecondWindowOptions[i], 0, y, 0, NULL);
        }
    }
}

static void SetBldCnt(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_DARKEN);
}

static void TryLoadPreviousTeam(void)
{
    if (sChosenTeam.teamSaved && sChooseMonsPtr != NULL)
    {
        s32 i, j;

        for (i = 0; i < 3; i++) {
            sChooseMonsPtr->species[i] = sChosenTeam.mon[i].species;
            sChooseMonsPtr->chosenItem[i] = sChosenTeam.mon[i].item;
            sChooseMonsPtr->chosenAbility[i] = sChosenTeam.mon[i].ability;
            for (j = 0; j < MAX_MON_MOVES; j++) {
                 sChooseMonsPtr->chosenMoves[i][j] = sChosenTeam.mon[i].moves[j];
            }
        }
    }
}

void ChooseMonsForPCChallenge(void)
{
    s32 windowId;
    sChooseMonsPtr = AllocZeroed(sizeof(*sChooseMonsPtr));
    TryLoadPreviousTeam();

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
    if (itemId > 0)
    {
        u32 spriteId = AddItemIconSprite(ITEM_TAG_ICON, ITEM_TAG_ICON, itemId);
        gSprites[spriteId].x = 225;
        gSprites[spriteId].y = 52;
        gSprites[spriteId].oam.priority = 0;
        sChooseMonsPtr->itemIconSpriteId = spriteId;
    }
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

static void SortMovesAlph(u16 *moves, s32 numMoves, const u8 **moveNames)
{
    bool32 swapMade;
    s32 i, j, k;

    for (i = 0; i < numMoves; i++)
    {
        moveNames[i] = GetMoveName(moves[i]);
        for (j = i - 1; j >= 0; j--)
        {
            swapMade = FALSE;
            for (k = 0; moveNames[j][k] != EOS; k++)
            {
                if (moveNames[j][k] > moveNames[j + 1][k])
                {
                    u16 temp;
                    const u8 *tempName;

                    SWAP(moves[j], moves[j + 1], temp);
                    SWAP(moveNames[j], moveNames[j + 1], tempName);
                    swapMade = TRUE;
                    break;
                }
                else if (moveNames[j][k] < moveNames[j + 1][k])
                    break;
            }
            if (!swapMade)
                break;
        }
    }
}

static struct ListMenuTemplate *GetListMenuTemplate(u32 taskId)
{
    struct ListMenu *list = (void *) gTasks[taskId].data;
    return &list->template;
}

static void ListMenuFunc_ChangeFont(u8 windowId, u32 itemId, u8 y)
{
    int i;
    struct ListMenuTemplate *listTemplate = GetListMenuTemplate(sChooseMonsPtr->moveListMenuTask);
    u16 *chosenMoves = sChooseMonsPtr->chosenMoves[sChooseMonsPtr->monsCursor];
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (itemId == chosenMoves[i]) {
            listTemplate->cursorPal = 6;
            return;
        }
    }
    listTemplate->cursorPal = 2;
}

static void SwitchToMovesWindow(void)
{
    s32 i;

    sChooseMonsPtr->numMenuChoices = GetAllSpeciesMoves(sChooseMonsPtr->species[sChooseMonsPtr->monsCursor], 100, sChooseMonsPtr->movesToShow);

    SortMovesAlph(sChooseMonsPtr->movesToShow, sChooseMonsPtr->numMenuChoices, sChooseMonsPtr->moveNames);
    for (i = 0; i < sChooseMonsPtr->numMenuChoices; i++)
    {
        sChooseMonsPtr->menuItems[i].name = sChooseMonsPtr->moveNames[i];
        sChooseMonsPtr->menuItems[i].id = sChooseMonsPtr->movesToShow[i];
    }

    sChooseMonsPtr->menuItems[sChooseMonsPtr->numMenuChoices].name = gText_Cancel;
    sChooseMonsPtr->menuItems[sChooseMonsPtr->numMenuChoices].id = LIST_CANCEL;
    sChooseMonsPtr->numMenuChoices++;
    sChooseMonsPtr->numToShowAtOnce = LoadMoveRelearnerMovesList(sChooseMonsPtr->menuItems, sChooseMonsPtr->numMenuChoices);
    gMultiuseListMenuTemplate.moveCursorFunc = NULL;
    gMultiuseListMenuTemplate.cursorKind = CURSOR_BLACK_ARROW_FORCE_FONT;
    gMultiuseListMenuTemplate.itemPrintFunc = ListMenuFunc_ChangeFont;
    gMultiuseListMenuTemplate.windowId = sChooseMonsPtr->modifyWindowId;
    sChooseMonsPtr->moveListMenuTask = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
}

static void PrintMoveOnSecondWindow(s32 moveSlot, const u8 *str);
static void FillEmptyMoveSlotSecondWindow(s32 moveSlot, bool32 toVram);
static void MoveMoveSlotsUp(u16 *chosenMoves, s32 from);

static void HighlightWhole3rdWindow(const struct WindowTemplate *winTempl)
{
    HighlightRow(winTempl, 0, winTempl->height * 8, 0);
}

static void SwitchToModifyWindow(u32 cursor)
{
    s32 i, j, windowId, temp, monId, secondWindowId;
    const struct WindowTemplate *winTempl = (cursor == MODIFY_MOVES) ? &sModifyMovesWindow : &sModifyWindow;

    sChooseMonsPtr->modifyWindowId = windowId = AddWindow(winTempl);
    DrawStdWindowFrame(windowId, FALSE);

    // Move highlight to new window
    HighlightWhole3rdWindow(winTempl);

    secondWindowId = sChooseMonsPtr->secondWindowId;
    // Remove all text except for the selected option
    FillWindowPixelBuffer(secondWindowId, PIXEL_FILL(1));
    PutOnSecondWindow(secondWindowId, cursor);
    CopyWindowToVram(secondWindowId, COPYWIN_FULL);

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
        else {
            sChooseMonsPtr->modifyCurrValue = 0;
            sChooseMonsPtr->itemChosen[monId] = TRUE;
        }
    }
    else if (cursor == MODIFY_MOVES)
    {
        FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
        CopyWindowToVram(windowId, COPYWIN_FULL);
        SwitchToMovesWindow();
        // Print saved moves and check if they're valid
        for (i = 0; i < MAX_MON_MOVES; i++) {
            s32 moveId = sChooseMonsPtr->chosenMoves[monId][i];
            if (moveId != MOVE_NONE) {
                for (j = 0; j < sChooseMonsPtr->numMenuChoices; j++) {
                    if (sChooseMonsPtr->movesToShow[j] == moveId)
                        break;
                }
                // Not valid move
                if (j == sChooseMonsPtr->numMenuChoices) {
                    sChooseMonsPtr->chosenMoves[monId][i] = MOVE_NONE;
                }
            }
        }
        MoveMoveSlotsUp(sChooseMonsPtr->chosenMoves[monId], 0);
        for (i = 0; i < MAX_MON_MOVES; i++) {
            s32 moveId = sChooseMonsPtr->chosenMoves[monId][i];
            if (moveId != MOVE_NONE) {
                PrintMoveOnSecondWindow(i, GetMoveName(moveId));
            }
        }
        return;
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
    FillWindowPixelBuffer(sChooseMonsPtr->secondWindowId, PIXEL_FILL(1));
    PutOnSecondWindow(sChooseMonsPtr->secondWindowId, -1);
    CopyWindowToVram(sChooseMonsPtr->secondWindowId, COPYWIN_FULL);
}

static void ValidSpeciesCheck(s32 *val, s32 incrementBy)
{
    while (gSpeciesInfo[*val].isLegendary
           || gSpeciesInfo[*val].isMythical
           || gSpeciesInfo[*val].isUltraBeast
           || gSpeciesInfo[*val].isParadox
           || gSpeciesInfo[*val].isTotem
           || gSpeciesInfo[*val].isMegaEvolution
           || gSpeciesInfo[*val].isPrimalReversion
           || gSpeciesInfo[*val].isUltraBurst
           || gSpeciesInfo[*val].isGigantamax
           || gSpeciesInfo[*val].isTeraForm)
    {
        (*val) += incrementBy;
    }
}

static void HighlightMoveOnMenu(u32 color, const u8 *moveName)
{
    struct ListMenuTemplate *listTemplate = GetListMenuTemplate(sChooseMonsPtr->moveListMenuTask);
    s32 x = ListMenuGetRowX(listTemplate, 0);
    s32 y = ListMenuGetRowY(listTemplate, 0, ListMenuGetYMultiplier(listTemplate), sChooseMonsPtr->scrollRow);
    listTemplate->cursorPal = color;
    FillWindowPixelRect(sChooseMonsPtr->modifyWindowId, PIXEL_FILL(1), x, y, sModifyMovesWindow.width * 8 - x, 15);
    ListMenuPrint(listTemplate, moveName, x, y);
    CopyWindowToVram(sChooseMonsPtr->modifyWindowId, COPYWIN_GFX);
}

static void AddMoveHighlight(const u8 *moveName)
{
    HighlightMoveOnMenu(6, moveName);
}

static void RemoveMoveHighlight(const u8 *moveName)
{
    HighlightMoveOnMenu(2, moveName);
}

static void FillEmptyMoveSlotSecondWindow(s32 moveSlot, bool32 toVram)
{
    FillWindowPixelRect(sChooseMonsPtr->secondWindowId, PIXEL_FILL(1), 0, moveSlot * 15, sSpeciesOptionsWindow.width * 8, 15);
    if (toVram)
        CopyWindowToVram(sChooseMonsPtr->secondWindowId, COPYWIN_GFX);
}

static void PrintMoveOnSecondWindow(s32 moveSlot, const u8 *str)
{
    FillEmptyMoveSlotSecondWindow(moveSlot, FALSE);
    AddTextPrinterParameterized(sChooseMonsPtr->secondWindowId, FONT_NORMAL, str, 0, moveSlot * 15, 0, NULL);
}

static void MoveMoveSlotsUp(u16 *chosenMoves, s32 from)
{
    s32 i, j;
    u8 str[0x20];
    for (i = from; i < MAX_MON_MOVES; i++){
        if (chosenMoves[i] == MOVE_NONE) {
            for (j = i + 1; j < MAX_MON_MOVES; j++) {
                if (chosenMoves[j] != MOVE_NONE) {
                    chosenMoves[i] = chosenMoves[j];
                    StringCopy(str, GetMoveName(chosenMoves[i]));
                    chosenMoves[j] = MOVE_NONE;
                    FillEmptyMoveSlotSecondWindow(j, FALSE);
                    PrintMoveOnSecondWindow(i, str);
                    break;
                }
            }
        }
    }
}

static void AddOrRemoveChosenMove(u16 *chosenMoves, s32 newMove)
{
    int i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        // Remove
        if (chosenMoves[i] == newMove)
        {
            chosenMoves[i] = MOVE_NONE;
            RemoveMoveHighlight(GetMoveName(newMove));
            FillEmptyMoveSlotSecondWindow(i, TRUE);
            // Move 'up' other moves, so that there are no empty spots
            MoveMoveSlotsUp(chosenMoves, i);
            break;
        }
        // Add
        if (chosenMoves[i] == MOVE_NONE)
        {
            chosenMoves[i] = newMove;
            AddMoveHighlight(GetMoveName(newMove));
            PrintMoveOnSecondWindow(i, GetMoveName(newMove));
            break;
        }
    }
    // 4 moves already chosen
    if (i == MAX_MON_MOVES)
    {
        sChooseMonsPtr->moveSwapActive = TRUE;
        sChooseMonsPtr->swappingMove = newMove;
        // Highlight 5th move in 3rd window and remove other moves
        FillWindowPixelBuffer(sChooseMonsPtr->modifyWindowId, PIXEL_FILL(1));
        HighlightMoveOnMenu(4, GetMoveName(newMove));
        // Move bldcnt highlight
        sChooseMonsPtr->optionsCursor = 0;
        HighlightSpeciesOptionRow(0);
    }
}

static void SaveChosenTeam(void)
{
    s32 i, j;

    for (i = 0; i < 3; i++) {
        sChosenTeam.mon[i].species = sChooseMonsPtr->species[i];
        sChosenTeam.mon[i].item = sChooseMonsPtr->chosenItem[i];
        sChosenTeam.mon[i].ability = sChooseMonsPtr->chosenAbility[i];
        for (j = 0; j < MAX_MON_MOVES; j++) {
            sChosenTeam.mon[i].moves[j] = sChooseMonsPtr->chosenMoves[i][j];
        }
    }
    sChosenTeam.teamSaved = TRUE;
}

static void MoveChosenTeamToParty(void)
{
    s32 i, j;

    ZeroPlayerPartyMons();
    for (i = 0; i < 3; i++) {
        struct Pokemon *mon = &gPlayerParty[i];

        CreateMonWithNature(mon, sChosenTeam.mon[i].species, 50, 0xFF, NATURE_DOCILE);
        for (j = 0; j < MAX_MON_MOVES; j++) {
            SetMonData(mon, MON_DATA_MOVE1 + j, &sChosenTeam.mon[i].moves[j]);
            SetMonData(mon, MON_DATA_PP1 + j, &gMovesInfo[sChosenTeam.mon[i].moves[j]].pp);
        }
        SetMonData(mon, MON_DATA_HELD_ITEM, &sChosenTeam.mon[i].item);

        if (sChosenTeam.mon[i].ability != ABILITY_NONE) {
            s32 abilityNum = 0;
            while (GetAbilityBySpecies(sChosenTeam.mon[i].species, abilityNum) != sChosenTeam.mon[i].ability) {
                abilityNum++;
            }
            SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);
        }

        for (j = 0; j < 6; j++) {
            u32 evs = 100;
            SetMonData(mon, MON_DATA_HP_EV + j, &evs);
        }
    }
}

static void FreeRemoveEverything(void)
{
    u8 *spriteIds;
    s32 i;

    // Remove blend
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);

    ClearRemoveWindow(sChooseMonsPtr->windowId);
    spriteIds = sChooseMonsPtr->monSpriteId;
    for (i = 0; i < 3; i++) {
        DestroySpriteAndFreeResources(&gSprites[spriteIds[i]]);
    }
    FREE_AND_SET_NULL(sChooseMonsPtr);
}

void Task_InputChooseMons(u8 taskId)
{
    s32 i;
    if (sChooseMonsPtr->modifyWindowActive && !sChooseMonsPtr->moveSwapActive)
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
                PlaySE(SE_SELECT);
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
                PlaySE(SE_SELECT);
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
                PlaySE(SE_SELECT);
                PrintOnModifyWindow(sChooseMonsPtr->modifyWindowId, PRINT_TEN_POWER);
                changed = FALSE;
            }

            if (gMain.newAndRepeatedKeys & DPAD_UP) {
                sChooseMonsPtr->modifyCurrValue += gPowersOfTen[sChooseMonsPtr->modifyTenPowerId];
                if (sChooseMonsPtr->modifyCurrValue > sChooseMonsPtr->modifyMaxValue)
                    sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->modifyMaxValue;

                if (sChooseMonsPtr->optionsCursor == MODIFY_SPECIES) {
                    ValidSpeciesCheck(&sChooseMonsPtr->modifyCurrValue, 1);
                    if (sChooseMonsPtr->modifyCurrValue > sChooseMonsPtr->modifyMaxValue)
                        sChooseMonsPtr->modifyCurrValue = sChooseMonsPtr->modifyMaxValue;
                }

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
                if (sChooseMonsPtr->optionsCursor == MODIFY_SPECIES) {
                    ValidSpeciesCheck(&sChooseMonsPtr->modifyCurrValue, -1);
                }
                changed = TRUE;
            }

            if (changed) {
                PlaySE(SE_SELECT);
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
        else if (sChooseMonsPtr->optionsCursor == MODIFY_MOVES) {
            s32 itemId = ListMenu_ProcessInput(sChooseMonsPtr->moveListMenuTask);
            ListMenuGetScrollAndRow(sChooseMonsPtr->moveListMenuTask, &sChooseMonsPtr->scrollOffset, &sChooseMonsPtr->scrollRow);

            if (gMain.newAndRepeatedKeys & (DPAD_UP | DPAD_DOWN))
                PlaySE(SE_SELECT);

            if (gMain.newKeys & A_BUTTON)
            {
                if (itemId == LIST_CANCEL || itemId == sChooseMonsPtr->numMenuChoices - 1)
                    goto MODIFY_B_PRESSED;
                PlaySE(SE_SELECT);
                if (itemId > 0) {
                    AddOrRemoveChosenMove(sChooseMonsPtr->chosenMoves[monsCursor], itemId);
                    return;
                }
            }
        }

        if (TEST_BUTTON(gMain.newKeys, B_BUTTON)
            || (sChooseMonsPtr->optionsCursor != MODIFY_MOVES && TEST_BUTTON(gMain.newKeys, A_BUTTON)))
        {
        MODIFY_B_PRESSED:
            PlaySE(SE_SELECT);
            if (sChooseMonsPtr->optionsCursor == MODIFY_MOVES)
                DestroyListMenuTask(sChooseMonsPtr->moveListMenuTask, &sChooseMonsPtr->scrollOffset, &sChooseMonsPtr->scrollRow);
            SwitchFromModifyWindow();
            sChooseMonsPtr->modifyWindowActive = FALSE;
            sChooseMonsPtr->secondWindowActive = TRUE;
        }
    }
    else if (sChooseMonsPtr->secondWindowActive || sChooseMonsPtr->moveSwapActive)
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
        {
            PlaySE(SE_SELECT);
            HighlightSpeciesOptionRow(sChooseMonsPtr->optionsCursor);
        }

        if (!sChooseMonsPtr->moveSwapActive)
        {
            if (gMain.newKeys & (B_BUTTON | DPAD_LEFT))
            {
                PlaySE(SE_SELECT);
                SwitchFromSpeciesOptionsWindow();
                sChooseMonsPtr->secondWindowActive = FALSE;
            }
            else if (gMain.newKeys & (A_BUTTON | DPAD_RIGHT))
            {
                PlaySE(SE_SELECT);
                sChooseMonsPtr->modifyWindowActive = TRUE;
                SwitchToModifyWindow(sChooseMonsPtr->optionsCursor);
                sChooseMonsPtr->secondWindowActive = FALSE;
            }
        }
        else
        {
            bool32 pressed = FALSE;
            if (TEST_BUTTON(gMain.newKeys, B_BUTTON))
            {
                pressed = TRUE;
            }
            else if (TEST_BUTTON(gMain.newKeys, A_BUTTON))
            {
                sChooseMonsPtr->chosenMoves[sChooseMonsPtr->monsCursor][sChooseMonsPtr->optionsCursor] = MOVE_NONE;
                AddOrRemoveChosenMove(sChooseMonsPtr->chosenMoves[sChooseMonsPtr->monsCursor], sChooseMonsPtr->swappingMove);
                pressed = TRUE;
            }

            if (pressed)
            {
                PlaySE(SE_SELECT);
                sChooseMonsPtr->optionsCursor = MODIFY_MOVES;
                sChooseMonsPtr->moveSwapActive = FALSE;
                RedrawListMenu(sChooseMonsPtr->moveListMenuTask);
                HighlightWhole3rdWindow(&sModifyMovesWindow);
            }
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
        {
            PlaySE(SE_SELECT);
            HighlightMonRow(sChooseMonsPtr->monsCursor);
        }

        if (TEST_BUTTON(gMain.newKeys, A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (sChooseMonsPtr->monsCursor != MENU_OPTIONS_COUNT - 1) // Not CONFIRM
            {
                SwitchToSpeciesOptionsWindow(sChooseMonsPtr->monsCursor);
                sChooseMonsPtr->secondWindowActive = TRUE;
            }
            else
            {
                SaveChosenTeam();
                MoveChosenTeamToParty();
                FreeRemoveEverything();
                ScriptContext_Enable();
                DestroyTask(taskId);
            }
        }
    }
}
