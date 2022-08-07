Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_WroteSecretCodeLockOpened::
	.string "{PLAYER} scrive il codice segreto\n"
	.string "sulla porta.\p"
	.string "“Il MAGO del QUIZ è un amore”.\n"
	.string "… … … … … … … …\p"
	.string "La porta si apre!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Non sono molti gli ALLENATORI\n"
	.string "che sono arrivati fin qui.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Devi essere proprio forte, dunque…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Hai battuto il CAMPIONE della LEGA\n"
	.string "POKéMON? Davvero un bel colpo!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Considerala una fortuna lottare\n"
	.string "contro di me!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Non è giusto!\n"
	.string "Non posso perdere!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Mi hai battuto per miracolo. \n"
	.string "Non fartene un vanto!$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Arranchi anche tu nella\n"
	.string "QUIZZOTECA, eh?$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Capisco.\n"
	.string "Hai una tecnica straordinaria!$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Il MAGO del QUIZ non potrà che\n"
	.string "essere felice di conoscerti.$"

