PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition:
	setflag FLAG_VISITED_PETALBURG_CITY
	goto_if_set FLAG_SYS_B_DASH, Fountain_Eventscript_NotFirstLoad
	setvar VAR_PETALBURG_CITY_STATE, 1
	@call_if_eq VAR_PETALBURG_CITY_STATE, 0, PetalburgCity_EventScript_MoveGymBoyToWestEntrance
	end

PetalburgCity_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 1, Fountain_EventScript_IntroScene
	@map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
	.2byte 0

Fountain_EventScript_End::
	end


Fountain_Eventscript_NotFirstLoad::
	setvar VAR_PETALBURG_CITY_STATE, 0
	addobject LOCALID_ABRA_WELL
	end

@@@@@ Intro cutscene

Fountain_EventScript_IntroScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookLeft
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookRight
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookDown
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	msgbox_portrait Fountain_Text_Intro01, FIELD_PIC_PHANPY_SAD
	delay 50
	playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	waitmovement 0
	msgbox_portrait Fountain_Text_Intro02, FIELD_PIC_PHANPY_SWEAT
	msgbox_portrait Fountain_Text_Intro03, FIELD_PIC_ABRA_SERIOUS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox_portrait Fountain_Text_Intro04, FIELD_PIC_PHANPY_CONFUSED
	msgbox_portrait Fountain_Text_Intro05, FIELD_PIC_ABRA_CONCERNED
	applymovement LOCALID_ABRA_WELL, Fountain_LookUp
	waitmovement 0
	delay 20

	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_CameraMove1
	waitmovement 0
	delay 30
	addobject LOCAL_ID_ALTARIA_INTRO
	applymovement LOCAL_ID_ALTARIA_INTRO, Fountain_FallIntoWater
	delay 10
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_FallIntoWater
	waitmovement 0
	removeobject LOCAL_ID_ALTARIA_INTRO
	playse SE_M_DIVE
	waitse
	delay 30
	addobject LOCALID_ABRA_WELL
	applymovement LOCALID_ABRA_WELL, Fountain_LookUp
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_CameraMove3
	waitmovement 0
	delay 20

	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	delay 10
	msgbox_portrait Fountain_Text_Intro06, FIELD_PIC_ABRA_DETERMINED
	delay 10
	playse SE_WARP_OUT
	removeobject LOCALID_ABRA_WELL
	delay 80
	playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	addobject LOCALID_EGG_INTRO
	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	delay 10
	msgbox_portrait Fountain_Text_Intro07, FIELD_PIC_ABRA_SWEAT
	fadescreenspeed FADE_TO_BLACK, 2
	delay 20
	removeobject LOCALID_EGG_INTRO
    addobject LOCALID_SWABLU_INTRO
    playegghatchanim SPECIES_SWABLU, TRUE
    waitstate
	applymovement LOCALID_SWABLU_INTRO, Fountain_LookUp
	waitmovement 0
	delay 10
	fadescreenspeed FADE_FROM_BLACK, 2

	delay 30
	msgbox_portrait Fountain_Text_Intro08, FIELD_PIC_ABRA_HAPPY
	applymovement LOCALID_SWABLU_INTRO, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox_portrait Fountain_Text_Intro09, FIELD_PIC_SWABLU_YELL
	msgbox_portrait Fountain_Text_Intro10, FIELD_PIC_ABRA_JOY
	msgbox_portrait Fountain_Text_Intro11, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_Intro12, FIELD_PIC_ABRA_CONCERNED
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookRight
	applymovement LOCALID_SWABLU_INTRO, Fountain_LookLeft
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	applymovement LOCALID_SWABLU_INTRO, Fountain_LookUp
	waitmovement 0
	delay 20
	msgbox_portrait Fountain_Text_Intro13, FIELD_PIC_SWABLU_ANGRY
	msgbox_portrait Fountain_Text_Intro14, FIELD_PIC_PHANPY_SAD
	applymovement LOCALID_ABRA_WELL, Fountain_LookUp
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_CameraMove4
	waitmovement 0
	delay 20
	msgbox_portrait Fountain_Text_Intro15, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_Intro16, FIELD_PIC_PHANPY_DETERMINED
	msgbox_portrait Fountain_Text_Intro17, FIELD_PIC_ABRA_CONCERNED
	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	waitmovement 0
	delay 30
	msgbox_portrait Fountain_Text_Intro18, FIELD_PIC_ABRA_DETERMINED
	msgbox_portrait Fountain_Text_Intro19, FIELD_PIC_ABRA_ANGRY
	@TOFOLD
	@applymovement OBJ_EVENT_ID_PLAYER, Fountain_Shudder
	@applymovement LOCALID_SWABLU_INTRO, Fountain_Shudder
	waitmovement 0
	delay 30
	msgbox_portrait Fountain_Text_Intro20, FIELD_PIC_PHANPY_SAD
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookLeft
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	delay 20
	msgbox_portrait Fountain_Text_Intro21, FIELD_PIC_PHANPY_DETERMINED
	msgbox_portrait Fountain_Text_Intro22, FIELD_PIC_SWABLU_ANGRY
	msgbox_portrait Fountain_Text_Intro23, FIELD_PIC_ABRA_THINKING
	msgbox_portrait Fountain_Text_Intro24, FIELD_PIC_SWABLU_ANGRY
	msgbox_portrait Fountain_Text_Intro25, FIELD_PIC_ABRA_ANGRY
	msgbox_portrait Fountain_Text_Intro26, FIELD_PIC_PHANPY_SAD
	msgbox_portrait Fountain_Text_Intro27, FIELD_PIC_ABRA_DETERMINED
	msgbox_portrait Fountain_Text_Intro28, FIELD_PIC_SWABLU_ANGRY
	applymovement LOCALID_ABRA_WELL, Fountain_LookUp
	waitmovement 0
	delay 20
	msgbox_portrait Fountain_Text_Intro29, FIELD_PIC_ABRA_CRY
	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	waitmovement 0
	delay 30
	msgbox_portrait Fountain_Text_Intro30, FIELD_PIC_ABRA_CONCERNED
	
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_POKEMON_GET
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setvar VAR_PETALBURG_CITY_STATE 1
	warpsilent MAP_PETALBURG_CITY,24,46
	release
	releaseall
	end






