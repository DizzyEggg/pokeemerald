MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Ehi, salve ALLENATORE!\n"
	.string "Il SUPER AMO è un portento!\p"
	.string "Checché se ne dica, è ottimo per\n"
	.string "pescare POKéMON dai fondali marini!\p"
	.string "Che ne pensi?\n"
	.string "Lo vuoi?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Lo sapevo! Dopotutto ci sarà pur\n"
	.string "un motivo per cui si chiama SUPER AMO!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Se c’è dell’acqua, prova a lanciare\n"
	.string "il tuo AMO e vedi cosa abbocca!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Uhm?\n"
	.string "Non ami la pesca?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Pesca i POKéMON dei fondali marini\n"
	.string "con questo SUPER AMO.$"

