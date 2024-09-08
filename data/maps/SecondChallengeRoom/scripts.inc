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
# 34 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_Hiker_Text_6, FIELD_PIC_HIKER
SecondChallengeRoom_Hiker_1:
# 36 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end

SecondChallengeRoom_Hiker_2:
# 18 "data/maps/SecondChallengeRoom/scripts.pory"
	goto_if_unset FLAG_HIKER_FIRST_ENCOUNTER_DONE, SecondChallengeRoom_Hiker_5
# 27 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_Hiker_Text_5, FIELD_PIC_HIKER, MSGBOX_YESNO
# 28 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SecondChallengeRoom_Hiker_8
	goto SecondChallengeRoom_Hiker_1

SecondChallengeRoom_Hiker_5:
# 19 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_Hiker_Text_0, FIELD_PIC_HIKER
# 20 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_Hiker_Text_1, FIELD_PIC_BIDOOF_NORMAL
# 21 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_Hiker_Text_2, FIELD_PIC_HIKER
# 22 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_Hiker_Text_3, FIELD_PIC_BIDOOF_NORMAL
# 23 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_Hiker_Text_4, FIELD_PIC_BIDOOF_SMIRKY
# 24 "data/maps/SecondChallengeRoom/scripts.pory"
	setflag FLAG_HIKER_FIRST_ENCOUNTER_DONE
# 25 "data/maps/SecondChallengeRoom/scripts.pory"
	goto SecondChallengeRoom_HikerBattle
	goto SecondChallengeRoom_Hiker_1

SecondChallengeRoom_Hiker_8:
# 29 "data/maps/SecondChallengeRoom/scripts.pory"
	goto SecondChallengeRoom_HikerBattle
	goto SecondChallengeRoom_Hiker_1


SecondChallengeRoom_HikerBattle::
# 41 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 42 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 43 "data/maps/SecondChallengeRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_HIKER_CHALLENGE, 0
# 44 "data/maps/SecondChallengeRoom/scripts.pory"
	getbyte gBattleOutcome, VAR_RESULT
# 45 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq SecondChallengeRoom_HikerBattle_2
# 64 "data/maps/SecondChallengeRoom/scripts.pory"
	setflag FLAG_HIDE_SUICUNE
# 65 "data/maps/SecondChallengeRoom/scripts.pory"
	setflag FLAG_HIKER_CHALLENGE_DONE
# 66 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_HikerBattle_Text_3, FIELD_PIC_HIKER
# 67 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_HikerBattle_Text_4
# 68 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 69 "data/maps/SecondChallengeRoom/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 70 "data/maps/SecondChallengeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 71 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_HikerBattle_Text_5, FIELD_PIC_HIKER
# 72 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 73 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 74 "data/maps/SecondChallengeRoom/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 75 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, 6
	goto_if_eq SecondChallengeRoom_HikerBattle_18
SecondChallengeRoom_HikerBattle_17:
# 79 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement 1, Movement_HikerNotBlocking
SecondChallengeRoom_HikerBattle_15:
# 81 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/SecondChallengeRoom/scripts.pory"
	setobjectxyperm 1, 4, 5
# 83 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_HikerBattle_Text_6, FIELD_PIC_BIDOOF_HAPPY
# 84 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_HikerBattle_Text_7, FIELD_PIC_BIDOOF_NORMAL
SecondChallengeRoom_HikerBattle_1:
# 86 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end

SecondChallengeRoom_HikerBattle_2:
# 46 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_HikerBattle_Text_0, FIELD_PIC_HIKER
# 47 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_HikerBattle_Text_1, FIELD_PIC_BIDOOF_NORMAL
# 48 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 49 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 50 "data/maps/SecondChallengeRoom/scripts.pory"
	special HealPlayerParty
# 51 "data/maps/SecondChallengeRoom/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 52 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, 7
	goto_if_eq SecondChallengeRoom_HikerBattle_12
