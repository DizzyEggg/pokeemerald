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


ThirdInGameLocation_Underwater_WildMonsSoon_Down::
# 15 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 16 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementJustFaceDown
# 17 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto ThirdInGameLocation_Underwater_WildMonsSoon
	return


ThirdInGameLocation_Underwater_WildMonsSoon_Left::
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 22 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementJustFaceLeft
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto ThirdInGameLocation_Underwater_WildMonsSoon
	return


ThirdInGameLocation_Underwater_WildMonsSoon::
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 28 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 7
# 29 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 30 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_0, VAR_0x8008
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x800A
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_1, VAR_0x800A
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_2, VAR_0x8008
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_3, VAR_0x8008
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_4, VAR_0x800A
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_WildMonsSoon_Text_5
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dynmultichoice 0, 5, TRUE, 1, 0, DYN_MULTICHOICE_CB_NONE, ThirdInGameLocation_Underwater_WildMonsSoon_Text_6
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_7, VAR_0x8008
# 40 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_8, VAR_0x8008
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 43 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerIntoGrass
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 46 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_SAFARI_MODE
# 47 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setbyte gNumSafariBalls, 1
# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setwildbattle SPECIES_CHINCHOU, 35
# 49 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dowildbattle
# 50 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	clearflag FLAG_SYS_SAFARI_MODE
# 51 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 33, 107, VAR_0x8009
# 52 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_9, VAR_0x8009
# 53 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 54 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox_pic ThirdInGameLocation_Underwater_WildMonsSoon_Text_10, VAR_0x8008
# 55 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 8
# 56 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x8009
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 62 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementJustFaceDown:
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 64 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementJustFaceLeft:
# 68 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_left
# 69 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 72 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerIntoGrass:
# 73 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 74 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 74 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 74 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 75 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_up_down
# 76 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_right_left
# 77 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_up_down
# 78 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_in_place_right_left
# 79 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_PsychicGuru::
# 83 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 84 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 85 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_PSYHIC_GURU_TALKED_WITH, ThirdInGameLocation_Underwater_PsychicGuru_2
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_10
ThirdInGameLocation_Underwater_PsychicGuru_1:
# 107 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_PsychicGuru_2:
# 86 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_0
# 87 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_1
# 88 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, 33, 107
# 89 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_2
# 90 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_3
# 92 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_4
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_5
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_6
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 29
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_7
# 100 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_8
# 101 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_9
# 102 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
# 103 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_PSYHIC_GURU_TALKED_WITH
	goto ThirdInGameLocation_Underwater_PsychicGuru_1


ThirdInGameLocation_Underwater_ActivateRockSwitch::
# 112 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 113 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_ActivateRockSwitch_2
# 146 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_3
ThirdInGameLocation_Underwater_ActivateRockSwitch_1:
# 148 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_ActivateRockSwitch_2:
# 114 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 115 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 116 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_F
# 117 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 118 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_E
# 119 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_D
# 121 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 122 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 123 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 124 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 125 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 126 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 127 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 128 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 129 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 130 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_CLICK
# 131 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 132 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_CAVE_DOOR_PUZZLE_DONE
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_WINGULL
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 72, 0x22E, FALSE
# 135 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 71, 0x226, FALSE
# 136 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 54, 75, 0x22F, TRUE
# 137 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	special DrawWholeMapView
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1
# 141 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 142 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_ActivateRockSwitch_1


ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger::
# 153 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 154 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2
ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1:
# 167 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_TRIGGER_3RD_MAP_SEEMS_NO_WAY
# 168 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2:
# 155 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 156 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0
# 157 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitbuttonpress
# 158 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 159 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 160 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SeeNoWay
# 161 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 162 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 163 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1
# 164 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2
# 165 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
	goto ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1


# 172 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
Movement_SeeNoWay:
# 173 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 174 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 175 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 176 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 177 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Bidoof3::
# 182 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 183 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 184 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_2
# 226 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 2
	goto_if_eq ThirdInGameLocation_Bidoof3_3
