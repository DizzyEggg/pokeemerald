AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Che cosa? Cosa vuoi dal TEAM IDRO?\p"
	.string "Il nostro CAPO non è qui! È andato\n"
	.string "ad arraffare qualcosa di importante!\p"
	.string "… …\n"
	.string "Dove?\p"
	.string "Ahahah! Credi che ti venga a spifferare\n"
	.string "un’informazione così importante?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Cosa?\n"
	.string "Fai parte del TEAM MAGMA?\p"
	.string "Ho sentito che quelli del TEAM MAGMA\n"
	.string "vogliono risvegliare un POKéMON\l"
	.string "incredibile nel loro RIFUGIO.\p"
	.string "Ma dove sarà il loro RIFUGIO?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Che cosa? Cosa vuoi dal TEAM IDRO?\p"
	.string "Il nostro CAPO non c’è! È andato \n"
	.string "a sgraffignare un sottomarino!\p"
	.string "… …\n"
	.string "Dove?\p"
	.string "Ahahah! Credi che ti venga a spifferare\n"
	.string "un’informazione così importante?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Che cosa? Cosa vuoi dal TEAM IDRO?\p"
	.string "Il nostro CAPO non è qui! Sta andando al\n"
	.string "MONTE PIRA sul PERCORSO 122!\p"
	.string "… …\n"
	.string "Perché?\p"
	.string "Ahahah! Credi che ti venga a spifferare\n"
	.string "un’informazione così importante?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Cosa?\n"
	.string "Fai parte del TEAM MAGMA?\p"
	.string "Ho sentito che quelli del TEAM MAGMA\n"
	.string "stanno cercando un POKéMON fantastico\l"
	.string "presso il MONTE CAMINO.\p"
	.string "Ma di che POKéMON si tratta?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Che cosa? Cosa vuoi dal TEAM IDRO?\p"
	.string "Il nostro CAPO non è qui!\n"
	.string "È diretto verso PORTO SELCEPOLI!\p"
	.string "… …\n"
	.string "Perché?\p"
	.string "Ahahah! Credi che ti venga a spifferare\n"
	.string "un’informazione così importante?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ihihih!\n"
	.string "Individuato personaggio sospetto!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrr… ho perso!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Ho perso nel nome del mio TEAM,\n"
	.string "ma ho la coscienza pulita…$"

