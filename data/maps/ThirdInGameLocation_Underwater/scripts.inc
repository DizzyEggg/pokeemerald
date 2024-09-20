ThirdInGameLocation_Underwater_MapScripts::
# 3 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_LOAD
# 12 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 17 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
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

ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 18 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script_2 VAR_TEMP_0, VAR_VALUE_GOT_KOED, Script_BidoofHeal_Underwater_GotKOedByWild
	.2byte 0


Script_BidoofHeal_Underwater_GotKOedByWild::
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 24 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	special HealPlayerParty
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait Script_BidoofHeal_Underwater_GotKOedByWild_Text_0, FIELD_PIC_BIDOOF_ASTONISHED
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait Script_BidoofHeal_Underwater_GotKOedByWild_Text_1, FIELD_PIC_BIDOOF_NORMAL
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_TEMP_0, 0
# 28 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


ThirdInGameLocation_Underwater_EscapeTrigger::
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_EscapeTrigger_Text_0, FIELD_PIC_BIDOOF_NORMAL, MSGBOX_YESNO
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ThirdInGameLocation_Underwater_EscapeTrigger_2
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 40 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepBack
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_EscapeTrigger_Text_2, FIELD_PIC_BIDOOF_NORMAL
ThirdInGameLocation_Underwater_EscapeTrigger_1:
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_EscapeTrigger_2:
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_EscapeTrigger_Text_1, FIELD_PIC_BIDOOF_ASTONISHED
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	warpteleport MAP_DARKNESS_TRANSITION_MAP, 9, 76
	goto ThirdInGameLocation_Underwater_EscapeTrigger_1


# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
Movement_PlayerStepBack:
# 49 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 50 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 51 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_SuicuneBattle::
# 55 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 56 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_0, FIELD_PIC_SUICUNE, MSGBOX_YESNO
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ThirdInGameLocation_Underwater_SuicuneBattle_2
ThirdInGameLocation_Underwater_SuicuneBattle_1:
# 88 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_SuicuneBattle_2:
# 59 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_1, FIELD_PIC_SUICUNE
# 61 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 62 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setwildbattle SPECIES_SUICUNE, 862
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dowildbattle
# 64 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	getbyte gBattleOutcome, VAR_RESULT
# 65 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ThirdInGameLocation_Underwater_SuicuneBattle_4
# 70 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 11
# 71 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_4, FIELD_PIC_SUICUNE
# 72 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	message ThirdInGameLocation_Underwater_SuicuneBattle_Text_5
# 73 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 74 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 75 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BADGE03_GET
# 76 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_6, FIELD_PIC_BIDOOF_HAPPY
# 77 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_7, FIELD_PIC_SUICUNE
# 78 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_8, FIELD_PIC_BIDOOF_ASTONISHED
# 79 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_9, FIELD_PIC_SUICUNE
# 80 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_10, FIELD_PIC_BIDOOF_ASTONISHED
# 81 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_11, FIELD_PIC_SUICUNE
# 82 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 83 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative ScrCmd_PlayBattleTransition
# 84 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 85 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_12, FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_SuicuneBattle_1

ThirdInGameLocation_Underwater_SuicuneBattle_4:
# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_2, FIELD_PIC_SUICUNE
# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneBattle_Text_3, FIELD_PIC_BIDOOF_NORMAL
# 68 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	special HealPlayerParty
	goto ThirdInGameLocation_Underwater_SuicuneBattle_1


