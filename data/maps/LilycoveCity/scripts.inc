.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "VERA: {PLAYER}{KUN}, anche tu a far\n"
	.string "compere, eh?\p"
	.string "Ieri ho comprato parecchie BAMBOLE e\n"
	.string "tanti POSTER.\p"
	.string "Naturalmente, ho catturato anche molti\n"
	.string "POKéMON e li sto allenando proprio bene.\p"
	.string "Ho paura che tu non ti occupi dei tuoi\n"
	.string "POKéMON con cura, {PLAYER}{KUN}.\p"
	.string "Lotterò con te, così vedrò\n"
	.string "i tuoi POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "VERA: Ma non hai allenato i tuoi\n"
	.string "POKéMON, {PLAYER}{KUN}?\p"
	.string "Non fai una gran bella figura\n"
	.string "come ALLENATORE…$"

LilycoveCity_Text_MayBattleMe:
	.string "VERA: Dai, lotta con me, così posso\n"
	.string "controllare i tuoi POKéMON!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "VERA: I POKéMON allenati da me non la\n"
	.string "daranno vinta ai tuoi, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Mi ricordo della lotta che abbiamo avuto\n"
	.string "sul PERCORSO 103, {PLAYER}{KUN}.\p"
	.string "È grazie a quella lotta che hai\n"
	.string "accresciuto la tua forza, {PLAYER}{KUN}, no?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "VERA: Sto pensando di tornare\n"
	.string "ad ALBANOVA al più presto.\p"
	.string "Ormai ho una bella squadretta di\n"
	.string "POKéMON e il mio POKéDEX ha fatto\l"
	.string "progressi. Vorrei mostrarli a mio padre.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, che farai tu?\p"
	.string "Vuoi vincere le MEDAGLIE di tutte\n"
	.string "le PALESTRE e sfidare la LEGA POKéMON?\p"
	.string "Se tu collezioni le MEDAGLIE, {PLAYER}{KUN},\n"
	.string "io mi darò da fare con il mio POKéDEX.\l"
	.string "Lo completerò prima di te!\p"
	.string "Ciao!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, che cosa intendi fare?\p"
	.string "Vuoi sfidare la LEGA POKéMON?\p"
	.string "O preferisci completare il tuo\n"
	.string "POKéDEX?\p"
	.string "Ho sì perso contro di te, ma il POKéDEX\n"
	.string "lo completerò prima io!\p"
	.string "Ciao!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, che cosa intendi fare?\p"
	.string "Vuoi sfidare il PARCO LOTTA?\p"
	.string "O preferisci completare il tuo\n"
	.string "POKéDEX?\p"
	.string "Ho sì perso contro di te, ma il POKéDEX\n"
	.string "lo completerò prima io!\p"
	.string "Ciao!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDON: Oh, ma tu sei {PLAYER}!\p"
	.string "Sono qui per sbrigare una faccenda per \n"
	.string "mio padre, e non per comprare BAMBOLE!\p"
	.string "È da un po’ che non ci si vede, eh?\p"
	.string "Vuoi lottare per vedere chi ha allenato\n"
	.string "meglio i suoi POKéMON?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRENDON: Ma che succede?\n"
	.string "Non ne hai il coraggio?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDON: Vuoi lottare per vedere chi ha\n"
	.string "allenato meglio i suoi POKéMON?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDON: Non mi farò battere da te,\n"
	.string "{PLAYER}!$"

