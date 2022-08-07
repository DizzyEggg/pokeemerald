BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "Che cosa vuoi?\p"
	.string "Non vedi che qui si lavora?\n"
	.string "Perché non togli il disturbo?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "Uh?\n"
	.string "Mi sembri un ALLENATORE forte.\p"
	.string "Eheh…\n"
	.string "Ascolta, ho una proposta da farti.\p"
	.string "Insieme a un piccolo gruppo di amici\n"
	.string "facciamo un giochino ispirato al\l"
	.string "PARCO LOTTA.\p"
	.string "Le regole sono davvero semplici.\p"
	.string "Innanzitutto, scegliamo un edificio\n"
	.string "del PARCO LOTTA.\p"
	.string "Poi, ognuno di noi scommette\n"
	.string "PUNTI LOTTA su un ALLENATORE\l"
	.string "a scelta che parteciperà alla sfida\l"
	.string "in quell’edificio.\p"
	.string "La persona che ha scommesso\n"
	.string "sull’ALLENATORE vincente si\l"
	.string "prende tutti i PUNTI LOTTA in palio.\p"
	.string "Facile, vero?\n"
	.string "Passiamo al sodo…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Sto cercando un ALLENATORE che\n"
	.string "sfidi le SALE LOTTA in SINGOLO\l"
	.string "della TORRE LOTTA.\p"
	.string "Ma, finora, non ho incrociato un\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Sto cercando un ALLENATORE che\n"
	.string "sfidi le SALE LOTTA in DOPPIO\l"
	.string "della TORRE LOTTA.\p"
	.string "Ma, finora, non ho incrociato un\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Sto cercando un ALLENATORE che\n"
	.string "sfidi le SALE LOTTA MULTIPLA\l"
	.string "della TORRE LOTTA.\p"
	.string "Ma, finora, non ho incrociato un\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Sto cercando un ALLENATORE\n"
	.string "che si iscriva al TORNEO LOTTA\l"
	.string "in SINGOLO della CUPOLA LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Sto cercando un ALLENATORE\n"
	.string "che si iscriva al TORNEO LOTTA\l"
	.string "in DOPPIO della CUPOLA LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Sto cercando un ALLENATORE che si\n"
	.string "iscriva al TORNEO LOTTA SCAMBIO\l"
	.string "in SINGOLO dell’AZIENDA LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Sto cercando un ALLENATORE che si\n"
	.string "iscriva al TORNEO LOTTA SCAMBIO\l"
	.string "in DOPPIO dell’AZIENDA LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Sto cercando un ALLENATORE che \n"
	.string "sfidi le AREE LOTTA in SINGOLO\l"
	.string "del PALAZZO LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Sto cercando un ALLENATORE che \n"
	.string "sfidi le AREE LOTTA in DOPPIO\l"
	.string "del PALAZZO LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Sto cercando un ALLENATORE che si\n"
	.string "iscriva al TORNEO TRE TURNI del\l"
	.string "DOJO LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Sto cercando un ALLENATORE che si\n"
	.string "iscriva alla LOTTA DILEMMA della\l"
	.string "SERPE LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Sto cercando un ALLENATORE che si\n"
	.string "iscriva alla LOTTA ESPLORAZIONE\l"
	.string "della PIRAMIDE LOTTA.\p"
	.string "Ma, finora, non ho incrociato nessun\n"
	.string "ALLENATORE all’altezza.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Farò in modo che sia vantaggioso\n"
	.string "anche per te. Cosa ne pensi?\l"
	.string "Vuoi partecipare all’evento?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Benissimo.\n"
	.string "Ehm… che ne dici di prestarmi\l"
	.string "qualche PUNTO LOTTA dei tuoi?\p"
	.string "Fidati di me. Più tardi ti dimostrerò\n"
	.string "la mia riconoscenza.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Fantastico!\n"
	.string "Allora quanti riesci a prestarmene?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh, no!\n"
	.string "Non hai PUNTI LOTTA sufficienti!\p"
	.string "Non fare il pagliaccio! Non ho tempo\n"
	.string "da perdere, io!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Eheh! Grazie mille!\n"
	.string "Forza e coraggio!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Parti subito alla conquista delle SALE\n"
	.string "LOTTA in SINGOLO della TORRE LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Parti subito alla conquista delle SALE\n"
	.string "LOTTA in DOPPIO della TORRE LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Parti subito alla conquista delle SALE\n"
	.string "LOTTA MULTIPLA della TORRE LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Parti subito alla conquista del TORNEO\n"
	.string "LOTTA in SINGOLO della CUPOLA LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Parti subito alla conquista del TORNEO\n"
	.string "LOTTA in DOPPIO della CUPOLA LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Parti subito alla conquista del TORNEO\n"
	.string "LOTTA SCAMBIO in SINGOLO\l"
	.string "dell’AZIENDA LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Parti subito alla conquista del TORNEO\n"
	.string "LOTTA SCAMBIO in DOPPIO\l"
	.string "dell’AZIENDA LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Parti subito alla conquista delle AREE\n"
	.string "LOTTA in SINGOLO del PALAZZO LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Parti subito alla conquista delle AREE\n"
	.string "LOTTA in DOPPIO del PALAZZO LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Parti subito alla conquista del TORNEO\n"
	.string "TRE TURNI del DOJO LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Parti subito alla conquista della LOTTA\n"
	.string "DILEMMA della SERPE LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Parti subito alla conquista della LOTTA\n"
	.string "ESPLORAZIONE della PIRAMIDE LOTTA!\p"
	.string "Non puoi non vincere!\n"
	.string "Non farti scappare questa opportunità!\l"
	.string "Sei l’artefice del mio e del tuo destino!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Ah, sei tu… ce l’hai messa tutta…\p"
	.string "Mi dispiace, ma non posso restituirti\n"
	.string "i tuoi PUNTI LOTTA…\p"
	.string "La prossima volta dobbiamo metterci\n"
	.string "più impegno!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh, sì!\n"
	.string "Ciao, campione!\p"
	.string "Sapevo che avresti potuto farcela!\n"
	.string "Sapevo che ce l’avresti fatta!\l"
	.string "Siamo imbattibili!\p"
	.string "Ti restituisco i tuoi PUNTI LOTTA, con\n"
	.string "una piccola aggiunta da parte mia!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} ottiene\n"
	.string "{STR_VAR_1} PUNTI LOTTA.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Se sei in vena di sfide,\n"
	.string "non ti scordar di me!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Non ti interessa?! Chi non risica,\n"
	.string "non rosica!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "Ancora una volta ho dato retta\n"
	.string "all’ALLENATORE sbagliato!\p"
	.string "Forse dovrei lottare normalmente,\n"
	.string "come fanno tutti…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Quell’ALLENATORE…\p"
	.string "È bravo, ma si lascia suggestionare\n"
	.string "troppo dalla CUPOLA LOTTA…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Ihihih! So riconoscere un vincitore\n"
	.string "a colpo d’occhio!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Quegli ALLENATORI…\n"
	.string "Perché se ne stanno in panciolle?\l"
	.string "Dovrebbero partecipare alle sfide.$"