SecondChallengeRoom_HikerBattle_10:
# 54 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, 5
	goto_if_eq SecondChallengeRoom_HikerBattle_9
SecondChallengeRoom_HikerBattle_8:
# 57 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerToNurse1
SecondChallengeRoom_HikerBattle_5:
# 59 "data/maps/SecondChallengeRoom/scripts.pory"
	delay 10
# 60 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 61 "data/maps/SecondChallengeRoom/scripts.pory"
	playfanfare FANFARE_HEAL
# 62 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_HikerBattle_Text_2, FIELD_PIC_BIDOOF_NORMAL
	goto SecondChallengeRoom_HikerBattle_1

SecondChallengeRoom_HikerBattle_6:
# 53 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerToNurse3
	goto SecondChallengeRoom_HikerBattle_5

SecondChallengeRoom_HikerBattle_7:
# 55 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerToNurse2
	goto SecondChallengeRoom_HikerBattle_5

SecondChallengeRoom_HikerBattle_9:
# 54 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8005, 4
	goto_if_eq SecondChallengeRoom_HikerBattle_7
	goto SecondChallengeRoom_HikerBattle_8

SecondChallengeRoom_HikerBattle_12:
# 52 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8005, 4
	goto_if_eq SecondChallengeRoom_HikerBattle_6
	goto SecondChallengeRoom_HikerBattle_10

SecondChallengeRoom_HikerBattle_16:
# 76 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement 1, Movement_HikerNotBlocking2
	goto SecondChallengeRoom_HikerBattle_15

SecondChallengeRoom_HikerBattle_18:
# 75 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8005, 5
	goto_if_eq SecondChallengeRoom_HikerBattle_16
	goto SecondChallengeRoom_HikerBattle_17


# 90 "data/maps/SecondChallengeRoom/scripts.pory"
Movement_HikerNotBlocking:
# 91 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 92 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 92 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 93 "data/maps/SecondChallengeRoom/scripts.pory"
	face_right
# 94 "data/maps/SecondChallengeRoom/scripts.pory"
	step_end

# 97 "data/maps/SecondChallengeRoom/scripts.pory"
Movement_HikerNotBlocking2:
# 98 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 99 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 100 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 101 "data/maps/SecondChallengeRoom/scripts.pory"
	face_right
# 102 "data/maps/SecondChallengeRoom/scripts.pory"
	step_end

# 105 "data/maps/SecondChallengeRoom/scripts.pory"
Movement_PlayerToNurse1:
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 106 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 107 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_right
# 108 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 108 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 108 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 109 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 109 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 109 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 110 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_up
# 111 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 111 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 112 "data/maps/SecondChallengeRoom/scripts.pory"
	step_end

# 115 "data/maps/SecondChallengeRoom/scripts.pory"
Movement_PlayerToNurse2:
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 116 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 117 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_right
# 117 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_right
# 118 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 118 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 118 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 119 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 119 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 119 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 120 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_up
# 121 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 121 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 122 "data/maps/SecondChallengeRoom/scripts.pory"
	step_end

# 125 "data/maps/SecondChallengeRoom/scripts.pory"
Movement_PlayerToNurse3:
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 126 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_down
# 127 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 127 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 127 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 128 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_up
# 129 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 129 "data/maps/SecondChallengeRoom/scripts.pory"
	walk_left
# 130 "data/maps/SecondChallengeRoom/scripts.pory"
	step_end

SecondChallengeRoom_FirstBidoofMsg::
# 134 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 135 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Up
# 136 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 137 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox_portrait SecondChallengeRoom_FirstBidoofMsg_Text_0, FIELD_PIC_BIDOOF_NORMAL
# 138 "data/maps/SecondChallengeRoom/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 9
# 139 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 140 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 141 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_NurseJoy::
# 146 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 147 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 148 "data/maps/SecondChallengeRoom/scripts.pory"
	msgbox SecondChallengeRoom_NurseJoy_Text_0