LilycoveCity_Text_BrendanDefeat:
	.string "Uh… ne hai fatto di allenamento!\p"
	.string "E pensare che prima ero più forte\n"
	.string "di te come ALLENATORE…!$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRENDON: Pensavo di tornare a casa\n"
	.string "ad ALBANOVA.\p"
	.string "Sto aiutando mio padre con il POKéDEX.\n"
	.string "Siccome sta andando benino, voglio\l"
	.string "mostrarglielo.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, che cosa intendi fare?\p"
	.string "Vuoi vincere le MEDAGLIE di tutte le\n"
	.string "PALESTRE e sfidare la LEGA POKéMON?\p"
	.string "Forse lo farò anch’io!\n"
	.string "Comunque, tieni duro!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, che cosa intendi fare?\p"
	.string "Ti senti abbastanza forte per sfidare\n"
	.string "la LEGA POKéMON, vero?\p"
	.string "Se allenassi meglio i miei POKéMON,\n"
	.string "sarei più forte di te, {PLAYER}.\p"
	.string "Comunque, tieni duro!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, che cosa intendi fare?\p"
	.string "Sfiderai il PARCO LOTTA?\p"
	.string "O preferisci completare il tuo\n"
	.string "POKéDEX?\p"
	.string "Sei forte. Dovresti prendere in\n"
	.string "considerazione la sfida al PARCO LOTTA.\p"
	.string "Se allenassi meglio i miei POKéMON,\n"
	.string "sarei più forte di te, {PLAYER}.\l"
	.string "Forse andrò anch’io al PARCO LOTTA.\p"
	.string "Comunque, tieni duro!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "Anche oggi il bottino nel nostro\n"
	.string "RIFUGIO è aumentato…\p"
	.string "Ma… tu chi sei?!\n"
	.string "Stavo parlando da solo!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Sono solo una RECLUTA, e non so\n"
	.string "come la pensi il CAPO…\p"
	.string "Sono però un membro del TEAM IDRO,\n"
	.string "quindi farò grandi cose!\p"
	.string "Ma… tu chi sei?!\n"
	.string "Stavo parlando da solo!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Ehi, tu!\p"
	.string "Non avvicinarti alla grotta nella baia!\p"
	.string "Perché? Che ti importa del motivo!\n"
	.string "Io sono un adulto e tu devi ascoltarmi!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Se l’intero mondo appartenesse a noi\n"
	.string "del TEAM IDRO, sarebbe un mondo più\l"
	.string "felice anche per i POKéMON.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Ehi, WAILMER!\n"
	.string "Salta subito fuori dall’acqua!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Cosa vuoi?\p"
	.string "Stai disturbando il nostro allenamento,\n"
	.string "perché non ti dilegui?$"

LilycoveCity_Text_ContestHallInTown:
	.string "C’è un’ARENA delle VIRTÙ in questa\n"
	.string "città.\p"
	.string "POKéMON ben allenati arrivano da\n"
	.string "ogni parte del paese.\p"
	.string "Non sto nella pelle!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Hai visto quella strana grotta nella\n"
	.string "baia ai margini della città?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Per partecipare alla GARA, insegnerò \n"
	.string "delle nuove mosse ai miei POKéMON.\p"
	.string "Andrò dall’ELIMINAMOSSE e farò\n"
	.string "scordare loro qualche mossa MN.$"

LilycoveCity_Text_ImFromKanto:
	.string "Vengo da KANTO.\p"
	.string "La regione di HOENN è favolosa con\n"
	.string "i suoi corsi d’acqua e la sua natura\l"
	.string "rigogliosa.\p"
	.string "Ma, aspetta un attimo…\p"
	.string "È possibile che ci siano POKéMON rari\n"
	.string "in quest’area?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "Il TEAM IDRO allena i suoi WAILMER\n"
	.string "nella baia…\p"
	.string "impedendo a noi MARINAI di uscire\n"
	.string "in mare con le nostre barche!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Lo sapevi?\p"
	.string "Qualcuno ci ha liberato dal TEAM IDRO!\p"
	.string "Così i WAILMER se ne sono andati dalla\n"
	.string "baia e noi possiamo uscire di nuovo\l"
	.string "in mare con le nostre barche.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Facevo un sonnellino in un alberghetto\n"
	.string "sul mare cullata dal rumore delle onde…\p"
	.string "quando qualcuno ha rubato il mio\n"
	.string "POKéMON!\p"
	.string "Chi sarà il rapitore?\p"
	.string "Il TEAM IDRO? Sarà il TEAM IDRO?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Il mio POKéMON scomparso…\n"
	.string "è tornato senza che me ne accorgessi!$"

