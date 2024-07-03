ThirdInGameLocation_Underwater_MapScripts::
# 2 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return


ThirdInGameLocation_Bidoof3::
# 7 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 8 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	faceplayer
# 9 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_2
# 51 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 2
	goto_if_eq ThirdInGameLocation_Bidoof3_3
ThirdInGameLocation_Bidoof3_1:
# 147 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_2:
# 10 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_UNEASY, 78, 107, VAR_0x8009
# 11 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_0
# 12 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 13 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 78, 107, VAR_0x8008
# 14 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_1
# 15 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 16 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107, VAR_0x800A
# 17 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_2
# 18 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 19 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 20 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_3
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 22 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_4
# 24 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_5
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 28 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_7
# 29 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 30 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800A
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_8
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_9
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_6
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8009
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_10
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 40 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_11
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 43 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x8009
# 44 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800A
# 45 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 46 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 47 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_3:
# 52 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 78, 107, VAR_0x8008
# 53 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_12, MSGBOX_YESNO
# 54 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_7
# 138 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 139 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 78, 107, VAR_0x800A
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_27
# 141 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
ThirdInGameLocation_Bidoof3_6:
# 143 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 144 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof3
# 145 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_1

ThirdInGameLocation_Bidoof3_7:
# 55 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 56 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Bidoof3_10
# 131 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 132 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107, VAR_0x800A
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_26
# 134 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_UNEASY, VAR_0x800A
	goto ThirdInGameLocation_Bidoof3_6

ThirdInGameLocation_Bidoof3_10:
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_13
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 59 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 78, 107, VAR_0x800A
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_14
# 61 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 62 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_SMIRKY, 78, 107, VAR_0x800A
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_15
# 64 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_SMIRKY, VAR_0x800A
# 65 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 66 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 67 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 68 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ThirdInGameLocation_Bidoof3_14
# 75 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_Up
# 76 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 77 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_Up
# 78 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
ThirdInGameLocation_Bidoof3_13:
# 80 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_ToRockSmash
# 81 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_ToRockSmash
# 82 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 83 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PC_LOGIN
# 84 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_16
# 85 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_17
# 86 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	closemessage
# 87 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 4
# 88 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 89 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitstate
# 90 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 91 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 92 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject VAR_LAST_TALKED
# 93 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_ROCK_SMASH_3RD_LOC
# 94 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_HAPPY, 78, 107, VAR_0x800A
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_18
# 96 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 97 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_19
# 99 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 100 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107, VAR_0x800B
# 101 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_20
# 102 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 103 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 104 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_21, MSGBOX_YESNO
# 105 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_18
ThirdInGameLocation_Bidoof3_17:
# 119 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_25
# 121 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_3
# 122 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 123 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 5
# 124 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 125 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_HAPPY, VAR_0x800A
# 126 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x800B
# 127 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Bidoof3_14:
# 69 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 5, MovementBidoof_East
# 70 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 71 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayer_East
# 72 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
	goto ThirdInGameLocation_Bidoof3_13

ThirdInGameLocation_Bidoof3_18:
ThirdInGameLocation_Bidoof3_22:
# 107 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 108 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_22
# 110 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
# 111 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x8008
# 112 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_23, MSGBOX_YESNO
# 113 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne ThirdInGameLocation_Bidoof3_22
# 114 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 115 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	show_field_pic VAR_0x800B
# 116 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Bidoof3_Text_24
# 117 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	hide_field_pic VAR_0x800B
	goto ThirdInGameLocation_Bidoof3_17


# 151 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_ToRockSmash:
# 152 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 153 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 154 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 155 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 156 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 157 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 158 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 159 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 160 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 161 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 164 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_ToRockSmash:
# 165 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 166 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 167 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 168 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 169 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 170 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 171 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 172 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 173 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 174 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 177 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_East:
# 178 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 179 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 180 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 181 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 184 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_East:
# 185 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 186 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 189 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof_Up:
# 190 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 191 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 192 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 193 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 196 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementPlayer_Up:
# 197 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_left
# 198 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 201 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof3:
# 202 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 203 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_RockSmash::
# 207 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 208 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	checkitem ITEM_HM06
# 209 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ThirdInGameLocation_Underwater_RockSmash_2
# 213 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_1
ThirdInGameLocation_Underwater_RockSmash_1:
# 215 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end

ThirdInGameLocation_Underwater_RockSmash_2:
# 210 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	msgbox ThirdInGameLocation_Underwater_RockSmash_Text_0
	goto ThirdInGameLocation_Underwater_RockSmash_1


