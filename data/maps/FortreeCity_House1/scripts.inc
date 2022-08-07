FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Wow! Lo voglio! Devo avere\n"
	.string "{STR_VAR_1} a tutti i costi.\l"
	.string "Non so cosa darei!\p"
	.string "Uh… l’hai sentito?\n"
	.string "L’urlo dal profondo del mio cuore?\p"
	.string "Se l’hai sentito, non puoi fare\n"
	.string "a meno di scambiare il tuo {STR_VAR_1}\l"
	.string "per il mio {STR_VAR_2}.$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Sì, benissimo!\p"
	.string "Benvenuto {STR_VAR_1}!\n"
	.string "Arrivederci {STR_VAR_2}!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "No, mi pare proprio di no.\n"
	.string "Questo non è {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "No? Non vuoi fare lo scambio?\n"
	.string "Anche se ti ho aperto il mio cuore?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "D’ora in poi mi dedicherò al mio\n"
	.string "VOLBEAT e lo rafforzerò!\p"
	.string "Spero che tu farai lo stesso\n"
	.string "con PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Scambiare POKéMON con gli altri…\p"
	.string "è come scambiare i tuoi ricordi\n"
	.string "con altre persone.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: ZigzagZigzag?$"