ThirdInGameLocation_Underwater_SuicuneTrigger::
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	fadeoutbgm 1
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_DOWNPOUR
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative ScrCmd_PlayBattleTransition
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_DOWNPOUR_STOP
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	fadeinbgm 2
# 100 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 8, MovementSuicuneJump
# 101 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 102 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setobjectxyperm 8, 26, 2
# 103 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementExclamationMark
# 104 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, MovementExclamationMark
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 106 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_0, FIELD_PIC_BIDOOF_ASTONISHED
# 107 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_1, FIELD_PIC_SUICUNE
# 108 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_2, FIELD_PIC_BIDOOF_ASTONISHED
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_3, FIELD_PIC_SUICUNE
# 110 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_4, FIELD_PIC_BIDOOF_ASTONISHED
# 111 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_5, FIELD_PIC_SUICUNE
# 112 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SuicuneTrigger_Text_6, FIELD_PIC_BIDOOF_NORMAL
# 113 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SUICUNE_TRIGGER_DONE
# 114 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 10
# 115 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 119 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementSuicuneJump:
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_up
# 121 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 122 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 123 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 126 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementExclamationMark:
# 127 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_exclamation_mark
# 128 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_WildMonsSoon_Down::
# 132 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementJustFaceDown
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto ThirdInGameLocation_Underwater_WildMonsSoon
	return


ThirdInGameLocation_Underwater_WildMonsSoon_Left::
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementJustFaceLeft
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto ThirdInGameLocation_Underwater_WildMonsSoon
	return


ThirdInGameLocation_Underwater_WildMonsSoon::
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 145 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 7
# 146 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_0, FIELD_PIC_BIDOOF_NORMAL
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_1, FIELD_PIC_BIDOOF_ASTONISHED
# 148 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_2, FIELD_PIC_BIDOOF_NORMAL
# 149 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_3, FIELD_PIC_BIDOOF_NORMAL
# 150 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_4, FIELD_PIC_BIDOOF_ASTONISHED
# 151 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_5, FIELD_PIC_BIDOOF_NORMAL
# 152 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dynmultichoice 0, 5, TRUE, 1, 0, DYN_MULTICHOICE_CB_NONE, ThirdInGameLocation_Underwater_WildMonsSoon_Text_6
# 153 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_7, FIELD_PIC_BIDOOF_NORMAL
# 154 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_8, FIELD_PIC_BIDOOF_NORMAL
# 155 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 156 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 157 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerIntoGrass
# 158 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 160 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_SAFARI_MODE
# 161 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setbyte gNumSafariBalls, 1
# 162 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setwildbattle SPECIES_CHINCHOU, 35
# 163 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dowildbattle
# 164 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	clearflag FLAG_SYS_SAFARI_MODE
# 165 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_9, FIELD_PIC_BIDOOF_HAPPY
# 166 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_WildMonsSoon_Text_10, FIELD_PIC_BIDOOF_NORMAL
# 167 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 8
# 168 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 172 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementJustFaceDown:
# 173 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 174 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 177 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementJustFaceLeft:
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_left
# 179 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 182 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerIntoGrass:
# 183 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 184 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 184 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 184 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 185 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_up_down
# 186 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_right_left
# 187 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_up_down
# 188 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_right_left
# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_PsychicGuru::
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 194 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 195 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_PSYHIC_GURU_TALKED_WITH, ThirdInGameLocation_Underwater_PsychicGuru_2
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_8
ThirdInGameLocation_Underwater_PsychicGuru_1:
# 211 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_PsychicGuru_2:
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_0
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_1
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_PsychicGuru_Text_2, FIELD_PIC_BIDOOF_UNEASY
# 199 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_3
# 200 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_4
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_5
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_6
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 204 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 205 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 29
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_PsychicGuru_Text_7, FIELD_PIC_BIDOOF_NORMAL
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_PSYHIC_GURU_TALKED_WITH
	goto ThirdInGameLocation_Underwater_PsychicGuru_1


ThirdInGameLocation_Underwater_ActivateRockSwitch::
# 216 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 217 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_ActivateRockSwitch_2
# 245 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2
ThirdInGameLocation_Underwater_ActivateRockSwitch_1:
# 247 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
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
	msgbox_portrait ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0, FIELD_PIC_BIDOOF_ASTONISHED
# 243 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1, FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_ActivateRockSwitch_1


ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger::
# 252 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 253 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2
ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1:
# 260 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_TRIGGER_3RD_MAP_SEEMS_NO_WAY
# 261 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2:
# 254 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0, FIELD_PIC_BIDOOF_NORMAL
# 255 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 256 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SeeNoWay
# 257 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 258 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1, FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1


