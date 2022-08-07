SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM49, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM49
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM49
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Oh, c’è un letto!\n"
	.string "Meglio riposarsi un po’…$"

SSTidalRooms_Text_ColtonIntro:
	.string "Mi reco spesso a PORTO ALGHEPOLI!\p"
	.string "Il mio hobby sono le GARE POKéMON.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Che bella lotta!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "È così emozionante immaginare quali\n"
	.string "POKéMON si esibiranno nella prossima\l"
	.string "GARA. Sono così ansioso!$"

SSTidalRooms_Text_MicahIntro:
	.string "Sono forti i tuoi amici?$"

SSTidalRooms_Text_MicahDefeat:
	.string "In effetti i tuoi amici sono forti!$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Ci sono tanti tipi di amici. I miei\n"
	.string "migliori amici sono i POKéMON!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Puah! Bambini…\n"
	.string "Hai bussato alla porta?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "La sconfitta va presa con filosofia.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Un GENTILUOMO non si scompone\n"
	.string "mai… in nessuna situazione!$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Mi sento un pochino a disagio, ma…\n"
	.string "ti mostreremo la forza delle coccole!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Oh, no…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: È la prima volta che la forza delle\n"
	.string "coccole non ha la meglio! Devi essere\l"
	.string "un ALLENATORE in gamba!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Ma hai soltanto un POKéMON?\n"
	.string "Non si sente un pochino solo?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Mi sento un po’ sciocca, ma… ti\n"
	.string "mostreremo la forza delle coccole!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Oh, no!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Non posso crederci!\n"
	.string "La forza delle coccole non ha vinto!\l"
	.string "Allora sei un ALLENATORE in gamba!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Mi andava di lottare, ma… non\n"
	.string "hai nemmeno due POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, giusto in tempo…\p"
	.string "Che noia! Magari possiamo ingannare\n"
	.string "il tempo lottando…$"

SSTidalRooms_Text_GarretDefeat:
	.string "Può bastare!$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Magari posso farmi comprare\n"
	.string "uno yacht da papà…\l"
	.string "uno yacht per me ed il mio POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Sei un ALLENATORE interessante!\n"
	.string "Vuoi un caffè?\l"
	.string "O preferisci lottare?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Capisco…\n"
	.string "Hai molta energia!$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Una crociera attorno al mondo su\n"
	.string "una nave di lusso ha il suo fascino…\p"
	.string "Ma altrettanto interessante è girare\n"
	.string "per la regione di HOENN in traghetto!$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Ah… ciao! No, non sto facendo nulla\n"
	.string "di sospetto! Tieni questo, è gratis!\p"
	.string "Io… davvero, non ho rubato nulla a\n"
	.string "nessuno, io! Non lo farei mai!\l"
	.string "È merce pulita! Puoi usarla tu!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "SCIPPO ruba la mossa al nemico per\n"
	.string "usarla successivamente.$"

