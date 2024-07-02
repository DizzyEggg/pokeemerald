SecondInGameLocation_Underwater_MapScripts::
# 2 "data/maps/SecondInGameLocation_Underwater/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SecondInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SecondInGameLocation_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/SecondInGameLocation_Underwater/scripts.pory"
	setflag FLAG_LEFT_FIRST_AREA
	return


SecondInGameLocation_Underwater_FirstWildBattle::
# 8 "data/maps/SecondInGameLocation_Underwater/scripts.pory"
	lockall
# 9 "data/maps/SecondInGameLocation_Underwater/scripts.pory"
	setwildbattle SPECIES_BIDOOF, 5
# 10 "data/maps/SecondInGameLocation_Underwater/scripts.pory"
	dowildbattle
# 11 "data/maps/SecondInGameLocation_Underwater/scripts.pory"
	addvar VAR_HACK_GAME_STATE, 1
# 12 "data/maps/SecondInGameLocation_Underwater/scripts.pory"
	releaseall
	end