Fountain_LookUp:
	face_up
	step_end

Fountain_LookDown:
	face_down
	step_end

Fountain_LookLeft:
	face_left
	step_end

Fountain_LookRight:
	face_right
	step_end

Fountain_CameraMove1:
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Fountain_FallIntoWater:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down	
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

Fountain_CameraMove3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	step_end

Fountain_CameraMove4:
	walk_up
	walk_up
	step_end

Fountain_Shudder:
	walk_in_place_faster_up
	end


Fountain_Text_Intro01:
	.string "Tuskan: Huh? Where… wasn’t there a…$"

Fountain_Text_Intro02:
	.string "Tuskan: Hey… a-are you my…?$"

Fountain_Text_Intro03:
	.string "???: Welcome back, Tuskan.$"

Fountain_Text_Intro04:
	.string "Tuskan: Welcome back? What?$"

Fountain_Text_Intro05:
	.string "???: Hold on, it'll be easier to explain\n"
	.string "it to both of you together.$"

Fountain_Text_Intro06:
	.string "???: Wait here a moment - I have to\n"
	.string "Teleport her out of the well.$"

Fountain_Text_Intro07:
	.string "???: Just wait a minute for her to \n"
	.string "hatch, and then I'll explain everything.$"

Fountain_Text_Intro08:
	.string "???: Ahem.\p"
	.string "Welcome back, Tuskan and Fluffball.\n"
	.string "My name is Dali.$"

