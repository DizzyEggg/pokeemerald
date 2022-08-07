.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Sono PIERANGELO PETRI, PRESIDENTE\n"
	.string "della DEVON SpA.\p"
	.string "Ho sentito parlare di te!\p"
	.string "Ci hai salvato ben due volte!\p"
	.string "Ho un favore da chiedere ad una\n"
	.string "persona meravigliosa come te.\p"
	.string "So che hai un pacchetto da consegnare\n"
	.string "al CANTIERE di SELCEPOLI.\p"
	.string "Bene, sulla strada ti potresti fermare a\n"
	.string "BLURUVIA?\p"
	.string "Vorrei che tu consegnassi una LETTERA\n"
	.string "a ROCCO.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "SIG. PETRI: Dovresti sapere che sono\n"
	.string "un PRESIDENTE molto magnanimo.\p"
	.string "Non potrei mai chiederti un favore\n"
	.string "senza offrirti qualcosa in cambio.\p"
	.string "Per cui ti prego di accettare questo.$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} riceve un POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "SIG. PETRI: Questo dispositivo…\p"
	.string "è un NAVIGATORE POKéMON, detto anche\n"
	.string "POKéNAV.\p"
	.string "È indispensabile per gli ALLENATORI\n"
	.string "che vogliono partire all’avventura.\p"
	.string "Ha una mappa della regione di HOENN.\p"
	.string "Troverai facilmente la strada per\n"
	.string "BLURUVIA e SELCEPOLI!\p"
	.string "A proposito, ho sentito dire che dei\n"
	.string "teppistelli, credo il TEAM MAGMA e\l"
	.string "il TEAM IDRO, stanno portando\l"
	.string "scompiglio in lungo e in largo.\p"
	.string "Penso che sia meglio che ti riposi un po’\n"
	.string "prima di metterti in viaggio.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "SIG. PETRI: Va bene, {PLAYER}{KUN},\n"
	.string "sii prudente allora!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "SIG. PETRI: Conto su di te!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "SIG. PETRI: Hai consegnato la mia\n"
	.string "LETTERA? Ti ringrazio profondamente!\p"
	.string "Vorrei che tu accettassi questo dono\n"
	.string "molto utile per un ALLENATORE.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "SIG. PETRI: Un POKéMON che tiene\n"
	.string "CONDIV. ESP. riceverà alcuni punti\l"
	.string "ESP. dalla lotta.\p"
	.string "Riceverà punti ESP. anche se non ha\n"
	.string "partecipato alla lotta.\p"
	.string "Credo che CONDIV. ESP. sia molto utile\n"
	.string "per allevare POKéMON deboli.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "SIG. PETRI: Ho iniziato a lavorare\n"
	.string "quando ero ancora molto giovane.\p"
	.string "Pertanto non sono molto al passo\n"
	.string "con i tempi.\p"
	.string "I giovani d’oggi vogliono tutti essere\n"
	.string "ALLENATORI nella LEGA POKéMON?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Ti trovi al secondo piano della\n"
	.string "DEVON SpA.\p"
	.string "L’UFFICIO del nostro PRESIDENTE\n"
	.string "è su questo piano.\p"
	.string "Non trovo le parole per esprimere\n"
	.string "la mia gratitudine…\p"
	.string "Uhm… quel pacchetto che ci hai\n"
	.string "riportato…\p"
	.string "Ti posso chiedere di consegnarlo\n"
	.string "al CANTIERE di SELCEPOLI?\p"
	.string "Sarebbe terribile se ci venisse rubato\n"
	.string "un’altra volta.\p"
	.string "Uhm… eheheh, quindi, uhm, posso\n"
	.string "contare su di te?\p"
	.string "Oh, giusto!\n"
	.string "Puoi aspettare un attimino?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Il nostro PRESIDENTE ti vorrebbe\n"
	.string "parlare.\p"
	.string "Ti prego di seguirmi.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Prego, accomodati.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Se visiti il CANTIERE di SELCEPOLI,\n"
	.string "dovresti andare a trovare il CAP. REMO.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "I nuovi prodotti della DEVON, la BIS\n"
	.string "BALL e la TIMER BALL, stanno avendo\l"
	.string "un grande successo tra gli ALLENATORI.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Una collezione di rocce e pietre rare\n"
	.string "del PRESIDENTE.$"

