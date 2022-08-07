.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "LINO: Ciao! {PLAYER}!\p"
	.string "Hai visto che bella sorpresa ti faccio?!\p"
	.string "Se sono riuscito ad arrivare fin qui,\n"
	.string "lo devo interamente a te!\p"
	.string "{PLAYER}, aver perso contro di te\n"
	.string "quella volta mi ha reso più forte!\p"
	.string "Ma questa volta non mi batterai!\p"
	.string "Vincerò, in onore dei POKéMON\n"
	.string "che mi hanno dato forza e coraggio!\p"
	.string "Ok… sono pronto!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, la tua forza è strabiliante!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "LINO: Oggi non sono riuscito a\n"
	.string "batterti, {PLAYER}, ma uno di questi\l"
	.string "giorni mi prenderò la rivincita!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "LINO: Ciao! {PLAYER}!\p"
	.string "Sono diventato più forte dell’ultima\n"
	.string "volta! Volevo dimostrartelo, {PLAYER}!\p"
	.string "Ok… eccomi qua!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, la tua forza è strabiliante!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "LINO: Anche questa volta non ce l’ho\n"
	.string "fatta… Ma un giorno, {PLAYER}, ti farò\l"
	.string "vedere di che pasta sono fatto!\p"
	.string "E sfiderò persino la LEGA POKéMON!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Sono arrivato fin qui già due volte,\n"
	.string "ma quest’ultimo tratto non finisce mai…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "I miei sogni si infrangono qui\n"
	.string "per la seconda volta…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Hai fatto tanta strada. Mantieni\n"
	.string "lo stesso slancio e diventa il CAMPIONE!\l"
	.string "Tu sì che ce la puoi fare!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Non ho fatto tanta strada per perdere\n"
	.string "proprio ora. Non esiste proprio!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Mi sembra impossibile… ho perso?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Ho perso…\p"
	.string "Evidentemente non ho ancora le carte\n"
	.string "in regola per diventare CAMPIONE…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Questa via così dura e, all’apparenza,\n"
	.string "infinita, è degna del nome VITTORIA.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Hai uno stile di lotta fantastico…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Sembri avere la stoffa del CAMPIONE.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Che cos’è la VIA VITTORIA?\n"
	.string "Te lo dirò se vinci!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Ok!\n"
	.string "Ben fatto!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Riuscire ad attraversarla è la prova\n"
	.string "finale che ogni ALLENATORE deve\l"
	.string "superare per diventare CAMPIONE\l"
	.string "di POKéMON.\p"
	.string "Per questo si chiama VIA VITTORIA.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Ho rispetto per chi è arrivato fin qui.\n"
	.string "Forza!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "Che disgrazia…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Vai pure avanti.\n"
	.string "A me non importa.$"