ThirdInGameLocation_Underwater_BidoffTrigger2::
# 220 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 221 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 222 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_2
# 223 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 3, MovementBidoof2
# 224 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 225 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 3
# 226 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 230 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof2:
# 231 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 232 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_up
# 233 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 234 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 235 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 236 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_down
# 237 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 238 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 239 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 240 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_down
# 241 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 242 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_BidoffTrigger1::
# 246 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 247 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 248 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_1
# 249 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 2, MovementBidoof1
# 250 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 251 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	removeobject 2
# 252 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 256 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof1:
# 257 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 258 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 259 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 260 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 261 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 262 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 263 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 264 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 265 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_CreepyHexManiac::
# 269 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 270 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 271 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 272 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 273 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 274 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 275 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 276 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 277 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 278 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 279 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 280 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 281 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 282 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 286 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 287 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 288 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 289 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 290 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 291 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 292 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 293 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 296 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 297 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 298 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 299 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 300 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 301 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 302 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 303 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 304 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Bidoof3_Text_0:
# 11 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly...$"

ThirdInGameLocation_Bidoof3_Text_1:
# 14 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hi.$"

ThirdInGameLocation_Bidoof3_Text_2:
# 17 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I mean! You must be pretty surprised to\n"
	.string "see a Bidoof underwater! After all,\l"
	.string "ocean's depths are not my natural\l"
	.string "habitat.$"

ThirdInGameLocation_Bidoof3_Text_3:
# 20 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's weird, isn't it? Seeing a Bidoof\n"
	.string "here...A talking Bidoof at that!$"

ThirdInGameLocation_Bidoof3_Text_4:
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Though you don't look that\n"
	.string "surprised...Or you do? Golly, I can't\l"
	.string "tell!$"

ThirdInGameLocation_Bidoof3_Text_5:
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Sorry about earlier, running off like\n"
	.string "that. I was a bit scared when I saw you\l"
	.string "floating around there! But you seem\l"
	.string "like a nice chum.$"

ThirdInGameLocation_Bidoof3_Text_6:
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "...$"

ThirdInGameLocation_Bidoof3_Text_7:
# 28 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "We need to get out of here. I don't know\n"
	.string "if you're aware, but there is a rock down\l"
	.string "there blocking the way.$"

ThirdInGameLocation_Bidoof3_Text_8:
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, it's really weird how it's\n"
	.string "placed there, just like that. As if it\l"
	.string "was put on purpose...Though, I have to\l"
	.string "tell you, this whole place is so\l"
	.string "strange...$"

ThirdInGameLocation_Bidoof3_Text_9:
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's not natural at all...Well, it doesn't\n"
	.string "matter that much I guess! We need to\l"
	.string "get out of here!$"

ThirdInGameLocation_Bidoof3_Text_10:
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "The problem is...I have no idea how! I\n"
	.string "tried to break the rock myself, but as\l"
	.string "you can clearly see, it didn't work.$"

ThirdInGameLocation_Bidoof3_Text_11:
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I'll rest a bit and try to think of a\n"
	.string "solution. In the meantime feel free to\l"
	.string "roam about, maybe you'll find something\l"
	.string "useful!$"

ThirdInGameLocation_Bidoof3_Text_12:
# 53 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hey pal, did you find something?$"

ThirdInGameLocation_Bidoof3_Text_13:
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Hm...Hidden machines...I know how these\n"
	.string "work!$"

ThirdInGameLocation_Bidoof3_Text_14:
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it just so happens that I can learn\n"
	.string "this move!$"

ThirdInGameLocation_Bidoof3_Text_15:
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get some rocks broken!$"

ThirdInGameLocation_Bidoof3_Text_16:
# 84 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof learned {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_17:
# 85 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Bidoof used {COLOR RED}Rock Smash{COLOR DARK_GRAY}!$"

ThirdInGameLocation_Bidoof3_Text_18:
# 95 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "And it's done! We make quite the team,\n"
	.string "huh?$"

ThirdInGameLocation_Bidoof3_Text_19:
# 98 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "You know, I think it'll be better if we\n"
	.string "hold together. At least, until we're out\l"
	.string "of here.$"

ThirdInGameLocation_Bidoof3_Text_20:
# 101 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Who knows whatever may loom here...$"

ThirdInGameLocation_Bidoof3_Text_21:
# 104 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "I hope you agree with me, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_22:
# 109 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, you can't be serious!\n$"

ThirdInGameLocation_Bidoof3_Text_23:
# 112 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Let's get out of here together, {PLAYER}!$"

ThirdInGameLocation_Bidoof3_Text_24:
# 116 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly, please do not joke like that!$"

ThirdInGameLocation_Bidoof3_Text_25:
# 120 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Alright! Take the lead, {PLAYER}. I'll\n"
	.string "be right behind you.$"

ThirdInGameLocation_Bidoof3_Text_26:
# 133 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "Golly! I'm not convinced...$"

ThirdInGameLocation_Bidoof3_Text_27:
# 140 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "No worries!$"

ThirdInGameLocation_Underwater_RockSmash_Text_0:
# 210 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\n"
	.string "Pokemon knowing the move {COLOR RED}Rock Smash{COLOR DARK_GRAY}\l"
	.string "could smash it.$"

ThirdInGameLocation_Underwater_RockSmash_Text_1:
# 213 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	.string "It's a rugged rock blocking the way.\nThere must be a way to smash it somehow...$"
