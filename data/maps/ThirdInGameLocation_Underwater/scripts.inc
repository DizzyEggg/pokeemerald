ThirdInGameLocation_Underwater_MapScripts::
# 3 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_LOAD
# 12 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_LOAD:
# 4 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_LOAD_1
# 9 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 54, 75, 0x22F, TRUE
	return

ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 5 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 72, METATILE_Underwater_RockWall, TRUE
# 6 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 71, METATILE_Underwater_RockWall, TRUE
	return

ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 13 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 10
	goto_if_eq ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 14 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setobjectxyperm 8, 26, 2
	return


ThirdInGameLocation_Underwater_EscapeTrigger::
# 20 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_EscapeTrigger_Text_0, FIELD_PIC_BIDOOF_NORMAL, MSGBOX_YESNO
# 22 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ThirdInGameLocation_Underwater_EscapeTrigger_2
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepBack
# 28 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 29 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_EscapeTrigger_Text_2, FIELD_PIC_BIDOOF_NORMAL
ThirdInGameLocation_Underwater_EscapeTrigger_1:
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_EscapeTrigger_2:
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_EscapeTrigger_Text_1, FIELD_PIC_BIDOOF_ASTONISHED
# 24 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	warpteleport MAP_DARKNESS_TRANSITION_MAP, 9, 76
	goto ThirdInGameLocation_Underwater_EscapeTrigger_1


# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
Movement_PlayerStepBack:
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_SuicuneBattle::
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 43 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_0, FIELD_PIC_SUICUNE, MSGBOX_YESNO
# 45 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ThirdInGameLocation_Underwater_SuicuneBattle_2
ThirdInGameLocation_Underwater_SuicuneBattle_1:
# 75 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_SuicuneBattle_2:
# 46 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
# 47 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_1, FIELD_PIC_SUICUNE
# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 49 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setwildbattle SPECIES_SUICUNE, 862
# 50 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dowildbattle
# 51 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	getbyte gBattleOutcome, VAR_RESULT
# 52 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ThirdInGameLocation_Underwater_SuicuneBattle_4
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 11
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_4, FIELD_PIC_SUICUNE
# 59 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	message ThirdInGameLocation_Underwater_SuicuneBattle_Text_5
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 61 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 62 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BADGE03_GET
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_6, FIELD_PIC_BIDOOF_HAPPY
# 64 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_7, FIELD_PIC_SUICUNE
# 65 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_8, FIELD_PIC_BIDOOF_ASTONISHED
# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_9, FIELD_PIC_SUICUNE
# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_10, FIELD_PIC_BIDOOF_ASTONISHED
# 68 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_11, FIELD_PIC_SUICUNE
# 69 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 70 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative ScrCmd_PlayBattleTransition
# 71 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 72 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_12, FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_SuicuneBattle_1

ThirdInGameLocation_Underwater_SuicuneBattle_4:
# 53 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_2, FIELD_PIC_SUICUNE
# 54 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_3, FIELD_PIC_BIDOOF_NORMAL
# 55 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	special HealPlayerParty
	goto ThirdInGameLocation_Underwater_SuicuneBattle_1


ThirdInGameLocation_Underwater_SuicuneTrigger::
# 80 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 81 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	fadeoutbgm 1
# 82 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_DOWNPOUR
# 83 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative ScrCmd_PlayBattleTransition
# 84 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 85 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_DOWNPOUR_STOP
# 86 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	fadeinbgm 2
# 87 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 8, MovementSuicuneJump
# 88 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 89 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setobjectxyperm 8, 26, 2
# 90 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementExclamationMark
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, MovementExclamationMark
# 92 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_0, FIELD_PIC_BIDOOF_ASTONISHED
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_1, FIELD_PIC_SUICUNE
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_2, FIELD_PIC_BIDOOF_ASTONISHED
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_3, FIELD_PIC_SUICUNE
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_4, FIELD_PIC_BIDOOF_ASTONISHED
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_5, FIELD_PIC_SUICUNE
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_6, FIELD_PIC_BIDOOF_NORMAL
# 100 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SUICUNE_TRIGGER_DONE
# 101 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 10
# 102 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 106 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementSuicuneJump:
# 107 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_up
# 108 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 110 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 113 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementExclamationMark:
# 114 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_exclamation_mark
# 115 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_WildMonsSoon_Down::
# 119 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementJustFaceDown
# 121 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto ThirdInGameLocation_Underwater_WildMonsSoon
	return


