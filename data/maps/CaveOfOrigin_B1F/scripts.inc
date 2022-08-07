.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, allora tu sei {PLAYER}{KUN}.\n"
	.string "Ho sentito parlare delle tue imprese.\p"
	.string "Mi chiamo ADRIANO.\p"
	.string "Prima ero il CAPOPALESTRA di CENERIDE,\n"
	.string "ma poi è successo qualcosa.\p"
	.string "Così ho lasciato la PALESTRA nelle\n"
	.string "mani del mio maestro RODOLFO.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON e KYOGRE, i due POKéMON che\n"
	.string "stanno portando lo scompiglio qui,\l"
	.string "sono POKéMON antichissimi.\p"
	.string "Ma non ci sono soltanto due POKéMON\n"
	.string "antichissimi.\p"
	.string "Ce n’è un altro da qualche parte.\p"
	.string "In un luogo sconosciuto c’è un POKéMON\n"
	.string "antichissimo chiamato RAYQUAZA.\p"
	.string "Si narra che sia stato RAYQUAZA a\n"
	.string "calmare i due combattenti in passato.\p"
	.string "Ma non ho idea di dove si\n"
	.string "nasconda…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "ADRIANO: {PLAYER}{KUN}, sai dove si trova\n"
	.string "RAYQUAZA?\p"
	.string "Se lo sai, dimmelo per favore.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "ADRIANO: La GROTTA dei TEMPI?\p"
	.string "È qui!\n"
	.string "Mi aspetto ben altro da te!\p"
	.string "Per favore, pensa a dove potrebbe\n"
	.string "essere RAYQUAZA ora.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "ADRIANO: Il MONTE PIRA?\p"
	.string "Quando ho incontrato la vecchia\n"
	.string "signora lì, non ha detto nulla.\p"
	.string "Dubito cha abbia voluto nascondermi\n"
	.string "qualcosa.\p"
	.string "{PLAYER}{KUN}, potresti pensarci\n"
	.string "meglio?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "ADRIANO: Cosa? Non ti ricordi?\n"
	.string "Mmm… che problema…$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "ADRIANO: La TORRE dei CIELI?\p"
	.string "Sì!\n"
	.string "Deve essere la TORRE dei CIELI!\p"
	.string "{PLAYER}{KUN}, non c’è tempo da perdere!\n"
	.string "Dirigiamoci verso la TORRE dei CIELI!$"

