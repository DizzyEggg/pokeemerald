LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Oh! Viaggi per conto tuo?\n"
	.string "Sei così giovane, complimenti!\p"
	.string "I miei figli dovrebbero seguire\n"
	.string "il tuo esempio!\p"
	.string "Io? Sono l’ESPERTA {POKEMELLE}.\p"
	.string "Se mi ci metto, posso preparare\n"
	.string "delle {POKEMELLE} fantastiche.\p"
	.string "Vuoi carpire qualche segreto\n"
	.string "dall’ESPERTA {POKEMELLE}?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Oh? Davvero?\p"
	.string "Non dovresti sempre fare di testa tua!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oh, la tua è una mossa intelligente!\n"
	.string "Stammi a sentire attentamente!\p"
	.string "Iniziamo?\p"
	.string "Le {POKEMELLE} sono classificate in base\n"
	.string "alla loro fibrosità.\p"
	.string "Minore è la fibrosità, meglio è!\n"
	.string "Non scordartelo!\p"
	.string "Una buona {POKEMELLA} ha una bassa\n"
	.string "fibrosità ed un alto livello.\p"
	.string "Se fai {POKEMELLE} di buona qualità, il tuo\n"
	.string "POKéMON ne potrà mangiare di più.\p"
	.string "Anche questo è un fattore da non\n"
	.string "trascurare.\p"
	.string "Se vuoi fare {POKEMELLE} morbide,\n"
	.string "usa diversi tipi di BACCHE.\p"
	.string "Abbonda pure! I tipi di BACCHE\n"
	.string "influenzano la morbidezza delle {POKEMELLE}.\p"
	.string "Un’altra cosa.\p"
	.string "Più persone fanno il mix di BACCHE,\n"
	.string "più morbide saranno le {POKEMELLE}.\p"
	.string "Ecco perché dovresti chiedere ad altre\n"
	.string "persone di aiutarti a fare le {POKEMELLE}.\p"
	.string "Questo è tutto quello che devi sapere\n"
	.string "per fare {POKEMELLE} di buona qualità.\p"
	.string "Se tutti avessero POKéMON a cui\n"
	.string "voler bene, {POKEMELLE} morbide e \l"
	.string "una famiglia affettuosa, il mondo \l"
	.string "sarebbe un posto migliore.\p"
	.string "Non mollare mai, tesorino!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Quando mia moglie ha dato alla luce\n"
	.string "quattro gemelli, mi è venuto un colpo!\p"
	.string "Adesso vederli giocare insieme\n"
	.string "mi riempie di gioia.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Facciamo LOTTE MULTIPLE, ma so\n"
	.string "già che vincerò.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Ci piace scambiare cose al BANCO\n"
	.string "REGISTRO.\p"
	.string "Ma che cosa ci si scambia?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Faremo super {POKEMELLE}\n"
	.string "con un MIXER BACCHE!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Voglio che tutti vedano quant’è\n"
	.string "grintoso il nostro POKéMON, quindi\l"
	.string "andiamo ad iscriverci a una GARA.$"

