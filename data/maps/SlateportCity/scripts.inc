.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM10  @ Hidden Power
	.2byte ITEM_TM43  @ Secret Power
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Sono l’ENERGIVENDOLO!\n"
	.string "Ti venderò tutto ciò di cui hai bisogno!$"

SlateportCity_Text_OhYourPokemon:
	.string "Cosa?\n"
	.string "Il tuo {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Se l’è cavata benissimo!\p"
	.string "Come ricompensa, dagli questo\n"
	.string "FIOCCO di MERITO.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} riceve il FIOCCO di MERITO.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} mette il FIOCCO di MERITO\n"
	.string "a {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Devi impegnarti di più.\p"
	.string "Se lo fai, darò qualcosa di carino\n"
	.string "al tuo POKéMON.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Guarda il tuo {STR_VAR_1},\n"
	.string "il FIOCCO di MERITO gli sta benissimo!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La luce del faro illumina per chilometri\n"
	.string "e chilometri.\p"
	.string "Che faccia spaventare i POKéMON\n"
	.string "nel mare?$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Guarda!\p"
	.string "Le alghe da queste parti sono fresche\n"
	.string "e piene di vita.\p"
	.string "Sembra che possano persino alzarsi\n"
	.string "ed attaccare!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Dove l’acqua è pulita, là si colgono\n"
	.string "i frutti di un generoso raccolto.\p"
	.string "La gente si riunisce in quel posto e\n"
	.string "ben presto sorge un mercato.\p"
	.string "È così che nasce e cresce una città.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Fare acquisti accompagnati dalla\n"
	.string "profumata brezza dell’oceano…\p"
	.string "Dove? A SELCEPOLI, una città\n"
	.string "straordinaria!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Se metti per terra BAMBOLE e CUSCINI,\n"
	.string "si sporcheranno.\p"
	.string "Comprerò dei MATTONI per appoggiarli \n"
	.string "e non sporcarli quando li lascio fuori.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Sì! Anch’io voglio lottare\n"
	.string "nel TENDONE LOTTA!\p"
	.string "Prima, però, devo acchiappare\n"
	.string "qualche POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Uh… sono esausto…\p"
	.string "Vengo a piedi da CICLAMIPOLI.\n"
	.string "Questa città è immensa!\p"
	.string "Se l’avessi saputo, sarei venuto\n"
	.string "in BICI.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "REMO, il tipo che ha costruito il MUSEO,\n"
	.string "è anche a capo di una squadra\l"
	.string "di esplorazione sottomarina.\p"
	.string "Tutti lo chiamano CAP. REMO.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Che succede là?\n"
	.string "Che coda…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Da bambina andavo spesso al MUSEO.\p"
	.string "Dopo aver visto le esposizioni, sognavo\n"
	.string "sempre i misteri del mare.$"

SlateportCity_Text_QuitPushing:
	.string "Ehi, smettila di spingere!\n"
	.string "C’è la coda, non vedi?$"

SlateportCity_Text_AquaHasPolicy:
	.string "Il TEAM IDRO ha l’abitudine di riunirsi\n"
	.string "e poi sparpagliarsi sul luogo delle\l"
	.string "operazioni.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Il nostro CAPO è intelligente.\p"
	.string "Che cosa vorrà fare con un MUSEO?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Chissà! Quale sarà il nuovo piano?\p"
	.string "Il nostro CAPO fa paura quando è\n"
	.string "arrabbiato. Meglio non far errori…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Dovremmo prendere tutto ciò che\n"
	.string "ci serve qui al MUSEO.$"

SlateportCity_Text_DontButtIn:
	.string "Ehi, tu. Non spingere!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Una lunga coda, eh?\p"
	.string "Mi fa pensare ai tempi in cui me ne stavo\n"
	.string "in coda per comprare giochi di successo.$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Perché poi stiamo in coda e paghiamo?\n"
	.string "Dovremmo fare irruzione e basta!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Come?\n"
	.string "Cosa vuoi?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Vuoi leggere questo cartello?\n"
	.string "Te lo leggo io!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Vediamo…\p"
	.string "Mmm… mi pare ci sia scritto:\n"
	.string "“La vita nel mare è infinita”.\p"
	.string "Sì, sono sicuro che dice così.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Uffa…\p"
	.string "Avrei dovuto portare il mio Game Boy\n"
	.string "Advance per non annoiarmi mentre\l"
	.string "faccio la fila…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Il nostro CAPO ha detto che a\n"
	.string "operazione terminata mi porterà\l"
	.string "alle sorgenti termali. Non vedo l’ora\l"
	.string "di andarci!$"

SlateportCity_Text_SeaIsSoWet:
	.string "Il mare è proprio immenso…\p"
	.string "Che si sia formato dalle lacrime\n"
	.string "versate dai POKéMON?!$"

