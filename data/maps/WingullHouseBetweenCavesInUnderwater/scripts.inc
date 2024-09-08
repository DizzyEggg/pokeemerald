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
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_0, FIELD_PIC_BIDOOF_NORMAL
# 27 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_1, FIELD_PIC_BIDOOF_ASTONISHED
# 28 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_2, FIELD_PIC_BIDOOF_NORMAL
# 29 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 4
# 30 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 31 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 32 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
	end


WingullHouseBetweenCavesInUnderwater_BellNotWorking::
# 37 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lock
# 38 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0, MSGBOX_YESNO
# 39 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WingullHouseBetweenCavesInUnderwater_BellNotWorking_2
# 42 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2
WingullHouseBetweenCavesInUnderwater_BellNotWorking_1:
# 44 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	release
	end

WingullHouseBetweenCavesInUnderwater_BellNotWorking_2:
# 40 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_1
	goto WingullHouseBetweenCavesInUnderwater_BellNotWorking_1


WingullHouseBetweenCavesInUnderwater_CallWingull::
# 49 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lock
# 50 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	goto_if_unset FLAG_WINGULL_BLENDER_BEATEN, WingullHouseBetweenCavesInUnderwater_CallWingull_2
# 204 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_HACK_GAME_STATE, 6
	goto_if_eq WingullHouseBetweenCavesInUnderwater_CallWingull_8
# 206 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	goto_if_set FLAG_HIKER_CHALLENGE_DONE, WingullHouseBetweenCavesInUnderwater_CallWingull_11
WingullHouseBetweenCavesInUnderwater_CallWingull_10:
# 211 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_51, FIELD_PIC_WINGULL
WingullHouseBetweenCavesInUnderwater_CallWingull_1:
# 214 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	release
	end

WingullHouseBetweenCavesInUnderwater_CallWingull_2:
# 51 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0, MSGBOX_YESNO
# 52 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WingullHouseBetweenCavesInUnderwater_CallWingull_5
# 201 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_1

