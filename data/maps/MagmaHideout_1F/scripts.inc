MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Quando ci chiamano a rapporto, a noi del\n"
	.string "TEAM MAGMA vengono assegnati dei turni\l"
	.string "di guardia a seconda dell’ordine in cui\l"
	.string "ci presentiamo.\p"
	.string "Per questo motivo me ne sto qui\n"
	.string "nell’angolo. Arrivo sempre tardi!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Arrivo sempre tardi anche agli\n"
	.string "allenamenti!\p"
	.string "Non mi piace dirlo, ma sono un incapace…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Ok, cercherò di metterci un po’ più di\n"
	.string "impegno d’ora in poi…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Il nostro CAPO ci ha detto di scavare al\n"
	.string "MONTE CAMINO e noi l’abbiamo fatto.\p"
	.string "Scavando abbiamo trovato qualcosa\n"
	.string "di incredibile!\p"
	.string "Vuoi sapere che cosa?\p"
	.string "Ahahah!\n"
	.string "Te lo dico se mi batti.$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh!\n"
	.string "Sono stato battuto!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Ho deciso di non dirtelo.\n"
	.string "Lo scoprirai da te quando ci arriverai!\p"
	.string "È meglio tenere le sorprese per la fine,\n"
	.string "non trovi?$"

