EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Sono DRAKE, maestro del tipo DRAGO e\n"
	.string "tuo ultimo sfidante dei SUPERQUATTRO\l"
	.string "della LEGA POKéMON!\p"
	.string "Nel loro habitat naturale, i POKéMON\n"
	.string "sono selvatici e allo stato brado.\p"
	.string "A volte, ci sono di ostacolo.\n"
	.string "A volte, di aiuto.\p"
	.string "Sai che cosa ci vuole per lottare\n"
	.string "fianco a fianco con i POKéMON?\p"
	.string "Dimmi, sai quello che ci vuole?\p"
	.string "Beh, se non lo sai non potrai mai\n"
	.string "battermi!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Superbo, non c’è che dire.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "Ho molta stima di te: hai fatto tanta\n"
	.string "strada come ALLENATORE di POKéMON.\p"
	.string "Sicuramente sai che cosa ci vuole\n"
	.string "per essere un grande ALLENATORE.\p"
	.string "Sì, un ALLENATORE deve avere\n"
	.string "un cuore virtuoso.\p"
	.string "I POKéMON fanno breccia nel cuore\n"
	.string "degli ALLENATORI e sanno fare tesoro\l"
	.string "delle esperienze, anche se negative.\p"
	.string "Scaldano il buon cuore degli ALLENATORI\n"
	.string "e si rafforzano.\p"
	.string "Prendi il coraggio a due mani!\n"
	.string "Il CAMPIONE ti sta aspettando!$"

