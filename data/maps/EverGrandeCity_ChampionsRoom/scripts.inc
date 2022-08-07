.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
    releaseall
    end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "ADRIANO: Ti do il benvenuto,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Riguardo a CENERIDE…\n"
	.string "Hai fatto un lavoro superbo. Hai messo\l"
	.string "fine alla crisi senza l’aiuto di nessuno.\p"
	.string "Oops!\p"
	.string "Non è del tutto corretto dire\n"
	.string "senza l’aiuto di nessuno.\p"
	.string "Hai superato la crisi insieme alla\n"
	.string "tua squadra di POKéMON.\p"
	.string "Noi ALLENATORI alleviamo i\n"
	.string "POKéMON, gli diamo strumenti e gli\l"
	.string "insegniamo nuove tecniche di lotta.\p"
	.string "Tuttavia, anche noi impariamo\n"
	.string "moltissime cose dai POKéMON.\p"
	.string "Questo è il luogo dove puoi\n"
	.string "confrontarti con altri come te e\l"
	.string "mettere alla prova la tua abilità.\p"
	.string "Adesso!\p"
	.string "Chi sa danzare più elegantemente\n"
	.string "con i propri POKéMON nella\l"
	.string "regione di HOENN?\p"
	.string "È giunto il momento di scoprirlo!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Io, il CAMPIONE, sono stato sconfitto…\p"
	.string "Un lavoro eccellente.\n"
	.string "Un’eleganza… quasi esasperante.\l"
	.string "Al tempo stesso semplicemente sublime!\p"
	.string "Gloria a te, {PLAYER}{KUN}!\p"
	.string "Sei un ALLENATORE di POKéMON\n"
	.string "di grande nobiltà d’animo!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "ADRIANO: I POKéMON che hai fatto\n"
	.string "lottare…\p"
	.string "a volte danzavano leggiadri come la\n"
	.string "brezza del mattino e a volte colpivano\l"
	.string "con l’intensità del fulmine.\p"
	.string "Li hai guidati con un’eleganza\n"
	.string "sopraffina e con incredibile fermezza.\p"
	.string "Sono stato quasi abbagliato dalla\n"
	.string "tua maestria.\p"
	.string "Ora hai raggiunto la gloriosa vetta\n"
	.string "della LEGA POKéMON.\p"
	.string "Ti conferisco il titolo di…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "VERA: {PLAYER}{KUN}!\p"
	.string "Eccoti qualche utile consiglio prima\n"
	.string "di sfidare il CAMPIONE…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "VERA: Uh? Che cosa?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Non può essere vero…\l"
	.string "È già tutto finito?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRENDON: {PLAYER}!\p"
	.string "Vuoi qualche dritta prima della\n"
	.string "supersfida con il CAMPIONE…?$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRENDON: {PLAYER}…\p"
	.string "Non mi dirai…\n"
	.string "che hai già sfidato il CAMPIONE?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. BIRCH: Ecco!\n"
	.string "Proprio come pensavo, {RIVAL}!\p"
	.string "Non ti avevo detto che {PLAYER}{KUN}\n"
	.string "se la sarebbe cavata benissimo?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, ce l’hai fatta.\p"
	.string "Quando ho sentito che avevi sconfitto\n"
	.string "addirittura tuo padre nella PALESTRA di\l"
	.string "PETALIPOLI, ho capito che forse\l"
	.string "c’era una possibilità…\p"
	.string "Oggi questo presentimento è diventato\n"
	.string "realtà. Sei il CAMPIONE!\p"
	.string "Ah, dimenticavo!\p"
	.string "A che punto è il tuo POKéDEX?\n"
	.string "Fammi vedere.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. BIRCH: Congratulazioni vivissime!\p"
	.string "Ora entra a testa alta nella sala\n"
	.string "finale!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "ADRIANO: {PLAYER}{KUN}…\p"
	.string "O meglio…\p"
	.string "Nuovo CAMPIONE!\p"
	.string "Seguimi.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "ADRIANO: Spiacente, ma…\p"
	.string "solo gli ALLENATORI CAMPIONI\n"
	.string "possono procedere oltre.\p"
	.string "Devi aspettare fuori con\n"
	.string "il PROF. BIRCH.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "VERA: Uffi…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Scherzo, ok!\n"
	.string "Le regole sono regole!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Congratulazioni vivissime!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRENDON: Cooosa?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Capisco, non sono ammessi\n"
	.string "strappi alla regola!\p"
	.string "{PLAYER}, sei grande!\n"
	.string "Congratulazioni!$"

