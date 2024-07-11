const struct Trainer gTrainers[] = {
    [TRAINER_NONE] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
    [TRAINER_SAWYER_1] =
    {
        .trainerName = _("SAWYER"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_AQUA_HIDEOUT_1] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_AQUA_HIDEOUT_2] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_AQUA_HIDEOUT_3] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_AQUA_HIDEOUT_4] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_1] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_2] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_3] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABRIELLE_1] =
    {
        .trainerName = _("GABRIELLE"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_PETALBURG_WOODS] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARCEL] =
    {
        .trainerName = _("MARCEL"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALBERTO] =
    {
        .trainerName = _("ALBERTO"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ED] =
    {
        .trainerName = _("ED"),
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZANGOOSE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEVIPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_4] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DECLAN] =
    {
        .trainerName = _("DECLAN"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_RUSTURF_TUNNEL] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_WEATHER_INST_1] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_WEATHER_INST_2] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_WEATHER_INST_3] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MUSEUM_1] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MUSEUM_2] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SPACE_CENTER_1] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MT_PYRE_1] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MT_PYRE_2] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MT_PYRE_3] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_WEATHER_INST_4] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_AQUA_HIDEOUT_5] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_AQUA_HIDEOUT_6] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FREDRICK] =
    {
        .trainerName = _("FREDRICK"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MATT] =
    {
        .trainerName = _("MATT"),
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .items = { ITEM_SUPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ZANDER] =
    {
        .trainerName = _("ZANDER"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHELLY_WEATHER_INSTITUTE] =
    {
        .trainerName = _("SHELLY"),
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHELLY_SEAFLOOR_CAVERN] =
    {
        .trainerName = _("SHELLY"),
        .trainerClass = TRAINER_CLASS_AQUA_ADMIN,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ARCHIE] =
    {
        .trainerName = _("ARCHIE"),
        .trainerClass = TRAINER_CLASS_AQUA_LEADER,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LEAH] =
    {
        .trainerName = _("LEAH"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPOINK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DAISY] =
    {
        .trainerName = _("DAISY"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROSE_1] =
    {
        .trainerName = _("ROSE"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FELIX] =
    {
        .trainerName = _("FELIX"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
            },
            },
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SKILL_SWAP,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_VIOLET] =
    {
        .trainerName = _("VIOLET"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROSE_2] =
    {
        .trainerName = _("ROSE"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROSE_3] =
    {
        .trainerName = _("ROSE"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROSE_4] =
    {
        .trainerName = _("ROSE"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROSE_5] =
    {
        .trainerName = _("ROSE"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DUSTY_1] =
    {
        .trainerName = _("DUSTY"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
    [TRAINER_CHIP] =
    {
        .trainerName = _("CHIP"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYBEAM,
                MOVE_SELF_DESTRUCT,
                MOVE_SANDSTORM,
                MOVE_ANCIENT_POWER,
            },
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
    [TRAINER_FOSTER] =
    {
        .trainerName = _("FOSTER"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
    [TRAINER_DUSTY_2] =
    {
        .trainerName = _("DUSTY"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
    [TRAINER_DUSTY_3] =
    {
        .trainerName = _("DUSTY"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
    [TRAINER_DUSTY_4] =
    {
        .trainerName = _("DUSTY"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
    [TRAINER_DUSTY_5] =
    {
        .trainerName = _("DUSTY"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SLASH,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
            },
            },
        },
    },
    [TRAINER_GABBY_AND_TY_1] =
    {
        .trainerName = _("GABBY & TY"),
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABBY_AND_TY_2] =
    {
        .trainerName = _("GABBY & TY"),
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABBY_AND_TY_3] =
    {
        .trainerName = _("GABBY & TY"),
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABBY_AND_TY_4] =
    {
        .trainerName = _("GABBY & TY"),
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABBY_AND_TY_5] =
    {
        .trainerName = _("GABBY & TY"),
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABBY_AND_TY_6] =
    {
        .trainerName = _("GABBY & TY"),
        .trainerClass = TRAINER_CLASS_INTERVIEWER,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SONIC_BOOM,
                MOVE_THUNDER_WAVE,
                MOVE_METAL_SOUND,
                MOVE_THUNDERBOLT,
            },
            },
            {
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ASTONISH,
                MOVE_STOMP,
                MOVE_SUPERSONIC,
                MOVE_HYPER_VOICE,
            },
            },
        },
    },
    [TRAINER_LOLA_1] =
    {
        .trainerName = _("LOLA"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AUSTINA] =
    {
        .trainerName = _("AUSTINA"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GWEN] =
    {
        .trainerName = _("GWEN"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LOLA_2] =
    {
        .trainerName = _("LOLA"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LOLA_3] =
    {
        .trainerName = _("LOLA"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LOLA_4] =
    {
        .trainerName = _("LOLA"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LOLA_5] =
    {
        .trainerName = _("LOLA"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RICKY_1] =
    {
        .trainerName = _("RICKY"),
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SAND_ATTACK,
                MOVE_HEADBUTT,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
    [TRAINER_SIMON] =
    {
        .trainerName = _("SIMON"),
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CHARLIE] =
    {
        .trainerName = _("CHARLIE"),
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RICKY_2] =
    {
        .trainerName = _("RICKY"),
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
    [TRAINER_RICKY_3] =
    {
        .trainerName = _("RICKY"),
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
    [TRAINER_RICKY_4] =
    {
        .trainerName = _("RICKY"),
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
    [TRAINER_RICKY_5] =
    {
        .trainerName = _("RICKY"),
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SAND_ATTACK,
                MOVE_PIN_MISSILE,
                MOVE_TAIL_WHIP,
                MOVE_SURF,
            },
            },
        },
    },
    [TRAINER_RANDALL] =
    {
        .trainerName = _("RANDALL"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_QUICK_ATTACK,
                MOVE_AGILITY,
                MOVE_WING_ATTACK,
            },
            },
        },
    },
    [TRAINER_PARKER] =
    {
        .trainerName = _("PARKER"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TEETER_DANCE,
                MOVE_DIZZY_PUNCH,
                MOVE_FOCUS_PUNCH,
            },
            },
        },
    },
    [TRAINER_GEORGE] =
    {
        .trainerName = _("GEORGE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLAKOTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SLACK_OFF,
                MOVE_COUNTER,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
    [TRAINER_BERKE] =
    {
        .trainerName = _("BERKE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_ENERGY,
                MOVE_SLASH,
            },
            },
        },
    },
    [TRAINER_BRAXTON] =
    {
        .trainerName = _("BRAXTON"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_ENERGY,
                MOVE_QUICK_ATTACK,
                MOVE_WING_ATTACK,
                MOVE_ENDEAVOR,
            },
            },
            {
            .species = SPECIES_TRAPINCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BITE,
                MOVE_DIG,
                MOVE_FEINT_ATTACK,
                MOVE_SAND_TOMB,
            },
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROLLOUT,
                MOVE_WHIRLPOOL,
                MOVE_ASTONISH,
                MOVE_WATER_PULSE,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDERBOLT,
                MOVE_SUPERSONIC,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
            },
            },
            {
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GIGA_DRAIN,
                MOVE_FEINT_ATTACK,
                MOVE_DOUBLE_TEAM,
                MOVE_SWAGGER,
            },
            },
        },
    },
    [TRAINER_VINCENT] =
    {
        .trainerName = _("VINCENT"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LEROY] =
    {
        .trainerName = _("LEROY"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WILTON_1] =
    {
        .trainerName = _("WILTON"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_SUPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDGAR] =
    {
        .trainerName = _("EDGAR"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALBERT] =
    {
        .trainerName = _("ALBERT"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MUK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SAMUEL] =
    {
        .trainerName = _("SAMUEL"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VITO] =
    {
        .trainerName = _("VITO"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_OWEN] =
    {
        .trainerName = _("OWEN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WILTON_2] =
    {
        .trainerName = _("WILTON"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WILTON_3] =
    {
        .trainerName = _("WILTON"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WILTON_4] =
    {
        .trainerName = _("WILTON"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WILTON_5] =
    {
        .trainerName = _("WILTON"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WARREN] =
    {
        .trainerName = _("WARREN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARY] =
    {
        .trainerName = _("MARY"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FEINT_ATTACK,
                MOVE_SHOCK_WAVE,
            },
            },
        },
    },
    [TRAINER_ALEXIA] =
    {
        .trainerName = _("ALEXIA"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WIGGLYTUFF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DEFENSE_CURL,
                MOVE_DOUBLE_EDGE,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
    [TRAINER_JODY] =
    {
        .trainerName = _("JODY"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZANGOOSE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SWORDS_DANCE,
                MOVE_SLASH,
            },
            },
        },
    },
    [TRAINER_WENDY] =
    {
        .trainerName = _("WENDY"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAWILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BATON_PASS,
                MOVE_FEINT_ATTACK,
                MOVE_FAKE_TEARS,
                MOVE_BITE,
            },
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_MEGA_DRAIN,
                MOVE_MAGICAL_LEAF,
                MOVE_GRASS_WHISTLE,
                MOVE_LEECH_SEED,
            },
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLY,
                MOVE_WATER_GUN,
                MOVE_MIST,
                MOVE_PROTECT,
            },
            },
        },
    },
    [TRAINER_KEIRA] =
    {
        .trainerName = _("KEIRA"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BROOKE_1] =
    {
        .trainerName = _("BROOKE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_SUPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JENNIFER] =
    {
        .trainerName = _("JENNIFER"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HOPE] =
    {
        .trainerName = _("HOPE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHANNON] =
    {
        .trainerName = _("SHANNON"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MICHELLE] =
    {
        .trainerName = _("MICHELLE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAROLINE] =
    {
        .trainerName = _("CAROLINE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JULIE] =
    {
        .trainerName = _("JULIE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINETALES,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BROOKE_2] =
    {
        .trainerName = _("BROOKE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BROOKE_3] =
    {
        .trainerName = _("BROOKE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BROOKE_4] =
    {
        .trainerName = _("BROOKE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BROOKE_5] =
    {
        .trainerName = _("BROOKE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PATRICIA] =
    {
        .trainerName = _("PATRICIA"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BANETTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KINDRA] =
    {
        .trainerName = _("KINDRA"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHUPPET,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TAMMY] =
    {
        .trainerName = _("TAMMY"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHUPPET,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VALERIE_1] =
    {
        .trainerName = _("VALERIE"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TASHA] =
    {
        .trainerName = _("TASHA"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHUPPET,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VALERIE_2] =
    {
        .trainerName = _("VALERIE"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SPOINK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VALERIE_3] =
    {
        .trainerName = _("VALERIE"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPOINK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VALERIE_4] =
    {
        .trainerName = _("VALERIE"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPOINK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VALERIE_5] =
    {
        .trainerName = _("VALERIE"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRUMPIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CINDY_1] =
    {
        .trainerName = _("CINDY"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DAPHNE] =
    {
        .trainerName = _("DAPHNE"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ATTRACT,
                MOVE_SWEET_KISS,
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
            },
            },
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ATTRACT,
                MOVE_SAFEGUARD,
                MOVE_TAKE_DOWN,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
    [TRAINER_GRUNT_SPACE_CENTER_2] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CINDY_2] =
    {
        .trainerName = _("CINDY"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_TAIL_WHIP,
            },
            },
        },
    },
    [TRAINER_BRIANNA] =
    {
        .trainerName = _("BRIANNA"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NAOMI] =
    {
        .trainerName = _("NAOMI"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CINDY_3] =
    {
        .trainerName = _("CINDY"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CINDY_4] =
    {
        .trainerName = _("CINDY"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CINDY_5] =
    {
        .trainerName = _("CINDY"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CINDY_6] =
    {
        .trainerName = _("CINDY"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FURY_SWIPES,
                MOVE_MUD_SPORT,
                MOVE_ODOR_SLEUTH,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
    [TRAINER_MELISSA] =
    {
        .trainerName = _("MELISSA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHEILA] =
    {
        .trainerName = _("SHEILA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHIRLEY] =
    {
        .trainerName = _("SHIRLEY"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JESSICA_1] =
    {
        .trainerName = _("JESSICA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_SEVIPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
    [TRAINER_CONNIE] =
    {
        .trainerName = _("CONNIE"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRIDGET] =
    {
        .trainerName = _("BRIDGET"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_OLIVIA] =
    {
        .trainerName = _("OLIVIA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CLAMPERL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_IRON_DEFENSE,
                MOVE_WHIRLPOOL,
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
            },
            },
            {
            .species = SPECIES_CORPHISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TAUNT,
                MOVE_CRABHAMMER,
                MOVE_WATER_PULSE,
            },
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_UPROAR,
                MOVE_FURY_SWIPES,
                MOVE_FAKE_OUT,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
    [TRAINER_TIFFANY] =
    {
        .trainerName = _("TIFFANY"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JESSICA_2] =
    {
        .trainerName = _("JESSICA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_SEVIPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
    [TRAINER_JESSICA_3] =
    {
        .trainerName = _("JESSICA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_SEVIPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
    [TRAINER_JESSICA_4] =
    {
        .trainerName = _("JESSICA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_SEVIPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
    [TRAINER_JESSICA_5] =
    {
        .trainerName = _("JESSICA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BIND,
                MOVE_LICK,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_SEVIPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_TAIL,
                MOVE_SCREECH,
                MOVE_GLARE,
                MOVE_CRUNCH,
            },
            },
        },
    },
    [TRAINER_WINSTON_1] =
    {
        .trainerName = _("WINSTON"),
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MOLLIE] =
    {
        .trainerName = _("MOLLIE"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WHISCASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GARRET] =
    {
        .trainerName = _("GARRET"),
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WINSTON_2] =
    {
        .trainerName = _("WINSTON"),
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WINSTON_3] =
    {
        .trainerName = _("WINSTON"),
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WINSTON_4] =
    {
        .trainerName = _("WINSTON"),
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WINSTON_5] =
    {
        .trainerName = _("WINSTON"),
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FURY_SWIPES,
                MOVE_MUD_SPORT,
                MOVE_ODOR_SLEUTH,
                MOVE_SAND_ATTACK,
            },
            },
        },
    },
    [TRAINER_STEVE_1] =
    {
        .trainerName = _("STEVE"),
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_THALIA_1] =
    {
        .trainerName = _("THALIA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARK] =
    {
        .trainerName = _("MARK"),
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MT_CHIMNEY_1] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_STEVE_2] =
    {
        .trainerName = _("STEVE"),
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_STEVE_3] =
    {
        .trainerName = _("STEVE"),
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_STEVE_4] =
    {
        .trainerName = _("STEVE"),
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_RHYHORN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_STEVE_5] =
    {
        .trainerName = _("STEVE"),
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_RHYDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LUIS] =
    {
        .trainerName = _("LUIS"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DOMINIK] =
    {
        .trainerName = _("DOMINIK"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DOUGLAS] =
    {
        .trainerName = _("DOUGLAS"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DARRIN] =
    {
        .trainerName = _("DARRIN"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TONY_1] =
    {
        .trainerName = _("TONY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JEROME] =
    {
        .trainerName = _("JEROME"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MATTHEW] =
    {
        .trainerName = _("MATTHEW"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DAVID] =
    {
        .trainerName = _("DAVID"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SPENCER] =
    {
        .trainerName = _("SPENCER"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROLAND] =
    {
        .trainerName = _("ROLAND"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NOLEN] =
    {
        .trainerName = _("NOLEN"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_STAN] =
    {
        .trainerName = _("STAN"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BARRY] =
    {
        .trainerName = _("BARRY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DEAN] =
    {
        .trainerName = _("DEAN"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RODNEY] =
    {
        .trainerName = _("RODNEY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RICHARD] =
    {
        .trainerName = _("RICHARD"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HERMAN] =
    {
        .trainerName = _("HERMAN"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SANTIAGO] =
    {
        .trainerName = _("SANTIAGO"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GILBERT] =
    {
        .trainerName = _("GILBERT"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FRANKLIN] =
    {
        .trainerName = _("FRANKLIN"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KEVIN] =
    {
        .trainerName = _("KEVIN"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACK] =
    {
        .trainerName = _("JACK"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DUDLEY] =
    {
        .trainerName = _("DUDLEY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CHAD] =
    {
        .trainerName = _("CHAD"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TONY_2] =
    {
        .trainerName = _("TONY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TONY_3] =
    {
        .trainerName = _("TONY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TONY_4] =
    {
        .trainerName = _("TONY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TONY_5] =
    {
        .trainerName = _("TONY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TAKAO] =
    {
        .trainerName = _("TAKAO"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HITOSHI] =
    {
        .trainerName = _("HITOSHI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KIYO] =
    {
        .trainerName = _("KIYO"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KOICHI] =
    {
        .trainerName = _("KOICHI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NOB_1] =
    {
        .trainerName = _("NOB"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NOB_2] =
    {
        .trainerName = _("NOB"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NOB_3] =
    {
        .trainerName = _("NOB"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NOB_4] =
    {
        .trainerName = _("NOB"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NOB_5] =
    {
        .trainerName = _("NOB"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_BLACK_BELT,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_YUJI] =
    {
        .trainerName = _("YUJI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DAISUKE] =
    {
        .trainerName = _("DAISUKE"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ATSUSHI] =
    {
        .trainerName = _("ATSUSHI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KIRK] =
    {
        .trainerName = _("KIRK"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_SPARK,
                MOVE_LEER,
            },
            },
            {
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_CHARGE,
                MOVE_SHOCK_WAVE,
                MOVE_SCREECH,
            },
            },
        },
    },
    [TRAINER_GRUNT_AQUA_HIDEOUT_7] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_AQUA_HIDEOUT_8] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHAWN] =
    {
        .trainerName = _("SHAWN"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FERNANDO_1] =
    {
        .trainerName = _("FERNANDO"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DALTON_1] =
    {
        .trainerName = _("DALTON"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DALTON_2] =
    {
        .trainerName = _("DALTON"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DALTON_3] =
    {
        .trainerName = _("DALTON"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DALTON_4] =
    {
        .trainerName = _("DALTON"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DALTON_5] =
    {
        .trainerName = _("DALTON"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_COLE] =
    {
        .trainerName = _("COLE"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JEFF] =
    {
        .trainerName = _("JEFF"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AXLE] =
    {
        .trainerName = _("AXLE"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACE] =
    {
        .trainerName = _("JACE"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KEEGAN] =
    {
        .trainerName = _("KEEGAN"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BERNIE_1] =
    {
        .trainerName = _("BERNIE"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BERNIE_2] =
    {
        .trainerName = _("BERNIE"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BERNIE_3] =
    {
        .trainerName = _("BERNIE"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BERNIE_4] =
    {
        .trainerName = _("BERNIE"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BERNIE_5] =
    {
        .trainerName = _("BERNIE"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DREW] =
    {
        .trainerName = _("DREW"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
            },
            },
        },
    },
    [TRAINER_BEAU] =
    {
        .trainerName = _("BEAU"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAPID_SPIN,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_STING,
                MOVE_SAND_ATTACK,
                MOVE_SCRATCH,
                MOVE_DIG,
            },
            },
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAPID_SPIN,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
    [TRAINER_LARRY] =
    {
        .trainerName = _("LARRY"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHANE] =
    {
        .trainerName = _("SHANE"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JUSTIN] =
    {
        .trainerName = _("JUSTIN"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ETHAN_1] =
    {
        .trainerName = _("ETHAN"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AUTUMN] =
    {
        .trainerName = _("AUTUMN"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TRAVIS] =
    {
        .trainerName = _("TRAVIS"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ETHAN_2] =
    {
        .trainerName = _("ETHAN"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ETHAN_3] =
    {
        .trainerName = _("ETHAN"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ETHAN_4] =
    {
        .trainerName = _("ETHAN"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ETHAN_5] =
    {
        .trainerName = _("ETHAN"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENT] =
    {
        .trainerName = _("BRENT"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DONALD] =
    {
        .trainerName = _("DONALD"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SILCOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TAYLOR] =
    {
        .trainerName = _("TAYLOR"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CASCOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JEFFREY_1] =
    {
        .trainerName = _("JEFFREY"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DEREK] =
    {
        .trainerName = _("DEREK"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JEFFREY_2] =
    {
        .trainerName = _("JEFFREY"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JEFFREY_3] =
    {
        .trainerName = _("JEFFREY"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JEFFREY_4] =
    {
        .trainerName = _("JEFFREY"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JEFFREY_5] =
    {
        .trainerName = _("JEFFREY"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MASQUERAIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SILVER_POWDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDWARD] =
    {
        .trainerName = _("EDWARD"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HIDDEN_POWER,
            },
            },
        },
    },
    [TRAINER_PRESTON] =
    {
        .trainerName = _("PRESTON"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VIRGIL] =
    {
        .trainerName = _("VIRGIL"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BLAKE] =
    {
        .trainerName = _("BLAKE"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WILLIAM] =
    {
        .trainerName = _("WILLIAM"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JOSHUA] =
    {
        .trainerName = _("JOSHUA"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAMERON_1] =
    {
        .trainerName = _("CAMERON"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAMERON_2] =
    {
        .trainerName = _("CAMERON"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAMERON_3] =
    {
        .trainerName = _("CAMERON"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAMERON_4] =
    {
        .trainerName = _("CAMERON"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAMERON_5] =
    {
        .trainerName = _("CAMERON"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACLYN] =
    {
        .trainerName = _("JACLYN"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HIDDEN_POWER,
            },
            },
        },
    },
    [TRAINER_HANNAH] =
    {
        .trainerName = _("HANNAH"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SAMANTHA] =
    {
        .trainerName = _("SAMANTHA"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAURA] =
    {
        .trainerName = _("MAURA"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KAYLA] =
    {
        .trainerName = _("KAYLA"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALEXIS] =
    {
        .trainerName = _("ALEXIS"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKI_1] =
    {
        .trainerName = _("JACKI"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKI_2] =
    {
        .trainerName = _("JACKI"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKI_3] =
    {
        .trainerName = _("JACKI"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKI_4] =
    {
        .trainerName = _("JACKI"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKI_5] =
    {
        .trainerName = _("JACKI"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALAKAZAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WALTER_1] =
    {
        .trainerName = _("WALTER"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MICAH] =
    {
        .trainerName = _("MICAH"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_THOMAS] =
    {
        .trainerName = _("THOMAS"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZANGOOSE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WALTER_2] =
    {
        .trainerName = _("WALTER"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WALTER_3] =
    {
        .trainerName = _("WALTER"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
                MOVE_ROAR,
            },
            },
        },
    },
    [TRAINER_WALTER_4] =
    {
        .trainerName = _("WALTER"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
            },
            },
        },
    },
    [TRAINER_WALTER_5] =
    {
        .trainerName = _("WALTER"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_ODOR_SLEUTH,
                MOVE_FURY_SWIPES,
            },
            },
            {
            .species = SPECIES_GOLDUCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FURY_SWIPES,
                MOVE_DISABLE,
                MOVE_CONFUSION,
                MOVE_PSYCH_UP,
            },
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_QUICK_ATTACK,
                MOVE_SPARK,
                MOVE_ODOR_SLEUTH,
                MOVE_ROAR,
            },
            },
        },
    },
    [TRAINER_SIDNEY] =
    {
        .trainerName = _("SIDNEY"),
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_SIDNEY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SETUP_FIRST_TURN,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PURPLE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROAR,
                MOVE_DOUBLE_EDGE,
                MOVE_SAND_ATTACK,
                MOVE_CRUNCH,
            },
            },
            {
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TORMENT,
                MOVE_DOUBLE_TEAM,
                MOVE_SWAGGER,
                MOVE_EXTRASENSORY,
            },
            },
            {
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LEECH_SEED,
                MOVE_FEINT_ATTACK,
                MOVE_NEEDLE_ARM,
                MOVE_COTTON_SPORE,
            },
            },
            {
            .species = SPECIES_CRAWDAUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SURF,
                MOVE_SWORDS_DANCE,
                MOVE_STRENGTH,
                MOVE_FACADE,
            },
            },
            {
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_ROCK_SLIDE,
                MOVE_SWORDS_DANCE,
                MOVE_SLASH,
            },
            },
        },
    },
    [TRAINER_PHOEBE] =
    {
        .trainerName = _("PHOEBE"),
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_PHOEBE,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_GREEN,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHADOW_PUNCH,
                MOVE_CONFUSE_RAY,
                MOVE_CURSE,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_BANETTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHADOW_BALL,
                MOVE_GRUDGE,
                MOVE_WILL_O_WISP,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_TEAM,
                MOVE_NIGHT_SHADE,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_BANETTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHADOW_BALL,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_FACADE,
            },
            },
            {
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHADOW_BALL,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_GLACIA] =
    {
        .trainerName = _("GLACIA"),
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_GLACIA,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_PINK,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ENCORE,
                MOVE_BODY_SLAM,
                MOVE_HAIL,
                MOVE_ICE_BALL,
            },
            },
            {
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LIGHT_SCREEN,
                MOVE_CRUNCH,
                MOVE_ICY_WIND,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ATTRACT,
                MOVE_DOUBLE_EDGE,
                MOVE_HAIL,
                MOVE_BLIZZARD,
            },
            },
            {
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHADOW_BALL,
                MOVE_EXPLOSION,
                MOVE_HAIL,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SURF,
                MOVE_BODY_SLAM,
                MOVE_ICE_BEAM,
                MOVE_SHEER_COLD,
            },
            },
        },
    },
    [TRAINER_DRAKE] =
    {
        .trainerName = _("DRAKE"),
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_DRAKE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_BLUE,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHELGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROCK_TOMB,
                MOVE_DRAGON_CLAW,
                MOVE_PROTECT,
                MOVE_DOUBLE_EDGE,
            },
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_EDGE,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SMOKESCREEN,
                MOVE_DRAGON_DANCE,
                MOVE_SURF,
                MOVE_BODY_SLAM,
            },
            },
            {
            .species = SPECIES_FLYGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_CRUNCH,
                MOVE_DRAGON_BREATH,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_SALAMENCE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_DRAGON_CLAW,
                MOVE_ROCK_SLIDE,
                MOVE_CRUNCH,
            },
            },
        },
    },
    [TRAINER_ROXANNE_1] =
    {
        .trainerName = _("ROXANNE"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_POTION, ITEM_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_ROCK_TOMB,
            },
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_DEFENSE_CURL,
                MOVE_ROCK_THROW,
                MOVE_ROCK_TOMB,
            },
            },
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BLOCK,
                MOVE_HARDEN,
                MOVE_TACKLE,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
    [TRAINER_BRAWLY_1] =
    {
        .trainerName = _("BRAWLY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_KARATE_CHOP,
                MOVE_LOW_KICK,
                MOVE_SEISMIC_TOSS,
                MOVE_BULK_UP,
            },
            },
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_BULK_UP,
            },
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ARM_THRUST,
                MOVE_VITAL_THROW,
                MOVE_REVERSAL,
                MOVE_BULK_UP,
            },
            },
        },
    },
    [TRAINER_WATTSON_1] =
    {
        .trainerName = _("WATTSON"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROLLOUT,
                MOVE_SPARK,
                MOVE_SELF_DESTRUCT,
                MOVE_SHOCK_WAVE,
            },
            },
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHOCK_WAVE,
                MOVE_LEER,
                MOVE_QUICK_ATTACK,
                MOVE_HOWL,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_SHOCK_WAVE,
                MOVE_THUNDER_WAVE,
                MOVE_SONIC_BOOM,
            },
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
                MOVE_SHOCK_WAVE,
                MOVE_HOWL,
            },
            },
        },
    },
    [TRAINER_FLANNERY_1] =
    {
        .trainerName = _("FLANNERY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SMOG,
                MOVE_LIGHT_SCREEN,
                MOVE_SUNNY_DAY,
            },
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_TACKLE,
                MOVE_SUNNY_DAY,
                MOVE_ATTRACT,
            },
            },
            {
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_BODY_SLAM,
                MOVE_ATTRACT,
            },
            },
        },
    },
    [TRAINER_NORMAN_1] =
    {
        .trainerName = _("NORMAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TEETER_DANCE,
                MOVE_PSYBEAM,
                MOVE_FACADE,
                MOVE_ENCORE,
            },
            },
            {
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SLASH,
                MOVE_FACADE,
                MOVE_ENCORE,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SLASH,
                MOVE_BELLY_DRUM,
                MOVE_FACADE,
                MOVE_HEADBUTT,
            },
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_COUNTER,
                MOVE_YAWN,
                MOVE_FACADE,
                MOVE_FEINT_ATTACK,
            },
            },
        },
    },
    [TRAINER_WINONA_1] =
    {
        .trainerName = _("WINONA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PERISH_SONG,
                MOVE_MIRROR_MOVE,
                MOVE_SAFEGUARD,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_SYNTHESIS,
            },
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_GUN,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SAND_ATTACK,
                MOVE_FURY_ATTACK,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
                MOVE_AERIAL_ACE,
            },
            },
        },
    },
    [TRAINER_TATE_AND_LIZA_1] =
    {
        .trainerName = _("TATE&LIZA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_ANCIENT_POWER,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_SUNNY_DAY,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_HYPNOSIS,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
    [TRAINER_JUAN_1] =
    {
        .trainerName = _("JUAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_HYPER_POTION, ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_ATTRACT,
                MOVE_SWEET_KISS,
                MOVE_FLAIL,
            },
            },
            {
            .species = SPECIES_WHISCASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_AMNESIA,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_SEALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ENCORE,
                MOVE_BODY_SLAM,
                MOVE_AURORA_BEAM,
                MOVE_WATER_PULSE,
            },
            },
            {
            .species = SPECIES_CRAWDAUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_CRABHAMMER,
                MOVE_TAUNT,
                MOVE_LEER,
            },
            },
            {
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
    [TRAINER_JERRY_1] =
    {
        .trainerName = _("JERRY"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TED] =
    {
        .trainerName = _("TED"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PAUL] =
    {
        .trainerName = _("PAUL"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JERRY_2] =
    {
        .trainerName = _("JERRY"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JERRY_3] =
    {
        .trainerName = _("JERRY"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JERRY_4] =
    {
        .trainerName = _("JERRY"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JERRY_5] =
    {
        .trainerName = _("JERRY"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BANETTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KAREN_1] =
    {
        .trainerName = _("KAREN"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GEORGIA] =
    {
        .trainerName = _("GEORGIA"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KAREN_2] =
    {
        .trainerName = _("KAREN"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KAREN_3] =
    {
        .trainerName = _("KAREN"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KAREN_4] =
    {
        .trainerName = _("KAREN"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KAREN_5] =
    {
        .trainerName = _("KAREN"),
        .trainerClass = TRAINER_CLASS_SCHOOL_KID,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KATE_AND_JOY] =
    {
        .trainerName = _("KATE & JOY"),
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_PSYBEAM,
                MOVE_DIZZY_PUNCH,
                MOVE_TEETER_DANCE,
            },
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_YAWN,
                MOVE_SLACK_OFF,
                MOVE_FEINT_ATTACK,
            },
            },
        },
    },
    [TRAINER_ANNA_AND_MEG_1] =
    {
        .trainerName = _("ANNA & MEG"),
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
    [TRAINER_ANNA_AND_MEG_2] =
    {
        .trainerName = _("ANNA & MEG"),
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
    [TRAINER_ANNA_AND_MEG_3] =
    {
        .trainerName = _("ANNA & MEG"),
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
    [TRAINER_ANNA_AND_MEG_4] =
    {
        .trainerName = _("ANNA & MEG"),
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
    [TRAINER_ANNA_AND_MEG_5] =
    {
        .trainerName = _("ANNA & MEG"),
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GROWL,
                MOVE_TAIL_WHIP,
                MOVE_HEADBUTT,
                MOVE_ODOR_SLEUTH,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_FOCUS_ENERGY,
                MOVE_ARM_THRUST,
            },
            },
        },
    },
    [TRAINER_VICTOR] =
    {
        .trainerName = _("VICTOR"),
        .trainerClass = TRAINER_CLASS_WINSTRATE,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MIGUEL_1] =
    {
        .trainerName = _("MIGUEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_COLTON] =
    {
        .trainerName = _("COLTON"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
                MOVE_HEAL_BELL,
            },
            },
        },
    },
    [TRAINER_MIGUEL_2] =
    {
        .trainerName = _("MIGUEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MIGUEL_3] =
    {
        .trainerName = _("MIGUEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MIGUEL_4] =
    {
        .trainerName = _("MIGUEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MIGUEL_5] =
    {
        .trainerName = _("MIGUEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VICTORIA] =
    {
        .trainerName = _("VICTORIA"),
        .trainerClass = TRAINER_CLASS_WINSTRATE,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VANESSA] =
    {
        .trainerName = _("VANESSA"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BETHANY] =
    {
        .trainerName = _("BETHANY"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AZURILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISABEL_1] =
    {
        .trainerName = _("ISABEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISABEL_2] =
    {
        .trainerName = _("ISABEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISABEL_3] =
    {
        .trainerName = _("ISABEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISABEL_4] =
    {
        .trainerName = _("ISABEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISABEL_5] =
    {
        .trainerName = _("ISABEL"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TIMOTHY_1] =
    {
        .trainerName = _("TIMOTHY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TIMOTHY_2] =
    {
        .trainerName = _("TIMOTHY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ARM_THRUST,
                MOVE_KNOCK_OFF,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
    [TRAINER_TIMOTHY_3] =
    {
        .trainerName = _("TIMOTHY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ARM_THRUST,
                MOVE_KNOCK_OFF,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
    [TRAINER_TIMOTHY_4] =
    {
        .trainerName = _("TIMOTHY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ARM_THRUST,
                MOVE_BELLY_DRUM,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
    [TRAINER_TIMOTHY_5] =
    {
        .trainerName = _("TIMOTHY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ARM_THRUST,
                MOVE_BELLY_DRUM,
                MOVE_SAND_ATTACK,
                MOVE_DIG,
            },
            },
        },
    },
    [TRAINER_VICKY] =
    {
        .trainerName = _("VICKY"),
        .trainerClass = TRAINER_CLASS_WINSTRATE,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HIGH_JUMP_KICK,
                MOVE_MEDITATE,
                MOVE_CONFUSION,
                MOVE_DETECT,
            },
            },
        },
    },
    [TRAINER_SHELBY_1] =
    {
        .trainerName = _("SHELBY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHELBY_2] =
    {
        .trainerName = _("SHELBY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHELBY_3] =
    {
        .trainerName = _("SHELBY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHELBY_4] =
    {
        .trainerName = _("SHELBY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHELBY_5] =
    {
        .trainerName = _("SHELBY"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CALVIN_1] =
    {
        .trainerName = _("CALVIN"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BILLY] =
    {
        .trainerName = _("BILLY"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JOSH] =
    {
        .trainerName = _("JOSH"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
            },
            },
        },
    },
    [TRAINER_TOMMY] =
    {
        .trainerName = _("TOMMY"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JOEY] =
    {
        .trainerName = _("JOEY"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BEN] =
    {
        .trainerName = _("BEN"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HEADBUTT,
                MOVE_SAND_ATTACK,
                MOVE_GROWL,
                MOVE_THUNDERBOLT,
            },
            },
            {
            .species = SPECIES_GULPIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AMNESIA,
                MOVE_SLUDGE,
                MOVE_YAWN,
                MOVE_POUND,
            },
            },
        },
    },
    [TRAINER_QUINCY] =
    {
        .trainerName = _("QUINCY"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ATTRACT,
                MOVE_ICE_BEAM,
                MOVE_THUNDERBOLT,
                MOVE_FLAMETHROWER,
            },
            },
            {
            .species = SPECIES_DUSCLOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SKILL_SWAP,
                MOVE_PROTECT,
                MOVE_WILL_O_WISP,
                MOVE_TOXIC,
            },
            },
        },
    },
    [TRAINER_KATELYNN] =
    {
        .trainerName = _("KATELYNN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SKILL_SWAP,
                MOVE_PSYCHIC,
                MOVE_THUNDERBOLT,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_SHADOW_BALL,
                MOVE_AERIAL_ACE,
                MOVE_BRICK_BREAK,
            },
            },
        },
    },
    [TRAINER_JAYLEN] =
    {
        .trainerName = _("JAYLEN"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TRAPINCH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DILLON] =
    {
        .trainerName = _("DILLON"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CALVIN_2] =
    {
        .trainerName = _("CALVIN"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CALVIN_3] =
    {
        .trainerName = _("CALVIN"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CALVIN_4] =
    {
        .trainerName = _("CALVIN"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CALVIN_5] =
    {
        .trainerName = _("CALVIN"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDDIE] =
    {
        .trainerName = _("EDDIE"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALLEN] =
    {
        .trainerName = _("ALLEN"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 4,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 3,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TIMMY] =
    {
        .trainerName = _("TIMMY"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WALLACE] =
    {
        .trainerName = _("WALLACE"),
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .trainerPic = TRAINER_PIC_CHAMPION_WALLACE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .mugshotEnabled = TRUE,
        .mugshotColor = MUGSHOT_COLOR_YELLOW,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAIN_DANCE,
                MOVE_WATER_SPOUT,
                MOVE_DOUBLE_EDGE,
                MOVE_BLIZZARD,
            },
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TOXIC,
                MOVE_HYDRO_PUMP,
                MOVE_SLUDGE_BOMB,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GIGA_DRAIN,
                MOVE_SURF,
                MOVE_LEECH_SEED,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
            .species = SPECIES_WHISCASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_SURF,
                MOVE_AMNESIA,
                MOVE_HYPER_BEAM,
            },
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
                MOVE_HYPER_BEAM,
                MOVE_SURF,
            },
            },
            {
            .species = SPECIES_MILOTIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RECOVER,
                MOVE_SURF,
                MOVE_ICE_BEAM,
                MOVE_TOXIC,
            },
            },
        },
    },
    [TRAINER_ANDREW] =
    {
        .trainerName = _("ANDREW"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_IVAN] =
    {
        .trainerName = _("IVAN"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CLAUDE] =
    {
        .trainerName = _("CLAUDE"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BARBOACH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ELLIOT_1] =
    {
        .trainerName = _("ELLIOT"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 7,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NED] =
    {
        .trainerName = _("NED"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DALE] =
    {
        .trainerName = _("DALE"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NOLAN] =
    {
        .trainerName = _("NOLAN"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BARBOACH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BARNY] =
    {
        .trainerName = _("BARNY"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WADE] =
    {
        .trainerName = _("WADE"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CARTER] =
    {
        .trainerName = _("CARTER"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ELLIOT_2] =
    {
        .trainerName = _("ELLIOT"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ELLIOT_3] =
    {
        .trainerName = _("ELLIOT"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ELLIOT_4] =
    {
        .trainerName = _("ELLIOT"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ELLIOT_5] =
    {
        .trainerName = _("ELLIOT"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RONALD] =
    {
        .trainerName = _("RONALD"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACOB] =
    {
        .trainerName = _("JACOB"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANTHONY] =
    {
        .trainerName = _("ANTHONY"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BENJAMIN_1] =
    {
        .trainerName = _("BENJAMIN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BENJAMIN_2] =
    {
        .trainerName = _("BENJAMIN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BENJAMIN_3] =
    {
        .trainerName = _("BENJAMIN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BENJAMIN_4] =
    {
        .trainerName = _("BENJAMIN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BENJAMIN_5] =
    {
        .trainerName = _("BENJAMIN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ABIGAIL_1] =
    {
        .trainerName = _("ABIGAIL"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JASMINE] =
    {
        .trainerName = _("JASMINE"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ABIGAIL_2] =
    {
        .trainerName = _("ABIGAIL"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ABIGAIL_3] =
    {
        .trainerName = _("ABIGAIL"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ABIGAIL_4] =
    {
        .trainerName = _("ABIGAIL"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ABIGAIL_5] =
    {
        .trainerName = _("ABIGAIL"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DYLAN_1] =
    {
        .trainerName = _("DYLAN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DYLAN_2] =
    {
        .trainerName = _("DYLAN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DYLAN_3] =
    {
        .trainerName = _("DYLAN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DYLAN_4] =
    {
        .trainerName = _("DYLAN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DYLAN_5] =
    {
        .trainerName = _("DYLAN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARIA_1] =
    {
        .trainerName = _("MARIA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARIA_2] =
    {
        .trainerName = _("MARIA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARIA_3] =
    {
        .trainerName = _("MARIA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARIA_4] =
    {
        .trainerName = _("MARIA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARIA_5] =
    {
        .trainerName = _("MARIA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAMDEN] =
    {
        .trainerName = _("CAMDEN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DEMETRIUS] =
    {
        .trainerName = _("DEMETRIUS"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAIAH_1] =
    {
        .trainerName = _("ISAIAH"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PABLO_1] =
    {
        .trainerName = _("PABLO"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CHASE] =
    {
        .trainerName = _("CHASE"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAIAH_2] =
    {
        .trainerName = _("ISAIAH"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAIAH_3] =
    {
        .trainerName = _("ISAIAH"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAIAH_4] =
    {
        .trainerName = _("ISAIAH"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAIAH_5] =
    {
        .trainerName = _("ISAIAH"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISOBEL] =
    {
        .trainerName = _("ISOBEL"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DONNY] =
    {
        .trainerName = _("DONNY"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(19, 19, 19, 19, 19, 19),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TALIA] =
    {
        .trainerName = _("TALIA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KATELYN_1] =
    {
        .trainerName = _("KATELYN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALLISON] =
    {
        .trainerName = _("ALLISON"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KATELYN_2] =
    {
        .trainerName = _("KATELYN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KATELYN_3] =
    {
        .trainerName = _("KATELYN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KATELYN_4] =
    {
        .trainerName = _("KATELYN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KATELYN_5] =
    {
        .trainerName = _("KATELYN"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NICOLAS_1] =
    {
        .trainerName = _("NICOLAS"),
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NICOLAS_2] =
    {
        .trainerName = _("NICOLAS"),
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NICOLAS_3] =
    {
        .trainerName = _("NICOLAS"),
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NICOLAS_4] =
    {
        .trainerName = _("NICOLAS"),
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BAGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NICOLAS_5] =
    {
        .trainerName = _("NICOLAS"),
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHELGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_DRAGON_FANG,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AARON] =
    {
        .trainerName = _("AARON"),
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BAGON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DRAGON_BREATH,
                MOVE_HEADBUTT,
                MOVE_FOCUS_ENERGY,
                MOVE_EMBER,
            },
            },
        },
    },
    [TRAINER_PERRY] =
    {
        .trainerName = _("PERRY"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HUGH] =
    {
        .trainerName = _("HUGH"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PHIL] =
    {
        .trainerName = _("PHIL"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JARED] =
    {
        .trainerName = _("JARED"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HUMBERTO] =
    {
        .trainerName = _("HUMBERTO"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PRESLEY] =
    {
        .trainerName = _("PRESLEY"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDWARDO] =
    {
        .trainerName = _("EDWARDO"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_COLIN] =
    {
        .trainerName = _("COLIN"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROBERT_1] =
    {
        .trainerName = _("ROBERT"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BENNY] =
    {
        .trainerName = _("BENNY"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CHESTER] =
    {
        .trainerName = _("CHESTER"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROBERT_2] =
    {
        .trainerName = _("ROBERT"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROBERT_3] =
    {
        .trainerName = _("ROBERT"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROBERT_4] =
    {
        .trainerName = _("ROBERT"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROBERT_5] =
    {
        .trainerName = _("ROBERT"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALEX] =
    {
        .trainerName = _("ALEX"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BECK] =
    {
        .trainerName = _("BECK"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_YASU] =
    {
        .trainerName = _("YASU"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TAKASHI] =
    {
        .trainerName = _("TAKASHI"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DIANNE] =
    {
        .trainerName = _("DIANNE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SKILL_SWAP,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDERBOLT,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_JANI] =
    {
        .trainerName = _("JANI"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LAO_1] =
    {
        .trainerName = _("LAO"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SMOG,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
        },
    },
    [TRAINER_LUNG] =
    {
        .trainerName = _("LUNG"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LAO_2] =
    {
        .trainerName = _("LAO"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
    [TRAINER_LAO_3] =
    {
        .trainerName = _("LAO"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
    [TRAINER_LAO_4] =
    {
        .trainerName = _("LAO"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
    [TRAINER_LAO_5] =
    {
        .trainerName = _("LAO"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_TACKLE,
                MOVE_SLUDGE,
                MOVE_SELF_DESTRUCT,
            },
            },
            {
            .species = SPECIES_WEEZING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SMOKE_BALL,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_SLUDGE,
            },
            },
        },
    },
    [TRAINER_JOCELYN] =
    {
        .trainerName = _("JOCELYN"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LAURA] =
    {
        .trainerName = _("LAURA"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CYNDY_1] =
    {
        .trainerName = _("CYNDY"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CORA] =
    {
        .trainerName = _("CORA"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PAULA] =
    {
        .trainerName = _("PAULA"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CYNDY_2] =
    {
        .trainerName = _("CYNDY"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CYNDY_3] =
    {
        .trainerName = _("CYNDY"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CYNDY_4] =
    {
        .trainerName = _("CYNDY"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CYNDY_5] =
    {
        .trainerName = _("CYNDY"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MADELINE_1] =
    {
        .trainerName = _("MADELINE"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EMBER,
                MOVE_TACKLE,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
    [TRAINER_CLARISSA] =
    {
        .trainerName = _("CLARISSA"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANGELICA] =
    {
        .trainerName = _("ANGELICA"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CASTFORM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAIN_DANCE,
                MOVE_WEATHER_BALL,
                MOVE_THUNDER,
                MOVE_WATER_PULSE,
            },
            },
        },
    },
    [TRAINER_MADELINE_2] =
    {
        .trainerName = _("MADELINE"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EMBER,
                MOVE_TACKLE,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
    [TRAINER_MADELINE_3] =
    {
        .trainerName = _("MADELINE"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EMBER,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
    [TRAINER_MADELINE_4] =
    {
        .trainerName = _("MADELINE"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LEECH_SEED,
                MOVE_MEGA_DRAIN,
                MOVE_GRASS_WHISTLE,
                MOVE_SUNNY_DAY,
            },
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_TAKE_DOWN,
                MOVE_MAGNITUDE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
    [TRAINER_MADELINE_5] =
    {
        .trainerName = _("MADELINE"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_SOLAR_BEAM,
                MOVE_SUNNY_DAY,
            },
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_TAKE_DOWN,
                MOVE_EARTHQUAKE,
                MOVE_SUNNY_DAY,
            },
            },
        },
    },
    [TRAINER_BEVERLY] =
    {
        .trainerName = _("BEVERLY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_IMANI] =
    {
        .trainerName = _("IMANI"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KYLA] =
    {
        .trainerName = _("KYLA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DENISE] =
    {
        .trainerName = _("DENISE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BETH] =
    {
        .trainerName = _("BETH"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TARA] =
    {
        .trainerName = _("TARA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MISSY] =
    {
        .trainerName = _("MISSY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALICE] =
    {
        .trainerName = _("ALICE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JENNY_1] =
    {
        .trainerName = _("JENNY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRACE] =
    {
        .trainerName = _("GRACE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TANYA] =
    {
        .trainerName = _("TANYA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHARON] =
    {
        .trainerName = _("SHARON"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NIKKI] =
    {
        .trainerName = _("NIKKI"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDA] =
    {
        .trainerName = _("BRENDA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KATIE] =
    {
        .trainerName = _("KATIE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SUSIE] =
    {
        .trainerName = _("SUSIE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KARA] =
    {
        .trainerName = _("KARA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DANA] =
    {
        .trainerName = _("DANA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SIENNA] =
    {
        .trainerName = _("SIENNA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DEBRA] =
    {
        .trainerName = _("DEBRA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LINDA] =
    {
        .trainerName = _("LINDA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KAYLEE] =
    {
        .trainerName = _("KAYLEE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LAUREL] =
    {
        .trainerName = _("LAUREL"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CARLEE] =
    {
        .trainerName = _("CARLEE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JENNY_2] =
    {
        .trainerName = _("JENNY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JENNY_3] =
    {
        .trainerName = _("JENNY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JENNY_4] =
    {
        .trainerName = _("JENNY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JENNY_5] =
    {
        .trainerName = _("JENNY"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HEIDI] =
    {
        .trainerName = _("HEIDI"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DIG,
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
            },
            },
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAPID_SPIN,
                MOVE_MUD_SLAP,
                MOVE_PSYBEAM,
                MOVE_ROCK_TOMB,
            },
            },
        },
    },
    [TRAINER_BECKY] =
    {
        .trainerName = _("BECKY"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SAND_ATTACK,
                MOVE_POISON_STING,
                MOVE_SLASH,
                MOVE_DIG,
            },
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROLLOUT,
                MOVE_BUBBLE_BEAM,
                MOVE_TAIL_WHIP,
                MOVE_DEFENSE_CURL,
            },
            },
        },
    },
    [TRAINER_CAROL] =
    {
        .trainerName = _("CAROL"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NANCY] =
    {
        .trainerName = _("NANCY"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARTHA] =
    {
        .trainerName = _("MARTHA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DIANA_1] =
    {
        .trainerName = _("DIANA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CEDRIC] =
    {
        .trainerName = _("CEDRIC"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DESTINY_BOND,
                MOVE_SAFEGUARD,
                MOVE_COUNTER,
                MOVE_MIRROR_COAT,
            },
            },
        },
    },
    [TRAINER_IRENE] =
    {
        .trainerName = _("IRENE"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DIANA_2] =
    {
        .trainerName = _("DIANA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DIANA_3] =
    {
        .trainerName = _("DIANA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DIANA_4] =
    {
        .trainerName = _("DIANA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DIANA_5] =
    {
        .trainerName = _("DIANA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_VILEPLUME,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AMY_AND_LIV_1] =
    {
        .trainerName = _("AMY & LIV"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AMY_AND_LIV_2] =
    {
        .trainerName = _("AMY & LIV"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GINA_AND_MIA_1] =
    {
        .trainerName = _("GINA & MIA"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MIU_AND_YUKI] =
    {
        .trainerName = _("MIU & YUKI"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AMY_AND_LIV_3] =
    {
        .trainerName = _("AMY & LIV"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GINA_AND_MIA_2] =
    {
        .trainerName = _("GINA & MIA"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSKULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_NIGHT_SHADE,
                MOVE_DISABLE,
            },
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ABSORB,
                MOVE_LEECH_SEED,
            },
            },
        },
    },
    [TRAINER_AMY_AND_LIV_4] =
    {
        .trainerName = _("AMY & LIV"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AMY_AND_LIV_5] =
    {
        .trainerName = _("AMY & LIV"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SPARK,
                MOVE_CHARGE,
                MOVE_FAKE_TEARS,
                MOVE_HELPING_HAND,
            },
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SPARK,
                MOVE_CHARGE,
                MOVE_CHARM,
                MOVE_HELPING_HAND,
            },
            },
        },
    },
    [TRAINER_AMY_AND_LIV_6] =
    {
        .trainerName = _("AMY & LIV"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_CHARGE,
                MOVE_FAKE_TEARS,
                MOVE_HELPING_HAND,
            },
            },
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_CHARGE,
                MOVE_CHARM,
                MOVE_HELPING_HAND,
            },
            },
        },
    },
    [TRAINER_HUEY] =
    {
        .trainerName = _("HUEY"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDMOND] =
    {
        .trainerName = _("EDMOND"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ERNEST_1] =
    {
        .trainerName = _("ERNEST"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DWAYNE] =
    {
        .trainerName = _("DWAYNE"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PHILLIP] =
    {
        .trainerName = _("PHILLIP"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LEONARD] =
    {
        .trainerName = _("LEONARD"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DUNCAN] =
    {
        .trainerName = _("DUNCAN"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ERNEST_2] =
    {
        .trainerName = _("ERNEST"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ERNEST_3] =
    {
        .trainerName = _("ERNEST"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ERNEST_4] =
    {
        .trainerName = _("ERNEST"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ERNEST_5] =
    {
        .trainerName = _("ERNEST"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ELI] =
    {
        .trainerName = _("ELI"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANNIKA] =
    {
        .trainerName = _("ANNIKA"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
                MOVE_RETURN,
                MOVE_ATTRACT,
            },
            },
            {
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAIL,
                MOVE_WATER_PULSE,
                MOVE_RETURN,
                MOVE_ATTRACT,
            },
            },
        },
    },
    [TRAINER_JAZMYN] =
    {
        .trainerName = _("JAZMYN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER_2,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JONAS] =
    {
        .trainerName = _("JONAS"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TOXIC,
                MOVE_THUNDER,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE_BOMB,
            },
            },
        },
    },
    [TRAINER_KAYLEY] =
    {
        .trainerName = _("KAYLEY"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CASTFORM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_WEATHER_BALL,
                MOVE_FLAMETHROWER,
                MOVE_SOLAR_BEAM,
            },
            },
        },
    },
    [TRAINER_AURON] =
    {
        .trainerName = _("AURON"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KELVIN] =
    {
        .trainerName = _("KELVIN"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARLEY] =
    {
        .trainerName = _("MARLEY"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BITE,
                MOVE_ROAR,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
            },
            },
        },
    },
    [TRAINER_REYNA] =
    {
        .trainerName = _("REYNA"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HUDSON] =
    {
        .trainerName = _("HUDSON"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CONOR] =
    {
        .trainerName = _("CONOR"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDWIN_1] =
    {
        .trainerName = _("EDWIN"),
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HECTOR] =
    {
        .trainerName = _("HECTOR"),
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZANGOOSE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEVIPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TABITHA_MOSSDEEP] =
    {
        .trainerName = _("TABITHA"),
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDWIN_2] =
    {
        .trainerName = _("EDWIN"),
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDWIN_3] =
    {
        .trainerName = _("EDWIN"),
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDWIN_4] =
    {
        .trainerName = _("EDWIN"),
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EDWIN_5] =
    {
        .trainerName = _("EDWIN"),
        .trainerClass = TRAINER_CLASS_COLLECTOR,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WALLY_VR_1] =
    {
        .trainerName = _("WALLY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_103_MUDKIP] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_110_MUDKIP] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_119_MUDKIP] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_103_TREECKO] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_110_TREECKO] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_119_TREECKO] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_103_TORCHIC] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_110_TORCHIC] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_ROUTE_119_TORCHIC] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_103_MUDKIP] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_110_MUDKIP] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_119_MUDKIP] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_103_TREECKO] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_110_TREECKO] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_119_TREECKO] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_103_TORCHIC] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_110_TORCHIC] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_ROUTE_119_TORCHIC] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAAC_1] =
    {
        .trainerName = _("ISAAC"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WHISMUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DAVIS] =
    {
        .trainerName = _("DAVIS"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PINSIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MITCHELL] =
    {
        .trainerName = _("MITCHELL"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EXPLOSION,
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
            },
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EXPLOSION,
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
    [TRAINER_ISAAC_2] =
    {
        .trainerName = _("ISAAC"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAAC_3] =
    {
        .trainerName = _("ISAAC"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAAC_4] =
    {
        .trainerName = _("ISAAC"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISAAC_5] =
    {
        .trainerName = _("ISAAC"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LAIRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LYDIA_1] =
    {
        .trainerName = _("LYDIA"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 11,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HALLE] =
    {
        .trainerName = _("HALLE"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SABLEYE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ABSOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GARRISON] =
    {
        .trainerName = _("GARRISON"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LYDIA_2] =
    {
        .trainerName = _("LYDIA"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LYDIA_3] =
    {
        .trainerName = _("LYDIA"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LYDIA_4] =
    {
        .trainerName = _("LYDIA"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LYDIA_5] =
    {
        .trainerName = _("LYDIA"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKSON_1] =
    {
        .trainerName = _("JACKSON"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LORENZO] =
    {
        .trainerName = _("LORENZO"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SEBASTIAN] =
    {
        .trainerName = _("SEBASTIAN"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CACTURNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKSON_2] =
    {
        .trainerName = _("JACKSON"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKSON_3] =
    {
        .trainerName = _("JACKSON"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKSON_4] =
    {
        .trainerName = _("JACKSON"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JACKSON_5] =
    {
        .trainerName = _("JACKSON"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CATHERINE_1] =
    {
        .trainerName = _("CATHERINE"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JENNA] =
    {
        .trainerName = _("JENNA"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SOPHIA] =
    {
        .trainerName = _("SOPHIA"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CATHERINE_2] =
    {
        .trainerName = _("CATHERINE"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(7, 7, 7, 7, 7, 7),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CATHERINE_3] =
    {
        .trainerName = _("CATHERINE"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(8, 8, 8, 8, 8, 8),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CATHERINE_4] =
    {
        .trainerName = _("CATHERINE"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CATHERINE_5] =
    {
        .trainerName = _("CATHERINE"),
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BELLOSSOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(10, 10, 10, 10, 10, 10),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JULIO] =
    {
        .trainerName = _("JULIO"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SEAFLOOR_CAVERN_5] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_UNUSED] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MT_PYRE_4] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_JAGGED_PASS] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARC] =
    {
        .trainerName = _("MARC"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDEN] =
    {
        .trainerName = _("BRENDEN"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LILITH] =
    {
        .trainerName = _("LILITH"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CRISTIAN] =
    {
        .trainerName = _("CRISTIAN"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SYLVIA] =
    {
        .trainerName = _("SYLVIA"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LEONARDO] =
    {
        .trainerName = _("LEONARDO"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ATHENA] =
    {
        .trainerName = _("ATHENA"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_THUNDER_WAVE,
                MOVE_QUICK_ATTACK,
            },
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SURF,
                MOVE_THIEF,
            },
            },
        },
    },
    [TRAINER_HARRISON] =
    {
        .trainerName = _("HARRISON"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MT_CHIMNEY_2] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CLARENCE] =
    {
        .trainerName = _("CLARENCE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TERRY] =
    {
        .trainerName = _("TERRY"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NATE] =
    {
        .trainerName = _("NATE"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPOINK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KATHLEEN] =
    {
        .trainerName = _("KATHLEEN"),
        .trainerClass = TRAINER_CLASS_HEX_MANIAC,
        .trainerPic = TRAINER_PIC_HEX_MANIAC,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CLIFFORD] =
    {
        .trainerName = _("CLIFFORD"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GIRAFARIG,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NICHOLAS] =
    {
        .trainerName = _("NICHOLAS"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SPACE_CENTER_3] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SPACE_CENTER_4] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SPACE_CENTER_5] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SPACE_CENTER_6] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_SPACE_CENTER_7] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MACEY] =
    {
        .trainerName = _("MACEY"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_RUSTBORO_TREECKO] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_RUSTBORO_MUDKIP] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PAXTON] =
    {
        .trainerName = _("PAXTON"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISABELLA] =
    {
        .trainerName = _("ISABELLA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_WEATHER_INST_5] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_AQUA,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_AQUA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TABITHA_MT_CHIMNEY] =
    {
        .trainerName = _("TABITHA"),
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JONATHAN] =
    {
        .trainerName = _("JONATHAN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_RUSTBORO_TORCHIC] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_RUSTBORO_MUDKIP] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TREECKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAXIE_MAGMA_HIDEOUT] =
    {
        .trainerName = _("MAXIE"),
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAXIE_MT_CHIMNEY] =
    {
        .trainerName = _("MAXIE"),
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .items = { ITEM_SUPER_POTION, ITEM_SUPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TIANA] =
    {
        .trainerName = _("TIANA"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 4,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 4,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HALEY_1] =
    {
        .trainerName = _("HALEY"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JANICE] =
    {
        .trainerName = _("JANICE"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_VIVI] =
    {
        .trainerName = _("VIVI"),
        .trainerClass = TRAINER_CLASS_WINSTRATE,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HALEY_2] =
    {
        .trainerName = _("HALEY"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HALEY_3] =
    {
        .trainerName = _("HALEY"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HALEY_4] =
    {
        .trainerName = _("HALEY"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HALEY_5] =
    {
        .trainerName = _("HALEY"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BRELOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SALLY] =
    {
        .trainerName = _("SALLY"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ODDISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROBIN] =
    {
        .trainerName = _("ROBIN"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANDREA] =
    {
        .trainerName = _("ANDREA"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CRISSY] =
    {
        .trainerName = _("CRISSY"),
        .trainerClass = TRAINER_CLASS_LASS,
        .trainerPic = TRAINER_PIC_LASS,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RICK] =
    {
        .trainerName = _("RICK"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 4,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 4,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LYLE] =
    {
        .trainerName = _("LYLE"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 3,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 3,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 3,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 3,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JOSE] =
    {
        .trainerName = _("JOSE"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WURMPLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DOUG] =
    {
        .trainerName = _("DOUG"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GREG] =
    {
        .trainerName = _("GREG"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLBEAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ILLUMISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KENT] =
    {
        .trainerName = _("KENT"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JAMES_1] =
    {
        .trainerName = _("JAMES"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 6,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JAMES_2] =
    {
        .trainerName = _("JAMES"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JAMES_3] =
    {
        .trainerName = _("JAMES"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JAMES_4] =
    {
        .trainerName = _("JAMES"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JAMES_5] =
    {
        .trainerName = _("JAMES"),
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SURSKIT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRICE] =
    {
        .trainerName = _("BRICE"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TRENT_1] =
    {
        .trainerName = _("TRENT"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LENNY] =
    {
        .trainerName = _("LENNY"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LUCAS_1] =
    {
        .trainerName = _("LUCAS"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALAN] =
    {
        .trainerName = _("ALAN"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CLARK] =
    {
        .trainerName = _("CLARK"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ERIC] =
    {
        .trainerName = _("ERIC"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LUCAS_2] =
    {
        .trainerName = _("LUCAS"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SPLASH,
                MOVE_WATER_GUN,
            },
            },
        },
    },
    [TRAINER_MIKE_1] =
    {
        .trainerName = _("MIKE"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GUST,
                MOVE_GROWL,
            },
            },
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 10,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BITE,
                MOVE_SCARY_FACE,
            },
            },
        },
    },
    [TRAINER_MIKE_2] =
    {
        .trainerName = _("MIKE"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TRENT_2] =
    {
        .trainerName = _("TRENT"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TRENT_3] =
    {
        .trainerName = _("TRENT"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TRENT_4] =
    {
        .trainerName = _("TRENT"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TRENT_5] =
    {
        .trainerName = _("TRENT"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DEZ_AND_LUKE] =
    {
        .trainerName = _("DEZ & LUKE"),
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LEA_AND_JED] =
    {
        .trainerName = _("LEA & JED"),
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KIRA_AND_DAN_1] =
    {
        .trainerName = _("KIRA & DAN"),
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLBEAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ILLUMISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KIRA_AND_DAN_2] =
    {
        .trainerName = _("KIRA & DAN"),
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLBEAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ILLUMISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KIRA_AND_DAN_3] =
    {
        .trainerName = _("KIRA & DAN"),
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLBEAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ILLUMISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KIRA_AND_DAN_4] =
    {
        .trainerName = _("KIRA & DAN"),
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLBEAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ILLUMISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KIRA_AND_DAN_5] =
    {
        .trainerName = _("KIRA & DAN"),
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLBEAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ILLUMISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JOHANNA] =
    {
        .trainerName = _("JOHANNA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GERALD] =
    {
        .trainerName = _("GERALD"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KECLEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_FURY_SWIPES,
                MOVE_FEINT_ATTACK,
                MOVE_BIND,
            },
            },
        },
    },
    [TRAINER_VIVIAN] =
    {
        .trainerName = _("VIVIAN"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BIDE,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_THUNDER_PUNCH,
            },
            },
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER_PUNCH,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_MEDITATE,
            },
            },
        },
    },
    [TRAINER_DANIELLE] =
    {
        .trainerName = _("DANIELLE"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BIDE,
                MOVE_DETECT,
                MOVE_CONFUSION,
                MOVE_FIRE_PUNCH,
            },
            },
        },
    },
    [TRAINER_HIDEO] =
    {
        .trainerName = _("HIDEO"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_POISON_GAS,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
        },
    },
    [TRAINER_KEIGO] =
    {
        .trainerName = _("KEIGO"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POISON_GAS,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SAND_ATTACK,
                MOVE_DOUBLE_TEAM,
                MOVE_FURY_CUTTER,
                MOVE_SWORDS_DANCE,
            },
            },
        },
    },
    [TRAINER_RILEY] =
    {
        .trainerName = _("RILEY"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NINCADA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LEECH_LIFE,
                MOVE_FURY_SWIPES,
                MOVE_MIND_READER,
                MOVE_DIG,
            },
            },
            {
            .species = SPECIES_KOFFING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TACKLE,
                MOVE_SELF_DESTRUCT,
                MOVE_SLUDGE,
                MOVE_SMOKESCREEN,
            },
            },
        },
    },
    [TRAINER_FLINT] =
    {
        .trainerName = _("FLINT"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ASHLEY] =
    {
        .trainerName = _("ASHLEY"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WALLY_MAUVILLE] =
    {
        .trainerName = _("WALLY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 16,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WALLY_VR_2] =
    {
        .trainerName = _("WALLY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
    [TRAINER_WALLY_VR_3] =
    {
        .trainerName = _("WALLY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
    [TRAINER_WALLY_VR_4] =
    {
        .trainerName = _("WALLY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
    [TRAINER_WALLY_VR_5] =
    {
        .trainerName = _("WALLY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_WALLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_SAFEGUARD,
                MOVE_DRAGON_BREATH,
                MOVE_DRAGON_DANCE,
            },
            },
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SING,
                MOVE_ASSIST,
                MOVE_CHARM,
                MOVE_FEINT_ATTACK,
            },
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_MAGICAL_LEAF,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_THUNDERBOLT,
                MOVE_TRI_ATTACK,
                MOVE_SCREECH,
            },
            },
            {
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(30, 30, 30, 30, 30, 30),
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_CALM_MIND,
                MOVE_PSYCHIC,
                MOVE_FUTURE_SIGHT,
            },
            },
        },
    },
    [TRAINER_BRENDAN_LILYCOVE_MUDKIP] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_LILYCOVE_TREECKO] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_LILYCOVE_TORCHIC] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_LILYCOVE_MUDKIP] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GROVYLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_LILYCOVE_TREECKO] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_COMBUSKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_LILYCOVE_TORCHIC] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARSHTOMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JONAH] =
    {
        .trainerName = _("JONAH"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HENRY] =
    {
        .trainerName = _("HENRY"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROGER] =
    {
        .trainerName = _("ROGER"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GYARADOS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALEXA] =
    {
        .trainerName = _("ALEXA"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GLOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RUBEN] =
    {
        .trainerName = _("RUBEN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KOJI_1] =
    {
        .trainerName = _("KOJI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WAYNE] =
    {
        .trainerName = _("WAYNE"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AIDAN] =
    {
        .trainerName = _("AIDAN"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_REED] =
    {
        .trainerName = _("REED"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPHEAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TISHA] =
    {
        .trainerName = _("TISHA"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TORI_AND_TIA] =
    {
        .trainerName = _("TORI & TIA"),
        .trainerClass = TRAINER_CLASS_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KIM_AND_IRIS] =
    {
        .trainerName = _("KIM & IRIS"),
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SWABLU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SING,
                MOVE_FURY_ATTACK,
                MOVE_SAFEGUARD,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_TAKE_DOWN,
                MOVE_REST,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_TYRA_AND_IVY] =
    {
        .trainerName = _("TYRA & IVY"),
        .trainerClass = TRAINER_CLASS_SR_AND_JR,
        .trainerPic = TRAINER_PIC_SR_AND_JR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GROWTH,
                MOVE_STUN_SPORE,
                MOVE_MEGA_DRAIN,
                MOVE_LEECH_SEED,
            },
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DEFENSE_CURL,
                MOVE_ROLLOUT,
                MOVE_MUD_SPORT,
                MOVE_ROCK_THROW,
            },
            },
        },
    },
    [TRAINER_MEL_AND_PAUL] =
    {
        .trainerName = _("MEL & PAUL"),
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GUST,
                MOVE_PSYBEAM,
                MOVE_TOXIC,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GUST,
                MOVE_MEGA_DRAIN,
                MOVE_ATTRACT,
                MOVE_STUN_SPORE,
            },
            },
        },
    },
    [TRAINER_JOHN_AND_JAY_1] =
    {
        .trainerName = _("JOHN & JAY"),
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
    [TRAINER_JOHN_AND_JAY_2] =
    {
        .trainerName = _("JOHN & JAY"),
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
    [TRAINER_JOHN_AND_JAY_3] =
    {
        .trainerName = _("JOHN & JAY"),
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(26, 26, 26, 26, 26, 26),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
    [TRAINER_JOHN_AND_JAY_4] =
    {
        .trainerName = _("JOHN & JAY"),
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(27, 27, 27, 27, 27, 27),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
    [TRAINER_JOHN_AND_JAY_5] =
    {
        .trainerName = _("JOHN & JAY"),
        .trainerClass = TRAINER_CLASS_OLD_COUPLE,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_FIRE_PUNCH,
                MOVE_PSYCH_UP,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_ROCK_TOMB,
                MOVE_REST,
                MOVE_BELLY_DRUM,
            },
            },
        },
    },
    [TRAINER_RELI_AND_IAN] =
    {
        .trainerName = _("RELI & IAN"),
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AZUMARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LILA_AND_ROY_1] =
    {
        .trainerName = _("LILA & ROY"),
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LILA_AND_ROY_2] =
    {
        .trainerName = _("LILA & ROY"),
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CHINCHOU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LILA_AND_ROY_3] =
    {
        .trainerName = _("LILA & ROY"),
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LILA_AND_ROY_4] =
    {
        .trainerName = _("LILA & ROY"),
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LILA_AND_ROY_5] =
    {
        .trainerName = _("LILA & ROY"),
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LANTURN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHARPEDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LISA_AND_RAY] =
    {
        .trainerName = _("LISA & RAY"),
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 27,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CHRIS] =
    {
        .trainerName = _("CHRIS"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 20,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_FEEBAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CARVANHA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 23,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DAWSON] =
    {
        .trainerName = _("DAWSON"),
        .trainerClass = TRAINER_CLASS_RICH_BOY,
        .trainerPic = TRAINER_PIC_RICH_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SARAH] =
    {
        .trainerName = _("SARAH"),
        .trainerClass = TRAINER_CLASS_LADY,
        .trainerPic = TRAINER_PIC_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_NUGGET,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DARIAN] =
    {
        .trainerName = _("DARIAN"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGIKARP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 9,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HAILEY] =
    {
        .trainerName = _("HAILEY"),
        .trainerClass = TRAINER_CLASS_TUBER_F,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CHANDLER] =
    {
        .trainerName = _("CHANDLER"),
        .trainerClass = TRAINER_CLASS_TUBER_M,
        .trainerPic = TRAINER_PIC_TUBER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 12,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KALEB] =
    {
        .trainerName = _("KALEB"),
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_TWINS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MINUN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_PLUSLE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_ORAN_BERRY,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JOSEPH] =
    {
        .trainerName = _("JOSEPH"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALYSSA] =
    {
        .trainerName = _("ALYSSA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_CYCLING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGNEMITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARCOS] =
    {
        .trainerName = _("MARCOS"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VOLTORB,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RHETT] =
    {
        .trainerName = _("RHETT"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TYRON] =
    {
        .trainerName = _("TYRON"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CELINA] =
    {
        .trainerName = _("CELINA"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BIANCA] =
    {
        .trainerName = _("BIANCA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HAYDEN] =
    {
        .trainerName = _("HAYDEN"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SOPHIE] =
    {
        .trainerName = _("SOPHIE"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_COBY] =
    {
        .trainerName = _("COBY"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LAWRENCE] =
    {
        .trainerName = _("LAWRENCE"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_WYATT] =
    {
        .trainerName = _("WYATT"),
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANGELINA] =
    {
        .trainerName = _("ANGELINA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KAI] =
    {
        .trainerName = _("KAI"),
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BARBOACH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CHARLOTTE] =
    {
        .trainerName = _("CHARLOTTE"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 19,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DEANDRE] =
    {
        .trainerName = _("DEANDRE"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ARON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 14,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_1] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_2] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_3] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_4] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_5] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_6] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_7] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_8] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_9] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_10] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_11] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_12] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_13] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_14] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_15] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRUNT_MAGMA_HIDEOUT_16] =
    {
        .trainerName = _("GRUNT"),
        .trainerClass = TRAINER_CLASS_TEAM_MAGMA,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BALTOY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TABITHA_MAGMA_HIDEOUT] =
    {
        .trainerName = _("TABITHA"),
        .trainerClass = TRAINER_CLASS_MAGMA_ADMIN,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZUBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(9, 9, 9, 9, 9, 9),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DARCY] =
    {
        .trainerName = _("DARCY"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAXIE_MOSSDEEP] =
    {
        .trainerName = _("MAXIE"),
        .trainerClass = TRAINER_CLASS_MAGMA_LEADER,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CROBAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(18, 18, 18, 18, 18, 18),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PETE] =
    {
        .trainerName = _("PETE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ISABELLE] =
    {
        .trainerName = _("ISABELLE"),
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANDRES_1] =
    {
        .trainerName = _("ANDRES"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JOSUE] =
    {
        .trainerName = _("JOSUE"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAMRON] =
    {
        .trainerName = _("CAMRON"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CORY_1] =
    {
        .trainerName = _("CORY"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CAROLINA] =
    {
        .trainerName = _("CAROLINA"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 24,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ELIJAH] =
    {
        .trainerName = _("ELIJAH"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CELIA] =
    {
        .trainerName = _("CELIA"),
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_GIRL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRYAN] =
    {
        .trainerName = _("BRYAN"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRANDEN] =
    {
        .trainerName = _("BRANDEN"),
        .trainerClass = TRAINER_CLASS_CAMPER,
        .trainerPic = TRAINER_PIC_CAMPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 22,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRYANT] =
    {
        .trainerName = _("BRYANT"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SHAYLA] =
    {
        .trainerName = _("SHAYLA"),
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KYRA] =
    {
        .trainerName = _("KYRA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_DODRIO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JAIDEN] =
    {
        .trainerName = _("JAIDEN"),
        .trainerClass = TRAINER_CLASS_NINJA_BOY,
        .trainerPic = TRAINER_PIC_NINJA_BOY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NINJASK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GULPIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALIX] =
    {
        .trainerName = _("ALIX"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HELENE] =
    {
        .trainerName = _("HELENE"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARLENE] =
    {
        .trainerName = _("MARLENE"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SPOINK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 18,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DEVAN] =
    {
        .trainerName = _("DEVAN"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_JOHNSON] =
    {
        .trainerName = _("JOHNSON"),
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 8,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MELINA] =
    {
        .trainerName = _("MELINA"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_RUNNING_TRIATHLETE_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DODUO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRANDI] =
    {
        .trainerName = _("BRANDI"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RALTS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_AISHA] =
    {
        .trainerName = _("AISHA"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAKAYLA] =
    {
        .trainerName = _("MAKAYLA"),
        .trainerClass = TRAINER_CLASS_EXPERT,
        .trainerPic = TRAINER_PIC_EXPERT_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ROSELIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FABIAN] =
    {
        .trainerName = _("FABIAN"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_DAYTON] =
    {
        .trainerName = _("DAYTON"),
        .trainerClass = TRAINER_CLASS_KINDLER,
        .trainerPic = TRAINER_PIC_KINDLER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLUGMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RACHEL] =
    {
        .trainerName = _("RACHEL"),
        .trainerClass = TRAINER_CLASS_PARASOL_LADY,
        .trainerPic = TRAINER_PIC_PARASOL_LADY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLDEEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LEONEL] =
    {
        .trainerName = _("LEONEL"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_QUICK_ATTACK,
                MOVE_THUNDER_WAVE,
            },
            },
        },
    },
    [TRAINER_CALLIE] =
    {
        .trainerName = _("CALLIE"),
        .trainerClass = TRAINER_CLASS_BATTLE_GIRL,
        .trainerPic = TRAINER_PIC_BATTLE_GIRL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CALE] =
    {
        .trainerName = _("CALE"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DUSTOX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_BEAUTIFLY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MYLES] =
    {
        .trainerName = _("MYLES"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PAT] =
    {
        .trainerName = _("PAT"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHROOMISH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MARILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GULPIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 25,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CRISTIN_1] =
    {
        .trainerName = _("CRISTIN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 29,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_RUSTBORO_TREECKO] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TORCHIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_RUSTBORO_TORCHIC] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 13,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MUDKIP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(6, 6, 6, 6, 6, 6),
            .lvl = 15,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ROXANNE_2] =
    {
        .trainerName = _("ROXANNE"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_MAGNITUDE,
                MOVE_EXPLOSION,
            },
            },
            {
            .species = SPECIES_KABUTO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
    [TRAINER_ROXANNE_3] =
    {
        .trainerName = _("ROXANNE"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_OMANYTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_MAGNITUDE,
                MOVE_EXPLOSION,
            },
            },
            {
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
    [TRAINER_ROXANNE_4] =
    {
        .trainerName = _("ROXANNE"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_OMASTAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PROTECT,
                MOVE_ROLLOUT,
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
            },
            },
            {
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
    [TRAINER_ROXANNE_5] =
    {
        .trainerName = _("ROXANNE"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_ROXANNE,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_AERODACTYL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROCK_SLIDE,
                MOVE_HYPER_BEAM,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_ROLLOUT,
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
            },
            },
            {
            .species = SPECIES_OMASTAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
                MOVE_ROCK_SLIDE,
                MOVE_SURF,
            },
            },
            {
            .species = SPECIES_KABUTOPS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SWORDS_DANCE,
                MOVE_ICE_BEAM,
                MOVE_SURF,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_STEELIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_IRON_TAIL,
                MOVE_EXPLOSION,
                MOVE_ROAR,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_DOUBLE_TEAM,
                MOVE_EXPLOSION,
                MOVE_PROTECT,
                MOVE_ROCK_SLIDE,
            },
            },
        },
    },
    [TRAINER_BRAWLY_2] =
    {
        .trainerName = _("BRAWLY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_KARATE_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
            .species = SPECIES_MEDITITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_TRIPLE_KICK,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FAKE_OUT,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_BRAWLY_3] =
    {
        .trainerName = _("BRAWLY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_KARATE_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_TRIPLE_KICK,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FAKE_OUT,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_BRAWLY_4] =
    {
        .trainerName = _("BRAWLY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SKY_UPPERCUT,
                MOVE_PROTECT,
                MOVE_FIRE_PUNCH,
                MOVE_ICE_PUNCH,
            },
            },
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_KARATE_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_PSYCHIC,
            },
            },
            {
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_TRIPLE_KICK,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FAKE_OUT,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_BRAWLY_5] =
    {
        .trainerName = _("BRAWLY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_BRAWLY,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HITMONLEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_MEGA_KICK,
                MOVE_FOCUS_PUNCH,
                MOVE_EARTHQUAKE,
                MOVE_BULK_UP,
            },
            },
            {
            .species = SPECIES_HITMONCHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SKY_UPPERCUT,
                MOVE_PROTECT,
                MOVE_FIRE_PUNCH,
                MOVE_ICE_PUNCH,
            },
            },
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_CROSS_CHOP,
                MOVE_ROCK_SLIDE,
                MOVE_FOCUS_PUNCH,
                MOVE_BULK_UP,
            },
            },
            {
            .species = SPECIES_MEDICHAM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FOCUS_PUNCH,
                MOVE_LIGHT_SCREEN,
                MOVE_REFLECT,
                MOVE_PSYCHIC,
            },
            },
            {
            .species = SPECIES_HITMONTOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PURSUIT,
                MOVE_COUNTER,
                MOVE_PROTECT,
                MOVE_TRIPLE_KICK,
            },
            },
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FAKE_OUT,
                MOVE_FOCUS_PUNCH,
                MOVE_BELLY_DRUM,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_WATTSON_2] =
    {
        .trainerName = _("WATTSON"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAREEP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_RAIN_DANCE,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_RAIN_DANCE,
            },
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
    [TRAINER_WATTSON_3] =
    {
        .trainerName = _("WATTSON"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PIKACHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_RAIN_DANCE,
                MOVE_SHOCK_WAVE,
            },
            },
            {
            .species = SPECIES_FLAAFFY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_RAIN_DANCE,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_RAIN_DANCE,
            },
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
    [TRAINER_WATTSON_4] =
    {
        .trainerName = _("WATTSON"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 44,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_AMPHAROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_RAIN_DANCE,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_RAIN_DANCE,
            },
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
    [TRAINER_WATTSON_5] =
    {
        .trainerName = _("WATTSON"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ELECTABUZZ,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SWIFT,
                MOVE_FOCUS_PUNCH,
                MOVE_THUNDER_PUNCH,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_RAICHU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_SLAM,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_AMPHAROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_THUNDER_WAVE,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_ELECTRODE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROLLOUT,
                MOVE_THUNDER,
                MOVE_EXPLOSION,
                MOVE_RAIN_DANCE,
            },
            },
            {
            .species = SPECIES_MAGNETON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_THUNDER,
                MOVE_RAIN_DANCE,
            },
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BITE,
                MOVE_THUNDER_WAVE,
                MOVE_THUNDER,
                MOVE_PROTECT,
            },
            },
        },
    },
    [TRAINER_FLANNERY_2] =
    {
        .trainerName = _("FLANNERY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
    [TRAINER_FLANNERY_3] =
    {
        .trainerName = _("FLANNERY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HELPING_HAND,
                MOVE_FLAMETHROWER,
                MOVE_ROAR,
                MOVE_SUNNY_DAY,
            },
            },
            {
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_PONYTA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
    [TRAINER_FLANNERY_4] =
    {
        .trainerName = _("FLANNERY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HOUNDOUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROAR,
                MOVE_SOLAR_BEAM,
                MOVE_TAUNT,
                MOVE_SUNNY_DAY,
            },
            },
            {
            .species = SPECIES_GROWLITHE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HELPING_HAND,
                MOVE_FLAMETHROWER,
                MOVE_SUNNY_DAY,
                MOVE_ROAR,
            },
            },
            {
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
    [TRAINER_FLANNERY_5] =
    {
        .trainerName = _("FLANNERY"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_FLANNERY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ARCANINE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HELPING_HAND,
                MOVE_FLAMETHROWER,
                MOVE_SUNNY_DAY,
                MOVE_ROAR,
            },
            },
            {
            .species = SPECIES_MAGCARGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_ATTRACT,
                MOVE_LIGHT_SCREEN,
                MOVE_ROCK_SLIDE,
            },
            },
            {
            .species = SPECIES_HOUNDOOM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_ROAR,
                MOVE_SOLAR_BEAM,
                MOVE_TAUNT,
                MOVE_SUNNY_DAY,
            },
            },
            {
            .species = SPECIES_RAPIDASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FLAMETHROWER,
                MOVE_ATTRACT,
                MOVE_SOLAR_BEAM,
                MOVE_BOUNCE,
            },
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EARTHQUAKE,
                MOVE_ATTRACT,
            },
            },
            {
            .species = SPECIES_TORKOAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_WHITE_HERB,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_OVERHEAT,
                MOVE_SUNNY_DAY,
                MOVE_EXPLOSION,
                MOVE_ATTRACT,
            },
            },
        },
    },
    [TRAINER_NORMAN_2] =
    {
        .trainerName = _("NORMAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 4,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BLIZZARD,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPER_BEAM,
                MOVE_FLAMETHROWER,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
    [TRAINER_NORMAN_3] =
    {
        .trainerName = _("NORMAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BLIZZARD,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
            .species = SPECIES_CHANSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 47,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FAKE_OUT,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPER_BEAM,
                MOVE_FLAMETHROWER,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
    [TRAINER_NORMAN_4] =
    {
        .trainerName = _("NORMAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BLIZZARD,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
            .species = SPECIES_BLISSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 52,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_LIGHT_SCREEN,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FAKE_OUT,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPER_BEAM,
                MOVE_FLAMETHROWER,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
    [TRAINER_NORMAN_5] =
    {
        .trainerName = _("NORMAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_BLIZZARD,
                MOVE_SHADOW_BALL,
                MOVE_DOUBLE_EDGE,
                MOVE_FIRE_BLAST,
            },
            },
            {
            .species = SPECIES_BLISSEY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PROTECT,
                MOVE_SING,
                MOVE_SKILL_SWAP,
                MOVE_FOCUS_PUNCH,
            },
            },
            {
            .species = SPECIES_KANGASKHAN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_FAKE_OUT,
                MOVE_DIZZY_PUNCH,
                MOVE_ENDURE,
                MOVE_REVERSAL,
            },
            },
            {
            .species = SPECIES_TAUROS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 57,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TAKE_DOWN,
                MOVE_PROTECT,
                MOVE_FIRE_BLAST,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TEETER_DANCE,
                MOVE_SKILL_SWAP,
                MOVE_FACADE,
                MOVE_HYPNOSIS,
            },
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 60,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPER_BEAM,
                MOVE_FLAMETHROWER,
                MOVE_THUNDERBOLT,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
    [TRAINER_WINONA_2] =
    {
        .trainerName = _("WINONA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DRATINI,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_WINONA_3] =
    {
        .trainerName = _("WINONA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HOOTHOOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 45,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_WINONA_4] =
    {
        .trainerName = _("WINONA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_DRAGONAIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER_WAVE,
                MOVE_THUNDERBOLT,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AERIAL_ACE,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_WINONA_5] =
    {
        .trainerName = _("WINONA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_WINONA,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NOCTOWL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_DREAM_EATER,
            },
            },
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_AERIAL_ACE,
                MOVE_SOLAR_BEAM,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SURF,
                MOVE_SUPERSONIC,
                MOVE_PROTECT,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_DRAGONITE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPER_BEAM,
                MOVE_THUNDERBOLT,
                MOVE_EARTHQUAKE,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WHIRLWIND,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
                MOVE_AERIAL_ACE,
            },
            },
            {
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 60,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SKY_ATTACK,
                MOVE_REST,
                MOVE_DRAGON_DANCE,
                MOVE_EARTHQUAKE,
            },
            },
        },
    },
    [TRAINER_TATE_AND_LIZA_2] =
    {
        .trainerName = _("TATE&LIZA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_ANCIENT_POWER,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 49,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
    [TRAINER_TATE_AND_LIZA_3] =
    {
        .trainerName = _("TATE&LIZA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DROWZEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 54,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 55,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
    [TRAINER_TATE_AND_LIZA_4] =
    {
        .trainerName = _("TATE&LIZA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_SLOWPOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 59,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 60,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 60,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
    [TRAINER_TATE_AND_LIZA_5] =
    {
        .trainerName = _("TATE&LIZA"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HYPNO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_DREAM_EATER,
                MOVE_HEADBUTT,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 64,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_EXPLOSION,
                MOVE_PSYCHIC,
                MOVE_LIGHT_SCREEN,
            },
            },
            {
            .species = SPECIES_SLOWKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_YAWN,
                MOVE_PSYCHIC,
                MOVE_CALM_MIND,
                MOVE_PROTECT,
            },
            },
            {
            .species = SPECIES_XATU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 64,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CONFUSE_RAY,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_LUNATONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_REST,
                MOVE_CALM_MIND,
            },
            },
            {
            .species = SPECIES_SOLROCK,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 65,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SUNNY_DAY,
                MOVE_SOLAR_BEAM,
                MOVE_PSYCHIC,
                MOVE_FLAMETHROWER,
            },
            },
        },
    },
    [TRAINER_JUAN_2] =
    {
        .trainerName = _("JUAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POLIWAG,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
            .species = SPECIES_WHISCASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 46,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_CRAWDAUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 48,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_REST,
                MOVE_CRABHAMMER,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
    [TRAINER_JUAN_3] =
    {
        .trainerName = _("JUAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 5,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 50,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
            .species = SPECIES_WHISCASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 51,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_CRAWDAUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 53,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_REST,
                MOVE_GUILLOTINE,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
    [TRAINER_JUAN_4] =
    {
        .trainerName = _("JUAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
                MOVE_ICE_BEAM,
                MOVE_CONFUSE_RAY,
            },
            },
            {
            .species = SPECIES_WHISCASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
            .species = SPECIES_POLIWHIRL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 56,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_RAIN_DANCE,
                MOVE_PROTECT,
                MOVE_HYDRO_PUMP,
            },
            },
            {
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_CRAWDAUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 58,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_REST,
                MOVE_GUILLOTINE,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
    [TRAINER_JUAN_5] =
    {
        .trainerName = _("JUAN"),
        .trainerClass = TRAINER_CLASS_LEADER,
        .trainerPic = TRAINER_PIC_LEADER_JUAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LAPRAS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
                MOVE_ICE_BEAM,
                MOVE_CONFUSE_RAY,
            },
            },
            {
            .species = SPECIES_WHISCASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_RAIN_DANCE,
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_FISSURE,
            },
            },
            {
            .species = SPECIES_POLITOED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 61,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_HYPNOSIS,
                MOVE_RAIN_DANCE,
                MOVE_HYDRO_PUMP,
                MOVE_PERISH_SONG,
            },
            },
            {
            .species = SPECIES_WALREIN,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_BODY_SLAM,
                MOVE_PROTECT,
                MOVE_SHEER_COLD,
            },
            },
            {
            .species = SPECIES_CRAWDAUNT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 63,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_REST,
                MOVE_GUILLOTINE,
                MOVE_TAUNT,
                MOVE_DOUBLE_TEAM,
            },
            },
            {
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_CHESTO_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 66,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_DOUBLE_TEAM,
                MOVE_ICE_BEAM,
                MOVE_REST,
            },
            },
        },
    },
    [TRAINER_ANGELO] =
    {
        .trainerName = _("ANGELO"),
        .trainerClass = TRAINER_CLASS_BUG_MANIAC,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ILLUMISE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHOCK_WAVE,
                MOVE_QUICK_ATTACK,
                MOVE_CHARM,
            },
            },
            {
            .species = SPECIES_VOLBEAT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 17,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_SHOCK_WAVE,
                MOVE_QUICK_ATTACK,
                MOVE_CONFUSE_RAY,
            },
            },
        },
    },
    [TRAINER_DARIUS] =
    {
        .trainerName = _("DARIUS"),
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_TROPIUS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(24, 24, 24, 24, 24, 24),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_STEVEN] =
    {
        .trainerName = _("STEVEN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_STEVEN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .items = { ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 77,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_SPIKES,
                MOVE_STEEL_WING,
            },
            },
            {
            .species = SPECIES_CLAYDOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 75,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_REFLECT,
                MOVE_LIGHT_SCREEN,
                MOVE_ANCIENT_POWER,
                MOVE_EARTHQUAKE,
            },
            },
            {
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 76,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_THUNDER,
                MOVE_EARTHQUAKE,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
            {
            .species = SPECIES_CRADILY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 76,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_GIGA_DRAIN,
                MOVE_ANCIENT_POWER,
                MOVE_INGRAIN,
                MOVE_CONFUSE_RAY,
            },
            },
            {
            .species = SPECIES_ARMALDO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 76,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_WATER_PULSE,
                MOVE_ANCIENT_POWER,
                MOVE_AERIAL_ACE,
                MOVE_SLASH,
            },
            },
            {
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .heldItem = ITEM_SITRUS_BERRY,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 78,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_EARTHQUAKE,
                MOVE_PSYCHIC,
                MOVE_METEOR_MASH,
                MOVE_SHADOW_BALL,
            },
            },
        },
    },
    [TRAINER_ANABEL] =
    {
        .trainerName = _("ANABEL"),
        .trainerClass = TRAINER_CLASS_SALON_MAIDEN,
        .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_TUCKER] =
    {
        .trainerName = _("TUCKER"),
        .trainerClass = TRAINER_CLASS_DOME_ACE,
        .trainerPic = TRAINER_PIC_DOME_ACE_TUCKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SPENSER] =
    {
        .trainerName = _("SPENSER"),
        .trainerClass = TRAINER_CLASS_PALACE_MAVEN,
        .trainerPic = TRAINER_PIC_PALACE_MAVEN_SPENSER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GRETA] =
    {
        .trainerName = _("GRETA"),
        .trainerClass = TRAINER_CLASS_ARENA_TYCOON,
        .trainerPic = TRAINER_PIC_ARENA_TYCOON_GRETA,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_NOLAND] =
    {
        .trainerName = _("NOLAND"),
        .trainerClass = TRAINER_CLASS_FACTORY_HEAD,
        .trainerPic = TRAINER_PIC_FACTORY_HEAD_NOLAND,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LUCY] =
    {
        .trainerName = _("LUCY"),
        .trainerClass = TRAINER_CLASS_PIKE_QUEEN,
        .trainerPic = TRAINER_PIC_PIKE_QUEEN_LUCY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRANDON] =
    {
        .trainerName = _("BRANDON"),
        .trainerClass = TRAINER_CLASS_PYRAMID_KING,
        .trainerPic = TRAINER_PIC_PYRAMID_KING_BRANDON,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BELDUM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANDRES_2] =
    {
        .trainerName = _("ANDRES"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANDRES_3] =
    {
        .trainerName = _("ANDRES"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANDRES_4] =
    {
        .trainerName = _("ANDRES"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSHREW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ANDRES_5] =
    {
        .trainerName = _("ANDRES"),
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_NOSEPASS,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SANDSLASH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CORY_2] =
    {
        .trainerName = _("CORY"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CORY_3] =
    {
        .trainerName = _("CORY"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACOOL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 32,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CORY_4] =
    {
        .trainerName = _("CORY"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CORY_5] =
    {
        .trainerName = _("CORY"),
        .trainerClass = TRAINER_CLASS_SAILOR,
        .trainerPic = TRAINER_PIC_SAILOR,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TENTACRUEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PABLO_2] =
    {
        .trainerName = _("PABLO"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PABLO_3] =
    {
        .trainerName = _("PABLO"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WINGULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PABLO_4] =
    {
        .trainerName = _("PABLO"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_PABLO_5] =
    {
        .trainerName = _("PABLO"),
        .trainerClass = TRAINER_CLASS_TRIATHLETE,
        .trainerPic = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_PELIPPER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_STARMIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KOJI_2] =
    {
        .trainerName = _("KOJI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KOJI_3] =
    {
        .trainerName = _("KOJI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAKUHITA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KOJI_4] =
    {
        .trainerName = _("KOJI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_KOJI_5] =
    {
        .trainerName = _("KOJI"),
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_HARIYAMA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 43,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CRISTIN_2] =
    {
        .trainerName = _("CRISTIN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(13, 13, 13, 13, 13, 13),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CRISTIN_3] =
    {
        .trainerName = _("CRISTIN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(14, 14, 14, 14, 14, 14),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CRISTIN_4] =
    {
        .trainerName = _("CRISTIN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(15, 15, 15, 15, 15, 15),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_VIGOROTH,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(12, 12, 12, 12, 12, 12),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_CRISTIN_5] =
    {
        .trainerName = _("CRISTIN"),
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_COOL,
        .items = { ITEM_HYPER_POTION },
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SPINDA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SLAKING,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(17, 17, 17, 17, 17, 17),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FERNANDO_2] =
    {
        .trainerName = _("FERNANDO"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FERNANDO_3] =
    {
        .trainerName = _("FERNANDO"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_ELECTRIKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FERNANDO_4] =
    {
        .trainerName = _("FERNANDO"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOUDRED,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 39,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_FERNANDO_5] =
    {
        .trainerName = _("FERNANDO"),
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MANECTRIC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_EXPLOUD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SAWYER_2] =
    {
        .trainerName = _("SAWYER"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SAWYER_3] =
    {
        .trainerName = _("SAWYER"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 28,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SAWYER_4] =
    {
        .trainerName = _("SAWYER"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUMEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 30,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_SAWYER_5] =
    {
        .trainerName = _("SAWYER"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MACHOKE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_CAMERUPT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_GOLEM,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABRIELLE_2] =
    {
        .trainerName = _("GABRIELLE"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_ZIGZAGOON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOTAD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEEDOT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 31,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABRIELLE_3] =
    {
        .trainerName = _("GABRIELLE"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_SKITTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_TAILLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 33,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABRIELLE_4] =
    {
        .trainerName = _("GABRIELLE"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LOMBRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_NUZLEAF,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 35,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_GABRIELLE_5] =
    {
        .trainerName = _("GABRIELLE"),
        .trainerClass = TRAINER_CLASS_PKMN_BREEDER,
        .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_DELCATTY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_MIGHTYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LINOONE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SHIFTRY,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SWELLOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 37,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_THALIA_2] =
    {
        .trainerName = _("THALIA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_HORSEA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(1, 1, 1, 1, 1, 1),
            .lvl = 34,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_THALIA_3] =
    {
        .trainerName = _("THALIA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(2, 2, 2, 2, 2, 2),
            .lvl = 36,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_THALIA_4] =
    {
        .trainerName = _("THALIA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILMER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_SEADRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(3, 3, 3, 3, 3, 3),
            .lvl = 38,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_THALIA_5] =
    {
        .trainerName = _("THALIA"),
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUVDISC,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_WAILORD,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_KINGDRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(4, 4, 4, 4, 4, 4),
            .lvl = 40,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MARIELA] =
    {
        .trainerName = _("MARIELA"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CHIMECHO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_ALVARO] =
    {
        .trainerName = _("ALVARO"),
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .doubleBattle = FALSE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BANETTE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
            {
            .species = SPECIES_KADABRA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_EVERETT] =
    {
        .trainerName = _("EVERETT"),
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_RICH,
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_WOBBUFFET,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_RED] =
    {
        .trainerName = _("RED"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_RED,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_CHARMANDER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_LEAF] =
    {
        .trainerName = _("LEAF"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_PIC_LEAF,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_BULBASAUR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_BRENDAN_PLACEHOLDER] =
    {
        .trainerName = _("BRENDAN"),
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .trainerPic = TRAINER_PIC_RS_BRENDAN,
        .encounterMusic_gender =
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GROUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_MAY_PLACEHOLDER] =
    {
        .trainerName = _("MAY"),
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .trainerPic = TRAINER_PIC_RS_MAY,
        .encounterMusic_gender =
F_TRAINER_FEMALE |
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .doubleBattle = FALSE,
        .partySize = 1,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_KYOGRE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            },
        },
    },
    [TRAINER_HIKER_CHALLENGE] =
    {
        .trainerName = _("KERHI"),
        .trainerClass = TRAINER_CLASS_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_GRAVELER,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 15, 19, 26, 22, 18),
            .ev = TRAINER_PARTY_EVS(200, 50, 50, 0, 100, 100),
            .lvl = 35,
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_BLAST, MOVE_DOUBLE_EDGE, MOVE_ROCK_POLISH},
            .ability = ABILITY_ROCK_HEAD,
            .heldItem = ITEM_FOCUS_SASH,
            },
            {
            .species = SPECIES_GARGANACL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 25, 25, 26, 22, 31),
            .ev = TRAINER_PARTY_EVS(250, 50, 50, 0, 100, 100),
            .lvl = 38,
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {MOVE_STEALTH_ROCK, MOVE_SMACK_DOWN, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH},
            .ability = ABILITY_ROCK_HEAD,
            .heldItem = ITEM_HARD_STONE,
            },
            {
            .species = SPECIES_MACHAMP,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 25, 25, 26, 22, 31),
            .ev = TRAINER_PARTY_EVS(50, 250, 50, 0, 100, 100),
            .lvl = 36,
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {MOVE_STRENGTH, MOVE_CROSS_CHOP, MOVE_POWER_UP_PUNCH, MOVE_BULLET_PUNCH},
            .ability = ABILITY_GUTS,
            .heldItem = ITEM_TOXIC_ORB,
            },
            {
            .species = SPECIES_RHYPERIOR,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .ev = TRAINER_PARTY_EVS(250, 250, 50, 0, 100, 100),
            .lvl = 38,
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_ROCK_BLAST, MOVE_CRUNCH},
            .ability = ABILITY_LIGHTNING_ROD,
            .heldItem = ITEM_MUSCLE_BAND,
            },
            {
            .species = SPECIES_ONIX,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .ev = TRAINER_PARTY_EVS(250, 250, 250, 0, 250, 250),
            .lvl = 71,
            .nature = NATURE_BOLD,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {MOVE_TACKLE, MOVE_BIDE, MOVE_ROCK_SMASH, MOVE_TOXIC},
            .ability = ABILITY_STURDY,
            .heldItem = ITEM_EVIOLITE,
            },
            {
            .species = SPECIES_GEODUDE,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
            .lvl = 5,
            .nature = NATURE_BOLD,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {MOVE_SELFDESTRUCT},
            .ability = ABILITY_ROCK_HEAD,
            .heldItem = ITEM_ORAN_BERRY,
            },
        },
    }

};
