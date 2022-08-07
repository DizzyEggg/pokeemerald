SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Ehi, ciao! Sono il GIUDICE ONOMASTICO,\n"
	.string "l’indovino dei nomi!\p"
	.string "Sarei lieto di valutare il soprannome\n"
	.string "dei tuoi POKéMON.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Quale soprannome di POKéMON devo\n"
	.string "giudicare?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Uhmm… {STR_VAR_1}, giusto? Hai scelto\n"
	.string "proprio un bel nome.\p"
	.string "Ma che ne dici di trovarne uno ancora\n"
	.string "migliore?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Bene! Quale nuovo soprannome vuoi\n"
	.string "dare?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Fatto! D’ora in poi, questo POKéMON\n"
	.string "si chiamerà {STR_VAR_1}!\p"
	.string "È un nome migliore del primo!\n"
	.string "Proprio una bella fortuna!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Ah… capisco.\n"
	.string "Torna a farmi visita.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Fatto! D’ora in poi, questo POKéMON\n"
	.string "si chiamerà {STR_VAR_1}!\p"
	.string "D’aspetto non è cambiato, però\n"
	.string "è immensamente superiore!\p"
	.string "Proprio una bella fortuna!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Uhmm… {STR_VAR_1}. Che bella scelta!\p"
	.string "Un soprannome magnifico!\n"
	.string "Assolutamente impeccabile!\p"
	.string "Abbi gran cura di {STR_VAR_1}, adesso e\n"
	.string "per sempre.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Suvvia!\n"
	.string "È soltanto un UOVO!$"