# 265 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
Movement_SeeNoWay:
# 266 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 267 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 268 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 269 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 270 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 271 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Bidoof3::
# 275 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 276 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 277 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_2
# 294 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 2
	goto_if_eq ThirdInGameLocation_Bidoof3_3
ThirdInGameLocation_Bidoof3_1:
# 366 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_2:
# 278 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_0, FIELD_PIC_BIDOOF_UNEASY
# 279 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_1, FIELD_PIC_BIDOOF_NORMAL
# 280 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_2, FIELD_PIC_BIDOOF_ASTONISHED
# 281 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_3, FIELD_PIC_BIDOOF_NORMAL
# 282 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_4, FIELD_PIC_BIDOOF_ASTONISHED
# 283 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_5, FIELD_PIC_BIDOOF_NORMAL
# 284 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_6, FIELD_PIC_BIDOOF_ASTONISHED
# 285 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_7, FIELD_PIC_BIDOOF_NORMAL
# 286 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_8, FIELD_PIC_BIDOOF_UNEASY
# 287 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_9, FIELD_PIC_BIDOOF_NORMAL
# 288 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 289 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 290 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_3:
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_10, FIELD_PIC_BIDOOF_NORMAL, MSGBOX_YESNO
# 296 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_7
# 361 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_25, FIELD_PIC_BIDOOF_HAPPY
ThirdInGameLocation_Bidoof3_6:
# 363 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 364 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_1

ThirdInGameLocation_Bidoof3_7:
# 297 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 298 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_10
# 357 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_24, FIELD_PIC_BIDOOF_ASTONISHED
	goto ThirdInGameLocation_Bidoof3_6

ThirdInGameLocation_Bidoof3_10:
# 299 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_11, FIELD_PIC_BIDOOF_NORMAL
# 300 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_12, FIELD_PIC_BIDOOF_HAPPY
# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_13, FIELD_PIC_BIDOOF_SMIRKY
# 302 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 303 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 304 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 305 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ThirdInGameLocation_Bidoof3_14
# 312 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_Up
# 313 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 314 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_Up
# 315 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
ThirdInGameLocation_Bidoof3_13:
# 317 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_ToRockSmash
# 318 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_ToRockSmash
# 319 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 320 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PC_LOGIN
# 321 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_14
# 322 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_15
# 323 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 324 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 4
# 325 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 326 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 327 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 328 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 329 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject VAR_LAST_TALKED
# 330 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_ROCK_SMASH_3RD_LOC
# 331 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_16, FIELD_PIC_BIDOOF_HAPPY
# 332 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_17, FIELD_PIC_BIDOOF_NORMAL
# 333 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_18, FIELD_PIC_BIDOOF_ASTONISHED
# 334 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_19, FIELD_PIC_BIDOOF_NORMAL, MSGBOX_YESNO
# 335 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_18
ThirdInGameLocation_Bidoof3_17:
# 342 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_23, FIELD_PIC_BIDOOF_HAPPY
# 343 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 344 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_3
# 345 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 346 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 347 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 5
# 348 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 349 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative UpdateFollowingPokemon
# 350 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 351 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerDown
# 352 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 353 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_14:
# 306 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_East
# 307 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 308 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_East
# 309 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_13

ThirdInGameLocation_Bidoof3_18:
ThirdInGameLocation_Bidoof3_22:
# 337 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_20, FIELD_PIC_BIDOOF_ASTONISHED
# 338 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_21, FIELD_PIC_BIDOOF_NORMAL, MSGBOX_YESNO
# 339 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_22
# 340 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Bidoof3_Text_22, FIELD_PIC_BIDOOF_ASTONISHED
	goto ThirdInGameLocation_Bidoof3_17


