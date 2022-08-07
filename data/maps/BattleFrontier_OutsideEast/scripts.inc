.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Questa è la TORRE LOTTA!\n"
	.string "Vinci tante volte di fila e dimostra\l"
	.string "che sei un ALLENATORE forte!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Questo è il PALAZZO LOTTA!\n"
	.string "Ammira le lotte POKéMON!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Questo è il DOJO LOTTA!\n"
	.string "Qui lottano le squadre più forti!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Questa è la PIRAMIDE LOTTA!\n"
	.string "Cimentati nella LOTTA ESPLORAZIONE!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "VILLA CLASSIFICA del PARCO LOTTA\n"
	.string "Scala la vetta della classifica!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "UFFICIO RITIRO PREMI\n"
	.string "Scambia i tuoi PUNTI LOTTA!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Wow!\n"
	.string "È enorme!\p"
	.string "La TORRE LOTTA è un posto speciale.\n"
	.string "Si distingue da tutti gli altri.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "La mia ambizione più grande è\n"
	.string "conquistare il PARCO LOTTA e\l"
	.string "la LEGA POKéMON.\p"
	.string "Se il mio sogno si avvera…\p"
	.string "chiederò a MIMMA che abita qui accanto\n"
	.string "di diventare mia amica!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "La PIRAMIDE LOTTA è troppo dura!\n"
	.string "Non riesco a raggiungere la cima!\p"
	.string "Non ho altra scelta. Proverò la scalata\n"
	.string "dall’esterno…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Adoro il buio.\n"
	.string "Qual è l’edificio che più mi si addice?\l"
	.string "La PIRAMIDE LOTTA, che discorsi…\p"
	.string "Perché non camminiamo insieme\n"
	.string "nelle tenebre?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Non ho chiuso occhio per una settimana,\n"
	.string "ma ho creato una squadra fortissima!\p"
	.string "Non possiamo perdere.\n"
	.string "Faremo furore nel DOJO LOTTA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Ti ha portato qui SCOTT?\n"
	.string "Ma che tipo è?\p"
	.string "Pare riconosca gli ALLENATORI di\n"
	.string "talento a colpo d’occhio…\p"
	.string "Non l’ho mai visto lottare di persona.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "Ho fiducia in te, tesoruccio!\p"
	.string "Mio caro ZIGG, se vinci ti cucino\n"
	.string "il tuo piatto preferito!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON ha lo sguardo perso…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Le persone mi dicono che dovrei darmi\n"
	.string "una calmata, ma è più forte di me.\p"
	.string "Hai i capelli in disordine!\n"
	.string "Oh, no! Il prato è sporco!\l"
	.string "Oops, è quasi ora di cena!\p"
	.string "Non posso rimanere con le mani in\n"
	.string "mano davanti al PALAZZO LOTTA…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Ti sembrerà impossibile, ma un tempo\n"
	.string "ho battuto un CAPOPALESTRA.\p"
	.string "Mai dire mai! Forse non dovrei\n"
	.string "rinunciare ai miei sogni di gloria.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Sulla BICI sono un fulmine. Anche nelle\n"
	.string "lotte non sono da meno.\p"
	.string "Vinco le lotte in un batter d’occhio!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Sono più brava del mio papà\n"
	.string "coi POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Forza, tesoro!\n"
	.string "Vinci per il tuo paparino!\p"
	.string "Sei proprio come la mamma,\n"
	.string "nessuno ti fermerà!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Raggiungere questo posto è stata\n"
	.string "un’impresa, ma volevo incontrare\l"
	.string "la strabiliante ragazza del DOJO LOTTA.\p"
	.string "Indovina chi ho trovato al suo posto?\p"
	.string "Un ammasso di atleti puzzolenti e\n"
	.string "rozzi!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "A volte vedo entrare un uomo di una\n"
	.string "certa età. Si direbbe un pezzo grosso.\p"
	.string "Ha dei POKéMON incredibili, ma mi sembra\n"
	.string "un tipo alla mano.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Conosci la leggenda della PIRAMIDE\n"
	.string "LOTTA?\p"
	.string "Quando un ALLENATORE sicuro di\n"
	.string "sé raggiunge la vetta dorata, appare\l"
	.string "un uomo speciale.\p"
	.string "Non conosci questa leggenda?\n"
	.string "Certo che no!\l"
	.string "Me la sono appena inventata!\p"
	.string "Qual è il suo significato recondito?\n"
	.string "Non posso dirtelo!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Cielo!\n"
	.string "Non avevo mai perso!\p"
	.string "Oltretutto non hanno avuto nessun\n"
	.string "riguardo nei miei confronti!\p"
	.string "Come si fa a dirmi che non ho\n"
	.string "talento?! Sono costernato!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Quest’uomo si è imbattuto in un\n"
	.string "ALLENATORE fortissimo mentre\l"
	.string "stava sfidando la TORRE LOTTA.\p"
	.string "Guarda come si è ridotto…\p"
	.string "Se decidi di entrare nella TORRE LOTTA,\n"
	.string "devi stare in campana.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Sì!\n"
	.string "Ho raccolto abbastanza PUNTI LOTTA!\p"
	.string "In cambio chiederò un’altra di quelle\n"
	.string "BAMBOLE di pezza giganti!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, sì!\n"
	.string "Questa è VILLA CLASSIFICA!\p"
	.string "Voglio passare alla storia come un\n"
	.string "super campione e voglio che il mio\l"
	.string "nome venga registrato qui per i posteri.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Con te al mio fianco, mi sento un leone.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Tesoruccio, sei meraviglioso!\p"
	.string "Non sto più nella pelle!\p"
	.string "Andiamo in una SALA LOTTA MULTIPLA\n"
	.string "senza perdere altro tempo!\p"
	.string "Se andiamo insieme nel SALONE LOTTA,\n"
	.string "tutti coloro che incrociamo saranno\l"
	.string "sopraffatti dal nostro amore.\p"
	.string "Cadranno come tante tessere\n"
	.string "del domino!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "Il PARCO LOTTA non è pensato solo\n"
	.string "per gli ALLENATORI forti.\p"
	.string "Pare che siano state invitate molte\n"
	.string "persone con abilità speciali.\p"
	.string "Quell’uomo, SCOTT…\p"
	.string "Forse nel costruire questo luogo\n"
	.string "perseguiva un ideale ancora\l"
	.string "più nobile…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Scusa, giovane.\n"
	.string "Hai una buona vista?\p"
	.string "Poco più in là c’è uno strano albero.\n"
	.string "Mi sembra che ondeggi, ma forse la\l"
	.string "vista mi tradisce.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Scusa, giovane.\n"
	.string "Hai una buona memoria?\p"
	.string "Mi sembra di ricordare che poco più\n"
	.string "in là ci fosse un albero.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "L’ho… l’ho visto!\p"
	.string "C’era un POKéMON appiccicoso\n"
	.string "con una lunga coda!\p"
	.string "Si nascondeva sotto un masso e\n"
	.string "continuava a fissarmi!$"
