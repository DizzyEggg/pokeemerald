PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition:
	setflag FLAG_VISITED_PETALBURG_CITY
	goto_if_set FLAG_SYS_B_DASH, Fountain_Eventscript_NotFirstLoad
	setvar VAR_PETALBURG_CITY_STATE, 1
	end

PetalburgCity_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 1, Fountain_EventScript_IntroScene
	.2byte 0

Fountain_EventScript_End::
	end


Fountain_Eventscript_NotFirstLoad::
	setvar VAR_PETALBURG_CITY_STATE, 0
	addobject LOCALID_ABRA_WELL
	
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
	setvar VAR_TEMP_A, 0
	
	@check for photo pieces
	checkitem UNIQUE_ITEM_PHOTO_1, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_GotPhoto
	checkitem UNIQUE_ITEM_PHOTO_2, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_GotPhoto
	checkitem UNIQUE_ITEM_PHOTO_3, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_GotPhoto
	checkitem UNIQUE_ITEM_PHOTO_4, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_GotPhoto
	checkitem UNIQUE_ITEM_PHOTO_5, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_GotPhoto
	end
    

Fountain_EventScript_GotPhoto::
	clearflag FLAG_NO_PHOTOS
	end



Fountain_FallIntoWaterWhiteOut:
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
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end
    
Fountain_ThirdFallIntoWaterWhiteOut:
    applymovement LOCALID_FALLING_THIRD, Fountain_FallIntoWaterWhiteOut
    goto Fountain_EventScript_WhiteoutContinueFall
    
Fountain_ThirdFallWaterSplash:
    splashwatereffect LOCALID_SPLASH_3
    goto Fountain_EventScript_WhiteoutContinueSplash
    
@ Partner localId - 0x8007

Fountain_WhiteOutPartnerSwablu:
    setvar VAR_0x8007, LOCALID_FIREPLACE_SWABLU
    clearflag FLAG_FIREPLACE_HIDE_SWABLU
    goto Fountain_EventScript_WhiteoutDoEggHatch
    
Fountain_WhiteOutPartnerPhanpy:
    setvar VAR_0x8007, LOCALID_FIREPLACE_PHANPY
    clearflag FLAG_FIREPLACE_HIDE_PHANPY
    goto Fountain_EventScript_WhiteoutDoEggHatch
   
       
@@@@@ After White-out cutscene
Fountain_EventScript_Whiteout::
    lockall
    applymovement OBJ_EVENT_ID_PLAYER, Fountain_FallIntoWaterWhiteOut
    applymovement LOCALID_FALLING_PARTNER, Fountain_FallIntoWaterWhiteOut
    goto_if_unset FLAG_WHITEOUT_FALLING_THIRD_NPC, Fountain_ThirdFallIntoWaterWhiteOut
Fountain_EventScript_WhiteoutContinueFall:
    playse SE_FALL
    waitmovement 0
    setspriteinvisible OBJ_EVENT_ID_PLAYER, TRUE
    setspriteinvisible LOCALID_FALLING_PARTNER, TRUE
    setspriteinvisible LOCALID_FALLING_THIRD, TRUE
    splashwatereffect LOCALID_SPLASH_1
    splashwatereffect LOCALID_SPLASH_2
    goto_if_unset FLAG_WHITEOUT_FALLING_THIRD_NPC, Fountain_ThirdFallWaterSplash
Fountain_EventScript_WhiteoutContinueSplash:
    delay 5
    playse SE_PUDDLE
    playse SE_PUDDLE
    waitfieldeffect FLDEFF_JUMP_BIG_SPLASH
    removeobject LOCALID_FALLING_PARTNER
    removeobject LOCALID_FALLING_THIRD
    setobjectxy OBJ_EVENT_ID_PLAYER, 24, 46
    setplayerxy 24, 46
    setspriteinvisible OBJ_EVENT_ID_PLAYER, FALSE
    @ Okay, the hard part is here. Partner and possible 3rd mon get devolved, so we move their sprites from fireplace and clear the flag
Fountain_EventScript_WhiteoutGetPartner:
    callnative ScriptCmd_GetPartnerSpecies
    goto_if_eq VAR_RESULT, SPECIES_SWABLU, Fountain_WhiteOutPartnerSwablu
    goto_if_eq VAR_RESULT, SPECIES_PHANPY, Fountain_WhiteOutPartnerPhanpy
Fountain_EventScript_WhiteoutDoEggHatch:
    fasttwomonsegghatchanim
    changeplayersprite SPECIES_NONE, TRUE, FALSE
    delay 20
Fountain_EventScript_MoveObjectsToSpot:
    addobject VAR_0x8007
    setobjectxy VAR_0x8007, 26, 46
    waitstate
    @ Copied from IntroScene
    lockall
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	applymovement VAR_0x8007, Fountain_LookUp
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookLeft
	applymovement VAR_0x8007, Fountain_LookLeft
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookRight
	applymovement VAR_0x8007, Fountain_LookRight
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookDown
	applymovement VAR_0x8007, Fountain_LookDown
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	applymovement VAR_0x8007, Common_Movement_QuestionMark
	delay 50
	waitmovement 0
    callnative ScriptCmd_GetPlayerSpecies
    goto_if_eq VAR_RESULT, SPECIES_SWABLU, ScriptAfterWhiteOutSwablu
    goto_if_eq VAR_RESULT, SPECIES_PHANPY, ScriptAfterWhiteOutPhanpy
    @ TODO: other mons
ScriptAfterWhiteOutSwablu:
ScriptAfterWhiteOutPhanpy:
	msgbox_portrait Fountain_Text_Intro01, FIELD_PIC_PHANPY_SAD
	waitmessage
	closemessage
    delay 40
    playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	applymovement VAR_0x8007, Fountain_LookUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement VAR_0x8007, Common_Movement_ExclamationMark
	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	waitmovement 0
	delay 40
	msgbox_portrait Fountain_Text_Tuskan1stDeathIntro1, FIELD_PIC_PHANPY_SWEAT
    bufferpartymonnick 0, 0
    bufferpartymonnick 1, 1
    goto_if_set FLAG_DO_AMY_RECRUIT_SCENE, Fountain_EventScript_RecruitAmy
    goto_if_set FLAG_DO_BELLA_RECRUIT_SCENE, Fountain_EventScript_RecruitBella
    goto_if_set FLAG_DO_RIPLEY_RECRUIT_SCENE, Fountain_EventScript_RecruitRipley
	msgbox_portrait Fountain_Text_Abra1stDeathIntro1, FIELD_PIC_ABRA_SERIOUS
