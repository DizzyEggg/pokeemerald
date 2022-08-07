Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Sono il proprietario della CASA sul MARE.\n"
	.string "Ma tutti mi chiamano SIG. SALSEDINE!\p"
	.string "La cosa che amo di più è assistere\n"
	.string "ad ardenti lotte di POKéMON.\p"
	.string "Fammi vedere quanto arde il tuo cuore!\p"
	.string "Se qui batterai tutti gli ALLENATORI,\n"
	.string "premierò i tuoi sforzi.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Fammi vedere qualche lotta ardente!\p"
	.string "Gestisco questa CASA sul MARE\n"
	.string "solo per questo motivo!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Fa così caldo che quasi si brucia!\n"
	.string "Le tue lotte fanno scintille!\l"
	.string "Non potrei essere più soddisfatto!\p"
	.string "Come ringraziamento per il tuo ardore,\n"
	.string "eccoti un regalo.\p"
	.string "Sono sei bottiglie di GASSOSA!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, aspetta, il tuo ZAINO è pieno zeppo!\n"
	.string "Le conserverò per te.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Vuoi comprare la GASSOSA?\n"
	.string "I POKéMON l’adorano!\p"
	.string "Solo ¥300 la bottiglia!\n"
	.string "Comprane qualcuna!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Ecco a te!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Non hai abbastanza soldi.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "No?\n"
	.string "Peggio per te.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Se ti va di lottare nella CASA sul MARE,\n"
	.string "non troverai ALLENATORE più in gamba\l"
	.string "di me. Non ci sono dubbi!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Che lotta infiammata!\n"
	.string "Accetto questa sconfitta!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Di SELCEPOLI, amo le lotte infiammate e\n"
	.string "la GASSOSA ghiacciata!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Perché impegnarsi in lotte monotone?\p"
	.string "Sono le lotte accese e infiammate che\n"
	.string "rafforzano ALLENATORI e POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Che calore!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Beh, mi è venuta una gran sete.\n"
	.string "Prenderò una GASSOSA.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Ti farò assaggiare la forza dei\n"
	.string "miei POKéMON, ma tu non piangere!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "Ho perso, ma non piangerò…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Se uno dei miei POKéMON conoscesse\n"
	.string "la mossa per trasportarmi in acqua sul\l"
	.string "dorso, mi libererei di questa ciambella.$"

