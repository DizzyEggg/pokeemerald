.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MAMMA: {PLAYER}, guarda!\n"
	.string "Cosa ne dici, non è bello qua?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "I POKéMON traslocatori si stanno\n"
	.string "occupando del trasloco e delle\l"
	.string "pulizie finali. Che comodità!\p"
	.string "{PLAYER}, la tua stanza è di sopra.\n"
	.string "Vai a vederla, tesoro!\p"
	.string "PAPÀ ti ha comprato un orologio\n"
	.string "per la tua nuova camera.\l"
	.string "Non dimenticare di regolarlo!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MAMMA: Allora, {PLAYER}?\p"
	.string "Non ti interessa vedere\n"
	.string "la tua nuova camera?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MAMMA: {PLAYER}…\p"
	.string "Va’ a regolare l’orologio, tesoro!$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MAMMA: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Vieni qua! Fai presto!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MAMMA: Guarda! È la PALESTRA di\n"
	.string "PETALIPOLI. Forse vediamo PAPÀ!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MAMMA: Oh… già finito…\p"
	.string "PAPÀ c’era di sicuro, ma ce lo\n"
	.string "siamo perso. Che peccato!$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Ah, dimenticavo… uno degli amici di PAPÀ\n"
	.string "vive in città.\p"
	.string "È il PROF. BIRCH.\p"
	.string "Abita proprio qui a fianco…\n"
	.string "Vai a fargli visita!$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MAMMA: Ciao, tesoro!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MAMMA: Allora, hai conosciuto\n"
	.string "il PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MAMMA: Come va, {PLAYER}?\n"
	.string "La stanchezza si fa sentire, eh?\p"
	.string "Dovresti riposare un po’!$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MAMMA: Mi raccomando, sii prudente!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MAMMA: Oh? PAPÀ ti ha già dato\n"
	.string "quella MEDAGLIA?\p"
	.string "Allora tieni! Questo te lo dà \n"
	.string "la tua MAMMA!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Cerca di non stancarti troppo, tesoro.\n"
	.string "Casomai puoi sempre tornare a casa!\p"
	.string "Fatti coraggio!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MAMMA: Che cos’è? Un POKéNAV?\n"
	.string "Te l’ha dato qualcuno della DEVON?\p"
	.string "Perché non registri la tua mamma?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Registrazione della MAMMA\n"
	.string "nel POKéNAV avvenuta.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Viiigoooroooth!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Viii, gooo, roooth…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "REPORTER: Oggi vi abbiamo proposto\n"
	.string "questo servizio direttamente dalla\l"
	.string "PALESTRA di PETALIPOLI.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "C’è un film in TV…\p"
	.string "Due uomini ballano sui tasti di\n"
	.string "un enorme pianoforte.\p"
	.string "Meglio andare!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "È il manuale di istruzioni delle\n"
	.string "SCARPE da CORSA.\p"
	.string "“Per correre premi il pulsante B,\n"
	.string "quando indossi le SCARPE da CORSA.\p"
	.string "Mettiti le SCARPE da CORSA e vai veloce\n"
	.string "come il vento!”.$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "PAPÀ: Eh?\p"
	.string "Ehi, ma allora sei proprio tu, {PLAYER}!\p"
	.string "Finalmente… da quanto tempo!!!\n"
	.string "Ti vedo più grande e più forte!\p"
	.string "Almeno così mi pare… ma anche\n"
	.string "tuo padre è ancora in gran forma!\p"
	.string "Ah, dimenticavo! Ho qualcosa per te.\n"
	.string "Questo è da parte di un certo…\l"
	.string "SIG. MARINO…$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAPÀ: Mhmm, un BIGLIETTO per\n"
	.string "salire su un traghetto?\p"
	.string "Se ricordo bene, ci sono due porti:\n"
	.string "uno a SELCEPOLI e l’altro ad ALGHEPOLI.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Farò meglio a tornare alla PALESTRA di\n"
	.string "PETALIPOLI.\p"
	.string "Cara, ti ringrazio perché ti prendi cura\n"
	.string "della casa quando non ci sono.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MAMMA: Tuo PAPÀ…\p"
	.string "tratta questa casa come se fosse\n"
	.string "un albergo e sa solo parlare di POKéMON!\p"
	.string "Dovrebbe riposarsi un po’ e fermarsi\n"
	.string "più a lungo.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MAMMA: È una notizia dell’ultima ora?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Notizia dell’ultima ora!\p"
	.string "Alcuni cittadini della regione di\n"
	.string "HOENN hanno avvistato un\l"
	.string "POKéMON che volava dal\l"
	.string "colore… BZZT…\p"
	.string "L’identità di questo POKéMON\n"
	.string "è ancora sconosciuta.\p"
	.string "Torniamo ora alla nostra\n"
	.string "normale programmazione.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MAMMA: {PLAYER}, hai sentito?\p"
	.string "Di quale colore hanno detto che\n"
	.string "era il POKéMON?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MAMMA: È una notizia interessante!\n"
	.string "Esistono ancora POKéMON sconosciuti.$"
