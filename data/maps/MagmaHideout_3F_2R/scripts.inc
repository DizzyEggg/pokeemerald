MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Ho comprensione per tutto ciò che il\n"
	.string "nostro CAPO dice. Ma sai cosa?\p"
	.string "Scavare per trovare un POKéMON\n"
	.string "antichissimo e rubare a qualcuno il\l"
	.string "suo METEORITE…\p"
	.string "Non pensi che stiamo esagerando\n"
	.string "un po’?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Sì, mi sembra che stiamo facendo\n"
	.string "qualcosa di sbagliato.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Perdere contro di te mi ha fatto capire\n"
	.string "molte cose.\p"
	.string "Quando vedo il nostro CAPO mi faccio\n"
	.string "spiegare cosa stiamo facendo.$"

