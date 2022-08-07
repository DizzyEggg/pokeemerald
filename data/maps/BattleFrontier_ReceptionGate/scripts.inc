.set LOCALID_GREETER, 1
.set LOCALID_GUIDE, 2
.set LOCALID_SCOTT, 4

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "È la tua prima visita?\n"
	.string "Prego, da questa parte!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "La nuova frontiera della lotta POKéMON!\n"
	.string "Questo è il PARCO LOTTA!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "A chi ci visita per la prima volta\n"
	.string "rilasciamo il PASS PARCO.\p"
	.string "Si può utilizzare in tutti gli edifici\n"
	.string "del PARCO LOTTA.\p"
	.string "Et voilà!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} ottiene il PASS PARCO.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} ha messo la SCHEDA ALLENATORE\n"
	.string "nel PASS PARCO.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Spero che il PARCO LOTTA sia\n"
	.string "di tuo gradimento!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Ma tu sei {PLAYER}{KUN}!\n"
	.string "Ne hai fatta di strada!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUIDA: Oh! SIG. SCOTT!\n"
	.string "Buongiorno a lei!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: Che bello rivederti!\n"
	.string "È proprio una gioia!\p"
	.string "Fai pure le cose con calma. Qui\n"
	.string "c’è molto da esplorare.\p"
	.string "Spero che tu possa assaporare\n"
	.string "la pura essenza della lotta.\p"
	.string "Io mi sono trasferito qui. Vieni\n"
	.string "pure a trovarmi quando vuoi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Se vuoi, ti illustro i diversi edifici\n"
	.string "del PARCO LOTTA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Quale edificio ti interessa?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "È una torre gigante. Viene considerata\n"
	.string "il simbolo del PARCO LOTTA.\p"
	.string "Ci sono quattro tipi di SALA LOTTA nella\n"
	.string "torre: per le LOTTE in SINGOLO, in\l"
	.string "DOPPIO, MULTIPLE e MULTIPLE in LINK.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "La CUPOLA LOTTA è un edificio enorme\n"
	.string "fatto a forma di uovo.\p"
	.string "In questo edificio si tengono\n"
	.string "i cosiddetti TORNEI LOTTA.\p"
	.string "Nei TORNEI LOTTA si combattono sia\n"
	.string "LOTTE in SINGOLO che in DOPPIO.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "Il PALAZZO LOTTA è un edificio rosso\n"
	.string "all’estremità destra del PARCO LOTTA.\p"
	.string "Ci sono due tipi di AREE LOTTA: per \n"
	.string "LOTTE in SINGOLO e in DOPPIO.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "Il DOJO LOTTA è un edificio che\n"
	.string "si trova al centro del PARCO LOTTA,\l"
	.string "sul lato destro.\p"
	.string "Nel DOJO LOTTA si disputa\n"
	.string "il TORNEO TRE TURNI.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "L’AZIENDA LOTTA è un grande edificio\n"
	.string "che si trova qui vicino.\p"
	.string "Lì si disputa la cosiddetta LOTTA\n"
	.string "SCAMBIO.\p"
	.string "La LOTTA SCAMBIO prevede sia\n"
	.string "LOTTE in SINGOLO che in DOPPIO.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "La SERPE LOTTA è un edificio fatto a\n"
	.string "forma di POKéMON che si trova al\l"
	.string "centro del PARCO LOTTA, sul lato\l"
	.string "sinistro.\p"
	.string "Lì ha luogo un evento chiamato\n"
	.string "LOTTA DILEMMA.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "La PIRAMIDE LOTTA è un enorme edificio\n"
	.string "fatto a forma di piramide.\p"
	.string "Lì si disputa la cosiddetta\n"
	.string "LOTTA ESPLORAZIONE.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "La VILLA CLASSIFICA si trova vicino\n"
	.string "alla TORRE LOTTA.\p"
	.string "Lì troverai i risultati migliori degli\n"
	.string "ALLENATORI che si sono cimentati\l"
	.string "nelle numerose sfide del PARCO LOTTA.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "L’UFFICIO RITIRO PREMI si\n"
	.string "trova vicino alla TORRE LOTTA.\p"
	.string "Lì puoi scambiare i PUNTI LOTTA che\n"
	.string "hai guadagnato nel PARCO LOTTA con\l"
	.string "favolosi premi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Se vuoi, ti illustro le regole di base\n"
	.string "comuni a tutte le sfide che si\l"
	.string "svolgono negli edifici del PARCO\l"
	.string "LOTTA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Quale regola ti interessa?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Tutte le sfide del PARCO LOTTA\n"
	.string "offrono due livelli di sfida: il LIVELLO\l"
	.string "50 e il LIVELLO LIBERO.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Il LIVELLO 50 è aperto ai POKéMON di\n"
	.string "livello pari o inferiore a 50.\p"
	.string "Ricorda, però, che nessun ALLENATORE\n"
	.string "avversario manderà in campo POKéMON\l"
	.string "al di sotto del livello 50.\p"
	.string "Questo è il livello base di tutte\n"
	.string "le lotte del PARCO LOTTA.\p"
	.string "Per iniziare dovresti cimentarti con\n"
	.string "questo livello.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Nel LIVELLO LIBERO puoi iscrivere\n"
	.string "POKéMON di qualsiasi livello.\p"
	.string "I livelli dei POKéMON dei tuoi rivali\n"
	.string "si adattano a quelli dei tuoi POKéMON.\p"
	.string "Tuttavia, nessun ALLENATORE\n"
	.string "avversario manderà in campo\l"
	.string "POKéMON di livello inferiore a 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Quasi tutti i POKéMON possono\n"
	.string "partecipare alle sfide offerte dai\l"
	.string "diversi edifici.\p"
	.string "Tuttavia, non puoi iscrivere le UOVA e\n"
	.string "alcune specie di POKéMON.\p"
	.string "Il numero di POKéMON richiesto varia\n"
	.string "a seconda dell’edificio.\p"
	.string "Inoltre, in tutti gli edifici non puoi\n"
	.string "far lottare due o più POKéMON uguali.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "I POKéMON che partecipano alle sfide\n"
	.string "del PARCO LOTTA non possono tenere\l"
	.string "gli stessi strumenti.\p"
	.string "Assicurati che tutti i POKéMON che\n"
	.string "mandi in campo tengano strumenti\l"
	.string "diversi.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Se vuoi, ti illustro come funziona\n"
	.string "il PASS PARCO.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Quale argomento ti interessa?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Nel PARCO LOTTA ci sono\n"
	.string "sette edifici.\p"
	.string "Ogni edificio conferisce un SIMBOLO\n"
	.string "agli ALLENATORI che si distinguono\l"
	.string "per le loro capacità.\p"
	.string "Per aggiudicarsi un SIMBOLO,\n"
	.string "gli ALLENATORI devono sconfiggere\l"
	.string "una serie di ALLENATORI avversari e\l"
	.string "vincere negli eventi ripetutamente.\p"
	.string "I SIMBOLI non sono per nulla facili da\n"
	.string "conquistare. Ti auguro tanta fortuna!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "È possibile far registrare un filmato di\n"
	.string "una lotta nel tuo PASS PARCO.\p"
	.string "Puoi far registrare il filmato di\n"
	.string "una lotta contro uno o più amici.\p"
	.string "Oppure di una qualsiasi lotta che hai\n"
	.string "disputato nel PARCO LOTTA, escluse\l"
	.string "le lotte che si tengono nella SERPE\l"
	.string "LOTTA o nella PIRAMIDE LOTTA.\p"
	.string "Alla fine della lotta ti verrà chiesto se\n"
	.string "vuoi che il filmato venga registrato.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "I PUNTI LOTTA vengono dati in premio\n"
	.string "agli ALLENATORI che si sono distinti\l"
	.string "nel PARCO LOTTA.\p"
	.string "Nell’UFFICIO RITIRO PREMI potrai\n"
	.string "ritirare un premio in cambio dei tuoi\l"
	.string "PUNTI LOTTA.$"