ScriptAfterWhiteOutEnd:
    waitmessage
    closemessage
    removeobject VAR_0x8007
    releaseall
    end



@@@@@@@@@@@@@@@ RECRUIT SCENES (when Amy, Bella, and Ripley fall in. conversations written and a barebones script scripted out, but triggers are up to you)


Fountain_EventScript_RecruitAmy::
    clearflag FLAG_DO_AMY_RECRUIT_SCENE
	msgbox_portrait Fountain_Text_RecruitAmy01, FIELD_PIC_ABRA_HAPPY
	msgbox_portrait Fountain_Text_RecruitAmy02, FIELD_PIC_PHANPY_CONFUSED
	msgbox_portrait Fountain_Text_RecruitAmy03, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_RecruitAmy04, FIELD_PIC_SWABLU_YELL
	msgbox_portrait Fountain_Text_RecruitAmy05, FIELD_PIC_PHANPY_DETERMINED
	msgbox_portrait Fountain_Text_RecruitAmy06, FIELD_PIC_ABRA_SERIOUS
	playse SE_WARP_OUT
	removeobject LOCALID_ABRA_WELL
	delay 80
	playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	addobject LOCALID_EGG_RECRUIT
	delay 50
	playegghatchanim SPECIES_TINKATINK, TRUE, NULL
    waitstate
	removeobject LOCALID_EGG_RECRUIT
	addobject LOCALID_AMY_RECRUIT
	msgbox_portrait Fountain_Text_RecruitAmy07, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitAmy08, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitAmy09, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitAmy10, FIELD_PIC_PHANPY_CONFUSED
	msgbox_portrait Fountain_Text_RecruitAmy11, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_RecruitAmy12, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitAmy13, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_RecruitAmy14, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitAmy15, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitAmy16, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitAmy17, FIELD_PIC_ABRA_HAPPY
    removeobject LOCALID_AMY_RECRUIT
    clearflag FLAG_FIREPLACE_HIDE_TINKATINK
    addobject LOCALID_FIREPLACE_TINKATINK
    goto ScriptAfterWhiteOutEnd
	end



Fountain_Text_RecruitAmy01::
	.string "Dali: Welcome back, Tuskan and Fluff-\p"
	.string "Wait a minute… another Pokemon fell\n"
	.string "into the Inkwell?$"

Fountain_Text_RecruitAmy02::
	.string "Tuskan: Huh? Inkwell?$"

Fountain_Text_RecruitAmy03::
	.string "Dali: You were just with each other and\n"
	.string "someone else, right?$"

Fountain_Text_RecruitAmy04::
	.string "Fluffball: Arggh! She almost beat us!$"

Fountain_Text_RecruitAmy05::
	.string "Tuskan: That's right! She fought us,\n"
	.string "but… she seemed nice?\p"
	.string "Maybe she'd help us get to Craftily?$"

Fountain_Text_RecruitAmy06::
	.string "Dali: Hmm… I guess trying couldn't hurt.\n"
	.string "Let me go get her out of the Inkwell.$"

Fountain_Text_RecruitAmy07::
	.string "Amy: Huh? Who are you?$"

Fountain_Text_RecruitAmy08::
	.string "Dali: I am Dali, and this is Tuskan and\n"
	.string "Fluffball. Look, there's a lot to\l"
	.string "explain, but let me ask you…\p"
	.string "What do you know… about Craftily?$"

Fountain_Text_RecruitAmy09::
	.string "Amy: He took care of me, I think.\n"
	.string "Is he my dad?$"

Fountain_Text_RecruitAmy10::
	.string "Tuskan: Took care of you?$"

Fountain_Text_RecruitAmy11::
	.string "Dali: That's odd. No other feelings?$"

Fountain_Text_RecruitAmy12::
	.string "Amy: I… I want to cry when I think about\n"
	.string "him. Something very bad happened.$"

Fountain_Text_RecruitAmy13::
	.string "Dali: What? What happened?$"

Fountain_Text_RecruitAmy14::
	.string "Amy: Oh, I don't know! He was cursed?\n"
	.string "And… he did some bad things.$"

Fountain_Text_RecruitAmy15::
	.string "Dali: We're going to try and find him.\n"
	.string "Will you come?$"

Fountain_Text_RecruitAmy16::
	.string "Amy: Yeah. Are we friends? You feel like\n"
	.string "my friends.$"

Fountain_Text_RecruitAmy17::
	.string "Dali: We're friends!$"






Fountain_EventScript_RecruitBella::
    clearflag FLAG_DO_BELLA_RECRUIT_SCENE
	msgbox_portrait Fountain_Text_RecruitBella1, FIELD_PIC_ABRA_HAPPY
	playse SE_WARP_OUT
	removeobject LOCALID_ABRA_WELL
	delay 80
	playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	addobject LOCALID_EGG_RECRUIT
	delay 50
	playegghatchanim SPECIES_VENIPEDE, TRUE, NULL
    waitstate
	removeobject LOCALID_EGG_RECRUIT
	addobject LOCALID_BELLA_RECRUIT
	msgbox_portrait Fountain_Text_RecruitBella2, FIELD_PIC_PHANPY_CONFUSED
	msgbox_portrait Fountain_Text_RecruitBella3, FIELD_PIC_ABRA_HAPPY
	msgbox_portrait Fountain_Text_RecruitBella4, FIELD_PIC_SWABLU_YELL
	msgbox_portrait Fountain_Text_RecruitBella5, FIELD_PIC_ABRA_THINKING
	msgbox_portrait Fountain_Text_RecruitBella6, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitBella7, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_RecruitBella8, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitBella9, FIELD_PIC_ABRA_ANGRY
	msgbox_portrait Fountain_Text_RecruitBella10, FIELD_PIC_PHANPY_CONFUSED
    removeobject LOCALID_BELLA_RECRUIT
    clearflag FLAG_FIREPLACE_HIDE_VENIPEDE
    addobject LOCALID_FIREPLACE_VENIPEDE
    goto ScriptAfterWhiteOutEnd
	end



