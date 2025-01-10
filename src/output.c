// Contents of pokenav_match_call_data.c
#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "pokenav.h"
#include "strings.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"


// NPC below means non-trainer character (no rematch or check page)
// Steven also uses this type but has a check page by using a MatchCallCheckPageOverride
enum
{
    MC_TYPE_NPC_pokenav_match_call_data,
    MC_TYPE_TRAINER_pokenav_match_call_data,
    MC_TYPE_WALLY_pokenav_match_call_data,
    MC_TYPE_BIRCH_pokenav_match_call_data,
    MC_TYPE_RIVAL_pokenav_match_call_data,
    MC_TYPE_LEADER_pokenav_match_call_data
};

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u8 mapSec;
    u16 flag;
};

struct MatchCallStructNPC {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

// Shared by MC_TYPE_TRAINER_pokenav_match_call_data and MC_TYPE_LEADER_pokenav_match_call_data
struct MatchCallStructTrainer {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallLocationOverride {
    u16 flag;
    u8 mapSec;
};

struct MatchCallWally {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallLocationOverride *locationData;
};

struct MatchCallBirch {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallRival {
    u8 type;
    u8 playerGender;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStructNPC *npc;
    const struct MatchCallStructTrainer *trainer;
    const struct MatchCallWally *wally;
    const struct MatchCallBirch *birch;
    const struct MatchCallRival *rival;
    const struct MatchCallStructTrainer *leader;
} match_call_t;

struct MatchCallCheckPageOverride {
    u16 idx;
    u16 facilityClass;
    u32 flag;
    const u8 *flavorTexts[CHECK_PAGE_ENTRY_COUNT];
};

// Static RAM declarations

// Static ROM declarations

static bool32 MatchCall_GetEnabled_NPC_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_GetEnabled_Trainer_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_GetEnabled_Wally_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_GetEnabled_Birch_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_GetEnabled_Rival_pokenav_match_call_data(match_call_t);

static u8 MatchCall_GetMapSec_NPC_pokenav_match_call_data(match_call_t);
static u8 MatchCall_GetMapSec_Trainer_pokenav_match_call_data(match_call_t);
static u8 MatchCall_GetMapSec_Wally_pokenav_match_call_data(match_call_t);
static u8 MatchCall_GetMapSec_Birch_pokenav_match_call_data(match_call_t);
static u8 MatchCall_GetMapSec_Rival_pokenav_match_call_data(match_call_t);

static bool32 MatchCall_IsRematchable_NPC_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_IsRematchable_Trainer_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_IsRematchable_Wally_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_IsRematchable_Birch_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_IsRematchable_Rival_pokenav_match_call_data(match_call_t);

static bool32 MatchCall_HasCheckPage_NPC_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_HasCheckPage_Trainer_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_HasCheckPage_Wally_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_HasCheckPage_Birch_pokenav_match_call_data(match_call_t);
static bool32 MatchCall_HasCheckPage_Rival_pokenav_match_call_data(match_call_t);

static u32 MatchCall_GetRematchTableIdx_NPC_pokenav_match_call_data(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Trainer_pokenav_match_call_data(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Wally_pokenav_match_call_data(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Birch_pokenav_match_call_data(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Rival_pokenav_match_call_data(match_call_t);

static void MatchCall_GetMessage_NPC_pokenav_match_call_data(match_call_t, u8 *);
static void MatchCall_GetMessage_Trainer_pokenav_match_call_data(match_call_t, u8 *);
static void MatchCall_GetMessage_Wally_pokenav_match_call_data(match_call_t, u8 *);
static void MatchCall_GetMessage_Birch_pokenav_match_call_data(match_call_t, u8 *);
static void MatchCall_GetMessage_Rival_pokenav_match_call_data(match_call_t, u8 *);

static void MatchCall_GetNameAndDesc_NPC_pokenav_match_call_data(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Trainer_pokenav_match_call_data(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Wally_pokenav_match_call_data(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Birch_pokenav_match_call_data(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Rival_pokenav_match_call_data(match_call_t, const u8 **, const u8 **);

static void MatchCall_BufferCallMessageText_pokenav_match_call_data(const match_call_text_data_t *, u8 *);
static void MatchCall_BufferCallMessageTextByRematchTeam_pokenav_match_call_data(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx_pokenav_match_call_data(u32, const u8 **, const u8 **);

// .rodata

static const match_call_text_data_t sMrStoneTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_MrStone1,  0xFFFF,                              FLAG_ENABLE_MR_STONE_POKENAV },
    { MatchCall_Text_MrStone2,  FLAG_ENABLE_MR_STONE_POKENAV,        0xFFFF },
    { MatchCall_Text_MrStone3,  FLAG_DELIVERED_STEVEN_LETTER,        0xFFFF },
    { MatchCall_Text_MrStone4,  FLAG_RECEIVED_EXP_SHARE,             0xFFFF },
    { MatchCall_Text_MrStone5,  FLAG_RECEIVED_HM_STRENGTH,           0xFFFF },
    { MatchCall_Text_MrStone6,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_MrStone7,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_MrStone8,  FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_MrStone9,  FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_MrStone10, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_MrStone11, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallStructNPC sMrStoneMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_NPC_pokenav_match_call_data,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = 0xFFFF,
    .desc = COMPOUND_STRING("DEVON PRES"),
    .name = COMPOUND_STRING("MR. STONE"),
    .textData = sMrStoneTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sNormanTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Norman1, FLAG_ENABLE_NORMAN_MATCH_CALL, 0xFFFF },
    { MatchCall_Text_Norman2, FLAG_DEFEATED_DEWFORD_GYM,     0xFFFF },
    { MatchCall_Text_Norman3, FLAG_DEFEATED_LAVARIDGE_GYM,   0xFFFF },
    { MatchCall_Text_Norman4, FLAG_DEFEATED_PETALBURG_GYM,   0xFFFF },
    { MatchCall_Text_Norman5, FLAG_RECEIVED_RED_OR_BLUE_ORB, 0xFFFF },
    { MatchCall_Text_Norman6, 0xFFFE,                        0xFFFF },
    { MatchCall_Text_Norman7, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { MatchCall_Text_Norman8, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { MatchCall_Text_Norman9, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { NULL,                   0xFFFF,                        0xFFFF }
};

static const struct MatchCallStructTrainer sNormanMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_PETALBURG_CITY,
    .flag = FLAG_ENABLE_NORMAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_NORMAN,
    .desc = COMPOUND_STRING("RELIABLE ONE"),
    .name = COMPOUND_STRING("DAD"),
    .textData = sNormanTextScripts_pokenav_match_call_data
};

static const struct MatchCallBirch sProfBirchMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_BIRCH_pokenav_match_call_data,
    .mapSec = 0,
    .flag = FLAG_ENABLE_PROF_BIRCH_MATCH_CALL,
    .desc = COMPOUND_STRING("{PKMN} PROF."),
    .name = COMPOUND_STRING("PROF. BIRCH")
};

static const match_call_text_data_t sMomTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Mom1, 0xFFFF,                      0xFFFF },
    { MatchCall_Text_Mom2, FLAG_DEFEATED_PETALBURG_GYM, 0xFFFF },
    { MatchCall_Text_Mom3, FLAG_SYS_GAME_CLEAR,         0xFFFF },
    { NULL,                0xFFFF,                      0xFFFF }
};

static const struct MatchCallStructNPC sMomMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_NPC_pokenav_match_call_data,
    .mapSec = MAPSEC_LITTLEROOT_TOWN,
    .flag = FLAG_ENABLE_MOM_MATCH_CALL,
    .desc = COMPOUND_STRING("CALM & KIND"),
    .name = COMPOUND_STRING("MOM"),
    .textData = sMomTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sStevenTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Steven1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Steven2, FLAG_RUSTURF_TUNNEL_OPENED,          0xFFFF },
    { MatchCall_Text_Steven3, FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Steven4, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Steven5, FLAG_DEFEATED_MOSSDEEP_GYM,          0xFFFF },
    { MatchCall_Text_Steven6, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Steven7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                   0xFFFF,                              0xFFFF },
};

static const struct MatchCallStructNPC sStevenMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_NPC_pokenav_match_call_data,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_REGISTERED_STEVEN_POKENAV,
    .desc = COMPOUND_STRING("HARD AS ROCK"),
    .name = COMPOUND_STRING("STEVEN"),
    .textData = sStevenTextScripts_pokenav_match_call_data
};

static const u8 gText_MayBrendanMatchCallDesc_pokenav_match_call_data[] = _("RAD NEIGHBOR");

static const match_call_text_data_t sMayTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_May1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_May2,  FLAG_DEFEATED_DEWFORD_GYM,           0xFFFF },
    { MatchCall_Text_May3,  FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { MatchCall_Text_May4,  FLAG_HIDE_MAUVILLE_CITY_WALLY,       0xFFFF },
    { MatchCall_Text_May5,  FLAG_RECEIVED_HM_STRENGTH,           0xFFFF },
    { MatchCall_Text_May6,  FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_May7,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_May8,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_May9,  FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_May10, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_May11, FLAG_MET_TEAM_AQUA_HARBOR,           0xFFFF },
    { MatchCall_Text_May12, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_May13, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_May14, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_May15, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                 0xFFFF,                              0xFFFF }
};

static const struct MatchCallRival sMayMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_RIVAL_pokenav_match_call_data,
    .playerGender = MALE,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gText_MayBrendanMatchCallDesc_pokenav_match_call_data,
    .name = gText_ExpandedPlaceholder_May,
    .textData = sMayTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sBrendanTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Brendan1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_Brendan2,  FLAG_DEFEATED_DEWFORD_GYM,           0xFFFF },
    { MatchCall_Text_Brendan3,  FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { MatchCall_Text_Brendan4,  FLAG_HIDE_MAUVILLE_CITY_WALLY,       0xFFFF },
    { MatchCall_Text_Brendan5,  FLAG_RECEIVED_HM_STRENGTH,           0xFFFF },
    { MatchCall_Text_Brendan6,  FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_Brendan7,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_Brendan8,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Brendan9,  FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Brendan10, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_Brendan11, FLAG_MET_TEAM_AQUA_HARBOR,           0xFFFF },
    { MatchCall_Text_Brendan12, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Brendan13, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Brendan14, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_Brendan15, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallRival sBrendanMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_RIVAL_pokenav_match_call_data,
    .playerGender = FEMALE,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gText_MayBrendanMatchCallDesc_pokenav_match_call_data,
    .name = gText_ExpandedPlaceholder_Brendan,
    .textData = sBrendanTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sWallyTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Wally1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Wally2, FLAG_RUSTURF_TUNNEL_OPENED,          0xFFFF },
    { MatchCall_Text_Wally3, FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_Wally4, FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Wally5, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_Wally6, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Wally7, FLAG_DEFEATED_WALLY_VICTORY_ROAD,    0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};

static const struct MatchCallLocationOverride sWallyLocationData_pokenav_match_call_data[] = {
    { FLAG_HIDE_MAUVILLE_CITY_WALLY,          MAPSEC_VERDANTURF_TOWN },
    { FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,    MAPSEC_NONE },
    { FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY,  MAPSEC_VICTORY_ROAD },
    { 0xFFFF,                                 MAPSEC_NONE }
};

static const struct MatchCallWally sWallyMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_WALLY_pokenav_match_call_data,
    .mapSec = 0,
    .flag = FLAG_ENABLE_WALLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_WALLY_VR,
    .desc = COMPOUND_STRING("{PKMN} LOVER"),
    .textData = sWallyTextScripts_pokenav_match_call_data,
    .locationData = sWallyLocationData_pokenav_match_call_data
};

static const match_call_text_data_t sScottTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Scott1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Scott2, FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY,  0xFFFF },
    { MatchCall_Text_Scott3, FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Scott4, FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Scott5, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Scott6, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_Scott7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};


static const struct MatchCallStructNPC sScottMatchCallHeader_pokenav_match_call_data =
{
    .type = 0,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_ENABLE_SCOTT_MATCH_CALL,
    .desc = COMPOUND_STRING("ELUSIVE EYES"),
    .name = COMPOUND_STRING("SCOTT"),
    .textData = sScottTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sRoxanneTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Roxanne1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Roxanne2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Roxanne3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Roxanne4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sRoxanneMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = FLAG_ENABLE_ROXANNE_MATCH_CALL,
    .rematchTableIdx = REMATCH_ROXANNE,
    .desc = COMPOUND_STRING("ROCKIN' WHIZ"),
    .name = NULL,
    .textData = sRoxanneTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sBrawlyTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Brawly1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Brawly2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brawly3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brawly4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sBrawlyMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_DEWFORD_TOWN,
    .flag = FLAG_ENABLE_BRAWLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_BRAWLY,
    .desc = COMPOUND_STRING("THE BIG HIT"),
    .name = NULL,
    .textData = sBrawlyTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sWattsonTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Wattson1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Wattson2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Wattson3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Wattson4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sWattsonMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_MAUVILLE_CITY,
    .flag = FLAG_ENABLE_WATTSON_MATCH_CALL,
    .rematchTableIdx = REMATCH_WATTSON,
    .desc = COMPOUND_STRING("SWELL SHOCK"),
    .name = NULL,
    .textData = sWattsonTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sFlanneryTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Flannery1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Flannery2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Flannery3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Flannery4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sFlanneryMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_LAVARIDGE_TOWN,
    .flag = FLAG_ENABLE_FLANNERY_MATCH_CALL,
    .rematchTableIdx = REMATCH_FLANNERY,
    .desc = COMPOUND_STRING("PASSION BURN"),
    .name = NULL,
    .textData = sFlanneryTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sWinonaTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Winona1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Winona2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Winona3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Winona4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sWinonaMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_FORTREE_CITY,
    .flag = FLAG_ENABLE_WINONA_MATCH_CALL,
    .rematchTableIdx = REMATCH_WINONA,
    .desc = COMPOUND_STRING("SKY TAMER"),
    .name = NULL,
    .textData = sWinonaTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sTateLizaTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_TateLiza1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_TateLiza2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_TateLiza3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_TateLiza4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sTateLizaMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_MOSSDEEP_CITY,
    .flag = FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL,
    .rematchTableIdx = REMATCH_TATE_AND_LIZA,
    .desc = COMPOUND_STRING("MYSTIC DUO"),
    .name = NULL,
    .textData = sTateLizaTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sJuanTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Juan1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Juan2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Juan3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Juan4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                 0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sJuanMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_SOOTOPOLIS_CITY,
    .flag = FLAG_ENABLE_JUAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_JUAN,
    .desc = COMPOUND_STRING("DANDY CHARM"),
    .name = NULL,
    .textData = sJuanTextScripts_pokenav_match_call_data
};

static const u8 gText_EliteFourMatchCallDesc_pokenav_match_call_data[] = _("ELITE FOUR");

static const match_call_text_data_t sSidneyTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Sidney, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sSidneyMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_SIDNEY,
    .rematchTableIdx = REMATCH_SIDNEY,
    .desc = gText_EliteFourMatchCallDesc_pokenav_match_call_data,
    .name = NULL,
    .textData = sSidneyTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sPhoebeTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Phoebe, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sPhoebeMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_PHOEBE,
    .rematchTableIdx = REMATCH_PHOEBE,
    .desc = gText_EliteFourMatchCallDesc_pokenav_match_call_data,
    .name = NULL,
    .textData = sPhoebeTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sGlaciaTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Glacia, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sGlaciaMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_GLACIA,
    .rematchTableIdx = REMATCH_GLACIA,
    .desc = gText_EliteFourMatchCallDesc_pokenav_match_call_data,
    .name = NULL,
    .textData = sGlaciaTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sDrakeTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Drake, 0xFFFF, 0xFFFF },
    { NULL,                 0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sDrakeMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_DRAKE,
    .rematchTableIdx = REMATCH_DRAKE,
    .desc = gText_EliteFourMatchCallDesc_pokenav_match_call_data,
    .name = NULL,
    .textData = sDrakeTextScripts_pokenav_match_call_data
};

static const match_call_text_data_t sWallaceTextScripts_pokenav_match_call_data[] = {
    { MatchCall_Text_Wallace, 0xFFFF, 0xFFFF },
    { NULL,                   0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sWallaceMatchCallHeader_pokenav_match_call_data =
{
    .type = MC_TYPE_LEADER_pokenav_match_call_data,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REGISTERED_WALLACE,
    .rematchTableIdx = REMATCH_WALLACE,
    .desc = COMPOUND_STRING("CHAMPION"),
    .name = NULL,
    .textData = sWallaceTextScripts_pokenav_match_call_data
};

static const match_call_t sMatchCallHeaders_pokenav_match_call_data[] = {
    [MC_HEADER_MR_STONE]   = {.npc    = &sMrStoneMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_PROF_BIRCH] = {.birch  = &sProfBirchMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_BRENDAN]    = {.rival  = &sBrendanMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_MAY]        = {.rival  = &sMayMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_WALLY]      = {.wally  = &sWallyMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_NORMAN]     = {.leader = &sNormanMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_MOM]        = {.npc    = &sMomMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_STEVEN]     = {.npc    = &sStevenMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_SCOTT]      = {.npc    = &sScottMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_ROXANNE]    = {.leader = &sRoxanneMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_BRAWLY]     = {.leader = &sBrawlyMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_WATTSON]    = {.leader = &sWattsonMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_FLANNERY]   = {.leader = &sFlanneryMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_WINONA]     = {.leader = &sWinonaMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_TATE_LIZA]  = {.leader = &sTateLizaMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_JUAN]       = {.leader = &sJuanMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_SIDNEY]     = {.leader = &sSidneyMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_PHOEBE]     = {.leader = &sPhoebeMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_GLACIA]     = {.leader = &sGlaciaMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_DRAKE]      = {.leader = &sDrakeMatchCallHeader_pokenav_match_call_data},
    [MC_HEADER_WALLACE]    = {.leader = &sWallaceMatchCallHeader_pokenav_match_call_data}
};

static bool32 (*const sMatchCallGetEnabledFuncs[])(match_call_t) = {
    MatchCall_GetEnabled_NPC_pokenav_match_call_data,
    MatchCall_GetEnabled_Trainer_pokenav_match_call_data,
    MatchCall_GetEnabled_Wally_pokenav_match_call_data,
    MatchCall_GetEnabled_Rival_pokenav_match_call_data,
    MatchCall_GetEnabled_Birch_pokenav_match_call_data
};

static u8 (*const sMatchCallGetMapSecFuncs[])(match_call_t) = {
    MatchCall_GetMapSec_NPC_pokenav_match_call_data,
    MatchCall_GetMapSec_Trainer_pokenav_match_call_data,
    MatchCall_GetMapSec_Wally_pokenav_match_call_data,
    MatchCall_GetMapSec_Rival_pokenav_match_call_data,
    MatchCall_GetMapSec_Birch_pokenav_match_call_data
};

static bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t) = {
    MatchCall_IsRematchable_NPC_pokenav_match_call_data,
    MatchCall_IsRematchable_Trainer_pokenav_match_call_data,
    MatchCall_IsRematchable_Wally_pokenav_match_call_data,
    MatchCall_IsRematchable_Rival_pokenav_match_call_data,
    MatchCall_IsRematchable_Birch_pokenav_match_call_data
};

static bool32 (*const sMatchCall_HasCheckPageFunctions[])(match_call_t) = {
    MatchCall_HasCheckPage_NPC_pokenav_match_call_data,
    MatchCall_HasCheckPage_Trainer_pokenav_match_call_data,
    MatchCall_HasCheckPage_Wally_pokenav_match_call_data,
    MatchCall_HasCheckPage_Rival_pokenav_match_call_data,
    MatchCall_HasCheckPage_Birch_pokenav_match_call_data
};

static u32 (*const sMatchCall_GetRematchTableIdxFunctions[])(match_call_t) = {
    MatchCall_GetRematchTableIdx_NPC_pokenav_match_call_data,
    MatchCall_GetRematchTableIdx_Trainer_pokenav_match_call_data,
    MatchCall_GetRematchTableIdx_Wally_pokenav_match_call_data,
    MatchCall_GetRematchTableIdx_Rival_pokenav_match_call_data,
    MatchCall_GetRematchTableIdx_Birch_pokenav_match_call_data
};

static void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *) = {
    MatchCall_GetMessage_NPC_pokenav_match_call_data,
    MatchCall_GetMessage_Trainer_pokenav_match_call_data,
    MatchCall_GetMessage_Wally_pokenav_match_call_data,
    MatchCall_GetMessage_Rival_pokenav_match_call_data,
    MatchCall_GetMessage_Birch_pokenav_match_call_data
};

static void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **) = {
    MatchCall_GetNameAndDesc_NPC_pokenav_match_call_data,
    MatchCall_GetNameAndDesc_Trainer_pokenav_match_call_data,
    MatchCall_GetNameAndDesc_Wally_pokenav_match_call_data,
    MatchCall_GetNameAndDesc_Rival_pokenav_match_call_data,
    MatchCall_GetNameAndDesc_Birch_pokenav_match_call_data
};

static const u8 gText_MatchCallSteven_Strategy[] = _("Attack the weak points!");
static const u8 gText_MatchCallSteven_Pokemon[] = _("Ultimate STEEL POKéMON.");

static const u8 gText_MatchCallBrendan_Strategy[] = _("Battle with knowledge!");
static const u8 gText_MatchCallBrendan_Pokemon[] = _("I will use various POKéMON.");
static const u8 gText_MatchCallBrendan_Intro1[] = _("I'll be a better POKéMON");
static const u8 gText_MatchCallBrendan_Intro2[] = _("prof than my father is!");

static const u8 gText_MatchCallMay_Strategy[] = _("I'm not so good at battles.");
static const u8 gText_MatchCallMay_Pokemon[] = _("I'll use any POKéMON!");
static const u8 gText_MatchCallMay_Intro1[] = _("My POKéMON and I help");
static const u8 gText_MatchCallMay_Intro2[] = _("my father's research.");

static const struct MatchCallCheckPageOverride sCheckPageOverrides_pokenav_match_call_data[] = {
    {
        .idx = MC_HEADER_STEVEN,
        .facilityClass = FACILITY_CLASS_STEVEN,
        .flag = 0xFFFF,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon,
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("I'd climb even waterfalls"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("to find a rare stone!")
        }
    },
    {
        .idx = MC_HEADER_STEVEN,
        .facilityClass = FACILITY_CLASS_STEVEN,
        .flag = FLAG_DEFEATED_MOSSDEEP_GYM,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon,
            [CHECK_PAGE_INTRO_1]  = COMPOUND_STRING("I'm the strongest and most"),
            [CHECK_PAGE_INTRO_2]  = COMPOUND_STRING("energetic after all!")
        }
    },
    {
        .idx = MC_HEADER_BRENDAN,
        .facilityClass = FACILITY_CLASS_BRENDAN,
        .flag = 0xFFFF,
        .flavorTexts = MCFLAVOR(Brendan)
    },
    {
        .idx = MC_HEADER_MAY,
        .facilityClass = FACILITY_CLASS_MAY,
        .flag = 0xFFFF,
        .flavorTexts = MCFLAVOR(May)
    }
};

