SecondChallengeRoom_MapScripts::
# 2 "data/maps/SecondChallengeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecondChallengeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SecondChallengeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/SecondChallengeRoom/scripts.pory"
	map_script_2 VAR_HACK_GAME_STATE, 8, SecondChallengeRoom_FirstBidoofMsg
	.2byte 0


SecondChallengeRoom_FirstBidoofMsg::
# 8 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 9 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Up
# 10 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 11 "data/maps/SecondChallengeRoom/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 12 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_FirstBidoofMsg_Text_0
# 13 "data/maps/SecondChallengeRoom/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 9
# 14 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 15 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 16 "data/maps/SecondChallengeRoom/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 17 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_NurseJoy::
# 22 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 23 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 24 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_NurseJoy_Text_0
# 25 "data/maps/SecondChallengeRoom/scripts.pory"
	playfanfare FANFARE_HEAL
# 26 "data/maps/SecondChallengeRoom/scripts.pory"
	special HealPlayerParty
# 27 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement 2, Movement_PkmnCenterNurse_Bow
# 28 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 29 "data/maps/SecondChallengeRoom/scripts.pory"
	waitfanfare
# 30 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_FirstBidoofMsg_Text_0:
# 12 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Looks like we've entered another\n"
	.string "transition cave. And this time, it is\l"
	.string "actually a cave. Let's keep our eyes\l"
	.string "open. Who knows what we'll find here.$"

SecondChallengeRoom_NurseJoy_Text_0:
# 24 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'll heal your Pokemon.$"