SlateportCity_Text_SinkOldBoats:
	.string "Sai cosa fanno con le vecchie navi\n"
	.string "troppo malmesse per navigare?\p"
	.string "Le fanno affondare nel mare in modo che\n"
	.string "i POKéMON le usino come abitazioni.$"

SlateportCity_Text_BuyTooMuch:
	.string "Quando vengo qui, mi lascio trasportare\n"
	.string "e compro sempre troppe cose.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Se vuoi cambiare il soprannome dei\n"
	.string "tuoi POKéMON, devi chiedere aiuto al\l"
	.string "GIUDICE ONOMASTICO.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Non puoi cambiare il soprannome di un \n"
	.string "POKéMON ottenuto con uno scambio.\p"
	.string "Il soprannome racchiude l’amore dell’\n"
	.string "ALLENATORE originario per quel POKéMON.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Di recente hanno aperto un TENDONE\n"
	.string "LOTTA a SELCEPOLI.\p"
	.string "Le PALESTRE sono divertenti, ma il\n"
	.string "TENDONE LOTTA è eccezionale.\p"
	.string "Devi trovare dei POKéMON forti\n"
	.string "per il TENDONE LOTTA.$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Speravo che fosse una star famosa\n"
	.string "a cui poter chiedere l’autografo.\p"
	.string "Ma chi stanno intervistando?\n"
	.string "Non è il CAP. REMO?$"

SlateportCity_Text_InterviewerSoCool:
	.string "La reporter è così pacata e carina.\p"
	.string "Quando sarò grande, sarò anch’io \n"
	.string "una reporter di fama internazionale.$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Il CAP. REMO ha detto che hanno\n"
	.string "scoperto qualcosa sul fondo marino.\p"
	.string "Che curiosità!\n"
	.string "Cosa sarà mai?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Che succede qui?\p"
	.string "Il buon CAPITANO è tornato dal fondo\n"
	.string "del mare con un grande pesce?!$"

SlateportCity_Text_AmIOnTV:
	.string "Ehi, stai guardando?\n"
	.string "Sono in TV?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "C’è un’intervista televisiva qui!\n"
	.string "Il CAPITANO è una celebrità!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TEO: CAP. REMO, guardi qui,\n"
	.string "un sorriso per la telecamera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "TEA: Capisco, ha avuto un’esperienza\n"
	.string "veramente interessante…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAP. REMO: Sì, certo. Intendiamo\n"
	.string "continuare con le nostre esplorazioni.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "TEA: Fantastico, CAP. REMO!\n"
	.string "Grazie per averci messo a disposizione\l"
	.string "parte del suo prezioso tempo.\p"
	.string "Speriamo di poterla intervistare ancora\n"
	.string "in occasione di nuove scoperte!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAP. REMO: Wow…\p"
	.string "È stata la mia prima apparizione in TV.\n"
	.string "Che emozione!$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh! {PLAYER}{KUN}!\n"
	.string "Stai proprio bene!\p"
	.string "Abbiamo fatto una scoperta \n"
	.string "sensazionale nel corso dell’ultima \l"
	.string "esplorazione dei fondali marini.\p"
	.string "Abbiamo trovato una grotta sommersa\n"
	.string "sul PERCORSO 128.\p"
	.string "Crediamo che ci viva un POKéMON che\n"
	.string "si pensava estinto ormai da tempo.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu… il CAP. REMO, suppongo.\p"
	.string "Noi del TEAM IDRO prenderemo\n"
	.string "il controllo del suo sottomarino!\p"
	.string "Protestare è inutile! Ci aspettiamo la\n"
	.string "sua più totale collaborazione!\p"
	.string "Fufufu… il TEAM IDRO è capace\n"
	.string "di grandi cose!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAP. REMO: Cos’è stato?\p"
	.string "Sembrava qualcuno che parlava\n"
	.string "al megafono…\p"
	.string "Da dove veniva?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Veniva dallo SCALO!\p"
	.string "Il sottomarino!\n"
	.string "Stanno cercando di impossessarsene!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Vieni con me!$"

SlateportCity_Text_BattleTentSign:
	.string "TENDONE LOTTA di SELCEPOLI\n"
	.string "“Quale sarà il POKéMON più forte?”.$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "CANTIERE del CAP. REMO\p"
	.string "“Cercasi marinaio in grado di solcare\n"
	.string "qualsiasi mare”.$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "CANTIERE del CAP. REMO\p"
	.string "“Traghetto M/N MAREA in fase di\n"
	.string "completamento. Entrerà in servizio\l"
	.string "tra SELCEPOLI e ALGHEPOLI”.$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "CANTIERE del CAP. REMO\p"
	.string "“Imbarco per il traghetto\n"
	.string "M/N MAREA SELCEPOLI - ALGHEPOLI\l"
	.string "presso lo SCALO”.$"

