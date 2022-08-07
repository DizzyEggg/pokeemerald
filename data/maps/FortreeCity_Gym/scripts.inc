FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM40, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM40
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM40
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Ehi, come va {PLAYER}, CAMPIONE in erba?\p"
	.string "ALICE, CAPOPALESTRA di FORESTOPOLI,\n"
	.string "è la regina dei POKéMON di tipo VOLANTE.\p"
	.string "Ti attende in fondo alla PALESTRA,\n"
	.string "dietro le porte girevoli.\p"
	.string "Sta aspettando nuovi sfidanti\n"
	.string "che cercano di spiccare il volo!\p"
	.string "Coraggio, lanciati nell’impresa!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Ce l’hai fatta!\n"
	.string "Sei in continua ascesa!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Ti mostrerò l’elegante stile di lotta\n"
	.string "dei POKéMON UCCELLO!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Tu… sei imbattibile…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Un ALLENATORE deve saper fronteggiare\n"
	.string "qualsiasi imprevisto.\p"
	.string "Vediamo se hai la stoffa per sfidare\n"
	.string "il nostro CAPOPALESTRA!$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Gli amanti dei POKéMON UCCELLO aspirano\n"
	.string "ad iscriversi in questa PALESTRA.\p"
	.string "Come membro della PALESTRA di\n"
	.string "FORESTOPOLI, non posso permettermi\l"
	.string "di perdere!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Questa volta non ce l’ho fatta…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Il mondo è sconfinato e gli ALLENATORI\n"
	.string "forti sono innumerevoli.\p"
	.string "Continuerò ad allenarmi per diventare\n"
	.string "sempre più forte.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Non c’è bisogno che ALICE, il nostro\n"
	.string "CAPOPALESTRA, si scomodi per te!\p"
	.string "Ci penserò io a fermarti!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "ALICE, io… ho perso!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "ALICE è carina e forte.\n"
	.string "È un grande CAPOPALESTRA!\p"
	.string "Ehm, ehm…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "Ho preso lezioni da ALICE!\n"
	.string "Battermi non sarà facile!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Mi hai battuto…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "La presenza di ALICE infonde\n"
	.string "tranquillità negli abitanti\l"
	.string "di FORESTOPOLI.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Quando ALICE si appresta a lottare,\n"
	.string "le si legge la determinazione sul viso…\p"
	.string "Non lascerò che tu arrivi così vicino\n"
	.string "da vedere il suo bellissimo volto!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Oh oh… non sono riuscito a fermarti.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Ti conviene fare attenzione!\n"
	.string "Se ti distrai ad osservare ALICE,\l"
	.string "andrai a tappeto in un attimo!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Devi sapere che c’è una grande varietà\n"
	.string "di POKéMON di tipo VOLANTE.\p"
	.string "Lo sapevi già, vero?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Sembra che tu sappia il fatto tuo!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Sì, mi hai sconfitto. Ma è presto per\n"
	.string "cantare vittoria. I POKéMON del nostro\l"
	.string "CAPOPALESTRA ALICE sono tosti.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Sono ALICE, CAPOPALESTRA di\n"
	.string "FORESTOPOLI.\p"
	.string "Sono una stella nel firmamento grazie\n"
	.string "ai miei POKéMON UCCELLO.\p"
	.string "Nelle lotte più ardue siamo sempre\n"
	.string "riusciti a tirare fuori gli artigli…\p"
	.string "Io e i miei POKéMON UCCELLO\n"
	.string "ti batteremo in volata!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Non avevo mai incontrato un ALLENATORE\n"
	.string "capace di comandare i POKéMON con più\l"
	.string "eleganza di me…\p"
	.string "Come riconoscimento della tua forza,\n"
	.string "ti meriti questa MEDAGLIA.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} riceve la MEDAGLIA PIUMA\n"
	.string "da ALICE.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Con la MEDAGLIA PIUMA, tutti i POKéMON\n"
	.string "fino al livello 70, anche se scambiati,\l"
	.string "obbediranno ad ogni tuo comando.\p"
	.string "Ti permette anche di usare la mossa\n"
	.string "MN VOLO quando non stai lottando.\p"
	.string "E questo… è un omaggio da parte mia.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "La MT40 contiene AEROASSALTO.\p"
	.string "La sua velocità…\n"
	.string "nessun POKéMON avrà scampo.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registrazione del CAPOPALESTRA\n"
	.string "ALICE nel POKéNAV avvenuta.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Anche se mi hai battuto, rimarrò fedele\n"
	.string "ai POKéMON UCCELLO.$"

FortreeCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON di FORESTOPOLI$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di FORESTOPOLI\p"
	.string "ALLENATORE CERTIFICATO da ALICE:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "ALICE: Gli uomini non possono sfuggire\n"
	.string "all’attrazione della forza terrestre.\p"
	.string "Tuttavia, aspirando alla perfezione,\n"
	.string "riescono a spiccare il volo!\p"
	.string "Come CAMPIONE in carica, tu\n"
	.string "hai raggiunto la vetta.\p"
	.string "Fammi vedere ora se sei veramente\n"
	.string "capace di volare!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Ancora una volta ho volato più basso\n"
	.string "di te…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "ALICE: Anche se ho perso, le ali del mio\n"
	.string "cuore sono rimaste intatte.\p"
	.string "Posso rialzarmi e spiccare il volo\n"
	.string "ancora una volta.\p"
	.string "Ne sono sicura.$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "ALICE: Gli uomini non possono sfuggire\n"
	.string "all’attrazione della forza terrestre.\p"
	.string "Tuttavia, aspirando alla perfezione,\n"
	.string "riescono a spiccare il volo!\p"
	.string "Come CAMPIONE in carica, tu\n"
	.string "hai raggiunto la vetta.\p"
	.string "Fammi vedere ora se sei veramente\n"
	.string "capace di volare!\p"
	.string "Oh, no… hai un solo POKéMON?\p"
	.string "Torna quando ne avrai almeno due.$"
