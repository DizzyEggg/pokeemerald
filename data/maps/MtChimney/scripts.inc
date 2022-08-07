.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "L’energia contenuta nel METEORITE…\p"
	.string "Amplificando la sua energia con questa\n"
	.string "macchina, l’attività vulcanica del MONTE\l"
	.string "CAMINO aumenterà esponenzialmente…\p"
	.string "L’energia nel cratere si farà sempre\n"
	.string "più intensa e…\l"
	.string "fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MAX: Eh?\n"
	.string "E tu chi sei?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ho sentito IVAN lamentarsi di un\n"
	.string "ALLENATORE in tenera età che voleva\l"
	.string "intralciare i piani del TEAM IDRO.\p"
	.string "Si riferiva a te, credo.\p"
	.string "E così vuoi intrometterti anche negli\n"
	.string "affari del TEAM MAGMA?\p"
	.string "Ascoltami bene.\n"
	.string "Tempo fa, tutti gli esseri vivevano\l"
	.string "e prosperavano sulla terra.\p"
	.string "La terra è importante perché è\n"
	.string "la culla della vita.\p"
	.string "Per questo motivo il TEAM MAGMA\n"
	.string "vuole espandere la terraferma.\p"
	.string "Gli esseri umani e i POKéMON ne\n"
	.string "trarranno un gran vantaggio!\p"
	.string "Per raggiungere il nostro obiettivo,\n"
	.string "abbiamo bisogno di ciò che\l"
	.string "questa montagna nasconde…\p"
	.string "Ma perché sto a raccontarti tutto\n"
	.string "questo?\p"
	.string "Adesso ti faccio vedere cosa succede\n"
	.string "a chi si intromette nel nostro piano.$"

MtChimney_Text_MaxieDefeat:
	.string "Che cosa?!\p"
	.string "Io, MAX, sono stato preso\n"
	.string "alla sprovvista?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAX: Ne ho avuto abbastanza.\n"
	.string "Per questa volta mi ritiro.\p"
	.string "Sentirai ancora parlare del\n"
	.string "TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Anche senza il METEORITE, dobbiamo\n"
	.string "mettere le mani su quella SFERA…$"

MtChimney_Text_TabithaIntro:
	.string "Eheheh!\p"
	.string "Ne hai fatta di strada!\p"
	.string "Ma sei in ritardo! Il METEORITE\n"
	.string "proveniente dalle CASCATE METEORA\l"
	.string "è già stato consegnato al CAPO!$"

MtChimney_Text_TabithaDefeat:
	.string "Eheheh…\p"
	.string "Ho perso, ma se il nostro CAPO\n"
	.string "risvegliasse quel…$"

MtChimney_Text_TabithaPostBattle:
	.string "Sbrigati, CAPO!\n"
	.string "Dagli l’energia del METEORITE!\p"
	.string "Eheheh…$"

MtChimney_Text_Grunt2Intro:
	.string "Noi del TEAM MAGMA ci impegniamo\n"
	.string "per il bene di tutti.\p"
	.string "Se il potere di quel coso creasse\n"
	.string "altra terra, ci sarebbe più spazio\l"
	.string "per vivere.\p"
	.string "E tutti sarebbero felici!$"

MtChimney_Text_Grunt2Defeat:
	.string "Uh? Non vorrà mica dire\n"
	.string "che ho perso?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Il nostro CAPO dice: “Tutti saranno\n"
	.string "più felici”.\p"
	.string "Allora perché cercano di metterci\n"
	.string "i bastoni tra le ruote?$"

MtChimney_Text_Grunt1Intro:
	.string "Se ci fosse più terraferma, potrei avere\n"
	.string "una casa grande tutta per me!\p"
	.string "La costruirei sulla lava indurita!$"

MtChimney_Text_Grunt1Defeat:
	.string "Il mio sogno di una grande casa…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Una persona giovane come te dovrebbe\n"
	.string "stare a giocare fra le onde!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Quei noiosi del TEAM IDRO…\n"
	.string "si intromettono sempre nei nostri piani!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "I METEORITI racchiudono un’enorme\n"
	.string "energia!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Non ficcare il naso nei nostri affari!\p"
	.string "Vogliamo risvegliare quel coso\n"
	.string "per il bene di tutti!$"

MtChimney_Text_AquasNameSimilar:
	.string "Noi siamo il TEAM MAGMA!\p"
	.string "Loro sono il TEAM IDRO!\p"
	.string "Non sopporto che usino un nome\n"
	.string "simile al nostro!$"

MtChimney_Text_DouseThemInFire:
	.string "Sìììì! Impareranno a non scherzare\n"
	.string "col fuoco!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Creeremo sempre più terraferma!$"

MtChimney_Text_Bufoh:
	.string "Maagmaa!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "IVAN: Grrr, {PLAYER}! Avrei dovuto\n"
	.string "immaginare di vederti qui!\p"
	.string "Guarda con i tuoi occhi cosa vogliono\n"
	.string "fare quei fanatici del TEAM MAGMA!\p"
	.string "Vogliono convogliare nel vulcano\n"
	.string "l’energia del METEORITE rubato!\p"
	.string "Una cosa del genere provocherà\n"
	.string "un’eruzione!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "IVAN: Grrr…\p"
	.string "Vorrei fermare quel MAX,\n"
	.string "ma non ci riesco.\p"
	.string "Almeno fintanto che sono impegnato\n"
	.string "a lottare contro tre rivali alla volta!$"

