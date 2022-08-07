BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_E, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_0
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Messaggio prova.$"

gText_BattlePyramidConfirmRest::
	.string "La tua avventura nella PIRAMIDE LOTTA\n"
	.string "verrà salvata affinché tu possa\l"
	.string "interrompere il gioco. Va bene?$"

gText_BattlePyramidConfirmRetire::
	.string "Vuoi ritirarti dalla tua avventura nella\n"
	.string "PIRAMIDE?$"

BattlePyramid_Text_ExitHintUp1::
	.string "L’uscita di questo piano è\n"
	.string "in questa direzione: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "L’uscita di questo piano è\n"
	.string "in questa direzione: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "L’uscita di questo piano è\n"
	.string "in questa direzione: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "L’uscita di questo piano è\n"
	.string "in questa direzione: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "L’uscita su questo piano è\n"
	.string "in questa direzione: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft2::
	.string "L’uscita su questo piano è\n"
	.string "in questa direzione: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight2::
	.string "L’uscita su questo piano è\n"
	.string "in questa direzione: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown2::
	.string "L’uscita su questo piano è\n"
	.string "in questa direzione: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp3::
	.string "L’uscita è in questa\n"
	.string "direzione: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft3::
	.string "L’uscita è in questa\n"
	.string "direzione: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight3::
	.string "L’uscita è in questa\n"
	.string "direzione: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown3::
	.string "L’uscita è in questa\n"
	.string "direzione: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp4::
	.string "Su questo piano l’uscita è da qualche\n"
	.string "parte in questa direzione: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft4::
	.string "Su questo piano l’uscita è da qualche\n"
	.string "parte in questa direzione: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight4::
	.string "Su questo piano l’uscita è da qualche\n"
	.string "parte in questa direzione: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown4::
	.string "Su questo piano l’uscita è da qualche\n"
	.string "parte in questa direzione: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp5::
	.string "L’uscita?\n"
	.string "È in questa direzione: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft5::
	.string "L’uscita?\n"
	.string "È in questa direzione: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight5::
	.string "L’uscita?\n"
	.string "È in questa direzione: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown5::
	.string "L’uscita?\n"
	.string "È in questa direzione: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp6::
	.string "L’uscita si trova in questa\n"
	.string "direzione: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft6::
	.string "L’uscita si trova in questa\n"
	.string "direzione: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight6::
	.string "L’uscita si trova in questa\n"
	.string "direzione: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown6::
	.string "L’uscita si trova in questa\n"
	.string "direzione: {DOWN_ARROW}$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Ce ne sono ancora otto\n"
	.string "da trovare.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Ce ne sono ancora sette\n"
	.string "da trovare.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Ce ne sono ancora sei\n"
	.string "da trovare.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Ce ne sono ancora cinque\n"
	.string "da trovare.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Ce ne sono ancora quattro\n"
	.string "da trovare.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Ce ne sono ancora tre\n"
	.string "da trovare.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Ce ne sono ancora due\n"
	.string "da trovare.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Ce n’è ancora uno\n"
	.string "da trovare.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Stai cercando strumenti?\p"
	.string "Non ce ne sono più in giro!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "Ci sono ancora otto strumenti\n"
	.string "in giro.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "Ci sono ancora sette strumenti\n"
	.string "in giro.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "Ci sono ancora sei strumenti\n"
	.string "in giro.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "Ci sono ancora cinque strumenti\n"
	.string "in giro.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "Ci sono ancora quattro strumenti\n"
	.string "in giro.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "Ci sono ancora tre strumenti\n"
	.string "in giro.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "Ci sono ancora due strumenti\n"
	.string "in giro.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "C’è ancora uno strumento\n"
	.string "in giro.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Siccome hai vinto, ti svelerò\n"
	.string "un piccolo segreto!\p"
	.string "Non ci sono più strumenti\n"
	.string "in giro.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano ci siano\n"
	.string "ancora otto strumenti da trovare.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano ci siano\n"
	.string "ancora sette strumenti da trovare.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano ci siano\n"
	.string "ancora sei strumenti da trovare.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano ci siano\n"
	.string "ancora cinque strumenti da trovare.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano ci siano\n"
	.string "ancora quattro strumenti da trovare.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano ci siano\n"
	.string "ancora tre strumenti da trovare.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano ci siano\n"
	.string "ancora due strumenti da trovare.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano ci sia\n"
	.string "ancora uno strumento da trovare.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Come va la tua collezione di strumenti?\p"
	.string "Credo che su questo piano non ci\n"
	.string "siano più strumenti da trovare.\l"
	.string "Stammi bene!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che ci siano ancora otto strumenti\n"
	.string "per terra.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che ci siano ancora sette\n"
	.string "strumenti per terra.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che ci siano ancora sei strumenti\n"
	.string "per terra.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che ci siano ancora cinque\n"
	.string "strumenti per terra.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che ci siano ancora quattro\n"
	.string "strumenti per terra.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che ci siano ancora tre strumenti\n"
	.string "per terra.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che ci siano ancora due strumenti\n"
	.string "per terra.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che ci sia ancora uno strumento\n"
	.string "per terra.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Ti meriti un suggerimento perché sei\n"
	.string "forte!\p"
	.string "Pare che non ci siano più strumenti\n"
	.string "per terra.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE gli strumenti siano otto…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE gli strumenti siano sette…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE gli strumenti siano sei…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE gli strumenti siano cinque…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE gli strumenti siano quattro…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE gli strumenti siano tre…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE gli strumenti siano due…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE ci sia uno strumento…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "Sembra che su questo piano della\n"
	.string "PIRAMIDE non ci siano strumenti…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano ce ne\n"
	.string "siano ancora otto.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano ce ne\n"
	.string "siano ancora sette.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano ce ne\n"
	.string "siano ancora sei.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano ce ne\n"
	.string "siano ancora cinque.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano ce ne\n"
	.string "siano ancora quattro.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano ce ne\n"
	.string "siano ancora tre.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano ce ne\n"
	.string "siano ancora due.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano ce ne\n"
	.string "sia ancora uno.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Hai raccolto qualche strumento?\p"
	.string "Credo che su questo piano non\n"
	.string "ce ne siano più.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Sei incredibile!\p"
	.string "Ma ci sono ben sette ALLENATORI\n"
	.string "agguerriti oltre a me!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Sei incredibile!\p"
	.string "Ma ci sono ben sei ALLENATORI\n"
	.string "agguerriti oltre a me!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Sei incredibile!\p"
	.string "Ma ci sono ben cinque ALLENATORI\n"
	.string "agguerriti oltre a me!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Sei incredibile!\p"
	.string "Ma ci sono ben quattro ALLENATORI\n"
	.string "agguerriti oltre a me!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Sei incredibile!\p"
	.string "Ma ci sono ben tre ALLENATORI\n"
	.string "agguerriti oltre a me!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Sei incredibile!\p"
	.string "Ma ci sono ben due ALLENATORI\n"
	.string "agguerriti oltre a me!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Sei incredibile!\p"
	.string "Ma c’è ancora un ALLENATORE\n"
	.string "agguerrito oltre a me!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Sei incredibile!\p"
	.string "Non ci sono più ALLENATORI in grado\n"
	.string "di batterti!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Che disdetta!\p"
	.string "Ma ci sono ancora sette ALLENATORI.\n"
	.string "Qualcuno riuscirà a sconfiggerti!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Che disdetta!\p"
	.string "Ma ci sono ancora sei ALLENATORI.\n"
	.string "Qualcuno riuscirà a sconfiggerti!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Che disdetta!\p"
	.string "Ma ci sono ancora cinque ALLENATORI.\n"
	.string "Qualcuno riuscirà a sconfiggerti!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Che disdetta!\p"
	.string "Ma ci sono ancora quattro ALLENATORI.\n"
	.string "Qualcuno riuscirà a sconfiggerti!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Che disdetta!\p"
	.string "Ma ci sono ancora tre ALLENATORI.\n"
	.string "Qualcuno riuscirà a sconfiggerti!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Che disdetta!\p"
	.string "Ma ci sono ancora due ALLENATORI.\n"
	.string "Qualcuno riuscirà a sconfiggerti!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Che disdetta!\p"
	.string "Ma c’è ancora un ALLENATORE.\n"
	.string "Ti sconfiggerà.$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Che disdetta!\p"
	.string "Oltretutto non ci sono più ALLENATORI\n"
	.string "che possano lottare contro di te!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Sei impressionante!\p"
	.string "Su questo piano ci sono ancora sette\n"
	.string "ALLENATORI. Riuscirai a batterli tutti?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Sei impressionante!\p"
	.string "Su questo piano ci sono ancora sei\n"
	.string "ALLENATORI. Riuscirai a batterli tutti?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Sei impressionante!\p"
	.string "Su questo piano ci sono ancora cinque\n"
	.string "ALLENATORI. Riuscirai a batterli tutti?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Sei impressionante!\p"
	.string "Su questo piano ci sono ancora quattro\n"
	.string "ALLENATORI. Riuscirai a batterli tutti?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Sei impressionante!\p"
	.string "Su questo piano ci sono ancora tre\n"
	.string "ALLENATORI. Riuscirai a batterli tutti?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Sei impressionante!\p"
	.string "Su questo piano ci sono ancora due\n"
	.string "ALLENATORI. Riuscirai a batterli?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Sei impressionante!\p"
	.string "Su questo piano c’è ancora un\n"
	.string "ALLENATORE. Riuscirai a batterlo?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Sei impressionante!\p"
	.string "Hai battuto tutti gli ALLENATORI di\n"
	.string "questo piano.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Potresti sconfiggere tutti e sette gli\n"
	.string "ALLENATORI rimasti su questo piano.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Potresti sconfiggere tutti e sei gli\n"
	.string "ALLENATORI rimasti su questo piano.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Potresti sconfiggere tutti e cinque gli\n"
	.string "ALLENATORI rimasti su questo piano.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Potresti sconfiggere tutti e quattro\n"
	.string "gli ALLENATORI rimasti su questo piano.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Potresti sconfiggere tutti e tre gli\n"
	.string "ALLENATORI rimasti su questo piano.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Potresti sconfiggere tutti e due gli\n"
	.string "ALLENATORI rimasti su questo piano.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Potresti sconfiggere persino l’ultimo\n"
	.string "ALLENATORE rimasto su questo piano.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Non è rimasto più nessuno in grado\n"
	.string "di sconfiggerti…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Hai la stoffa per battere i sette\n"
	.string "ALLENATORI esperti rimasti.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Hai la stoffa per battere i sei\n"
	.string "ALLENATORI esperti rimasti.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Hai la stoffa per battere i cinque\n"
	.string "ALLENATORI esperti rimasti.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Hai la stoffa per battere i quattro\n"
	.string "ALLENATORI esperti rimasti.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Hai la stoffa per battere i tre\n"
	.string "ALLENATORI esperti rimasti.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Hai la stoffa per battere i due\n"
	.string "ALLENATORI esperti rimasti.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Hai la stoffa per battere l’unico\n"
	.string "ALLENATORE esperto rimasto.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "La tua abilità è innegabile.\p"
	.string "Qui non ci sono altri ALLENATORI in\n"
	.string "grado di batterti.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Continuerai a vincere contro i\n"
	.string "sette ALLENATORI rimasti?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Continuerai a vincere contro i\n"
	.string "sei ALLENATORI rimasti?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Continuerai a vincere contro i\n"
	.string "cinque ALLENATORI rimasti?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Continuerai a vincere contro i\n"
	.string "quattro ALLENATORI rimasti?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Continuerai a vincere contro i\n"
	.string "tre ALLENATORI rimasti?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Continuerai a vincere contro i\n"
	.string "due ALLENATORI rimasti?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Continuerai a vincere contro\n"
	.string "l’ultimo ALLENATORE rimasto?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Non ci sono altri ALLENATORI in\n"
	.string "grado di sfidarti…$"