// .text

static u32 MatchCallGetFunctionIndex_pokenav_match_call_data(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        default:
        case MC_TYPE_NPC_pokenav_match_call_data:
            return 0;
        case MC_TYPE_TRAINER_pokenav_match_call_data:
        case MC_TYPE_LEADER_pokenav_match_call_data:
            return 1;
        case MC_TYPE_WALLY_pokenav_match_call_data:
            return 2;
        case MC_TYPE_RIVAL_pokenav_match_call_data:
            return 3;
        case MC_TYPE_BIRCH_pokenav_match_call_data:
            return 4;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 MatchCall_GetEnabled(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders_pokenav_match_call_data))
        return FALSE;
    matchCall = sMatchCallHeaders_pokenav_match_call_data[idx];
    i = MatchCallGetFunctionIndex_pokenav_match_call_data(matchCall);
    return sMatchCallGetEnabledFuncs[i](matchCall);
}

static bool32 MatchCall_GetEnabled_NPC_pokenav_match_call_data(match_call_t matchCall)
{
    if (matchCall.npc->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.npc->flag);
}

static bool32 MatchCall_GetEnabled_Trainer_pokenav_match_call_data(match_call_t matchCall)
{
    if (matchCall.trainer->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.trainer->flag);
}

static bool32 MatchCall_GetEnabled_Wally_pokenav_match_call_data(match_call_t matchCall)
{
    if (matchCall.wally->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.wally->flag);
}

