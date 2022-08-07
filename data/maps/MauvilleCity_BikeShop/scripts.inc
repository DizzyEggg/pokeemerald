MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Bene, bene, chi abbiamo qui?\n"
	.string "Un cliente molto energico!\p"
	.string "Io? Mi chiamo CLELIO.\n"
	.string "Sono il proprietario del negozio.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "CLELIO: Le tue SCARPE da CORSA…\n"
	.string "sono molto sporche.\p"
	.string "Arrivi da molto lontano?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "CLELIO: Davvero?\p"
	.string "Beh, allora immagino che tu non\n"
	.string "voglia nessuna delle mie BICI.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "CLELIO: Uhm, uhm… … … … …\n"
	.string "… … … … … … … …\p"
	.string "Mi stai dicendo che arrivi da ALBANOVA?\p"
	.string "Accipicchia!\n"
	.string "Ne hai fatta di strada!\p"
	.string "Con una delle mie BICI, potresti\n"
	.string "andare dove vuoi con la brezza\l"
	.string "che ti accarezza il viso!\p"
	.string "Sai cosa ti dico…\n"
	.string "ti regalo una BICI!\p"
	.string "Oh, aspetta un attimo!\p"
	.string "Ho dimenticato di dirti che ci sono\n"
	.string "due tipi di BICI!\p"
	.string "La BICI da CORSA e la BICI da CROSS!\p"
	.string "La BICI da CORSA è per ciclisti che\n"
	.string "amano correre lambiti dal vento!\p"
	.string "Mentre la BICI da CROSS è pensata\n"
	.string "per corse più tecniche!\p"
	.string "Voglio essere generoso… Scegli pure\n"
	.string "quella che vuoi!\p"
	.string "Quale preferisci?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} sceglie la BICI da CORSA.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} sceglie la BICI da CROSS.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "CLELIO: Se vuoi cambiare tipo di BICI,\n"
	.string "vieni a trovarmi!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "CLELIO: Oh?! Vuoi cambiare tipo di BICI?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "CLELIO: Ok, sono qui per questo!\n"
	.string "Ti do l’altro tipo!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} riceve la BICI da CROSS in\n"
	.string "cambio della BICI da CORSA.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} riceve la BICI da CORSA in\n"
	.string "cambio della BICI da CROSS.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "CLELIO: Bene, bene!\n"
	.string "Sono contento che ti piaccia!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh?! Dove hai messo la BICI che\n"
	.string "ti avevo dato?\p"
	.string "Oh, capisco, l’hai riposta nel tuo PC.\p"
	.string "Prelevala dal PC, sarò contento\n"
	.string "di sostituirtela!\p"
	.string "Spero che in quest’avventura tu abbia\n"
	.string "sempre il vento in poppa!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Lavorando qui ho imparato un sacco\n"
	.string "di cose sulle BICI.\p"
	.string "Se hai bisogno di qualche buon consiglio\n"
	.string "su come andare in BICI, ci sono\l"
	.string "un paio di manuali nel retro.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Un manuale sulla BICI da CORSA.\p"
	.string "Quale pagina vuoi leggere?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "La BICI si muove nella direzione in cui\n"
	.string "premi la pulsantiera di comando +.\p"
	.string "La BICI accelera man mano che prende\n"
	.string "velocità.\p"
	.string "Rilasciando la pulsantiera di comando +,\n"
	.string "la BICI rallenterà fino a fermarsi.\p"
	.string "Vuoi leggere un’altra pagina?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "La BICI da CORSA è veloce e non è facile\n"
	.string "farla rallentare.\p"
	.string "Può essere un po’ complicato svoltare\n"
	.string "agli angoli.\p"
	.string "Prima di una svolta, rilascia\n"
	.string "leggermente la pulsantiera di\l"
	.string "comando + e rallenta.\p"
	.string "Vuoi leggere un’altra pagina?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Nella regione di HOENN ci sono delle\n"
	.string "piccole dune sabbiose.\p"
	.string "La sabbia fine e soffice le rende\n"
	.string "impossibili da scalare.\p"
	.string "Ma con una BICI da CORSA, le puoi\n"
	.string "superare veloce come un lampo.\p"
	.string "Vuoi leggere un’altra pagina?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Un manuale sulla BICI da CROSS.\p"
	.string "Quale pagina vuoi leggere?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Per fare sollevare la ruota davanti,\n"
	.string "premi il pulsante B mentre corri.\p"
	.string "Con la pulsantiera di comando +,\n"
	.string "puoi sfrecciare con la ruota sollevata.\p"
	.string "Questa tecnica si chiama impennata.\p"
	.string "Vuoi leggere un’altra pagina?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Tenendo premuto il pulsante B,\n"
	.string "la BICI salta sul posto.\p"
	.string "Questa è la tecnica dei saltelli.\p"
	.string "Puoi anche correre saltellando.\p"
	.string "Vuoi leggere un’altra pagina?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Per saltare premi il pulsante B e la\n"
	.string "pulsantiera di comando + insieme.\p"
	.string "Premi la pulsantiera di comando + di\n"
	.string "lato rispetto alla tua posizione per\l"
	.string "saltare a destra o a sinistra.\p"
	.string "Premila all’indietro per invertire\n"
	.string "la direzione.\p"
	.string "Vuoi leggere un’altra pagina?$"