# 370 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerDown:
# 371 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 372 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 375 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_ToRockSmash:
# 376 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 377 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 378 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 379 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 380 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 381 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 382 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 383 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 384 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 385 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 388 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_ToRockSmash:
# 389 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 390 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 391 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 392 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 393 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 394 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 395 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 396 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 397 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 398 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 401 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_East:
# 402 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 403 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 404 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 405 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 408 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_East:
# 409 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 410 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 413 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_Up:
# 414 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 415 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 416 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 417 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 420 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_Up:
# 421 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 422 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 425 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof3:
# 426 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 427 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_RockSmash::
# 431 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 432 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 433 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Underwater_RockSmash_2
# 437 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_1
ThirdInGameLocation_Underwater_RockSmash_1:
# 439 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_RockSmash_2:
# 434 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_0
	goto ThirdInGameLocation_Underwater_RockSmash_1


ThirdInGameLocation_Underwater_BidoffTrigger2::
# 444 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 445 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 446 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_2
# 447 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 3, MovementBidoof2
# 448 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 449 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 3
# 450 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 454 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof2:
# 455 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 456 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 457 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 458 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 459 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 460 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 461 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 462 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 463 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 464 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 465 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 466 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_BidoffTrigger1::
# 470 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 471 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 472 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_1
# 473 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 2, MovementBidoof1
# 474 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 475 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 2
# 476 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 480 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof1:
# 481 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 482 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 483 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 484 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 485 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 486 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 487 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 488 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 489 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_CreepyHexManiac::
# 493 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 494 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 495 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 496 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 497 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 498 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 499 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 500 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 501 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 502 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 503 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 504 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 505 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 507 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_set FLAG_BIDOOF_FOLLOWER, ThirdInGameLocation_Underwater_CreepyHexManiac_2
ThirdInGameLocation_Underwater_CreepyHexManiac_1:
# 511 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_CreepyHexManiac_2:
# 508 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 27
# 509 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_portrait ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0, FIELD_PIC_BIDOOF_ASTONISHED
	goto ThirdInGameLocation_Underwater_CreepyHexManiac_1


# 515 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 516 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 517 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 518 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 519 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 520 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 521 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 522 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 525 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 526 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 527 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 528 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 529 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 530 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 531 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 532 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 533 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

Script_BidoofHeal_Underwater_GotKOedByWild_Text_0:
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, {PLAYER}! Your Pokemon\n"
	.string "fainted!$"

Script_BidoofHeal_Underwater_GotKOedByWild_Text_1:
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll heal your Party, but you need to be\n"
	.string "more careful the next time!$"

ThirdInGameLocation_Underwater_EscapeTrigger_Text_0:
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Do you really want to leave, {PLAYER}?$"

ThirdInGameLocation_Underwater_EscapeTrigger_Text_1:
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, I'm really nervous about it!\pWelp!$"

ThirdInGameLocation_Underwater_EscapeTrigger_Text_2:
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You're right, let's prepare ourselves\n"
	.string "first!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_0:
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Do you wish to battle me?$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_1:
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Here I come!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_2:
# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Not yet! Come back when you're better\n"
	.string "prepeared.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_3:
# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You can't give up now, {PLAYER}!\p"
	.string "There must be some way to defeat him, I\n"
	.string "believe in you!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_4:
# 71 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Splendid!\p"
	.string "I admit my defeat. Please take this as a\n"
	.string "proof of overcoming this challenge.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_5:
# 72 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "{PLAYER} received the Suicune Badge.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_6:
# 76 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Wow! You're rocking it, {PLAYER}!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_7:
# 77 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
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
# 78 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, what!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_9:
# 79 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you are aware of the dangers,\n"
	.string "and know what you are doing.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_10:
# 80 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I have absolutely no idea what you're\n"
	.string "referring to!$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_11:
# 81 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll take that as a yes. That was my\n"
	.string "final warning. Proceed with caution.\p"
	.string "{PLAYER}.\p"
	.string "Bidoof.\p"
	.string "Au revoir.$"

ThirdInGameLocation_Underwater_SuicuneBattle_Text_12:
# 85 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
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
# 106 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly!$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_1:
# 107 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It is a pleasure to finally meet you,\n"
	.string "{PLAYER}!\p"
	.string "You too Bidoof, it has been a while\n"
	.string "since the last time.$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_2:
# 108 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Is this the legendary Suicune?!$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_3:
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
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
# 110 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, sounds scary!$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_5:
# 111 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "There is nothing scary about it, Bidoof.\n"
	.string "You and I both know this. In fact, if\l"
	.string "there is anything you should be scared\l"
	.string "about, it's triumphing over me and\l"
	.string "passing through that door.\p"
	.string "Nonetheless, I'll be waiting for you\n"
	.string "here. Whenever you feel ready, I'll take\l"
	.string "on your challenge.$"

ThirdInGameLocation_Underwater_SuicuneTrigger_Text_6:
# 112 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hmm, this looks different than what we\n"
	.string "have faced before! Be careful,\l"
	.string "{PLAYER}! It probably won't be as\l"
	.string "easy as that Hiker's battle.\p"
	.string "In any case, let's do our best!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_0:
# 146 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey, {PLAYER}! There's long grass\n"
	.string "ahead. Do you know what it means? Well,\l"
	.string "it means that it's dangerous to go\l"
	.string "there without a Pokemon!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_1:
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, don't give me that look! I'm too\n"
	.string "weak to handle all of these by my own!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_2:
# 148 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "But don't you worry, chum. I've got a\n"
	.string "plan!\p"
	.string "Listen carefully!\p"
	.string "I'll give you one of these Poke Balls,\n"
	.string "you'll use it to capture the wild\l"
	.string "Pokemon, and then we'll be able to cross\l"
	.string "the grass! Clever, isn't it?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_3:
# 149 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Uhm? Where did I get the Poke Ball from?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_4:
# 150 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Well, sometimes it's better not to know\n"
	.string "everything!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_5:
# 151 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "So, what do you say? Are you in?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_6:
# 152 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "What if it doesn't get caught?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_7:
# 153 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries! I've already taken that into\n"
	.string "account. Remember how we blended\l"
	.string "berries with Wingull? You actually got a\l"
	.string "{POKEBLOCK}, which can be fed to Pokemon!\l"
	.string "That'll make it easier to catch!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_8:
# 154 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright, let's go!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_9:
# 165 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Nicely done, {PLAYER}! You've just\n"
	.string "caught your very first Pokemon! I\l"
	.string "certainly hope it won't be your last!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_10:
# 166 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright {PLAYER}, I believe we can go\n"
	.string "into the long grass without worrying\l"
	.string "about wild Pokemon. Let's continue\l"
	.string "ahead.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_0:
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Y{PAUSE 15}-O{PAUSE 25}-U!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_1:
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Yes, you two! Do not be timid! Welcome in\n"
	.string "my domain - the forest!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_2:
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Forest? We're underwater...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_3:
# 199 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "YES! The trees are my servants, look at\n"
	.string "their majestic movements. Observe how\l"
	.string "they gracely dance with the wind!\n"
	.string "Yes, yes, do you hear them talking?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_4:
# 200 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Listen closely!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_5:
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "V2UncmUgcm9ja3MsIG5vdCB0cmVlcy\n4gV2UncmUgdW5kZXJ3YXRlciBhbmQg\lbm90IGluc2lkZSBhIGZvcmVzdC4gQW\l5kIHRoaXMgZ3V5IGlzIGEgZnUqKmluZy\lBtb3JvbiwgZG9uJ3QgbGlzdGVuIHRv\lIGhpbSB+IHNpbmNlcmVseSwgd\lGhlIHJvY2tzLg==$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_6:
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Aren't they magnificent?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_7:
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Psst! {PLAYER}!\p"
	.string "I don't think this person is going to\n"
	.string "help us much...\p"
	.string "Let's leave and go our way.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_8:
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I take good care of my servants.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0:
# 242 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly!\pI think you did something...$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1:
# 243 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's see what's changed.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2:
# 245 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It is already activated.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0:
# 254 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1:
# 258 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It seems the way is blocked\n"
	.string "by these rocks.\p"
	.string "I don't think I'll be able to smash these\n"
	.string "by myself. Let's try to find some other\l"
	.string "way to get past them.$"

ThirdInGameLocation_Bidoof3_Text_0:
# 278 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly...$"

ThirdInGameLocation_Bidoof3_Text_1:
# 279 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hi.$"