ThirdInGameLocation_Underwater_WildMonsSoon_Left::
# 125 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 126 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementJustFaceLeft
# 127 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto ThirdInGameLocation_Underwater_WildMonsSoon
	return


ThirdInGameLocation_Underwater_WildMonsSoon::
# 131 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 132 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 7
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_0, VAR_0x8008
# 135 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 136 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_1, VAR_0x800A
# 137 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_2, VAR_0x8008
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_3, VAR_0x8008
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_4, VAR_0x800A
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 141 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_WildMonsSoon_Text_5
# 142 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dynmultichoice 0, 5, TRUE, 1, 0, DYN_MULTICHOICE_CB_NONE, ThirdInGameLocation_Underwater_WildMonsSoon_Text_6
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_7, VAR_0x8008
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_8, VAR_0x8008
# 145 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 146 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerIntoGrass
# 148 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 150 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_SAFARI_MODE
# 151 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setbyte gNumSafariBalls, 1
# 152 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setwildbattle SPECIES_CHINCHOU, 35
# 153 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dowildbattle
# 154 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	clearflag FLAG_SYS_SAFARI_MODE
# 155 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8009
# 156 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_9, VAR_0x8009
# 157 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 158 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_10, VAR_0x8008
# 159 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 8
# 160 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x8009
# 161 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 162 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 166 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementJustFaceDown:
# 167 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 168 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 171 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementJustFaceLeft:
# 172 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_left
# 173 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 176 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerIntoGrass:
# 177 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 179 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_up_down
# 180 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_right_left
# 181 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_up_down
# 182 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_right_left
# 183 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_PsychicGuru::
# 187 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 188 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_PSYHIC_GURU_TALKED_WITH, ThirdInGameLocation_Underwater_PsychicGuru_2
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_10
ThirdInGameLocation_Underwater_PsychicGuru_1:
# 211 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_PsychicGuru_2:
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_0
# 191 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_1
# 192 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_2
# 194 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY
# 195 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_3
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_4
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_5
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_6
# 199 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 200 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 29
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_7
# 204 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_8
# 205 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_9
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_PSYHIC_GURU_TALKED_WITH
	goto ThirdInGameLocation_Underwater_PsychicGuru_1


ThirdInGameLocation_Underwater_ActivateRockSwitch::
# 216 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 217 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_ActivateRockSwitch_2
# 250 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2
ThirdInGameLocation_Underwater_ActivateRockSwitch_1:
# 252 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_ActivateRockSwitch_2:
# 218 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 219 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 220 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_F
# 221 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 222 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_E
# 223 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 224 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_D
# 225 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 226 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 227 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 228 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 229 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 230 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 231 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 232 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 233 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 234 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_CLICK
# 235 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 236 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_CAVE_DOOR_PUZZLE_DONE
# 237 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_WINGULL
# 238 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 72, 0x22E, FALSE
# 239 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 71, 0x226, FALSE
# 240 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 54, 75, 0x22F, TRUE
# 241 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	special DrawWholeMapView
# 242 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 243 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SuicuneTrigger_Text_0
# 244 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0
# 245 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 246 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 247 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1
# 248 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_ActivateRockSwitch_1


ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger::
# 257 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 258 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2
ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1:
# 271 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_TRIGGER_3RD_MAP_SEEMS_NO_WAY
# 272 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2:
# 259 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 260 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0
# 261 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitbuttonpress
# 262 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 263 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 264 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SeeNoWay
# 265 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 266 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 267 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1
# 268 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2
# 269 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
	goto ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1


# 276 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
Movement_SeeNoWay:
# 277 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 278 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 279 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 280 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 281 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 282 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Bidoof3::
# 286 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 287 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 288 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_2
# 330 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 2
	goto_if_eq ThirdInGameLocation_Bidoof3_3
