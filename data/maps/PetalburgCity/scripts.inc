PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition:
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_SYS_B_DASH
	call_if_eq VAR_PETALBURG_CITY_STATE, 0, PetalburgCity_EventScript_MoveGymBoyToWestEntrance
	call_if_eq VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_DisableMapNameAndMusic
	call_if_eq VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_DisableMapNameAndMusic
	call_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_EventScript_SetGymDoorsUnlocked
	end

PetalburgCity_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
	.2byte 0



Fountain_EventScript_Abra_Mansion_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_MANSION
	removeobject LOCALID_ABRA_BIRDHOUSE
	removeobject LOCALID_ABRA_STACKS
	removeobject LOCALID_ABRA_BACKDOOR
	removeobject LOCALID_ABRA_GARDEN
	setvar VAR_TEMP_0, 1
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Grave_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_GRAVE
	removeobject LOCALID_ABRA_GARDEN
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Garden_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_GARDEN
	removeobject LOCALID_ABRA_BIRDHOUSE
	removeobject LOCALID_ABRA_MANSION
	removeobject LOCALID_ABRA_GRAVE
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Birdhouse_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_BIRDHOUSE
	removeobject LOCALID_ABRA_MANSION
	removeobject LOCALID_ABRA_GARDEN
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Backdoor_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_BACKDOOR
	removeobject LOCALID_ABRA_MANSION
	removeobject LOCALID_ABRA_SHED
	removeobject LOCALID_ABRA_STACKS
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 1
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Shed_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_SHED
	removeobject LOCALID_ABRA_BACKDOOR
	removeobject LOCALID_ABRA_STACKS
	removeobject LOCALID_ABRA_STUMPS
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 1
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Stacks_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_STACKS
	removeobject LOCALID_ABRA_BACKDOOR
	removeobject LOCALID_ABRA_SHED
	removeobject LOCALID_ABRA_STUMPS
	removeobject LOCALID_ABRA_MANSION
	removeobject LOCALID_ABRA_WELL
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 1
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Stumps_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_STUMPS
	removeobject LOCALID_ABRA_BACKDOOR
	removeobject LOCALID_ABRA_SHED
	removeobject LOCALID_ABRA_STACKS
	removeobject LOCALID_ABRA_WELL
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 1
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Well_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	removeobject LOCALID_ABRA_STACKS
	removeobject LOCALID_ABRA_STUMPS
	removeobject LOCALID_ABRA_GATE
	removeobject LOCALID_ABRA_CAMPFIRE
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 1
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Campfire_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_CAMPFIRE
	removeobject LOCALID_ABRA_WELL
	removeobject LOCALID_ABRA_GATE
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 1
	setvar VAR_TEMP_A, 0
	end

Fountain_EventScript_Abra_Gate_Trigger::
	playse SE_WARP_IN
	addobject LOCALID_ABRA_GATE
	removeobject LOCALID_ABRA_CAMPFIRE
	removeobject LOCALID_ABRA_STUMPS
	removeobject LOCALID_ABRA_WELL
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 1
	end


Fountain_EventScript_Abra_Mansion::
	end

Fountain_EventScript_Abra_Garden::
	end

Fountain_EventScript_Abra_Grave::
	end

Fountain_EventScript_Abra_Birdhouse::
	end

Fountain_EventScript_Abra_Backdoor::
	end

Fountain_EventScript_Abra_Shed::
	end

Fountain_EventScript_Abra_Stacks::
	end

Fountain_EventScript_Abra_Stumps::
	end

Fountain_EventScript_Abra_Well::
	end

Fountain_EventScript_Abra_Campfire::
	end

Fountain_EventScript_Abra_Gate::
	end


Fountain_Text_AbraMansion1:
	.string "Here it is.\p"
	.string "Inside this house is where Cradily hides.\p"
	.string "It is automatically sent to a STORAGE\n"
	.string "BOX over a PC connection.$"





Fountain_EventScript_Grave::
	msgbox Fountain_Text_Grave, MSGBOX_NPC
	end

Fountain_Text_Grave:
	.string "A smooth pale stone.\n"
	.string "It's covered in strange markings.$"

Fountain_EventScript_PhotoStump::
	goto_if_set FLAG_OBTAINED_PHOTO1, Fountain_EventScript_PhotoCheck
	goto_if_set FLAG_OBTAINED_PHOTO2, Fountain_EventScript_PhotoCheck
	goto_if_set FLAG_OBTAINED_PHOTO3, Fountain_EventScript_PhotoCheck
	goto_if_set FLAG_OBTAINED_PHOTO4, Fountain_EventScript_PhotoCheck
	goto_if_set FLAG_OBTAINED_PHOTO5, Fountain_EventScript_PhotoCheck
	end

