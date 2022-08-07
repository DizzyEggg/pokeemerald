MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Che ho fatto per meritarmi questo\n"
	.string "posto di guardia?\p"
	.string "Il mio orecchio sinistro sta bruciando!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Non ne posso più di questo calore…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Non ti sembra strano che portiamo un\n"
	.string "cappuccio in un vulcano pieno di magma?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Noi vogliamo aiutare il nostro CAPO\n"
	.string "a realizzare la sua fantastica idea.\p"
	.string "Non fa differenza se sei del TEAM IDRO\n"
	.string "o se stai solo passando di qua.\p"
	.string "Chi interferisce con noi non la\n"
	.string "passa liscia!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh, no!\n"
	.string "Non ci si può fidare di te!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Ascoltami.\n"
	.string "Il TEAM MAGMA ha ragione!\p"
	.string "Non ascoltare quelli del TEAM IDRO.\n"
	.string "Non credere alle loro fandonie!$"

