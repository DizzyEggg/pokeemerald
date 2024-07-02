ThirdInGameLocation_Underwater_MapScripts::
# 2 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return


ThirdInGameLocation_Underwater_CreepyHexManiac::
# 7 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 8 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 9 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 10 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 11 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 12 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 13 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 14 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 15 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 16 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 17 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 18 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 19 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 20 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 24 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 26 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 27 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 28 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 29 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 30 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 40 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end
