MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Quando sono qui…\n"
	.string "mi pervade uno strano potere…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Il potere sta sfumando…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Forse il potere proviene dai POKéMON\n"
	.string "che riposano qui…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… ho perso\n"
	.string "ma… ho questa capacità…\p"
	.string "Senza neppure toccare il tuo\n"
	.string "POKéNAV… ahah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Dietro di te… che cosa c’è…?$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Qualcosa si è dileguato…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "I POKéMON che riposano qui…\n"
	.string "a volte giocano…$"

MtPyre_6F_Text_CedricIntro:
	.string "Hai perso l’orientamento?\n"
	.string "Non aver paura, ci sono io qui!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Non avevi perso la bussola?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Pensavo che un ALLENATORE che si\n"
	.string "è perso fosse facile da battere.\p"
	.string "Non mi va giù. Non ci riproverò…$"

