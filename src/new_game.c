#include "global.h"
#include "new_game.h"
#include "random.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "mauville_old_man.h"
#include "match_call.h"
#include "lilycove_lady.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "trainer_hill.h"
#include "tv.h"
#include "coins.h"
#include "text.h"
#include "overworld.h"
#include "mail.h"
#include "battle_records.h"
#include "item.h"
#include "pokedex.h"
#include "apprentice.h"
#include "frontier_util.h"
#include "pokedex.h"
#include "save.h"
#include "link_rfu.h"
#include "main.h"
#include "contest.h"
#include "item_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_jump.h"
#include "decoration_inventory.h"
#include "secret_base.h"
#include "player_pc.h"
#include "field_specials.h"
#include "berry_powder.h"
#include "mystery_gift.h"
#include "union_room_chat.h"
#include "constants/map_groups.h"
#include "constants/items.h"
#include "difficulty.h"
#include "follower_npc.h"
#include "string_util.h"
#include "mansion_floor_generation.h"
#include "script_pokemon_util.h"
#include "script.h"

extern const u8 EventScript_ResetAllMapFlags[];

static void ClearFrontierRecord(void);
static void WarpToTruck(void);
static void ResetMiniGamesRecords(void);
static void ResetItemFlags(void);
static void ResetDexNav(void);

EWRAM_DATA bool8 gDifferentSaveFile = FALSE;
EWRAM_DATA bool8 gEnableContestDebugging = FALSE;

static const struct ContestWinner sContestWinnerPicDummy =
{
    .monName = _(""),
    .trainerName = _("")
};

void SetTrainerId(u32 trainerId, u8 *dst)
{
    dst[0] = trainerId;
    dst[1] = trainerId >> 8;
    dst[2] = trainerId >> 16;
    dst[3] = trainerId >> 24;
}

u32 GetTrainerId(u8 *trainerId)
{
    return (trainerId[3] << 24) | (trainerId[2] << 16) | (trainerId[1] << 8) | (trainerId[0]);
}

void CopyTrainerId(u8 *dst, u8 *src)
{
    s32 i;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        dst[i] = src[i];
}

static void InitPlayerTrainerId(void)
{
    u32 trainerId = (Random() << 16) | GetGeneratedTrainerIdLower();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
}

// L=A isnt set here for some reason.
static void SetDefaultOptions(void)
{
    gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_MID;
    gSaveBlock2Ptr->optionsWindowFrameType = 0;
    gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_MONO;
    gSaveBlock2Ptr->optionsBattleStyle = OPTIONS_BATTLE_STYLE_SHIFT;
    gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
    gSaveBlock2Ptr->regionMapZoom = FALSE;
}

static void ClearPokedexFlags(void)
{
    gUnusedPokedexU8 = 0;
    memset(&gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    memset(&gSaveBlock1Ptr->dexSeen, 0, sizeof(gSaveBlock1Ptr->dexSeen));
}

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();

    // Clear Museum paintings
    for (i = MUSEUM_CONTEST_WINNERS_START; i < NUM_CONTEST_WINNERS; i++)
        gSaveBlock1Ptr->contestWinners[i] = sContestWinnerPicDummy;
}

static void ClearFrontierRecord(void)
{
    CpuFill32(0, &gSaveBlock2Ptr->frontier, sizeof(gSaveBlock2Ptr->frontier));

    gSaveBlock2Ptr->frontier.opponentNames[0][0] = EOS;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = EOS;
}

static void WarpToTruck(void)
{
    SetWarpDestination(MAP_GROUP(MAP_PETALBURG_CITY), MAP_NUM(MAP_PETALBURG_CITY), WARP_ID_NONE, 24, 46);
    WarpIntoMap();
}

void Sav2_ClearSetDefault(void)
{
    ClearSav2();
    SetDefaultOptions();
}

void ResetMenuAndMonGlobals(void)
{
    gDifferentSaveFile = FALSE;
    ResetPokedexScrollPositions();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    ResetPokeblockScrollPositions();
}

static void SetFirstPlayerSprite(void)
{
    gSaveBlock2Ptr->playerSpriteIsShiny = TRUE;
    gSaveBlock2Ptr->playerSpriteMonId = SPECIES_PHANPY;
}

