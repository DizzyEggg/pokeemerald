.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Questa è la CUPOLA LOTTA!\n"
	.string "Diventa un astro imbattibile!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Questa è l’AZIENDA LOTTA!\n"
	.string "Cerca i POKéMON più forti!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Questa è la SERPE LOTTA!\n"
	.string "Scegli uno dei tre cammini!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Questa è la TORRE LOTTA.\p"
	.string "Gli ALLENATORI mandano in campo i\n"
	.string "POKéMON meglio allenati per una serie\l"
	.string "di gare a eliminazione diretta.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Ciao, sei qui per prendere il traghetto?\n"
	.string "Mi fai vedere il BIGLIETTO?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} non ha il BIGLIETTO.\p"
	.string "Spiacente.\p"
	.string "Devi avere il BIGLIETTO per imbarcarti\n"
	.string "sul traghetto.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} mostra il BIGLIETTO.\p"
	.string "Perfetto! Non hai bisogno d’altro!\p"
	.string "Dove desideri andare?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "Ok, si salpa per PORTO SELCEPOLI!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "Ok, si salpa per PORTO ALGHEPOLI!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Spero di rivederti un’altra volta!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Sali sul traghetto e attendi\n"
	.string "la partenza.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Dove vorresti andare allora?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Fra i miei amici sono il migliore.\n"
	.string "Ma qui, sono un disastro!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Voglio visitare la TORRE LOTTA,\n"
	.string "ma anche con la mappa del PARCO\l"
	.string "LOTTA non riesco a trovarla.\p"
	.string "Questo posto è immenso!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Volevo partecipare a una sfida\n"
	.string "appena arrivato.\p"
	.string "Ma nel tragitto mi è venuto il mal di\n"
	.string "mare… urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Questo posto non è aperto a tutti,\n"
	.string "lo sapevi?\p"
	.string "Solo gli ALLENATORI di indiscussa\n"
	.string "bravura possono accedervi.\p"
	.string "Per questo molti ALLENATORI ignorano\n"
	.string "persino l’esistenza del PARCO LOTTA.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Ehi, fratello…\p"
	.string "Sei sicuro che possiamo partecipare\n"
	.string "alle sfide anche senza POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Uh…\n"
	.string "Sono sicuro che ce la caveremo.\p"
	.string "Almeno credo…\p"
	.string "Ti ricordi le parole di quell’omone?\n"
	.string "“Si noleggiano POKéMON!”.$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Questa è l’AZIENDA LOTTA.\n"
	.string "Qui si noleggiano POKéMON forti.\p"
	.string "Mi sorge un dubbio.\n"
	.string "Chi alleva i POKéMON a nolo?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Ho paura di entrare nella SERPE LOTTA\n"
	.string "a causa di SEVIPER…\p"
	.string "Ma… visto che sono arrivata fin\n"
	.string "qui, voglio provare a vincere tutto!\l"
	.string "Che fifa!$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Giochiamo a morra cinese!\n"
	.string "Un, due, tre!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Ho vinto!\n"
	.string "Sfiderò la SERPE LOTTA!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, no!\n"
	.string "Ho perso.\p"
	.string "Oggi non è giornata.\n"
	.string "Rimanderò la mia sfida alla SERPE LOTTA\l"
	.string "a domani.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Credo che qui non ci siano altre persone\n"
	.string "che, per un qualche oscuro motivo,\l"
	.string "preferiscano la pesca alla lotta.\p"
	.string "Uh? Qui non c’è nulla da pescare?\n"
	.string "Che delusione…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Oggi lotterò a più non posso. Voglio\n"
	.string "aggiudicarmi un SIMBOLO.\l"
	.string "Costi quel che costi.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Vuoi sfidare la CUPOLA LOTTA?\p"
	.string "Ti auguro tanta fortuna.\n"
	.string "Chissà che un giorno, dopo tante\l"
	.string "vittorie, non ci sfideremo in una lotta.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Nonno, per di qui!\n"
	.string "Ecco la CUPOLA LOTTA!\l"
	.string "Nonno, fai vedere chi sei!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Questa sarebbe la CUPOLA LOTTA?\n"
	.string "I GENTILUOMINI non mi batteranno!\p"
	.string "Ma da dove si entra?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Fino a poco tempo fa qui non c’era\n"
	.string "nulla.\p"
	.string "Ora guarda questo posto meraviglioso!\n"
	.string "Voglio portarci mia madre.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Finalmente sono arrivata al PARCO\n"
	.string "LOTTA!\p"
	.string "Sono sicura che il mio aspetto e le mie\n"
	.string "capacità faranno colpo!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Ehm, ehm…\p"
	.string "Questo posto pullula di gente che\n"
	.string "ci sa fare.\p"
	.string "Ehm, ehm…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Uhm, ehm…\p"
	.string "Un po’ di tempo fa ho incontrato una\n"
	.string "ragazza più grande nella SERPE LOTTA.\p"
	.string "Mi guardava con occhi terrificanti e\n"
	.string "stralunati.\p"
	.string "Uhm, ehm…\p"
	.string "Tutta inviperita, con aria da saccente,\n"
	.string "mi ha detto: “Smettila di mangiare!”.\p"
	.string "È stata un’esperienza da far\n"
	.string "accapponare la pelle.\p"
	.string "Uhm, ehm…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Ma cosa stai dicendo?\n"
	.string "Questo non è nulla!\p"
	.string "Mentre stavo facendo il tifo per lui,\n"
	.string "il nostro sguardo si è incrociato e\l"
	.string "sono state scintille!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Cooooosa?!\n"
	.string "Pfft!\p"
	.string "Guarda che è successo solo perché\n"
	.string "ero seduta accanto a te!\p"
	.string "L’ASTRO CUPOLA ha voltato lo sguardo\n"
	.string "perché urlavo a squarciagola!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Ssshhh!\n"
	.string "Cos’è questo baccano!\p"
	.string "Voi fan della buona sorte dovreste\n"
	.string "fare il tifo per un CAPOPALESTRA!\p"
	.string "L’ASTRO CUPOLA è mio!\n"
	.string "È il mio unico idolo!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Quelle persone che stanno\n"
	.string "bisticciando…\p"
	.string "È difficile da credere, ma una volta\n"
	.string "erano bravi ALLENATORI.\p"
	.string "Erano incredibilmente forti e molto\n"
	.string "famosi.\p"
	.string "Ma sono stati messi in ombra da un\n"
	.string "certo ALLENATORE durante un torneo.\p"
	.string "L’ALLENATORE ha dato una tale prova di\n"
	.string "superiorità da stregarli.\p"
	.string "Ora sono tutti fan dell’ALLENATORE.\n"
	.string "Ogni giorno si recano alla CUPOLA LOTTA\l"
	.string "e fanno il tifo per lui.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Corre voce che qualcuno abbia visto\n"
	.string "un POKéMON con una coda molto\l"
	.string "lunga nel PARCO LOTTA.\p"
	.string "Sono sicura che è adorabile…\p"
	.string "Le sfide possono attendere. Devo\n"
	.string "trovare questa creatura deliziosa!$"