ThirdInGameLocation_Bidoof3_1:
# 328 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_2:
# 185 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, 33, 107, VAR_0x8009
# 186 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_0
# 187 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 188 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_1
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 191 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x800A
# 192 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_2
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 194 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 195 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_3
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_4
# 199 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 200 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_5
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_7
# 204 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 205 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_8
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_9
# 208 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 210 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 211 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 212 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8009
# 213 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_10
# 214 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 215 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 216 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_11
# 217 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 218 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x8009
# 219 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800A
# 220 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 221 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 222 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 223 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_3:
# 227 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 228 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_12, MSGBOX_YESNO
# 229 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_7
# 319 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 320 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 33, 107, VAR_0x800A
# 321 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_27
# 322 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
ThirdInGameLocation_Bidoof3_6:
# 324 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 325 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 326 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_1

ThirdInGameLocation_Bidoof3_7:
# 230 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 231 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_10
# 312 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 313 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x800A
# 314 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_26
# 315 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x800A
	goto ThirdInGameLocation_Bidoof3_6

ThirdInGameLocation_Bidoof3_10:
# 232 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_13
# 233 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 234 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 33, 107, VAR_0x800A
# 235 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_14
# 236 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 237 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_SMIRKY, 33, 107, VAR_0x800A
# 238 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_15
# 239 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_SMIRKY, VAR_0x800A
# 240 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 241 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 242 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 243 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ThirdInGameLocation_Bidoof3_14
# 250 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_Up
# 251 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 252 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_Up
# 253 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
ThirdInGameLocation_Bidoof3_13:
# 255 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_ToRockSmash
# 256 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_ToRockSmash
# 257 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 258 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PC_LOGIN
# 259 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_16
# 260 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_17
# 261 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 262 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 4
# 263 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 264 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 265 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 266 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 267 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject VAR_LAST_TALKED
# 268 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_ROCK_SMASH_3RD_LOC
# 269 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 33, 107, VAR_0x800A
# 270 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_18
# 271 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 272 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 273 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_19
# 274 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 275 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x800B
# 276 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_20
# 277 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 278 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 279 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_21, MSGBOX_YESNO
# 280 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_18
ThirdInGameLocation_Bidoof3_17:
# 294 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_25
# 296 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_3
# 297 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 298 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 299 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 5
# 300 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 302 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800B
# 303 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 304 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative UpdateFollowingPokemon
# 305 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 306 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerDown
# 307 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 308 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_14:
# 244 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_East
# 245 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 246 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_East
# 247 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_13

ThirdInGameLocation_Bidoof3_18:
ThirdInGameLocation_Bidoof3_22:
# 282 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 283 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 284 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_22
# 285 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 286 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 287 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_23, MSGBOX_YESNO
# 288 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_22
# 289 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 290 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_24
# 292 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
	goto ThirdInGameLocation_Bidoof3_17


# 332 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerDown:
# 333 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 334 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 337 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_ToRockSmash:
# 338 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 339 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 340 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 341 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 342 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 343 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 344 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 345 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 346 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 347 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 350 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_ToRockSmash:
# 351 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 352 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 353 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 354 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 355 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 356 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 357 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 358 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 359 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 360 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 363 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_East:
# 364 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 365 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 366 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 367 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 370 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_East:
# 371 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 372 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 375 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_Up:
# 376 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 377 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 378 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 379 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 382 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_Up:
# 383 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 384 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 387 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof3:
# 388 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 389 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_RockSmash::
# 393 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 394 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 395 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Underwater_RockSmash_2
# 399 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_1
ThirdInGameLocation_Underwater_RockSmash_1:
# 401 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_RockSmash_2:
# 396 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_0
	goto ThirdInGameLocation_Underwater_RockSmash_1


