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


ThirdInGameLocation_Underwater_PsychicGuru::
# 15 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 16 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 17 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_PSYHIC_GURU_TALKED_WITH, ThirdInGameLocation_Underwater_PsychicGuru_2
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_10
ThirdInGameLocation_Underwater_PsychicGuru_1:
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_PsychicGuru_2:
# 18 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_0
# 19 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_1
# 20 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, 33, 107
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_2
# 22 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_3
# 24 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_4
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_5
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_6
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmessage
# 28 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 29 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 29
# 30 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_7
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_8
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_PsychicGuru_Text_9
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_PSYHIC_GURU_TALKED_WITH
	goto ThirdInGameLocation_Underwater_PsychicGuru_1


ThirdInGameLocation_Underwater_ActivateRockSwitch::
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 45 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_ActivateRockSwitch_2
# 77 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_3
ThirdInGameLocation_Underwater_ActivateRockSwitch_1:
# 79 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_ActivateRockSwitch_2:
# 46 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 47 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_F
# 49 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 50 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_E
# 51 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 52 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_D
# 53 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 54 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 55 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 56 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 59 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 61 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 62 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_CLICK
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 64 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_CAVE_DOOR_PUZZLE_DONE
# 65 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 72, 0x22E, FALSE
# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 71, 0x226, FALSE
# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 54, 75, 0x22F, TRUE
# 68 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	special DrawWholeMapView
# 69 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107
# 70 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0
# 71 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1
# 72 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 73 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107
# 74 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2
# 75 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_ActivateRockSwitch_1


ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger::
# 84 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 85 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2
ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1:
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_TRIGGER_3RD_MAP_SEEMS_NO_WAY
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2:
# 86 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 87 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0
# 88 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitbuttonpress
# 89 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 90 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SeeNoWay
# 92 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
	goto ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1


# 103 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
Movement_SeeNoWay:
# 104 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 106 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 107 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 108 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Bidoof3::
# 113 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 114 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 115 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_2
# 157 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 2
	goto_if_eq ThirdInGameLocation_Bidoof3_3
ThirdInGameLocation_Bidoof3_1:
# 259 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_2:
# 116 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, 33, 107, VAR_0x8009
# 117 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_0
# 118 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 119 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_1
# 121 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 122 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x800A
# 123 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_2
# 124 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 125 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 126 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_3
# 127 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 128 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 129 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_4
# 130 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 131 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 132 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_5
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_7
# 135 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 136 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 137 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_8
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_9
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 141 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 142 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8009
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_10
# 145 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 146 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_11
# 148 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 149 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x8009
# 150 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800A
# 151 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 152 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 153 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 154 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_3:
# 158 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 159 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_12, MSGBOX_YESNO
# 160 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_7
# 250 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 251 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 33, 107, VAR_0x800A
# 252 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_27
# 253 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
ThirdInGameLocation_Bidoof3_6:
# 255 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 256 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 257 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_1

ThirdInGameLocation_Bidoof3_7:
# 161 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 162 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_10
# 243 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 244 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x800A
# 245 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_26
# 246 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x800A
	goto ThirdInGameLocation_Bidoof3_6

ThirdInGameLocation_Bidoof3_10:
# 163 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_13
# 164 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 165 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 33, 107, VAR_0x800A
# 166 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_14
# 167 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 168 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_SMIRKY, 33, 107, VAR_0x800A
# 169 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_15
# 170 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_SMIRKY, VAR_0x800A
# 171 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 172 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 173 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 174 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ThirdInGameLocation_Bidoof3_14
# 181 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_Up
# 182 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 183 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_Up
# 184 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
ThirdInGameLocation_Bidoof3_13:
# 186 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_ToRockSmash
# 187 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_ToRockSmash
# 188 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PC_LOGIN
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_16
# 191 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_17
# 192 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 4
# 194 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 195 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject VAR_LAST_TALKED
# 199 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_ROCK_SMASH_3RD_LOC
# 200 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 33, 107, VAR_0x800A
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_18
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 204 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_19
# 205 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x800B
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_20
# 208 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 210 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_21, MSGBOX_YESNO
# 211 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_18
ThirdInGameLocation_Bidoof3_17:
# 225 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 226 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_25
# 227 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_3
# 228 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 229 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 230 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 5
# 231 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 232 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 233 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800B
# 234 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 235 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative UpdateFollowingPokemon
# 236 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 237 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerDown
# 238 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 239 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_14:
# 175 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_East
# 176 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 177 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_East
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_13

