SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Stammi a sentire, ho qualcosa di\n"
	.string "importante da dirti.\p"
	.string "Corre voce che nei dintorni ci sia\n"
	.string "un relitto sul fondo del mare.\p"
	.string "Laggiù ci potrebbero essere tesori\n"
	.string "ancora da scoprire.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Tesori antichi…\p"
	.string "Sarebbe fantastico se esistessero,\n"
	.string "ma anche se così non fosse, sai che\l"
	.string "bello farsi una passeggiata sott’acqua\l"
	.string "con il mio POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Azumari.$"

