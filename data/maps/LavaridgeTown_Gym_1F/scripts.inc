.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM50, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM50
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM50
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Ehi, come va futuro CAMPIONE,\n"
	.string "{PLAYER}?\p"
	.string "Il CAPOPALESTRA di CUORDILAVA,\n"
	.string "FIAMMETTA, usa POKéMON di tipo FUOCO.\p"
	.string "La sua passione per i POKéMON brucia\n"
	.string "più ardente di un vulcano.\p"
	.string "Se ti avvicini troppo, ti brucerai!\n"
	.string "Getta acqua sul fuoco!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Wow! Questa sì che è stata una lotta \n"
	.string "infuocata!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Ohohohoh!\n"
	.string "Ahi, come scotta!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Il sudore negli occhi mi acceca…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Le sabbiature favoriscono\n"
	.string "la circolazione.\p"
	.string "Fanno bene per le articolazioni\n"
	.string "doloranti.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Sto cercando di alleviare lo stress.\n"
	.string "Non venire a peggiorare la situazione!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Spero che FIAMMETTA ti rosoli per bene!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Ahaaa… che caldo…\p"
	.string "Se passi troppo tempo nella sabbia\n"
	.string "bollente, ti assale la stanchezza…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Non senti ancora la stanchezza?\n"
	.string "Non vuoi riposarti un po’ nella sabbia\l"
	.string "bollente?\p"
	.string "Dovresti sapere che mantenere la forza\n"
	.string "di volontà è molto importante per\l"
	.string "qualsiasi ALLENATORE.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Gioca col fuoco e ti brucerai…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Hai talento… ma il nostro CAPOPALESTRA\n"
	.string "FIAMMETTA è forte.\p"
	.string "Se non fai attenzione, potrebbe essere\n"
	.string "un’esperienza scottante!$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "I tuoi POKéMON resistono ad\n"
	.string "una temperatura di 200 gradi?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Non scottava abbastanza…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "La temperatura del magma è di\n"
	.string "200 gradi.\p"
	.string "I tuoi POKéMON mi hanno battuto,\n"
	.string "quindi resistono al magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Ehm… ok, lotterò con te.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, ma sei troppo forte…$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Diventerò bella e forte proprio come\n"
	.string "FIAMMETTA.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Forza!\n"
	.string "Lottiamo prima che mi raffreddi!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Fa così caldo, ma il mio cuore\n"
	.string "è un ghiacciolo…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Lotti con tale ardore che anche\n"
	.string "il nostro CAPOPALESTRA potrebbe\l"
	.string "prendersi una scottatura.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Vedi come divampano le fiamme? \n"
	.string "Attendo con ardore la mia vittoria!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Qualcosa non ha funzionato.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Beh, allora? Io cammino a piedi\n"
	.string "nudi sui carboni ardenti!\p"
	.string "Tu non provarci nemmeno!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Adoro la montagna. I vulcani sono\n"
	.string "la mia passione.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "La situazione mi è scappata di mano e\n"
	.string "ho perso.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Ho deciso di rimanere qui perché\n"
	.string "FIAMMETTA mi ha ammaliato.\p"
	.string "Eheheheh.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Allora mi hai raggiunto… no, aspetta!\p"
	.string "ALLENATORE in erba, che bello vedere\n"
	.string "che hai trovato la strada fin qui!\p"
	.string "In qualità di…\n"
	.string "No, aspetta!\p"
	.string "Sono FIAMMETTA e in questa sede sono\n"
	.string "il CAPOPALESTRA!\p"
	.string "Mhmm…\n"
	.string "Non osare sottovalutarmi, nonostante\l"
	.string "sia CAPOPALESTRA solo da poco!\p"
	.string "Con le abilità ereditate da mio nonno,\n"
	.string "ehm, ti mostrerò mosse infuocate\l"
	.string "assai raffinate!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Allora sei più forte di me…\p"
	.string "Io… sono diventata CAPOPALESTRA\n"
	.string "soltanto da poco.\p"
	.string "Ho tentato di misurarmi con qualcuno\n"
	.string "ancora troppo forte per me.\p"
	.string "Se non lotto secondo le mie forze,\n"
	.string "i miei POKéMON si confonderanno.\p"
	.string "Grazie per avermelo insegnato. Ti\n"
	.string "regalo questo in segno di gratitudine.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} riceve la MEDAGLIA FIAMMA\n"
	.string "da FIAMMETTA.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Con la MEDAGLIA FIAMMA ti obbediranno\n"
	.string "tutti i POKéMON fino al livello 50, anche\l"
	.string "quelli ottenuti da uno scambio.\p"
	.string "Inoltre, potrai usare la mossa MN\n"
	.string "FORZA anche fuori dalla lotta.\p"
	.string "Ecco il segno della mia gratitudine.\n"
	.string "Sono felice di averti conosciuto!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "La MT50 contiene VAMPATA.\p"
	.string "Questa mossa infligge un duro colpo\n"
	.string "all’avversario.\p"
	.string "Ma riduce drasticamente l’ATT. SP.\n"
	.string "del POKéMON che la usa. Non è molto\l"
	.string "adatta a lotte prolungate.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Registrazione del CAPOPALESTRA\n"
	.string "FIAMMETTA nel POKéNAV avvenuta.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "La tua forza mi ricorda qualcuno…\p"
	.string "Oh! Ora ho capito! Lotti come NORMAN,\n"
	.string "il CAPOPALESTRA di PETALIPOLI.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "PALESTRA POKéMON di CUORDILAVA$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di CUORDILAVA\p"
	.string "ALLENATORE CERTIFICATO da FIAMMETTA:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FIAMMETTA: Non mi demoralizzo perché\n"
	.string "ho perso una lotta.\p"
	.string "Adoro i POKéMON.\n"
	.string "Amo la lotta.\l"
	.string "Questa PALESTRA è tutta la mia vita!\p"
	.string "Scambiamoci mosse arroventate\n"
	.string "in un’altra lotta!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Ahh!\n"
	.string "Sto per scoppiare!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FIAMMETTA: Ho perso la lotta, ma\n"
	.string "sono pienamente soddisfatta.\p"
	.string "Non capita tutti i giorni di lottare\n"
	.string "con tanto ardore.\p"
	.string "Spero di lottare ancora con te\n"
	.string "in questo modo!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FIAMMETTA: Non mi demoralizzo perché\n"
	.string "ho perso una lotta.\p"
	.string "Adoro i POKéMON.\n"
	.string "Amo la lotta.\l"
	.string "Questa PALESTRA è tutta la mia vita!\p"
	.string "Scambiamoci mosse arroventate\n"
	.string "in un’altra lotta!\p"
	.string "Aspetta. Hai solo un POKéMON da\n"
	.string "mandare in campo?\p"
	.string "Mi dispiace dovertelo dire, ma devi\n"
	.string "portare almeno due POKéMON.$"