LilycoveCity_Text_ImArtDealer:
	.string "Sono un MERCANTE d’ARTE.\p"
	.string "Compro e vendo opere d’arte,\n"
	.string "in particolare dipinti.\p"
	.string "Ho sentito dire che ci sono opere\n"
	.string "favolose in esposizione al MUSEO…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Mentre noi diventiamo vecchi, il mare\n"
	.string "rimane sempre giovane nella sua\l"
	.string "magnificenza e vitalità…\p"
	.string "Ohohohoh…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Sono passati sessant’anni da quando\n"
	.string "mio marito mi ha chiesto in moglie qui.\l"
	.string "Il mare è più bello che mai.\p"
	.string "Mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Sai che c’è una strana grotta\n"
	.string "in questa baia?\p"
	.string "Era una formazione naturale, ma poi è\n"
	.string "arrivato il TEAM IDRO e ha apportato\l"
	.string "alcune modifiche.\p"
	.string "Si fanno chiamare il “TEAM IDRO\n"
	.string "amante della natura”!\p"
	.string "Ma fra il dire e il fare c’è di mezzo \n"
	.string "il mare!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Quella grotta nella baia…\p"
	.string "Non mi ero accorto che l’avessero\n"
	.string "completamente svuotata.\p"
	.string "Il TEAM IDRO sembra essersene\n"
	.string "andato definitivamente.$"

LilycoveCity_Text_CitySign:
	.string "PORTO ALGHEPOLI\p"
	.string "“Là dove la terra finisce e il mare\n"
	.string "comincia”.$"

LilycoveCity_Text_ContestHallSign:
	.string "ARENA delle VIRTÙ\n"
	.string "“Dove si incontrano gli ALLENATORI!”.$"

LilycoveCity_Text_MotelSign:
	.string "HOTEL ALGA\p"
	.string "“Il paradiso dei viandanti\n"
	.string "di ALGHEPOLI”.$"

LilycoveCity_Text_MuseumSign:
	.string "MUSEO di ALGHEPOLI\p"
	.string "“Collezione di opere d’arte POKéMON\n"
	.string "in esposizione!”.$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUSEO di ALGHEPOLI\p"
	.string "“Collezione POKéMON di {PLAYER} \n"
	.string "in esposizione!”.$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "SCALO di ALGHEPOLI\p"
	.string "“Il traghetto M/N MAREA è in\n"
	.string "costruzione a PORTO SELCEPOLI.\p"
	.string "Entrerà in servizio tra breve”.$"

LilycoveCity_Text_HarborSign:
	.string "SCALO di ALGHEPOLI\p"
	.string "“Concedetevi una rilassante crociera\n"
	.string "sul traghetto M/N MAREA”.$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "FAN CLUB ALLENATORI di POKéMON \p"
	.string "Gli ALLENATORI hanno scritto i loro nomi\n"
	.string "sul cartello…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "CENTRO COMMERCIALE di ALGHEPOLI\p"
	.string "“Merce favolosa e divertimento\n"
	.string "a volontà!\p"
	.string "Il posto dove troverai quel qualcosa\n"
	.string "di cui hai bisogno!”.$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "CASA dell’ELIMINAMOSSE\p"
	.string "“Per far scordare ai POKéMON le mosse\n"
	.string "indesiderate”.$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Mai sentito parlare di una macchina\n"
	.string "chiamata MIXER BACCHE?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Manovrandola in più persone, la si \n"
	.string "può far girare più velocemente.\p"
	.string "Più forte gira, migliori sono le {POKEMELLE}.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Si usa per fare un nuovo tipo di\n"
	.string "caramella chiamata {POKEMELLA}.\p"
	.string "Dai una buona {POKEMELLA} a un POKéMON,\n"
	.string "migliorerai le sue virtù.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Dicono che c’è una torre nei pressi\n"
	.string "di un percorso marino.\p"
	.string "Si chiama TORRE dei CIELI, mi pare.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Ho visto una torre alta nei pressi\n"
	.string "del PERCORSO 131.\p"
	.string "Ti sembra possibile…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Siamo qui in luna di miele.\p"
	.string "Abbiamo visto un POKéMON di tipo\n"
	.string "DRAGO volare alto nel cielo.\p"
	.string "Ci sono altri POKéMON del genere\n"
	.string "nella regione di HOENN?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Ci siamo ripromessi di vedere molti\n"
	.string "POKéMON rari in luna di miele.\p"
	.string "Quindi siamo stati felicissimi di\n"
	.string "vederne uno appena arrivati.\p"
	.string "Siamo al settimo cielo!$"

