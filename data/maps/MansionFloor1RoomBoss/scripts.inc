MansionFloor1RoomBoss_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MansionFloor1RoomBoss_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MansionFloor1RoomBoss_OnFrame
	.byte 0

MansionFloor1RoomBoss_OnTransition:
	setvar VAR_TEMP_0, 0
	end

MansionFloor1RoomBoss_OnFrame:
	.2byte 0



MansionFloor1RoomBoss_EventScript_Boss1::
	goto_if_set FLAG_DEFEATED_SAVORY_SQUAD, MansionFloor1RoomBoss_EventScript_RandomizeBoss
	goto_if_set FLAG_DEFEATED_SWEET_SQUAD, MansionFloor1RoomBoss_EventScript_SavorySquadScene1
	goto_if_set FLAG_FOUGHT_SWEET_SQUAD, MansionFloor1RoomBoss_EventScript_SavorySquadScene1
	goto MansionFloor1RoomBoss_EventScript_SweetSquadScene1
	end




MansionFloor1RoomBoss_EventScript_SweetSquadScene1::
	lockall
	setvar VAR_TEMP_0, 0
	setflag FLAG_FOUGHT_SWEET_SQUAD
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	special SpawnCameraObject
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, MansionFloor1RoomBoss_CameraMove1
	waitmovement 0
	delay 20
	applymovement LOCALID_FIDOUGH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_LookDown
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor1RoomBoss_Text_Fidough1, FIELD_PIC_FIDOUGH_SURPRISED
	delay 20
	applymovement OBJ_EVENT_ID_CAMERA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_FidoughAssemble
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_ApplinAssemble
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_SinisteaAssemble
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_VanilliteAssemble
	waitmovement 0
	delay 50
	msgbox_portrait MansionFloor1RoomBoss_Text_Applin1, FIELD_PIC_APPLIN_DETERMINED
	msgbox_portrait MansionFloor1RoomBoss_Text_Sinistea1, FIELD_PIC_SINISTEA_HAPPY
	msgbox_portrait MansionFloor1RoomBoss_Text_Vanillite1, FIELD_PIC_VANILLITE_SIGH
	msgbox_portrait MansionFloor1RoomBoss_Text_Vanillite2, FIELD_PIC_VANILLITE_ANGRY
	delay 20
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_CameraMove2
	waitmovement 0
	@TOFOLD - add the fight command
	@setflag FLAG_DEFEATED_SWEET_SQUAD
	special RemoveCameraObject
	releaseall
	end

MansionFloor1RoomBoss_Text_Fidough1:
	.string "Whoa!\p"
	.string "Alert! Alert!\n"
	.string "Bad Pokemon! Here! They want stairs!\p"
	.string "Sweet Squad! Fight!$"

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
	.string "Sweet Squad, attack!$"



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
	jump_2_left
	face_down
	step_end

MansionFloor1RoomBoss_VanilliteAssemble:
	jump_2_left
	walk_left
	walk_left
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




@@@@@ Sweet Squad V2

MansionFloor1RoomBoss_EventScript_SweetSquadScene2::
	lockall
	setvar VAR_TEMP_0, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	special SpawnCameraObject
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, MansionFloor1RoomBoss_CameraMove1
	waitmovement 0
	delay 20
	applymovement LOCALID_FIDOUGH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_LookDown
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor1RoomBoss_Text_FidoughRematch, FIELD_PIC_FIDOUGH_SURPRISED
	delay 20
	applymovement OBJ_EVENT_ID_CAMERA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_FidoughAssemble
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_ApplinAssemble
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_SinisteaAssemble
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_VanilliteAssemble
	waitmovement 0
	delay 50
	msgbox_portrait MansionFloor1RoomBoss_Text_ApplinRematch, FIELD_PIC_APPLIN_DETERMINED
	msgbox_portrait MansionFloor1RoomBoss_Text_SinisteaRematch, FIELD_PIC_SINISTEA_HAPPY
	msgbox_portrait MansionFloor1RoomBoss_Text_VanilliteRematch, FIELD_PIC_VANILLITE_ANGRY
	delay 20
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_CameraMove2
	waitmovement 0
	@TOFOLD - add the fight command
	special RemoveCameraObject
	releaseall
	end




