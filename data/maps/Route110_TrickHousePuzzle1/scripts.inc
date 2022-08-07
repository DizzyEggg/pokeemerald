Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} scrive il codice segreto\n"
	.string "sulla porta.\p"
	.string "“Il MAGO del QUIZ è un mito”.\n"
	.string "… … … … … … … …\p"
	.string "La porta si apre!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Mi farò strada verso la vittoria\n"
	.string "con un colpo di TAGLIO!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Perché non sorridi un po’?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Non mi stanco mai di tagliare\n"
	.string "e tranciare!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Sono finito in questo strano posto\n"
	.string "per puro caso…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "E ora ho pure perso…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Ho perso la lotta, mi sono perso e ora\n"
	.string "sono proprio perso! Come si esce da qui?$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Ma chi è questo MAGO del QUIZ?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Ho perso perché ero persa\n"
	.string "nei miei pensieri!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Tu sì che sei forte!\n"
	.string "Ma chi sei?$"

