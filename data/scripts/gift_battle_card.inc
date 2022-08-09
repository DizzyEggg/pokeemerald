MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "La tua SCHEDA CONTALOTTE\n"
	.string "calcola il numero di LOTTE contro\l"
	.string "ALLENATORI con la stessa SCHEDA.\p"
	.string "Cerca altri ALLENATORI che hanno\n"
	.string "la SCHEDA CONTALOTTE e sfidali!\p"
	.string "I risultati saranno diffusi tra le\n"
	.string "NOTIZIE!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO!\p"
	.string "Congratulazioni! Hai ottenuto\n"
	.string "un premio per aver vinto tre lotte!\p"
	.string "Speriamo che questo ti aiuti ad\n"
	.string "impegnarti ancora di più nella\l"
	.string "lotta!$"
