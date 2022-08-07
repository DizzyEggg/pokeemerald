@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Il mio POKéMON aveva già vinto\n"
	.string "una GARA di BELLEZZA in questa sede.\p"
	.string "Bene, indovina un po’… oggi ha vinto\n"
	.string "una GARA di ACUME!\p"
	.string "Le mie abilità sono spaventose…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Mi sono iscritto a molte GARE e\n"
	.string "comincio a capirne il meccanismo.\p"
	.string "In una GARA di CLASSE, le mosse di\n"
	.string "classe hanno successo nell’esibizione.\p"
	.string "Le mosse acute e graziose, però, non\n"
	.string "fanno altrettanta bella figura.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Quel giovane uomo che ha vinto prima\n"
	.string "aveva tantissime {POKEMELLE} diverse.\p"
	.string "Tutte quelle cose aiutano a vincere?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Wow, non trovi che sia un posto\n"
	.string "colossale!\p"
	.string "È molto più elettrizzante rispetto alle\n"
	.string "ARENE delle VIRTÙ di provincia.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "ASSISTENTE: Ok, POKéMON ACUTI e\n"
	.string "loro ALLENATORI, siete pronti?!\p"
	.string "Fateci vedere di che cosa siete capaci!\n"
	.string "Diamo inizio all’esibizione!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "GIUDICE: Ti piace questa GARA?\p"
	.string "Torna con tre amici: potrete iscrivervi\n"
	.string "tutti ad una GARA!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ahiahiahi…\n"
	.string "Ho scelto la GARA sbagliata.\p"
	.string "Ho iscritto questo POKéMON grintoso\n"
	.string "alla GARA di ACUME…\p"
	.string "Forza, sorprendili con una mossa\n"
	.string "SPACCAROCCIA acuta.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Ho speso una vita e tanta saggezza per\n"
	.string "insegnare a questo POKéMON ad essere\l"
	.string "acuto.\p"
	.string "Un POKéMON di un debuttante non può\n"
	.string "fare meglio di lui.\p"
	.string "Cara mogliettina, stai ammirando?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Eccolo!\p"
	.string "Se adesso il mio POKéMON fa una mossa\n"
	.string "acuta, l’entusiasmo del pubblico salirà\l"
	.string "alle stelle!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh, no!\p"
	.string "La SANGUISUGA di ZUBAT è così graziosa\n"
	.string "che ho continuato ad usarla!\p"
	.string "Ma queste persone non sembrano\n"
	.string "gradirla affatto. Ce l’hanno con me!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Aahhh! Sei bello, nonnino!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Anche quando gli ALLENATORI iscrivono\n"
	.string "la stessa specie di POKéMON, sembrano\l"
	.string "usare mosse diverse nell’esibizione.\p"
	.string "Anche nella lotta le persone adottano\n"
	.string "stili diversi.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Credo che i POKéMON siano un bel po’\n"
	.string "più acuti dei loro ALLENATORI.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "A conti fatti, preferisco le GARE di\n"
	.string "ACUME.\p"
	.string "Quel colore verde così intellettuale…\n"
	.string "mi fa impazzire!$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "ASSISTENTE: Ti iscrivi anche tu alla\n"
	.string "GARA di BELLEZZA? In bocca al lupo!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "GIUDICE: Ogni POKéMON qui è un esempio\n"
	.string "di rara bellezza!\p"
	.string "Per poco mi dimenticavo di dare \n"
	.string "il punteggio!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Un POKéMON così bello…\n"
	.string "sbaraglia la concorrenza.\p"
	.string "Nessuno riuscirà a togliergli gli occhi\n"
	.string "di dosso.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Aaaaah!\p"
	.string "Ho tirato a lustro il mio POKéMON\n"
	.string "per questa GARA…\p"
	.string "Ma forse ho esagerato un po’…\n"
	.string "Il mantello del mio POKéMON è tutto\l"
	.string "ispido…\p"
	.string "Che cosa devo fare?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "La mossa RAGGIAURORA è così lucente\n"
	.string "che il GIUDICE ne verrà abbagliato.\p"
	.string "Uh, aspetta un secondo… non ha\n"
	.string "senso usarla!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Questo POKéMON tanto carino assomiglia\n"
	.string "a me quando ero giovane.\p"
	.string "Appena l’ho detto, mio marito ha\n"
	.string "sputato il caffè che stava bevendo.\p"
	.string "Fa tanto ridere quello che ho detto?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Sai, come donna, se vinco una GARA di\n"
	.string "BELLEZZA sono tanto contenta.\l"
	.string "Sarà vanità femminile?$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Ahahahah!\p"
	.string "Dai un’occhiata a tutti questi POKéMON\n"
	.string "tanto carini!\l"
	.string "Che bello spettacolo!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Non puoi contare solo sulla bellezza.\p"
	.string "Devi anche vestire il tuo POKéMON\n"
	.string "a festa.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "ASSISTENTE: Uh! Ehi!\n"
	.string "Siamo nel bel mezzo di una GARA!\p"
	.string "Bisogna iscriversi al bancone prima\n"
	.string "di esibirsi, ok?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "GIUDICE: Oh, queste esibizioni sono\n"
	.string "così affascinanti e graziose!\p"
	.string "Un’esibizione, quella con DOCCIASCUDO,\n"
	.string "del tutto adorabile!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh, no… il mio dolce AZURILL…\n"
	.string "un altro POKéMON l’ha distratto.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Il mio POKéMON non vince mai in lotta,\n"
	.string "ma guarda com’è bravo nelle GARE!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "La PETALODANZA del mio POKéMON\n"
	.string "è una meraviglia di eleganza.\p"
	.string "Non permetterò a nessuno di disturbare\n"
	.string "la sua prova.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "I POKéMON degli altri sono molto\n"
	.string "graziosi.\p"
	.string "Ma se il mio POKéMON dovesse fare\n"
	.string "un’esibizione graziosa…\p"
	.string "sono sicura che sarebbe molto più\n"
	.string "grazioso degli altri.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Il mio tesoro partecipa a questa GARA.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Coraggio, fatti valere!\n"
	.string "Il tuo POKéMON è il migliore!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Credo che quella ragazza sia\n"
	.string "la più graziosa di tutte.\p"
	.string "Che cosa? Giudicano i POKéMON\n"
	.string "per il loro aspetto?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Oh, vedere tutti questi POKéMON così\n"
	.string "graziosi, mi ha fatto venir voglia di\l"
	.string "averne uno tutto mio!\p"
	.string "Adesso ne catturo qualcuno!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "GARA di BELLEZZA: FATEVI AFFASCINARE\n"
	.string "da POKéMON BELLI!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "GARA di GRAZIA: FATEVI INCANTARE\n"
	.string "da POKéMON GRAZIOSI!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "GARA di ACUME: FATEVI IMPRESSIONARE\n"
	.string "da POKéMON ACUTI!$"

