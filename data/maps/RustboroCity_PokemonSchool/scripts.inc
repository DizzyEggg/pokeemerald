RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Sulla lavagna sono scritte le modifiche \n"
	.string "di stato che i POKéMON possono subire\l"
	.string "durante la lotta.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Quale argomento vuoi leggere?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Se avvelenato, un POKéMON perde\n"
	.string "costantemente PS.\p"
	.string "Il veleno agisce anche dopo la lotta.\p"
	.string "Il POKéMON avvelenato continua\n"
	.string "a perdere PS mentre lo porti in giro.\p"
	.string "Contro il veleno serve un ANTIDOTO.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Se un POKéMON è paralizzato,\n"
	.string "la sua VELOCITÀ si riduce.\p"
	.string "Durante la lotta, può anche non\n"
	.string "riuscire a muoversi.\p"
	.string "La paralisi permane anche dopo\n"
	.string "la lotta. Usa ANTIPARALISI!$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Un POKéMON che dorme non\n"
	.string "può attaccare.\p"
	.string "Un POKéMON può svegliarsi per conto\n"
	.string "suo, ma se la lotta finisce mentre è\l"
	.string "appisolato continuerà a dormire.\p"
	.string "Sveglialo con la SVEGLIA!$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Le scottature riducono la potenza\n"
	.string "di ATTACCO e diminuiscono\l"
	.string "costantemente i PS.\p"
	.string "Le scottature persistono dopo la lotta.\n"
	.string "Curale con ANTISCOTTATURA.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Se un POKéMON è congelato,\n"
	.string "non può fare nulla.\p"
	.string "Il congelamento permane anche dopo\n"
	.string "la lotta. Usa l’ANTIGELO per guarirlo.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Gli studenti svogliati assaporeranno\n"
	.string "il mio RAPIDARTIGLI.\p"
	.string "Se hai studiato o meno si capirà da\n"
	.string "come sai usare questo strumento.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Al POKéMON che tiene RAPIDARTIGLI\n"
	.string "sarà più facile attaccare per primo.\l"
	.string "Inoltre, sarà più veloce.\p"
	.string "I POKéMON possono tenere\n"
	.string "molti altri strumenti.\p"
	.string "Anche solo per apprendere questi\n"
	.string "argomenti, c’è da studiare parecchio!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Sto scambiando POKéMON con\n"
	.string "il mio amico proprio ora.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Ho sempre voluto un SEEDOT e ora\n"
	.string "ne sto per ottenere uno!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "I POKéMON possono tenere strumenti,\n"
	.string "ma non sanno usare gli strumenti fatti\l"
	.string "dall’uomo come POZIONE e ANTIDOTO.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Sapevi che certe mosse possono\n"
	.string "confondere un POKéMON?\p"
	.string "Un POKéMON confuso può colpire\n"
	.string "se stesso senza volerlo.\p"
	.string "Ritorna però normale quando viene\n"
	.string "ritirato dalla lotta.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON che ha una BACCA come\n"
	.string "strumento tenuto può curarsi…\p"
	.string "I POKéMON possono tenere molti\n"
	.string "tipi di strumenti…\p"
	.string "È davvero dura prendere appunti…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Sono gli appunti di uno studente…\p"
	.string "I POKéMON vanno catturati con\n"
	.string "le POKé BALL.\p"
	.string "Un ALLENATORE può avere fino a sei\n"
	.string "POKéMON in squadra.\p"
	.string "Un ALLENATORE è qualcuno che cattura\n"
	.string "i POKéMON, li alleva e lotta con loro.\p"
	.string "La missione di un ALLENATORE è quella\n"
	.string "di sconfiggere ALLENATORI altrettanto\l"
	.string "forti nelle PALESTRE POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Ehi, non ci siamo già incontrati?\n"
	.string "A PETALIPOLI, mi pare.\p"
	.string "Mi presento: sono SCOTT.\p"
	.string "Sono sempre in viaggio alla ricerca di \n"
	.string "ALLENATORI in gamba.\p"
	.string "Mi spiego, sto cercando esperti di lotta\n"
	.string "con i POKéMON.\p"
	.string "Qual buon vento ti porta alla nostra\n"
	.string "SCUOLA? Sei un ALLENATORE anche tu?\p"
	.string "La cosa più importante è insegnare\n"
	.string "TAGLIO a uno dei tuoi POKéMON.\p"
	.string "Se non mi sbaglio, c’è qualcuno che\n"
	.string "ha TAGLIO in questa città.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Uhm…\p"
	.string "Non so esattamente quanto siano bravi\n"
	.string "gli studenti di questa SCUOLA.\l"
	.string "Il potenziale sembra esserci, però.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: E quella cos’è?\p"
	.string "Non è una MEDAGLIA PIETRA?\n"
	.string "I miei complimenti…\p"
	.string "Comunque, mi sarebbe piaciuto\n"
	.string "vederti lottare.\p"
	.string "Non è facile giudicare le qualità di\n"
	.string "un ALLENATORE da una MEDAGLIA.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Ehi, non ci siamo già incontrati noi due?\n"
	.string "A PETALIPOLI, mi pare.\p"
	.string "Mi presento: sono SCOTT.\p"
	.string "Sono sempre in viaggio alla ricerca di \n"
	.string "ALLENATORI in gamba.\p"
	.string "Mi spiego, sto cercando esperti di lotta\n"
	.string "con i POKéMON.\p"
	.string "E quella cos’è?\n"
	.string "Non è una MEDAGLIA PIETRA?\p"
	.string "Non male per un ALLENATORE\n"
	.string "principiante come te.\p"
	.string "Comunque, mi sarebbe piaciuto\n"
	.string "vederti lottare.\p"
	.string "Non è facile giudicare le qualità di\n"
	.string "un ALLENATORE da una MEDAGLIA.$"

