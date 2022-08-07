BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_D is the move selection
@ VAR_TEMP_E is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_E, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahahah!\p"
	.string "Dal mio aspetto non si direbbe, ma\n"
	.string "in passato ero un bravo ALLENATORE.\p"
	.string "Tutti mi conoscevano come la\n"
	.string "BELLEZZA più forte in circolazione!\p"
	.string "… … … … … …\p"
	.string "Cosa c’è?\n"
	.string "Non mi credi?\p"
	.string "Non sono come quella spaccona\n"
	.string "laggiù. Io ho del talento!\p"
	.string "Adesso te ne darò prova.\n"
	.string "Posso insegnare ai POKéMON mosse\l"
	.string "speciali ma, al contempo, carine.\p"
	.string "Non insegno gratuitamente.\n"
	.string "Che ne dici di ripagarmi con qualche\l"
	.string "PUNTO LOTTA?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahahah!\p"
	.string "Sei qui perché vuoi che insegni\n"
	.string "una mossa speciale, ma carina,\l"
	.string "a uno dei tuoi POKéMON?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Bene, guarda qui!\n"
	.string "Quale mossa vuoi che insegni?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "Vuoi la mossa {STR_VAR_1}?\n"
	.string "Ti costerà {STR_VAR_2} PUNTI LOTTA, va bene?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Bene, bene. Scegli il POKéMON\n"
	.string "al quale devo insegnare la mossa.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Caspita!\n"
	.string "Non hai PUNTI LOTTA sufficienti!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Hai visto che ho talento da vendere?\n"
	.string "Mi prenderò i tuoi PUNTI LOTTA, grazie!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Qualcosa non va?\n"
	.string "Hai cambiato idea?\p"
	.string "Se vuoi toccare con mano il mio\n"
	.string "talento, torna pure quando vuoi!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihih!\p"
	.string "Lo so che non si direbbe, ma un tempo\n"
	.string "ero un ALLENATORE fantastico.\p"
	.string "Tutti mi conoscevano come la miglior\n"
	.string "NUOTATRICE in circolazione!\p"
	.string "… … … … … …\p"
	.string "Qualcosa non va?\n"
	.string "Non mi credi?\p"
	.string "Non sono mica come quella buffona\n"
	.string "laggiù. Ho molta esperienza alle spalle!\p"
	.string "Se vuoi te lo dimostro.\n"
	.string "Posso insegnare ai POKéMON mosse\l"
	.string "difficili ma, al contempo, carine.\p"
	.string "Non insegno gratuitamente.\n"
	.string "Che ne dici di ripagarmi con qualche\l"
	.string "PUNTO LOTTA?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihih!\p"
	.string "Sei qui perché vuoi che insegni\n"
	.string "una mossa difficile, ma carina,\l"
	.string "a uno dei tuoi POKéMON?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Quelle signore sparlano l’una\n"
	.string "dell’altra. Si direbbe che non\l"
	.string "vadano affatto d’accordo.\p"
	.string "Ma se fosse così, non andrebbero\n"
	.string "in giro insieme, non trovi?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Quando ero un giovane BULLO, quelle\n"
	.string "signore erano forti e belle.\p"
	.string "Erano gli idoli di noi ALLENATORI.\p"
	.string "Ma l’età non ha offuscato le loro\n"
	.string "abilità.\p"
	.string "Di fatto le loro mosse POKéMON \n"
	.string "sono diventate ancora più raffinate.\p"
	.string "Ma non so per quale motivo, non posso\n"
	.string "fare a meno di pensare…\p"
	.string "che il tempo è così crudele…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Chi la usa recu-\n"
	.string "pera fino a metà\n"
	.string "dei PS massimi.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Infligge un danno\n"
	.string "pari al livello di\n"
	.string "chi la usa.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Assorbe metà dei\n"
	.string "PS persi da un ne-\n"
	.string "mico che dorme.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Un pugno tirato\n"
	.string "con estrema\n"
	.string "potenza.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Un calcio\n"
	.string "estremamente\n"
	.string "potente.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Una carica con\n"
	.string "tutto il corpo che\n"
	.string "può paralizzare.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Massi lanciati\n"
	.string "sul nemico, che\n"
	.string "può tentennare.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Replica agli\n"
	.string "attacchi fisici\n"
	.string "con forza doppia.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Debole scarica\n"
	.string "elettrica che pa-\n"
	.string "ralizza il nemico.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Una danza che\n"
	.string "potenzia forte-\n"
	.string "mente l’ATTACCO.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Raggomitolandosi,\n"
	.string "chi la usa aumenta\n"
	.string "la propria DIFESA.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Attacco rumoroso\n"
	.string "usato solo mentre\n"
	.string "si dorme.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Fango in faccia al\n"
	.string "nemico, per ridur-\n"
	.string "ne la precisione.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Raggi a forma\n"
	.string "di stella:\n"
	.string "infallibili.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Attacco gelido:\n"
	.string "riduce la VELOCI-\n"
	.string "TÀ del nemico.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Per un turno, chi\n"
	.string "la usa resiste con\n"
	.string "almeno 1 PS.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copia le modifiche\n"
	.string "nelle statistiche\n"
	.string "del nemico.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Pugno di ghiaccio\n"
	.string "che può congelare\n"
	.string "il nemico.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Pugno elettrico\n"
	.string "che può paraliz-\n"
	.string "zare il nemico.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Pugno ardente\n"
	.string "che può scottare\n"
	.string "il nemico.$"