WingullHouseBetweenCavesInUnderwater_CallWingull_5:
# 53 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_0
# 54 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 55 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 56 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_M_HEAL_BELL
# 57 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 58 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 59 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 60 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 61 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_1, FIELD_PIC_BIDOOF_NORMAL
# 62 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 63 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_M_HEAL_BELL
# 64 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 65 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_BIKE_BELL
# 66 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 67 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_2, FIELD_PIC_BIDOOF_NORMAL
# 68 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 69 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	fadeoutbgm 3
# 70 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative FadeAllExceptBg0AndMugshots
# 71 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 72 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_3, FIELD_PIC_BIDOOF_ASTONISHED
# 73 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 74 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 75 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative RemoveFollowingPokemon
# 76 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	clearflag FLAG_BIDOOF_FOLLOWER
# 77 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 78 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER2
# 79 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 80 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_4, FIELD_PIC_BIDOOF_ASTONISHED
# 81 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 82 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 83 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 84 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_5
# 85 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 30
# 86 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 87 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_6
# 88 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_THUNDER
# 89 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 20
# 90 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_7
# 91 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 92 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_8, FIELD_PIC_BIDOOF_ASTONISHED
# 93 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 94 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_9
# 95 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 96 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_10
# 97 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 98 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_11, FIELD_PIC_BIDOOF_ASTONISHED
# 99 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 100 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_CallWingull_Text_12
# 101 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LookDown
# 102 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	addobject 1
# 103 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	clearflag FLAG_HIDE_WINGULL
# 104 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	turnobject 1, DIR_NORTH
# 105 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	addobject 2
# 106 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxy 1, 7, 5
# 107 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	fadeinbgm 3
# 108 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative FadeOutAllExceptBg0AndMugshots
# 109 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 5
# 110 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_13, FIELD_PIC_WINGULL
# 111 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_14, FIELD_PIC_BIDOOF_ASTONISHED
# 112 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_15, FIELD_PIC_WINGULL
# 113 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_16, FIELD_PIC_BIDOOF_ASTONISHED
# 114 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_17, FIELD_PIC_WINGULL
# 115 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_18, FIELD_PIC_BIDOOF_ASTONISHED
# 116 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_19, FIELD_PIC_WINGULL
# 117 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 118 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setwildbattle SPECIES_WINGULL, 19
# 119 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	dowildbattle
# 120 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 5
# 121 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_20, FIELD_PIC_WINGULL
# 122 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_21, FIELD_PIC_BIDOOF_ASTONISHED
# 123 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	load_field_pic FIELD_PIC_WINGULL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x8008
# 124 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_22, FIELD_PIC_WINGULL
# 125 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playse SE_APPLAUSE
# 126 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitse
# 127 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	destroy_field_pic FIELD_PIC_WINGULL, VAR_0x8008
# 128 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_23, FIELD_PIC_BIDOOF_ASTONISHED
# 129 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_24, FIELD_PIC_WINGULL
# 130 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 131 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 1, MovementToBlenderWingull
# 132 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementToBlenderPlayer
# 133 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 2, MovementToBlenderBidoof
# 134 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 135 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_25, FIELD_PIC_WINGULL
# 136 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 137 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	giveitem ITEM_POKEBLOCK_CASE, 1
# 138 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 31
# 139 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_26, FIELD_PIC_WINGULL
# 140 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_27, FIELD_PIC_BIDOOF_NORMAL
# 141 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_28, FIELD_PIC_WINGULL, MSGBOX_YESNO
# 142 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq WingullHouseBetweenCavesInUnderwater_CallWingull_16
# 146 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_31, FIELD_PIC_WINGULL
WingullHouseBetweenCavesInUnderwater_CallWingull_15:
# 148 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_32, FIELD_PIC_WINGULL
# 149 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 150 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_0x8004, 2
# 151 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	fadescreen FADE_TO_BLACK
# 152 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	special DoBerryBlending
# 153 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitstate
# 154 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	playbgm MUS_LINK_CONTEST_P1, FALSE
# 155 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative BerryBlenderGetLostCount
# 156 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	switch VAR_RESULT
# 157 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 0, WingullHouseBetweenCavesInUnderwater_CallWingull_21
# 158 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 1, WingullHouseBetweenCavesInUnderwater_CallWingull_22
# 159 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 2, WingullHouseBetweenCavesInUnderwater_CallWingull_23
# 160 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 3, WingullHouseBetweenCavesInUnderwater_CallWingull_24
# 161 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 4, WingullHouseBetweenCavesInUnderwater_CallWingull_25
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 5, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 6, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 7, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 8, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 9, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 10, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 11, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 12, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	case 13, WingullHouseBetweenCavesInUnderwater_CallWingull_26
# 163 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_39, FIELD_PIC_WINGULL
WingullHouseBetweenCavesInUnderwater_CallWingull_19:
# 165 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	message WingullHouseBetweenCavesInUnderwater_CallWingull_Text_40
# 166 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 167 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 168 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_BADGE01_GET
# 169 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_WINGULL_BLENDER_BEATEN
# 170 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_41, FIELD_PIC_WINGULL
# 171 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_42, FIELD_PIC_BIDOOF_NORMAL
# 172 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_43, FIELD_PIC_BIDOOF_ASTONISHED
# 173 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_44, FIELD_PIC_WINGULL
# 174 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_45, FIELD_PIC_BIDOOF_ASTONISHED
# 175 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_46, FIELD_PIC_WINGULL
# 176 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 177 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 1, MovementOneDown
# 178 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setmetatile 2, 2, 0x221, FALSE
# 179 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setmetatile 2, 3, 0x2DD, TRUE
# 180 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxy 3, 13, 0
# 181 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxy 4, 2, 3
# 182 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setobjectxyperm 4, 2, 3
# 183 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	special DrawWholeMapView
# 184 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 185 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_47, FIELD_PIC_WINGULL
# 186 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 1, MovementWingullFromBlender
# 187 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_48, FIELD_PIC_BIDOOF_NORMAL
# 188 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmessage
# 189 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	closemessage
# 190 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 191 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement 2, MovementBidoofLeft
# 192 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 193 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_BIDOOF_FOLLOWER
# 194 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	callnative UpdateFollowingPokemon
# 195 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	removeobject 2
# 196 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MovementPlayerFaceUp_WingullHouse
# 197 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	waitmovement 0
# 198 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay 2
# 199 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 6
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_1

WingullHouseBetweenCavesInUnderwater_CallWingull_8:
# 205 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_49, FIELD_PIC_WINGULL
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_1

WingullHouseBetweenCavesInUnderwater_CallWingull_9:
# 207 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_50, FIELD_PIC_WINGULL
# 208 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	setflag FLAG_WINGULL_COMMENTARY_HIKER
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_1

WingullHouseBetweenCavesInUnderwater_CallWingull_11:
# 206 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	goto_if_unset FLAG_WINGULL_COMMENTARY_HIKER, WingullHouseBetweenCavesInUnderwater_CallWingull_9
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_10

