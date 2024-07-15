DarknessTransitionMap_MapScripts::
# 2 "data/maps/DarknessTransitionMap/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DarknessTransitionMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DarknessTransitionMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/DarknessTransitionMap/scripts.pory"
	map_script_2 VAR_HACK_GAME_STATE, 11, DarknessTransitionMap_FirstComment
	.2byte 0


DarknessTransitionMap_GameSave::
# 8 "data/maps/DarknessTransitionMap/scripts.pory"
	lock
# 9 "data/maps/DarknessTransitionMap/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 13
# 10 "data/maps/DarknessTransitionMap/scripts.pory"
	callnative ScrCmd_SaveGame
# 11 "data/maps/DarknessTransitionMap/scripts.pory"
	callnative GlitchScreen
# 12 "data/maps/DarknessTransitionMap/scripts.pory"
	callnative GlitchSound
# 13 "data/maps/DarknessTransitionMap/scripts.pory"
	delay 1
# 14 "data/maps/DarknessTransitionMap/scripts.pory"
	callnative DoSoftReset
# 15 "data/maps/DarknessTransitionMap/scripts.pory"
	release
	end


DarknessTransitionMap_FirstComment::
# 20 "data/maps/DarknessTransitionMap/scripts.pory"
	lock
# 21 "data/maps/DarknessTransitionMap/scripts.pory"
	msgbox_portrait DarknessTransitionMap_FirstComment_Text_0, FIELD_PIC_BIDOOF_ASTONISHED
# 22 "data/maps/DarknessTransitionMap/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 12
# 23 "data/maps/DarknessTransitionMap/scripts.pory"
	release
	end


DarknessTransitionMap_FourthLeader::
# 28 "data/maps/DarknessTransitionMap/scripts.pory"
	lock
# 29 "data/maps/DarknessTransitionMap/scripts.pory"
	msgbox DarknessTransitionMap_FourthLeader_Text_0
# 30 "data/maps/DarknessTransitionMap/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 31 "data/maps/DarknessTransitionMap/scripts.pory"
	setvar VAR_0x8005, 14
# 32 "data/maps/DarknessTransitionMap/scripts.pory"
	callnative BlendTalkingObj
# 33 "data/maps/DarknessTransitionMap/scripts.pory"
	message DarknessTransitionMap_FourthLeader_Text_1
# 34 "data/maps/DarknessTransitionMap/scripts.pory"
	waitmessage
# 35 "data/maps/DarknessTransitionMap/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 36 "data/maps/DarknessTransitionMap/scripts.pory"
	setflag FLAG_BADGE04_GET
# 37 "data/maps/DarknessTransitionMap/scripts.pory"
	setflag FLAG_HIDE_GLITCH_4TH
# 38 "data/maps/DarknessTransitionMap/scripts.pory"
	removeobject 1
# 39 "data/maps/DarknessTransitionMap/scripts.pory"
	msgbox_portrait DarknessTransitionMap_FourthLeader_Text_2, FIELD_PIC_BIDOOF_ASTONISHED
# 40 "data/maps/DarknessTransitionMap/scripts.pory"
	release
	end


DarknessTransitionMap_FirstComment_Text_0:
# 21 "data/maps/DarknessTransitionMap/scripts.pory"
	.string "Wow...\p"
	.string "Suicune wasn't joking around! This\n"
	.string "place...\p"
	.string "Let's go upwards, maybe we'll find some\n"
	.string "sort of exit there. I mean, assuming\l"
	.string "there is any 'up' here!$"

DarknessTransitionMap_FourthLeader_Text_0:
# 29 "data/maps/DarknessTransitionMap/scripts.pory"
	.string "I am the fourth???\pTo defffeatme? you neeeeed t0 defffeat mee?$"

DarknessTransitionMap_FourthLeader_Text_1:
# 33 "data/maps/DarknessTransitionMap/scripts.pory"
	.string "HELP ME{FILL_WINDOW}{PLAYER} r-?-d the RGFya25lc3M= Badge.$"

DarknessTransitionMap_FourthLeader_Text_2:
# 39 "data/maps/DarknessTransitionMap/scripts.pory"
	.string "What...what did just happen???\p"
	.string "Did-did you just get the fourth Badge?\n"
	.string "I guess there was no challenge this\l"
	.string "time around...\p"
	.string "Golly, this place is giving me the\n"
	.string "creeps!$"
