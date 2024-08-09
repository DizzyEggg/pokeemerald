MapFifthLeader_MapScripts::
	.byte 0


Script_HackFifthLeader::
# 4 "data/maps/MapFifthLeader/scripts.pory"
	lockall
# 5 "data/maps/MapFifthLeader/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_OTHER
# 6 "data/maps/MapFifthLeader/scripts.pory"
	special DoPCTurnOnEffect
# 7 "data/maps/MapFifthLeader/scripts.pory"
	playse SE_PC_ON
# 8 "data/maps/MapFifthLeader/scripts.pory"
	goto_if_unset FLAG_FIFTH_LEADER_BEATEN, Script_HackFifthLeader_2
Script_HackFifthLeader_1:
# 41 "data/maps/MapFifthLeader/scripts.pory"
	playse SE_PC_OFF
# 42 "data/maps/MapFifthLeader/scripts.pory"
	special DoPCTurnOffEffect
# 43 "data/maps/MapFifthLeader/scripts.pory"
	releaseall
	end

Script_HackFifthLeader_2:
# 9 "data/maps/MapFifthLeader/scripts.pory"
	goto_if_set FLAG_FIFTH_EXPLAINED, Script_HackFifthLeader_5
# 31 "data/maps/MapFifthLeader/scripts.pory"
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
# 32 "data/maps/MapFifthLeader/scripts.pory"
	msgbox Script_HackFifthLeader_Text_4
# 33 "data/maps/MapFifthLeader/scripts.pory"
	msgbox Script_HackFifthLeader_Text_5
# 34 "data/maps/MapFifthLeader/scripts.pory"
	setflag FLAG_FIFTH_EXPLAINED
# 35 "data/maps/MapFifthLeader/scripts.pory"
	goto Script_HackFifthLeader_StartChallengeAsk
	goto Script_HackFifthLeader_1

Script_HackFifthLeader_5:
# 10 "data/maps/MapFifthLeader/scripts.pory"
Script_HackFifthLeader_StartChallengeAsk:
# 11 "data/maps/MapFifthLeader/scripts.pory"
	msgbox Script_HackFifthLeader_Text_0, MSGBOX_YESNO
# 12 "data/maps/MapFifthLeader/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Script_HackFifthLeader_8
	goto Script_HackFifthLeader_1

Script_HackFifthLeader_8:
# 13 "data/maps/MapFifthLeader/scripts.pory"
	special SavePlayerParty
# 14 "data/maps/MapFifthLeader/scripts.pory"
	callnative ChooseMonsForPCChallenge
# 15 "data/maps/MapFifthLeader/scripts.pory"
	waitstate
# 16 "data/maps/MapFifthLeader/scripts.pory"
	setflag B_FLAG_AI_VS_AI_BATTLE
# 17 "data/maps/MapFifthLeader/scripts.pory"
	trainerbattle_no_intro TRAINER_ROTOM_PC_CHALLENGE, Script_HackFifthLeader_Text_1
# 18 "data/maps/MapFifthLeader/scripts.pory"
	clearflag B_FLAG_AI_VS_AI_BATTLE
# 19 "data/maps/MapFifthLeader/scripts.pory"
	special LoadPlayerParty
# 20 "data/maps/MapFifthLeader/scripts.pory"
	getbyte gBattleOutcome, VAR_RESULT
# 21 "data/maps/MapFifthLeader/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Script_HackFifthLeader_10
# 25 "data/maps/MapFifthLeader/scripts.pory"
	msgbox Script_HackFifthLeader_Text_3
# 26 "data/maps/MapFifthLeader/scripts.pory"
	setflag FLAG_FIFTH_LEADER_BEATEN
	goto Script_HackFifthLeader_1

Script_HackFifthLeader_10:
# 22 "data/maps/MapFifthLeader/scripts.pory"
	msgbox Script_HackFifthLeader_Text_2
	goto Script_HackFifthLeader_1


Script_HackFifthLeader_Text_0:
# 11 "data/maps/MapFifthLeader/scripts.pory"
	.string "Are you ready?$"

Script_HackFifthLeader_Text_1:
# 17 "data/maps/MapFifthLeader/scripts.pory"
	.string "Wow, you did it!$"

Script_HackFifthLeader_Text_2:
# 22 "data/maps/MapFifthLeader/scripts.pory"
	.string "Won't be that easy, hm? Try to think of\n"
	.string "a better team next time!$"

Script_HackFifthLeader_Text_3:
# 25 "data/maps/MapFifthLeader/scripts.pory"
	.string "Awesome work!$"

Script_HackFifthLeader_Text_4:
# 32 "data/maps/MapFifthLeader/scripts.pory"
	.string "…\p"
	.string "Hey! Don't turn me on like that!\p"
	.string "Anyway, welcome challenger! I am the\n"
	.string "first…no, not first. Fifth…I think! I am\l"
	.string "the fifth gym leader! In order to\l"
	.string "proceed, you will need to defeat me.\l"
	.string "However! We won't have a regular battle\l"
	.string "like usual. We'll have a…hmm special kind\l"
	.string "of battle I guess. Let me explain…\p"
	.string "So…\p"
	.string "Ugh, I'm not good with explaining. You\n"
	.string "know what? Screw the script. Basically,\l"
	.string "he wanted to me to be some sort of a\l"
	.string "'cheater' challenge, but with a twist.\l"
	.string "The twist being that it'll be ME\l"
	.string "controlling your Pokemon! Cool stuff,\l"
	.string "huh? I'm sure you were NOT expecting\l"
	.string "this! And that's not all! You will be able\l"
	.string "to choose almost ANY Pokemon in this\l"
	.string "challenge!\p"
	.string "Where's the catch? Well, your team will\n"
	.string "be against 3 legendaries, {COLOR BLUE}Kyogre{COLOR DARK_GRAY},\l"
	.string "{COLOR RED}Groudon{COLOR DARK_GRAY} and {COLOR GREEN}Rayquaza{COLOR DARK_GRAY}. Oh, and you\l"
	.string "cannot choose neither legendary nor\l"
	.string "mythical Pokemon.\p"
	.string "Hmm? You're saying it's not fair? Well,\n"
	.string "who told you it was even supposed to be\l"
	.string "fair! Uff, that's some wall of text\l"
	.string "you've just had to read, huh?$"

Script_HackFifthLeader_Text_5:
# 33 "data/maps/MapFifthLeader/scripts.pory"
	.string "Don't worry, I'm finished. You can\n"
	.string "choose your Pokemon and we can start\l"
	.string "the challenge!$"
