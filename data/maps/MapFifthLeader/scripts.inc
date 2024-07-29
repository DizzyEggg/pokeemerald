MapFifthLeader_MapScripts::
	.byte 0


Script_HackFifthLeader::
# 4 "data/maps/MapFifthLeader/scripts.pory"
	lockall
# 5 "data/maps/MapFifthLeader/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_OTHER
# 6 "data/maps/MapFifthLeader/scripts.pory"
	special DoPCTurnOnEffect
# 7 "data/maps/MapFifthLeader/scripts.pory"
	playse SE_PC_ON
# 8 "data/maps/MapFifthLeader/scripts.pory"
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
# 9 "data/maps/MapFifthLeader/scripts.pory"
	msgbox Script_HackFifthLeader_Text_0
# 10 "data/maps/MapFifthLeader/scripts.pory"
	releaseall
	end


Script_HackFifthLeader_Text_0:
# 9 "data/maps/MapFifthLeader/scripts.pory"
	.string "...\pHey! Don't turn me on like that!$"
