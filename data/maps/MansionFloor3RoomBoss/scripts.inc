MansionFloor3RoomBoss_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MansionFloor3RoomBoss_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MansionFloor3RoomBoss_OnFrame
	.byte 0

MansionFloor3RoomBoss_OnTransition:
	setvar VAR_TEMP_0, 0
	end

MansionFloor3RoomBoss_OnFrame:
	.2byte 0


MansionFloor3RoomBoss_EventScript_BossFight::
	goto_if_unset FLAG_HIDE_BOSS3_TRIO, MansionFloor3RoomBoss_EventScript_BossAmy
	goto_if_unset FLAG_HIDE_BOSS3_DUO, MansionFloor3RoomBoss_EventScript_BossBella
	goto_if_unset FLAG_HIDE_BOSS3_SOLO, MansionFloor3RoomBoss_EventScript_BossRipley
	end



MansionFloor3RoomBoss_EventScript_BossAmy::
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
	setwildbattle SPECIES_FIDOUGH, 9, ITEM_ORAN_BERRY, SPECIES_APPLIN, 10, ITEM_ORAN_BERRY
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_CameraMove2
	waitmovement 0
	special RemoveCameraObject
	dowildbattle
	waitstate
	setwildbattle SPECIES_SINISTEA, 11, ITEM_ORAN_BERRY, SPECIES_VANILLITE, 12, ITEM_ORAN_BERRY
	dowildbattle
	waitstate
	@TOFOLD - add the fight command
	setflag FLAG_HIDE_BOSS3_TRIO
	clearflag FLAG_HIDE_BOSS3_DUO
	removeobject LOCALID_APPLIN
	removeobject LOCALID_VANILLITE
	removeobject LOCALID_FIDOUGH
	removeobject LOCALID_SINISTEA
	releaseall
	end

MansionFloor3RoomBoss_EventScript_BossBella::
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
	setwildbattle SPECIES_FIDOUGH, 9, ITEM_ORAN_BERRY, SPECIES_APPLIN, 10, ITEM_ORAN_BERRY
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_CameraMove2
	waitmovement 0
	special RemoveCameraObject
	dowildbattle
	waitstate
	setwildbattle SPECIES_SINISTEA, 11, ITEM_ORAN_BERRY, SPECIES_VANILLITE, 12, ITEM_ORAN_BERRY
	dowildbattle
	waitstate
	@TOFOLD - add the fight command
	setflag FLAG_HIDE_BOSS3_DUO
	clearflag FLAG_HIDE_BOSS3_SOLO
	removeobject LOCALID_APPLIN
	removeobject LOCALID_VANILLITE
	removeobject LOCALID_FIDOUGH
	removeobject LOCALID_SINISTEA
	releaseall
	end


MansionFloor3RoomBoss_EventScript_BossRipley::
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
	setwildbattle SPECIES_FIDOUGH, 9, ITEM_ORAN_BERRY, SPECIES_APPLIN, 10, ITEM_ORAN_BERRY
	applymovement LOCALID_FIDOUGH, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_APPLIN, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_SINISTEA, MansionFloor1RoomBoss_CameraMove2
	applymovement LOCALID_VANILLITE, MansionFloor1RoomBoss_CameraMove2
	waitmovement 0
	special RemoveCameraObject
	dowildbattle
	waitstate
	setwildbattle SPECIES_SINISTEA, 11, ITEM_ORAN_BERRY, SPECIES_VANILLITE, 12, ITEM_ORAN_BERRY
	dowildbattle
	waitstate
	@TOFOLD - add the fight command
	setflag FLAG_HIDE_BOSS3_SOLO
	removeobject LOCALID_APPLIN
	removeobject LOCALID_VANILLITE
	removeobject LOCALID_FIDOUGH
	removeobject LOCALID_SINISTEA
	releaseall
	end







MansionFloor3RoomBoss_EventScript_Tinkaton1::
	lockall
	setvar VAR_TEMP_0, 1
	@TOFOLD
	end


MansionFloor3RoomBoss_Text_Boss1Amy1:
	.string "???: Halt, evildoers!\p"
	.string "Not another step! You stand before\n"
	.string "Amy, Craftily's favorite daughter!$"

MansionFloor3RoomBoss_Text_Boss1Bella1:
	.string "???: HEY!$"

MansionFloor3RoomBoss_Text_Boss1Amy2:
	.string "Amy: Favorites can tie, Bella!$"