Fountain_Text_Intro09:
	.string "Fluffball: Wait, Fluffball? My name\n"
	.string "is Fluffball?$"

Fountain_Text_Intro10:
	.string "Dali: You ask me that every time you\n"
	.string "hatch! Yep, that's your name!$"

Fountain_Text_Intro11:
	.string "Dali: And yes, you've been here before.\p"
	.string "Even though you're newly hatched,\n"
	.string "we've had this conversation before.$"

Fountain_Text_Intro12:
	.string "Dali: Tuskan, you saw it, didn't you?\p"
	.string "You saw Fluffball falling into the well,\n"
	.string "and coming out as an egg.\p"
	.string "Do you remember anything from before\n"
	.string "you fell in?$"

Fountain_Text_Intro13:
	.string "Fluffball: I… remember fighting. Anger.\n"
	.string "Betrayal.$"

Fountain_Text_Intro14:
	.string "Tuskan: I remember fighting too. Why\n"
	.string "can't we remember?$"

Fountain_Text_Intro15:
	.string "Dali: It's because of this dark well.\n"
	.string "I call it the Inkwell.\p"
	.string "The inky water heals all, but it makes\n"
	.string "you… younger. It takes away your\l"
	.string "experience and memories.\p"
	.string "Taking a small sip is safe, but falling\n"
	.string "in quickly turns you back into an egg.$"

Fountain_Text_Intro16:
	.string "Tuskan: But why were we in that place?\n"
	.string "And who threw us into the Inkwell?$"

Fountain_Text_Intro17:
	.string "Dali: …$"

Fountain_Text_Intro18:
	.string "Dali: I'm going to say a name.\n"
	.string "Tell me what you remember about it.$"

Fountain_Text_Intro19:
	.string "Dali: Craftily.$"

Fountain_Text_Intro20:
	.string "Tuskan: I…$"

Fountain_Text_Intro21:
	.string "Tuskan: I don't like that name. He did\n"
	.string "something to us.$"

Fountain_Text_Intro22:
	.string "Fluffball: Craftily… he… he betrayed us.$"

Fountain_Text_Intro23:
	.string "Dali: I think Craftily did this to us.\p"
	.string "I don't remember what happened either…\n"
	.string "Don’t even remember what he looks like.\p"
	.string "But we’re all weak, and he’s so strong.\p"
	.string "I can only guess that there was a \n"
	.string "terrible battle, and Craftily won and\l"
	.string "forced us into the Inkwell.$"

Fountain_Text_Intro24:
	.string "Fluffball: Why would he do that?$"

Fountain_Text_Intro25:
	.string "Dali: I don't know.\p"
	.string "What I do know is that there's a deep,\n"
	.string "half-forgotten anger I feel when I\l"
	.string "hear that name, and you feel it too.$"

Fountain_Text_Intro26:
	.string "Tuskan: But… what can we do?$"

Fountain_Text_Intro27:
	.string "Dali: You two have to get to Craftily in\n"
	.string "the mansion to find out what happened.\p"
	.string "With some strategy and a little luck,\n"
	.string "maybe you can beat him, and get him to\l"
	.string "confess to whatever he did to us.\p"
	.string "He might be the only one left who knows.\p"
	.string "But the Pokemon in the mansion believe\n"
	.string "Craftily's a hero. They will fight and\l"
	.string "throw you in the Inkwell if they can.$"

Fountain_Text_Intro28:
	.string "Fluffball: He is not a hero. I feel it\n"
	.string "in my soul. He betrayed us.$"

Fountain_Text_Intro29:
	.string "Dali: …only the three of us know that.\p"
	.string "And I… I can't fight. The only thing I\n"
	.string "can do is Teleport to help you a little,\l"
	.string "and keep the memories alive for us.\p"
	.string "And every time you come back, I have to\n"
	.string "ask you to go back in there and fight.$"