static const u16 sOtherItemsSet[] = {
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_ENIGMA_BERRY,
    ITEM_ENIGMA_BERRY,
    ITEM_ENIGMA_BERRY,
    ITEM_ENIGMA_BERRY,
    ITEM_ENIGMA_BERRY,
    ITEM_STARF_BERRY,
    ITEM_STARF_BERRY,
    ITEM_STARF_BERRY,
    ITEM_STARF_BERRY,
    ITEM_STARF_BERRY,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY,
    ITEM_LIFE_ORB,
    ITEM_LIFE_ORB,
    ITEM_CHOICE_SCARF,
    ITEM_CHOICE_SCARF,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SPECS,
    ITEM_CHOICE_SPECS,
    ITEM_BRIGHTPOWDER,
    ITEM_BRIGHTPOWDER,
    ITEM_QUICK_CLAW,
    ITEM_QUICK_CLAW,
    ITEM_KINGS_ROCK,
    ITEM_KINGS_ROCK,
    ITEM_ROCKY_HELMET,
    ITEM_ROCKY_HELMET,
    ITEM_ASSAULT_VEST,
    ITEM_ASSAULT_VEST,
    ITEM_EXPERT_BELT,
    ITEM_EXPERT_BELT,
};

static const u16 sUniqueItemsSet[UNIQUE_ITEMS_COUNT] = {
    UNIQUE_ITEM_BLACK_DISC,
    UNIQUE_ITEM_GREEN_DISC,
    UNIQUE_ITEM_GRAY_DISC,
    UNIQUE_ITEM_PURPLE_DISC,
    UNIQUE_ITEM_RED_DISC,
    UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1,
    UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2,
    UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3,
    UNIQUE_ITEM_PHOTO_1,
    UNIQUE_ITEM_PHOTO_2,
    UNIQUE_ITEM_PHOTO_3,
    UNIQUE_ITEM_PHOTO_4,
    UNIQUE_ITEM_PHOTO_5,
};

static bool32 PlayerObtainedUniqueItem(u32 itemId)
{
    s32 i;
    for (i = 0; i < UNIQUE_ITEMS_COUNT; i++) {
        if (gSaveBlock1Ptr->availableItems.unique.obtainedArr[i] == itemId)
            return TRUE;
    }
    return FALSE;
}

static void SetAvailableItems(struct UniqueItems *unique)
{
    s32 i, forcedUniqueId[2], uniqueId;
    s32 uniqueGiven;
    u16 shuffledItems[OTHER_ITEMS_COUNT];
    u16 uniqueItems[UNIQUE_ITEMS_COUNT];

    memcpy(shuffledItems, sOtherItemsSet, sizeof(sOtherItemsSet));
    memcpy(uniqueItems, sUniqueItemsSet, sizeof(sUniqueItemsSet));

    Shuffle16(shuffledItems, ARRAY_COUNT(sOtherItemsSet));
    Shuffle16(uniqueItems, ARRAY_COUNT(sUniqueItemsSet));

    gSaveBlock1Ptr->availableItems = (struct AvailableItems) {0};
    gSaveBlock1Ptr->availableItems.unique = *unique;
    for (i = 0; i < ARRAY_COUNT(sOtherItemsSet); i++) {
        gSaveBlock1Ptr->availableItems.other.arr[i] = shuffledItems[i];
    }
    // Choose two slots from 0 ... 17 to force unique items
    forcedUniqueId[0] = RandomUniform(0, 0, 17);
    do {
        forcedUniqueId[1] = RandomUniform(0, 0, 17);
    } while (forcedUniqueId[0] == forcedUniqueId[1]);

    // Choose 2 random unique items the player did not obtain yet
    uniqueGiven = 0;
    for (uniqueId = 0; uniqueId < UNIQUE_ITEMS_COUNT; uniqueId++) {
        u16 randUnique = uniqueItems[uniqueId];
        if (!PlayerObtainedUniqueItem(randUnique)) {
            gSaveBlock1Ptr->availableItems.other.arr[forcedUniqueId[uniqueGiven++]] = randUnique;
            if (uniqueGiven >= 2)
                break;
        }
    }

    for (; i < OTHER_ITEMS_COUNT; i++) {
        gSaveBlock1Ptr->availableItems.other.arr[i] = 0;
    }
}

