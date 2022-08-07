MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Gli ALLENATORI che usano\n"
	.string "il tipo DRAGO si allenano qui.\p"
	.string "Anche il CAMPIONE viene a farci visita!\n"
	.string "È un posto davvero speciale…$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Urgh!\n"
	.string "Non sospettavo che fossi così forte!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "La strada davanti a me è lunga e\n"
	.string "scoscesa.\p"
	.string "Quando potremo io e i miei POKéMON\n"
	.string "diventare i più forti?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Vorrei saperne di più sulla tua forza.\n"
	.string "Ti registrerò nel mio POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Dal nostro incontro, ci siamo allenati\n"
	.string "senza perdere di vista il numero uno.\p"
	.string "Aiutaci a capire quanto più forti\n"
	.string "siamo diventati!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Urgh!\n"
	.string "Non sospettavo che fossi così forte!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "È chiaro che non hai mai smesso\n"
	.string "di allenarti con i POKéMON.\p"
	.string "Se continui ad essere così forte,\n"
	.string "anch’io posso rafforzarmi!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "IVO: Abbiamo sempre lottato con\n"
	.string "i POKéMON in coppia.\l"
	.string "Confidiamo nelle nostre capacità.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "IVO: Oh, cielo!\n"
	.string "Mogliettina cara, abbiamo perso.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "IVO: Siamo sposati da cinquant’anni.\p"
	.string "Pensa un po’… non sono ancora riuscito\n"
	.string "a battere mia moglie in una lotta.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "IVO: Bene, bene, che ALLENATORE\n"
	.string "giovane!\p"
	.string "Vuoi lottare con noi? Beh, se è questo\n"
	.string "che vuoi, ritorna con più POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "IVO: Se sarà possibile, combatterai\n"
	.string "ancora con noi, giovane ALLENATORE?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "IVA: Siamo sposati da cinquant’anni.\p"
	.string "Il legame che ci unisce non potrà\n"
	.string "mai essere spezzato.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "IVA: Oh, cielo!\n"
	.string "Maritino caro, abbiamo perso.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "IVA: Cinquant’anni di matrimonio…\p"
	.string "Abbiamo sempre fatto pace lottando\n"
	.string "con i POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "IVA: Bene, bene, sei un ALLENATORE\n"
	.string "tanto giovane…\p"
	.string "se vuoi lottare con noi, devi tornare\n"
	.string "con più POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "IVO: Abbiamo sempre lottato con\n"
	.string "i POKéMON in coppia.\l"
	.string "Abbiamo fiducia nelle nostre capacità.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "IVO: Oh, cielo!\n"
	.string "Mogliettina cara, abbiamo perso.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "IVO: Sposati da cinquant’anni…\p"
	.string "Pensandoci bene… io e mia moglie non\n"
	.string "abbiamo mai smesso di lottare…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "IVO: Bene, bene, che ALLENATORE\n"
	.string "giovane!\p"
	.string "Vuoi lottare con noi? Beh, se è questo\n"
	.string "che vuoi, ritorna con più POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "IVA: Siamo sposati da cinquant’anni…\p"
	.string "Non abbiamo mai smesso di incoraggiarci\n"
	.string "e di rafforzarci a vicenda.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "IVA: Oh, cielo!\n"
	.string "Maritino caro, abbiamo perso.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "IVA: In cinquant’anni di matrimonio…\n"
	.string "sono successe tante cose.\p"
	.string "Spero che potremo condividere\n"
	.string "ricordi felici anche nel futuro.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "IVA: Bene, bene, sei un ALLENATORE\n"
	.string "tanto giovane…\p"
	.string "se vuoi lottare con noi, devi tornare\n"
	.string "con più POKéMON.$"

