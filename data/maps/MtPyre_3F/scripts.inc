MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "L’atmosfera speciale della montagna\n"
	.string "rafforza i miei poteri psichici!\p"
	.string "Sei ancora in fasce… credi di\n"
	.string "potermi battere?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "È tutta colpa mia…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "I miei poteri psichici si sono\n"
	.string "notevolmente rafforzati, ma…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahah!\p"
	.string "I marmocchi non mi piacciono,\n"
	.string "togli il tuo bel faccino di torno!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Una sconfitta netta…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Ciò significa che devo allenarmi\n"
	.string "di più…\p"
	.string "Devo darmi da fare per raggiungere\n"
	.string "la vetta…\p"
	.string "Ce la farò!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Che ci fai tu qui?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Magnifico! Sei un ALLENATORE\n"
	.string "veramente speciale!$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "I POKéMON che non sono più fra noi.\n"
	.string "I POKéMON che hai con te.\p"
	.string "E i POKéMON che incontrerai in\n"
	.string "futuro…\p"
	.string "Tutti meritano il nostro affetto.\n"
	.string "Non dimenticarlo.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Mi piacerebbe rivedere i tuoi POKéMON\n"
	.string "quando saranno cresciuti…\p"
	.string "Per favore, fammi vedere il tuo POKéNAV.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Ah, sei tu…\p"
	.string "Sei qui per farmi vedere i tuoi POKéMON\n"
	.string "cresciuti?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Fantastico!\n"
	.string "Sei una persona speciale.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "I POKéMON che non sono più fra noi.\n"
	.string "I POKéMON che hai con te.\p"
	.string "E i POKéMON che incontrerai in\n"
	.string "futuro…\p"
	.string "Tutti meritano il nostro affetto.\n"
	.string "Vedo che non l’hai dimenticato.$"

