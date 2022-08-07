FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM27
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COSMI: Oh…\n"
	.string "Non avrei mai dovuto farmi raggirare\l"
	.string "dal TEAM MAGMA e rivelargli dove\l"
	.string "si trovano i METEORITI…\p"
	.string "Quel METEORITE delle CASCATE METEORA…\n"
	.string "non sarà mai mio…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh!\n"
	.string "Ehi… ma…\p"
	.string "Quello strumento…\p"
	.string "Non può essere…\p"
	.string "È il METEORITE rubato dal TEAM MAGMA\n"
	.string "alle CASCATE METEORA?\p"
	.string "Ti prego, posso averlo io?\p"
	.string "Non lo voglio gratis, ovviamente.\n"
	.string "Cosa ne dici di questa MT in cambio?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COSMI: Questa MT è un segno\n"
	.string "della mia profonda gratitudine.\l"
	.string "Usala, ti prego!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COSMI: Oh, non ci posso credere.\n"
	.string "È davvero fantastico!\p"
	.string "Darà un contributo fondamentale\n"
	.string "alla mia ricerca!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COSMI: Oh, ma… che delusione!\n"
	.string "Non me l’aspettavo da te…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COSMI: Mi dai quel METEORITE,\n"
	.string "per favore?\p"
	.string "Non lo voglio gratis, ovviamente.\n"
	.string "Cosa ne dici di questa MT in cambio?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "Il PROF. COSMI se n’è andato alle\n"
	.string "CASCATE METEORA sul PERCORSO 114\l"
	.string "con dei loschi figuri del TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Povero PROF. COSMI!\n"
	.string "È così depresso… mi dispiace per lui.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Guarda il PROF. COSMI!\n"
	.string "È così felice! Sembra un bambino…$"