Fountain_Text_Intro30:
	.string "Dali: So explore around here all you \n"
	.string "like; I'll tell you everything I know.\p"
	.string "But… please go find Craftily. Figuring\n"
	.string "out what happened is our only way out.$"






@@@@@@ Abra Triggers

Fountain_EventScript_Abra_Mansion_Trigger::
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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
	goto_if_set FLAG_ABRA_IN_PARTY, Fountain_EventScript_End
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




@@@@@@ INTRO




@@@@@@@
@ Abra events - TOFOLD


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
	.string "I don't know much about this building.\p"
	.string "I don't have words for it… but it looks\p"
	.string "It is automatically sent to a STORAGE\n"
	.string "BOX over a PC connection.$"

Fountain_Text_AbraGarden1:
	.string "This area is different from the rest of\p"
	.string "the ground. \p"
	.string "It is automatically sent to a STORAGE\n"
	.string "BOX over a PC connection.$"

Fountain_Text_AbraGrave1:
	.string "Dali: I don't like coming here.\n"
	.string "That stone makes me uncomfortable.\p"
	.string "I think I knew how to read those\n"
	.string "markings once, but not anymore.$"

Fountain_Text_AbraGrave2:
	.string "Dali: I've put that strange picture\n"
	.string "piece you found here.\p"
	.string "Maybe if you find them all, the picture\n"
	.string "will help us understand.$"

Fountain_Text_AbraGraveComplete1:
	.string "Dali: The picture's complete!\n"
	.string "Now, let's see here…$"

Fountain_Text_AbraGraveComplete2:
	.string "Dali: This… this looks like us.$"

Fountain_Text_AbraGraveComplete3:
	.string "Dali: That's Fluffball, on the right.\n"
	.string "That's what she looks like evolved.\p"
	.string "Next to her… is that really me?\n"
	.string "I look… so confident…$"
	.string "And on her other side… that's him.\n"
	.string "That's Craftily.$"

Fountain_Text_AbraGraveComplete4:
	.string "Dali: We were all friends once.\n"
	.string "I remember. We were… a team.\p"
	.string "I recognize the others, too.\n"
	.string "Bella, Amy, Ripley…$"

Fountain_Text_AbraGraveComplete5:
	.string "Dali: And that one in the middle.\n"
	.string "Not a Pokemon. A… a trainer.\p"
	.string "What… what happened to her?$"

Fountain_Text_AbraGraveComplete6:
	.string "Dali: I need some time to think.\p"
	.string "Come back later and I'll tell you\n"
	.string "what I've figured out.$"

Fountain_Text_AbraGraveRecruit1:
	.string "Dali: Okay. I have some thoughts.\p"
	.string "First, we used to be a team, like a\n"
	.string "family. Maybe we lived here.\p"
	.string "Second, Craftily betrayed us. \n"
	.string "family. Maybe we lived here.\p"
	.string "First, we used to be a team, like a\n"
	.string "family. Maybe we lived here.$"
@TOFOLD




@@@@@ Static Events - TOFOLD

Fountain_EventScript_Grave::
	goto_if_set FLAG_SECRET_ENDING_COMPLETE, Fountain_EventScript_GraveEnd
	msgbox Fountain_Text_Grave, MSGBOX_NPC
	end

Fountain_EventScript_GraveEnd::
	msgbox Fountain_Text_GraveEnd, MSGBOX_NPC
	end

Fountain_Text_Grave:
	.string "A smooth pale stone covered in strange,\n"
	.string "worn markings.\p"
	.string "It makes you feel... sad?$"

Fountain_Text_GraveEnd:
	.string "This must be Ada's grave.\p"
	.string "TODO"
	.string "$"



