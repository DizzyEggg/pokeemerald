MansionFloor1RoomBoss_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MansionFloor1RoomBoss_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MansionFloor1RoomBoss_OnFrame
	.byte 0

MansionFloor1RoomBoss_OnTransition:
	goto_if_set FLAG_BOSS1_CLEAR, MansionFloor1RoomBoss_EventScript_End
	setvar VAR_TEMP_0, 0
	end

MansionFloor1RoomBoss_OnFrame:
	.2byte 0


MansionFloor1RoomBoss_EventScript_End::
	releaseall
	end


MansionFloor1RoomBoss_EventScript_Boss1::
	goto_if_set FLAG_HIDE_BOSS3_TRIO, MansionFloor1RoomBoss_EventScript_BossCheckA
	goto_if_set FLAG_FOUGHT_SWEET_SQUAD, MansionFloor1RoomBoss_EventScript_SweetSquadScene2
	goto MansionFloor1RoomBoss_EventScript_SweetSquadScene1
	end


MansionFloor1RoomBoss_EventScript_BossCheckA::
	@defeated amy
	goto_if_set FLAG_HIDE_BOSS3_DUO, MansionFloor1RoomBoss_EventScript_BossCheckB
	
	@check if they've been here before
	goto_if_set FLAG_FOUGHT_SAVORY_SQUAD, MansionFloor1RoomBoss_EventScript_SavorySquadScene2
	goto MansionFloor1RoomBoss_EventScript_SavorySquadScene1
	end

MansionFloor1RoomBoss_EventScript_BossCheckB::
	@defeated Bella
	goto_if_set FLAG_HIDE_BOSS3_SOLO, MansionFloor1RoomBoss_EventScript_SavorySquadScene2
	@not beaten Ripley
	goto MansionFloor1RoomBoss_EventScript_SweetSquadScene2
	end


MansionFloor1RoomBoss_EventScript_SweetSquadScene1::
	lockall
	setvar VAR_TEMP_0, 1
	playbgm MUS_PMDRED_MAKUHITA_DOJO, FALSE
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
	setwildbattle SPECIES_FIDOUGH, 9, ITEM_ORAN_BERRY, SPECIES_APPLIN, 10, ITEM_ORAN_BERRY
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_AttackMove
	waitmovement 0
	special RemoveCameraObject
	dowildbattle
	setwildbattle SPECIES_SINISTEA, 11, ITEM_ORAN_BERRY, SPECIES_VANILLITE, 12, ITEM_ORAN_BERRY
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	setflag FLAG_DEFEATED_SWEET_SQUAD
	setflag FLAG_HIDE_SWEET_SQUAD
	setflag FLAG_BOSS1_CLEAR
	fadedefaultbgm
	removeobject LOCALID_APPLIN
	removeobject LOCALID_VANILLITE
	removeobject LOCALID_FIDOUGH
	removeobject LOCALID_SINISTEA
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