Fountain_Text_RecruitBella1::
	.string "Dali: Another one of Craftily's\n"
	.string "lieutenants? Let's see.$"

Fountain_Text_RecruitBella2::
	.string "Bella:…$"

Fountain_Text_RecruitBella3::
	.string "Dali: Hello, I'm Dali. You're shiny too,\n"
	.string "how interesting! I…$"

Fountain_Text_RecruitBella4::
	.string "Bella: Where's Ada? I swear, if you've\n"
	.string "hurt her…$"

Fountain_Text_RecruitBella5::
	.string "Dali: Wait. Ada… I know that name.$"

Fountain_Text_RecruitBella6::
	.string "Bella: Hey, you're Dali! Aren't you\n"
	.string "supposed to be helping me look for her?$"

Fountain_Text_RecruitBella7::
	.string "Dali: You're looking for Ada?$"

Fountain_Text_RecruitBella8::
	.string "Bella: Of course! I don't remember much,\n"
	.string "but aren't you lot looking for her too?\p"
	.string "Do you and Craftily have a plan?$"

Fountain_Text_RecruitBella9::
	.string "Dali: I think Craftily has the plan.\n"
	.string "We've gotta get to him. Will you help us?$"

Fountain_Text_RecruitBella10::
	.string "Bella: The question is, can you keep up?$"




Fountain_EventScript_RecruitRipley::
    clearflag FLAG_DO_RIPLEY_RECRUIT_SCENE
	msgbox_portrait Fountain_Text_RecruitRipley01, FIELD_PIC_ABRA_HAPPY
	playse SE_WARP_OUT
	removeobject LOCALID_ABRA_WELL
	delay 80
	playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	addobject LOCALID_EGG_RECRUIT
	delay 50
	playegghatchanim SPECIES_SQUIRTLE, TRUE, NULL
    waitstate
	removeobject LOCALID_EGG_RECRUIT
	addobject LOCALID_RIPLEY_RECRUIT
	msgbox_portrait Fountain_Text_RecruitRipley02, FIELD_PIC_ABRA_THINKING
	msgbox_portrait Fountain_Text_RecruitRipley03, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_RecruitRipley04, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_RecruitRipley05, FIELD_PIC_PHANPY_DETERMINED
	msgbox_portrait Fountain_Text_RecruitRipley06, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_RecruitRipley07, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitRipley08, FIELD_PIC_ABRA_THINKING
	msgbox_portrait Fountain_Text_RecruitRipley09, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitRipley10, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_RecruitRipley11, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_RecruitRipley12, FIELD_PIC_ABRA_HAPPY
    removeobject LOCALID_RIPLEY_RECRUIT
    clearflag FLAG_FIREPLACE_HIDE_SQUIRTLE
    addobject LOCALID_FIREPLACE_SQUIRTLE
    goto ScriptAfterWhiteOutEnd
	end


Fountain_Text_RecruitRipley01::
	.string "Dali: Another new Pokemon? This must be\n"
	.string "the last of Craftily's lieutenants.\p"
	.string "Let's see what they have to say.$"

Fountain_Text_RecruitRipley02::
	.string "Dali: You're… you're Ripley!$"

Fountain_Text_RecruitRipley03::
	.string "Ripley: I am! Wha- get away from that\n"
	.string "edge! You'll fall in the water!$"

Fountain_Text_RecruitRipley04::
	.string "Dali: Huh?$"

Fountain_Text_RecruitRipley05::
	.string "Ripley: It's not safe over there!\n"
	.string "Wild Pokemon could be anywhere!$"

Fountain_Text_RecruitRipley06::
	.string "Dali: Do you know who we are, Ripley?$"

Fountain_Text_RecruitRipley07::
	.string "Ripley: Um, my head is full of bubbles\n"
	.string "right now, but I know I have to keep\l"
	.string "you safe! Levitating won't protect you\l"
	.string "from a Sharpedo!$"

Fountain_Text_RecruitRipley08::
	.string "Dali: As soon as you saw me, you felt\n"
	.string "compelled to protect me?$"

Fountain_Text_RecruitRipley09::
	.string "Ripley: Well, yeah. Aren't you like… my\n"
	.string "little brother?$"

Fountain_Text_RecruitRipley10::
	.string "Dali: I guess I probably am. Ripley, we\n"
	.string "need help. We need to find Craftily and-$"

Fountain_Text_RecruitRipley11::
	.string "Ripley: Say no more. What's that scamp\n"
	.string "done this time?$"

Fountain_Text_RecruitRipley12::
	.string "Dali: Heh, we have no idea! Come on.$"





@@@@@ Intro cutscene

.equ SKIP_INTRO_FOR_TESTING, 0

