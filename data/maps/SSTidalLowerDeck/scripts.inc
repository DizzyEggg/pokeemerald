SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Grrr! Sono arcistufo di pulire\n"
	.string "questo posto enorme!\p"
	.string "Avanti, lottiamo!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Incredibile, ho perso!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Siamo i FRATELLI RIPULISTI!\p"
	.string "Il più grande sparge il detersivo,\n"
	.string "il più piccolo passa lo straccio!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Siamo all’interno dello scafo della\n"
	.string "nave. C’è un sacco di spazio. Proprio\l"
	.string "il posto giusto per una bella lotta.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Inammissibile, ho perso!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Siamo i FRATELLI RIPULISTI!\p"
	.string "Il più grande sparge il detersivo,\n"
	.string "il più piccolo passa lo straccio!$"

