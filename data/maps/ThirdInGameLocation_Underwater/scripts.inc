ThirdInGameLocation_Underwater_MapScripts::
# 3 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_LOAD
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


ThirdInGameLocation_Underwater_SuicuneTrigger::
	return


ThirdInGameLocation_Underwater_WildMonsSoon_Down::
# 19 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 20 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementJustFaceDown
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto ThirdInGameLocation_Underwater_WildMonsSoon
	return


ThirdInGameLocation_Underwater_WildMonsSoon_Left::
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementJustFaceLeft
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto ThirdInGameLocation_Underwater_WildMonsSoon
	return


ThirdInGameLocation_Underwater_WildMonsSoon::
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 7
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_0, VAR_0x8008
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_1, VAR_0x800A
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_2, VAR_0x8008
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_3, VAR_0x8008
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_4, VAR_0x800A
# 40 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_WildMonsSoon_Text_5
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dynmultichoice 0, 5, TRUE, 1, 0, DYN_MULTICHOICE_CB_NONE, ThirdInGameLocation_Underwater_WildMonsSoon_Text_6
# 43 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_7, VAR_0x8008
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_8, VAR_0x8008
# 45 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 46 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 47 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerIntoGrass
# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 50 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_SAFARI_MODE
# 51 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setbyte gNumSafariBalls, 1
# 52 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setwildbattle SPECIES_CHINCHOU, 35
# 53 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dowildbattle
# 54 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	clearflag FLAG_SYS_SAFARI_MODE
# 55 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8009
# 56 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_9, VAR_0x8009
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_10, VAR_0x8008
# 59 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 8
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x8009
# 61 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 62 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementJustFaceDown:
# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 68 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 71 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementJustFaceLeft:
# 72 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_left
# 73 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 76 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerIntoGrass:
# 77 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 78 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 78 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 78 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 79 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_up_down
# 80 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_right_left
# 81 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_up_down
# 82 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_right_left
# 83 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_PsychicGuru::
# 87 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 88 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 89 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_PSYHIC_GURU_TALKED_WITH, ThirdInGameLocation_Underwater_PsychicGuru_2
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_10
ThirdInGameLocation_Underwater_PsychicGuru_1:
# 111 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_PsychicGuru_2:
# 90 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_0
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_1
# 92 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_2
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_3
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_4
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_5
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_6
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 100 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 101 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 29
# 102 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 103 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_7
# 104 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_8
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_9
# 106 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
# 107 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_PSYHIC_GURU_TALKED_WITH
	goto ThirdInGameLocation_Underwater_PsychicGuru_1


ThirdInGameLocation_Underwater_ActivateRockSwitch::
# 116 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 117 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_ActivateRockSwitch_2
# 150 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_3
ThirdInGameLocation_Underwater_ActivateRockSwitch_1:
# 152 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_ActivateRockSwitch_2:
# 118 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 119 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_F
# 121 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 122 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_E
# 123 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 124 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_D
# 125 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 126 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 127 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 128 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 129 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 130 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 131 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 132 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_CLICK
# 135 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 136 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_CAVE_DOOR_PUZZLE_DONE
# 137 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_WINGULL
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 72, 0x22E, FALSE
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 71, 0x226, FALSE
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 54, 75, 0x22F, TRUE
# 141 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	special DrawWholeMapView
# 142 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1
# 145 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 146 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2
# 148 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_ActivateRockSwitch_1


ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger::
# 157 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 158 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2
ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1:
# 171 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_TRIGGER_3RD_MAP_SEEMS_NO_WAY
# 172 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2:
# 159 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 160 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0
# 161 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitbuttonpress
# 162 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 163 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 164 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SeeNoWay
# 165 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 166 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 167 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1
# 168 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2
# 169 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
	goto ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1


# 176 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
Movement_SeeNoWay:
# 177 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 179 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 180 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 181 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 182 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Bidoof3::
# 186 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 187 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 188 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_2
# 230 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 2
	goto_if_eq ThirdInGameLocation_Bidoof3_3