Fountain_EventScript_PhotoCheck::
	goto_if_unset FLAG_OBTAINED_PHOTO1, Fountain_EventScript_IncompletePhoto


Fountain_EventScript_IncompletePhoto::
	msgbox Fountain_Text_IncompletePhoto, MSGBOX_NPC
	end

Fountain_Text_IncompletePhoto:
	.string "The pieces of that odd picture you\n"
	.string "found are assembled here.\p"
	.string "It doesn't look complete yet.\n"
	.string "found are assembled here.$"






















PetalburgCity_EventScript_MoveGymBoyToWestEntrance::
	setobjectxyperm LOCALID_GYM_BOY, 5, 11
	return

PetalburgCity_EventScript_DisableMapNameAndMusic::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_FOLLOW_ME
	return

PetalburgCity_EventScript_SetGymDoorsUnlocked::
	setvar VAR_PETALBURG_GYM_STATE, 7
	return

PetalburgCity_EventScript_WallyTutorial::
	lockall
	special SavePlayerParty
	special LoadWallyZigzagoon
	applymovement LOCALID_PETALBURG_WALLY, PetalburgCity_Movement_WallyTutorialWally
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
	waitmovement 0
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
	special StartWallyTutorialBattle
	waitstate
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WALLY, Common_Movement_WalkInPlaceFasterLeft, MAP_PETALBURG_CITY
	waitmovement LOCALID_PETALBURG_WALLY, MAP_PETALBURG_CITY
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_PETALBURG_CITY_STATE, 3
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	special LoadPlayerParty
	setvar VAR_PETALBURG_GYM_STATE, 1
	warp MAP_PETALBURG_CITY_GYM, 4, 108
	waitstate
	releaseall
	end

PetalburgCity_EventScript_WalkToWallyHouse::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkToWallyHouseWallysDad
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkToWallyHousePlayer
	waitmovement 0
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 5
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_PETALBURG_WALLYS_DAD, PetalburgCity_Movement_WalkInsideHouseWallysDad
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_WalkInsideHousePlayer
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	hideobjectat LOCALID_PLAYER, MAP_PETALBURG_CITY
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PETALBURG_CITY_WALLYS_HOUSE, 2, 4
	waitstate
	releaseall
	end

PetalburgCity_EventScript_Boy::
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_EventScript_WallysMom::
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
	end

PetalburgCity_Movement_WalkToWallyHousePlayer:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHousePlayer:
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkToWallyHouseWallysDad:
	delay_8
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHouseWallysDad:
	walk_up
	set_invisible
	step_end

PetalburgCity_Movement_WallyTutorialPlayer:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Movement_WallyTutorialWally:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

PetalburgCity_EventScript_GymSign::
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign::
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Gentleman::
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_WallyHouseSign::
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_ShowGymToPlayer0::
	lockall
	setvar VAR_0x8008, 0
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer1::
	lockall
	setvar VAR_0x8008, 1
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer2::
	lockall
	setvar VAR_0x8008, 2
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer3::
	lockall
	setvar VAR_0x8008, 3
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer::
	applymovement LOCALID_GYM_BOY, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_FOLLOW_ME, FALSE
	playse SE_PIN
	applymovement LOCALID_GYM_BOY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GYM_BOY, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_BoyApproachPlayer0
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_BoyApproachPlayer1
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_BoyApproachPlayer2
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_BoyApproachPlayer3
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_LeadPlayerToGym0
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_LeadPlayerToGym1
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_LeadPlayerToGym2
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_LeadPlayerToGym3
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
	applymovement LOCALID_GYM_BOY, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkAway
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

PetalburgCity_EventScript_BoyApproachPlayer0::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer1::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer1
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer2::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer3::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer3
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym0::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym0
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym1::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym1
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym2::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym2
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym3::
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym3
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
	waitmovement 0
	return

@ Unused
PetalburgCity_Movement_Delay48::
	delay_16
	delay_16
	delay_16
	step_end

PetalburgCity_Movement_BoyApproachPlayer0:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

PetalburgCity_Movement_BoyApproachPlayer1:
	walk_right
	walk_right
	step_end

PetalburgCity_Movement_BoyApproachPlayer2:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

PetalburgCity_Movement_BoyApproachPlayer3:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

