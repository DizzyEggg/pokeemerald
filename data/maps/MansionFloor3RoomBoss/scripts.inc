MansionFloor3RoomBoss_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MansionFloor3RoomBoss_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MansionFloor3RoomBoss_OnFrame
	.byte 0

MansionFloor3RoomBoss_OnTransition:
	goto_if_set FLAG_BOSS3_CLEAR, MansionFloor1RoomBoss_EventScript_End
	setvar VAR_TEMP_0, 0
	end

MansionFloor3RoomBoss_OnFrame:
	.2byte 0


MansionFloor3RoomBoss_EventScript_BossFight::
	goto_if_unset FLAG_HIDE_BOSS3_TRIO, MansionFloor3RoomBoss_EventScript_BossAmy
	goto_if_unset FLAG_HIDE_BOSS3_DUO, MansionFloor3RoomBoss_EventScript_BossBella
	goto_if_unset FLAG_HIDE_BOSS3_SOLO, MansionFloor3RoomBoss_EventScript_BossRipley
	end

sText_TinkatonNickname:
	.string "AMY$"

sText_ScolipedeNickname:
	.string "BELLADONNA$"

sText_BlastoiseNickname:
	.string "RIPLEY$"

MansionFloor3RoomBoss_EventScript_BossAmy::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_AMY1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss1Amy1, FIELD_PIC_TINKATON_DETERMINED
	delay 30
	applymovement LOCALID_BELLA1, MansionFloor3RoomBoss_Talk
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss1Bella1, FIELD_PIC_SCOLIPEDE_ANGRY
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss1Amy2, FIELD_PIC_TINKATON_INSPIRED
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss1Amy3, FIELD_PIC_TINKATON_SAD
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss1Amy4, FIELD_PIC_TINKATON_HAPPY
	applymovement LOCALID_RIPLEY1, MansionFloor3RoomBoss_Talk
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss1Ripley1, FIELD_PIC_BLASTOISE_ANGRY
	delay 80
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss1Amy5, FIELD_PIC_TINKATON_ANGRY

	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1
	setwildbattle SPECIES_TINKATON, 55, ITEM_WEAKNESS_POLICY
    setenemymonnick 0, sText_TinkatonNickname
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	setflag FLAG_BOSS3_CLEAR
	
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss1Amy6, FIELD_PIC_TINKATON_DETERMINED
	applymovement LOCALID_AMY1, MansionFloor3RoomBoss_Charge1
	waitmovement 0
	@hit sound?
	@playse
	applymovement LOCALID_AMY1, MansionFloor3RoomBoss_Charge2
	applymovement OBJ_EVENT_ID_PLAYER, MansionFloor3RoomBoss_Charge3
	waitmovement 0
	removeobject LOCALID_AMY1
	removeobject OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_BELLA1, Common_Movement_ExclamationMark
	applymovement LOCALID_RIPLEY1, Common_Movement_ExclamationMark
	@EGGHELP
	@This is where both PCs and Amy get thrown into the fountain, so need game over with a falling Tinkaton as well
	releaseall
	end


MansionFloor3RoomBoss_Talk:
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

MansionFloor3RoomBoss_Charge1:
	walk_faster_down
	step_end

MansionFloor3RoomBoss_Charge2:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

MansionFloor3RoomBoss_Charge3:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end




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
	.string "Ripley's last resort technique…\n"
	.string "It's my only chance!\p"
	.string "Hiyaaaa!$"





MansionFloor3RoomBoss_EventScript_BossBella::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_BELLA2, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss2Bella1, FIELD_PIC_SCOLIPEDE_ANGRY
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 0, 0, 1
	
	setwildbattle SPECIES_SCOLIPEDE, 60, ITEM_METRONOME
    setenemymonmoves 0, MOVE_FURY_CUTTER, MOVE_ROLLOUT, 0, 0
	setenemymonnick 0, sText_ScolipedeNickname
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	setflag FLAG_BOSS3_CLEAR
	
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss2Bella2, FIELD_PIC_SCOLIPEDE_ANGRY
	delay 50
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss2Bella3, FIELD_PIC_SCOLIPEDE_WORRIED
	applymovement LOCALID_BELLA2, MansionFloor3RoomBoss_Charge1
	waitmovement 0
	@hit sound?
	@playse
	applymovement LOCALID_BELLA2, MansionFloor3RoomBoss_Charge2
	applymovement OBJ_EVENT_ID_PLAYER, MansionFloor3RoomBoss_Charge3
	waitmovement 0
	removeobject LOCALID_BELLA2
	removeobject OBJ_EVENT_ID_PLAYER

	@EGGHELP2 - game over script. This is where both PCs and Bella get thrown into the fountain, so need a game over with a falling Scolipede
	
	releaseall
	end






MansionFloor3RoomBoss_Text_Boss2Bella1:
	.string "Bella: Hmph.\p"
	.string "Father doesn't like it when I hurt\n"
	.string "his children.\p"
	.string "Oh sure, we have the Fountain, but\n"
	.string "fear doesn't heal.\p"
	.string "But.\p"
	.string "Father also doesn't like being\n"
	.string "disturbed or reminded of the past.\p"
	.string "Which means… I get to hurt you.\p"
	.string "Guilt-free.\p"
	.string "Prepare.$"


MansionFloor3RoomBoss_Text_Boss2Bella2:
	.string "Bella: Damn it!\p"
	.string "Now I've got no choice but to use the\n"
	.string "dumbest strategy ever invented!\p"
	.string "Heal myself and delay you… but risk\n"
	.string "turning into a troublemaker zombie!$"

MansionFloor3RoomBoss_Text_Boss2Bella3:
	.string "…\p"
	.string "You better not convince me to turn on\n"
	.string "my own father.\p"
	.string "At least I can buy him some time.$"






MansionFloor3RoomBoss_EventScript_BossRipley::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_RIPLEY3, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss3Ripley1, FIELD_PIC_BLASTOISE_NORMAL
	
	@EGGHELP1 - same problem with createmon.
	
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 0, 0, 1
	setwildbattle SPECIES_BLASTOISE, 65, ITEM_LEFTOVERS
	setenemymonmoves 0, MOVE_WAVE_CRASH, MOVE_PROTECT, MOVE_AQUA_RING, 0
	setenemymonnick 0, sText_BlastoiseNickname
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	setflag FLAG_BOSS3_CLEAR
	
	msgbox_portrait MansionFloor3RoomBoss_Text_Boss2Bella2, FIELD_PIC_BLASTOISE_PAIN
	applymovement LOCALID_RIPLEY3, MansionFloor3RoomBoss_Charge1
	waitmovement 0
	@hit sound?
	@playse
	applymovement LOCALID_RIPLEY3, MansionFloor3RoomBoss_Charge2
	applymovement OBJ_EVENT_ID_PLAYER, MansionFloor3RoomBoss_Charge3
	waitmovement 0
	removeobject LOCALID_BELLA2
	removeobject OBJ_EVENT_ID_PLAYER
	@EGGHELP2 Another game over with a falling Blastoise
	releaseall
	end





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


MansionFloor3RoomBoss_EventScript_GameOver::
    dowhiteout
	end

MansionFloor3RoomBoss_EventScript_DontLeave::
	end