ThirdInGameLocation_Underwater_BidoffTrigger2::
# 406 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 407 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 408 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_2
# 409 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 3, MovementBidoof2
# 410 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 411 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 3
# 412 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 416 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof2:
# 417 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 418 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 419 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 420 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 421 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 422 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 423 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 424 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 425 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 426 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 427 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 428 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_BidoffTrigger1::
# 432 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 433 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 434 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_1
# 435 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 2, MovementBidoof1
# 436 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 437 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 2
# 438 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 442 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof1:
# 443 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 444 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 445 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 446 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 447 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 448 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 449 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 450 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 451 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_CreepyHexManiac::
# 455 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 456 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 457 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 458 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 459 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 460 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 461 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 462 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 463 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 464 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 465 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 466 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 467 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 469 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_set FLAG_BIDOOF_FOLLOWER, ThirdInGameLocation_Underwater_CreepyHexManiac_2
ThirdInGameLocation_Underwater_CreepyHexManiac_1:
# 475 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_CreepyHexManiac_2:
# 470 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 27
# 471 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107
# 472 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0
# 473 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
	goto ThirdInGameLocation_Underwater_CreepyHexManiac_1


# 479 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 480 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 481 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 482 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 483 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 484 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 485 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 486 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 489 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 490 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 491 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 492 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 493 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 494 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 495 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 496 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 497 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_WildMonsSoon_Text_0:
# 30 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey, {PLAYER}! There's long grass\n"
	.string "ahead. Do you know what it means? Well,\l"
	.string "it means that it's dangerous to go\l"
	.string "there without a Pokemon!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_1:
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, don't give me that look! I'm too\n"
	.string "weak to handle all of these by my own!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_2:
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "But don't you worry, chum. I've got a\n"
	.string "plan!\p"
	.string "Listen carefully!\p"
	.string "I'll give you one of these Poke Balls,\n"
	.string "you'll use it to capture the wild\l"
	.string "Pokemon, and then we'll be able to cross\l"
	.string "the grass! Clever, isn't it?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_3:
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Uhm? Where did I get the Poke Ball from?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_4:
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Well, sometimes it's better not to know\n"
	.string "everything!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_5:
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "So, what do you say? Are you in?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_6:
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "What if it doesn't get caught?$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_7:
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries! I've already taken that into\n"
	.string "account. Remember how we blended\l"
	.string "berries with Wingull? You actually got a\l"
	.string "{POKEBLOCK}, which can be fed to Pokemon!\l"
	.string "That'll make it easier to catch!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_8:
# 40 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright, let's go!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_9:
# 52 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Nicely done, {PLAYER}! You've just\n"
	.string "caught your very first Pokemon! I\l"
	.string "certainly hope it won't be your last!$"

ThirdInGameLocation_Underwater_WildMonsSoon_Text_10:
# 54 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright {PLAYER}, I believe we can go\n"
	.string "into the long grass without worrying\l"
	.string "about wild Pokemon. Let's continue\l"
	.string "ahead.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_0:
# 86 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Y{PAUSE 15}-O{PAUSE 25}-U!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_1:
# 87 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Yes, you two! Do not be timid! Welcome in\n"
	.string "my domain - the forest!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_2:
# 89 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Forest? We're underwater...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_3:
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "YES! The trees are my servants, look at\n"
	.string "their majestic movements. Observe how\l"
	.string "they gracely dance with the wind!\n"
	.string "Yes, yes, do you hear them talking?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_4:
# 92 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Listen closely!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_5:
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "V2UncmUgcm9ja3MsIG5vdCB0cmVlcy\n4gV2UncmUgdW5kZXJ3YXRlciBhbmQg\lbm90IGluc2lkZSBhIGZvcmVzdC4gQW\l5kIHRoaXMgZ3V5IGlzIGEgZnUqKmluZy\lBtb3JvbiwgZG9uJ3QgbGlzdGVuIHRv\lIGhpbSB+IHNpbmNlcmVseSwgd\lGhlIHJvY2tzLg==$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_6:
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Aren't they magnificent?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_7:
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Psst! {PLAYER}!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_8:
# 100 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think this person is going to\n"
	.string "help us much...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_9:
# 101 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's leave and go our way.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_10:
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I take good care of my servants.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0:
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly!$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1:
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I think you did something...$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2:
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's see what's changed.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_3:
# 146 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It is already activated.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0:
# 156 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1:
# 163 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It seems the way is blocked\nby these rocks.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2:
# 164 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think I'll be able to smash these\n"
	.string "by myself. Let's try to find some other\l"
	.string "way to get past them.$"

ThirdInGameLocation_Bidoof3_Text_0:
# 186 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly...$"

