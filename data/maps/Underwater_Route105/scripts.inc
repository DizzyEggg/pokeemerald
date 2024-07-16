Underwater_Route105_MapScripts::
# 2 "data/maps/Underwater_Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Script_Underwater_Route105_OnResume
# 6 "data/maps/Underwater_Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Underwater_Route105_MapScripts_MAP_SCRIPT_ON_LOAD
# 3 "data/maps/Underwater_Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Underwater_Route105_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Underwater_Route105_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/Underwater_Route105/scripts.pory"
	compare VAR_HACK_GAME_STATE, 13
	goto_if_ge Underwater_Route105_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

Underwater_Route105_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 9 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 20, 51, 0x21B, TRUE
# 10 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 20, 50, 0x21B, TRUE
# 11 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 54, 75, 0x22F, TRUE
# 13 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 21, 59, 0x2A9, FALSE
# 14 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 20, 60, 0x2A9, FALSE
# 15 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 21, 60, 0x2A9, FALSE
# 16 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 21, 61, 0x2A9, FALSE
# 18 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 20, 58, 0x27E, TRUE
# 19 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 20, 59, 0x286, TRUE
# 20 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 19, 60, 0x286, TRUE
# 21 "data/maps/Underwater_Route105/scripts.pory"
	setmetatile 20, 61, 0x27E, TRUE
	return

Underwater_Route105_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/Underwater_Route105/scripts.pory"
	map_script_2 VAR_HACK_GAME_STATE, 14, Script_UnderwaterRoute105_SaveGame
	.2byte 0


Script_Underwater_Route105_OnResume::
# 27 "data/maps/Underwater_Route105/scripts.pory"
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end


Script_UnderwaterRoute105_SaveGame::
# 32 "data/maps/Underwater_Route105/scripts.pory"
	lock
# 33 "data/maps/Underwater_Route105/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 15
# 34 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Script_UnderwaterRoute105_SaveGame_Text_0
# 35 "data/maps/Underwater_Route105/scripts.pory"
	callnative ScrCmd_SaveGame
# 36 "data/maps/Underwater_Route105/scripts.pory"
	closemessage
# 37 "data/maps/Underwater_Route105/scripts.pory"
	release
	end


Underwater_Route105_Sign1::
# 42 "data/maps/Underwater_Route105/scripts.pory"
	random 5
# 43 "data/maps/Underwater_Route105/scripts.pory"
	switch VAR_RESULT
# 44 "data/maps/Underwater_Route105/scripts.pory"
	case 0, Underwater_Route105_Sign1_2
# 45 "data/maps/Underwater_Route105/scripts.pory"
	case 1, Underwater_Route105_Sign1_3
# 46 "data/maps/Underwater_Route105/scripts.pory"
	case 2, Underwater_Route105_Sign1_4
# 47 "data/maps/Underwater_Route105/scripts.pory"
	case 3, Underwater_Route105_Sign1_5
# 48 "data/maps/Underwater_Route105/scripts.pory"
	case 4, Underwater_Route105_Sign1_6
	return

Underwater_Route105_Sign1_2:
# 44 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_0, MSGBOX_SIGN
	return

Underwater_Route105_Sign1_3:
# 45 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_1, MSGBOX_SIGN
	return

Underwater_Route105_Sign1_4:
# 46 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_2, MSGBOX_SIGN
	return

Underwater_Route105_Sign1_5:
# 47 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_3, MSGBOX_SIGN
	return

Underwater_Route105_Sign1_6:
# 48 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_4, MSGBOX_SIGN
	return


Script_UnderwaterRoute105_SaveGame_Text_0:
# 34 "data/maps/Underwater_Route105/scripts.pory"
	.string "WAIT...$"

Underwater_Route105_Sign1_Text_0:
# 44 "data/maps/Underwater_Route105/scripts.pory"
	.string "Panneau.$"

Underwater_Route105_Sign1_Text_1:
# 45 "data/maps/Underwater_Route105/scripts.pory"
	.string "Questo è un cartello.$"

Underwater_Route105_Sign1_Text_2:
# 46 "data/maps/Underwater_Route105/scripts.pory"
	.string "Esto es una señal.$"

Underwater_Route105_Sign1_Text_3:
# 47 "data/maps/Underwater_Route105/scripts.pory"
	.string "This is a signpost.$"

Underwater_Route105_Sign1_Text_4:
# 48 "data/maps/Underwater_Route105/scripts.pory"
	.string "German: TODO.$"