ThirdInGameLocation_Bidoof3_1:
# 432 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_2:
# 289 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8009
# 290 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_0
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 292 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 293 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_1
# 294 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 296 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_2
# 297 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 298 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 299 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_3
# 300 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 302 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_4
# 303 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 304 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 305 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_5
# 306 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 307 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_7
# 308 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 309 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 310 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_8
# 311 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_9
# 312 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 313 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 314 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 315 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 316 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8009
# 317 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_10
# 318 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 319 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 320 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_11
# 321 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 322 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x8009
# 323 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800A
# 324 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 325 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 326 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 327 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_3:
# 331 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 332 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_12, MSGBOX_YESNO
# 333 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_7
# 423 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 424 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 425 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_27
# 426 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
ThirdInGameLocation_Bidoof3_6:
# 428 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 429 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 430 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_1

ThirdInGameLocation_Bidoof3_7:
# 334 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 335 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_10
# 416 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 417 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 418 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_26
# 419 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x800A
	goto ThirdInGameLocation_Bidoof3_6

ThirdInGameLocation_Bidoof3_10:
# 336 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_13
# 337 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 338 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 339 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_14
# 340 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 341 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_SMIRKY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 342 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_15
# 343 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_SMIRKY, VAR_0x800A
# 344 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 345 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 346 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 347 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ThirdInGameLocation_Bidoof3_14
# 354 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_Up
# 355 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 356 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_Up
# 357 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
ThirdInGameLocation_Bidoof3_13:
# 359 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_ToRockSmash
# 360 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_ToRockSmash
# 361 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 362 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PC_LOGIN
# 363 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_16
# 364 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_17
# 365 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 366 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 4
# 367 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 368 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 369 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 370 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 371 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject VAR_LAST_TALKED
# 372 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_ROCK_SMASH_3RD_LOC
# 373 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 374 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_18
# 375 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 376 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 377 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_19
# 378 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 379 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800B
# 380 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_20
# 381 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 382 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 383 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_21, MSGBOX_YESNO
# 384 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_18
ThirdInGameLocation_Bidoof3_17:
# 398 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 399 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_25
# 400 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_3
# 401 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 402 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 403 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 5
# 404 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 405 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 406 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800B
# 407 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 408 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative UpdateFollowingPokemon
# 409 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 410 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerDown
# 411 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 412 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_14:
# 348 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_East
# 349 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 350 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_East
# 351 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_13

ThirdInGameLocation_Bidoof3_18:
ThirdInGameLocation_Bidoof3_22:
# 386 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 387 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 388 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_22
# 389 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 390 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 391 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_23, MSGBOX_YESNO
# 392 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_22
# 393 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 394 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 395 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_24
# 396 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
	goto ThirdInGameLocation_Bidoof3_17


# 436 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerDown:
# 437 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 438 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 441 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_ToRockSmash:
# 442 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 443 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 444 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 445 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 446 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 447 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 448 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 449 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 450 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 451 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 454 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_ToRockSmash:
# 455 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 456 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 457 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 458 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 459 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 460 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 461 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 462 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 463 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 464 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 467 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_East:
# 468 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 469 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 470 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 471 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 474 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_East:
# 475 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 476 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 479 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_Up:
# 480 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 481 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 482 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 483 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 486 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_Up:
# 487 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 488 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 491 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof3:
# 492 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 493 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_RockSmash::
# 497 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 498 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 499 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Underwater_RockSmash_2
# 503 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_1
ThirdInGameLocation_Underwater_RockSmash_1:
# 505 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_RockSmash_2:
# 500 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_0
	goto ThirdInGameLocation_Underwater_RockSmash_1