ThirdInGameLocation_Bidoof3_Text_1:
# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hi.$"

ThirdInGameLocation_Bidoof3_Text_2:
# 192 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I mean! You must be pretty surprised to\n"
	.string "see a Bidoof underwater! After all,\l"
	.string "ocean's depths are not my natural\l"
	.string "habitat.$"

ThirdInGameLocation_Bidoof3_Text_3:
# 195 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's weird, isn't it? Seeing a Bidoof\n"
	.string "here...A talking Bidoof at that!$"

ThirdInGameLocation_Bidoof3_Text_4:
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Though you don't look that\n"
	.string "surprised...Or you do? Golly, I can't\l"
	.string "tell!$"

ThirdInGameLocation_Bidoof3_Text_5:
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Sorry about earlier, running off like\n"
	.string "that. I was a bit scared when I saw you\l"
	.string "floating around there! But you seem\l"
	.string "like a nice chum.$"

ThirdInGameLocation_Bidoof3_Text_6:
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "...$"

ThirdInGameLocation_Bidoof3_Text_7:
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "We need to get out of here. I don't know\n"
	.string "if you're aware, but there is a rock down\l"
	.string "there blocking the way.$"

ThirdInGameLocation_Bidoof3_Text_8:
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, it's really weird how it's\n"
	.string "placed there, just like that. As if it\l"
	.string "was put on purpose...Though, I have to\l"
	.string "tell you, this whole place is so\l"
	.string "strange...$"

ThirdInGameLocation_Bidoof3_Text_9:
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's not natural at all...Well, it doesn't\n"
	.string "matter that much I guess! We need to\l"
	.string "get out of here!$"

ThirdInGameLocation_Bidoof3_Text_10:
# 213 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "The problem is...I have no idea how! I\n"
	.string "tried to break the rock myself, but as\l"
	.string "you can clearly see, it didn't work.$"

ThirdInGameLocation_Bidoof3_Text_11:
# 216 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll rest a bit and try to think of a\n"
	.string "solution. In the meantime feel free to\l"
	.string "roam about, maybe you'll find something\l"
	.string "useful!$"

ThirdInGameLocation_Bidoof3_Text_12:
# 228 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey pal, did you find something?$"

ThirdInGameLocation_Bidoof3_Text_13:
# 232 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...Hidden machines...I know how these\n"
	.string "work!$"

ThirdInGameLocation_Bidoof3_Text_14:
# 235 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it just so happens that I can learn\n"
	.string "this move!$"

ThirdInGameLocation_Bidoof3_Text_15:
# 238 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get some rocks broken!$"

ThirdInGameLocation_Bidoof3_Text_16:
# 259 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof learned {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_17:
# 260 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof used {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_18:
# 270 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it's done! We make quite the team,\n"
	.string "huh?$"

ThirdInGameLocation_Bidoof3_Text_19:
# 273 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, I think it'll be better if we\n"
	.string "hold together. At least, until we're out\l"
	.string "of here.$"

ThirdInGameLocation_Bidoof3_Text_20:
# 276 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Who knows whatever may loom here...$"

ThirdInGameLocation_Bidoof3_Text_21:
# 279 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you agree with me, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_22:
# 284 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, you can't be serious!\n$"

ThirdInGameLocation_Bidoof3_Text_23:
# 287 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get out of here together, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_24:
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, please do not joke like that!$"

ThirdInGameLocation_Bidoof3_Text_25:
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright! Take the lead, {PLAYER}. I'll\n"
	.string "be right behind you.$"

ThirdInGameLocation_Bidoof3_Text_26:
# 314 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! I'm not convinced...$"

ThirdInGameLocation_Bidoof3_Text_27:
# 321 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries!$"

ThirdInGameLocation_Underwater_RockSmash_Text_0:
# 396 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\n"
	.string "Pokemon knowing the move {COLOR RED}Rock Smash{COLOR DARK_GRAY}\l"
	.string "could smash it.$"

ThirdInGameLocation_Underwater_RockSmash_Text_1:
# 399 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\nThere must be a way to smash it somehow...$"

ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0:
# 472 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! Did-did you see that???$"
