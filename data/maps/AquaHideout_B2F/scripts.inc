.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Eheheh…\p"
	.string "Sei già qui?\n"
	.string "Ti ho sottovalutato!\p"
	.string "Facciamola finita!\p"
	.string "Sono una spanna al di sopra delle\n"
	.string "RECLUTE che hai incontrato finora.\p"
	.string "Veniamo subito al sodo: ti batterò\n"
	.string "senza possibilità di appello!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Eheheh… hai vinto persino contro di me…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Eheheh!\p"
	.string "Mentre me la spassavo con te,\n"
	.string "il nostro CAPO ha finito i preparativi!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Eheheh!\p"
	.string "Il nostro CAPO è già diretto verso\n"
	.string "una grotta in fondo al mare!\p"
	.string "Se hai intenzione di dargli la caccia,\n"
	.string "ti conviene cercare nel grande mare\l"
	.string "oltre ALGHEPOLI.\p"
	.string "Ma credi veramente di riuscire a\n"
	.string "trovarlo? Eheheh!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Ahahah, mi sono stufato di aspettare!\n"
	.string "E mi devi pure una lotta!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Meglio girarsi i pollici…\n"
	.string "che perdere così miseramente…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "CAPO…\n"
	.string "ti ho deluso?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "I pannelli di teletrasferimento sono\n"
	.string "l’orgoglio del nostro RIFUGIO!\p"
	.string "Non hai la più pallida idea di dove\n"
	.string "ti trovi, giusto?\p"
	.string "Confondi e sfinisci il nemico, e poi vai\n"
	.string "a segno! Questa è la nostra strategia!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Ma chi sei?\n"
	.string "Non conosci la fatica!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "A proposito… non ricordo più\n"
	.string "dove ho messo la MASTER BALL.\p"
	.string "Se la perdo di vista, il nostro CAPO\n"
	.string "mi mangia viva!$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Quando mi sono unito al TEAM IDRO,\n"
	.string "per prima cosa ho imparato a attivare\l"
	.string "i pannelli di teletrasferimento.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Ero troppo impegnato a pensare ai\n"
	.string "pannelli di teletrasferimento…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Devo imparare a lottare in modo\n"
	.string "più efficace…$"
