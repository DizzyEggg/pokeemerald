FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM10, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM10
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM10
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Le persone… i POKéMON…\p"
	.string "L’ambiente naturale nel quale vivono\n"
	.string "risveglia la loro forza interiore…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Mostra a questa nonnina se la tua\n"
	.string "forza interiore si è risvegliata…\p"
	.string "Ho una moneta in mano.\p"
	.string "Ora, dimmi, è nella mano destra\n"
	.string "o in quella sinistra?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Sì, indovinato!\p"
	.string "Proviamo un’altra volta.\p"
	.string "In quale mano nascondo la moneta?\n"
	.string "Destra o sinistra?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Sì, indovinato!\p"
	.string "Proviamo un’altra volta.\p"
	.string "In quale mano nascondo la moneta?\n"
	.string "Destra o sinistra?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Magnifico!\n"
	.string "La tua forza interiore si è risvegliata!\p"
	.string "Prendi questo e risveglia la forza\n"
	.string "interiore dei tuoi POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "INTROFORZA è una mossa che varia\n"
	.string "a seconda del POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "No, peccato.\n"
	.string "Non hai indovinato.$"