Fountain_EventScript_IntroScene::
	
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	delay 40
	playbgm MUS_PMDRED_STORMY_SEA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookLeft
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookRight
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookDown
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	delay 50
	@fadenewbgm MUS_PMDRED_STORMY_SEA

	@cutscene skipper
    .if SKIP_INTRO_FOR_TESTING == 1
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_HIDE_SAVORY_SQUAD
	setflag FLAG_HIDE_BOSS3_SOLO
	setflag FLAG_HIDE_BOSS3_DUO 
	setflag FLAG_NO_PHOTOS 
	setflag FLAG_HIDE_DISC_RED   
	setflag FLAG_HIDE_DISC_GREEN 
	setflag FLAG_HIDE_DISC_PURPLE
	setflag FLAG_HIDE_DISC_BLACK 
	setflag FLAG_HIDE_DISC_GRAY   
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setvar VAR_PETALBURG_CITY_STATE 1
	warpsilent MAP_PETALBURG_CITY,24,46
	addobject LOCALID_ABRA_WELL
	end
    .endif

	waitmovement 0
	msgbox_portrait Fountain_Text_Intro01, FIELD_PIC_PHANPY_SAD
	waitmessage
	closemessage
	delay 80
	playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	waitmovement 0
	delay 40
	msgbox_portrait Fountain_Text_Intro02, FIELD_PIC_PHANPY_SWEAT
	msgbox_portrait Fountain_Text_Intro03, FIELD_PIC_ABRA_SERIOUS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox_portrait Fountain_Text_Intro04, FIELD_PIC_PHANPY_CONFUSED
	msgbox_portrait Fountain_Text_Intro05, FIELD_PIC_ABRA_CONCERNED
	closemessage
	applymovement LOCALID_ABRA_WELL, Fountain_LookUp
	waitmovement 0
	delay 20

	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_CameraMove1
	waitmovement 0
	delay 30
	msgbox Fountain_Text_Intro05_2, MSGBOX_NPC
	addobject LOCAL_ID_ALTARIA_INTRO
	applymovement LOCAL_ID_ALTARIA_INTRO, Fountain_FallIntoWater
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_FallIntoWater
	waitmovement 0
	setspriteinvisible LOCAL_ID_ALTARIA_INTRO, TRUE
    splashwatereffect LOCALID_SPLASH_1
    delay 5
	playse SE_M_DIVE
	waitse
    waitfieldeffect FLDEFF_JUMP_BIG_SPLASH
    removeobject LOCAL_ID_ALTARIA_INTRO
	delay 30
	addobject LOCALID_ABRA_WELL
	applymovement LOCALID_ABRA_WELL, Fountain_LookUp
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_CameraMove3
	waitmovement 0
	delay 20

	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	delay 10
	msgbox_portrait Fountain_Text_Intro06, FIELD_PIC_ABRA_DETERMINED
	closemessage
	delay 10
	playse SE_WARP_OUT
	removeobject LOCALID_ABRA_WELL
	delay 80
	playse SE_WARP_IN
	addobject LOCALID_ABRA_WELL
	addobject LOCALID_EGG_INTRO
	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	special RemoveCameraObject
	delay 10
	msgbox_portrait Fountain_Text_Intro07, FIELD_PIC_ABRA_SWEAT
	fadescreenspeed FADE_TO_BLACK, 2
	delay 20
	removeobject LOCALID_EGG_INTRO
    addobject LOCALID_SWABLU_INTRO
    playegghatchanim SPECIES_SWABLU, TRUE, NULL
    waitstate
	playbgm MUS_PMDRED_STORMY_SEA, FALSE	
	applymovement LOCALID_SWABLU_INTRO, Fountain_LookUp
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	waitmovement 0
	delay 10
	@fadescreenspeed FADE_FROM_BLACK, 2

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
	delay 50
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	applymovement LOCALID_SWABLU_INTRO, Fountain_LookUp
	waitmovement 0
	delay 20
	msgbox_portrait Fountain_Text_Intro13, FIELD_PIC_SWABLU_ANGRY
	msgbox_portrait Fountain_Text_Intro14, FIELD_PIC_PHANPY_SAD
	closemessage
	applymovement LOCALID_ABRA_WELL, Fountain_LookUp
	waitmovement 0
	delay 50
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_CameraMove4
	waitmovement 0
	delay 40
	msgbox_portrait Fountain_Text_Intro15, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_Intro16, FIELD_PIC_PHANPY_DETERMINED
	msgbox_portrait Fountain_Text_Intro17, FIELD_PIC_ABRA_CONCERNED
	applymovement OBJ_EVENT_ID_CAMERA, Fountain_CameraMove5
	waitmovement 0
	applymovement LOCALID_ABRA_WELL, Fountain_LookDown
	waitmovement 0
	delay 30
	msgbox_portrait Fountain_Text_Intro18, FIELD_PIC_ABRA_DETERMINED
	fadeoutbgm 1
	msgbox_portrait Fountain_Text_Intro19, FIELD_PIC_ABRA_ANGRY
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_Shudder
	applymovement LOCALID_SWABLU_INTRO, Fountain_Shudder
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookLeft
	delay 40
	fadeinbgm 1
	msgbox_portrait Fountain_Text_Intro20, FIELD_PIC_PHANPY_SAD
	applymovement OBJ_EVENT_ID_PLAYER, Fountain_LookUp
	delay 40
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
	setflag FLAG_HIDE_SAVORY_SQUAD
	setflag FLAG_HIDE_BOSS3_SOLO
	setflag FLAG_HIDE_BOSS3_DUO 
	setflag FLAG_NO_PHOTOS
	setflag FLAG_HIDE_DISC_RED   
	setflag FLAG_HIDE_DISC_GREEN 
	setflag FLAG_HIDE_DISC_PURPLE
	setflag FLAG_HIDE_DISC_BLACK 
	setflag FLAG_HIDE_DISC_GRAY   
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	setvar VAR_PETALBURG_CITY_STATE 1
	warpsilent MAP_PETALBURG_CITY,24,46
	fadedefaultbgm
	addobject LOCALID_ABRA_WELL
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
	walk_faster_down
	walk_faster_down
	step_end

Fountain_CameraMove3:
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
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Fountain_CameraMove5:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	step_end

Fountain_Shudder:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end


Fountain_Text_Intro01:
	.string "Tuskan: Huh? Where… wasn’t there a…$"

Fountain_Text_Intro02:
	.string "Tuskan: Um, excuse me, where am I?\n"
	.string "A-are you my…?$"
    
Fountain_Text_Tuskan1stDeathIntro1:
	.string "Tuskan: Um, excuse me, where are we?\n"
	.string "D-dali…?$"

Fountain_Text_Intro03:
	.string "???: Welcome back, Tuskan.$"
    
Fountain_Text_Abra1stDeathIntro1:
	.string "Dali: Welcome back,\n{STR_VAR_1} and {STR_VAR_2}.\p"
	.string "You do remember me this time around.\n"
	.string "This makes me happy.$"

Fountain_Text_Intro04:
	.string "Tuskan: Welcome back? What?$"

Fountain_Text_Intro05:
	.string "???: Hold on, it'll be easier to explain\n"
	.string "it to both of you together.$"

Fountain_Text_Intro05_2:
	.string "???: Aaaaaaah!$"

Fountain_Text_Intro06:
	.string "???: Wait here a moment - I have to\n"
	.string "Teleport her out of the well.$"

