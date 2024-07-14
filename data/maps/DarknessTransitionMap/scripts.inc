DarknessTransitionMap_MapScripts::
# 2 "data/maps/DarknessTransitionMap/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DarknessTransitionMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DarknessTransitionMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/DarknessTransitionMap/scripts.pory"
	map_script_2 VAR_HACK_GAME_STATE, 11, DarknessTransitionMap_FirstComment
	.2byte 0


DarknessTransitionMap_FirstComment::
# 8 "data/maps/DarknessTransitionMap/scripts.pory"
	lock
# 9 "data/maps/DarknessTransitionMap/scripts.pory"
	msgbox_portrait DarknessTransitionMap_FirstComment_Text_0, FIELD_PIC_BIDOOF_ASTONISHED
# 10 "data/maps/DarknessTransitionMap/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 12
# 11 "data/maps/DarknessTransitionMap/scripts.pory"
	release
	end


DarknessTransitionMap_FirstComment_Text_0:
# 9 "data/maps/DarknessTransitionMap/scripts.pory"
	.string "Wow...\p"
	.string "Suicune wasn't joking around! This\n"
	.string "place...\p"
	.string "Let's go upwards, maybe we'll find some\n"
	.string "sort of exit there. I mean, assuming\l"
	.string "there is any 'up' here!$"
