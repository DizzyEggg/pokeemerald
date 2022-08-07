Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Scusa per tutto questo disordine, ma \n"
	.string "quando sono concentrata sulle\l"
	.string "mie ricerche, finisce sempre così!\p"
	.string "Che imbarazzo… ti prego di non dirlo\n"
	.string "in giro, in cambio prendi questo!$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Posso darti qualche consiglio sul\n"
	.string "mio Sistema Memoria POKéMON?\p"
	.string "Dovresti organizzare i BOX in modo da\n"
	.string "capire che POKéMON contengano.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Gli appunti di LANETTE!\n"
	.string "Contengono informazioni sui BOX.\p"
	.string "BOX da 30 POKéMON ciascuno.\p"
	.string "Ogni ALLENATORE deve poter depositare\n"
	.string "420 POKéMON nel PC.\p"
	.string "Vuoi continuare a leggere?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Per organizzare meglio i POKéMON\n"
	.string "serve un sistema per contrassegnarli.\p"
	.string "Il nome e lo sfondo di ogni BOX\n"
	.string "possono essere modificati per\l"
	.string "rallegrare i POKéMON presenti.\p"
	.string "Vuoi continuare a leggere?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Quando un POKéMON viene inviato al mio\n"
	.string "PC, viene riposto nell’ultimo BOX aperto.\p"
	.string "Se il BOX è pieno, il POKéMON ricevuto\n"
	.string "viene collocato nel BOX successivo.\p"
	.string "In altre parole, l’ultimo BOX aperto\n"
	.string "viene automaticamente selezionato\l"
	.string "per collocare i nuovi POKéMON.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} chiude il quaderno.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Qualcuno ha mandato un’e-mail al PC.\p"
	.string "“… … … … … … …\p"
	.string "Il tuo Sistema Memoria offre maggiori\n"
	.string "vantaggi del mio.\p"
	.string "Molte caratteristiche ne agevolano\n"
	.string "l’uso e lo rendono utile e divertente.\p"
	.string "Sono felice di aver contribuito\n"
	.string "alla sua progettazione.\p"
	.string "Spero che continuerai la ricerca\n"
	.string "sui Sistemi Memoria.\p"
	.string "Saluti, BILL\n"
	.string "… … … … … … … …”.$"