# 149 "data/maps/SecondChallengeRoom/scripts.pory"
	playfanfare FANFARE_HEAL
# 150 "data/maps/SecondChallengeRoom/scripts.pory"
	special HealPlayerParty
# 151 "data/maps/SecondChallengeRoom/scripts.pory"
	applymovement 2, Movement_PkmnCenterNurse_Bow
# 152 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmovement 0
# 153 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 154 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 155 "data/maps/SecondChallengeRoom/scripts.pory"
	waitfanfare
# 156 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_MartGuy::
# 161 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 162 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 163 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MartGuy_Text_0
# 164 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 165 "data/maps/SecondChallengeRoom/scripts.pory"
	pokemart SecondChallengeRoom_Mart
# 166 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end


SecondChallengeRoom_MoveRelearner::
# 171 "data/maps/SecondChallengeRoom/scripts.pory"
	lock
# 172 "data/maps/SecondChallengeRoom/scripts.pory"
	faceplayer
# 173 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MoveRelearner_Text_0
# 174 "data/maps/SecondChallengeRoom/scripts.pory"
	waitmessage
# 175 "data/maps/SecondChallengeRoom/scripts.pory"
	closemessage
# 176 "data/maps/SecondChallengeRoom/scripts.pory"
SecondChallengeRoom_MoveRelearner_ChooseMon:
# 177 "data/maps/SecondChallengeRoom/scripts.pory"
	special ChooseMonForMoveRelearner
# 178 "data/maps/SecondChallengeRoom/scripts.pory"
	waitstate
# 179 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_ne SecondChallengeRoom_MoveRelearner_2
SecondChallengeRoom_MoveRelearner_1:
# 193 "data/maps/SecondChallengeRoom/scripts.pory"
	release
	end

SecondChallengeRoom_MoveRelearner_2:
# 180 "data/maps/SecondChallengeRoom/scripts.pory"
	special IsSelectedMonEgg
# 181 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SecondChallengeRoom_MoveRelearner_4
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_4:
# 182 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq SecondChallengeRoom_MoveRelearner_6
# 185 "data/maps/SecondChallengeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 186 "data/maps/SecondChallengeRoom/scripts.pory"
	waitstate
# 187 "data/maps/SecondChallengeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq SecondChallengeRoom_MoveRelearner_9
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_6:
# 183 "data/maps/SecondChallengeRoom/scripts.pory"
	message SecondChallengeRoom_MoveRelearner_Text_1
	goto SecondChallengeRoom_MoveRelearner_1

SecondChallengeRoom_MoveRelearner_9:
# 188 "data/maps/SecondChallengeRoom/scripts.pory"
	goto SecondChallengeRoom_MoveRelearner_ChooseMon
	goto SecondChallengeRoom_MoveRelearner_1


	.align 2
# 197 "data/maps/SecondChallengeRoom/scripts.pory"
SecondChallengeRoom_Mart:
# 198 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_LUCKY_EGG
# 199 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_EXP_SHARE
# 200 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_POKE_BALL
# 201 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 202 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 203 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_LOVE_BALL
# 204 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 205 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 206 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FRIEND_BALL
# 207 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ABILITY_CAPSULE
# 208 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ABILITY_PATCH
# 209 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 210 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 211 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 212 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_POTION
# 213 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_PARLYZ_HEAL
# 214 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 215 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HEAL_POWDER
# 216 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ETHER
# 217 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ELIXIR
# 218 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 219 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_HP_UP
# 220 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 221 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_X_DEFEND
# 222 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 223 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_BAND
# 224 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_SPECS
# 225 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHOICE_SCARF
# 226 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FLAME_ORB
# 227 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_TOXIC_ORB
# 228 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_FOCUS_SASH
# 229 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 230 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 231 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_ZOOM_LENS
# 232 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_METAL_COAT
# 233 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 234 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_DEEP_SEA_TOOTH
# 235 "data/maps/SecondChallengeRoom/scripts.pory"
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte ITEM_NONE

