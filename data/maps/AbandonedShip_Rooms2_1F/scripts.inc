AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Andando a caccia di tesori…\n"
	.string "abbiamo trovato un ALLENATORE!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Anche in due non siamo riusciti\n"
	.string "a batterti…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: Non riusciamo a trovare i tesori…\n"
	.string "Se li sarà già intascati qualcuno?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Non hai nemmeno due POKéMON.\n"
	.string "Come credi di poterci battere?$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "CIRA: Oh? Eravamo a caccia di tesori.\n"
	.string "Ma chi abbiamo incontrato?\l"
	.string "Un ALLENATORE!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "CIRA: Oh, wow, sei forte!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "CIRA: Chissà dove sono nascosti\n"
	.string "i tesori…\p"
	.string "So già cosa comprarmi quando li troverò!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "CIRA: Non hai due POKéMON?\n"
	.string "Beh, allora dobbiamo rinviare la sfida!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "CIRA: Che rabbia che mi fai!\n"
	.string "Ti registrerò nel POKéNAV!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: È da tempo che siamo a caccia\n"
	.string "di tesori.\p"
	.string "I nostri POKéMON si sono rafforzati.\n"
	.string "Vuoi una dimostrazione?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Sei forte, come sempre!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: Non troviamo tesori, perdiamo\n"
	.string "con i POKéMON…\p"
	.string "Voglio andare a casa… Ma se oso dirlo\n"
	.string "a mia moglie, va su tutte le furie…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Non hai nemmeno due POKéMON.\n"
	.string "Come credi di poterci battere?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "CIRA: Ehi, chi si rivede!\p"
	.string "Vedo che anche tu non hai rinunciato\n"
	.string "a dare la caccia ai tesori!\p"
	.string "Che ne dici di lottare e chi perde\n"
	.string "rinuncia al bottino?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "CIRA: Oh no, ancora una volta…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "CIRA: Resteremo qui ad allenare\n"
	.string "i nostri POKéMON! Non si torna\l"
	.string "a casa a mani vuote!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "CIRA: Non hai due POKéMON?\n"
	.string "Beh, allora è tutto rimandato!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Nuotare non è il mio forte,\n"
	.string "ma le lotte sì!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Oops.\n"
	.string "Qualcosa è andato storto.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Non mi piace camminare a piedi nudi\n"
	.string "su questa nave.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Forza e compassione…\n"
	.string "sono i tesori di un ALLENATORE!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "C’è qualcosa di luccicante in te.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Ho visto qualcosa luccicare in\n"
	.string "una cabina a bordo.$"
