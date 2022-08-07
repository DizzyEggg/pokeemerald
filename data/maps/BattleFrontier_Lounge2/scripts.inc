BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Salve! Sono il numero 1 quando si tratta\n"
	.string "di dare informazioni sul PARCO LOTTA.\p"
	.string "Mi merito l’appellativo di FANATICO\n"
	.string "del PARCO.\p"
	.string "Non per farmi gli affari tuoi, ma\n"
	.string "tu sei un ALLENATORE, giusto?\p"
	.string "Ti aggiorno volentieri sulle novità \n"
	.string "del PARCO LOTTA.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Salve! Sei qui per farmi il terzo grado\n"
	.string "sulle ultime tendenze? Perfetto!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Well? Well? Well?\p"
	.string "I’m sure my information’s been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Vediamo un po’…\p"
	.string "{STR_VAR_1}! È il posto che tira\n"
	.string "di più.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Vediamo un po’…\p"
	.string "Pare che la LOTTA {STR_VAR_1}\n"
	.string "della TORRE LOTTA vada alla grande.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Scommetto che non lo sai!\p"
	.string "Lì si trova uno degli ALLENATORI che\n"
	.string "SCOTT chiama gli ASSI del PARCO.\p"
	.string "Il posto è diretto da un ALLENATORE\n"
	.string "misterioso che chiamano DAMA TORRE.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Hai mai sfidato la DAMA TORRE?\p"
	.string "Pare che contro gli avversari mandi\n"
	.string "in campo questi POKéMON:\p"
	.string "un POKéMON PSICO di tipo PSICO,\n"
	.string "un POKéMON VULCANO di tipo FUOCO e\l"
	.string "un POKéMON SONNO di tipo NORMALE.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Hai mai sfidato la DAMA TORRE\n"
	.string "quando fa sul serio?\p"
	.string "Quando lotta senza scherzare pare\n"
	.string "che utilizzi questi POKéMON:\p"
	.string "un POKéMON EONE di tipo DRAGO e PSICO,\n"
	.string "un POKéMON TUONO di tipo ELETTRO e\l"
	.string "un POKéMON SONNO di tipo NORMALE.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Scommetto che non lo sai!\p"
	.string "Lì si trova uno degli ALLENATORI che\n"
	.string "SCOTT chiama gli ASSI del PARCO.\p"
	.string "Il posto è diretto da un ALLENATORE\n"
	.string "spumeggiante che chiamano\l"
	.string "ASTRO CUPOLA.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Hai mai sfidato l’ASTRO CUPOLA?\p"
	.string "Quando non vuole infierire sul rivale,\n"
	.string "utilizza questi POKéMON:\p"
	.string "un POKéMON DRAGO di tipo DRAGO e\n"
	.string "VOLANTE, un POKéMON FANGO PESCE\l"
	.string "di tipo ACQUA e TERRA e un POKéMON\l"
	.string "FIAMMA di tipo FUOCO e VOLANTE.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Hai mai sfidato l’ASTRO CUPOLA\n"
	.string "quando fa sul serio?\p"
	.string "Quando vuole dimostrare che è uno\n"
	.string "stratega, schiera questi tre POKéMON:\p"
	.string "un POKéMON EONE di tipo DRAGO e PSICO,\n"
	.string "un POKéMON FANGO PESCE di tipo ACQUA e\l"
	.string "TERRA e un POKéMON FERRARTO di tipo\l"
	.string "ACCIAIO e PSICO.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Scommetto che non lo sai!\p"
	.string "Lì si trova uno degli ALLENATORI che\n"
	.string "SCOTT chiama gli ASSI del PARCO.\p"
	.string "Il posto è diretto da un ALLENATORE\n"
	.string "bizzarro che chiamano BOSS AZIENDA.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Hai già sfidato il BOSS AZIENDA?\p"
	.string "Fammi pensare… quando lotta\n"
	.string "utilizza solo POKéMON a nolo.\p"
	.string "Ti sfida alle tue stesse condizioni.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Hai mai sfidato il BOSS AZIENDA\n"
	.string "quando fa sul serio?\p"
	.string "Anche quando lotta con tutto se stesso\n"
	.string "utilizza tre POKéMON a nolo.\p"
	.string "Ti sfida praticamente alle tue\n"
	.string "stesse condizioni.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Scommetto che non lo sai!\p"
	.string "Lì si trova uno degli ALLENATORI che\n"
	.string "SCOTT chiama gli ASSI del PARCO.\p"
	.string "Il posto è diretto da un ALLENATORE\n"
	.string "terribile che chiamano REGINA SERPE.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Hai già lottato contro la REGINA SERPE?\p"
	.string "Dicono che quando è di buon umore\n"
	.string "utilizzi questi tre POKéMON:\p"
	.string "un POKéMON ZANNASERPE di tipo VELENO,\n"
	.string "un POKéMON MUFFA di tipo COLEOTTERO e\l"
	.string "ROCCIA e un POKéMON TENEREZZA\l"
	.string "di tipo ACQUA.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Hai mai sfidato la REGINA SERPE\n"
	.string "quando fa sul serio?\p"
	.string "Quando è inviperita, dicono che\n"
	.string "utilizzi questi tre POKéMON:\p"
	.string "un POKéMON ZANNASERPE di tipo VELENO,\n"
	.string "un POKéMON FERROSERPE di tipo\l"
	.string "ACCIAIO e TERRA e un POKéMON\l"
	.string "ATROCE di tipo ACQUA e VOLANTE.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Scommetto che non lo sai!\p"
	.string "Lì si trova uno degli ALLENATORI che\n"
	.string "SCOTT chiama gli ASSI del PARCO.\p"
	.string "Il posto è diretto da un ALLENATORE\n"
	.string "avvenente che chiamano MAESTRA DOJO.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Hai già sfidato la MAESTRA DOJO?\p"
	.string "Per valutare l’abilità del rivale pare\n"
	.string "che mandi in campo questi POKéMON:\p"
	.string "un POKéMON MONOCORNO di tipo COLEOT-\n"
	.string "TERO e LOTTA, un POKéMON LUCELUNARE\l"
	.string "di tipo BUIO e un POKéMON CAMBIAPELLE\l"
	.string "di tipo COLEOTTERO e SPETTRO.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Hai mai sfidato la MAESTRA DOJO\n"
	.string "quando fa sul serio?\p"
	.string "Quando ci si mette d’impegno, dicono\n"
	.string "che schieri questi POKéMON:\p"
	.string "un POKéMON LUCELUNARE di tipo BUIO,\n"
	.string "un POKéMON OMBRA di tipo SPETTRO e\l"
	.string "VELENO e un POKéMON FUNGO di tipo\l"
	.string "ERBA e LOTTA.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Scommetto che non lo sai!\p"
	.string "Lì si trova uno degli ALLENATORI che\n"
	.string "SCOTT chiama gli ASSI del PARCO.\p"
	.string "Il posto è diretto da un ALLENATORE\n"
	.string "ostile che chiamano SIRE PALAZZO.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Hai già sfidato il SIRE PALAZZO?\p"
	.string "Per testare lo spirito del rivale,\n"
	.string "si dice che utilizzi questi POKéMON:\p"
	.string "un POKéMON PIPISTRELLO di tipo VELENO\n"
	.string "e VOLANTE, un POKéMON PIGRIZIA di tipo\l"
	.string "NORMALE e un POKéMON TRASPORTO\l"
	.string "di tipo ACQUA e GHIACCIO.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Hai mai sfidato il SIRE PALAZZO\n"
	.string "quando fa sul serio?\p"
	.string "Quando lotta al massimo della potenza,\n"
	.string "si dice che utilizzi questi POKéMON:\p"
	.string "un POKéMON LEGGENDA di tipo FUOCO,\n"
	.string "un POKéMON PIGRIZIA di tipo NORMALE e\l"
	.string "un POKéMON AURORA di tipo ACQUA.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Scommetto che non lo sai!\p"
	.string "Lì si trova uno degli ALLENATORI che\n"
	.string "SCOTT chiama gli ASSI del PARCO.\p"
	.string "Il posto è diretto da un ALLENATORE\n"
	.string "intrepido che chiamano RE PIRAMIDE.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Hai già sfidato il RE PIRAMIDE?\p"
	.string "Per testare la potenza del rivale,\n"
	.string "si dice che utilizzi questi POKéMON:\p"
	.string "un POKéMON PICCO di tipo ROCCIA,\n"
	.string "un POKéMON ICEBERG di tipo GHIACCIO e\l"
	.string "un POKéMON FERRO di tipo ACCIAIO.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Hai già sfidato il RE PIRAMIDE\n"
	.string "quando fa sul serio?\p"
	.string "Quando combatte con grande vigore,\n"
	.string "si dice che utilizzi questi POKéMON:\p"
	.string "un POKéMON GELO di tipo GHIACCIO e\n"
	.string "VOLANTE, un POKéMON ELETTRICO di\l"
	.string "tipo ELETTRO e VOLANTE e un POKéMON\l"
	.string "FIAMMA di tipo FUOCO e VOLANTE.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Ci sono molti posti in cui puoi\n"
	.string "partecipare alle LOTTE in DOPPIO.\p"
	.string "Ma le SALE LOTTA in DOPPIO della\n"
	.string "TORRE LOTTA sono semplici!\p"
	.string "Sono pensate per imparare come\n"
	.string "disputare le LOTTE in DOPPIO nel\l"
	.string "PARCO LOTTA.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Devi stare in campana.\p"
	.string "Ho sentito che qui gli ALLENATORI\n"
	.string "sviluppano strategie finalizzate\l"
	.string "unicamente alle LOTTE in DOPPIO.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Quando hai preso la mano con le\n"
	.string "LOTTE in DOPPIO di questo posto,\l"
	.string "dovresti pensare a cimentarti in\l"
	.string "altre LOTTE in DOPPIO.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Nel SALONE LOTTA si riuniscono\n"
	.string "tanti tipi di ALLENATORI diversi.\p"
	.string "Pensa un po’… potresti\n"
	.string "imbatterti in un amico o in un fan!\l"
	.string "Guarda attentamente!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Entra nella SALA LOTTA MULTIPLA\n"
	.string "in LINK con un amico.\p"
	.string "Se il tuo amico è bravo, puoi aspettarti\n"
	.string "di trovare nemici forti!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Che capacità di raccogliere notizie!\n"
	.string "Il mio precettore non ha eguali!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Che spirito d’osservazione!\n"
	.string "Il mio precettore non ha eguali!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Che potere di persuasione!\n"
	.string "Il mio precettore non ha eguali!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "Che posto è questo?\n"
	.string "Mi spaventa…$"

