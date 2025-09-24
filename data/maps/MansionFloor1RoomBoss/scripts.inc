MansionFloor1RoomBoss_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MansionFloor1RoomBoss_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MansionFloor1RoomBoss_OnFrame
	.byte 0

MansionFloor1RoomBoss_OnTransition:
	setvar VAR_TEMP_0, 0
	end

MansionFloor1RoomBoss_OnFrame:
	.2byte 0




MansionFloor1RoomBoss_EventScript_SugarSquadScene1::
	lockall
	setvar VAR_TEMP_0, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	special SpawnCameraObject
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, MansionFloor1RoomBoss_CameraMove1
	waitmovement 0
	delay 20
	applymovement LOCALID_FIDOUGH, Common_Movement_ExclamationMark
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_LookDown
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor1RoomBoss_Text_Fidough1, FIELD_PIC_ABRA_SERIOUS
	delay 20
	applymovement OBJ_EVENT_ID_CAMERA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_FidoughAssemble
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_ApplinAssemble
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_SinisteaAssemble
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_VanilliteAssemble
	waitmovement 0
	delay 50
	msgbox_portrait MansionFloor1RoomBoss_Text_Applin1, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait MansionFloor1RoomBoss_Text_Sinistea1, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait MansionFloor1RoomBoss_Text_Vanillite1, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait MansionFloor1RoomBoss_Text_Vanillite2, FIELD_PIC_ABRA_SERIOUS
	delay 20
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_CameraMove2
	waitmovement 0
	@TOFOLD - add the fight command
	releaseall
	end

MansionFloor1RoomBoss_Text_Fidough1:
	.string "Whoa!\p"
	.string "Alert! Alert!\n"
	.string "Bad Pokemon! Here! They want stairs!\p"
	.string "Sugar Squad! Fight!$"

MansionFloor1RoomBoss_Text_Applin1:
	.string "It's these two troublemakers again!\p"
	.string "You're not getting past us this time!\n"
	.string "Father needs his rest!$"

MansionFloor1RoomBoss_Text_Sinistea1:
	.string "Yesss…\p"
	.string "We're just going to throw you back in\n"
	.string "the Fountain where you belong.\p"
	.string "Stop struggling, hm?$"

MansionFloor1RoomBoss_Text_Vanillite1:
	.string "I see the way you lick your lips when\n"
	.string "you look at us…\p"
	.string "Perhaps you'd like a taste…$"

MansionFloor1RoomBoss_Text_Vanillite2:
	.string "OF MY FIST!\p"
	.string "Sugar Squad, attack!$"



MansionFloor1RoomBoss_CameraMove1:
	walk_up
	walk_up
	walk_up
	step_end

MansionFloor1RoomBoss_CameraMove2:
	walk_down
	walk_down
	step_end

MansionFloor1RoomBoss_FidoughAssemble:
	walk_down
	walk_down
	step_end

MansionFloor1RoomBoss_ApplinAssemble:
	walk_left
	walk_left
	jump_left
	face_down
	step_end

MansionFloor1RoomBoss_VanilliteAssemble:
	jump_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MansionFloor1RoomBoss_SinisteaAssemble:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

MansionFloor1RoomBoss_LookUp:
	face_up
	step_end

MansionFloor1RoomBoss_LookDown:
	face_down
	step_end

MansionFloor1RoomBoss_LookLeft:
	face_left
	step_end

MansionFloor1RoomBoss_LookRight:
	face_right
	step_end