MansionFloor1RoomBoss_AttackMove:
	walk_fast_down
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
	setvar VAR_TEMP_0, 1
	playbgm MUS_PMDRED_MAKUHITA_DOJO, FALSE
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
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_AttackMove
	waitmovement 0
	special RemoveCameraObject
	setwildbattle SPECIES_FIDOUGH, 9, ITEM_ORAN_BERRY, SPECIES_APPLIN, 10, ITEM_ORAN_BERRY
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	setwildbattle SPECIES_SINISTEA, 11, ITEM_ORAN_BERRY, SPECIES_VANILLITE, 12, ITEM_ORAN_BERRY
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	setflag FLAG_BOSS1_CLEAR
	fadedefaultbgm
	removeobject LOCALID_APPLIN
	removeobject LOCALID_VANILLITE
	removeobject LOCALID_FIDOUGH
	removeobject LOCALID_SINISTEA
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
	setvar VAR_TEMP_0, 1
	playbgm MUS_PMDRED_MAKUHITA_DOJO, FALSE
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
	msgbox_portrait MansionFloor1RoomBoss_Text_Tatsugiri1, FIELD_PIC_TATSUGIRI_SPECIAL
	delay 20
	applymovement LOCALID_TATSUGIRI, MansionFloor1RoomBoss_TatsugiriAssemble
	applymovement LOCALID_SMOLIV, MansionFloor1RoomBoss_SmolivAssemble
	applymovement LOCALID_FARFETCHD, MansionFloor1RoomBoss_FarfetchdAssemble
	applymovement LOCALID_NACLI, MansionFloor1RoomBoss_NacliAssemble
	waitmovement 0
	delay 50
	msgbox_portrait MansionFloor1RoomBoss_Text_Smoliv1, FIELD_PIC_SMOLIV_CRY
	msgbox_portrait MansionFloor1RoomBoss_Text_Farfetchd1, FIELD_PIC_FARFETCHD_DETERMINED
	msgbox_portrait MansionFloor1RoomBoss_Text_Nacli1, FIELD_PIC_NACLI_NORMAL
	delay 20
	applymovement LOCALID_TATSUGIRI, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_SMOLIV, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_FARFETCHD, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_NACLI, MansionFloor1RoomBoss_AttackMove
	waitmovement 0
	setwildbattle SPECIES_SMOLIV, 7, ITEM_ORAN_BERRY, SPECIES_FARFETCHD, 11, ITEM_ORAN_BERRY
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	setwildbattle SPECIES_NACLI, 10, ITEM_ORAN_BERRY, SPECIES_TATSUGIRI, 14, ITEM_ORAN_BERRY
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	@TOFOLD
	@setflag FLAG_DEFEATED_SAVORY_SQUAD
	setflag FLAG_BOSS1_CLEAR
	special RemoveCameraObject
	releaseall
	end



MansionFloor1RoomBoss_Text_Tatsugiri1:
	.string "Well, well, well.\p"
	.string "You beat our rivals.\p"
	.string "They're cute, but they're not much use\n"
	.string "in a real fight, you get me?\p"
	.string "Sweets are an afterthought. A luxury.\p"
	.string "They can't compete with the supremely\n"
	.string "satisfying flavor of the Savory Squad!\p"
	.string "Ain't that right, squad?$"

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



MansionFloor1RoomBoss_EventScript_SavorySquadScene2::
	lockall
	setvar VAR_TEMP_0, 1
	playbgm MUS_PMDRED_MAKUHITA_DOJO, FALSE
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
	msgbox_portrait MansionFloor1RoomBoss_Text_Tatsugiri2, FIELD_PIC_TATSUGIRI_SPECIAL
	delay 20
	applymovement LOCALID_TATSUGIRI, MansionFloor1RoomBoss_TatsugiriAssemble
	applymovement LOCALID_SMOLIV, MansionFloor1RoomBoss_SmolivAssemble
	applymovement LOCALID_FARFETCHD, MansionFloor1RoomBoss_FarfetchdAssemble
	applymovement LOCALID_NACLI, MansionFloor1RoomBoss_NacliAssemble
	waitmovement 0
	delay 50
	msgbox_portrait MansionFloor1RoomBoss_Text_Smoliv2, FIELD_PIC_SMOLIV_CRY
	msgbox_portrait MansionFloor1RoomBoss_Text_Farfetchd2, FIELD_PIC_FARFETCHD_DETERMINED
	msgbox_portrait MansionFloor1RoomBoss_Text_Nacli2, FIELD_PIC_NACLI_NORMAL
	delay 20
	applymovement LOCALID_TATSUGIRI, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_SMOLIV, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_FARFETCHD, MansionFloor1RoomBoss_AttackMove
	applymovement LOCALID_NACLI, MansionFloor1RoomBoss_AttackMove
	waitmovement 0
	setwildbattle SPECIES_SMOLIV, 7, ITEM_ORAN_BERRY, SPECIES_FARFETCHD, 8, ITEM_ORAN_BERRY
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	setwildbattle SPECIES_NACLI, 10, ITEM_ORAN_BERRY, SPECIES_TATSUGIRI, 14, ITEM_ORAN_BERRY
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	@TOFOLD
	setflag FLAG_DEFEATED_SAVORY_SQUAD
	setflag FLAG_BOSS1_CLEAR
	special RemoveCameraObject
	releaseall
	end



