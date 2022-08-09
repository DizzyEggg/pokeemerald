MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "Tu sei {PLAYER}, vero? Ho qui\n"
	.string "una MAPPA STINTA per te.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Dovrebbe servirti allo scalo di\n"
	.string "PORTO ALGHEPOLI.\p"
	.string "Ti conviene andare a vedere\n"
	.string "di persona.$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, mi spiace. La TASCA STRUMENTI\n"
	.string "BASE del tuo ZAINO è piena.\p"
	.string "Torna a trovarmi dopo aver\n"
	.string "depositato qualcosa nel PC.$"
