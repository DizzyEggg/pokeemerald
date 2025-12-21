MansionFloor2RoomBoss_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MansionFloor2RoomBoss_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MansionFloor2RoomBoss_OnFrame
	.byte 0

MansionFloor2RoomBoss_OnTransition:
	goto_if_set FLAG_BOSS2_CLEAR, MansionFloor1RoomBoss_EventScript_End
	setvar VAR_TEMP_0, 1
	end

MansionFloor2RoomBoss_OnFrame:
	.2byte 0

MansionFloor2RoomBoss_EventScript_HaunterScenePicker::
	goto_if_unset FLAG_HIDE_BOSS3_TRIO, MansionFloor2RoomBoss_EventScript_HaunterScene1
	goto_if_unset FLAG_HIDE_BOSS3_DUO, MansionFloor2RoomBoss_EventScript_HaunterScene2
	goto_if_unset FLAG_HIDE_BOSS3_SOLO, MansionFloor2RoomBoss_EventScript_HaunterScene3
	goto MansionFloor2RoomBoss_EventScript_HaunterScene4
	end

MansionFloor2RoomBoss_EventScript_HaunterScene1::
	lockall
	setvar VAR_TEMP_0, 0
	playbgm MUS_PMDRED_TINY_WOODS, FALSE
	applymovement LOCALID_HAUNTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor2RoomBoss_Text_Haunter1, FIELD_PIC_HAUNTER_INSPIRED
	delay 80
	applymovement LOCALID_HAUNTER, MansionFloor2RoomBoss_LookLeft
	waitmovement 0
	delay 100
	msgbox_portrait MansionFloor2RoomBoss_Text_Haunter2, FIELD_PIC_HAUNTER_SIGH
	delay 20
	applymovement LOCALID_HAUNTER, MansionFloor2RoomBoss_LookRight
	waitmovement 0
	msgbox_portrait MansionFloor2RoomBoss_Text_Haunter3, FIELD_PIC_HAUNTER_YELL
	setwildbattle SPECIES_HAUNTER, 25, ITEM_WIDE_LENS, SPECIES_SNORLAX, 32, ITEM_LEFTOVERS
	setenemymonstatus 1, STATUS1_SLEEP - 3 @ STATUS1_SLEEP is 7 sleep turns by default
    @setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	fadedefaultbgm
	setflag FLAG_BOSS2_CLEAR
	removeobject LOCALID_HAUNTER
	removeobject LOCALID_SNORLAX
	releaseall
	end




MansionFloor2RoomBoss_Text_Haunter1:
	.string "No.\p"
	.string "Those were just the creaky noises this\n"
	.string "house always makes.\p"
	.string "There's no one behind me.\p"
	.string "And even if there was, they're just here\n"
	.string "for a friendly visit.\p"
	.string "They're definitely not the troublemakers\n"
	.string "interrupting my lunch break yet again.\p"
	.string "Definitely not.$"

MansionFloor2RoomBoss_Text_Haunter2:
	.string "Um.\p"
	.string "I don't get it.\p"
	.string "Not only are you harassing your own\n"
	.string "old, sick father, you're interrupting\l"
	.string "my lunch.\p"
	.string "And today's lunch was about running\n"
	.string "out of food! There was a narrative!\p"
	.string "Okay, fine. Whatever.$"

MansionFloor2RoomBoss_Text_Haunter3:
	.string "HEY! BIG LUG! THEY'RE HERE!$"


@@@@ New scenes for Haunter


