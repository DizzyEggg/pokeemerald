.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "Il CAPO è interessato alla ricerca\n"
	.string "condotta qui, per questo ci ha mandato.\p"
	.string "Tu stanne fuori!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Battuto… battuto da una pulce…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Il nostro CAPO sa tutto.\p"
	.string "Ma io sono solo una RECLUTA.\n"
	.string "Non posso sapere cos’ha in testa!$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Eh? Che ci fai tu qui?\n"
	.string "Non è posto per bambini questo!$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Eh?\n"
	.string "Ho perso?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, no… chissà che lavata di capo\n"
	.string "per aver perso contro di te…\p"
	.string "Meglio che mi riposi un po’…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Mentre dormivo, sono andati tutti \n"
	.string "di sopra!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Però, sei davvero forte!\p"
	.string "Magari diventassi un ALLENATORE\n"
	.string "di POKéMON come te!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "Il PROFESSORE ama la pioggia.\n"
	.string "È un dato di fatto.\p"
	.string "Se continua a piovere, la gente sarà nei\n"
	.string "guai. Anche questo è un dato di fatto.\p"
	.string "Così il PROFESSORE sta studiando\n"
	.string "come sfruttare la pioggia in modo utile.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Al primo piano dell’ISTITUTO,\n"
	.string "studiamo i microclimi della\l"
	.string "regione di HOENN.\p"
	.string "Ultimamente abbiamo registrato\n"
	.string "casi isolati di siccità e piogge\l"
	.string "battenti…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Ciao! Grazie, ci hai tolto dai pasticci!\p"
	.string "Ma non capisco quale fosse\n"
	.string "lo scopo degli IDRO.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Oh, c’è un letto!\n"
	.string "Meglio riposarsi un po’…$"

