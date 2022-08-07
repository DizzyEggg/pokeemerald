.set LOCALID_ATTENDANT, 1
.set LOCALID_HINT_GIVER, 2

BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Qui viene messa alla prova l’audacia\n"
	.string "degli ALLENATORI!\p"
	.string "Ti do il benvenuto alla PIRAMIDE LOTTA!\p"
	.string "Sarò la tua guida nella LOTTA\n"
	.string "ESPLORAZIONE.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Hai il coraggio di accettare la sfida\n"
	.string "LOTTA ESPLORAZIONE?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Spero che accetterai\n"
	.string "la prossima volta.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "La LOTTA ESPLORAZIONE è un evento\n"
	.string "nel quale devi perlustrare la PIRAMIDE\l"
	.string "cercando di raggiungere la cima.\p"
	.string "La PIRAMIDE ha sette piani di dedali\n"
	.string "pieni zeppi di ALLENATORI, ma anche\l"
	.string "di POKéMON selvatici.\p"
	.string "Devi iscrivere tre POKéMON, ma\n"
	.string "nessuno può tenere uno strumento.\p"
	.string "Prima di iniziare ti verrà dato uno\n"
	.string "ZAINO LOTTA per gli strumenti.\p"
	.string "Se perdi, dovrai dire addio agli\n"
	.string "strumenti accumulati nello ZAINO LOTTA.\p"
	.string "Se vuoi interrompere la sfida, devi\n"
	.string "selezionare “PAUSA” e salvare\l"
	.string "il gioco.\p"
	.string "Se non salvi prima di interromperla,\n"
	.string "la tua sfida verrà annullata.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "La PIRAMIDE offre due livelli di\n"
	.string "sfida: il LIVELLO 50 e il LIVELLO\l"
	.string "LIBERO. Quale scegli?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Bene. Ora scegli i tre POKéMON che\n"
	.string "vuoi portare con te in quest’avventura.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "C’è un problemino!\p"
	.string "A quanto pare non hai tre POKéMON\n"
	.string "con tutti i requisiti.\p"
	.string "Ricordati di prelevare tutti gli\n"
	.string "strumenti tenuti dai POKéMON.\p"
	.string "Le UOVA{STR_VAR_1} inutilizzabili qui.\p"
	.string "Quando hai i requisiti, torna pure\n"
	.string "a trovarci.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "C’è un problemino!\p"
	.string "A quanto pare non hai tre POKéMON\n"
	.string "con tutti i requisiti.\p"
	.string "Per entrare, devi avere tre POKéMON \n"
	.string "diversi di livello pari o inferiore a 50.\p"
	.string "Ricordati di prelevare tutti gli\n"
	.string "strumenti tenuti dai POKéMON.\p"
	.string "Le UOVA{STR_VAR_1} inutilizzabili qui.\p"
	.string "Quando hai i requisiti, torna pure\n"
	.string "a trovarci.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Prima di entrare nella PIRAMIDE LOTTA,\n"
	.string "devi salvare il tuo gioco. Ok?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Bene. Ti faccio strada nella\n"
	.string "PIRAMIDE LOTTA.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "{PLAYER}, mentre esplori, il tuo ZAINO\n"
	.string "lo tengo io.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "In cambio, prendi pure lo ZAINO LOTTA\n"
	.string "che hai usato precedentemente.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "In cambio, prendi pure questo\n"
	.string "ZAINO LOTTA.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} ottiene lo ZAINO LOTTA\n"
	.string "in cambio del suo ZAINO.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Per passare al piano superiore della\n"
	.string "PIRAMIDE posizionati su questo\l"
	.string "pannello colorato nel pavimento.\p"
	.string "Spero vivamente che tu possa\n"
	.string "superare questa sfida!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Un bel problema!\p"
	.string "Quando hai interrotto la sfida l’ultima\n"
	.string "volta, non hai salvato il gioco.\p"
	.string "Per questo motivo, la tua sfida è\n"
	.string "stata annullata. Spiacente!\p"
	.string "Ti restituisco il tuo ZAINO.\p"
	.string "{PLAYER} ha riavuto il suo ZAINO.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Sono contento di rivederti!\p"
	.string "Hai conquistato la PIRAMIDE!\n"
	.string "Fantastico!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, c’è un problemino.\p"
	.string "Almeno un POKéMON tiene\n"
	.string "uno strumento.\p"
	.string "Spiacente, non si possono portare via\n"
	.string "gli strumenti ottenuti nella PIRAMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Tutti gli strumenti tenuti dai tuoi\n"
	.string "POKéMON verranno trasferiti\l"
	.string "nello ZAINO LOTTA, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Nello ZAINO LOTTA non c’è spazio per\n"
	.string "tutti i tuoi strumenti. Spiacente!\p"
	.string "Scegli gli strumenti da tenere nello\n"
	.string "ZAINO LOTTA e da far tenere ai\l"
	.string "tuoi POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Almeno un POKéMON sta tenendo\n"
	.string "uno strumento.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Scegli gli strumenti da tenere nello\n"
	.string "ZAINO LOTTA e da far tenere ai\l"
	.string "tuoi POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} returned everything that\n"
	.string "the POKéMON held.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "Metterò da parte lo ZAINO LOTTA che hai\n"
	.string "usato per la tua prossima sfida.\p"
	.string "{PLAYER} ha consegnato lo ZAINO LOTTA\n"
	.string "per riavere il suo ZAINO.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Il tuo risultato verrà salvato.\n"
	.string "Attendi.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "As a memento for conquering\n"
	.string "the BATTLE PYRAMID, please take this.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah…\n"
	.string "Your BAG appears to be filled.\p"
	.string "Please return after you’ve organized\n"
	.string "your BAG’s contents.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Che delusione…\p"
	.string "Questo è lo ZAINO che ho custodito\n"
	.string "per te.\p"
	.string "{PLAYER} ha riavuto il suo ZAINO.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Aspettiamo con ansia la tua prossima\n"
	.string "sfida.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "We have been looking forward to\n"
	.string "your arrival!\p"
	.string "Here is your prize for conquering\n"
	.string "the PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Salve…\p"
	.string "Faccio profezie sulle avversità a cui\n"
	.string "andrai incontro nella PIRAMIDE…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Vedo uno zampillo di scintille…\p"
	.string "In questo zampillo, i tuoi POKéMON\n"
	.string "subiranno gli effetti della paralisi…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Vedo del veleno…\p"
	.string "I tuoi POKéMON soffriranno a causa\n"
	.string "degli effetti dell’avvelenamento…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Vedo fiammate di un rosso acceso…\p"
	.string "I tuoi POKéMON soffriranno a causa\n"
	.string "delle scottature…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Vedo un accesso di rabbia\n"
	.string "incontenibile…\p"
	.string "È una maledizione…\p"
	.string "I tuoi POKéMON con i PUNTI POTENZA \n"
	.string "azzerati dovranno ricorrere\l"
	.string "a SCONTRO…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Vedo POKéMON elevarsi in volo…\p"
	.string "I tuoi POKéMON saranno in difficoltà\n"
	.string "perché le mosse di tipo TERRA\l"
	.string "risulteranno inefficaci…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Sento un’energia potentissima\n"
	.string "sprigionarsi dal terreno…\p"
	.string "I tuoi POKéMON saranno incapaci di\n"
	.string "reagire a tanta potenza…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Vedo POKéMON di tipo GHIACCIO…\p"
	.string "I tuoi POKéMON lotteranno contro gli\n"
	.string "effetti ibernanti del congelamento…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Vedo una raffica di mosse che mettono\n"
	.string "in pericolo chi le usa…\p"
	.string "I tuoi POKéMON soccomberanno a\n"
	.string "tali mosse…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Vedo POKéMON di tipo PSICO…\p"
	.string "I tuoi POKéMON saranno tormentati da\n"
	.string "mosse di tipo PSICO…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Vedo POKéMON di tipo ROCCIA…\p"
	.string "I tuoi POKéMON saranno colpiti da mosse\n"
	.string "di tipo ROCCIA…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Vedo POKéMON di tipo LOTTA…\p"
	.string "I tuoi POKéMON saranno colpiti da mosse\n"
	.string "di tipo LOTTA…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "PIOGGIADANZA… GIORNODISOLE…\n"
	.string "TERREMPESTA… GRANDINE…\p"
	.string "I POKéMON si rafforzeranno con\n"
	.string "le condizioni atmosferiche…\p"
	.string "I tuoi POKéMON saranno confusi da tipi\n"
	.string "differenti di mosse…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Vedo POKéMON di tipo COLEOTTERO…\p"
	.string "I tuoi POKéMON saranno bersaglio di\n"
	.string "diversi tipi di attacchi.…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Vedo POKéMON di tipo BUIO…\p"
	.string "I tuoi POKéMON saranno colpiti da mosse\n"
	.string "di tipo BUIO…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Vedo POKéMON di tipo ACQUA…\p"
	.string "I tuoi POKéMON saranno colpiti da mosse\n"
	.string "di tipo ACQUA…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Vedo POKéMON di tipo SPETTRO…\p"
	.string "I tuoi POKéMON saranno colpiti da mosse\n"
	.string "di tipo SPETTRO…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Vedo POKéMON di tipo ACCIAIO…\p"
	.string "I tuoi POKéMON saranno colpiti da mosse\n"
	.string "estremamente potenti…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Vedo POKéMON di tipo VOLANTE…\p"
	.string "I tuoi POKéMON saranno colpiti da mosse\n"
	.string "estremamente potenti…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Vedo le specie che si sono evolute\n"
	.string "grazie al potere delle pietre…\p"
	.string "Vedo fuoco, acqua ed elettricità…\p"
	.string "I tuoi POKéMON saranno colpiti da\n"
	.string "questi tre poteri…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Vedo POKéMON di tipo NORMALE…\p"
	.string "I tuoi POKéMON saranno colpiti da mosse\n"
	.string "estremamente potenti…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Puoi scegliere se credere o no alle\n"
	.string "mie profezie…\p"
	.string "Il futuro può modificarsi in un istante!\n"
	.string "In bocca al lupo per la tua avventura…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Lo sapevi?\p"
	.string "Se corri veloce, può succedere che gli\n"
	.string "ALLENATORI ti notino e si avvicinino\l"
	.string "per sfidarti in una lotta.\p"
	.string "Se vuoi evitare gli ALLENATORI,\n"
	.string "non incrociare il loro sguardo e\l"
	.string "cammina con cautela davanti\l"
	.string "a loro.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Aaaaaaarrrrgh!\p"
	.string "Avevo un sacco di strumenti,\n"
	.string "ma li ho persi con la sconfitta!\p"
	.string "Aaaaaaarrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Che bello rivederti!\n"
	.string "Hai compiuto un’impresa memorabile!\p"
	.string "Hai sconfitto il RE PIRAMIDE e hai\n"
	.string "conquistato la PIRAMIDE LOTTA!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Giovane promessa! Come riconoscimento\n"
	.string "per la tua audacia, accetta questo\l"
	.string "premio in PUNTI LOTTA!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Lista delle regole della LOTTA\n"
	.string "ESPLORAZIONE.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Quale argomento vuoi approfondire?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Una volta che la PIRAMIDE è stata\n"
	.string "conquistata, vi appaiono nuove\l"
	.string "specie di POKéMON selvatici.\p"
	.string "Studia, osserva e conosci i POKéMON\n"
	.string "selvatici che incontrerai.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "All’interno della PIRAMIDE ti attendono\n"
	.string "gli ALLENATORI.\p"
	.string "Ne puoi trovare fino a otto per piano.\p"
	.string "Quando sconfiggi un ALLENATORE,\n"
	.string "riceverai un suggerimento utile per\l"
	.string "la tua avventura.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Ogni volta che entri nella PIRAMIDE,\n"
	.string "i suoi dedali si trasformano.\p"
	.string "I dedali sono scarsamente illuminati.\n"
	.string "Devi muoverti con cautela.\p"
	.string "Quando sconfiggi un POKéMON selvatico\n"
	.string "o un ALLENATORE, avrai più luce.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "Lo ZAINO LOTTA sostituisce il tuo\n"
	.string "ZAINO abituale quando ti trovi nella\l"
	.string "PIRAMIDE.\p"
	.string "Ci sono due ZAINI LOTTA: uno per\n"
	.string "l’avventura di LIVELLO 50 e l’altro\l"
	.string "per quella di LIVELLO LIBERO.\p"
	.string "Entrambi possono contenere fino a 99\n"
	.string "unità di dieci tipi di strumenti diversi.\p"
	.string "In caso di sconfitta, perderai\n"
	.string "il contenuto dello ZAINO LOTTA.$"