MansionFloor2RoomBoss_EventScript_HaunterScene2::
	lockall
	setvar VAR_TEMP_0, 0
	playbgm MUS_PMDRED_TINY_WOODS, FALSE
	applymovement LOCALID_HAUNTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	applymovement LOCALID_HAUNTER, MansionFloor2RoomBoss_LookLeft
	waitmovement 0
	delay 100
	msgbox_portrait MansionFloor2RoomBoss_Text_HaunterRematchA1, FIELD_PIC_HAUNTER_SIGH
	delay 20
	applymovement LOCALID_HAUNTER, MansionFloor2RoomBoss_LookRight
	waitmovement 0
	msgbox_portrait MansionFloor2RoomBoss_Text_HaunterRematchA2, FIELD_PIC_HAUNTER_YELL
	setwildbattle SPECIES_HAUNTER, 25, ITEM_WIDE_LENS, SPECIES_SNORLAX, 32, ITEM_LEFTOVERS
	setenemymonstatus 1, STATUS1_SLEEP - 3 @ STATUS1_SLEEP is 7 sleep turns by default
    @setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	fadedefaultbgm
	setflag FLAG_BOSS2_CLEAR
	removeobject LOCALID_HAUNTER
	removeobject LOCALID_SNORLAX
	releaseall
	end



MansionFloor2RoomBoss_Text_HaunterRematchA1:
	.string "Awww, not again!\n"
	.string "I was just getting to the good part!\p"
	.string "Today's meal is about being chased by\n"
	.string "an angry Infernape!\p"	
	.string "And it's a Ghost! And Levitating!\n"
	.string "And it has Heal Block!\p"
	.string "…Not that you care how tasty it is. You\n"
	.string "just want to see me suffer.\p"
	.string "And… you want my friend here to suffer\n"
	.string "less. Until you beat him up again.\p"
	.string "Ugh. Priorities all mixed up.$"

MansionFloor2RoomBoss_Text_HaunterRematchA2:
	.string "WAKE UP! THEY'RE HERE!$"



MansionFloor2RoomBoss_EventScript_HaunterScene3::
	lockall
	setvar VAR_TEMP_0, 0
	playbgm MUS_PMDRED_TINY_WOODS, FALSE
	applymovement LOCALID_HAUNTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	applymovement LOCALID_HAUNTER, MansionFloor2RoomBoss_LookLeft
	waitmovement 0
	delay 40
	msgbox_portrait MansionFloor2RoomBoss_Text_HaunterRematchB1, FIELD_PIC_HAUNTER_SIGH
	delay 20
	applymovement LOCALID_HAUNTER, MansionFloor2RoomBoss_LookRight
	waitmovement 0
	msgbox_portrait MansionFloor2RoomBoss_Text_HaunterRematchB2, FIELD_PIC_HAUNTER_YELL
	setwildbattle SPECIES_HAUNTER, 25, ITEM_WIDE_LENS, SPECIES_SNORLAX, 32, ITEM_LEFTOVERS
	setenemymonstatus 1, STATUS1_SLEEP - 3 @ STATUS1_SLEEP is 7 sleep turns by default
    @setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	fadedefaultbgm
	setflag FLAG_BOSS2_CLEAR
	removeobject LOCALID_HAUNTER
	removeobject LOCALID_SNORLAX
	releaseall
	end


MansionFloor2RoomBoss_Text_HaunterRematchB1:
	.string "Noooooo!\p"
	.string "Not during the falling dream!\p"
	.string "Snorlaxes don't really move, so falling\n"
	.string "dreams are really rare!\p"	
	.string "Aaah, why nowwww???$"

MansionFloor2RoomBoss_Text_HaunterRematchB2:
	.string "YOU'RE NOT FALLING! GET UP!$"



MansionFloor2RoomBoss_EventScript_HaunterScene4::
	lockall
	setvar VAR_TEMP_0, 0
	playbgm MUS_PMDRED_TINY_WOODS, FALSE
	applymovement LOCALID_HAUNTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_HAUNTER, MansionFloor2RoomBoss_LookLeft
	waitmovement 0
	delay 40
	msgbox_portrait MansionFloor2RoomBoss_Text_HaunterRematchC1, FIELD_PIC_HAUNTER_SIGH
	delay 40
	msgbox_portrait MansionFloor2RoomBoss_Text_HaunterRematchC2, FIELD_PIC_HAUNTER_INSPIRED
	delay 80
	msgbox_portrait MansionFloor2RoomBoss_Text_HaunterRematchC3, FIELD_PIC_HAUNTER_SIGH
	delay 80
	applymovement LOCALID_HAUNTER, MansionFloor2RoomBoss_LookRight
	waitmovement 0
	msgbox_portrait MansionFloor2RoomBoss_Text_HaunterRematchC4, FIELD_PIC_HAUNTER_YELL
	setwildbattle SPECIES_HAUNTER, 25, ITEM_WIDE_LENS, SPECIES_SNORLAX, 32, ITEM_LEFTOVERS
	setenemymonstatus 1, STATUS1_SLEEP - 4 @ STATUS1_SLEEP is 7 sleep turns by default
    @setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	fadedefaultbgm
	setflag FLAG_BOSS2_CLEAR
	removeobject LOCALID_HAUNTER
	removeobject LOCALID_SNORLAX
	releaseall
	end


