GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM05
	setflag FLAG_RECEIVED_HM05
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Ehi, tu!\n"
	.string "Più avanti è davvero buio.\l"
	.string "Non sarà facile addentrarsi.\p"
	.string "Quel ragazzo che è passato prima…\n"
	.string "si chiamava ROCCO…\p"
	.string "Lui sapeva usare FLASH, quindi di sicuro\n"
	.string "se la starà cavando bene, ma…\p"
	.string "aiutare chi incontriamo è il motto di noi\n"
	.string "AVVENTURIERI!\p"
	.string "Prendi questo, ti sarà utile.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Insegna la mossa MN FLASH\n"
	.string "ad un POKéMON.\p"
	.string "FLASH illumina anche gli angoli\n"
	.string "più oscuri delle grotte.\p"
	.string "Ma senza la MEDAGLIA della PALESTRA\n"
	.string "POKéMON di BLURUVIA non puoi usarla.$"

