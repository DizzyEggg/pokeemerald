DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM08, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM08
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM08
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Ehi, cosa mi racconti, {PLAYER},\n"
	.string "futuro CAMPIONE?\p"
	.string "Il CAPOPALESTRA di BLURUVIA, RUDI,\n"
	.string "allena POKéMON di tipo LOTTA.\p"
	.string "Se lotti contro di lui con POKéMON di\n"
	.string "tipo NORMALE, sei nei guai.\p"
	.string "I POKéMON di tipo LOTTA sono molto\n"
	.string "efficaci contro i POKéMON di tipo\l"
	.string "NORMALE!\p"
	.string "Fai attenzione! Anche perché in\n"
	.string "questa PALESTRA è buio pesto.\p"
	.string "Tuttavia, diventerà sempre più chiaro\n"
	.string "man mano che sconfiggi gli ALLENATORI!\p"
	.string "Forza, allora, dacci dentro!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Ehi! È fin troppo chiaro qui dentro!\p"
	.string "Anche il tuo futuro splende!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "La potenza è giustizia!\n"
	.string "Fatti sotto!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "La potenza non è mai abbastanza…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "La tua bravura supera la mia forza!\n"
	.string "Hai una tecnica encomiabile!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Non c’è bisogno di scomodare RUDI!\p"
	.string "Ti anniento io!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Ma… come?\n"
	.string "Come ho potuto perdere così?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Farò tesoro di questa lezione.\n"
	.string "Mi servirà come motivazione!\p"
	.string "Un giorno diventerò CAPOPALESTRA…\p"
	.string "Anzi no, diventerò CAMPIONE della\n"
	.string "LEGA POKéMON!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Non osare snobbarmi!\n"
	.string "Te ne pentirai!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Nooooooo!\n"
	.string "Ho perso!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Lotto nel buio per aumentare\n"
	.string "il mio coraggio!\p"
	.string "Ma, a causa del buio, non ho mai\n"
	.string "visto RUDI in faccia…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu… stai brancolando nel buio?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Ehi! Chi ti vuole conoscere!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Ti meriti di perdere la via e di\n"
	.string "ritrovarti all’entrata!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Noi uomini di mare abbiamo grinta.\n"
	.string "Adesso te lo dimostro!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Com’è potuto succedere?\n"
	.string "Non è nel mio stile perdere così!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Ehi! Ti meriti di incontrare\n"
	.string "il nostro CAPOPALESTRA.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Per passare devi superare un ostacolo,\n"
	.string "vale a dire il sottoscritto!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Mi hai sopraffatto!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Hai vinto!\n"
	.string "Adesso vuoi anche la MEDAGLIA?!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Sono RUDI!\n"
	.string "Il CAPOPALESTRA di BLURUVIA!\p"
	.string "Ho l’irruenza delle onde maestose\n"
	.string "della zona e mi sono fatto le ossa\l"
	.string "nella grotta buia!\p"
	.string "Hai intenzione di sfidarmi?\n"
	.string "Fammi vedere cosa sai fare!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Ehi! Hai superato ogni mia aspettativa!\p"
	.string "Mi hai travolto!\p"
	.string "Sto brancolando nel buio…\n"
	.string "Prendi la MEDAGLIA di questa PALESTRA!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} riceve la MEDAGLIA PUGNO\n"
	.string "da RUDI.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "Con la MEDAGLIA PUGNO ti obbediranno\n"
	.string "tutti i POKéMON fino al livello 30, anche\l"
	.string "quelli ottenuti da uno scambio.\p"
	.string "Inoltre, potrai usare la mossa MN\n"
	.string "FLASH anche fuori dalla lotta.\p"
	.string "Infine, se vuoi, potrai usare anche\n"
	.string "questa MACCHINA TECNICA.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "La MT08 contiene GRANFISICO.\p"
	.string "Si tratta di una mossa che aumenta\n"
	.string "le statistiche d’ATTACCO e di DIFESA.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Registrazione del CAPOPALESTRA RUDI\n"
	.string "nel POKéNAV avvenuta.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Vedo il tuo talento diventare un’onda\n"
	.string "gigante e causare un giorno una bufera\l"
	.string "di sbigottimento tra gli ALLENATORI!$"

DewfordTown_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON di BLURUVIA$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di BLURUVIA\p"
	.string "ALLENATORE CERTIFICATO da RUDI:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "RUDI: Un’onda si ritira, ma prima o poi\n"
	.string "ritorna sempre alla riva.\p"
	.string "Sapevo che un’onda gigante di talento\n"
	.string "come te sarebbe tornata!\p"
	.string "Fammi vedere quali altezze hai\n"
	.string "raggiunto!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Wow!\n"
	.string "Mi hai travolto di nuovo!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "RUDI: La lotta è vasta e profonda.\n"
	.string "Non ne vedi mai il fondo. Come il\l"
	.string "mare della regione di HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "RUDI: Un’onda si ritira, ma prima o poi\n"
	.string "ritorna sempre alla riva.\p"
	.string "Sapevo che un’onda gigante di talento\n"
	.string "come te sarebbe tornata!\p"
	.string "Oh? Hai solo un POKéMON da\n"
	.string "mandare in campo.\p"
	.string "Spiacente. Devi tornare con almeno\n"
	.string "due POKéMON.$"