MansionFloor1RoomBoss_Text_FidoughRematch:
	.string "They're back!\p"
	.string "They're back they're back they're back!\p"
	.string "Bad Pokemon! Not good!\p"
	.string "Sweet Squad!$"

MansionFloor1RoomBoss_Text_ApplinRematch:
	.string "They're persistent.\p"
	.string "But the Sweet Squad will always fight\n"
	.string "for sweet justice!$"

MansionFloor1RoomBoss_Text_SinisteaRematch:
	.string "Yesss…\p"
	.string "The Fountain makes them tireless.\p"
	.string "Well, at least they're amusing.$"

MansionFloor1RoomBoss_Text_VanilliteRematch:
	.string "Want another serving of pain?\n"
	.string "Come on, then, bring it!$"



MansionFloor1RoomBoss_EventScript_SavorySquadScene1::
	lockall
	setvar VAR_TEMP_0, 0
	setflag FLAG_FOUGHT_SAVORY_SQUAD
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	special SpawnCameraObject
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, MansionFloor1RoomBoss_CameraMove3
	waitmovement 0
	delay 20
	applymovement LOCALID_TATSUGIRI, MansionFloor1RoomBoss_TatsugiriHello
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor1RoomBoss_Text_Tatsugiri1, FIELD_PIC_FIDOUGH_SURPRISED
	delay 20
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_TatsugiriAssemble
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_SmolivAssemble
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_FarfetchdAssemble
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_NacliAssemble
	waitmovement 0
	delay 50
	msgbox_portrait MansionFloor1RoomBoss_Text_Smoliv1, FIELD_PIC_APPLIN_DETERMINED
	msgbox_portrait MansionFloor1RoomBoss_Text_Farfetchd1, FIELD_PIC_SINISTEA_HAPPY
	msgbox_portrait MansionFloor1RoomBoss_Text_Nacli1, FIELD_PIC_VANILLITE_ANGRY
	delay 20
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_CameraMove2
	waitmovement 0
	@TOFOLD - add the fight command
	@setflag FLAG_DEFEATED_SAVORY_SQUAD
	special RemoveCameraObject
	releaseall
	end



MansionFloor1RoomBoss_Text_Tatsugiri1:
	.string "Well, well, well.\p"
	.string "You beat our rivals.\p"
	.string "They're cute, but they're not much use\n"
	.string "in a real fight, you get me?\p"
	.string "Sweets are an afterthought. A luxury.\p"
	.string "They can't compete with the awesome\n"
	.string "powers of the Savory Squad!\p"
	.string "Ain't that right, squad?\p"

MansionFloor1RoomBoss_Text_Smoliv1:
	.string "Aaaaaaaa they're so big!\n"
	.string "Why do we have to fight them?!$"

MansionFloor1RoomBoss_Text_Farfetchd1:
	.string "Smoliv, you'll be fine! You gotta be\n"
	.string "rough and tough with these villains.\p"
	.string "Like this: Hey, you two!\p"
	.string "Don't hit Smoliv… or I'll hit you!$"

MansionFloor1RoomBoss_Text_Nacli1:
	.string "YOU. ENJOYED. DESSERT.\p"
	.string "NOW. MAIN COURSE.$"



MansionFloor1RoomBoss_CameraMove3:
	walk_up
	step_end

MansionFloor1RoomBoss_TatsugiriHello:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end


MansionFloor1RoomBoss_TatsugiriAssemble:
	jump_left
	jump_left
	jump_up
	face_down
	step_end

MansionFloor1RoomBoss_SmolivAssemble:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MansionFloor1RoomBoss_FarfetchdAssemble:
	jump_2_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end

MansionFloor1RoomBoss_NacliAssemble:
	jump_2_right
	walk_right
	face_down
	step_end


@@ TOFOLD
MansionFloor1RoomBoss_EventScript_RandomizeBoss::
	end