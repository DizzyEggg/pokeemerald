SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 4, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Ehm, ehm! Sono il PRESIDENTE del\n"
	.string "POKéMON FAN CLUB!\p"
	.string "Essendo il PRESIDENTE, sono la persona\n"
	.string "più autorevole!\p"
	.string "Nessuno alleva i POKéMON meglio di me.\n"
	.string "Nessuno!\p"
	.string "Ti dirò qualcosa a proposito delle\n"
	.string "GARE POKéMON.\p"
	.string "Le GARE ti danno la possibilità di far \n"
	.string "esibire i tuoi POKéMON davanti a un\l"
	.string "folto pubblico.\p"
	.string "Purtroppo, queste GARE si svolgono\n"
	.string "in una città lontana e io non posso\l"
	.string "parteciparvi spesso.\p"
	.string "Per questo motivo, ci incontriamo qui\n"
	.string "per mostrare i nostri POKéMON agli\l"
	.string "altri e vedere i loro.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "Come mi piacerebbe vedere i POKéMON\n"
	.string "di un ALLENATORE che ha appena par-\l"
	.string "tecipato a una GARA POKéMON!$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Ehm, ehm! Vedo che hai partecipato a\n"
	.string "una GARA POKéMON!\p"
	.string "Ti prego, fammi vedere se hai allenato\n"
	.string "bene i tuoi POKéMON.\p"
	.string "È un tal piacere per me vedere\n"
	.string "i POKéMON cresciuti dagli altri.\p"
	.string "L’espressione felice dei POKéMON\n"
	.string "ben allevati…\p"
	.string "gli sguardi attenti ed amorevoli dei\n"
	.string "loro ALLENATORI…\p"
	.string "Il mio cuore è pervaso da immensa gioia.\p"
	.string "Oh, cielo! Scusa, ho chiacchierato\n"
	.string "troppo!\p"
	.string "Permettimi di esaminare uno dei tuoi\n"
	.string "POKéMON per vedere come sta crescendo.$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Come stanno crescendo i tuoi POKéMON?\n"
	.string "Permettimi di esaminarne uno.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Uhm, uhm… vedo…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Uhmm… non c’è male, ma puoi fare\n"
	.string "di meglio…\p"
	.string "Come ALLENATORE devi impegnarti\n"
	.string "di più quando alleni questo POKéMON!\p"
	.string "Ad esempio, ti posso suggerire di dargli\n"
	.string "più {POKEMELLE}?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Ehmm…\p"
	.string "Il tuo POKéMON sta crescendo molto\n"
	.string "bene, ti meriti una ricompensa.\p"
	.string "Sfortunatamente, non hai più spazio\n"
	.string "nel tuo ZAINO.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Il tuo {STR_VAR_1} sta crescendo\n"
	.string "superbamente!\l"
	.string "È proprio un bell’esemplare!\p"
	.string "Ma se gli dai questo, potrà diventare\n"
	.string "ancora più forte!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Fai tenere la FASCIA ROSSA ad\n"
	.string "un POKéMON.\p"
	.string "Tutti potranno ammirare la sua\n"
	.string "classe!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Fai tenere la FASCIA BLU ad\n"
	.string "un POKéMON.\p"
	.string "Esalterà ancora di più la sua bellezza!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Fai tenere la FASCIA ROSA ad\n"
	.string "un POKéMON.\p"
	.string "La sua grazia spiccherà meglio!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Fai tenere la FASCIA VERDE ad\n"
	.string "un POKéMON.\p"
	.string "Accentuerà il suo acume!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Fai tenere la FASCIA GIALLA ad\n"
	.string "un POKéMON.\p"
	.string "Rafforzerà molto la sua grinta!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Mi dispiace, ma non ho più nulla da darti!\p"
	.string "Dopotutto riesci ad allevare i POKéMON\n"
	.string "senza ricorrere agli strumenti. Un vero\l"
	.string "dono di natura!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "È edificante vedere i POKéMON che\n"
	.string "vogliono bene ai loro ALLENATORI.\p"
	.string "I POKéMON sono molto sensibili ai\n"
	.string "sentimenti dei loro ALLENATORI.\p"
	.string "Se tratti i tuoi POKéMON con amore e\n"
	.string "con cura, ti vorranno bene a loro volta.\p"
	.string "Quando i tuoi POKéMON ti vorranno\n"
	.string "tanto bene, torna a trovarmi.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Il tuo POKéMON ti adora davvero.\p"
	.string "Un omaggio ad un ALLENATORE sensibile\n"
	.string "da parte del FAN CLUB!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "I POKéMON sono molto sensibili ai\n"
	.string "sentimenti dei loro ALLENATORI.\p"
	.string "Se tratti i tuoi POKéMON con amore e\n"
	.string "con cura, ti vorranno bene a loro volta.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Se continui a far lottare un POKéMON\n"
	.string "finché è esausto… non ne sarà\l"
	.string "contento!\p"
	.string "Presto diventerà più diffidente nei\n"
	.string "confronti del suo ALLENATORE.\p"
	.string "In altre parole, non ti vorrà più tanto\n"
	.string "bene.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Sono contenti i POKéMON quando usi\n"
	.string "strumenti su di loro?\p"
	.string "Il mio sembrava davvero contento\n"
	.string "quando gli ho dato della PROTEINA.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Ssskkkiiitttyyy…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON: ZigzagZigzag…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Azumari?$"