static bool32 MatchCall_GetEnabled_Rival_pokenav_match_call_data(match_call_t matchCall)
{
    if (matchCall.rival->playerGender != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall.rival->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.rival->flag);
}

static bool32 MatchCall_GetEnabled_Birch_pokenav_match_call_data(match_call_t matchCall)
{
    return FlagGet(matchCall.birch->flag);
}

u8 MatchCall_GetMapSec(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders_pokenav_match_call_data))
        return 0;
    matchCall = sMatchCallHeaders_pokenav_match_call_data[idx];
    i = MatchCallGetFunctionIndex_pokenav_match_call_data(matchCall);
    return sMatchCallGetMapSecFuncs[i](matchCall);
}

static u8 MatchCall_GetMapSec_NPC_pokenav_match_call_data(match_call_t matchCall)
{
    return matchCall.npc->mapSec;
}

static u8 MatchCall_GetMapSec_Trainer_pokenav_match_call_data(match_call_t matchCall)
{
    return matchCall.trainer->mapSec;
}

static u8 MatchCall_GetMapSec_Wally_pokenav_match_call_data(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.wally->locationData[i].flag != 0xFFFF; i++)
    {
        if (!FlagGet(matchCall.wally->locationData[i].flag))
            break;
    }
    return matchCall.wally->locationData[i].mapSec;
}

