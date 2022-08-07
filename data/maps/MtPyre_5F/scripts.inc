MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Mi piacciono le cose che fanno paura…\n"
	.string "È più forte di me…\p"
	.string "Quando sono qui…\n"
	.string "mi viene la tremarella…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Non mi piace perdere…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Ho il batticuore…\n"
	.string "ma non mi va di andarmene…\p"
	.string "Vuoi…\n"
	.string "vuoi farmi compagnia?$"

