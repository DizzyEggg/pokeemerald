SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM03, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Ehi, come va giovane promessa,\n"
	.string "{PLAYER}?\p"
	.string "Il CAPOPALESTRA di CENERIDE,\n"
	.string "RODOLFO, è maestro dei POKéMON\l"
	.string "di tipo ACQUA.\p"
	.string "La strada per arrivare da RODOLFO\n"
	.string "è ghiacciata e cedevole…\p"
	.string "Mi dispiace, ma non ho altre\n"
	.string "dritte da darti.\p"
	.string "Il resto del cammino lo dovrai\n"
	.string "affrontare con le tue forze!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Wow! Hai battuto persino RODOLFO! È\n"
	.string "il migliore di tutta la regione di HOENN!\p"
	.string "Controlla la tua SCHEDA ALLENATORE!\p"
	.string "Se hai tutte le MEDAGLIE, puoi prendere\n"
	.string "parte alla sfida della LEGA POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Volevo chiederti una cosa.\n"
	.string "Sapevi che… ah, non dovrei essere\l"
	.string "così timido.\p"
	.string "Sono stato io ad insegnare ad ADRIANO\n"
	.string "tutto ciò che c’è da sapere sui POKéMON.\p"
	.string "Tempo fa, ho rinunciato alla mia\n"
	.string "posizione di CAPOPALESTRA.\p"
	.string "Avevo affidato la carica di\n"
	.string "CAPOPALESTRA ad ADRIANO.\p"
	.string "Per una serie di circostanze\n"
	.string "sono dovuto tornare.\p"
	.string "Basta con le chiacchiere.\n"
	.string "Cominciamo la lotta, va bene?\p"
	.string "Preparati ad assistere a una vera e\n"
	.string "propria dimostrazione di talento.\p"
	.string "Un’opera d’arte eseguita nell’acqua da\n"
	.string "me e dalla mia squadra di POKéMON!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahah! Eccellente!\n"
	.string "Bene, hai vinto!\p"
	.string "Intravedo in te una forza prorompente\n"
	.string "che ti permetterà di superare tutte le\l"
	.string "prove che ti attendono.\p"
	.string "Tuttavia, rispetto ad ADRIANO e a me\n"
	.string "ti manca l’eleganza.\p"
	.string "Vuoi che ti presti i miei vestiti?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ahahah, stavo scherzando!\p"
	.string "Invece dei vestiti, ti darò\n"
	.string "la MEDAGLIA PIOGGIA.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} riceve la MEDAGLIA PIOGGIA\n"
	.string "da RODOLFO.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Con questa MEDAGLIA tutti i tuoi\n"
	.string "POKéMON obbediranno a ogni\l"
	.string "tuo comando.\p"
	.string "La MEDAGLIA ti permetterà, inoltre,\n"
	.string "di usare la mossa MN CASCATA\l"
	.string "per risalire le cascate d’acqua.\p"
	.string "Accetta questo in ricordo\n"
	.string "della nostra sfida…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La MACCHINA TECNICA che ti porgo\n"
	.string "contiene IDROPULSAR.\p"
	.string "Nelle sfide, può confondere\n"
	.string "l’avversario con onde ad ultrasuoni.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Registrazione del CAPOPALESTRA\n"
	.string "RODOLFO nel POKéNAV avvenuta.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Gli ALLENATORI con tutte le MEDAGLIE\n"
	.string "della regione di HOENN possono incammi-\l"
	.string "narsi verso la destinazione finale.\p"
	.string "La LEGA POKéMON.\p"
	.string "Fai rotta verso le estremità orientali\n"
	.string "della regione di HOENN. La LEGA POKéMON\l"
	.string "si trova sull’isola di IRIDOPOLI.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Ti è rimasta ancora una MEDAGLIA da\n"
	.string "ottenere nella regione di HOENN.\p"
	.string "Se vuoi sfidare la LEGA POKéMON,\n"
	.string "devi ottenere l’ultima MEDAGLIA\l"
	.string "nella PALESTRA di FORESTOPOLI.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "PALESTRA POKéMON di CENERIDE$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di CENERIDE\p"
	.string "ALLENATORE CERTIFICATO da RODOLFO:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "RODOLFO: Questa PALESTRA aveva\n"
	.string "ritrovato la pace di sempre…\p"
	.string "ma il nostro piccolo tifone è ritornato\n"
	.string "per metterci nuovamente alla prova!\p"
	.string "Va bene, accetto!\p"
	.string "Sarò lieto di danzare con te ogni\n"
	.string "volta che lo vorrai!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahah, hai vinto!\n"
	.string "Mi hai sconfitto ancora!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "RODOLFO: Sono sicuro che non\n"
	.string "accetteresti che io diventassi\l"
	.string "il tuo maestro.\p"
	.string "Vorrei regalarti il cappotto che\n"
	.string "indosso.\p"
	.string "Ma so che non accetteresti\n"
	.string "neppure questo.\p"
	.string "Questo è un segno di nobiltà\n"
	.string "d’animo!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "RODOLFO: Questa PALESTRA aveva\n"
	.string "ritrovato la pace di sempre…\p"
	.string "ma il nostro piccolo tifone è ritornato\n"
	.string "per metterci nuovamente alla prova!\p"
	.string "Va bene, accetto!\n"
	.string "Sarò lieto di danzare con te…\p"
	.string "Ah, no, non ci siamo.\n"
	.string "Hai soltanto un POKéMON.\p"
	.string "Mi farebbe piacere se ritornassi\n"
	.string "con due o più POKéMON.$"

