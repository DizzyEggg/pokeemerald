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


ThirdInGameLocation_Underwater_ActivateRockSwitch::
# 15 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 16 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_ActivateRockSwitch_2
# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_3
ThirdInGameLocation_Underwater_ActivateRockSwitch_1:
# 50 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_ActivateRockSwitch_2:
# 17 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 18 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 19 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_F
# 20 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_E
# 22 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_D
# 24 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 28 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 29 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_G
# 30 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_NOTE_C
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_CLICK
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitse
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_CAVE_DOOR_PUZZLE_DONE
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 72, 0x22E, TRUE
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 32, 71, 0x226, TRUE
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setmetatile 54, 75, 0x22F, TRUE
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	special DrawWholeMapView
# 40 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1
# 43 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 78, 107
# 45 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2
# 46 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
	goto ThirdInGameLocation_Underwater_ActivateRockSwitch_1


ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger::
# 55 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 56 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_unset FLAG_CAVE_DOOR_PUZZLE_DONE, ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2
ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1:
# 69 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_TRIGGER_3RD_MAP_SEEMS_NO_WAY
# 70 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_2:
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 78, 107, VAR_0x8008
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0
# 59 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitbuttonpress
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 61 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 62 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SeeNoWay
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 64 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 65 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1
# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2
# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
	goto ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_1


# 74 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
Movement_SeeNoWay:
# 75 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 76 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 77 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 78 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 79 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 80 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Bidoof3::
# 84 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 85 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 86 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_2
# 128 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 2
	goto_if_eq ThirdInGameLocation_Bidoof3_3
ThirdInGameLocation_Bidoof3_1:
# 230 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_2:
# 87 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, 78, 107, VAR_0x8009
# 88 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_0
# 89 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 90 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 78, 107, VAR_0x8008
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_1
# 92 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107, VAR_0x800A
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_2
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_3
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 100 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_4
# 101 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 102 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 103 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_5
# 104 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_7
# 106 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 107 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 108 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_8
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_9
# 110 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 111 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 112 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 113 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 114 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8009
# 115 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_10
# 116 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 117 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 118 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_11
# 119 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x8009
# 121 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800A
# 122 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 123 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 124 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 125 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_3:
# 129 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 78, 107, VAR_0x8008
# 130 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_12, MSGBOX_YESNO
# 131 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_7
# 221 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 222 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 78, 107, VAR_0x800A
# 223 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_27
# 224 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
ThirdInGameLocation_Bidoof3_6:
# 226 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 227 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 228 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_1

ThirdInGameLocation_Bidoof3_7:
# 132 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_10
# 214 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 215 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107, VAR_0x800A
# 216 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_26
# 217 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x800A
	goto ThirdInGameLocation_Bidoof3_6

ThirdInGameLocation_Bidoof3_10:
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_13
# 135 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 136 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 78, 107, VAR_0x800A
# 137 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_14
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_SMIRKY, 78, 107, VAR_0x800A
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_15
# 141 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_SMIRKY, VAR_0x800A
# 142 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 145 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ThirdInGameLocation_Bidoof3_14
# 152 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_Up
# 153 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 154 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_Up
# 155 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
ThirdInGameLocation_Bidoof3_13:
# 157 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_ToRockSmash
# 158 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_ToRockSmash
# 159 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 160 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PC_LOGIN
# 161 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_16
# 162 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_17
# 163 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 164 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 4
# 165 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 166 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 167 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 168 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 169 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject VAR_LAST_TALKED
# 170 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_ROCK_SMASH_3RD_LOC
# 171 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 78, 107, VAR_0x800A
# 172 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_18
# 173 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 174 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 175 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_19
# 176 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 177 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107, VAR_0x800B
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_20
# 179 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 180 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 181 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_21, MSGBOX_YESNO
# 182 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_18
ThirdInGameLocation_Bidoof3_17:
# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_25
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_3
# 199 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 200 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 5
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 204 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800B
# 205 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 206 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative UpdateFollowingPokemon
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 2
# 208 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerDown
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 210 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_14:
# 146 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_East
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 148 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_East
# 149 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_13

ThirdInGameLocation_Bidoof3_18:
ThirdInGameLocation_Bidoof3_22:
# 184 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 185 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 186 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_22
# 187 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 188 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_23, MSGBOX_YESNO
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_22
# 191 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 192 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_24
# 194 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
	goto ThirdInGameLocation_Bidoof3_17


# 234 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayerDown:
# 235 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 236 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 239 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_ToRockSmash:
# 240 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 241 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 242 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 243 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 244 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 245 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 246 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 247 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 248 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 249 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 252 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_ToRockSmash:
# 253 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 254 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 255 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 256 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 257 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 258 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 259 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 260 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 261 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 262 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 265 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_East:
# 266 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 267 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 268 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 269 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 272 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_East:
# 273 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 274 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 277 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_Up:
# 278 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 279 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 280 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 281 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 284 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_Up:
# 285 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 286 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 289 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof3:
# 290 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_RockSmash::
# 295 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 296 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 297 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Underwater_RockSmash_2
# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_1
ThirdInGameLocation_Underwater_RockSmash_1:
# 303 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_RockSmash_2:
# 298 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_0
	goto ThirdInGameLocation_Underwater_RockSmash_1