SlateportCity_Text_PokemonFanClubSign:
	.string "POKéMON FAN CLUB\n"
	.string "“Per tutti i fan dei POKéMON!”.$"

SlateportCity_Text_OceanicMuseumSign:
	.string "MUSEO OCEANOGRAFICO\p"
	.string "“Il mare, nella sua immensità, è\n"
	.string "il sostegno di ogni forma di vita”.$"

SlateportCity_Text_CitySign:
	.string "PORTO SELCEPOLI\p"
	.string "“Porto d’incontro fra gli uomini\n"
	.string "e i POKéMON”.$"

SlateportCity_Text_MarketSign:
	.string "MERCATO di SELCEPOLI\n"
	.string "“Strumenti unici e introvabili!”.$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "SCALO di SELCEPOLI\p"
	.string "“Traghetto M/N MAREA in costruzione\n"
	.string "presso il CANTIERE.\p"
	.string "Entrerà in servizio tra breve”.$"

SlateportCity_Text_HarborSign:
	.string "SCALO di SELCEPOLI\p"
	.string "“Concedetevi una rilassante crociera\n"
	.string "sul traghetto M/N MAREA”.$"

SlateportCity_Text_NameRatersHouseSign:
	.string "CASA del GIUDICE ONOMASTICO\n"
	.string "“Valutiamo i soprannomi dei POKéMON”.$"

SlateportCity_Text_ExplainBerries:
	.string "Se un POKéMON selvatico si ferisce,\n"
	.string "mangia delle BACCHE per curarsi.\p"
	.string "Incredibile, vero?\p"
	.string "Così qualcuno ha avuto l’idea di fare\n"
	.string "dei medicamenti con le BACCHE.\p"
	.string "Incredibile, vero?\p"
	.string "Per produrre dei medicamenti, bisogna\n"
	.string "ridurre le BACCHE in polvere.\p"
	.string "Incredibile, vero?\p"
	.string "Sembri avere interesse per le\n"
	.string "BACCHE, o sbaglio?\p"
	.string "Ho qualcosa che fa al caso tuo.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Di recente ho fatto installare nei\n"
	.string "CENTRI POKéMON degli apparecchi\l"
	.string "per ridurre le BACCHE in polvere.\p"
	.string "I MACINABACCHE sono al primo\n"
	.string "piano nella SALA DIRETTA.\p"
	.string "Incredibile, vero?\p"
	.string "Potresti fare un po’ di FARINA di\n"
	.string "BACCHE usando quel macchinario?\p"
	.string "Con una buona quantità di FARINA, ti\n"
	.string "preparo tutti i medicamenti che vuoi.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Mi hai portato della FARINA di BACCHE?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Cosa vuoi in cambio?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Bene: vuoi scambiare la tua FARINA\n"
	.string "di BACCHE con 1 {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Ehi, non hai abbastanza FARINA di\n"
	.string "BACCHE!$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Questa FARINA di BACCHE è\n"
	.string "eccellente.\p"
	.string "Ne ricaverò degli ottimi\n"
	.string "medicamenti.\p"
	.string "Vuoi scambiare dell’altra FARINA\n"
	.string "di BACCHE per qualcos’altro?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Ok, portami dell’altra FARINA di BACCHE\n"
	.string "quando ne avrai ancora.$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Torna a trovarmi quando vuoi scambiare\n"
	.string "la FARINA di BACCHE con medicamenti!\p"
	.string "Qui è sempre aperto.\p"
	.string "Incredibile, vero?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Mmm…\n"
	.string "Sono sicuro che ci siamo già incontrati.\p"
	.string "Mi sono già presentato?\n"
	.string "Io sono SCOTT.\p"
	.string "Ho appena visto quelli del TEAM IDRO\n"
	.string "correre via.\p"
	.string "Non dirmi che li hai scacciati tu!$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Mmm… forse… forse\n"
	.string "questo ALLENATORE…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Penso proprio che diventeremo\n"
	.string "buoni amici noi due.\p"
	.string "Registriamoci nei nostri POKéNAV.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Registrazione di SCOTT nel POKéNAV\n"
	.string "avvenuta.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Non vorrei perderti di vista,\n"
	.string "ma allo stesso tempo vorrei tenere\l"
	.string "d’occhio anche altri talenti. Quindi\l"
	.string "andrò ancora in giro per altre città.\p"
	.string "Ci vediamo, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Ehi, non sei {PLAYER}{KUN}?\p"
	.string "Fammi indovinare, {PLAYER}{KUN}. Vuoi\n"
	.string "cimentarti nel TENDONE LOTTA?\p"
	.string "Sì! È una buona idea!\n"
	.string "Anzi, un’idea fantastica!\p"
	.string "Dopo tutto, un ALLENATORE forte è\n"
	.string "quello che ci vuole nel TENDONE LOTTA!\p"
	.string "Dai il meglio di te!$"
