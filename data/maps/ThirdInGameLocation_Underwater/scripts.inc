ThirdInGameLocation_Underwater_MapScripts::
# 2 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ThirdInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return


ThirdInGameLocation_Underwater_BidoffTrigger1::
# 7 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 8 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playse SE_PIN
# 9 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HIDE_BIDOOF_1
# 10 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement 2, MovementBidoof1
# 11 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 12 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 16 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementBidoof1:
# 17 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	emote_double_exclamation_mark
# 18 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_16
# 19 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 20 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	face_right
# 21 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_8
# 22 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 23 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_right
# 24 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 25 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

ThirdInGameLocation_Underwater_CreepyHexManiac::
# 29 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	lock
# 30 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_LAST_TALKED, 1
# 31 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8004, RGB_WHITEALPHA
# 32 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 7
# 33 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 34 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac1
# 35 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 36 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setvar VAR_0x8005, 13
# 37 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	callnative BlendTalkingObj
# 38 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	playmoncry ADDED_SOUND_FEMALE_LAUGH_1, CRY_MODE_NORMAL
# 39 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	applymovement VAR_LAST_TALKED, MovementHexManiac2
# 40 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	waitmovement 0
# 41 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	setflag FLAG_HEX_MANIAC_GONE
# 42 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	release
	end


# 46 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac1:
# 47 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	jump_2_down
# 48 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_2
# 49 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 50 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_slow_down
# 51 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_slow_down
# 52 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_1
# 53 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end

# 56 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
MovementHexManiac2:
# 57 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 58 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_in_place_fast_down
# 59 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	delay_4
# 60 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 61 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 62 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	walk_faster_down
# 63 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	set_invisible
# 64 "data/maps/ThirdInGameLocation_Underwater/scripts.pory"
	step_end