static u8 MatchCall_GetMapSec_Rival_pokenav_match_call_data(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

static u8 MatchCall_GetMapSec_Birch_pokenav_match_call_data(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders_pokenav_match_call_data))
        return 0;
    matchCall = sMatchCallHeaders_pokenav_match_call_data[idx];
    i = MatchCallGetFunctionIndex_pokenav_match_call_data(matchCall);
    return sMatchCall_IsRematchableFunctions[i](matchCall);
}

static bool32 MatchCall_IsRematchable_NPC_pokenav_match_call_data(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Trainer_pokenav_match_call_data(match_call_t matchCall)
{
#if FREE_MATCH_CALL == FALSE
    if (matchCall.trainer->rematchTableIdx >= REMATCH_ELITE_FOUR_ENTRIES)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.trainer->rematchTableIdx] ? TRUE : FALSE;
#else
    return FALSE;
#endif //FREE_MATCH_CALL
}

static bool32 MatchCall_IsRematchable_Wally_pokenav_match_call_data(match_call_t matchCall)
{
#if FREE_MATCH_CALL == FALSE
    return gSaveBlock1Ptr->trainerRematches[matchCall.wally->rematchTableIdx] ? TRUE : FALSE;
#else
    return FALSE;
#endif //FREE_MATCH_CALL
}

