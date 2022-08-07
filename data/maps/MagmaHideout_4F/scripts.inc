.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Vorrei anch’io vedere GROUDON, ma non\n"
	.string "mi fanno vedere neppure la coda…\p"
	.string "Che frustrazione.\p"
	.string "Oh, no! Mi è sfuggito!\n"
	.string "Non dovevo parlare di GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Penso che sia impossibile vincere\n"
	.string "se non si è tranquilli…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Ma GROUDON ce l’avrà la coda?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Ahahah!\n"
	.string "Manca poco! Pochissimo!\l"
	.string "E il nostro obiettivo sarà raggiunto!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr… sono arrivato fin qui solo\n"
	.string "per questo?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAX, signore!\n"
	.string "Un intruso si dirige verso di voi!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Dove vuoi scappare?!\n"
	.string "Io sono un osso duro!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "È stato così facile battermi?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "Dai, ancora una sfida…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Eheheh! Hai fatto tanta strada per\n"
	.string "arrivare fin qui. Te lo dirò!\p"
	.string "Sì!\n"
	.string "GROUDON sta dormendo laggiù!\p"
	.string "MAX è andato da GROUDON pochi\n"
	.string "minuti fa!\p"
	.string "Si sveglierà fra un attimo!\n"
	.string "Eheh! Eheheh!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Sconfitto ancora una volta!\n"
	.string "Eheh…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "Mentre tu perdevi tempo qui\n"
	.string "con me, MAX è andato a svegliare\l"
	.string "GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAX: GROUDON…\p"
	.string "Te ne stai lì cullato dal magma e niente\n"
	.string "potrebbe svegliarti dal tuo sonno…\p"
	.string "La SFERA BLU è quello che cercavi,\n"
	.string "non è vero?\p"
	.string "Ti ho portato la SFERA BLU.\n"
	.string "Il suo splendore ti sveglierà!\p"
	.string "Fammi vedere…\n"
	.string "fammi vedere la tua potenza!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAX: GROUDON!\n"
	.string "Che succede?\p"
	.string "Non ci voleva la SFERA BLU?\p"
	.string "GROUDON!\n"
	.string "Dove sei andato…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAX: È stata colpa tua allora?\p"
	.string "Ho visto che ti aggiravi da queste\n"
	.string "parti. La tua presenza non è gradita.\p"
	.string "Ci sono! Devi aver usato\n"
	.string "un trucchetto!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Da dove ti viene questa abilità con\n"
	.string "i POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAX: Deve esserci un motivo per cui\n"
	.string "GROUDON è fuggito…\p"
	.string "È questo che vuoi dire?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Mmm… pensavi che non lo sapessi?\p"
	.string "Visto che GROUDON se ne è andato,\n"
	.string "questo vulcano non serve più a nulla.\p"
	.string "Le nostre strade si dividono qui.\n"
	.string "Io devo inseguire GROUDON.$"