Fountain_EventScript_PhotoStump::
	goto_if_set FLAG_OBTAINED_PHOTO1, Fountain_EventScript_PhotoCheck
	goto_if_set FLAG_OBTAINED_PHOTO2, Fountain_EventScript_PhotoCheck
	goto_if_set FLAG_OBTAINED_PHOTO3, Fountain_EventScript_PhotoCheck
	goto_if_set FLAG_OBTAINED_PHOTO4, Fountain_EventScript_PhotoCheck
	goto_if_set FLAG_OBTAINED_PHOTO5, Fountain_EventScript_PhotoCheck
	end

Fountain_EventScript_PhotoCheck::
	goto_if_unset FLAG_OBTAINED_PHOTO1, Fountain_EventScript_IncompletePhoto
	goto_if_unset FLAG_OBTAINED_PHOTO2, Fountain_EventScript_IncompletePhoto
	goto_if_unset FLAG_OBTAINED_PHOTO3, Fountain_EventScript_IncompletePhoto
	goto_if_unset FLAG_OBTAINED_PHOTO4, Fountain_EventScript_IncompletePhoto
	goto_if_unset FLAG_OBTAINED_PHOTO5, Fountain_EventScript_IncompletePhoto
	msgbox Fountain_Text_CompletePhoto, MSGBOX_NPC

Fountain_Text_CompletePhoto:
	.string "You've found all of the pieces of the\n"
	.string "old picture.$"
@TODO - add picture, add Abra reaction and agreeing to join you


Fountain_EventScript_IncompletePhoto::
	msgbox Fountain_Text_IncompletePhoto, MSGBOX_NPC
	end

Fountain_Text_IncompletePhoto:
	.string "The pieces of that odd picture you\n"
	.string "found are assembled here.\p"
	.string "It doesn't look complete yet.\n"
	.string "found are assembled here.$"




Fountain_EventScript_GardenTrees::
	msgbox Fountain_Text_GardenTrees, MSGBOX_NPC
	end

Fountain_Text_GardenTrees:
	.string "Withered, decrepit trees. The plot\n"
	.string "looks like it was once a nice garden.$"


Fountain_EventScript_Birdhouse::
	msgbox Fountain_Text_Birdhouse, MSGBOX_NPC
	end

Fountain_Text_Birdhouse:
	.string "A quiet birdhouse. There are still a few\n"
	.string "seeds inside.$"


Fountain_EventScript_Campfire::
	msgbox Fountain_Text_Campfire, MSGBOX_NPC
	end

Fountain_Text_Campfire:
	.string "A ring of stones around a smoky black\n"
	.string "pit. The logs around here make this\l"
	.string "a nice place to rest.$"


Fountain_EventScript_Gate::
	msgbox Fountain_Text_Gate, MSGBOX_NPC
	end

Fountain_Text_Gate:
	.string "Thorny vines interlace with the\n"
	.string "ornate metal gate. There's no way\l"
	.string "you can open this.$"





Fountain_EventScript_Inkwell::
	msgbox Fountain_Text_Inkwell, MSGBOX_NPC
	end

Fountain_Text_Inkwell:
	.string "The Inkwell is full of dark, inky water.\p"
	.string "You can feel a sinister energy coming\n"
	.string "from the depths.$"



Fountain_EventScript_Stacks::
	msgbox Fountain_Text_Stacks, MSGBOX_NPC
	end

Fountain_Text_Stacks:
	.string "These appear to be tiles, like the\n"
	.string "ancient stone around the Inkwell.\p"
	.string "Why are they stacked up here?$"



Fountain_EventScript_ShedDoor::
	msgbox Fountain_Text_ShedDoor, MSGBOX_NPC
	end

Fountain_Text_ShedDoor:
	.string "It's covered in thick, thorny vines.\n"
	.string "They're too tough to cut.$"




Fountain_EventScript_BackDoor::
	msgbox Fountain_Text_BackDoor, MSGBOX_NPC
	end

Fountain_Text_BackDoor:
	.string "It's covered in thick, thorny vines.\n"
	.string "They're too tough to cut.$"



































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