static bool32 MatchCall_IsRematchable_Rival_pokenav_match_call_data(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Birch_pokenav_match_call_data(match_call_t matchCall)
{
    return FALSE;
}

bool32 MatchCall_HasCheckPage(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders_pokenav_match_call_data))
        return FALSE;
    matchCall = sMatchCallHeaders_pokenav_match_call_data[idx];
    i = MatchCallGetFunctionIndex_pokenav_match_call_data(matchCall);
    if (sMatchCall_HasCheckPageFunctions[i](matchCall))
        return TRUE;
    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides_pokenav_match_call_data); i++)
    {
        if (sCheckPageOverrides_pokenav_match_call_data[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_NPC_pokenav_match_call_data(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Trainer_pokenav_match_call_data(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Wally_pokenav_match_call_data(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Rival_pokenav_match_call_data(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Birch_pokenav_match_call_data(match_call_t matchCall)
{
    return FALSE;
}

u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders_pokenav_match_call_data))
        return REMATCH_TABLE_ENTRIES;
    matchCall = sMatchCallHeaders_pokenav_match_call_data[idx];
    i = MatchCallGetFunctionIndex_pokenav_match_call_data(matchCall);
    return sMatchCall_GetRematchTableIdxFunctions[i](matchCall);
}

static u32 MatchCall_GetRematchTableIdx_NPC_pokenav_match_call_data(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Trainer_pokenav_match_call_data(match_call_t matchCall)
{
    return matchCall.trainer->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Wally_pokenav_match_call_data(match_call_t matchCall)
{
    return matchCall.wally->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Rival_pokenav_match_call_data(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Birch_pokenav_match_call_data(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders_pokenav_match_call_data))
        return;
    matchCall = sMatchCallHeaders_pokenav_match_call_data[idx];
    i = MatchCallGetFunctionIndex_pokenav_match_call_data(matchCall);
    sMatchCall_GetMessageFunctions[i](matchCall, dest);
}

static void MatchCall_GetMessage_NPC_pokenav_match_call_data(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText_pokenav_match_call_data(matchCall.npc->textData, dest);
}

// This is the one functional difference between MC_TYPE_TRAINER_pokenav_match_call_data and MC_TYPE_LEADER_pokenav_match_call_data
static void MatchCall_GetMessage_Trainer_pokenav_match_call_data(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != MC_TYPE_LEADER_pokenav_match_call_data)
        MatchCall_BufferCallMessageText_pokenav_match_call_data(matchCall.trainer->textData, dest);
    else
        MatchCall_BufferCallMessageTextByRematchTeam_pokenav_match_call_data(matchCall.leader->textData, matchCall.leader->rematchTableIdx, dest);
}

static void MatchCall_GetMessage_Wally_pokenav_match_call_data(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText_pokenav_match_call_data(matchCall.wally->textData, dest);
}

static void MatchCall_GetMessage_Rival_pokenav_match_call_data(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText_pokenav_match_call_data(matchCall.rival->textData, dest);
}

static void MatchCall_GetMessage_Birch_pokenav_match_call_data(match_call_t matchCall, u8 *dest)
{
    BufferPokedexRatingForMatchCall(dest);
}

static void MatchCall_BufferCallMessageText_pokenav_match_call_data(const match_call_text_data_t *textData, u8 *dest)
{
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (textData[i].flag != 0xFFFF && FlagGet(textData[i].flag) == TRUE)
            break;
        i--;
    }
    if (textData[i].flag2 != 0xFFFF)
        FlagSet(textData[i].flag2);
    StringExpandPlaceholders(dest, textData[i].text);
}

static void MatchCall_BufferCallMessageTextByRematchTeam_pokenav_match_call_data(const match_call_text_data_t *textData, u16 idx, u8 *dest)
{
#if FREE_MATCH_CALL == FALSE
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
    {
        if (textData[i].flag == 0xFFFE)
            break;
        if (textData[i].flag != 0xFFFF && !FlagGet(textData[i].flag))
            break;
    }
    if (textData[i].flag != 0xFFFE)
    {
        if (i)
            i--;
        if (textData[i].flag2 != 0xFFFF)
            FlagSet(textData[i].flag2);
        StringExpandPlaceholders(dest, textData[i].text);
    }
    else
    {
        if (FlagGet(FLAG_SYS_GAME_CLEAR))
        {
            do
            {
                if (gSaveBlock1Ptr->trainerRematches[idx])
                    i += 2;
                else if (CountBattledRematchTeams(idx) >= 2)
                    i += 3;
                else
                    i++;
            } while (0);
        }

        StringExpandPlaceholders(dest, textData[i].text);
    }
#endif //FREE_MATCH_CALL
}

void MatchCall_GetNameAndDesc(u32 idx, const u8 **desc, const u8 **name)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders_pokenav_match_call_data))
        return;
    matchCall = sMatchCallHeaders_pokenav_match_call_data[idx];
    i = MatchCallGetFunctionIndex_pokenav_match_call_data(matchCall);
    sMatchCall_GetNameAndDescFunctions[i](matchCall, desc, name);
}

static void MatchCall_GetNameAndDesc_NPC_pokenav_match_call_data(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.npc->desc;
    *name = matchCall.npc->name;
}

static void MatchCall_GetNameAndDesc_Trainer_pokenav_match_call_data(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.trainer->name == NULL)
        MatchCall_GetNameAndDescByRematchIdx_pokenav_match_call_data(_matchCall.trainer->rematchTableIdx, desc, name);
    else
        *name = _matchCall.trainer->name;
    *desc = _matchCall.trainer->desc;
}

