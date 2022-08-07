MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Non ho nessun conto in sospeso con te.\n"
	.string "Eseguo solo gli ordini!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Sì, ho perso, però…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Scavando abbiamo trovato qualcosa\n"
	.string "di incredibile. Abbiamo la SFERA BLU!\p"
	.string "E il resto è per il nostro CAPO…\n"
	.string "Fufufu… ahahah!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Non sopporto il calore. Forse avrei\n"
	.string "dovuto unirmi al TEAM IDRO…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "E sì, sembra proprio che il TEAM MAGMA\n"
	.string "non faccia per me…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Non rimpiangi il mare in un posto\n"
	.string "come questo?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "A volte si sentono delle scosse qui.\p"
	.string "Sarà il vulcano?\n"
	.string "Oppure sarà GROU…\p"
	.string "Oops!\n"
	.string "Dimentica ciò che ho detto!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Lotti in modo superbo.\n"
	.string "Sei un vulcano!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Vabbè, non importa se hai vinto\n"
	.string "questa volta.\p"
	.string "L’obiettivo del TEAM MAGMA è\n"
	.string "ormai raggiunto!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Uno dei nostri non faceva che urlare di\n"
	.string "aver perso il suo STEMMA MAGMA…\p"
	.string "Un attimo!\n"
	.string "L’hai trovato tu?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Non posso crederci…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Ho la strana sensazione che il nostro\n"
	.string "piano fallirà…$"

