MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM34, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM34
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM34
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM34
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM34
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Ehi, come va aspirante CAMPIONE,\n"
	.string "{PLAYER}?\p"
	.string "WALTER, il CAPOPALESTRA di\n"
	.string "CICLAMIPOLI, usa POKéMON\l"
	.string "di tipo ELETTRO.\p"
	.string "Se lo sfidi con POKéMON di tipo ACQUA,\n"
	.string "li folgorerà! Bzzt!\p"
	.string "Tutte le porte della sua PALESTRA\n"
	.string "sono controllate da interruttori!\p"
	.string "Ehi, sarà una bella sfida!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, sei elettrizzante!\n"
	.string "Con la tua energia hai aperto la porta!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Il mio soul elettrico farà vacillare\n"
	.string "i tuoi sogni!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Mi hai fatto andare in corto circuito!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "I POKéMON e il rock: è tutta una\n"
	.string "questione di cuore, yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "WALTER è il mio ALLENATORE!\n"
	.string "Battermi non sarà impresa facile!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Mi hai staccato la spina…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "WALTER, il nostro CAPOPALESTRA,\n"
	.string "non è un esordiente.\p"
	.string "Lottava già prima che nascesse tuo\n"
	.string "padre… è un tipo tosto!$"

MauvilleCity_Gym_Text_BenIntro:
	.string "Questa PALESTRA ha dei tranelli!\n"
	.string "Non lo trovi divertente?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Perdere non è divertente…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "A WALTER piace inventare trabocchetti\n"
	.string "azionati da interruttori.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Il mio carisma e le mosse della mia\n"
	.string "squadra di POKéMON ti fulmineranno!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "La tua energia è impressionante!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "Ho sentito che WALTER è il fondatore\n"
	.string "di CICLAMIPOLI.\p"
	.string "Era già ALLENATORE prima che tutti\n"
	.string "noi lo diventassimo.\l"
	.string "Deve conoscere un sacco di cose!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "Mi piacciono le cose luccicanti!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh!\n"
	.string "I miei occhi sono rimasti fulminati…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "WALTER, il CAPOPALESTRA di\n"
	.string "CICLAMIPOLI, ha la fronte luminosa.\l"
	.string "Che bello!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Ho abbandonato i miei piani\n"
	.string "di trasformare la città.\p"
	.string "Quindi passo il tempo ad inventare\n"
	.string "trabocchetti nella mia PALESTRA.\p"
	.string "Ehi! Che cosa ci fai tu qui?\p"
	.string "Non mi dirai che hai superato\n"
	.string "tutte le mie porte truccate!\p"
	.string "Ahahahah!\n"
	.string "Adesso mi diverto io!\p"
	.string "Io, WALTER, CAPOPALESTRA di\n"
	.string "CICLAMIPOLI, ti elettrizzerò!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Ahahahah!\n"
	.string "Ok, ho perso!\p"
	.string "Mi hai dato la scossa!\n"
	.string "Prendi questa MEDAGLIA!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} riceve la MEDAGLIA DINAMO\n"
	.string "da WALTER.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Con la MEDAGLIA DINAMO, i POKéMON\n"
	.string "possono usare SPACCAROCCIA fuori\l"
	.string "dalla lotta.\p"
	.string "Inoltre, renderà i tuoi POKéMON\n"
	.string "un po’ più veloci.\p"
	.string "Uhmm… prendi anche questo!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "Questa MT34 contiene ONDASHOCK.\p"
	.string "È una mossa affidabile che va sempre\n"
	.string "a segno! Ci puoi contare!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Registrazione del CAPOPALESTRA\n"
	.string "WALTER nel POKéNAV avvenuta.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Vedere una giovane promessa come te\n"
	.string "mi riempie di ottimismo!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Ahahahah!\n"
	.string "Continua così, giovane promessa!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON di CICLAMIPOLI$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di CICLAMIPOLI\p"
	.string "ALLENATORE CERTIFICATO da WALTER:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WALTER: Ahah! Eccoci finalmente!\n"
	.string "So benissimo cosa vuoi. Vuoi lottare\l"
	.string "contro la mia squadra di POKéMON!\p"
	.string "Ahahahah!\p"
	.string "Ti farò fare scintille!\n"
	.string "Uomo avvisato, mezzo salvato!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Uff… le nostre batterie si sono\n"
	.string "esaurite…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WALTER: Dobbiamo ricaricare le nostre\n"
	.string "batterie.\p"
	.string "Dopo di che, saremo lieti di accettare\n"
	.string "nuovamente la tua sfida.\p"
	.string "Ritorna un’altra volta, ok?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WALTER: Ahah! Eccoci finalmente!\n"
	.string "So benissimo cosa vuoi. Vuoi lottare\l"
	.string "contro la mia squadra di POKéMON!\p"
	.string "Ahahahah!\p"
	.string "Oops! Aspetta!\n"
	.string "Hai un solo POKéMON!\p"
	.string "Torna a trovarmi quando avrai più\n"
	.string "di un POKéMON, va bene?$"