MansionFloor3RoomBoss_Text_Boss1Amy3:
	.string "Anyway, Father is very sick!\p"
	.string "He's so old, and he won't accept any\n"
	.string "Fountain water!\p"
	.string "We're trying to reason with him,\n"
	.string "and that becomes a lot harder when\l"
	.string "troublemakers like you interrupt!$"

MansionFloor3RoomBoss_Text_Boss1Amy4:
	.string "Why are you troublemakers anyway?\p"
	.string "You look nice, and you're shiny, just\n"
	.string "like us three!\p"
	.string "I'm sure Father would forgive you!\p"
	.string "But it's not a good time for trouble,\n"
	.string "so please jump into the Fountain.\p"
	.string "Pretty please?\p"
	.string "You can use the window with all the\n"
	.string "broken glass behind you - that's\l"
	.string "where we throw you out.$"

MansionFloor3RoomBoss_Text_Boss1Ripley1:
	.string "???: They're not going to listen,\n"
	.string "Amy. Remember what we practiced.$"

MansionFloor3RoomBoss_Text_Boss1Amy5:
	.string "Amy: UGH.\p"
	.string "I don't get it. I don't.\n"
	.string "But Father must not be disturbed.\p"
	.string "Here comes the hammer of justice!$"


MansionFloor3RoomBoss_Text_Boss1Amy6:
	.string "Amy: No!\p"
	.string "You can't be allowed to bother him!\p"
	.string "…\p"
	.string "Ripley's last resort technique…\p"
	.string "It's my only chance!$"



MansionFloor3RoomBoss_Text_Boss2Bella1:
	.string "Bella: Hmph.\p"
	.string "Father doesn't like it when I fight\n"
	.string "his other children.\p"
	.string "Oh sure, we have the Fountain, but\n"
	.string "fear doesn't heal.\p"
	.string "But.\p"
	.string "Father also doesn't like being\n"
	.string "disturbed, reminded of the past.\p"
	.string "Which means… I get to hurt you.\p"
	.string "Guilt-free.\p"
	.string "Prepare.$"


MansionFloor3RoomBoss_Text_Boss2Bella2:
	.string "Bella: Damn it!\p"
	.string "Now I've got no choice but to use the\n"
	.string "dumbest strategy ever invented!\p"
	.string "Heal myself and delay you… but risk\n"
	.string "turning into a troublemaker zombie!\p"
	.string "You better not convince me to turn on\n"
	.string "my own father.\p"
	.string "But at least I buy him some more time.$"





MansionFloor3RoomBoss_Text_Boss3Ripley1:
	.string "Ripley: You're in over your heads, kids.\p"
	.string "You've just hatched, and are already\n"
	.string "radicalized and turned into fighting\l"
	.string "machines by that nefarious Abra.\p"
	.string "But it doesn't matter.\p"
	.string "Not only am I the strongest of Father's\n"
	.string "children, but I've got a secret weapon.\p"
	.string "A tank full of Fountain water.\p"
	.string "Father didn't let me use it on him, so\n"
	.string "I've got plenty to spare.\p"
	.string "When I'm through with you, I won't even\n"
	.string "need to throw you into the Fountain!$"


MansionFloor3RoomBoss_Text_Boss3Ripley2:
	.string "Ripley: I've… I've got nothing left.\p"
	.string "I guess it's time to see what all the\n"
	.string "fuss is about.$"





MansionFloor3RoomBoss_Eventscript_BrokenGlass::
	msgbox MansionFloor3RoomBoss_Text_BrokenGlass, MSGBOX_NPC
	end

MansionFloor3RoomBoss_Text_BrokenGlass:
	.string "There's a lot of broken glass here.\p"
	.string "Wait, this is it… This is the window that\n"
	.string "Craftily's goons throw you out of.\p"
	.string "You can see the Inkwell down there.$"


MansionFloor3RoomBoss_Eventscript_Window::
	msgbox MansionFloor3RoomBoss_Text_Window, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MansionFloor3RoomBoss_EventScript_DontLeave
	goto_if_eq VAR_RESULT, YES, MansionFloor3RoomBoss_EventScript_GameOver
	end

MansionFloor3RoomBoss_Text_Window:
	.string "You've been through this window before.\p"
	.string "Involuntarily.\p"
	.string "Do you want to jump into the Inkwell,\n"
	.string "resetting your memory?$"


@TOFOLD
MansionFloor3RoomBoss_EventScript_GameOver::
	end

MansionFloor3RoomBoss_EventScript_DontLeave::
	end