ThirdInGameLocation_Underwater_BidoffTrigger2::
# 308 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 309 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 310 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_2
# 311 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 3, MovementBidoof2
# 312 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 313 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 3
# 314 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 318 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof2:
# 319 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 320 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 321 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 322 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 323 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 324 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 325 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 326 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 327 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 328 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 329 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 330 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_BidoffTrigger1::
# 334 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 335 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 336 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_1
# 337 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 2, MovementBidoof1
# 338 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 339 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 2
# 340 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 344 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof1:
# 345 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 346 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 347 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 348 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 349 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 350 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 351 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 352 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 353 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_CreepyHexManiac::
# 357 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 358 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 359 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 360 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 361 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 362 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 363 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 364 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 365 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 366 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 367 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 368 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 369 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 371 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	goto_if_set FLAG_BIDOOF_FOLLOWER, ThirdInGameLocation_Underwater_CreepyHexManiac_2
ThirdInGameLocation_Underwater_CreepyHexManiac_1:
# 377 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_CreepyHexManiac_2:
# 372 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay 27
# 373 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107
# 374 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0
# 375 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
	goto ThirdInGameLocation_Underwater_CreepyHexManiac_1


# 381 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 382 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 383 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 384 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 385 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 386 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 387 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 388 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 391 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 392 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 393 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 394 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 395 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 396 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 397 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 398 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 399 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_0:
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly!$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_1:
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I think you did something...$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_2:
# 45 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's see what's changed.$"

ThirdInGameLocation_Underwater_ActivateRockSwitch_Text_3:
# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It is already activated.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_0:
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_1:
# 65 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It seems the way is blocked\nby these rocks.$"

ThirdInGameLocation_Underwater_SeemsTheWayIsBlockedTrigger_Text_2:
# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I don't think I'll be able to smash these\n"
	.string "by myself. Let's try to find some other\l"
	.string "way to get past them.$"

ThirdInGameLocation_Bidoof3_Text_0:
# 88 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly...$"

ThirdInGameLocation_Bidoof3_Text_1:
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hi.$"

ThirdInGameLocation_Bidoof3_Text_2:
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I mean! You must be pretty surprised to\n"
	.string "see a Bidoof underwater! After all,\l"
	.string "ocean's depths are not my natural\l"
	.string "habitat.$"

ThirdInGameLocation_Bidoof3_Text_3:
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's weird, isn't it? Seeing a Bidoof\n"
	.string "here...A talking Bidoof at that!$"

ThirdInGameLocation_Bidoof3_Text_4:
# 100 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Though you don't look that\n"
	.string "surprised...Or you do? Golly, I can't\l"
	.string "tell!$"

ThirdInGameLocation_Bidoof3_Text_5:
# 103 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Sorry about earlier, running off like\n"
	.string "that. I was a bit scared when I saw you\l"
	.string "floating around there! But you seem\l"
	.string "like a nice chum.$"

ThirdInGameLocation_Bidoof3_Text_6:
# 104 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "...$"

ThirdInGameLocation_Bidoof3_Text_7:
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "We need to get out of here. I don't know\n"
	.string "if you're aware, but there is a rock down\l"
	.string "there blocking the way.$"

ThirdInGameLocation_Bidoof3_Text_8:
# 108 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, it's really weird how it's\n"
	.string "placed there, just like that. As if it\l"
	.string "was put on purpose...Though, I have to\l"
	.string "tell you, this whole place is so\l"
	.string "strange...$"

ThirdInGameLocation_Bidoof3_Text_9:
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's not natural at all...Well, it doesn't\n"
	.string "matter that much I guess! We need to\l"
	.string "get out of here!$"

ThirdInGameLocation_Bidoof3_Text_10:
# 115 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "The problem is...I have no idea how! I\n"
	.string "tried to break the rock myself, but as\l"
	.string "you can clearly see, it didn't work.$"

ThirdInGameLocation_Bidoof3_Text_11:
# 118 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll rest a bit and try to think of a\n"
	.string "solution. In the meantime feel free to\l"
	.string "roam about, maybe you'll find something\l"
	.string "useful!$"

ThirdInGameLocation_Bidoof3_Text_12:
# 130 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey pal, did you find something?$"

ThirdInGameLocation_Bidoof3_Text_13:
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...Hidden machines...I know how these\n"
	.string "work!$"

ThirdInGameLocation_Bidoof3_Text_14:
# 137 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it just so happens that I can learn\n"
	.string "this move!$"

ThirdInGameLocation_Bidoof3_Text_15:
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get some rocks broken!$"

ThirdInGameLocation_Bidoof3_Text_16:
# 161 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof learned {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_17:
# 162 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof used {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_18:
# 172 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it's done! We make quite the team,\n"
	.string "huh?$"

ThirdInGameLocation_Bidoof3_Text_19:
# 175 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, I think it'll be better if we\n"
	.string "hold together. At least, until we're out\l"
	.string "of here.$"

ThirdInGameLocation_Bidoof3_Text_20:
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Who knows whatever may loom here...$"

ThirdInGameLocation_Bidoof3_Text_21:
# 181 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you agree with me, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_22:
# 186 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, you can't be serious!\n$"

ThirdInGameLocation_Bidoof3_Text_23:
# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get out of here together, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_24:
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, please do not joke like that!$"

ThirdInGameLocation_Bidoof3_Text_25:
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright! Take the lead, {PLAYER}. I'll\n"
	.string "be right behind you.$"

ThirdInGameLocation_Bidoof3_Text_26:
# 216 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! I'm not convinced...$"

ThirdInGameLocation_Bidoof3_Text_27:
# 223 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries!$"

ThirdInGameLocation_Underwater_RockSmash_Text_0:
# 298 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\n"
	.string "Pokemon knowing the move {COLOR RED}Rock Smash{COLOR DARK_GRAY}\l"
	.string "could smash it.$"

ThirdInGameLocation_Underwater_RockSmash_Text_1:
# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\nThere must be a way to smash it somehow...$"

ThirdInGameLocation_Underwater_CreepyHexManiac_Text_0:
# 374 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! Did-did you see that???$"