static void MatchCall_GetNameAndDesc_Wally_pokenav_match_call_data(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    MatchCall_GetNameAndDescByRematchIdx_pokenav_match_call_data(matchCall.wally->rematchTableIdx, desc, name);
    *desc = matchCall.wally->desc;
}

static void MatchCall_GetNameAndDesc_Rival_pokenav_match_call_data(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.rival->desc;
    *name = matchCall.rival->name;
}

static void MatchCall_GetNameAndDesc_Birch_pokenav_match_call_data(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.birch->desc;
    *name = matchCall.birch->name;
}

static void MatchCall_GetNameAndDescByRematchIdx_pokenav_match_call_data(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = GetTrainerStructFromId(GetTrainerIdxByRematchIdx(idx));
    *desc = gTrainerClasses[trainer->trainerClass].name;
    *name = trainer->trainerName;
}

const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides_pokenav_match_call_data); i++)
    {
        if (sCheckPageOverrides_pokenav_match_call_data[i].idx == idx)
        {
            for (; i + 1 < ARRAY_COUNT(sCheckPageOverrides_pokenav_match_call_data) &&
                sCheckPageOverrides_pokenav_match_call_data[i + 1].idx == idx &&
                FlagGet(sCheckPageOverrides_pokenav_match_call_data[i + 1].flag); i++);
            return sCheckPageOverrides_pokenav_match_call_data[i].flavorTexts[offset];
        }
    }
    return NULL;
}

int MatchCall_GetOverrideFacilityClass(u32 idx)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides_pokenav_match_call_data); i++)
    {
        if (sCheckPageOverrides_pokenav_match_call_data[i].idx == idx)
            return sCheckPageOverrides_pokenav_match_call_data[i].facilityClass;
    }
    return -1;
}

bool32 MatchCall_HasRematchId(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders_pokenav_match_call_data); i++)
    {
        u32 id = MatchCall_GetRematchTableIdx(i);
        if (id != REMATCH_TABLE_ENTRIES && id == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    int index = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (index >= 0)
        FlagSet(TRAINER_REGISTERED_FLAGS_START + index);
}