SecondChallengeRoom_Hiker_Text_0:
# 19 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Yo. Listen, I'll make it short for all of\n"
	.string "us. As you may have already guessed, I\l"
	.string "am the second leader here. And I can't\l"
	.string "let you pass, until you beat me. I hope\l"
	.string "I've made myself clear.$"

SecondChallengeRoom_Hiker_Text_1:
# 20 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Be careful {PLAYER}. We don't know\n"
	.string "what we'll need to do in order to get\l"
	.string "past him.$"

SecondChallengeRoom_Hiker_Text_2:
# 21 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "You just need to beat me in a battle,\n"
	.string "pal. Simple as that.$"

SecondChallengeRoom_Hiker_Text_3:
# 22 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Oh, it looks like it'll be simpler this\n"
	.string "time around then.$"

SecondChallengeRoom_Hiker_Text_4:
# 23 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Let's beat this guy, {PLAYER}!$"

SecondChallengeRoom_Hiker_Text_5:
# 27 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "It's you again.\pYou wanna try one more time?$"

SecondChallengeRoom_Hiker_Text_6:
# 34 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Good luck on your journey, you'll need\n"
	.string "it.$"

SecondChallengeRoom_HikerBattle_Text_0:
# 46 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "You lost, punk.\p"
	.string "You need stronger Pokemon, if you want\n"
	.string "to defeat me.$"

SecondChallengeRoom_HikerBattle_Text_1:
# 47 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Ow…Don't worry, {PLAYER}! I'm sure\n"
	.string "you'll beat this guy. Look around the\l"
	.string "place, try to find new Pokemon and come\l"
	.string "with a better plan next time!\p"
	.string "For now, let's get your Party members\n"
	.string "healed.$"

SecondChallengeRoom_HikerBattle_Text_2:
# 62 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'll give you a tip, {PLAYER}. Check\n"
	.string "out the area south from here. I'm sure\l"
	.string "you'll be be able to train and catch new\l"
	.string "Pokemon there. Courage!$"

SecondChallengeRoom_HikerBattle_Text_3:
# 66 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "NANI?!\p"
	.string "Well, as much as it hurts me to say, you\n"
	.string "did win. You earned this, punk.$"

SecondChallengeRoom_HikerBattle_Text_4:
# 67 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "{PLAYER} received the Hiker Badge.$"

SecondChallengeRoom_HikerBattle_Text_5:
# 71 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "You can proceed further now. I won't\n"
	.string "block the way.$"

SecondChallengeRoom_HikerBattle_Text_6:
# 83 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Wow! You're amazing, {PLAYER}!$"

SecondChallengeRoom_HikerBattle_Text_7:
# 84 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "This is your second Badge, now! I'm not\n"
	.string "sure if you'll need to obtain all 8 of\l"
	.string "them, but even then, it shouldn't be\l"
	.string "much of a problem for you! If you want\l"
	.string "to, you can look around the area, and\l"
	.string "then let's continue forward.$"

SecondChallengeRoom_FirstBidoofMsg_Text_0:
# 137 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "Looks like we've entered another\n"
	.string "transition cave. And this time, it is\l"
	.string "actually a cave. Let's keep our eyes\l"
	.string "open. Who knows what we'll find here.$"

SecondChallengeRoom_NurseJoy_Text_0:
# 148 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'll heal your Pokemon.$"

SecondChallengeRoom_MartGuy_Text_0:
# 163 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I sell items.$"

SecondChallengeRoom_MoveRelearner_Text_0:
# 173 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "I'm the Move Reminder.\p$"

SecondChallengeRoom_MoveRelearner_Text_1:
# 183 "data/maps/SecondChallengeRoom/scripts.pory"
	.string "This Pokemon cannot learn anything.$"
