EventScript_BidoofNoPokemonTalk::
# 2 "data/scripts/new_scripts.pory"
	lockall
# 3 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofNoPokemonTalk_Text_0, FIELD_PIC_BIDOOF_NORMAL
# 4 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofNoPokemonTalk_Text_1, FIELD_PIC_BIDOOF_ASTONISHED
# 5 "data/scripts/new_scripts.pory"
	setflag FLAG_BIDOOF_NO_POKES_COMMENT
# 6 "data/scripts/new_scripts.pory"
	releaseall
	end


EventScript_BidoofFirstMsg::
# 11 "data/scripts/new_scripts.pory"
	lock
# 12 "data/scripts/new_scripts.pory"
	faceplayer
# 13 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFirstMsg_Text_0, FIELD_PIC_BIDOOF_NORMAL
# 14 "data/scripts/new_scripts.pory"
	addvar VAR_BIDOOF_FOLLOWER_NO_TALKS, 1
# 15 "data/scripts/new_scripts.pory"
	waitmessage
	return


EventScript_BidoofFollowerTypicalMsg::
# 20 "data/scripts/new_scripts.pory"
	lock
# 21 "data/scripts/new_scripts.pory"
	faceplayer
# 22 "data/scripts/new_scripts.pory"
	random 7
# 23 "data/scripts/new_scripts.pory"
	switch VAR_RESULT
# 24 "data/scripts/new_scripts.pory"
	case 0, EventScript_BidoofFollowerTypicalMsg_3
# 25 "data/scripts/new_scripts.pory"
	case 1, EventScript_BidoofFollowerTypicalMsg_4
# 26 "data/scripts/new_scripts.pory"
	case 2, EventScript_BidoofFollowerTypicalMsg_5
# 27 "data/scripts/new_scripts.pory"
	case 3, EventScript_BidoofFollowerTypicalMsg_6
# 28 "data/scripts/new_scripts.pory"
	case 4, EventScript_BidoofFollowerTypicalMsg_7
# 29 "data/scripts/new_scripts.pory"
	case 5, EventScript_BidoofFollowerTypicalMsg_8
# 30 "data/scripts/new_scripts.pory"
	case 6, EventScript_BidoofFollowerTypicalMsg_9
EventScript_BidoofFollowerTypicalMsg_1:
# 32 "data/scripts/new_scripts.pory"
	addvar VAR_BIDOOF_FOLLOWER_NO_TALKS, 1
# 33 "data/scripts/new_scripts.pory"
	waitmessage
	return

EventScript_BidoofFollowerTypicalMsg_3:
# 24 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_0, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_4:
# 25 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_1, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_5:
# 26 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_2, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_6:
# 27 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_3, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_7:
# 28 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_4, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_8:
# 29 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_5, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1

EventScript_BidoofFollowerTypicalMsg_9:
# 30 "data/scripts/new_scripts.pory"
	msgbox_portrait EventScript_BidoofFollowerTypicalMsg_Text_6, FIELD_PIC_BIDOOF_NORMAL
	goto EventScript_BidoofFollowerTypicalMsg_1


EventScript_BidoofNoPokemonTalk_Text_0:
# 3 "data/scripts/new_scripts.pory"
	.string "Hmmm? Are you surprised?\pWe agreed to form a team.\nThat's true.$"

EventScript_BidoofNoPokemonTalk_Text_1:
# 4 "data/scripts/new_scripts.pory"
	.string "But I'm not going to become one of your,\n"
	.string "so called, 'Party Members'! Especially\l"
	.string "not closed in that weird 'Poke Ball'\l"
	.string "thing!$"

EventScript_BidoofFirstMsg_Text_0:
# 13 "data/scripts/new_scripts.pory"
	.string "Aren't you excited? The adventure is\n"
	.string "calling us!$"

EventScript_BidoofFollowerTypicalMsg_Text_0:
# 24 "data/scripts/new_scripts.pory"
	.string "Let's continue.$"

EventScript_BidoofFollowerTypicalMsg_Text_1:
# 25 "data/scripts/new_scripts.pory"
	.string "Let's go!$"

EventScript_BidoofFollowerTypicalMsg_Text_2:
# 26 "data/scripts/new_scripts.pory"
	.string "Hmm? You want to take a break?$"

EventScript_BidoofFollowerTypicalMsg_Text_3:
# 27 "data/scripts/new_scripts.pory"
	.string "This place is so weird…$"

EventScript_BidoofFollowerTypicalMsg_Text_4:
# 28 "data/scripts/new_scripts.pory"
	.string "Lead the way.$"

EventScript_BidoofFollowerTypicalMsg_Text_5:
# 29 "data/scripts/new_scripts.pory"
	.string "I've got your back.$"

EventScript_BidoofFollowerTypicalMsg_Text_6:
# 30 "data/scripts/new_scripts.pory"
	.string "Yup!$"

gText_BidoofTalkDuringGlitchIntro::
# 37 "data/scripts/new_scripts.pory"
	.string "Golly! What a mess! I guess you didn't\n"
	.string "expect to see me here, {PLAYER}…Well,\l"
	.string "I didn't expect to see…THIS, whatever\l"
	.string "it is. Suicune really knew what he was\l"
	.string "talking about, huh? Maybe I should've\l"
	.string "listened to him…Well, it's too late now\l"
	.string "anyway. Listen, {PLAYER}. I'll try to\l"
	.string "get us out of this mess.\p"
	.string "How? Well, uhm…\p"
	.string "There MUST be some way out, right? I'm\n"
	.string "sure{PAUSE 25} that once the intro finishes, we$"
