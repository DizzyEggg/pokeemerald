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
	getbyte gBattleOutcome, VAR_RESULT
# 48 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq SecondChallengeRoom_HikerBattle_2
# 71 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_HikerBattle_Text_5
# 72 "data/maps/SecondChallengeRoom/scripts.pory"
	setflag FLAG_HIKER_CHALLENGE_DONE
SecondChallengeRoom_HikerBattle_1:
# 74 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end

SecondChallengeRoom_HikerBattle_2:
# 49 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_HikerBattle_Text_0
# 50 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_HikerBattle_Text_1
# 51 "data/maps/SecondChallengeRoom/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 52 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_pic SecondChallengeRoom_HikerBattle_Text_2, VAR_0x8008
# 53 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_pic SecondChallengeRoom_HikerBattle_Text_3, VAR_0x8008
# 54 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 55 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 56 "data/maps/SecondChallengeRoom/scripts.pory"
	special HealPlayerParty
# 57 "data/maps/SecondChallengeRoom/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 58 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, 7
	goto_if_eq SecondChallengeRoom_HikerBattle_12
SecondChallengeRoom_HikerBattle_10:
# 60 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, 5
	goto_if_eq SecondChallengeRoom_HikerBattle_9
SecondChallengeRoom_HikerBattle_8:
# 63 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerToNurse1
SecondChallengeRoom_HikerBattle_5:
# 65 "data/maps/SecondChallengeRoom/scripts.pory"
	delay 10
# 66 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 67 "data/maps/SecondChallengeRoom/scripts.pory"
	playfanfare FANFARE_HEAL
# 68 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_pic SecondChallengeRoom_HikerBattle_Text_4, VAR_0x8008
# 69 "data/maps/SecondChallengeRoom/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
	goto SecondChallengeRoom_HikerBattle_1

SecondChallengeRoom_HikerBattle_6:
# 59 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerToNurse3
	goto SecondChallengeRoom_HikerBattle_5

SecondChallengeRoom_HikerBattle_7:
# 61 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerToNurse2
	goto SecondChallengeRoom_HikerBattle_5

SecondChallengeRoom_HikerBattle_9:
# 60 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8005, 4
	goto_if_eq SecondChallengeRoom_HikerBattle_7
	goto SecondChallengeRoom_HikerBattle_8

SecondChallengeRoom_HikerBattle_12:
# 58 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8005, 4
	goto_if_eq SecondChallengeRoom_HikerBattle_6
	goto SecondChallengeRoom_HikerBattle_10


# 78 "data/maps/SecondChallengeRoom/scripts.pory"
Movement_PlayerToNurse1:
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 80 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_right
# 81 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 81 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 81 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 82 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 82 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 82 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 83 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_up
# 84 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 84 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 85 "data/maps/SecondChallengeRoom/scripts.pory"
	step_end

# 88 "data/maps/SecondChallengeRoom/scripts.pory"
Movement_PlayerToNurse2:
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 89 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 90 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_right
# 90 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_right
# 91 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 91 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 91 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 92 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 92 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 92 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 93 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_up
# 94 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 94 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 95 "data/maps/SecondChallengeRoom/scripts.pory"
	step_end

# 98 "data/maps/SecondChallengeRoom/scripts.pory"
Movement_PlayerToNurse3:
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 100 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 100 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 100 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 101 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_up
# 102 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 102 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 103 "data/maps/SecondChallengeRoom/scripts.pory"
	step_end

SecondChallengeRoom_FirstBidoofMsg::
# 107 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 108 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Up
# 109 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 110 "data/maps/SecondChallengeRoom/scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 33, 107, VAR_0x8008
# 111 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_FirstBidoofMsg_Text_0
# 112 "data/maps/SecondChallengeRoom/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 9
# 113 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 114 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 115 "data/maps/SecondChallengeRoom/scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL, VAR_0x8008
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_NurseJoy::
# 121 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 122 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 123 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_NurseJoy_Text_0
# 124 "data/maps/SecondChallengeRoom/scripts.pory"
	playfanfare FANFARE_HEAL
# 125 "data/maps/SecondChallengeRoom/scripts.pory"
	special HealPlayerParty
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement 2, Movement_PkmnCenterNurse_Bow
# 127 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 128 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 129 "data/maps/SecondChallengeRoom/scripts.pory"
	waitfanfare
