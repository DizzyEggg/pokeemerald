.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Ehm… se questa cosa va qui e quella\n"
	.string "va là…\p"
	.string "Dove va allora questo?\n"
	.string "E quell’aggeggio lì?\p"
	.string "Aaargh! Non ne vengo a capo!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Uhm?\n"
	.string "Ciao, sono TIMON.\p"
	.string "Il CAP. REMO mi ha dato l’incarico\n"
	.string "di progettare un traghetto.\p"
	.string "Oh! Che cos’è…?\n"
	.string "È la MERCE DEVON?\p"
	.string "Uhmm…\n"
	.string "fammi pensare…\p"
	.string "Il CAP. REMO è partito per chissà dove.\n"
	.string "Aveva delle faccende da sbrigare.\p"
	.string "Ti va di cercare il CAP. REMO e di\n"
	.string "consegnargli direttamente la merce?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "TIMON: Dove sarà andato il CAP. REMO?\p"
	.string "Puoi cercare il CAP. REMO e consegnargli\n"
	.string "quel pacchetto?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "TIMON: Costruire navi è un’arte.\p"
	.string "Molti fattori non si possono prevedere\n"
	.string "con semplici calcoli matematici.\p"
	.string "Potrei chiedere consiglio a\n"
	.string "un vecchio lupo di mare…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "TIMON: Ciao! Il SIG. MARINO è venuto a\n"
	.string "darci una mano.\p"
	.string "Grazie al suo aiuto, il traghetto\n"
	.string "sta venendo molto bene.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "TIMON: Il traghetto è pronto!\p"
	.string "La nuova M/N MAREA è davvero una\n"
	.string "meraviglia della tecnologia!\p"
	.string "Ma credo che possiamo fare qualcosa\n"
	.string "di più grandioso.\p"
	.string "Sai, non si può porre un freno alla\n"
	.string "tecnologia.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "SIG. MARINO: Ah, {PLAYER}{KUN}!\n"
	.string "Da quanto tempo!\p"
	.string "Ehi, da quando ci siamo visti, questo \n"
	.string "vecchio lupo di mare si è dato da fare!\p"
	.string "Ho deciso di dare una mano a TIMON\n"
	.string "per costruire un traghetto.\p"
	.string "Un traghetto può essere davvero utile\n"
	.string "e trasportare un sacco di persone.\p"
	.string "E poi tu conosci TIMON… è un tipo\n"
	.string "davvero speciale!\p"
	.string "Con il suo estro e la mia esperienza,\n"
	.string "sono sicuro che possiamo costruire\l"
	.string "un traghetto memorabile! Hip hip, urrà!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Le stagioni, il tempo, la posizione\n"
	.string "della luna nel cielo…\p"
	.string "È l’insieme di questi fattori a far\n"
	.string "cambiare aspetto al mare.\p"
	.string "È proprio vero!\n"
	.string "Il mare è dotato di vita propria!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Soffrendo di mal di mare, preferisco\n"
	.string "dare una mano qui sulla terraferma.$"