MtChimney_Text_ArchieThankYou:
	.string "IVAN: {PLAYER}!\n"
	.string "Grazie!\p"
	.string "Con il tuo aiuto, siamo riusciti a\n"
	.string "sventare i piani del TEAM MAGMA!\p"
	.string "Ma… tu… da che parte stai?\p"
	.string "Non importa.\p"
	.string "Resteremo in guardia e continueremo\n"
	.string "a dare la caccia al TEAM MAGMA.\p"
	.string "{PLAYER}, ci incontreremo ancora!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Oops… il TEAM MAGMA è in superiorità!\n"
	.string "Non possiamo tenergli testa!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Se espandono la terraferma, ci saranno\n"
	.string "meno habitat per i POKéMON d’ACQUA!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Noi siamo il TEAM IDRO!\p"
	.string "Loro sono il TEAM MAGMA!\p"
	.string "Ma perché usano un nome\n"
	.string "così strano?$"

MtChimney_Text_Bushaa:
	.string "Iiiidrooo!$"

MtChimney_Text_LavaCookiesJust200:
	.string "I LAVOTTINI sono la specialità locale\n"
	.string "del MONTE CAMINO.\p"
	.string "Vuoi provarne uno? Costa solo ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Grazie, tesoro!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Tesorino, non si può comprare qualcosa\n"
	.string "senza avere soldi a sufficienza.$"

MtChimney_Text_OhFineThen:
	.string "Oh, va bene lo stesso.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "Un METEORITE è inserito in una macchina\n"
	.string "misteriosa…\p"
	.string "La macchina sembra trasmettere energia\n"
	.string "al METEORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Un METEORITE è inserito in una macchina\n"
	.string "misteriosa…\p"
	.string "Vuoi rimuovere il METEORITE?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} rimuove il METEORITE dalla\n"
	.string "macchina misteriosa.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} lascia il METEORITE dov’è.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Questa macchina misteriosa…\n"
	.string "non dà segni di vita.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} PASSO SELVAGGIO\n"
	.string "PER CUORDILAVA SEMPRE DRITTO$"

MtChimney_Text_ShelbyIntro:
	.string "Sono stata alle sorgenti termali\n"
	.string "per riposare le mie ossa stanche.\l"
	.string "Ora mi sento totalmente rigenerata!$"

MtChimney_Text_ShelbyDefeat:
	.string "Complimenti! Non bisogna prenderti\n"
	.string "alla leggera!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Ok, ok, ho perso. Non merito più\n"
	.string "l’appellativo di SPECIALISTA, giusto?$"

MtChimney_Text_ShelbyRegister:
	.string "Grazie, tesoro! Mi hai fatto ricordare\n"
	.string "la mia giovinezza.\p"
	.string "Torna a trovarmi per la\n"
	.string "rivincita.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Se riesci a fondere il tuo cuore con\n"
	.string "quello dei tuoi POKéMON, potrai\l"
	.string "realizzare cose fantastiche.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Complimenti! Non bisogna prenderti\n"
	.string "alla leggera!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Forse il tuo cuore batte all’unisono\n"
	.string "con quello dei tuoi POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "Il fuoco arde in me!\n"
	.string "Sto scoppiando, devo lottare!$"

MtChimney_Text_MelissaDefeat:
	.string "Ooh, che lotta incandescente!$"

MtChimney_Text_MelissaPostBattle:
	.string "Il calore del MONTE CAMINO mi infiamma!$"

MtChimney_Text_SheilaIntro:
	.string "Eccomi finalmente al MONTE CAMINO. \n"
	.string "Ora voglio lottare con il mio POKéMON!$"

MtChimney_Text_SheilaDefeat:
	.string "Nella lotta non ti ferma nessuno,\n"
	.string "sembri un’eruzione del MONTE CAMINO!$"

MtChimney_Text_SheilaPostBattle:
	.string "Come già detto, finalmente sono giunta\n"
	.string "al MONTE CAMINO. Sarebbe un peccato\l"
	.string "fare solo la turista…\p"
	.string "Voglio lanciarmi in sfide e comprare\n"
	.string "i LAVOTTINI come souvenir.$"

MtChimney_Text_ShirleyIntro:
	.string "Da quando ho fatto il bagno nelle\n"
	.string "sorgenti termali, sto che è una\l"
	.string "meraviglia! Ho la vittoria in pugno!$"

MtChimney_Text_ShirleyDefeat:
	.string "Ahhh! Che sconfitta cocente!$"

MtChimney_Text_ShirleyPostBattle:
	.string "Vado ad immergermi ancora nelle\n"
	.string "sorgenti termali. Vuoi venire anche tu?\p"
	.string "Fa bene alla pelle!$"

MtChimney_Text_SawyerIntro:
	.string "Questo monte è fantastico! Si sente il\n"
	.string "calore delle persone che si incontrano!$"

MtChimney_Text_SawyerDefeat:
	.string "Wow, tu sei come un tizzone ardente!$"

MtChimney_Text_SawyerPostBattle:
	.string "Avrei bisogno di immergermi nelle\n"
	.string "SORGENTI di CUORDILAVA\l"
	.string "insieme agli abitanti del luogo.$"

MtChimney_Text_SawyerRegister:
	.string "Mi piacciono le persone tutto pepe\n"
	.string "come te. Ti registro nel mio POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Ci sono un sacco di persone\n"
	.string "focose da queste parti. Non perderò!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Mamma mia, sei sempre un tizzone\n"
	.string "ardente!$"

MtChimney_Text_SawyerPostRematch:
	.string "Fa veramente caldo qui.\n"
	.string "I miei abiti sono troppo pesanti.$"

