MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Il MONTE PIRA è un luogo dove si fanno\n"
	.string "incontri strani…\p"
	.string "Sono successe cose incredibili.\n"
	.string "Prendi questo. Ti sarà utile.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Fai tenere VELOPURO ad un POKéMON.\p"
	.string "Aiuterà a tenere lontano i POKéMON\n"
	.string "selvatici.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Vieni a venerare le anime dei\n"
	.string "POKéMON scomparsi?\p"
	.string "Devi volere molto bene ai tuoi POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Qui riposa il mio ZIGZAGOON. Sono\n"
	.string "venuto a rendergli omaggio…$"