Fountain_Text_Intro07:
	.string "???: Phew.\p"
	.string "Just wait a minute for her to hatch,\n"
	.string "and then I'll explain everything.$"

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
	.string "The dark, inky water heals any injury,\n"
	.string "but it also… makes you younger.\p"
	.string "It takes away your experience,\n"
	.string "and your memories.\p"
	.string "Taking a small sip is safe, but falling\n"
	.string "in quickly turns you back into an egg.\p"
	.string "That's what just happened to you.$"

Fountain_Text_Intro16:
	.string "Tuskan: But why were we in that house?\n"
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
	.string "Dali:…\p"
	.string "I don't remember what happened either.\n"
	.string "Don’t even remember what he looks like.\p"
	.string "I only remember his name.\p"
	.string "But the other Pokemon around here say\n"
	.string "that a great Pokemon named Craftily\l"
	.string "lives at the top of that strange house.\p"
	.string "We’re all so weak, and he’s so strong.\p"
	.string "I think Craftily did this to us.\p"
	.string "I can only guess that there was a\n"
	.string "terrible battle, and Craftily won and\l"
	.string "forced us into the Inkwell.$"

Fountain_Text_Intro24:
	.string "Fluffball: Why would he do that?$"

Fountain_Text_Intro25:
	.string "Dali: I don't know.\p"
	.string "What I do know is that there's a deep,\n"
	.string "half-forgotten anger I feel when I\l"
	.string "hear that name, and you feel it too.\p"
	.string "I feel like there are so many clues\n"
	.string "around here to what happened, but\l"
	.string "I just can't put them together.$"

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
	.string "can do is Teleport.\p"
	.string "I can only support this mission from\n"
	.string "the sidelines, and try to keep our\l"
	.string "memories alive.\p"
	.string "And every time you come back, I have to\n"
	.string "ask you to go back in there and fight.$"

Fountain_Text_Intro30:
	.string "Dali: So explore around here all you\n"
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





@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Abra events - TOFOLD

@ MANSION

Fountain_EventScript_Abra_Mansion::
	lockall
	faceplayer
	goto_if_set FLAG_RECRUITED_ABRA, Fountain_EventScript_Abra_Mansion3
	goto_if_set FLAG_FOUGHT_SWEET_SQUAD , Fountain_EventScript_Abra_Mansion2
	msgbox_portrait Fountain_Text_Abra_Mansion1, FIELD_PIC_ABRA_CONCERNED
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Mansion2::
	msgbox_portrait Fountain_Text_Abra_Mansion2, FIELD_PIC_ABRA_DETERMINED
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Mansion3::
	msgbox_portrait Fountain_Text_Abra_Mansion3, FIELD_PIC_ABRA_CONCERNED
	closemessage
	releaseall
	end

Fountain_Text_Abra_Mansion1:
	.string "Dali: This is it. This is where Craftily\n"
	.string "and a lot of his followers live.\p"
	.string "I know you're both only level 1, but\n"
	.string "you're our only chance.\p"
	.string "Go in whenever you're ready.$"

Fountain_Text_Abra_Mansion2:
	.string "Dali: I know it's tough, but please don't\n"
	.string "give up.\p"
	.string "I bet there's a lot of Craftily's allies\n"
	.string "making trouble for you, but as long as\l"
	.string "they keep throwing you in the Inkwell,\l"
	.string "we can eventually win!$"

Fountain_Text_Abra_Mansion3:
	.string "Dali: Huh?\p"
	.string "Are you claiming that the rooms in the\n"
	.string "house seem to be moving around?\p"
	.string "Doors don't go to where they used to?\p"
	.string "Umm, houses don't work like that.\p"
	.string "You probably just don't remember where\n"
	.string "the rooms are, because of the Inkwell.$"


@ GARDEN

Fountain_EventScript_Abra_Garden::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_SWEET_SQUAD , Fountain_EventScript_Abra_Garden2
	msgbox_portrait Fountain_Text_Abra_Garden1, FIELD_PIC_ABRA_HAPPY
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Garden2::
	msgbox_portrait Fountain_Text_Abra_Garden2, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_Text_Abra_Garden1:
	.string "Dali: I call this area the garden.\p"
	.string "Even though all the trees are dead,\n"
	.string "it's still peaceful. Something was\l"
	.string "growing here at some point.$"

Fountain_Text_Abra_Garden2:
	.string "Dali: Maybe we used the garden to grow\n"
	.string "our own food.\p"
	.string "You know, because we must have been doing\n"
	.string "something before this.\p"
	.string "Or… were we born next to the Inkwell?$"


@@ ABRA GRAVE


Fountain_EventScript_Abra_Grave::
	lockall
	faceplayer
	goto_if_set FLAG_RECRUITED_ABRA, Fountain_EventScript_Abra_Grave4

	@if they have any photos, send them to the Grave2/Grave3 choice
	checkitem UNIQUE_ITEM_PHOTO_1, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_Abra_GravePhotoCheck
	checkitem UNIQUE_ITEM_PHOTO_2, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_Abra_GravePhotoCheck
	checkitem UNIQUE_ITEM_PHOTO_3, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_Abra_GravePhotoCheck
	checkitem UNIQUE_ITEM_PHOTO_4, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_Abra_GravePhotoCheck
	checkitem UNIQUE_ITEM_PHOTO_5, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_Abra_GravePhotoCheck

	@this means they have no photos, so Grave 1
	msgbox_portrait Fountain_Text_Abra_Grave1, FIELD_PIC_ABRA_CONCERNED
	closemessage
	releaseall
	end