PetalburgCity_Movement_BoyWalkToGym0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

PetalburgCity_Movement_BoyWalkToGym1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

PetalburgCity_Movement_BoyWalkToGym2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

PetalburgCity_Movement_BoyWalkToGym3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

PetalburgCity_Movement_BoyWalkAway:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWalkToGym0:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym1:
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym3:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_EventScript_Scott0::
	lockall
	addobject LOCALID_PETALBURG_SCOTT
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 10
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott1::
	lockall
	addobject LOCALID_PETALBURG_SCOTT
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 11
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott2::
	lockall
	addobject LOCALID_PETALBURG_SCOTT
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 12
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott3::
	lockall
	addobject LOCALID_PETALBURG_SCOTT
	setvar VAR_0x8008, 3
	setobjectxy LOCALID_PETALBURG_SCOTT, 13, 13
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott::
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottStartWalkLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_SCOTT_STATE, 1
	msgbox PetalburgCity_Text_AreYouATrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_WellMaybeNot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_ImLookingForTalentedTrainers, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, PetalburgCity_EventScript_ScottExit0
	call_if_eq VAR_0x8008, 1, PetalburgCity_EventScript_ScottExit1
	call_if_eq VAR_0x8008, 2, PetalburgCity_EventScript_ScottExit2
	call_if_eq VAR_0x8008, 3, PetalburgCity_EventScript_ScottExit3
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
	removeobject LOCALID_PETALBURG_SCOTT
	releaseall
	end

PetalburgCity_EventScript_ScottExit0::
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit0
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit1::
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit1
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit2::
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit2
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit3::
	applymovement LOCALID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
	applymovement LOCALID_PETALBURG_SCOTT, PetalburgCity_Movement_ScottExit3
	waitmovement 0
	return

PetalburgCity_Movement_ScottStartWalkLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottExit0:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit0:
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_ScottExit1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit1:
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_ScottExit2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit2:
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

PetalburgCity_Movement_ScottExit3:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit3:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

PetalburgCity_EventScript_GymBoy::
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
	end

PetalburgCity_Text_WhereIsWally:
	.string "Where has our WALLY gone?\p"
	.string "We have to leave for VERDANTURF TOWN\n"
	.string "very soon…$"

PetalburgCity_Text_AreYouRookieTrainer:
	.string "Hiya! Are you maybe…\n"
	.string "A rookie TRAINER?\p"
	.string "Do you know what POKéMON TRAINERS\n"
	.string "do when they reach a new town?\p"
	.string "They first check what kind of GYM\n"
	.string "is in the town.$"

PetalburgCity_Text_ThisIsPetalburgGym:
	.string "See? This is PETALBURG CITY's GYM.$"

PetalburgCity_Text_ThisIsGymSign:
	.string "This is the GYM's sign. Look for it\n"
	.string "whenever you're looking for a GYM.$"

PetalburgCity_Text_WaterReflection:
	.string "My face is reflected in the water.\p"
	.string "It's a shining grin full of hope…\p"
	.string "Or it could be a look of somber silence\n"
	.string "struggling with fear…\p"
	.string "What do you see reflected in your face?$"

PetalburgCity_Text_FullPartyExplanation:
	.string "Let's say you have six POKéMON.\n"
	.string "If you catch another one…\p"
	.string "It is automatically sent to a STORAGE\n"
	.string "BOX over a PC connection.$"

PetalburgCity_Text_GymSign:
	.string "PETALBURG CITY POKéMON GYM\n"
	.string "LEADER: NORMAN\l"
	.string "“A man in pursuit of power!”$"

PetalburgCity_Text_CitySign:
	.string "PETALBURG CITY\n"
	.string "“Where people mingle with nature.”$"

PetalburgCity_Text_WallyHouseSign:
	.string "WALLY'S HOUSE$"

PetalburgCity_Text_AreYouATrainer:
	.string "Excuse me!\p"
	.string "Let me guess, from the way you're\n"
	.string "dressed, are you a POKéMON TRAINER?$"

PetalburgCity_Text_WellMaybeNot:
	.string "… … … … … …\p"
	.string "Well, maybe not.\n"
	.string "Your clothes aren't all that dirty.\p"
	.string "You're either a rookie TRAINER,\n"
	.string "or maybe you're just an ordinary kid.$"

PetalburgCity_Text_ImLookingForTalentedTrainers:
	.string "I'm roaming the land in search of\n"
	.string "talented TRAINERS.\p"
	.string "I'm sorry to have taken your time.$"
