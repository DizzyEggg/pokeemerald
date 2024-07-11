WingullHouseBetweenCavesInUnderwater_MapScripts::
# 3 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_LOAD
# 10 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 17 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_LOAD:
# 4 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	goto_if_set FLAG_WINGULL_BLENDER_BEATEN, WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 5 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setmetatile 2, 2, 0x221, FALSE
# 6 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setmetatile 2, 3, 0x2DD, TRUE
	return

WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 11 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	goto_if_set FLAG_WINGULL_BLENDER_BEATEN, WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 14 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxyperm 4, 13, 0
	return

WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 12 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxyperm 3, 13, 0
	return

WingullHouseBetweenCavesInUnderwater_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 18 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	map_script_2 VAR_HACK_GAME_STATE, 3, WingullHouseBetweenCavesInUnderwater_WeMadeit
	.2byte 0


WingullHouseBetweenCavesInUnderwater_WeMadeit::
# 23 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lock
# 24 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Up
# 25 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 26 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 27 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_0
# 28 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_1
# 29 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 30 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 31 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_2
# 32 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 33 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8008
# 34 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_3
# 35 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 4
# 36 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 37 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 38 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 39 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
	end


WingullHouseBetweenCavesInUnderwater_BellNotWorking::
# 44 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lock
# 45 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0, MSGBOX_YESNO
# 46 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WingullHouseBetweenCavesInUnderwater_BellNotWorking_2
# 49 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2
WingullHouseBetweenCavesInUnderwater_BellNotWorking_1:
# 51 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	release
	end

WingullHouseBetweenCavesInUnderwater_BellNotWorking_2:
# 47 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_1
	goto WingullHouseBetweenCavesInUnderwater_BellNotWorking_1


WingullHouseBetweenCavesInUnderwater_CallWingull::
# 56 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lock
# 57 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	goto_if_unset FLAG_WINGULL_BLENDER_BEATEN, WingullHouseBetweenCavesInUnderwater_CallWingull_2
# 260 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_WINGULL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 261 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 262 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 6
	goto_if_eq WingullHouseBetweenCavesInUnderwater_CallWingull_9
# 264 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	goto_if_set FLAG_HIKER_CHALLENGE_DONE, WingullHouseBetweenCavesInUnderwater_CallWingull_12
WingullHouseBetweenCavesInUnderwater_CallWingull_11:
# 270 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_54, VAR_0x800A
WingullHouseBetweenCavesInUnderwater_CallWingull_8:
# 272 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_WINGULL, VAR_0x800A
WingullHouseBetweenCavesInUnderwater_CallWingull_1:
# 274 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	release
	end

WingullHouseBetweenCavesInUnderwater_CallWingull_2:
# 58 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0, MSGBOX_YESNO
# 59 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WingullHouseBetweenCavesInUnderwater_CallWingull_5
# 257 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_1

