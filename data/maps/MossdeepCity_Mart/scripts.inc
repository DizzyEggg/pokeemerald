MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "Il REVITALIZZANTE è fantastico!\p"
	.string "Dallo ad un POKéMON esausto\n"
	.string "e ritornerà subito in sé.\p"
	.string "Ma attenzione: il REVITALIZZANTE non\n"
	.string "restituisce i PP esauriti delle mosse.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "Il REPELLENTE MAX tiene alla larga\n"
	.string "i POKéMON deboli.\p"
	.string "È lo spray REPELLENTE che dura\n"
	.string "più a lungo.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "RETE e SUB BALL sono POKé BALL\n"
	.string "rare che si fanno solo a VERDEAZZUPOLI.\p"
	.string "La RETE BALL è efficace contro\n"
	.string "i POKéMON di tipo COLEOTTERO e ACQUA.\p"
	.string "La SUB BALL funziona meglio sui POKéMON\n"
	.string "dei fondali marini.$"

