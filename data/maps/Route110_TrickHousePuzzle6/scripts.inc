Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} scrive il codice segreto\n"
	.string "sulla porta.\p"
	.string "“Il MAGO del QUIZ è la mia vita”.\n"
	.string "… … … … … … … …\p"
	.string "La porta si apre!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Quando ho saputo di questo strano\n"
	.string "posto, ho voluto vederlo.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Ho scoperto un ALLENATORE in gamba!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Sicuramente ci si diverte a scoprire\n"
	.string "questo posto.\p"
	.string "È una sfida che trovo utile ripetere!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Forse i miei POKéMON UCCELLO\n"
	.string "riescono a volare oltre il muro…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Ahaaaaa! Ho perso!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Eheheh… sicuramente ho perso\n"
	.string "perché tentavo di imbrogliare.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Mi gira la testa con tutte\n"
	.string "queste porte girevoli…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Gira tutto come una trottola.\n"
	.string "Non ne posso davvero più…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Non mi pare che la cosa ti interessi.\n"
	.string "O fai solo buon viso a cattivo gioco?$"