ThirdInGameLocation_Underwater_BidoffTrigger2::
# 510 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 511 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 512 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_2
# 513 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 3, MovementBidoof2
# 514 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 515 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 3
# 516 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 520 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof2:
# 521 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 522 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 523 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 524 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 525 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 526 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 527 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 528 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 529 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 530 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 531 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 532 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_BidoffTrigger1::
# 536 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 537 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 538 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_1
# 539 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 2, MovementBidoof1
# 540 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 541 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 2
# 542 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 546 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof1:
# 547 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 548 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 549 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 550 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 551 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 552 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 553 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 554 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 555 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_CreepyHexManiac::
# 559 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 560 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 561 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 562 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 563 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 564 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 565 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 566 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 567 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 568 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 569 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 570 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 571 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 573 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_set FLAG_BIDOOF_FOLLOWER, ThirdInGameLocation_Underwater_CreepyHexManiac_2
ThirdInGameLocation_Underwater_CreepyHexManiac_1:
# 579 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_CreepyHexManiac_2:
# 574 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 27
# 575 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 576 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0
# 577 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
	goto ThirdInGameLocation_Underwater_CreepyHexManiac_1


# 583 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 584 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 585 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 586 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 587 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 588 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 589 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 590 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 593 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 594 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 595 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 596 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 597 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 598 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 599 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 600 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 601 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_EscapeTrigger_Text_0:
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Do you really want to leave, {PLAYER}?$"

ThirdInGameLocation_Underwater_EscapeTrigger_Text_1:
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, I'm really nervous about it!\pWelp!$"

ThirdInGameLocation_Underwater_EscapeTrigger_Text_2:
# 29 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You're right, let's prepare ourselves\n"
	.string "first!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_0:
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Do you wish to battle me?$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_1:
# 47 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Here I come!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_2:
# 53 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Not yet! Come back when you're better\n"
	.string "prepeared.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_3:
# 54 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You can't give up now, {PLAYER}!\p"
	.string "There must be some way to defeat him, I\n"
	.string "believe in you!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_4:
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Splendid!\p"
	.string "I admit my defeat. Please take this as a\n"
	.string "proof of overcoming this challenge.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_5:
# 59 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "{PLAYER} received the Suicune Badge.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_6:
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Wow! You're rocking it, {PLAYER}!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_7:
# 64 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "As I promised earlier, you are free to\n"
	.string "leave this place. However, let me warn\l"
	.string "you. I cannot guarantee you'll be able\l"
	.string "to return here. The things you will\l"
	.string "experience from now on, are nothing like\l"
	.string "you have ever seen before. This world\l"
	.string "may already seem beyond repair, but it\l"
	.string "gets worse.\p"
	.string "Bidoof.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_8:
# 65 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, what!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_9:
# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you are aware of the dangers,\n"
	.string "and know what you are doing.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_10:
# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I have absolutely no idea what you're\n"
	.string "referring to!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_11:
# 68 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll take that as a yes. That was my\n"
	.string "final warning. Proceed with caution.\p"
	.string "{PLAYER}.\p"
	.string "Bidoof.\p"
	.string "Au revoir.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_12:
# 72 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Wow, that was certainly something!\p"
	.string "He did sound serious though...I have no\n"
	.string "idea what awaits us once we leave this\l"
	.string "place, {PLAYER}. Let's prepare\l"
	.string "ourselves for the worst. As Suicune\l"
	.string "said, I have no idea if we'll be able to\l"
	.string "go back. Make sure to equip everything\l"
	.string "you think could be useful in the future.\l"
	.string "Once you're ready, let's go!$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_0:
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly!$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_1:
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It is a pleasure to finally meet you,\n"
	.string "{PLAYER}!\p"
	.string "You too Bidoof, it has been a while\n"
	.string "since the last time.$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_2:
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Is this the legendary Suicune?!$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_3:
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "The guardian's role has been assigned\n"
	.string "to me, and I'll do my best to fulfill it.\p"
	.string "I will not let you pass, until you have\n"
	.string "proved your worth to me. You see, this\l"
	.string "distorted world has given me an immense\l"
	.string "power, I feel stronger than ever. As\l"
	.string "such, this trial will pertain to your\l"
	.string "craftiness. In order to defeat me in a\l"
	.string "battle, you will need to think outside\l"
	.string "the box, to come up with non-standard\l"
	.string "solutions.$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_4:
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, sounds scary!$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_5:
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "There is nothing scary about it, Bidoof.\n"
	.string "You and I both know this. In fact, if\l"
	.string "there is anything you should be scared\l"
	.string "about, it's triumphing over me and\l"
	.string "passing through that door.\p"
	.string "Nonetheless, I'll be waiting for you\n"
	.string "here. Whenever you feel ready, I'll take\l"
	.string "on your challenge.$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_6:
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hmm, this looks different than what we\n"
	.string "have faced before! Be careful,\l"
	.string "{PLAYER}! It probably won't be as\l"
	.string "easy as that Hiker's battle.\p"
	.string "In any case, let's do our best!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_0:
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey, {PLAYER}! There's long grass\n"
	.string "ahead. Do you know what it means? Well,\l"
	.string "it means that it's dangerous to go\l"
	.string "there without a Pokemon!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_1:
