RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Ai miei POKéMON do dei soprannomi\n"
	.string "che calzano a pennello!\p"
	.string "È un modo tutto mio per esprimere\n"
	.string "la mia originalità!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Ma che senso ha dare il soprannome\n"
	.string "PEKACHU ad un PIKACHU…?\p"
	.string "Credo che sia una buona idea usare\n"
	.string "un nome facile da capire…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

