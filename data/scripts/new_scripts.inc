EventScript_BidoofNoPokemonTalk::
# 2 "data/scripts/new_scripts.pory"
	lockall
# 3 "data/scripts/new_scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_NORMAL, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 4 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofNoPokemonTalk_Text_0
# 5 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofNoPokemonTalk_Text_1
# 6 "data/scripts/new_scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_NORMAL
# 7 "data/scripts/new_scripts.pory"
	load_field_pic FIELD_PIC_BIDOOF_ASTONISHED, MSG_PORTRAIT_X, MSG_PORTRAIT_Y
# 8 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofNoPokemonTalk_Text_2
# 9 "data/scripts/new_scripts.pory"
	destroy_field_pic FIELD_PIC_BIDOOF_ASTONISHED
# 10 "data/scripts/new_scripts.pory"
	setflag FLAG_BIDOOF_NO_POKES_COMMENT
# 11 "data/scripts/new_scripts.pory"
	releaseall
	end


EventScript_BidoofFirstMsg::
# 19 "data/scripts/new_scripts.pory"
	lock
# 20 "data/scripts/new_scripts.pory"
	faceplayer
# 21 "data/scripts/new_scripts.pory"
	setvar VAR_0x8008, FIELD_PIC_BIDOOF_NORMAL
# 22 "data/scripts/new_scripts.pory"
	load_field_pic VAR_0x8008, MSG_PORTRAIT_X, MSG_PORTRAIT_Y, VAR_0x800A
# 23 "data/scripts/new_scripts.pory"
	msgbox EventScript_BidoofFirstMsg_Text_0
# 24 "data/scripts/new_scripts.pory"
	addvar VAR_BIDOOF_FOLLOWER_NO_TALKS, 1
# 25 "data/scripts/new_scripts.pory"
	waitmessage
	return


EventScript_BidoofFollowerTypicalMsg::
# 30 "data/scripts/new_scripts.pory"
	lock
# 31 "data/scripts/new_scripts.pory"
	faceplayer
# 32 "data/scripts/new_scripts.pory"
	random 7
# 33 "data/scripts/new_scripts.pory"
	switch VAR_RESULT
# 34 "data/scripts/new_scripts.pory"
	case 0, EventScript_BidoofFollowerTypicalMsg_3
# 35 "data/scripts/new_scripts.pory"
	case 1, EventScript_BidoofFollowerTypicalMsg_4
# 36 "data/scripts/new_scripts.pory"
	case 2, EventScript_BidoofFollowerTypicalMsg_5
# 37 "data/scripts/new_scripts.pory"
	case 3, EventScript_BidoofFollowerTypicalMsg_6
# 38 "data/scripts/new_scripts.pory"
	case 4, EventScript_BidoofFollowerTypicalMsg_7
# 39 "data/scripts/new_scripts.pory"
	case 5, EventScript_BidoofFollowerTypicalMsg_8
# 40 "data/scripts/new_scripts.pory"
	case 6, EventScript_BidoofFollowerTypicalMsg_9
EventScript_BidoofFollowerTypicalMsg_1:
# 42 "data/scripts/new_scripts.pory"
	addvar VAR_BIDOOF_FOLLOWER_NO_TALKS, 1
# 43 "data/scripts/new_scripts.pory"
	waitmessage
	return

EventScript_BidoofFollowerTypicalMsg_3:
# 34 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_0, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_4:
# 35 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_1, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_5:
# 36 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_2, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_6:
# 37 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_3, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_7:
# 38 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_4, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_8:
# 39 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_5, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_9:
# 40 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_6, FIELD_PIC_BIDOOF_NORMAL
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
# 23 "data/scripts/new_scripts.pory"
	.string "Aren't you excited? The adventure is\n"
	.string "calling us!$"

EventScript_BidoofFollowerTypicalMsg_Text_0:
# 34 "data/scripts/new_scripts.pory"
	.string "Let's continue.$"

EventScript_BidoofFollowerTypicalMsg_Text_1:
# 35 "data/scripts/new_scripts.pory"
	.string "Let's go!$"

EventScript_BidoofFollowerTypicalMsg_Text_2:
# 36 "data/scripts/new_scripts.pory"
	.string "Hmm? You want to take a break?$"

EventScript_BidoofFollowerTypicalMsg_Text_3:
# 37 "data/scripts/new_scripts.pory"
	.string "This place is so weird...$"

EventScript_BidoofFollowerTypicalMsg_Text_4:
# 38 "data/scripts/new_scripts.pory"
	.string "Lead the way.$"

EventScript_BidoofFollowerTypicalMsg_Text_5:
# 39 "data/scripts/new_scripts.pory"
	.string "I've got your back.$"

EventScript_BidoofFollowerTypicalMsg_Text_6:
# 40 "data/scripts/new_scripts.pory"
	.string "Yup!$"
