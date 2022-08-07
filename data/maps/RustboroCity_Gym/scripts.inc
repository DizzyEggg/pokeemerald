RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Ehi, come va?\p"
	.string "Ho qualcosa da dirti!\n"
	.string "Vuoi diventare CAMPIONE?\p"
	.string "Non sono un ALLENATORE, ma posso\n"
	.string "darti alcune dritte per vincere.\p"
	.string "Ok, affare fatto! Ti darò una mano a\n"
	.string "diventare CAMPIONE di POKéMON!\p"
	.string "Come ALLENATORE hai il compito di\n"
	.string "vincere MEDAGLIE, giusto?\p"
	.string "Ma i CAPIPALESTRA sono degli ossi duri!\p"
	.string "Ed è qui che entro in gioco!\n"
	.string "Ascolta bene quello che ti sto per dire!\p"
	.string "PETRA, il CAPOPALESTRA, usa POKéMON\n"
	.string "di tipo ROCCIA.\p"
	.string "Il tipo ROCCIA è molto resistente, ma\n"
	.string "non può soffrire le mosse di tipo ACQUA\l"
	.string "ed ERBA.\p"
	.string "Se riesci a battere il CAPOPALESTRA,\n"
	.string "vieni a trovarmi di nuovo.\p"
	.string "In bocca al lupo!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Wow! Che vittoria entusiasmante!\n"
	.string "Ho fatto il tifo per te!\p"
	.string "Magnifico!\n"
	.string "Controlla la tua SCHEDA ALLENATORE.\p"
	.string "Dovrebbe esserci registrata\n"
	.string "la MEDAGLIA PIETRA che hai vinto.\p"
	.string "In altre parole…\p"
	.string "hai compiuto il primo passo per\n"
	.string "diventare CAMPIONE!\p"
	.string "Deve essere una sensazione incredibile!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Gli ALLENATORI delle PALESTRE\n"
	.string "non vanno presi alla leggera!\l"
	.string "Ti dimostrerò il perché.$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Sei troppo forte…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Ancora non conosci la potenza\n"
	.string "terrificante del tipo ROCCIA!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Se non riesci a battermi, non avrai\n"
	.string "alcuna possibilità contro PETRA!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! Ne hai di talento!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "PETRA è molto più forte di me!\p"
	.string "Farai meglio a stare in guardia!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Siamo nel bel mezzo della città, ma chi\n"
	.string "se ne importa?\p"
	.string "I miei POKéMON ROCCIA hanno bisogno di\n"
	.string "spazio per scatenarsi!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, mamma mia!\n"
	.string "Il nostro sfidante è un osso duro!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Cosa racconterò al nostro\n"
	.string "CAPOPALESTRA?\p"
	.string "È stata veramente in gamba a catturare\n"
	.string "POKéMON di tipo ROCCIA così giovane.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Ciao, sono PETRA, CAPOPALESTRA\n"
	.string "di FERRUGIPOLI.\p"
	.string "Sono diventata CAPOPALESTRA per\n"
	.string "mettere in pratica nella lotta quello\l"
	.string "che ho imparato alla SCUOLA per\l"
	.string "ALLENATORI.\p"
	.string "Vuoi dimostrarmi come lotti e quali\n"
	.string "POKéMON usi?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Quindi… ho perso…\p"
	.string "Credo di avere ancora molto da\n"
	.string "imparare…\p"
	.string "Ora mi è tutto più chiaro.\p"
	.string "Secondo le regole della LEGA POKéMON,\n"
	.string "agli ALLENATORI viene conferito questo\l"
	.string "se sconfiggono un CAPOPALESTRA.\p"
	.string "Ti prego di accettare la MEDAGLIA\n"
	.string "PIETRA della LEGA POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} riceve la MEDAGLIA PIETRA\n"
	.string "da PETRA.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "La MEDAGLIA PIETRA migliora la potenza\n"
	.string "di ATTACCO dei tuoi POKéMON.\p"
	.string "Inoltre, potranno usare la mossa MN\n"
	.string "TAGLIO fuori dalla lotta.\p"
	.string "Ti prego di accettare anche questo.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Questa MACCHINA TECNICA, la MT39\n"
	.string "contiene ROCCIOTOMBA.\p"
	.string "Non solo arreca danno tirando rocce,\n"
	.string "ma fa diminuire la VELOCITÀ.\p"
	.string "Se usi una MT, uno dei tuoi POKéMON\n"
	.string "potrà subito imparare una mossa.\p"
	.string "Attenzione però: una MT si usa solo\n"
	.string "una volta. Pensaci prima di usarla.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Visto che sei così forte, dovresti\n"
	.string "sfidare altri CAPIPALESTRA.\p"
	.string "Sfidando molti ALLENATORI, si imparano\n"
	.string "senz’altro tante cose.$"

RustboroCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON di FERRUGIPOLI$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di FERRUGIPOLI\p"
	.string "ALLENATORE CERTIFICATO da PETRA:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Driiin!\p"
	.string "PETRA: Ciao, {PLAYER}.\n"
	.string "Sono PETRA di FERRUGIPOLI.\p"
	.string "RUDI mi ha detto che stai\n"
	.string "facendo passi da gigante come\l"
	.string "ALLENATORE.\p"
	.string "Un giorno spero di poterti\n"
	.string "sconfiggere…\p"
	.string "Qui alla PALESTRA stiamo\n"
	.string "dandoci sotto con gli allenamenti,\l"
	.string "così potremo accettare ancora\l"
	.string "la tua sfida.\p"
	.string "Mi auguro che tu ne abbia\n"
	.string "voglia quanto me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Registrazione del CAPOPALESTRA\n"
	.string "PETRA nel POKéNAV avvenuta.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "PETRA: Che piacere rivederti! Sono\n"
	.string "PETRA, il CAPOPALESTRA.\p"
	.string "Dall’ultima volta abbiamo accumulato \n"
	.string "numerose esperienze di lotta.\p"
	.string "Mettiamoci alla prova e vediamo se\n"
	.string "abbiamo fatto progressi. Dai, lottiamo!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grrr… ho perso un’altra volta…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "PETRA: In quanto a lotte con i POKéMON,\n"
	.string "ho ancora molto da imparare.\p"
	.string "Rendermi conto di ciò mi fa apprezzare\n"
	.string "la lotta ancora di più.$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "PETRA: Che piacere rivederti! Sono\n"
	.string "PETRA, il CAPOPALESTRA.\p"
	.string "Dall’ultima volta abbiamo accumulato \n"
	.string "numerose esperienze di lotta.\p"
	.string "Mettiamoci alla prova e vediamo se\n"
	.string "abbiamo fatto progressi…\p"
	.string "Oh, no… non dirmi che hai\n"
	.string "un solo POKéMON?\p"
	.string "Ritorna quando ne avrai almeno due.$"