ThirdInGameLocation_Bidoof3_1:
# 332 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_2:
# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8009
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_0
# 191 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 192 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_1
# 194 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 195 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_2
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 199 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_3
# 200 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_4
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 204 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 205 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_5
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_7
# 208 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 210 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_8
# 211 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_9
# 212 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 213 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 214 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 215 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 216 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8009
# 217 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_10
# 218 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 219 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 220 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_11
# 221 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 222 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x8009
# 223 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800A
# 224 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 225 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 226 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 227 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_3:
# 231 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 232 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_12, MSGBOX_YESNO
# 233 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_7
# 323 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 324 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 325 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_27
# 326 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
ThirdInGameLocation_Bidoof3_6:
# 328 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 329 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 330 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_1

ThirdInGameLocation_Bidoof3_7:
# 234 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 235 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_10
# 316 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 317 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 318 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_26
# 319 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x800A
	goto ThirdInGameLocation_Bidoof3_6

ThirdInGameLocation_Bidoof3_10:
# 236 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_13
# 237 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 238 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 239 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_14
# 240 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 241 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_SMIRKY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 242 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_15
# 243 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_SMIRKY, VAR_0x800A
# 244 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 245 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 246 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 247 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ThirdInGameLocation_Bidoof3_14
# 254 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_Up
# 255 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 256 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_Up
# 257 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
ThirdInGameLocation_Bidoof3_13:
# 259 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_ToRockSmash
# 260 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_ToRockSmash
# 261 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 262 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PC_LOGIN
# 263 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_16
# 264 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_17
# 265 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 266 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 4
# 267 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 268 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 269 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 270 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 271 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject VAR_LAST_TALKED
# 272 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_ROCK_SMASH_3RD_LOC
# 273 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 274 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_18
# 275 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 276 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 277 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_19
# 278 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 279 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800B
# 280 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_20
# 281 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 282 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 283 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_21, MSGBOX_YESNO
# 284 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_18
ThirdInGameLocation_Bidoof3_17:
# 298 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 299 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_25
# 300 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_3
# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 302 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 303 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 5
# 304 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 305 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 306 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800B
# 307 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 308 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative UpdateFollowingPokemon
# 309 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 310 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerDown
# 311 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 312 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_14:
# 248 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_East
# 249 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 250 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_East
# 251 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_13

ThirdInGameLocation_Bidoof3_18:
ThirdInGameLocation_Bidoof3_22:
# 286 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 287 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 288 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_22
# 289 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 290 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_23, MSGBOX_YESNO
# 292 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_22
# 293 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 294 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_24
# 296 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
	goto ThirdInGameLocation_Bidoof3_17


# 336 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerDown:
# 337 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 338 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 341 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_ToRockSmash:
# 342 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 343 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 344 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 345 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 346 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 347 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 348 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 349 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 350 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 351 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 354 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_ToRockSmash:
# 355 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 356 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 357 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 358 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 359 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 360 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 361 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 362 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 363 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 364 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 367 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_East:
# 368 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 369 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 370 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 371 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 374 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_East:
# 375 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 376 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 379 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_Up:
# 380 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 381 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 382 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 383 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 386 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_Up:
# 387 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 388 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 391 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof3:
# 392 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 393 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_RockSmash::
# 397 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 398 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 399 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Underwater_RockSmash_2
# 403 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_1
ThirdInGameLocation_Underwater_RockSmash_1:
# 405 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_RockSmash_2:
# 400 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_0
	goto ThirdInGameLocation_Underwater_RockSmash_1


