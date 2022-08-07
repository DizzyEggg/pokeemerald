.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "Qui viene messo alla prova lo spirito\n"
	.string "combattivo degli ALLENATORI!\p"
	.string "Ti do il benvenuto al DOJO LOTTA!\p"
	.string "Ti farò vedere come funziona\n"
	.string "il TORNEO TRE TURNI!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Vuoi sfidare il DOJO LOTTA?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Spero che accetterai la prossima volta.$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "Nel DOJO LOTTA si combatte\n"
	.string "il TORNEO TRE TURNI.\p"
	.string "Tutti gli sfidanti partecipano con\n"
	.string "una squadra di tre POKéMON.\p"
	.string "I tre POKéMON devono essere schierati\n"
	.string "nell’ordine in cui scendono in campo.\p"
	.string "I POKéMON scendono in campo uno\n"
	.string "alla volta nell’ordine prestabilito.\p"
	.string "Una volta sceso in campo, il POKéMON\n"
	.string "non può essere sostituito se la partita\l"
	.string "è ancora aperta.\p"
	.string "Se dopo tre turni la partita non ha\n"
	.string "ancora dato esito, si passa ai punti.\p"
	.string "Se vuoi interrompere la sfida,\n"
	.string "devi salvare il gioco.\p"
	.string "Se non salvi, non potrai\n"
	.string "continuare la tua sfida.\p"
	.string "Se riesci a sconfiggere sette\n"
	.string "ALLENATORI di fila, vincerai\l"
	.string "PUNTI LOTTA.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Prima di entrare nel DOJO LOTTA, devi\n"
	.string "salvare i tuoi progressi di gioco. Ok?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "Il DOJO LOTTA offre due livelli\n"
	.string "di sfida: il LIVELLO 50 e il LIVELLO\l"
	.string "LIBERO. Quale scegli?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Scegli i tre POKéMON che vuoi mandare\n"
	.string "in campo.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Mi dispiace!\p"
	.string "Non hai tre POKéMON con tutti\n"
	.string "i requisiti.\p"
	.string "Devi avere tre POKéMON diversi per\n"
	.string "entrare.\p"
	.string "Inoltre, i POKéMON devono tenere \n"
	.string "strumenti di tipo differente.\p"
	.string "Le UOVA{STR_VAR_1} inutilizzabili qui.\p"
	.string "Torna a trovarci quando hai i requisiti.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Mi dispiace!\p"
	.string "Non hai tre POKéMON con tutti\n"
	.string "i requisiti.\p"
	.string "Per entrare, devi avere tre POKéMON \n"
	.string "diversi.\p"
	.string "Devono essere tutti di livello pari o\n"
	.string "inferiore a 50.\p"
	.string "Inoltre, i POKéMON devono tenere \n"
	.string "strumenti di tipo differente.\p"
	.string "Le UOVA{STR_VAR_1} inutilizzabili qui.\p"
	.string "Torna a trovarci quando hai i requisiti.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Ora ti accompagno nel DOJO LOTTA.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Mi dispiace!\p"
	.string "Quando hai interrotto la sfida l’ultima\n"
	.string "volta, non hai salvato il gioco.\p"
	.string "Per questo motivo, la tua sfida è\n"
	.string "stata annullata.\p"
	.string "Se ti va, puoi iniziare una nuova\n"
	.string "sfida.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Congratulazioni! Hai conseguito\n"
	.string "una serie di splendide vittorie\l"
	.string "contro sette ALLENATORI!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Il tuo risultato verrà salvato. Attendi\n"
	.string "mentre salvo i tuoi progressi.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "In commemoration of your 7-win streak,\n"
	.string "we present you with this prize.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Oh?\n"
	.string "Your BAG seems to be full.\p"
	.string "I urge you to clear space and\n"
	.string "return for your prize.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Grazie per aver partecipato!\p"
	.string "Ti prego di attendere mentre\n"
	.string "salvo i tuoi progressi.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Spero che parteciperai\n"
	.string "un’altra volta.$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Ti stavamo aspettando!\p"
	.string "Prima di accedere al DOJO LOTTA,\n"
	.string "il gioco deve essere salvato. Attendi.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Vuoi che registri nel PASS PARCO\n"
	.string "il filmato della tua ultima lotta nel\l"
	.string "DOJO LOTTA ?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "L’ARBITRO ha decretato la mia\n"
	.string "sconfitta…\p"
	.string "Non è stata una buona idea usare solo\n"
	.string "mosse difensive senza attaccare…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "La mia vittoria è stata decisa a\n"
	.string "tavolino!\p"
	.string "La mia strategia di attacco è\n"
	.string "stata premiata!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "L’ARBITRO ha deciso per il pareggio.\p"
	.string "Allo scadere del tempo, ai miei POKéMON\n"
	.string "e a quelli dell’avversario erano rimasti\l"
	.string "all’incirca gli stessi PS.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "Nel DOJO LOTTA, l’ordine di\n"
	.string "schieramento dei POKéMON è\l"
	.string "estremamente importante.\p"
	.string "Ad esempio, se il primo POKéMON\n"
	.string "è sotto certi aspetti svantaggiato,\l"
	.string "fa’ in modo che il secondo POKéMON\l"
	.string "possa contare su mosse superefficaci.\p"
	.string "Credo che sia il modo migliore per\n"
	.string "costruire una squadra vincente.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Lista delle regole del TORNEO TRE TURNI.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Quale argomento vuoi approfondire?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "Il TORNEO TRE TURNI ha regole che lo\n"
	.string "rendono molto speciale.\p"
	.string "Prima di tutto, una lotta dura solo\n"
	.string "tre turni.\p"
	.string "Se dopo tre turni non emerge\n"
	.string "un vincitore, il risultato della lotta\l"
	.string "viene deciso a tavolino.\p"
	.string "L’ARBITRO decreterà il vincitore\n"
	.string "sulla base di come hanno lottato\l"
	.string "i POKéMON.\p"
	.string "Inoltre, il POKéMON non potrà essere\n"
	.string "sostituito prima che la sua lotta non\l"
	.string "abbia dato un esito.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "Il primo criterio di giudizio è\n"
	.string "“Mente”.\l"
	.string "Con questo indice si valuta\l"
	.string "l’aggressività dei lottatori.\p"
	.string "Il giudizio si basa sulla frequenza\n"
	.string "d’uso di mosse d’attacco da parte\l"
	.string "dell’ALLENATORE.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "Il secondo criterio di giudizio è\n"
	.string "“Abilità”.\l"
	.string "Con questo indice si valuta l’efficacia\l"
	.string "delle mosse utilizzate.\p"
	.string "Più una mossa è efficace, maggiore\n"
	.string "è l’Abilità ad essa associata.\p"
	.string "Se una mossa non va a segno, l’Abilità\n"
	.string "viene giudicata negativamente.\p"
	.string "Nelle mosse d’attacco, l’indice di\n"
	.string "Abilità aumenta se la mossa è stata\l"
	.string "“superefficace”, mentre diminuisce\l"
	.string "se “non è stata molto efficace”.\p"
	.string "L’indice di Abilità non aumenta con\n"
	.string "mosse quali PROTEZIONE e INDIVIDUA.\p"
	.string "Se il tuo POKéMON non riesce a\n"
	.string "contrattaccare a PROTEZIONE e\l"
	.string "INDIVIDUA, il suo indice di Abilità\l"
	.string "rimane invariato.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "Il terzo criterio di giudizio è\n"
	.string "“Corpo”.\l"
	.string "Con questo indice si valutano i PS\l"
	.string "rimasti alla fine della lotta.\p"
	.string "Nella valutazione vengono calcolati\n"
	.string "i PS di un POKéMON all’inizio e alla\l"
	.string "fine della lotta.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Hai strappato la vittoria alla MAESTRA\n"
	.string "DOJO, l’ultima di sette ALLENATORI!\p"
	.string "Congratulazioni vivissime per\n"
	.string "la tua prova esemplare!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Come riconoscimento per il\n"
	.string "tuo spirito combattivo, accetta\l"
	.string "questo premio in PUNTI LOTTA.$"