# 130 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_MartGuy::
# 135 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 136 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 137 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MartGuy_Text_0
# 138 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 139 "data/maps/SecondChallengeRoom/scripts.pory"
	pokemart SecondChallengeRoom_Mart
# 140 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_MoveRelearner::
# 145 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 146 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 147 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MoveRelearner_Text_0
# 148 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 149 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 150 "data/maps/SecondChallengeRoom/scripts.pory"
SecondChallengeRoom_MoveRelearner_ChooseMon:
# 151 "data/maps/SecondChallengeRoom/scripts.pory"
	special ChooseMonForMoveRelearner
# 152 "data/maps/SecondChallengeRoom/scripts.pory"
	waitstate
# 153 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_ne SecondChallengeRoom_MoveRelearner_2
SecondChallengeRoom_MoveRelearner_1:
# 167 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end

SecondChallengeRoom_MoveRelearner_2:
# 154 "data/maps/SecondChallengeRoom/scripts.pory"
	special IsSelectedMonEgg
# 155 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SecondChallengeRoom_MoveRelearner_4
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_4:
# 156 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq SecondChallengeRoom_MoveRelearner_6
# 159 "data/maps/SecondChallengeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 160 "data/maps/SecondChallengeRoom/scripts.pory"
	waitstate
# 161 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq SecondChallengeRoom_MoveRelearner_9
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_6:
# 157 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MoveRelearner_Text_1
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_9:
# 162 "data/maps/SecondChallengeRoom/scripts.pory"
	goto SecondChallengeRoom_MoveRelearner_ChooseMon
	goto SecondChallengeRoom_MoveRelearner_1


	.align 2
# 171 "data/maps/SecondChallengeRoom/scripts.pory"
SecondChallengeRoom_Mart:
# 172 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_LUCKY_EGG
# 173 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_EXP_SHARE
# 174 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_POKE_BALL
# 175 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 176 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 177 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_LOVE_BALL
# 178 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 179 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 180 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FRIEND_BALL
# 181 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 182 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 183 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 184 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 185 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 186 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_POTION
# 187 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_PARLYZ_HEAL
# 188 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 189 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HEAL_POWDER
# 190 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ETHER
# 191 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ELIXIR
# 192 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 193 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HP_UP
# 194 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 195 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_X_DEFEND
# 196 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 197 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_BAND
# 198 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_SPECS
# 199 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_SCARF
# 200 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FLAME_ORB
# 201 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_TOXIC_ORB
# 202 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FOCUS_SASH
# 203 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 204 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 205 "data/maps/SecondChallengeRoom/scripts.pory"
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
	.string "Oh, it looks like it'll be simpler this\n"
	.string "time around then.$"

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

SecondChallengeRoom_HikerBattle_Text_0:
# 49 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "You lost, punk.$"

SecondChallengeRoom_HikerBattle_Text_1:
# 50 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "You need stronger Pokemon, if you want\n"
	.string "to defeat me.$"

SecondChallengeRoom_HikerBattle_Text_2:
# 52 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Ow...Don't worry, {PLAYER}! I'm sure\n"
	.string "you'll beat this guy. Look around the\l"
	.string "place, try to find new Pokemon and come\l"
	.string "with a better plan next time!$"

SecondChallengeRoom_HikerBattle_Text_3:
# 53 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "For now, let's get your Party members\n"
	.string "healed.$"

SecondChallengeRoom_HikerBattle_Text_4:
# 68 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'll give you a tip, {PLAYER}. Check\n"
	.string "out the area south from here. I'm sure\l"
	.string "you'll be be able to train and catch new\l"
	.string "Pokemon there. Courage!$"

SecondChallengeRoom_HikerBattle_Text_5:
# 71 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "NANI?!$"

SecondChallengeRoom_FirstBidoofMsg_Text_0:
# 111 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Looks like we've entered another\n"
	.string "transition cave. And this time, it is\l"
	.string "actually a cave. Let's keep our eyes\l"
	.string "open. Who knows what we'll find here.$"

SecondChallengeRoom_NurseJoy_Text_0:
# 123 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'll heal your Pokemon.$"

SecondChallengeRoom_MartGuy_Text_0:
# 137 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I sell items.$"

SecondChallengeRoom_MoveRelearner_Text_0:
# 147 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'm the Move Reminder.\p$"

SecondChallengeRoom_MoveRelearner_Text_1:
# 157 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "This Pokemon cannot learn anything.$"
