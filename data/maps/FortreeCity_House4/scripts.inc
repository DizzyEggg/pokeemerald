.set LOCALID_WINGULL, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "Vivere insieme ai POKéMON crea maggior\n"
	.string "affiatamento fra gli esseri umani.\p"
	.string "C’è maggior sintonia nel mondo.\n"
	.string "È fantastico!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Forza!\n"
	.string "Vai, POKéMON UCCELLO!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Eheheh, ho chiesto al mio WINGULL\n"
	.string "di fare una missione per me.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Bene!\n"
	.string "Bentornato, WINGULL!\p"
	.string "Uh? Che cos’è?\n"
	.string "Che cosa sta tenendo?\p"
	.string "Una MENTALERBA?\n"
	.string "Deve averla raccolta da qualche parte.\p"
	.string "Ma non sono un ALLENATORE, quindi te\n"
	.string "la regalo.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Grazie al mio WINGULL, ho amici\n"
	.string "che vengono da lontano.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL: Wiinngguull!$"