Fountain_EventScript_Abra_GravePhotoCheck::
	checkitem UNIQUE_ITEM_PHOTO_1, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_Abra_Grave2
	checkitem UNIQUE_ITEM_PHOTO_2, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_Abra_Grave2
	checkitem UNIQUE_ITEM_PHOTO_3, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_Abra_Grave2
	checkitem UNIQUE_ITEM_PHOTO_4, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_Abra_Grave2
	checkitem UNIQUE_ITEM_PHOTO_5, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_Abra_Grave2

	@all photos
	msgbox_portrait Fountain_Text_AbraGraveComplete1, FIELD_PIC_ABRA_HAPPY
	msgbox_portrait Fountain_Text_AbraGraveComplete2, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_AbraGraveComplete3, FIELD_PIC_ABRA_DETERMINED
	msgbox_portrait Fountain_Text_AbraGraveComplete4, FIELD_PIC_ABRA_THINKING
	msgbox_portrait Fountain_Text_AbraGraveComplete5, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_AbraGraveComplete6, FIELD_PIC_ABRA_THINKING
	msgbox_portrait Fountain_Text_AbraGraveComplete7, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait Fountain_Text_AbraGraveComplete8, FIELD_PIC_ABRA_DETERMINED
	msgbox_portrait Fountain_Text_AbraGraveComplete9, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait Fountain_Text_AbraGraveComplete10, FIELD_PIC_ABRA_CRY
	setflag FLAG_RECRUITED_ABRA
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Grave2::
	msgbox_portrait Fountain_Text_Abra_Grave2, FIELD_PIC_ABRA_SERIOUS
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Grave4::
	msgbox_portrait Fountain_Text_Abra_Grave4, FIELD_PIC_ABRA_DETERMINED
	closemessage
	releaseall
	end


Fountain_Text_Abra_Grave1:
	.string "Dali: Here's the pale stone.\p"
	.string "There aren't any other stones like\n"
	.string "this around, and nothing with all\l"
	.string "these complicated markings.\p"
	.string "But, I don't like coming here.\n"
	.string "That stone makes me uncomfortable.$"

Fountain_Text_Abra_Grave2:
	.string "Dali: I've put the picture piece you\n"
	.string "found on this stump here.\p"
	.string "There's probably more in that house\n"
	.string "somewhere, and if you find them all,\l"
	.string "maybe that'll tell us something?$"



Fountain_Text_AbraGraveComplete1:
	.string "Dali: The picture's complete!\n"
	.string "You found all the pieces!\p"
	.string "Now, let's see here…$"

Fountain_Text_AbraGraveComplete2:
	.string "This… this looks like us.$"

Fountain_Text_AbraGraveComplete3:
	.string "That's Fluffball, on the right.\n"
	.string "That's what she looks like evolved.\p"
	.string "Next to her… is that really me?\n"
	.string "I look… so confident…\p"
	.string "And on her other side… that's him.\n"
	.string "That's Craftily.$"

Fountain_Text_AbraGraveComplete4:
	.string "We were all friends once.\n"
	.string "I remember. We were… a team.\p"
	.string "I recognize the others, too.\n"
	.string "Bella, Amy, Ripley…$"

Fountain_Text_AbraGraveComplete5:
	.string "And that one in the middle.\n"
	.string "Not a Pokemon. A… a trainer.\p"
	.string "What… what happened to her?$"

Fountain_Text_AbraGraveComplete6:
	.string "This is a lot. I… I need some time to\n"
	.string "think it through.\p"
	.string "…$"

Fountain_Text_AbraGraveComplete7:
	.string "Dali: Okay. I have some thoughts.\n"
	.string "We know three important things now.$"

Fountain_Text_AbraGraveComplete8:
	.string "One, we used to be a team, like a family.\n"
	.string "All of us, even Craftily, and a human.\p"
	.string "And then something happened, and we\n"
	.string "remember it as Craftily betraying us.$"

Fountain_Text_AbraGraveComplete9:
	.string "Two. Tuskan… wasn't in the picture.\p"
	.string "I don't know why, but there's\n"
	.string "something special about Tuskan.$"

Fountain_Text_AbraGraveComplete10:
	.string "And three, I…\p"
	.string "I… looked so strong in that picture.\p"
	.string "I've always thought that I was useless,\n"
	.string "that I needed to be protected.\p"
	.string "But… maybe I'm not useless.\n"
	.string "Maybe I can learn to fight, with training.\p"
	.string "So, um, if you'll have me… I can join you\n"
	.string "in the fight.\p"
	.string "I mean, I won't be able to Teleport back\n"
	.string "to refill vials if I'm fighting, and no\l"
	.string "one else can Teleport… so it's probably\l"
	.string "a bad idea.\p"
	.string "But... I'll try.$"


Fountain_Text_Abra_Grave4:
	.string "Dali: That photo taught us a lot.\p"
	.string "But the whole story can only come from\n"
	.string "Craftily himself.$"


@ BIRDHOUSE

Fountain_EventScript_Abra_Birdhouse::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_SWEET_SQUAD, Fountain_EventScript_Abra_Birdhouse2
	msgbox_portrait Fountain_Text_Abra_Birdhouse1, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Birdhouse2::
	msgbox_portrait Fountain_Text_Abra_Birdhouse2, FIELD_PIC_ABRA_SERIOUS
	closemessage
	releaseall
	end

Fountain_Text_Abra_Birdhouse1:
	.string "Dali: As far as I can tell, this little\n"
	.string "building is too small for anyone.\p"
	.string "Why is it here?$"

Fountain_Text_Abra_Birdhouse2:
	.string "Dali: When you fall into the Inkwell,\n"
	.string "sometimes you have seeds in the bag.\p"
	.string "They're probably berries that de-age\n"
	.string "when they touch the dark water.\p"
	.string "I've been storing them here.\p"
	.string "I had some plans for them, but there\n"
	.string "probably won't be enough time.$"

@ BACKDOOR

Fountain_EventScript_Abra_Backdoor::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_SWEET_SQUAD, Fountain_EventScript_Abra_Backdoor2
	msgbox_portrait Fountain_Text_Abra_Backdoor1, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Backdoor2::
	msgbox_portrait Fountain_Text_Abra_Backdoor2, FIELD_PIC_ABRA_HAPPY
	closemessage
	releaseall
	end

Fountain_Text_Abra_Backdoor1:
	.string "Dali: There's another entrance here,\n"
	.string "but it's covered with those vines.\p"
	.string "Those thick vines seem to be growing\n"
	.string "on everything!$"

Fountain_Text_Abra_Backdoor2:
	.string "Dali: The house is in really bad shape.\n"
	.string "It's all broken and falling apart.\p"
	.string "Too bad it won't fit in the Inkwell.$"

@ SHED

