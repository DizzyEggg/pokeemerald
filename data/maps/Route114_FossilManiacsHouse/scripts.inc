Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM28, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM28
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM28
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Il mio fratellone è l’ESPERTO FOSSILI!\n"
	.string "È un tipo simpatico che ama i FOSSILI…\p"
	.string "Gli piace da matti scavare.\n"
	.string "Questo buco l’ha fatto lui…\p"
	.string "Prendi questo, così potrai scavare\n"
	.string "una FOSSA come lui…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Se usi FOSSA mentre sei in una grotta,\n"
	.string "tornerai all’entrata…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "La teca contiene pietre dalla\n"
	.string "forma stravagante.$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LA COMPOSIZIONE DEGLI STRATI…\n"
	.string "COME LA PIOGGIA MODELLA IL TERRENO…\l"
	.string "PIETRE, SUOLO E ROCCIA…\p"
	.string "È tutto pieno zeppo di libri.$"

