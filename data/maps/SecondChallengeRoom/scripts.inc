SecondChallengeRoom_MapScripts::
# 2 "data/maps/SecondChallengeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SecondChallengeRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 9 "data/maps/SecondChallengeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecondChallengeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SecondChallengeRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/SecondChallengeRoom/scripts.pory"
	goto_if_unset FLAG_HIKER_CHALLENGE_DONE, SecondChallengeRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SecondChallengeRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/SecondChallengeRoom/scripts.pory"
	setobjectxyperm 1, 6, 4
# 5 "data/maps/SecondChallengeRoom/scripts.pory"
	turnobject 1, DIR_SOUTH
	return

SecondChallengeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/SecondChallengeRoom/scripts.pory"
	map_script_2 VAR_HACK_GAME_STATE, 8, SecondChallengeRoom_FirstBidoofMsg
	.2byte 0


SecondChallengeRoom_Hiker::
# 15 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 16 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 17 "data/maps/SecondChallengeRoom/scripts.pory"
	goto_if_unset FLAG_HIKER_CHALLENGE_DONE, SecondChallengeRoom_Hiker_2
# 39 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_Hiker_Text_7
SecondChallengeRoom_Hiker_1:
# 41 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end

SecondChallengeRoom_Hiker_2:
# 18 "data/maps/SecondChallengeRoom/scripts.pory"
	goto_if_unset FLAG_HIKER_FIRST_ENCOUNTER_DONE, SecondChallengeRoom_Hiker_5
# 31 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_Hiker_Text_5
# 32 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_Hiker_Text_6, MSGBOX_YESNO
# 33 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SecondChallengeRoom_Hiker_8
	goto SecondChallengeRoom_Hiker_1

SecondChallengeRoom_Hiker_5:
# 19 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_Hiker_Text_0
# 20 "data/maps/SecondChallengeRoom/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 21 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_pic SecondChallengeRoom_Hiker_Text_1, VAR_0x8008
# 22 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_Hiker_Text_2
# 23 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_pic SecondChallengeRoom_Hiker_Text_3, VAR_0x8008
# 24 "data/maps/SecondChallengeRoom/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_SMIRKY, 33, 107, VAR_0x800A
# 25 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_pic SecondChallengeRoom_Hiker_Text_4, VAR_0x800A
# 26 "data/maps/SecondChallengeRoom/scripts.pory"
	setflag FLAG_HIKER_FIRST_ENCOUNTER_DONE
# 27 "data/maps/SecondChallengeRoom/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 28 "data/maps/SecondChallengeRoom/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_SMIRKY, VAR_0x800A
# 29 "data/maps/SecondChallengeRoom/scripts.pory"
	goto SecondChallengeRoom_HikerBattle
	goto SecondChallengeRoom_Hiker_1

SecondChallengeRoom_Hiker_8:
# 34 "data/maps/SecondChallengeRoom/scripts.pory"
	goto SecondChallengeRoom_HikerBattle
	goto SecondChallengeRoom_Hiker_1


SecondChallengeRoom_HikerBattle::
# 46 "data/maps/SecondChallengeRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_HIKER_CHALLENGE, 0
# 47 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_FirstBidoofMsg::
# 52 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 53 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Up
# 54 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 55 "data/maps/SecondChallengeRoom/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 56 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_FirstBidoofMsg_Text_0
# 57 "data/maps/SecondChallengeRoom/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 9
# 58 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 59 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 60 "data/maps/SecondChallengeRoom/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 61 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_NurseJoy::
# 66 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 67 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 68 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_NurseJoy_Text_0
# 69 "data/maps/SecondChallengeRoom/scripts.pory"
	playfanfare FANFARE_HEAL
# 70 "data/maps/SecondChallengeRoom/scripts.pory"
	special HealPlayerParty
# 71 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement 2, Movement_PkmnCenterNurse_Bow
# 72 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 73 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 74 "data/maps/SecondChallengeRoom/scripts.pory"
	waitfanfare
# 75 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_MartGuy::
# 80 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 81 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 82 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MartGuy_Text_0
# 83 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 84 "data/maps/SecondChallengeRoom/scripts.pory"
	pokemart SecondChallengeRoom_Mart
