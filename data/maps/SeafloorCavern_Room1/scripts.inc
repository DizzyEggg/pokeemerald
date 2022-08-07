SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Togli il disturbo, scricciolo!\n"
	.string "Tornatene a casa!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Casetta mia, aspettami…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Voglio una promozione, così potrò\n"
	.string "fare il gradasso con le RECLUTE…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Il sottomarino… dentro è così stretto.\n"
	.string "Sono tutto ammaccato!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Ho subito uno smacco!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Nel sottomarino che abbiamo rubato\n"
	.string "si sta stretti come delle sardine!$"