# 136 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, don't give me that look! I'm too\n"
	.string "weak to handle all of these by my own!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_2:
# 137 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "But don't you worry, chum. I've got a\n"
	.string "plan!\p"
	.string "Listen carefully!\p"
	.string "I'll give you one of these Poke Balls,\n"
	.string "you'll use it to capture the wild\l"
	.string "Pokemon, and then we'll be able to cross\l"
	.string "the grass! Clever, isn't it?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_3:
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Uhm? Where did I get the Poke Ball from?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_4:
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Well, sometimes it's better not to know\n"
	.string "everything!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_5:
# 141 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "So, what do you say? Are you in?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_6:
# 142 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "What if it doesn't get caught?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_7:
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries! I've already taken that into\n"
	.string "account. Remember how we blended\l"
	.string "berries with Wingull? You actually got a\l"
	.string "{POKEBLOCK}, which can be fed to Pokemon!\l"
	.string "That'll make it easier to catch!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_8:
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright, let's go!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_9:
# 156 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Nicely done, {PLAYER}! You've just\n"
	.string "caught your very first Pokemon! I\l"
	.string "certainly hope it won't be your last!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_10:
# 158 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright {PLAYER}, I believe we can go\n"
	.string "into the long grass without worrying\l"
	.string "about wild Pokemon. Let's continue\l"
	.string "ahead.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_0:
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Y{PAUSE 15}-O{PAUSE 25}-U!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_1:
# 191 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Yes, you two! Do not be timid! Welcome in\n"
	.string "my domain - the forest!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_2:
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Forest? We're underwater...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_3:
# 195 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "YES! The trees are my servants, look at\n"
	.string "their majestic movements. Observe how\l"
	.string "they gracely dance with the wind!\n"
	.string "Yes, yes, do you hear them talking?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_4:
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Listen closely!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_5:
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "V2UncmUgcm9ja3MsIG5vdCB0cmVlcy\n4gV2UncmUgdW5kZXJ3YXRlciBhbmQg\lbm90IGluc2lkZSBhIGZvcmVzdC4gQW\l5kIHRoaXMgZ3V5IGlzIGEgZnUqKmluZy\lBtb3JvbiwgZG9uJ3QgbGlzdGVuIHRv\lIGhpbSB+IHNpbmNlcmVseSwgd\lGhlIHJvY2tzLg==$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_6:
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Aren't they magnificent?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_7:
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Psst! {PLAYER}!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_8:
# 204 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think this person is going to\n"
	.string "help us much...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_9:
# 205 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's leave and go our way.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_10:
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I take good care of my servants.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0:
# 244 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I think you did something...$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1:
# 247 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's see what's changed.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2:
# 250 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It is already activated.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0:
# 260 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1:
# 267 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It seems the way is blocked\nby these rocks.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2:
# 268 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think I'll be able to smash these\n"
	.string "by myself. Let's try to find some other\l"
	.string "way to get past them.$"

ThirdInGameLocation_Bidoof3_Text_0:
# 290 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly...$"

ThirdInGameLocation_Bidoof3_Text_1:
# 293 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hi.$"

