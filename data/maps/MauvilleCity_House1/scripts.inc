MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM06, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM06
	setflag FLAG_RECEIVED_HM06
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Wow!\p"
	.string "Ho saputo che mi chiamano il TIPO\n"
	.string "SPACCAROCCIA. Il nome non mi\l"
	.string "rende giustizia, però…\p"
	.string "Penso di meritare un po’ più di rispetto.\n"
	.string "Perché non mi chiamano il BELLO\l"
	.string "SPACCAROCCIA?\p"
	.string "Wow, i tuoi POKéMON mi sembrano proprio\n"
	.string "in forma.\p"
	.string "Complimenti!\n"
	.string "Prendi questa MACCHINA NASCOSTA!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "La MN contiene SPACCAROCCIA.\p"
	.string "Se una roccia blocca il tuo cammino…\p"
	.string "usa questa mossa MN per ridurla\n"
	.string "in poltiglia!\p"
	.string "Hai capito bene, in poltiglia!\n"
	.string "Wow!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Quando frantumi una roccia, un POKéMON\n"
	.string "potrebbe essere in agguato…\p"
	.string "Wow!$"

