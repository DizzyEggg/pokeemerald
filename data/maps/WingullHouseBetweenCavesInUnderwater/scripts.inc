WingullHouseBetweenCavesInUnderwater_MapScripts::
# 2 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	map_script_2 VAR_HACK_GAME_STATE, 3, WingullHouseBetweenCavesInUnderwater_WeMadeit
	.2byte 0


WingullHouseBetweenCavesInUnderwater_WeMadeit::
# 8 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lock
# 9 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Up
# 10 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 11 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 12 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_0
# 13 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_1
# 14 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 15 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107
# 16 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_2
# 17 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 18 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8008
# 19 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_3
# 20 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 4
# 21 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 22 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 23 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 24 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
	end


WingullHouseBetweenCavesInUnderwater_BellNotWorking::
# 29 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lock
# 30 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0, MSGBOX_YESNO
# 31 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WingullHouseBetweenCavesInUnderwater_BellNotWorking_2
# 34 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2
WingullHouseBetweenCavesInUnderwater_BellNotWorking_1:
# 36 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	release
	end

WingullHouseBetweenCavesInUnderwater_BellNotWorking_2:
# 32 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_1
	goto WingullHouseBetweenCavesInUnderwater_BellNotWorking_1


WingullHouseBetweenCavesInUnderwater_CallWingull::
# 41 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lock
# 42 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0, MSGBOX_YESNO
# 43 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WingullHouseBetweenCavesInUnderwater_CallWingull_2
# 171 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2
WingullHouseBetweenCavesInUnderwater_CallWingull_1:
# 173 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	release
	end

WingullHouseBetweenCavesInUnderwater_CallWingull_2:
# 44 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_0
# 45 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 46 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 47 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_M_HEAL_BELL
# 48 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 49 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 50 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 51 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 52 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 53 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_1
# 54 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 55 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 56 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 57 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_M_HEAL_BELL
# 58 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 59 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 60 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 61 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8008
# 62 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_2
# 63 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 64 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 65 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 66 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	fadeoutbgm 3
# 67 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x8009
# 68 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 69 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative FadeAllExceptBg0AndMugshots
# 70 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 71 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 72 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_3
# 73 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 74 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_4
# 75 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 76 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 77 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 78 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 79 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative RemoveFollowingPokemon
# 80 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	clearflag FLAG_BIDOOF_FOLLOWER
# 81 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 82 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER2
# 83 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 84 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 85 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_5
# 86 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 87 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 88 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 89 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 90 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 91 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_6
# 92 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 93 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 94 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_7
# 95 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 96 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 20
# 97 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_8
# 98 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 99 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 100 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_9
# 101 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 102 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 103 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_10
# 104 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 105 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_11
# 106 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 107 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 108 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_12
# 109 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 110 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 111 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_13
# 112 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LookDown
# 113 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 114 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	addobject 1
# 115 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	addobject 2
# 116 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxy 1, 7, 5
# 117 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	fadeinbgm 3
# 118 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative FadeOutAllExceptBg0AndMugshots
# 119 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 5
# 120 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_WINGULL, 33, 107, VAR_0x800A
# 121 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_14
# 122 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 123 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 124 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_15
# 125 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_16
# 126 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 127 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 128 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_17
# 129 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 130 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 131 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_18
# 132 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 133 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 134 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_19
# 135 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 136 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 137 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_20
# 138 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 139 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 140 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_21
# 141 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 142 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 143 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 144 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setwildbattle SPECIES_WINGULL, 19
# 145 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	dowildbattle
# 146 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 5
# 147 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_WINGULL, 33, 107, VAR_0x800A
# 148 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_22
# 149 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 150 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 33, 107, VAR_0x8009
# 151 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_23
# 152 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 153 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 154 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_24
# 155 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_APPLAUSE
# 156 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 157 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 158 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 159 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_25
# 160 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 161 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_26
# 163 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 164 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 165 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 166 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 1, MovementToBlenderWingull
# 167 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementToBlenderPlayer
# 168 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 2, MovementToBlenderBidoof
# 169 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_1


# 177 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderWingull:
# 178 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 179 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 180 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 181 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 182 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 183 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 184 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 185 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 188 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderPlayer:
# 189 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 190 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 191 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 192 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 193 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 194 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 195 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 196 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 197 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 198 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 199 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_right
# 200 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 203 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderBidoof:
# 204 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 205 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 206 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 207 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 208 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 209 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 210 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 211 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 212 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 213 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_left
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine::
# 218 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lockall
# 219 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine_Text_0
# 220 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	releaseall
	end


# 224 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_LookDown:
# 225 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 226 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 229 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_Up:
# 230 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 231 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 232 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 235 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_LookUp:
# 236 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_up
# 237 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_0:
# 12 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Whew, we did it!$"

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_1:
# 13 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Nice thinking with the rock-switch,\n"
	.string "{PLAYER}!$"

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_2:
# 16 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Though...We were underwater and now\n"
	.string "we're inside...a house? Talk about\l"
	.string "ambient change. This whole area is so\l"
	.string "messed up, {PLAYER}. It could be some\l"
	.string "sort of illusion, or even a spell. I'm not\l"
	.string "exactly sure.$"

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_3:
# 19 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "In any case, let's explore and continue\n"
	.string "forward.$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0:
# 30 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "There's a Bell.\nRing it?$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_1:
# 32 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "The Bell is broken.$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2:
# 34 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You left the bell untouched.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_0:
# 44 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "{PLAYER} rang the bell.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_1:
# 53 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hmm...Let's try again.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_2:
# 62 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You know, I would expect something to\n"
	.string "happen.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_3:
# 72 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "{PLAYER}!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_4:
# 74 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly, it got dark all of a sudden!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_5:
# 85 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Did you hear that?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_6:
# 91 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "WHO?!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_7:
# 94 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Who is it...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_8:
# 97 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "SPEAK!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_9:
# 100 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "We didn't want to disturb you, I swear!\n"
	.string "We actually want to leave!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_10:
# 103 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "W{PAUSE 30}A{PAUSE 30}I{PAUSE 30}T!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_11:
# 105 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "I can't let you {PAUSE 20}go that easily...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_12:
# 108 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_13:
# 111 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "T{PAUSE 10}u{PAUSE 20}r{PAUSE 30}n a{PAUSE 25}r{PAUSE 28}o{PAUSE 22}u{PAUSE 22}n{PAUSE 22}d.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_14:
# 121 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hey y'all! I'm Wingull!\nWingull, the gull!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_15:
# 124 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_16:
# 125 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Really?\lTalk about anticlamatic...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_17:
# 128 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hmm? You were sayin'?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_18:
# 131 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly, no! Nothing!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_19:
# 134 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Welcome in my humble domain!\n"
	.string "The rules are simple: if you wish to\l"
	.string "pass, you'll need to defeat me in a duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_20:
# 137 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Duel?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_21:
# 140 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Yes! It's time to du-du-du-duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_22:
# 148 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hey!\nLet me finish first!\pWe'll have a...\la...\la...\la...\la...\la...\la...\la...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_23:
# 151 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Oh come on!\nSpit it out already!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_24:
# 154 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "As I was saying!\pWe'll have a...\lBerry Blending duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_25:
# 159 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Right, exactly what I had in mind...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_26:
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Follow me!$"

WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine_Text_0:
# 219 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "It's a Berry Blender.\nIt can't be used at the moment.$"