WingullHouseBetweenCavesInUnderwater_CallWingull_5:
# 60 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_0
# 61 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 62 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 63 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_M_HEAL_BELL
# 64 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 65 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 66 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 67 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 68 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 69 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_1
# 70 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 71 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 72 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 73 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_M_HEAL_BELL
# 74 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 75 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 76 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 77 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8008
# 78 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_2
# 79 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 80 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8008
# 81 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 82 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	fadeoutbgm 3
# 83 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8009
# 84 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 85 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative FadeAllExceptBg0AndMugshots
# 86 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 87 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 88 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_3
# 89 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 90 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_4
# 91 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 92 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 93 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 94 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 95 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative RemoveFollowingPokemon
# 96 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	clearflag FLAG_BIDOOF_FOLLOWER
# 97 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 98 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER2
# 99 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 100 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 101 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_5
# 102 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 103 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 104 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 105 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 106 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 107 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_6
# 108 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 109 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 110 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_7
# 111 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 112 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 20
# 113 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_8
# 114 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 115 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 116 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_9
# 117 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 118 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 119 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_10
# 120 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 121 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_11
# 122 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 123 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 124 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_12
# 125 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 126 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 127 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_13
# 128 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LookDown
# 129 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	addobject 1
# 130 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	clearflag FLAG_HIDE_WINGULL
# 131 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	turnobject 1, DIR_NORTH
# 132 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	addobject 2
# 133 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxy 1, 7, 5
# 134 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	fadeinbgm 3
# 135 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative FadeOutAllExceptBg0AndMugshots
# 136 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 5
# 137 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_WINGULL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 138 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_14
# 139 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 140 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 141 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_15
# 142 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_16
# 143 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 144 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 145 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_17
# 146 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 147 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 148 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_18
# 149 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 150 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 151 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_19
# 152 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 153 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 154 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_20
# 155 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 156 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 157 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_21
# 158 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 159 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 160 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 161 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setwildbattle SPECIES_WINGULL, 19
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	dowildbattle
# 163 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 5
# 164 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_WINGULL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 165 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_22
# 166 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 167 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8009
# 168 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_23
# 169 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 170 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 171 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_24
# 172 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_APPLAUSE
# 173 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 174 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 175 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x8009
# 176 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_25
# 177 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x8009
# 178 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	show_field_pic VAR_0x800A
# 179 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_26
# 180 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 181 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 182 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	hide_field_pic VAR_0x800A
# 183 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 1, MovementToBlenderWingull
# 184 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementToBlenderPlayer
# 185 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 2, MovementToBlenderBidoof
# 186 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 187 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_27, VAR_0x800A
# 188 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	giveitem ITEM_POKEBLOCK_CASE, 1
# 189 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 31
# 190 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_28, VAR_0x800A
# 191 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 192 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_29, VAR_0x8008
# 193 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_30, VAR_0x800A, MSGBOX_YESNO
# 194 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WingullHouseBetweenCavesInUnderwater_CallWingull_17
# 198 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_33, VAR_0x800A
WingullHouseBetweenCavesInUnderwater_CallWingull_16:
# 200 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_34, VAR_0x800A
# 201 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_0x8004, 2
# 202 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	fadescreen FADE_TO_BLACK
# 203 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	special DoBerryBlending
# 204 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitstate
# 205 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_WINGULL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 206 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playbgm MUS_LINK_CONTEST_P1, FALSE
# 207 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative BerryBlenderGetLostCount
# 208 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	switch VAR_RESULT
# 209 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 0, WingullHouseBetweenCavesInUnderwater_CallWingull_22
# 210 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 1, WingullHouseBetweenCavesInUnderwater_CallWingull_23
# 211 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 2, WingullHouseBetweenCavesInUnderwater_CallWingull_24
# 212 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 3, WingullHouseBetweenCavesInUnderwater_CallWingull_25
# 213 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 4, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 5, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 6, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 7, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 8, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 9, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 10, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 11, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 12, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 13, WingullHouseBetweenCavesInUnderwater_CallWingull_27
# 215 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_41, VAR_0x800A
WingullHouseBetweenCavesInUnderwater_CallWingull_20:
# 217 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	message WingullHouseBetweenCavesInUnderwater_CallWingull_Text_42
# 218 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 219 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 220 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_BADGE01_GET
# 221 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_WINGULL_BLENDER_BEATEN
# 222 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_43, VAR_0x800A
# 223 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 224 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_44, VAR_0x8008
# 225 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8009
# 226 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_45, VAR_0x8009
# 227 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_46, VAR_0x800A
# 228 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_47, VAR_0x8009
# 229 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_48, VAR_0x800A
# 230 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 1, MovementOneDown
# 231 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setmetatile 2, 2, 0x221, FALSE
# 232 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setmetatile 2, 3, 0x2DD, TRUE
# 233 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxy 3, 13, 0
# 234 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxy 4, 2, 3
# 235 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxyperm 4, 2, 3
# 236 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	special DrawWholeMapView
# 237 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 238 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_49, VAR_0x800A
# 239 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 1, MovementWingullFromBlender
# 240 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_50, VAR_0x8008
# 241 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 242 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 243 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 244 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 2, MovementBidoofLeft
# 245 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 246 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 247 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative UpdateFollowingPokemon
# 248 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	removeobject 2
# 249 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerFaceUp_WingullHouse
# 250 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 251 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 2
# 252 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 6
# 253 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED, VAR_0x8009
# 254 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 255 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_WINGULL, VAR_0x800A
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_1

WingullHouseBetweenCavesInUnderwater_CallWingull_9:
# 263 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_51, VAR_0x800A
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_8

WingullHouseBetweenCavesInUnderwater_CallWingull_10:
# 265 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_52, VAR_0x800A
# 266 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_53, VAR_0x800A
# 267 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_WINGULL_COMMENTARY_HIKER
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_8