Fountain_EventScript_Abra_Shed::
	lockall
	faceplayer
	goto_if_set FLAG_RECRUITED_ABRA, Fountain_EventScript_Abra_Shed3
	goto_if_set FLAG_DEFEATED_SWEET_SQUAD, Fountain_EventScript_Abra_Shed2
	msgbox_portrait Fountain_Text_Abra_Shed1, FIELD_PIC_ABRA_CONCERNED
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Shed2::
	msgbox_portrait Fountain_Text_Abra_Shed2, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Shed3::
	msgbox_portrait Fountain_Text_Abra_Shed3, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_Text_Abra_Shed1:
	.string "Dali: This tiny house is closed off.\p"
	.string "It's a shame - it would be nice to\n"
	.string "spend nights in there.$"

Fountain_Text_Abra_Shed2:
	.string "Dali: It's made of the same stuff as\n"
	.string "the big house, but not the Inkwell.\p"
	.string "So the same Pokemon probably didn't\n"
	.string "make both?$"

Fountain_Text_Abra_Shed3:
	.string "Dali: I think… maybe we used this for storage?\n"
	.string "I can't really remember.$"

@STACKS

Fountain_EventScript_Abra_Stacks::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_SWEET_SQUAD, Fountain_EventScript_Abra_Stacks2
	msgbox_portrait Fountain_Text_Abra_Stacks1, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Stacks2::
	msgbox_portrait Fountain_Text_Abra_Stacks2, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_Text_Abra_Stacks1:
	.string "Dali: Organized piles of the old stone\n"
	.string "pieces used to make the Inkwell.\p"
	.string "Did we make the Inkwell?$"

Fountain_Text_Abra_Stacks2:
	.string "Dali: I'm thinking about our names.\p"
	.string "I know my name is Dali, but why?\n"
	.string "Did I choose it for myself?\p"
	.string "And Fluffball doesn't even like her\n"
	.string "name - was she different before?\p"
	.string "Or did someone else name us?$"


@ STUMPS

Fountain_EventScript_Abra_Stumps::
	lockall
	faceplayer
	goto_if_unset FLAG_HIDE_DISC_RED, Fountain_EventScript_Abra_Stumps2
	goto_if_unset FLAG_HIDE_DISC_GREEN, Fountain_EventScript_Abra_Stumps2
	goto_if_unset FLAG_HIDE_DISC_PURPLE, Fountain_EventScript_Abra_Stumps2
	goto_if_unset FLAG_HIDE_DISC_BLACK, Fountain_EventScript_Abra_Stumps2
	goto_if_unset FLAG_HIDE_DISC_GRAY, Fountain_EventScript_Abra_Stumps2
	msgbox_portrait Fountain_Text_Abra_Stumps1, FIELD_PIC_ABRA_HAPPY
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Stumps2::
	msgbox_portrait Fountain_Text_Abra_Stumps2, FIELD_PIC_ABRA_HAPPY
	closemessage
	releaseall
	end

Fountain_Text_Abra_Stumps1:
	.string "Dali: There used to be a lot of trees\n"
	.string "here. Look, that's what's left of them.\p"
	.string "But that's not all I've figured out!\p"
	.string "If you look closely at the house, you'll\n"
	.string "see it's made of tree pieces!$"

Fountain_Text_Abra_Stumps2:
	.string "Dali: Discs! This should be a good\n"
	.string "spot for any discs you find.\p"
	.string "They don't do anything for me, but\n"
	.string "maybe they can help you learn moves?$"


@ WELL

Fountain_EventScript_Abra_Well::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_SWEET_SQUAD, Fountain_EventScript_Abra_Well2
	msgbox_portrait Fountain_Text_Abra_Well1, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Well2::
	msgbox_portrait Fountain_Text_Abra_Well2, FIELD_PIC_ABRA_SERIOUS
	closemessage
	releaseall
	end

Fountain_Text_Abra_Well1:
	.string "Dali: This is the Inkwell.\p"
	.string "Remember, drinking from it will reduce\n"
	.string "your level, but it'll heal you fully.\p"
	.string "There's another kind of water, too.\p"
	.string "I call it Airwater, because it comes out\n"
	.string "of the air and is the same color as air.$"

Fountain_Text_Abra_Well2:
	.string "Dali: Make sure you look around this\n"
	.string "area before going back in.\p"
	.string "Most of your items sink when you fall in\n"
	.string "the Inkwell, but I've saved a few unique\l"
	.string "things and set up places for them.$"




@ CAMPFIRE

Fountain_EventScript_Abra_Campfire::
	lockall
	faceplayer
	goto_if_set FLAG_TINKATINK_AVAILABLE, Fountain_EventScript_Abra_Campfire2
	@no recruits
	msgbox_portrait Fountain_Text_Abra_Campfire1, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end
    
Fountain_EventScript_Abra_Campfire2ToAmy:
    msgbox_portrait Fountain_Text_Abra_Campfire2ToAmy, FIELD_PIC_ABRA_JOY
    goto  Fountain_EventScript_Abra_Campfire2EndMsg

Fountain_EventScript_Abra_Campfire2::
	goto_if_set FLAG_VENIPEDE_AVAILABLE, Fountain_EventScript_Abra_Campfire3
	@tink but not scoli
    callnative ScriptCmd_GetPlayerSpecies
    goto_if_eq VAR_RESULT, SPECIES_TINKATINK, Fountain_EventScript_Abra_Campfire2ToAmy
	msgbox_portrait Fountain_Text_Abra_Campfire2, FIELD_PIC_ABRA_JOY
Fountain_EventScript_Abra_Campfire2EndMsg:
	closemessage
	releaseall
	end


Fountain_EventScript_Abra_Campfire3::
	goto_if_set FLAG_SQUIRTLE_AVAILABLE, Fountain_EventScript_Abra_Campfire4
    @tink and scoly
	msgbox_portrait Fountain_Text_Abra_Campfire3, FIELD_PIC_ABRA_JOY
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Campfire4::
    @tink, scoly, squirtle
	msgbox_portrait Fountain_Text_Abra_Campfire4, FIELD_PIC_ABRA_JOY
	closemessage
	releaseall
	end