ThirdInGameLocation_Underwater_BidoffTrigger2::
# 410 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 411 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 412 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_2
# 413 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 3, MovementBidoof2
# 414 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 415 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 3
# 416 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 420 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof2:
# 421 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 422 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 423 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 424 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 425 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 426 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 427 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 428 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 429 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 430 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 431 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 432 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_BidoffTrigger1::
# 436 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 437 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 438 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_1
# 439 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 2, MovementBidoof1
# 440 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 441 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 2
# 442 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 446 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof1:
# 447 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 448 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 449 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 450 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 451 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 452 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 453 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 454 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 455 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_CreepyHexManiac::
# 459 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 460 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 461 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 462 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 463 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 464 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 465 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 466 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 467 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 468 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 469 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 470 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 471 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 473 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_set FLAG_BIDOOF_FOLLOWER, ThirdInGameLocation_Underwater_CreepyHexManiac_2
ThirdInGameLocation_Underwater_CreepyHexManiac_1:
# 479 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_CreepyHexManiac_2:
# 474 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 27
# 475 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 476 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0
# 477 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
	goto ThirdInGameLocation_Underwater_CreepyHexManiac_1


# 483 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 484 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 485 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 486 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 487 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 488 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 489 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 490 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 493 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 494 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 495 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 496 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 497 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 498 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 499 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 500 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 501 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_WildMonsSoon_Text_0:
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey, {PLAYER}! There's long grass\n"
	.string "ahead. Do you know what it means? Well,\l"
	.string "it means that it's dangerous to go\l"
	.string "there without a Pokemon!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_1:
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, don't give me that look! I'm too\n"
	.string "weak to handle all of these by my own!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_2:
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "But don't you worry, chum. I've got a\n"
	.string "plan!\p"
	.string "Listen carefully!\p"
	.string "I'll give you one of these Poke Balls,\n"
	.string "you'll use it to capture the wild\l"
	.string "Pokemon, and then we'll be able to cross\l"
	.string "the grass! Clever, isn't it?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_3:
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Uhm? Where did I get the Poke Ball from?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_4:
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Well, sometimes it's better not to know\n"
	.string "everything!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_5:
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "So, what do you say? Are you in?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_6:
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "What if it doesn't get caught?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_7:
# 43 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries! I've already taken that into\n"
	.string "account. Remember how we blended\l"
	.string "berries with Wingull? You actually got a\l"
	.string "{POKEBLOCK}, which can be fed to Pokemon!\l"
	.string "That'll make it easier to catch!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_8:
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright, let's go!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_9:
# 56 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Nicely done, {PLAYER}! You've just\n"
	.string "caught your very first Pokemon! I\l"
	.string "certainly hope it won't be your last!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_10:
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright {PLAYER}, I believe we can go\n"
	.string "into the long grass without worrying\l"
	.string "about wild Pokemon. Let's continue\l"
	.string "ahead.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_0:
# 90 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Y{PAUSE 15}-O{PAUSE 25}-U!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_1:
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Yes, you two! Do not be timid! Welcome in\n"
	.string "my domain - the forest!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_2:
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Forest? We're underwater...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_3:
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "YES! The trees are my servants, look at\n"
	.string "their majestic movements. Observe how\l"
	.string "they gracely dance with the wind!\n"
	.string "Yes, yes, do you hear them talking?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_4:
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Listen closely!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_5:
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "V2UncmUgcm9ja3MsIG5vdCB0cmVlcy\n4gV2UncmUgdW5kZXJ3YXRlciBhbmQg\lbm90IGluc2lkZSBhIGZvcmVzdC4gQW\l5kIHRoaXMgZ3V5IGlzIGEgZnUqKmluZy\lBtb3JvbiwgZG9uJ3QgbGlzdGVuIHRv\lIGhpbSB+IHNpbmNlcmVseSwgd\lGhlIHJvY2tzLg==$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_6:
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Aren't they magnificent?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_7:
# 103 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Psst! {PLAYER}!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_8:
# 104 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think this person is going to\n"
	.string "help us much...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_9:
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's leave and go our way.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_10:
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I take good care of my servants.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0:
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly!$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1:
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I think you did something...$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2:
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's see what's changed.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_3:
# 150 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It is already activated.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0:
# 160 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1:
# 167 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It seems the way is blocked\nby these rocks.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2:
# 168 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think I'll be able to smash these\n"
	.string "by myself. Let's try to find some other\l"
	.string "way to get past them.$"

ThirdInGameLocation_Bidoof3_Text_0:
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly...$"

ThirdInGameLocation_Bidoof3_Text_1:
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hi.$"