WingullHouseBetweenCavesInUnderwater_CallWingull_12:
# 264 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	goto_if_unset FLAG_WINGULL_COMMENTARY_HIKER, WingullHouseBetweenCavesInUnderwater_CallWingull_10
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_11

WingullHouseBetweenCavesInUnderwater_CallWingull_17:
# 195 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_31, VAR_0x800A
# 196 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_32, VAR_0x8009
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_16

WingullHouseBetweenCavesInUnderwater_CallWingull_22:
# 209 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_35, VAR_0x800A
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_20

WingullHouseBetweenCavesInUnderwater_CallWingull_23:
# 210 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_36, VAR_0x800A
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_20

WingullHouseBetweenCavesInUnderwater_CallWingull_24:
# 211 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_37, VAR_0x800A
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_20

WingullHouseBetweenCavesInUnderwater_CallWingull_25:
# 212 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_38, VAR_0x800A
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_20

WingullHouseBetweenCavesInUnderwater_CallWingull_26:
# 213 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_39, VAR_0x800A
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_20

WingullHouseBetweenCavesInUnderwater_CallWingull_27:
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_pic WingullHouseBetweenCavesInUnderwater_CallWingull_Text_40, VAR_0x800A
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_20


# 278 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementPlayerFaceUp_WingullHouse:
# 279 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_down
# 280 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_up
# 281 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 284 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementBidoofLeft:
# 285 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 286 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 287 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 288 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 291 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementWingullFromBlender:
# 292 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 293 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 294 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 295 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 296 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 297 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 298 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 299 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 300 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 303 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementOneDown:
# 304 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_down
# 305 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 308 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderWingull:
# 309 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 310 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 311 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 312 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 313 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 314 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 315 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 316 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 319 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderPlayer:
# 320 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 321 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 322 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 323 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 324 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 325 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 326 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 327 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 328 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 329 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 330 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_right
# 331 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 334 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderBidoof:
# 335 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 336 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 337 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 338 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 339 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 340 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 341 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 342 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 343 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 344 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_left
# 345 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine::
# 349 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lockall
# 350 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine_Text_0
# 351 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	releaseall
	end


# 355 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_LookDown:
# 356 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 357 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 360 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_Up:
# 361 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 362 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 363 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 366 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_LookUpWingull:
# 367 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_up
# 368 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_0:
# 27 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Whew, we did it!$"

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_1:
# 28 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Nice thinking with the rock-switch,\n"
	.string "{PLAYER}!$"

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_2:
# 31 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Though...We were underwater and now\n"
	.string "we're inside...a house? Talk about\l"
	.string "ambient change. This whole area is so\l"
	.string "messed up, {PLAYER}. It could be some\l"
	.string "sort of illusion, or even a spell. I'm not\l"
	.string "exactly sure.$"

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_3:
# 34 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "In any case, let's explore and continue\n"
	.string "forward.$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0:
# 45 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "There's a Bell.\nRing it?$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_1:
# 47 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "The Bell is broken.$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2:
# 49 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You left the bell untouched.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_0:
# 60 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "{PLAYER} rang the bell.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_1:
# 69 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hmm...Let's try again.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_2:
# 78 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You know, I would expect something to\n"
	.string "happen.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_3:
# 88 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "{PLAYER}!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_4:
# 90 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly, it got dark all of a sudden!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_5:
# 101 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Did you hear that?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_6:
# 107 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "WHO?!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_7:
# 110 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Who is it...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_8:
# 113 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "SPEAK!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_9:
# 116 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "We didn't want to disturb you, I swear!\n"
	.string "We actually want to leave!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_10:
# 119 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "W{PAUSE 30}A{PAUSE 30}I{PAUSE 30}T!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_11:
# 121 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "I can't let you {PAUSE 20}go that easily...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_12:
# 124 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_13:
# 127 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "T{PAUSE 10}u{PAUSE 20}r{PAUSE 30}n a{PAUSE 25}r{PAUSE 28}o{PAUSE 22}u{PAUSE 22}n{PAUSE 22}d.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_14:
# 138 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hey y'all! I'm Wingull!\nWingull, the gull!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_15:
# 141 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_16:
# 142 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Really?\lTalk about anticlamatic...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_17:
# 145 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hmm? You were sayin'?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_18:
# 148 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly, no! Nothing!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_19:
# 151 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Welcome in my humble domain!\n"
	.string "The rules are simple: if you wish to\l"
	.string "pass, you'll need to defeat me in a duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_20:
# 154 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Duel?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_21:
# 157 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Yes! It's time to du-du-du-duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_22:
# 165 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hey!\nLet me finish first!\pWe'll have a...\la...\la...\la...\la...\la...\la...\la...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_23:
# 168 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Oh come on!\nSpit it out already!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_24:
# 171 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "As I was saying!\pWe'll have a...\lBerry Blending duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_25:
# 176 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Right, exactly what I had in mind...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_26:
# 179 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Follow me!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_27:
# 187 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Alright! There's three of us, so that's\n"
	.string "even better. I was hoping for a quartet,\l"
	.string "but whatever.\l"
	.string "THE RULES!\l"
	.string "The rules are fairly simple, you just\l"
	.string "need the right equipment. Which you are\l"
	.string "missing, but fear not! I have a spare\l"
	.string "Pokeblock Case and some berries. Here!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_28:
# 190 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Now we're ready!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_29:
# 192 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "What about the rules?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_30:
# 193 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Rules? You want me to explain\nthe rules?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_31:
# 195 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Well, ugh...\n"
	.string "You throw a Berry and then the thing\l"
	.string "spins...I'm sure you'll quickly get the\l"
	.string "hang of it!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_32:
# 196 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "For sure...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_33:
# 198 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Yeah, I'm sure you already know them!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_34:
# 200 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Let's go!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_35:
# 209 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Wow! You beat me on the first try!\n"
	.string "You're like a Berry Blending Master!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_36:
# 210 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Wow, you're pretty good! It only took\n"
	.string "you 2 attempts to beat me!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_37:
# 211 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You're good, I'll give you that!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_38:
# 212 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "It took you 4 tries, but you've got it.\n"
	.string "Grats!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_39:
# 213 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You got me, not bad!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_40:
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You did it champ! It took you long\n"
	.string "enough, but you beat me fair and\l"
	.string "square.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_41:
# 215 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Well...Every streak has to end, mine too!\n"
	.string "As for you, I fell like you'll have\l"
	.string "enough Berry Blending for quite some\l"
	.string "time, haha!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_42:
# 217 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "{PLAYER} received the Blender Badge\nfrom Wingull.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_43:
# 222 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You earned it, champ!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_44:
# 224 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Oh, I see {PLAYER}!\n"
	.string "If things were normal, you would've\l"
	.string "received a Badge only after beating a\l"
	.string "Gym leader! I believe there are 8 Gym\l"
	.string "Leaders you need to beat, before\l"
	.string "facing the ultimate challenge. Or\l"
	.string "something similar, I'm not 100% sure.\l"
	.string "...\l"
	.string "Given the actual state of affairs here,\l"
	.string "you'll probably obtain the badges in\l"
	.string "other, weirder ways, just like here with\l"
	.string "Wingull.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_45:
# 226 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly! I struggle to think what the next\n"
	.string "'Gym Leader' will be like!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_46:
# 227 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "That's how things work here in the\n"
	.string "Underwater.\l"
	.string "Though, Bidoof. Out of everyone, you\l"
	.string "should've known that already.\l"
	.string "After all...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_47:
# 228 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "What are you even talking about!?\n"
	.string "Whatever, {PLAYER} won, which means\l"
	.string "we can leave.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_48:
# 229 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "I was hoping you'd stay here for a bit\n"
	.string "longer! But it's fine! Let me move this\l"
	.string "thing...$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_49:
# 238 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Much better!\p"
	.string "I'm not going anywhere, so if you need\n"
	.string "something, just let me know!\l"
	.string "Smell ya later!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_50:
# 240 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Alright, {PLAYER}! Let's get out of\n"
	.string "here!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_51:
# 263 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Thanks for playing with me! I'm sure\n"
	.string "we'll see each other again!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_52:
# 265 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "I see you've beaten that Hiker asshole!\n"
	.string "Nicely done. Seriously, screw him.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_53:
# 266 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Thanks for stepping by and sharing the\n"
	.string "news with me!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_54:
# 270 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hey guys! Nice to see you again!$"

WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine_Text_0:
# 350 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "It's a Berry Blender.\nIt can't be used at the moment.$"