static void SetDummyPlayerName(void)
{
    const u8 *name = COMPOUND_STRING("Folded");

    StringCopy(gSaveBlock2Ptr->playerName, name);
}

static const u8 *sPhanpyNickname = COMPOUND_STRING("Tuskan");
static const u8 *sSwabluNickname = COMPOUND_STRING("Fluffball");

static void SetStartingPokemon(void)
{
    u32 otGender = FEMALE;
    u16 moves[MAX_MON_MOVES] = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_NONE};
    u8 evs[NUM_STATS]        = {0, 0, 0, 0, 0, 0};
    u8 ivs[NUM_STATS]        = {MAX_IV_MASK, MAX_IV_MASK, MAX_IV_MASK, MAX_IV_MASK, MAX_IV_MASK, MAX_IV_MASK};
    ScriptGiveMonParameterized(0, 0, SPECIES_PHANPY, 1, 0, BALL_POKE, NATURE_ADAMANT, 0, MON_MALE, evs, ivs, moves, TRUE, FALSE, NUMBER_OF_MON_TYPES, 0);
    ScriptGiveMonParameterized(0, 1, SPECIES_SWABLU, 1, 0, BALL_POKE, NATURE_BOLD, 2, MON_FEMALE, evs, ivs, moves, TRUE, FALSE, NUMBER_OF_MON_TYPES, 0);

    SetMonData(&gPlayerParty[0], MON_DATA_NICKNAME, sPhanpyNickname);
    SetMonData(&gPlayerParty[1], MON_DATA_NICKNAME, sSwabluNickname);

    SetMonData(&gPlayerParty[0], MON_DATA_OT_GENDER, &otGender);
    SetMonData(&gPlayerParty[1], MON_DATA_OT_GENDER, &otGender);

    FlagSet(FLAG_SYS_POKEMON_GET);
}

void NewGameInitData(void)
{
    struct UniqueItems uniqueItems = gSaveBlock1Ptr->availableItems.unique; // Preserve unique items

    if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
        RtcReset();

    gDifferentSaveFile = TRUE;
    gSaveBlock2Ptr->encryptionKey = 0;
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetPokedex();
    ClearFrontierRecord();
    ClearSav1();
    ClearSav3();
    ClearAllMail();
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
    gSaveBlock2Ptr->gcnLinkFlags = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
    ClearPokedexFlags();
    InitEventData();
    ClearTVShowData();
    ResetGabbyAndTy();
    ClearSecretBases();
    ClearBerryTrees();
    SetMoney(&gSaveBlock1Ptr->money, 3000);
    SetCoins(0);
    ResetLinkContestBoolean();
    ResetGameStats();
    ClearAllContestWinnerPics();
    ClearPlayerLinkBattleRecords();
    InitSeedotSizeRecord();
    InitLotadSizeRecord();
    gPlayerPartyCount = 0;
    ZeroPlayerPartyMons();
    ResetPokemonStorageSystem();
    DeactivateAllRoamers();
    gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    ClearBag();
    NewGameInitPCItems();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    WarpToTruck();
    RunScriptImmediately(EventScript_ResetAllMapFlags);
    ResetMiniGamesRecords();
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    ClearMysteryGift();
    WipeTrainerNameRecords();
    ResetTrainerHillResults();
    ResetContestLinkResults();
    SetCurrentDifficultyLevel(DIFFICULTY_NORMAL);
    ResetItemFlags();
    ResetDexNav();
    ClearFollowerNPCData();
    SetDummyPlayerName();
    SetFirstPlayerSprite();
    SetAvailableItems(&uniqueItems);
    GenerateAllMansionFloorLayouts();
    SetStartingPokemon();
}

static void ResetMiniGamesRecords(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokemonJumpRecords();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}

static void ResetItemFlags(void)
{
#if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_FIRST_TIME
    memset(&gSaveBlock3Ptr->itemFlags, 0, sizeof(gSaveBlock3Ptr->itemFlags));
#endif
}

static void ResetDexNav(void)
{
#if USE_DEXNAV_SEARCH_LEVELS == TRUE
    memset(gSaveBlock3Ptr->dexNavSearchLevels, 0, sizeof(gSaveBlock3Ptr->dexNavSearchLevels));
#endif
    gSaveBlock3Ptr->dexNavChain = 0;
}