ThirdInGameLocation_Bidoof3_Text_2:
# 296 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I mean! You must be pretty surprised to\n"
	.string "see a Bidoof underwater! After all,\l"
	.string "ocean's depths are not my natural\l"
	.string "habitat.$"

ThirdInGameLocation_Bidoof3_Text_3:
# 299 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's weird, isn't it? Seeing a Bidoof\n"
	.string "here...A talking Bidoof at that!$"

ThirdInGameLocation_Bidoof3_Text_4:
# 302 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Though you don't look that\n"
	.string "surprised...Or you do? Golly, I can't\l"
	.string "tell!$"

ThirdInGameLocation_Bidoof3_Text_5:
# 305 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Sorry about earlier, running off like\n"
	.string "that. I was a bit scared when I saw you\l"
	.string "floating around there! But you seem\l"
	.string "like a nice chum.$"

ThirdInGameLocation_Bidoof3_Text_6:
# 306 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "...$"

ThirdInGameLocation_Bidoof3_Text_7:
# 307 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "We need to get out of here. I don't know\n"
	.string "if you're aware, but there is a rock down\l"
	.string "there blocking the way.$"

ThirdInGameLocation_Bidoof3_Text_8:
# 310 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, it's really weird how it's\n"
	.string "placed there, just like that. As if it\l"
	.string "was put on purpose...Though, I have to\l"
	.string "tell you, this whole place is so\l"
	.string "strange...$"

ThirdInGameLocation_Bidoof3_Text_9:
# 311 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's not natural at all...Well, it doesn't\n"
	.string "matter that much I guess! We need to\l"
	.string "get out of here!$"

ThirdInGameLocation_Bidoof3_Text_10:
# 317 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "The problem is...I have no idea how! I\n"
	.string "tried to break the rock myself, but as\l"
	.string "you can clearly see, it didn't work.$"

ThirdInGameLocation_Bidoof3_Text_11:
# 320 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll rest a bit and try to think of a\n"
	.string "solution. In the meantime feel free to\l"
	.string "roam about, maybe you'll find something\l"
	.string "useful!$"

ThirdInGameLocation_Bidoof3_Text_12:
# 332 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey pal, did you find something?$"

ThirdInGameLocation_Bidoof3_Text_13:
# 336 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...Hidden machines...I know how these\n"
	.string "work!$"

ThirdInGameLocation_Bidoof3_Text_14:
# 339 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it just so happens that I can learn\n"
	.string "this move!$"

ThirdInGameLocation_Bidoof3_Text_15:
# 342 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get some rocks broken!$"

ThirdInGameLocation_Bidoof3_Text_16:
# 363 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof learned {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_17:
# 364 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof used {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_18:
# 374 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it's done! We make quite the team,\n"
	.string "huh?$"

ThirdInGameLocation_Bidoof3_Text_19:
# 377 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, I think it'll be better if we\n"
	.string "hold together. At least, until we're out\l"
	.string "of here.$"

ThirdInGameLocation_Bidoof3_Text_20:
# 380 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Who knows whatever may loom here...$"

ThirdInGameLocation_Bidoof3_Text_21:
# 383 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you agree with me, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_22:
# 388 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, you can't be serious!\n$"

ThirdInGameLocation_Bidoof3_Text_23:
# 391 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get out of here together, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_24:
# 395 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, please do not joke like that!$"

ThirdInGameLocation_Bidoof3_Text_25:
# 399 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright! Take the lead, {PLAYER}. I'll\n"
	.string "be right behind you.$"

ThirdInGameLocation_Bidoof3_Text_26:
# 418 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! I'm not convinced...$"

ThirdInGameLocation_Bidoof3_Text_27:
# 425 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries!$"

ThirdInGameLocation_Underwater_RockSmash_Text_0:
# 500 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\n"
	.string "Pokemon knowing the move {COLOR RED}Rock Smash{COLOR DARK_GRAY}\l"
	.string "could smash it.$"

ThirdInGameLocation_Underwater_RockSmash_Text_1:
# 503 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\nThere must be a way to smash it somehow...$"

ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0:
# 576 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! Did-did you see that???$"
