PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 4, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 2, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM21
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Ehm, ehm!\p"
	.string "Sono la persona più importante di\n"
	.string "tutto il POKéMON FAN CLUB, sono\l"
	.string "il fratello minore del PRESIDENTE.\p"
	.string "Ora mi sto godendo la mia vacanza\n"
	.string "coi POKéMON, proprio così!$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Ah!\n"
	.string "Il tuo POKéMON…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Ti è molto affezionato…\p"
	.string "Un POKéMON così bello, che ti adora,\n"
	.string "merita una MT come questa, non credi?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Mhmm… non va male,\n"
	.string "ma nemmeno tanto bene.\p"
	.string "Tu che sei l’ALLENATORE devi\n"
	.string "impegnarti di più.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Che sguardo minaccioso che ha…\p"
	.string "Un POKéMON così spaventoso\n"
	.string "merita una MT come questa.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Se un POKéMON è molto legato a te,\n"
	.string "sale la potenza di RITORNO.\p"
	.string "Se invece non gli piaci, sale la\n"
	.string "potenza di FRUSTRAZIONE.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "A giorni dovrei ricevere qualche\n"
	.string "buona MT. Siamo a meno {STR_VAR_1}.\p"
	.string "Passa a trovarmi allora. Ti darò\n"
	.string "una MT adatta al tuo POKéMON.$"

PacifidlogTown_House2_Text_Rurii:
	.string "AZURILL: Azuriiiiill!$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "Pare molto affezionato al suo\n"
	.string "ALLENATORE.$"

PacifidlogTown_House2_Text_Rururi:
	.string "AZURILL: Azuriiiiill!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "Non mi pare molto affezionato\n"
	.string "al suo ALLENATORE!$"

