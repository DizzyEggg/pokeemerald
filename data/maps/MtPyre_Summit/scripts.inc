.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "No! Quei teppistelli del TEAM MAGMA\n"
	.string "sono arrivati qui prima di noi!\p"
	.string "Non possiamo restare indietro!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Pensavo che fossi del TEAM MAGMA\n"
	.string "e che avessi fatto ritorno qui…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ok, sarai anche forte…\n"
	.string "ma noi siamo in tanti!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Ah!\n"
	.string "Peggio per te!\p"
	.string "Arrivando prima, avresti dovuto lottare\n"
	.string "contro quegli smidollati del TEAM MAGMA.\p"
	.string "Invece adesso devi vedertela con dei\n"
	.string "tipi duri come noi!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Avrei dovuto lasciarti sfidare il\n"
	.string "TEAM MAGMA prima…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Tu non sai niente, quindi evita di\n"
	.string "ficcare il naso nei nostri affari!$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Ehi, ti ricordi… ci siamo visti sul\n"
	.string "MONTE CAMINO.\p"
	.string "Non fai parte di nessuno dei due\n"
	.string "TEAM. Che ci fai qui?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Se devi proprio intrometterti,\n"
	.string "fallo col TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Eh, non importa!\n"
	.string "Abbiamo guadagnato del tempo!\p"
	.string "Il CAPO dovrebbe essere riuscito ad\n"
	.string "impossessarsi di quello che cercava!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Ah, lo so!\n"
	.string "Hai provato ad entrare nel TEAM MAGMA,\l"
	.string "ma non ti hanno accettato!\p"
	.string "Neppure noi ti faremo entrare nel\n"
	.string "TEAM IDRO!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Se sei così impaziente di unirti al TEAM\n"
	.string "IDRO, potremmo ripensarci…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Che squadra favolosa formiamo noi\n"
	.string "membri insieme al nostro CAPO!$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "IVAN: MAX del TEAM MAGMA ci ha\n"
	.string "preceduto, ma anche noi abbiamo\l"
	.string "ottenuto ciò che volevamo.\p"
	.string "La SFERA ROSSA custodita presso\n"
	.string "il MONTE PIRA è ora nelle mie mani!\p"
	.string "Ahah… ora possiamo realizzare\n"
	.string "il nostro obiettivo!\p"
	.string "Ok, TEAM!\n"
	.string "Diamoci da fare!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, no…\n"
	.string "Non può essere vero…\p"
	.string "Non hanno rubato solo la SFERA BLU,\n"
	.string "ma anche la SFERA ROSSA…\p"
	.string "Per nessun motivo, la SFERA BLU e\n"
	.string "la SFERA ROSSA si devono separare.\p"
	.string "Che cosa vorranno fare con le due\n"
	.string "SFERE?\p"
	.string "… … … … … … … …\p"
	.string "Ah, sì. È stato il TEAM MAGMA a\n"
	.string "prendere la SFERA BLU?\p"
	.string "Nella fretta, si sono dimenticati\n"
	.string "questo.\p"
	.string "Non so proprio cosa sia.\p"
	.string "Prendilo tu.\n"
	.string "Forse ti sarà utile un giorno.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "La SFERA BLU e la SFERA ROSSA rubate\n"
	.string "da quegli uomini cattivi…\p"
	.string "non devono essere divise.\n"
	.string "Se no accadrà qualcosa di terribile…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh, mamma mia…\p"
	.string "Dici che GROUDON e KYOGRE\n"
	.string "si sono risvegliati?\p"
	.string "Si narra che la SFERA BLU e la SFERA\n"
	.string "ROSSA abbiano calmato la rabbia\l"
	.string "dei due POKéMON…\p"
	.string "Si narra inoltre che il vero padrone\n"
	.string "delle due SFERE esista ancora.\p"
	.string "Tuttavia nessuno sa esattamente a chi\n"
	.string "o a che cosa le due SFERE appartengano.\p"
	.string "Potrebbe trattarsi di un essere umano o\n"
	.string "addirittura di un POKéMON, chissà…$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "I due uomini che hanno rubato le SFERE\n"
	.string "le hanno riportate spontaneamente.\p"
	.string "Forse non sono poi così cattivi…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "L’incarnazione della terra, del mare \n"
	.string "e del cielo…\p"
	.string "Si dice che i POKéMON antichissimi\n"
	.string "siano questo…\p"
	.string "Come noi e i POKéMON siamo esseri\n"
	.string "viventi, anche il mondo è vivo…\p"
	.string "Questa è la lezione che abbiamo\n"
	.string "imparato dai POKéMON antichissimi…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "Il MONTE PIRA è dove calmiamo gli spiriti\n"
	.string "dei POKéMON scomparsi…\p"
	.string "È una vetta da dove si può contemplare\n"
	.string "tutta la regione di HOENN…\p"
	.string "Gli spiriti liberi dei POKéMON\n"
	.string "qui trovano conforto…\p"
	.string "Che coincidenza che tu sia qui…\p"
	.string "Vuoi ascoltare una storia che si narra\n"
	.string "da tanto tempo nella regione di HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "È accaduto molto, molto tempo fa…\p"
	.string "Il mondo fu scosso da un terribile\n"
	.string "scontro tra il POKéMON della terra\l"
	.string "ed il POKéMON del mare…\p"
	.string "Il POKéMON della terra forgiò\n"
	.string "montagne e creò continenti…\p"
	.string "Il POKéMON del mare generò enormi\n"
	.string "onde e ricavò oceani…\p"
	.string "Il fiero duello imperversava senza fine.\p"
	.string "Furiose tempeste ed enormi catastrofi\n"
	.string "si abbatterono sul mondo.\p"
	.string "La SFERA BLU e la SFERA ROSSA posero\n"
	.string "fine a tale calamità.\p"
	.string "Le due SFERE emanarono una luce\n"
	.string "che placò la furia dei contendenti.\p"
	.string "I due POKéMON, resi mansueti,\n"
	.string "si rifugiarono nelle profondità marine\l"
	.string "dove un giorno scomparvero…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Oh, capisco… beh, non c’è problema…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAX: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Il mio compito è tramandare le leggende\n"
	.string "della regione di HOENN alle generazioni\l"
	.string "future.\p"
	.string "La crisi appena terminata a CENERIDE\n"
	.string "è entrata nella leggenda…\p"
	.string "Ti piacerebbe sentire la nuova leggenda\n"
	.string "della regione di HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "È accaduto molto, molto tempo fa…\p"
	.string "Il mondo fu scosso da un terribile\n"
	.string "scontro tra il POKéMON della terra\l"
	.string "ed il POKéMON del mare…\p"
	.string "Il POKéMON della terra forgiò\n"
	.string "montagne e creò continenti…\p"
	.string "Il POKéMON del mare generò enormi\n"
	.string "onde e ricavò oceani…\p"
	.string "Il fiero duello imperversava senza fine.\p"
	.string "Furiose tempeste ed enormi fiammate\n"
	.string "si abbatterono sul mondo.\p"
	.string "Fu così che il POKéMON del cielo\n"
	.string "discese sulle ali di una tempesta.\p"
	.string "Il POKéMON, che emanava una luce verde\n"
	.string "vivida, calmò i due POKéMON infuriati.\p"
	.string "Fatto il suo dovere, il POKéMON verde\n"
	.string "fece ritorno nel cielo blu…$"

