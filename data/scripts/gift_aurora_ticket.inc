MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "Tu sei {PLAYER}, vero? Ho qui\n"
	.string "un biglietto per te.$"

sText_AuroraTicketUseAtPort:
	.string "Dovrebbe servirti allo scalo di\n"
	.string "PORTO ALGHEPOLI.\p"
	.string "Ti conviene andare a vedere\n"
	.string "di persona.$"

sText_AuroraTicketThankYou:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.$"

sText_AuroraTicketBagFull:
	.string "Oh, mi spiace. La TASCA STRUMENTI\n"
	.string "BASE del tuo ZAINO è piena.\p"
	.string "Torna a trovarmi dopo aver\n"
	.string "depositato qualcosa nel PC.$"