ThirdInGameLocation_Bidoof3_18:
ThirdInGameLocation_Bidoof3_22:
# 213 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 214 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 215 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_22
# 216 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 217 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 218 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_23, MSGBOX_YESNO
# 219 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_22
# 220 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 221 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 222 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_24
# 223 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
	goto ThirdInGameLocation_Bidoof3_17


# 263 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerDown:
# 264 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 265 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 268 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_ToRockSmash:
# 269 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 270 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 271 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 272 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 273 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 274 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 275 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 276 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 277 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 278 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 281 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_ToRockSmash:
# 282 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 283 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 284 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 285 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 286 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 287 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 288 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 289 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 290 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 294 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_East:
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 296 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 297 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 298 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_East:
# 302 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 303 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 306 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_Up:
# 307 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 308 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 309 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 310 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 313 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_Up:
# 314 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 315 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 318 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof3:
# 319 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 320 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_RockSmash::
# 324 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 325 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 326 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Underwater_RockSmash_2
# 330 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_1
ThirdInGameLocation_Underwater_RockSmash_1:
# 332 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_RockSmash_2:
# 327 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_0
	goto ThirdInGameLocation_Underwater_RockSmash_1


ThirdInGameLocation_Underwater_BidoffTrigger2::
# 337 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 338 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 339 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_2
# 340 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 3, MovementBidoof2
# 341 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 342 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 3
# 343 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 347 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof2:
# 348 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 349 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 350 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 351 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 352 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 353 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 354 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 355 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 356 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 357 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 358 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 359 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_BidoffTrigger1::
# 363 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 364 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 365 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_1
# 366 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 2, MovementBidoof1
# 367 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 368 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 2
# 369 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 373 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof1:
# 374 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 375 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 376 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 377 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 378 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 379 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 380 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 381 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 382 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_CreepyHexManiac::
# 386 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 387 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 388 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 389 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 390 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 391 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 392 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 393 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 394 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 395 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 396 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 397 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 398 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 400 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_set FLAG_BIDOOF_FOLLOWER, ThirdInGameLocation_Underwater_CreepyHexManiac_2
ThirdInGameLocation_Underwater_CreepyHexManiac_1:
# 406 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_CreepyHexManiac_2:
# 401 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 27
# 402 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107
# 403 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0
# 404 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
	goto ThirdInGameLocation_Underwater_CreepyHexManiac_1


# 410 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 411 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 412 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 413 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 414 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 415 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 416 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 417 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 420 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 421 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 422 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 423 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 424 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 425 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 426 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 427 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 428 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_PsychicGuru_Text_0:
# 18 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Y{PAUSE 15}-O{PAUSE 25}-U!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_1:
# 19 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Yes, you two! Do not be timid! Welcome in\n"
	.string "my domain - the forest!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_2:
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Forest? We're underwater...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_3:
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "YES! The trees are my servants, look at\n"
	.string "their majestic movements. Observe how\l"
	.string "they gracely dance with the wind!\n"
	.string "Yes, yes, do you hear them talking?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_4:
# 24 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Listen closely!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_5:
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "V2UncmUgcm9ja3MsIG5vdCB0cmVlcy\n4gV2UncmUgdW5kZXJ3YXRlciBhbmQg\lbm90IGluc2lkZSBhIGZvcmVzdC4gQW\l5kIHRoaXMgZ3V5IGlzIGEgZnUqKmluZy\lBtb3JvbiwgZG9uJ3QgbGlzdGVuIHRv\lIGhpbSB+IHNpbmNlcmVseSwgd\lGhlIHJvY2tzLg==$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_6:
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Aren't they magnificent?$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_7:
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Psst! {PLAYER}!$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_8:
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think this person is going to\n"
	.string "help us much...$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_9:
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's leave and go our way.$"

ThirdInGameLocation_Underwater_PsychicGuru_Text_10:
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I take good care of my servants.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0:
# 70 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly!$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1:
# 71 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I think you did something...$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2:
# 74 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's see what's changed.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_3:
# 77 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It is already activated.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0:
# 87 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1:
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It seems the way is blocked\nby these rocks.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2:
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think I'll be able to smash these\n"
	.string "by myself. Let's try to find some other\l"
	.string "way to get past them.$"

