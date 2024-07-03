EventScript_BidoofNoPokemonTalk::
# 2 "data/scripts/new_scripts.pory"
	lockall
# 3 "data/scripts/new_scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, 78, 107
# 4 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofNoPokemonTalk_Text_0
# 5 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofNoPokemonTalk_Text_1
# 6 "data/scripts/new_scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
# 7 "data/scripts/new_scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, 78, 107
# 8 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofNoPokemonTalk_Text_2
# 9 "data/scripts/new_scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 10 "data/scripts/new_scripts.pory"
	setflag FLAG_BIDOOF_NO_POKES_COMMENT
# 11 "data/scripts/new_scripts.pory"
	releaseall
	end


EventScript_BidoofFollowerTypicalStart::
# 18 "data/scripts/new_scripts.pory"
	lock
# 19 "data/scripts/new_scripts.pory"
	faceplayer
# 20 "data/scripts/new_scripts.pory"
	setvar VAR_0x8008, 0xFF
# 21 "data/scripts/new_scripts.pory"
	setvar VAR_0x8009, 0xFF
	return


EventScript_BidoofFollowerTypicalEnd::
# 26 "data/scripts/new_scripts.pory"
	addvar VAR_BIDOOF_FOLLOWER_NO_TALKS, 1
# 27 "data/scripts/new_scripts.pory"
	waitmessage
# 28 "data/scripts/new_scripts.pory"
	compare VAR_0x8008, 0xFF
	goto_if_ne EventScript_BidoofFollowerTypicalEnd_2
EventScript_BidoofFollowerTypicalEnd_1:
# 31 "data/scripts/new_scripts.pory"
	compare VAR_0x8009, 0xFF
	goto_if_ne EventScript_BidoofFollowerTypicalEnd_5
EventScript_BidoofFollowerTypicalEnd_4:
	return

EventScript_BidoofFollowerTypicalEnd_2:
# 29 "data/scripts/new_scripts.pory"
	destroy_field_pic VAR_0x8008, VAR_0x800A
	goto EventScript_BidoofFollowerTypicalEnd_1

EventScript_BidoofFollowerTypicalEnd_5:
# 32 "data/scripts/new_scripts.pory"
	destroy_field_pic VAR_0x8009, VAR_0x800B
	goto EventScript_BidoofFollowerTypicalEnd_4


EventScript_BidoofFirstMsg::
# 38 "data/scripts/new_scripts.pory"
	call EventScript_BidoofFollowerTypicalStart
# 39 "data/scripts/new_scripts.pory"
	setvar VAR_0x8008, FIELD_PIC_BIDOOF_NORMAL
# 40 "data/scripts/new_scripts.pory"
	load_field_pic VAR_0x8008, 78, 107, VAR_0x800A
# 41 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFirstMsg_Text_0
# 42 "data/scripts/new_scripts.pory"
	goto EventScript_BidoofFollowerTypicalEnd
	return


EventScript_BidoofFollowerTypicalMsg::
# 46 "data/scripts/new_scripts.pory"
	call EventScript_BidoofFollowerTypicalStart
# 47 "data/scripts/new_scripts.pory"
	setvar VAR_0x8008, FIELD_PIC_BIDOOF_NORMAL
# 48 "data/scripts/new_scripts.pory"
	load_field_pic VAR_0x8008, 78, 107, VAR_0x800A
# 49 "data/scripts/new_scripts.pory"
	random 7
# 50 "data/scripts/new_scripts.pory"
	switch VAR_RESULT
# 51 "data/scripts/new_scripts.pory"
	case 0, EventScript_BidoofFollowerTypicalMsg_3
# 52 "data/scripts/new_scripts.pory"
	case 1, EventScript_BidoofFollowerTypicalMsg_4
# 53 "data/scripts/new_scripts.pory"
	case 2, EventScript_BidoofFollowerTypicalMsg_5
# 54 "data/scripts/new_scripts.pory"
	case 3, EventScript_BidoofFollowerTypicalMsg_6
# 55 "data/scripts/new_scripts.pory"
	case 4, EventScript_BidoofFollowerTypicalMsg_7
# 56 "data/scripts/new_scripts.pory"
	case 5, EventScript_BidoofFollowerTypicalMsg_8
# 57 "data/scripts/new_scripts.pory"
	case 6, EventScript_BidoofFollowerTypicalMsg_9
EventScript_BidoofFollowerTypicalMsg_1:
# 59 "data/scripts/new_scripts.pory"
	goto EventScript_BidoofFollowerTypicalEnd
	return

EventScript_BidoofFollowerTypicalMsg_3:
# 51 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFollowerTypicalMsg_Text_0
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_4:
# 52 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFollowerTypicalMsg_Text_1
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_5:
# 53 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFollowerTypicalMsg_Text_2
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_6:
# 54 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFollowerTypicalMsg_Text_3
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_7:
# 55 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFollowerTypicalMsg_Text_4
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_8:
# 56 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFollowerTypicalMsg_Text_5
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_9:
# 57 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFollowerTypicalMsg_Text_6
	goto EventScript_BidoofFollowerTypicalMsg_1


EventScript_BidoofNoPokemonTalk_Text_0:
# 4 "data/scripts/new_scripts.pory"
	.string "Hmmm? Are you surprised?$"

EventScript_BidoofNoPokemonTalk_Text_1:
# 5 "data/scripts/new_scripts.pory"
	.string "We agreed to form a team.\nThat's true.$"

EventScript_BidoofNoPokemonTalk_Text_2:
# 8 "data/scripts/new_scripts.pory"
	.string "But I'm not going to become one of your,\n"
	.string "so called, 'Party Members'! Especially\l"
	.string "not closed in that weird 'Poke Ball'\l"
	.string "thing!$"

EventScript_BidoofFirstMsg_Text_0:
# 41 "data/scripts/new_scripts.pory"
	.string "Aren't you excited? The adventure is\n"
	.string "calling us!$"

EventScript_BidoofFollowerTypicalMsg_Text_0:
# 51 "data/scripts/new_scripts.pory"
	.string "Let's continue.$"

EventScript_BidoofFollowerTypicalMsg_Text_1:
# 52 "data/scripts/new_scripts.pory"
	.string "Let's go!$"

EventScript_BidoofFollowerTypicalMsg_Text_2:
# 53 "data/scripts/new_scripts.pory"
	.string "Hmm? You want to take a break?$"

EventScript_BidoofFollowerTypicalMsg_Text_3:
# 54 "data/scripts/new_scripts.pory"
	.string "This place is so weird...$"

EventScript_BidoofFollowerTypicalMsg_Text_4:
# 55 "data/scripts/new_scripts.pory"
	.string "Lead the way.$"

EventScript_BidoofFollowerTypicalMsg_Text_5:
# 56 "data/scripts/new_scripts.pory"
	.string "I've got your back.$"

EventScript_BidoofFollowerTypicalMsg_Text_6:
# 57 "data/scripts/new_scripts.pory"
	.string "Yup!$"