ThirdInGameLocation_Bidoof3_Text_2:
# 280 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I mean! You must be pretty surprised to\n"
	.string "see a Bidoof underwater! After all,\l"
	.string "ocean's depths are not my natural\l"
	.string "habitat.$"

ThirdInGameLocation_Bidoof3_Text_3:
# 281 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's weird, isn't it? Seeing a Bidoof\n"
	.string "here...A talking Bidoof at that!$"

ThirdInGameLocation_Bidoof3_Text_4:
# 282 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Though you don't look that\n"
	.string "surprised...Or you do? Golly, I can't\l"
	.string "tell!$"

ThirdInGameLocation_Bidoof3_Text_5:
# 283 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Sorry about earlier, running off like\n"
	.string "that. I was a bit scared when I saw you\l"
	.string "floating around there! But you seem\l"
	.string "like a nice chum.\p"
	.string "...\p"
	.string "We need to get out of here. I don't know\n"
	.string "if you're aware, but there is a rock down\l"
	.string "there blocking the way.$"

ThirdInGameLocation_Bidoof3_Text_6:
# 284 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, it's really weird how it's\n"
	.string "placed there, just like that. As if it\l"
	.string "was put on purpose...Though, I have to\l"
	.string "tell you, this whole place is so\l"
	.string "strange...\p"
	.string "It's not natural at all...Well, it doesn't\n"
	.string "matter that much I guess! We need to\l"
	.string "get out of here!$"

ThirdInGameLocation_Bidoof3_Text_7:
# 285 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "...$"

ThirdInGameLocation_Bidoof3_Text_8:
# 286 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "The problem is...I have no idea how! I\n"
	.string "tried to break the rock myself, but as\l"
	.string "you can clearly see, it didn't work.$"

ThirdInGameLocation_Bidoof3_Text_9:
# 287 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll rest a bit and try to think of a\n"
	.string "solution. In the meantime feel free to\l"
	.string "roam about, maybe you'll find something\l"
	.string "useful!$"

ThirdInGameLocation_Bidoof3_Text_10:
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey pal, did you find something?$"

ThirdInGameLocation_Bidoof3_Text_11:
# 299 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...Hidden machines...I know how these\n"
	.string "work!$"

ThirdInGameLocation_Bidoof3_Text_12:
# 300 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it just so happens that I can learn\n"
	.string "this move!$"

ThirdInGameLocation_Bidoof3_Text_13:
# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get some rocks broken!$"

ThirdInGameLocation_Bidoof3_Text_14:
# 321 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof learned {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_15:
# 322 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof used {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_16:
# 331 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it's done! We make quite the team,\n"
	.string "huh?$"

ThirdInGameLocation_Bidoof3_Text_17:
# 332 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, I think it'll be better if we\n"
	.string "hold together. At least, until we're out\l"
	.string "of here.$"

ThirdInGameLocation_Bidoof3_Text_18:
# 333 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Who knows whatever may loom here...$"

ThirdInGameLocation_Bidoof3_Text_19:
# 334 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you agree with me, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_20:
# 337 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, you can't be serious!\n$"

ThirdInGameLocation_Bidoof3_Text_21:
# 338 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get out of here together, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_22:
# 340 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, please do not joke like that!$"

ThirdInGameLocation_Bidoof3_Text_23:
# 342 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright! Take the lead, {PLAYER}. I'll\n"
	.string "be right behind you.$"

ThirdInGameLocation_Bidoof3_Text_24:
# 357 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! I'm not convinced...$"

ThirdInGameLocation_Bidoof3_Text_25:
# 361 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries! I'm sure we'll find some way\n"
	.string "out of here!$"

ThirdInGameLocation_Underwater_RockSmash_Text_0:
# 434 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\n"
	.string "Pokemon knowing the move {COLOR RED}Rock Smash{COLOR DARK_GRAY}\l"
	.string "could smash it.$"

ThirdInGameLocation_Underwater_RockSmash_Text_1:
# 437 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\nThere must be a way to smash it somehow...$"

ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0:
# 509 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! Did-did you see that???$"