Fountain_Text_Abra_Campfire1:
	.string "Dali: Look at the logs and stumps here.\p"
	.string "It's very easy to sit and rest, around\n"
	.string "this black pit.\p"
	.string "We should relax here when this is over.$"

Fountain_Text_Abra_Campfire2:
	.string "Dali: Whoa, you got Amy on our side!\n"
	.string "I'm sure she'd going to be a big help!$"
    
Fountain_Text_Abra_Campfire2ToAmy:
	.string "Dali: I am pleased to see\n"
	.string "you together with us, Amy!$"

Fountain_Text_Abra_Campfire3:
	.string "Dali: Amy and Belladonna?\p"
	.string "Wow, maybe we can get even more friends\n"
	.string "to help us get to Craftily!$"

Fountain_Text_Abra_Campfire4:
	.string "Dali: I'm so happy to see all of our\n"
	.string "old and new friends!\p"
	.string "We're going to figure it out, just\n"
	.string "you wait!$"


@ GATE

Fountain_EventScript_Abra_Gate::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_SWEET_SQUAD, Fountain_EventScript_Abra_Gate2
	msgbox_portrait Fountain_Text_Abra_Gate1, FIELD_PIC_ABRA_THINKING
	closemessage
	releaseall
	end

Fountain_EventScript_Abra_Gate2::
	msgbox_portrait Fountain_Text_Abra_Gate2, FIELD_PIC_ABRA_HAPPY
	closemessage
	releaseall
	end

Fountain_Text_Abra_Gate1:
	.string "Dali: This is how we can leave, I think.\p"
	.string "It's still scary to me to think that\n"
	.string "there are other places out there.\p"
	.string "Who knows what might be there?\p"
	.string "But this gate is sealed up with vines.\n"
	.string "I don't think we can cut through.$"

Fountain_Text_Abra_Gate2:
	.string "Dali: I can kind of see a little path,\n"
	.string "but there's nothing at the end.\p"
	.string "Just more tightly packed trees.\p"
	.string "Why block this place with a gate\n"
	.string "if the path doesn't go anywhere?$"







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
	.string "A smooth, pale stone. Strange, angular\n"
	.string "marks are carved into it.\p"
	.string "It makes you feel… sad?$"

Fountain_Text_GraveEnd:
	.string "This must be Ada's grave.\p"
	.string "TOFOLD"
	.string "$"



Fountain_EventScript_PhotoStump::
	checkitem UNIQUE_ITEM_PHOTO_1, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_StumpPhotoCheck
	checkitem UNIQUE_ITEM_PHOTO_2, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_StumpPhotoCheck
	checkitem UNIQUE_ITEM_PHOTO_3, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_StumpPhotoCheck
	checkitem UNIQUE_ITEM_PHOTO_4, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_StumpPhotoCheck
	checkitem UNIQUE_ITEM_PHOTO_5, 1
	goto_if_eq VAR_RESULT, YES, Fountain_EventScript_StumpPhotoCheck
	end

Fountain_EventScript_StumpPhotoCheck::
	checkitem UNIQUE_ITEM_PHOTO_1, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_IncompletePhoto
	checkitem UNIQUE_ITEM_PHOTO_2, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_IncompletePhoto
	checkitem UNIQUE_ITEM_PHOTO_3, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_IncompletePhoto
	checkitem UNIQUE_ITEM_PHOTO_4, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_IncompletePhoto
	checkitem UNIQUE_ITEM_PHOTO_5, 1
	goto_if_eq VAR_RESULT, NO, Fountain_EventScript_IncompletePhoto
	msgbox Fountain_Text_CompletePhoto, MSGBOX_NPC

Fountain_Text_CompletePhoto:
	.string "You've found all of the pieces of the\n"
	.string "old picture.$"

@TODO - add picture


Fountain_EventScript_IncompletePhoto::
	msgbox Fountain_Text_IncompletePhoto, MSGBOX_NPC
	end

Fountain_Text_IncompletePhoto:
	.string "The pieces of that odd picture you\n"
	.string "found are assembled here.\p"
	.string "It doesn't look complete yet.$"




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
	.string "A tiny house. There are still a few\n"
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


Text_WantToJoin:
    .string "Do you want {STR_VAR_1}\nto join the team?$"
    
Text_JoinedTeam:
    .string "{STR_VAR_1} joined the team!$"
    
EventScript_FireplaceShowPhanpy:
    clearflag FLAG_FIREPLACE_HIDE_PHANPY
    addobject LOCALID_FIREPLACE_PHANPY
    return
EventScript_FireplaceShowSwablu:
    clearflag FLAG_FIREPLACE_HIDE_SWABLU
    addobject LOCALID_FIREPLACE_SWABLU
    return
EventScript_FireplaceShowTinkatink:
    clearflag FLAG_FIREPLACE_HIDE_TINKATINK
    addobject LOCALID_FIREPLACE_TINKATINK
    return

EventScript_FireplaceRecruit::
    lockall
    faceplayer
    buffernpcnamefromspecies 0 @ Also sets var VAR_0x8007 to species
    msgbox Text_WantToJoin, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_FireplaceRecruitEnd
    goto_if_eq VAR_RESULT, YES, EventScript_FireplaceRecruitYes
EventScript_FireplaceRecruitEnd:
    releaseall
    end
EventScript_FireplaceRecruitYes:
    msgbox Text_JoinedTeam
    waitmessage
    closemessage
    fadescreenspeed FADE_TO_BLACK, 2
    delay 10
    removeobject VAR_LAST_TALKED
    callnative ScriptCmd_GetPlayerSpecies
    call_if_eq VAR_RESULT, SPECIES_PHANPY, EventScript_FireplaceShowPhanpy
    call_if_eq VAR_RESULT, SPECIES_SWABLU, EventScript_FireplaceShowSwablu
    call_if_eq VAR_RESULT, SPECIES_TINKATINK, EventScript_FireplaceShowTinkatink
    callnative ScriptCmd_SwapTeamMembers
    changeplayersprite VAR_0x8007, TRUE, TRUE
EventScript_FireplaceRecruitYesGoBackFromFade:
    fadescreen FADE_FROM_BLACK
    goto EventScript_FireplaceRecruitEnd



@@@@@ TMs / Discs

@@ check movetutors.inc, they're all there.



