WingullHouseBetweenCavesInUnderwater_CallWingull_16:
# 143 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_29, FIELD_PIC_WINGULL
# 144 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_30, FIELD_PIC_BIDOOF_ASTONISHED
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_15

WingullHouseBetweenCavesInUnderwater_CallWingull_21:
# 157 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_33, FIELD_PIC_WINGULL
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_19

WingullHouseBetweenCavesInUnderwater_CallWingull_22:
# 158 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_34, FIELD_PIC_WINGULL
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_19

WingullHouseBetweenCavesInUnderwater_CallWingull_23:
# 159 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_35, FIELD_PIC_WINGULL
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_19

WingullHouseBetweenCavesInUnderwater_CallWingull_24:
# 160 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_36, FIELD_PIC_WINGULL
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_19

WingullHouseBetweenCavesInUnderwater_CallWingull_25:
# 161 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_37, FIELD_PIC_WINGULL
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_19

WingullHouseBetweenCavesInUnderwater_CallWingull_26:
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox_portrait WingullHouseBetweenCavesInUnderwater_CallWingull_Text_38, FIELD_PIC_WINGULL
	goto WingullHouseBetweenCavesInUnderwater_CallWingull_19


# 218 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementPlayerFaceUp_WingullHouse:
# 219 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_down
# 220 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_up
# 221 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 224 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementBidoofLeft:
# 225 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 226 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 227 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 228 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 231 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementWingullFromBlender:
# 232 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 233 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 234 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 235 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 236 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_right
# 237 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 238 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 239 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 240 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 243 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementOneDown:
# 244 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_down
# 245 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 248 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderWingull:
# 249 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 250 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 251 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 252 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 253 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 254 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 255 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 256 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 259 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderPlayer:
# 260 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 261 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 262 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 263 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 264 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 265 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 266 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 267 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 268 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 269 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 270 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_right
# 271 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 274 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
MovementToBlenderBidoof:
# 275 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 276 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	delay_16
# 277 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 278 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 279 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 280 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 281 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_left
# 282 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 283 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 284 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_left
# 285 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine::
# 289 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	lockall
# 290 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	msgbox WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine_Text_0
# 291 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	releaseall
	end


# 295 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_LookDown:
# 296 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 297 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 300 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_Up:
# 301 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	walk_up
# 302 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_down
# 303 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

# 306 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
Movement_LookUpWingull:
# 307 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	face_up
# 308 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	step_end

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_0:
# 26 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Whew, we did it!\p"
	.string "Nice thinking with the rock-switch,\n"
	.string "{PLAYER}!$"

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_1:
# 27 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Though…We were underwater and now\n"
	.string "we're inside…a house? Talk about\l"
	.string "ambient change. This whole area is so\l"
	.string "messed up, {PLAYER}. It could be some\l"
	.string "sort of illusion, or even a spell. I'm not\l"
	.string "exactly sure.$"

WingullHouseBetweenCavesInUnderwater_WeMadeit_Text_2:
# 28 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "In any case, let's explore and continue\n"
	.string "forward.$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_0:
# 38 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "There's a Bell.\nRing it?$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_1:
# 40 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "The Bell is broken.$"

WingullHouseBetweenCavesInUnderwater_BellNotWorking_Text_2:
# 42 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You left the bell untouched.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_0:
# 53 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "{PLAYER} rang the bell.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_1:
# 61 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hmm…Let's try again.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_2:
# 67 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You know, I would expect something to\n"
	.string "happen.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_3:
# 72 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "{PLAYER}!\p"
	.string "Golly, it got dark all of a sudden!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_4:
# 80 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Did you hear that?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_5:
# 84 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "WHO?!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_6:
# 87 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Who is it…$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_7:
# 90 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "SPEAK!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_8:
# 92 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "We didn't want to disturb you, I swear!\n"
	.string "We actually want to leave!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_9:
# 94 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "W{PAUSE 30}A{PAUSE 30}I{PAUSE 30}T!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_10:
# 96 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "I can't let you {PAUSE 20}go that easily…$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_11:
# 98 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_12:
# 100 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "T{PAUSE 10}u{PAUSE 20}r{PAUSE 30}n a{PAUSE 25}r{PAUSE 28}o{PAUSE 22}u{PAUSE 22}n{PAUSE 22}d.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_13:
# 110 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hey y'all! I'm Wingull!\nWingull, the gull!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_14:
# 111 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "…\pReally?\lTalk about anticlamatic…$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_15:
# 112 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hmm? You were sayin'?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_16:
# 113 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly, no! Nothing!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_17:
# 114 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Welcome in my humble domain!\n"
	.string "The rules are simple: if you wish to\l"
	.string "pass, you'll need to defeat me in a duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_18:
# 115 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Duel?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_19:
# 116 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Yes! It's time to du-du-du-duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_20:
# 121 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hey!\nLet me finish first!\pWe'll have a…\la…\la…\la…\la…\la…\la…\la…$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_21:
# 122 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Oh come on!\nSpit it out already!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_22:
# 124 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "As I was saying!\pWe'll have a…\lBerry Blending duel!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_23:
# 128 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Right, exactly what I had in mind…$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_24:
# 129 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Follow me!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_25:
# 135 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Alright! There's three of us, so that's\n"
	.string "even better. I was hoping for a quartet,\l"
	.string "but whatever.\l"
	.string "THE RULES!\l"
	.string "The rules are fairly simple, you just\l"
	.string "need the right equipment. Which you are\l"
	.string "missing, but fear not! I have a spare\l"
	.string "Pokeblock Case and some berries. Here!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_26:
# 139 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Now we're ready!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_27:
# 140 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "What about the rules?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_28:
# 141 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Rules? You want me to explain\nthe rules?$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_29:
# 143 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Well, ugh…\n"
	.string "You throw a Berry and then the thing\l"
	.string "spins…I'm sure you'll quickly get the\l"
	.string "hang of it!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_30:
# 144 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "For sure…$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_31:
# 146 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Yeah, I'm sure you already know them!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_32:
# 148 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Let's go!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_33:
# 157 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Wow! You beat me on the first try!\n"
	.string "You're like a Berry Blending Master!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_34:
# 158 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Wow, you're pretty good! It only took\n"
	.string "you 2 attempts to beat me!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_35:
# 159 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You're good, I'll give you that!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_36:
# 160 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "It took you 4 tries, but you've got it.\n"
	.string "Grats!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_37:
# 161 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You got me, not bad!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_38:
# 162 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You did it champ! It took you long\n"
	.string "enough, but you beat me fair and\l"
	.string "square.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_39:
# 163 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Well…Every streak has to end, mine too!\n"
	.string "As for you, I fell like you'll have\l"
	.string "enough Berry Blending for quite some\l"
	.string "time, haha!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_40:
# 165 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "{PLAYER} received the Blender Badge\nfrom Wingull.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_41:
# 170 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "You earned it, champ!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_42:
# 171 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Oh, I see {PLAYER}!\n"
	.string "If things were normal, you would've\l"
	.string "received a Badge only after beating a\l"
	.string "Gym leader! I believe there are 8 Gym\l"
	.string "Leaders you need to beat, before\l"
	.string "facing the ultimate challenge. Or\l"
	.string "something similar, I'm not 100% sure.\l"
	.string "…\l"
	.string "Given the actual state of affairs here,\l"
	.string "you'll probably obtain the badges in\l"
	.string "other, weirder ways, just like here with\l"
	.string "Wingull.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_43:
# 172 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Golly! I struggle to think what the next\n"
	.string "'Gym Leader' will be like!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_44:
# 173 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "That's how things work here in the\n"
	.string "Underwater.\l"
	.string "Though, Bidoof. Out of everyone, you\l"
	.string "should've known that already.\l"
	.string "After all…$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_45:
# 174 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "What are you even talking about!?\n"
	.string "Whatever, {PLAYER} won, which means\l"
	.string "we can leave.$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_46:
# 175 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "I was hoping you'd stay here for a bit\n"
	.string "longer! But it's fine! Let me move this\l"
	.string "thing…$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_47:
# 185 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Much better!\p"
	.string "I'm not going anywhere, so if you need\n"
	.string "something, just let me know!\l"
	.string "Smell ya later!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_48:
# 187 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Alright, {PLAYER}! Let's get out of\n"
	.string "here!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_49:
# 205 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Thanks for playing with me! I'm sure\n"
	.string "we'll see each other again!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_50:
# 207 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "I see you've beaten that Hiker asshole!\n"
	.string "Nicely done. Seriously, screw him.\p"
	.string "Thanks for stepping by and sharing the\n"
	.string "news with me!$"

WingullHouseBetweenCavesInUnderwater_CallWingull_Text_51:
# 211 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "Hey guys! Nice to see you again!$"

WingullHouseBetweenCavesInUnderwater_BerryBlenderMachine_Text_0:
# 290 "data/maps/WingullHouseBetweenCavesInUnderwater/scripts.pory"
	.string "It's a Berry Blender.\nIt can't be used at the moment.$"
