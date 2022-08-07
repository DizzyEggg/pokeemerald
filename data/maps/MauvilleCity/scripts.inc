.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM24
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM24_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "ZIO: Immagino sia grazie ai POKéMON \n"
	.string "che questo ragazzo è diventato così\l"
	.string "energico… anche troppo, direi…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "LINO: ZIO, per favore!\p"
	.string "Voglio sfidare questa PALESTRA per\n"
	.string "vedere se ho fatto progressi.\p"
	.string "Posso? Ti prego…$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "ZIO: Aspetta, LINO.\p"
	.string "Da quando hai cominciato a vivere con\n"
	.string "i POKéMON sei diventato molto più forte.\p"
	.string "Ma non pensi di esagerare nel voler\n"
	.string "sfidare subito una PALESTRA?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "LINO: Non sto esagerando.\p"
	.string "Io e RALTS insieme possiamo battere\n"
	.string "chiunque.$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "LINO: Oh, ciao, {PLAYER}!\p"
	.string "Sono diventato molto più forte da\n"
	.string "quando ci siamo visti l’ultima volta.\p"
	.string "{PLAYER}, vorrei che tu e mio ZIO\n"
	.string "lo capiste.\p"
	.string "{PLAYER}, ti va di lottare con me?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "LINO: Oh… {PLAYER} se non lotti con me,\n"
	.string "mio ZIO non saprà mai come sono\l"
	.string "diventato forte.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "ZIO: {PLAYER}{KUN}, vero?\n"
	.string "Da parte di LINO, ti chiedo di lottare\l"
	.string "con lui.\p"
	.string "Credo proprio che non si riuscirà\n"
	.string "a farlo desistere.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "LINO: {PLAYER}, per favore!\n"
	.string "Lotta con me, ti prego.$"

MauvilleCity_Text_WallyHereICome:
	.string "LINO: Grazie, {PLAYER}.\p"
	.string "Ok, eccomi!$"

MauvilleCity_Text_WallyDefeat:
	.string "LINO: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Ho perso…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "LINO: ZIO…\n"
	.string "Ritornerò a MENTANIA…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "Grazie, {PLAYER}.\n"
	.string "È difficile fare l’ALLENATORE, vero?\p"
	.string "Non basta avere dei POKéMON da far\n"
	.string "lottare. Essere un ALLENATORE ha\l"
	.string "un significato più profondo.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "ZIO: LINO, non buttarti giù.\p"
	.string "Nessuno ti impedisce di diventare\n"
	.string "sempre più forte.\p"
	.string "Dai, andiamo a casa. Ti stanno\n"
	.string "aspettando tutti.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "ZIO: {PLAYER}{KUN}, mi sono appena reso conto\n"
	.string "che sei l’ALLENATORE che ha aiutato\l"
	.string "LINO a catturare il suo POKéMON.\p"
	.string "Perché non ci vieni a trovare a\n"
	.string "MENTANIA un giorno?\l"
	.string "LINO ne sarà felice.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Driiin!\p"
	.string "LINO: Ciao, {PLAYER}!\p"
	.string "Ti chiamo per dirti che mio zio mi\n"
	.string "ha comprato un POKéNAV!\p"
	.string "Adesso possiamo sentirci ogni\n"
	.string "volta che vogliamo, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MauvilleCity_Text_RegisteredWally:
	.string "Registrazione di LINO nel POKéNAV\n"
	.string "avvenuta.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Eheh… stavo\n"
	.string "guardando la lotta!\p"
	.string "Tu e quel LINO siete amici,\n"
	.string "non è vero?\p"
	.string "Ma tu hai dato il meglio di te e\n"
	.string "l’hai battuto in maniera esemplare.\p"
	.string "Sì! È questo il vero spirito delle\n"
	.string "lotte di POKéMON!\p"
	.string "Adoro gli ALLENATORI che si\n"
	.string "comportano così!\p"
	.string "… … … … … …\n"
	.string "Farò il tifo per te!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WALTER: Oh, {PLAYER}{KUN}!\n"
	.string "Sembri un tipo dinamico!\l"
	.string "È una buona cosa, ahahah!\p"
	.string "Beh, ascolta.\n"
	.string "Ho bisogno di un favore, {PLAYER}{KUN}!\p"
	.string "A CICLAMIPOLI c’è un’area sotterranea\n"
	.string "chiamata CICLANOVA.\p"
	.string "{PLAYER}{KUN}, vorrei che tu ci andassi\n"
	.string "e spegnessi il GENERATORE.\p"
	.string "Si è guastato e sta diventando \n"
	.string "pericoloso.\p"
	.string "Eccoti la CHIAVE per entrare\n"
	.string "a CICLANOVA.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WALTER: Non preoccuparti, per te\n"
	.string "sarà come bere un bicchier d’acqua!\p"
	.string "L’entrata di CICLANOVA è ad un breve\n"
	.string "tragitto in SURF dal PERCORSO 110.\p"
	.string "Conto su di te!\n"
	.string "Ahah!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WALTER: Ahahah!\p"
	.string "{PLAYER}{KUN}, sapevo di aver chiesto \n"
	.string "alla persona giusta!\p"
	.string "Come ringraziamento, eccoti una MT\n"
	.string "contenente FULMINE!\p"
	.string "Prendila, te la sei meritata!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WALTER: Ahahah!\p"
	.string "Non sai che piacere sia per me vedere\n"
	.string "i giovani far strada e diventare\l"
	.string "responsabili!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Avere POKéMON che lottano è sì bello,\n"
	.string "ma…\p"
	.string "se uno dei tuoi POKéMON si indebolisce,\n"
	.string "devi curarlo e farlo tornare in salute.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Le strade di questa città vanno in ogni\n"
	.string "direzione: nord, sud, est e ovest.\p"
	.string "È per questo che passano tante\n"
	.string "persone di qui.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Hai fatto un salto da BICI CLELIO?\p"
	.string "Il proprietario, CLELIO, è una persona\n"
	.string "molto generosa.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Puoi incappare in POKéMON selvatici\n"
	.string "anche se sei in BICI.$"

MauvilleCity_Text_CitySign:
	.string "CICLAMIPOLI\n"
	.string "“La fulgente città dei divertimenti!”.$"

MauvilleCity_Text_GymSign:
	.string "PALESTRA POKéMON di CICLAMIPOLI\n"
	.string "CAPOPALESTRA: WALTER\l"
	.string "“L’uomo dal sorriso elettrizzante!”.$"

MauvilleCity_Text_BikeShopSign:
	.string "BICI CLELIO\n"
	.string "“Con la bici sulla via, vai felice\l"
	.string "in compagnia!”.$"

MauvilleCity_Text_GameCornerSign:
	.string "CASINÒ di CICLAMIPOLI\n"
	.string "“Divertimento per tutti!”.$"

MauvilleCity_Text_ExplainTV:
	.string "Dai un’occhiata alla TV ogni tanto?\p"
	.string "Fanno degli show interessanti\n"
	.string "ultimamente.\p"
	.string "La TV è straordinaria. A volte ci ho\n"
	.string "visto degli amici, così, all’improvviso.\p"
	.string "E a volte capita di vedere se stessi\n"
	.string "a propria insaputa…\p"
	.string "Un giorno mi piacerebbe andare in TV.\p"
	.string "Vale la pena dare un’occhiata alla TV\n"
	.string "quando se ne ha l’occasione.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Ciao, hai mai dato un’occhiata alla TV?$"