MansionFloor1RoomBoss_Text_Tatsugiri2:
	.string "Well, well, well; back for more.\n"
	.string "This is a clash of the titans, really.\p"
	.string "The bold, rich, and satisfying Savory\n"
	.string "Squad of legend…\p"
	.string "against two of the most unsavory\n"
	.string "Pokemon I've ever seen.$"

MansionFloor1RoomBoss_Text_Smoliv2:
	.string "Aaaaaaaa not again!\n"
	.string "They bent my leaf last time!$"

MansionFloor1RoomBoss_Text_Farfetchd2:
	.string "You villains!\p"
	.string "No holding back this time!$"

MansionFloor1RoomBoss_Text_Nacli2:
	.string "YOU. WILL. BE. SALTY.\p"
	.string "WHEN. YOU. LOSE.$"














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





@@@ Static events


MansionFloor1RoomBoss_EventScript_HeadChair::
	msgbox MansionFloor1RoomBoss_Text_HeadChair, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_HeadChair:
	.string "The head of the table. Looks like a\n"
	.string "well-used chair.$"


MansionFloor1RoomBoss_EventScript_VineStool::
	msgbox MansionFloor1RoomBoss_Text_VineStool, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_VineStool:
	.string "A stool covered in old, dead vines.$"


MansionFloor1RoomBoss_EventScript_HammerStool::
	msgbox MansionFloor1RoomBoss_Text_HammerStool, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_HammerStool:
	.string "A nice chair with two worn\n"
	.string "footprints on it.$"


MansionFloor1RoomBoss_EventScript_HammerHole::
	msgbox MansionFloor1RoomBoss_Text_HammerHole, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_HammerHole:
	.string "A huge, circular hole in the floor!\n"
	.string "Very shallow, but so round!$"



MansionFloor1RoomBoss_EventScript_PillowStool::
	msgbox MansionFloor1RoomBoss_Text_PillowStool, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_PillowStool:
	.string "A stool with bits of fluff stuck in\n"
	.string "every crevice.$"



MansionFloor1RoomBoss_EventScript_Feathers::
	msgbox MansionFloor1RoomBoss_Text_Feathers, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_Feathers:
	.string "The ground is covered with little bits\n"
	.string "of either cotton fluff or feathers.$"



MansionFloor1RoomBoss_EventScript_UnusedChair::
	msgbox MansionFloor1RoomBoss_Text_UnusedChair, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_UnusedChair:
	.string "This chair is pristine.\n"
	.string "It looks like no one has ever sat here.$"



MansionFloor1RoomBoss_EventScript_Pillow::
	msgbox MansionFloor1RoomBoss_Text_Pillow, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_Pillow:
	.string "A huge, fluffy pillow!\n"
	.string "It's covered in claw marks.$"



MansionFloor1RoomBoss_EventScript_MossStool::
	msgbox MansionFloor1RoomBoss_Text_MossStool, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_MossStool:
	.string "This stool is oddly damp to the touch.\n"
	.string "Mold has wormed into the cracks.$"



MansionFloor1RoomBoss_EventScript_Sink::
	msgbox MansionFloor1RoomBoss_Text_Sink, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_Sink:
	.string "The sink is full of spiderwebs.$"


MansionFloor1RoomBoss_EventScript_Shelves::
	msgbox MansionFloor1RoomBoss_Text_Shelves, MSGBOX_NPC
	end

MansionFloor1RoomBoss_Text_Shelves:
	.string "Dusty jars line the shelves.\n"
	.string "Nothing looks useful.$"

