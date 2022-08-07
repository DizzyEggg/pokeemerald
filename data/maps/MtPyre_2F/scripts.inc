MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Quando penso al mio SKITTY adorato…\n"
	.string "mi si riempiono gli occhi di lacrime.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ahimè… qui e lì ci sono buche\n"
	.string "nel terreno.\p"
	.string "Non me ne sono accorto e\n"
	.string "sono precipitato!$"

MtPyre_2F_Text_MarkIntro:
	.string "Ehi! Stai cercando POKéMON?\n"
	.string "Mi vieni appresso! Non è carino!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ahhhhhh!\n"
	.string "Perdono, ti prego!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Essendo un’area poco battuta, credevo\n"
	.string "di trovarci POKéMON rari.$"

MtPyre_2F_Text_LukeIntro:
	.string "KEN: Siamo qui per fare una sfida.\p"
	.string "Eheheh, se le faccio vedere che\n"
	.string "mito sono, si innamorerà di me!\p"
	.string "Vincerò alla grande e le farò vedere\n"
	.string "di che pasta sono fatto!$"

MtPyre_2F_Text_LukeDefeat:
	.string "KEN: Che gaffe!$"

MtPyre_2F_Text_LukePostBattle:
	.string "KEN: Beh, abbiamo perso, ma va bene\n"
	.string "lo stesso! Siamo una coppia di ferro!\l"
	.string "Questa sfida non potrà dividerci!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "KEN: Se vuoi lottare con me,\n"
	.string "porta più POKéMON.\p"
	.string "Se non lo fai, non potrò dimostrare alla\n"
	.string "mia ragazza che tipo tosto sono!$"

MtPyre_2F_Text_DezIntro:
	.string "DESI: Sono venuta qui con il mio ragazzo\n"
	.string "per fare una sfida.\p"
	.string "Ho molta paura, ma con il mio ragazzo\n"
	.string "non ho nulla da temere.\p"
	.string "Il mio ragazzo farà un figurone\n"
	.string "stracciandoti nella lotta!$"

MtPyre_2F_Text_DezDefeat:
	.string "DESI: Aaaaah! Ho paura!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DESI: Siamo una coppia molto coccolona,\n"
	.string "non ci importa perdere!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DESI: Se ci vuoi sfidare, devi avere\n"
	.string "con te almeno due POKéMON.\p"
	.string "Il mio ragazzo è forte.\n"
	.string "Un solo POKéMON non basta.$"

MtPyre_2F_Text_LeahIntro:
	.string "Non sei una faccia conosciuta…\n"
	.string "Vattene prima che ti succeda qualcosa!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Mmm… sei resistente.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "I miei familiari sono ALLENATORI qui\n"
	.string "da tre generazioni…\p"
	.string "È mio dovere proteggere questa\n"
	.string "montagna…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Aahh!\n"
	.string "Che orrore!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Nooooooo!\n"
	.string "Sono sconvolto!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Mi agito tutte le volte che vedo\n"
	.string "qualcosa muoversi…\p"
	.string "Non sarei dovuto venire qui ad\n"
	.string "allenarmi…$"