ThirdInGameLocation_Bidoof3_Text_2:
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I mean! You must be pretty surprised to\n"
	.string "see a Bidoof underwater! After all,\l"
	.string "ocean's depths are not my natural\l"
	.string "habitat.$"

ThirdInGameLocation_Bidoof3_Text_3:
# 199 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's weird, isn't it? Seeing a Bidoof\n"
	.string "here...A talking Bidoof at that!$"

ThirdInGameLocation_Bidoof3_Text_4:
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Though you don't look that\n"
	.string "surprised...Or you do? Golly, I can't\l"
	.string "tell!$"

ThirdInGameLocation_Bidoof3_Text_5:
# 205 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Sorry about earlier, running off like\n"
	.string "that. I was a bit scared when I saw you\l"
	.string "floating around there! But you seem\l"
	.string "like a nice chum.$"

ThirdInGameLocation_Bidoof3_Text_6:
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "...$"

ThirdInGameLocation_Bidoof3_Text_7:
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "We need to get out of here. I don't know\n"
	.string "if you're aware, but there is a rock down\l"
	.string "there blocking the way.$"

ThirdInGameLocation_Bidoof3_Text_8:
# 210 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, it's really weird how it's\n"
	.string "placed there, just like that. As if it\l"
	.string "was put on purpose...Though, I have to\l"
	.string "tell you, this whole place is so\l"
	.string "strange...$"

ThirdInGameLocation_Bidoof3_Text_9:
# 211 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's not natural at all...Well, it doesn't\n"
	.string "matter that much I guess! We need to\l"
	.string "get out of here!$"

ThirdInGameLocation_Bidoof3_Text_10:
# 217 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "The problem is...I have no idea how! I\n"
	.string "tried to break the rock myself, but as\l"
	.string "you can clearly see, it didn't work.$"

ThirdInGameLocation_Bidoof3_Text_11:
# 220 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll rest a bit and try to think of a\n"
	.string "solution. In the meantime feel free to\l"
	.string "roam about, maybe you'll find something\l"
	.string "useful!$"

ThirdInGameLocation_Bidoof3_Text_12:
# 232 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey pal, did you find something?$"

ThirdInGameLocation_Bidoof3_Text_13:
# 236 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...Hidden machines...I know how these\n"
	.string "work!$"

ThirdInGameLocation_Bidoof3_Text_14:
# 239 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it just so happens that I can learn\n"
	.string "this move!$"

ThirdInGameLocation_Bidoof3_Text_15:
# 242 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get some rocks broken!$"

ThirdInGameLocation_Bidoof3_Text_16:
# 263 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof learned {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_17:
# 264 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof used {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_18:
# 274 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it's done! We make quite the team,\n"
	.string "huh?$"

ThirdInGameLocation_Bidoof3_Text_19:
# 277 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, I think it'll be better if we\n"
	.string "hold together. At least, until we're out\l"
	.string "of here.$"

ThirdInGameLocation_Bidoof3_Text_20:
# 280 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Who knows whatever may loom here...$"

ThirdInGameLocation_Bidoof3_Text_21:
# 283 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you agree with me, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_22:
# 288 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, you can't be serious!\n$"

ThirdInGameLocation_Bidoof3_Text_23:
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get out of here together, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_24:
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, please do not joke like that!$"

ThirdInGameLocation_Bidoof3_Text_25:
# 299 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright! Take the lead, {PLAYER}. I'll\n"
	.string "be right behind you.$"

ThirdInGameLocation_Bidoof3_Text_26:
# 318 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! I'm not convinced...$"

ThirdInGameLocation_Bidoof3_Text_27:
# 325 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries!$"

ThirdInGameLocation_Underwater_RockSmash_Text_0:
# 400 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\n"
	.string "Pokemon knowing the move {COLOR RED}Rock Smash{COLOR DARK_GRAY}\l"
	.string "could smash it.$"

ThirdInGameLocation_Underwater_RockSmash_Text_1:
# 403 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\nThere must be a way to smash it somehow...$"

ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0:
# 476 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! Did-did you see that???$"