ThirdInGameLocation_Bidoof3_Text_0:
# 117 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly...$"

ThirdInGameLocation_Bidoof3_Text_1:
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hi.$"

ThirdInGameLocation_Bidoof3_Text_2:
# 123 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I mean! You must be pretty surprised to\n"
	.string "see a Bidoof underwater! After all,\l"
	.string "ocean's depths are not my natural\l"
	.string "habitat.$"

ThirdInGameLocation_Bidoof3_Text_3:
# 126 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's weird, isn't it? Seeing a Bidoof\n"
	.string "here...A talking Bidoof at that!$"

ThirdInGameLocation_Bidoof3_Text_4:
# 129 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Though you don't look that\n"
	.string "surprised...Or you do? Golly, I can't\l"
	.string "tell!$"

ThirdInGameLocation_Bidoof3_Text_5:
# 132 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Sorry about earlier, running off like\n"
	.string "that. I was a bit scared when I saw you\l"
	.string "floating around there! But you seem\l"
	.string "like a nice chum.$"

ThirdInGameLocation_Bidoof3_Text_6:
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "...$"

ThirdInGameLocation_Bidoof3_Text_7:
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "We need to get out of here. I don't know\n"
	.string "if you're aware, but there is a rock down\l"
	.string "there blocking the way.$"

ThirdInGameLocation_Bidoof3_Text_8:
# 137 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, it's really weird how it's\n"
	.string "placed there, just like that. As if it\l"
	.string "was put on purpose...Though, I have to\l"
	.string "tell you, this whole place is so\l"
	.string "strange...$"

ThirdInGameLocation_Bidoof3_Text_9:
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's not natural at all...Well, it doesn't\n"
	.string "matter that much I guess! We need to\l"
	.string "get out of here!$"

ThirdInGameLocation_Bidoof3_Text_10:
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "The problem is...I have no idea how! I\n"
	.string "tried to break the rock myself, but as\l"
	.string "you can clearly see, it didn't work.$"

ThirdInGameLocation_Bidoof3_Text_11:
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll rest a bit and try to think of a\n"
	.string "solution. In the meantime feel free to\l"
	.string "roam about, maybe you'll find something\l"
	.string "useful!$"

ThirdInGameLocation_Bidoof3_Text_12:
# 159 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey pal, did you find something?$"

ThirdInGameLocation_Bidoof3_Text_13:
# 163 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...Hidden machines...I know how these\n"
	.string "work!$"

ThirdInGameLocation_Bidoof3_Text_14:
# 166 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it just so happens that I can learn\n"
	.string "this move!$"

ThirdInGameLocation_Bidoof3_Text_15:
# 169 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get some rocks broken!$"

ThirdInGameLocation_Bidoof3_Text_16:
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof learned {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_17:
# 191 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof used {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_18:
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it's done! We make quite the team,\n"
	.string "huh?$"

ThirdInGameLocation_Bidoof3_Text_19:
# 204 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, I think it'll be better if we\n"
	.string "hold together. At least, until we're out\l"
	.string "of here.$"

ThirdInGameLocation_Bidoof3_Text_20:
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Who knows whatever may loom here...$"

ThirdInGameLocation_Bidoof3_Text_21:
# 210 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you agree with me, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_22:
# 215 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, you can't be serious!\n$"

ThirdInGameLocation_Bidoof3_Text_23:
# 218 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get out of here together, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_24:
# 222 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, please do not joke like that!$"

ThirdInGameLocation_Bidoof3_Text_25:
# 226 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright! Take the lead, {PLAYER}. I'll\n"
	.string "be right behind you.$"

ThirdInGameLocation_Bidoof3_Text_26:
# 245 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! I'm not convinced...$"

ThirdInGameLocation_Bidoof3_Text_27:
# 252 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries!$"

ThirdInGameLocation_Underwater_RockSmash_Text_0:
# 327 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\n"
	.string "Pokemon knowing the move {COLOR RED}Rock Smash{COLOR DARK_GRAY}\l"
	.string "could smash it.$"

ThirdInGameLocation_Underwater_RockSmash_Text_1:
# 330 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\nThere must be a way to smash it somehow...$"

ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0:
# 403 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! Did-did you see that???$"
