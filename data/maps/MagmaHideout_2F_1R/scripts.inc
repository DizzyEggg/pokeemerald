MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Cosa, cosa, cosa?\p"
	.string "Qui ci dovrebbero essere solo i\n"
	.string "membri del TEAM MAGMA!\p"
	.string "Tu non indossi l’uniforme del\n"
	.string "TEAM MAGMA…\p"
	.string "Sei un tipo sospetto!\n"
	.string "Lottiamo!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Ahi ahi… il mio orgoglio\n"
	.string "di membro del TEAM MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Se soffri il freddo, dovresti unirti al\n"
	.string "TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Aspetta!\p"
	.string "Non penserai che ti lasci passare\n"
	.string "come niente fosse?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Wow!\n"
	.string "Ti cedo il passo!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Sarebbe stato meglio se non ti avessi\n"
	.string "sfidato…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ah!\n"
	.string "Un intruso!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Ho già perso.\p"
	.string "Perché continuo a girare in tondo?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh!\n"
	.string "Un intruso!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Grrr…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "La lotta non è mai stata il mio forte…$"