# 85 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_MoveRelearner::
# 90 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 91 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 92 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MoveRelearner_Text_0
# 93 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 94 "data/maps/SecondChallengeRoom/scripts.pory"
SecondChallengeRoom_MoveRelearner_ChooseMon:
# 95 "data/maps/SecondChallengeRoom/scripts.pory"
	special ChooseMonForMoveRelearner
# 96 "data/maps/SecondChallengeRoom/scripts.pory"
	waitstate
# 97 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_ne SecondChallengeRoom_MoveRelearner_2
SecondChallengeRoom_MoveRelearner_1:
# 111 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end

SecondChallengeRoom_MoveRelearner_2:
# 98 "data/maps/SecondChallengeRoom/scripts.pory"
	special IsSelectedMonEgg
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SecondChallengeRoom_MoveRelearner_4
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_4:
# 100 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq SecondChallengeRoom_MoveRelearner_6
# 103 "data/maps/SecondChallengeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 104 "data/maps/SecondChallengeRoom/scripts.pory"
	waitstate
# 105 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq SecondChallengeRoom_MoveRelearner_9
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_6:
# 101 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MoveRelearner_Text_1
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_9:
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	goto SecondChallengeRoom_MoveRelearner_ChooseMon
	goto SecondChallengeRoom_MoveRelearner_1


	.align 2
# 115 "data/maps/SecondChallengeRoom/scripts.pory"
SecondChallengeRoom_Mart:
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_POKE_BALL
# 117 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 118 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 119 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_LOVE_BALL
# 120 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 121 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 122 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FRIEND_BALL
# 123 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 124 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 125 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 127 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 128 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_POTION
# 129 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_PARLYZ_HEAL
# 130 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 131 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HEAL_POWDER
# 132 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ETHER
# 133 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ELIXIR
# 134 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 135 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HP_UP
# 136 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 137 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_X_DEFEND
# 138 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 139 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_BAND
# 140 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_SPECS
# 141 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_SCARF
# 142 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FLAME_ORB
# 143 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_TOXIC_ORB
# 144 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FOCUS_SASH
# 145 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ZOOM_LENS
	.2byte ITEM_NONE

SecondChallengeRoom_Hiker_Text_0:
# 19 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Yo. Listen, I'll make it short for all of\n"
	.string "us. As you may have already guessed, I\l"
	.string "am the second leader here. And I can't\l"
	.string "let you pass, until you beat me. I hope\l"
	.string "I've made myself clear.$"

SecondChallengeRoom_Hiker_Text_1:
# 21 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Be careful {PLAYER}. We don't know\n"
	.string "what we'll need to do in order to get\l"
	.string "past him.$"

SecondChallengeRoom_Hiker_Text_2:
# 22 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "You just need to beat me in a battle,\n"
	.string "pal. Simple as that.$"

SecondChallengeRoom_Hiker_Text_3:
# 23 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Looks like it'll be simpler this time\n"
	.string "around.$"

SecondChallengeRoom_Hiker_Text_4:
# 25 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Let's beat this guy, {PLAYER}!$"

SecondChallengeRoom_Hiker_Text_5:
# 31 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "It's you again.$"

SecondChallengeRoom_Hiker_Text_6:
# 32 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "You wanna try one more time?$"

SecondChallengeRoom_Hiker_Text_7:
# 39 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Good luck on your journey, you'll need\n"
	.string "it.$"

SecondChallengeRoom_FirstBidoofMsg_Text_0:
# 56 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Looks like we've entered another\n"
	.string "transition cave. And this time, it is\l"
	.string "actually a cave. Let's keep our eyes\l"
	.string "open. Who knows what we'll find here.$"

SecondChallengeRoom_NurseJoy_Text_0:
# 68 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'll heal your Pokemon.$"

SecondChallengeRoom_MartGuy_Text_0:
# 82 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I sell items.$"

SecondChallengeRoom_MoveRelearner_Text_0:
# 92 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'm the Move Reminder.$"

SecondChallengeRoom_MoveRelearner_Text_1:
# 101 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "This Pokemon cannot learn anything.$"
