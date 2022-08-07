Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} scrive il codice segreto\n"
	.string "sulla porta.\p"
	.string "“Il MAGO del QUIZ è grande”.\n"
	.string "… … … … … … … …\p"
	.string "La porta si apre!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Troppa fatica risolvere questo\n"
	.string "rompicapo. Voglio solo lottare!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Anche se ho perso, mi piace lottare\n"
	.string "al meglio!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Andrei ovunque pur di incontrare degli\n"
	.string "ALLENATORI, tu no?$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Ehi! Massi come questi riesco\n"
	.string "a spostarli con un dito io!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Certo, so spostare i massi ma non\n"
	.string "riesco a risolvere questo rompicapo…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Non basta essere forti… bisogna\n"
	.string "essere anche furbi! Usa il cervello!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "La QUIZZOTECA si fa sempre più\n"
	.string "interessante, no?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Nooooo!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Ma c’è mai arrivato nessuno alla fine?$"