MansionFloor2RoomBoss_Text_HaunterRematchC1:
	.string "…sigh.\p"
	.string "Well, at least you're not interrupting\n"
	.string "my meal this time.\p"
	.string "The big oaf is just enjoying a deep,\n"	
	.string "dreamless sleep.$"

MansionFloor2RoomBoss_Text_HaunterRematchC2:
	.string "Don't you think it would be nice to give\n"
	.string "the lug a break? That's what I'm doing.\p"
	.string "…$"

MansionFloor2RoomBoss_Text_HaunterRematchC3:
	.string "Welp, it was worth a shot.\p"
	.string "Just… just don't hurt Father.$"

MansionFloor2RoomBoss_Text_HaunterRematchC4:
	.string "HEY! BATTLE TIME!$"




MansionFloor2RoomBoss_LookLeft:
	face_left
	step_end

MansionFloor2RoomBoss_LookRight:
	face_right
	step_end



@@@@@ Static Events

MansionFloor2RoomBoss_EventScript_Cushion::
	msgbox MansionFloor2RoomBoss_Text_Cushion, MSGBOX_NPC
	end

MansionFloor2RoomBoss_Text_Cushion:
	.string "A huge, fluffy, pink cushion.\n"
	.string "It looks extremely comfy.$"


MansionFloor2RoomBoss_EventScript_Hole::
	msgbox MansionFloor2RoomBoss_Text_Hole, MSGBOX_NPC
	end

MansionFloor2RoomBoss_Text_Hole:
	.string "Beside the cushion, there's a perfectly\n"
	.string "circular hole in the ground.$"


MansionFloor2RoomBoss_EventScript_Fluff::
	msgbox MansionFloor2RoomBoss_Text_Fluff, MSGBOX_NPC
	end

MansionFloor2RoomBoss_Text_Fluff:
	.string "Whoa, there's a huge pile of fluff here!\n"
	.string "Feathers or cotton?$"


MansionFloor2RoomBoss_EventScript_Stool::
	msgbox MansionFloor2RoomBoss_Text_Stool, MSGBOX_NPC
	end

MansionFloor2RoomBoss_Text_Stool:
	.string "An old stool, covered in dead vines.$"


MansionFloor2RoomBoss_EventScript_Teleport::
	msgbox MansionFloor2RoomBoss_Text_Teleport, MSGBOX_NPC
	end

MansionFloor2RoomBoss_Text_Teleport:
	.string "A strange diamondshape sigil. It looks\n"
	.string "like Abra's teleport pads.$"


MansionFloor2RoomBoss_EventScript_Bed::
	msgbox MansionFloor2RoomBoss_Text_Bed, MSGBOX_NPC
	end

MansionFloor2RoomBoss_Text_Bed:
	.string "A big pink bed. It doesn't look like it's\n"
	.string "been used in a while…$"


MansionFloor2RoomBoss_EventScript_Tub::
	msgbox MansionFloor2RoomBoss_Text_Tub, MSGBOX_NPC
	end

MansionFloor2RoomBoss_Text_Tub:
	.string "There's a depression in the floor here,\n"
	.string "tiled with broken and grimy tiles.\p"
	.string "Looks like the water has dried up.$"


MansionFloor2RoomBoss_EventScript_LongMat::
	msgbox MansionFloor2RoomBoss_Text_LongMat, MSGBOX_NPC
	end

MansionFloor2RoomBoss_Text_LongMat:
	.string "A super-long woven mat.\n"
	.string "It's covered in strange claw marks.$"
