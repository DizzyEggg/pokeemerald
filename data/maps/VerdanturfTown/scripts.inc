.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Me l’ha detto il mio papà.\p"
	.string "Questo tunnel è pieno di POKéMON\n"
	.string "timorosi.\p"
	.string "Si spaventano per i rumori forti e\n"
	.string "si agitano moltissimo.\p"
	.string "Per questo hanno dovuto interrompere\n"
	.string "gli scavi.\p"
	.string "Ma c’è un uomo che sta cercando di\n"
	.string "scavare il tunnel da solo!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "C’era un uomo che scavava un tunnel\n"
	.string "per la donna amata.\p"
	.string "È una cosa che non capisco,\n"
	.string "ma è davvero ammirevole.$"

VerdanturfTown_Text_AirCleanHere:
	.string "La direzione del vento impedisce alla\n"
	.string "cenere vulcanica di arrivare fin qui.\p"
	.string "L’aria è fresca e pulita.\n"
	.string "Vivere qui è un toccasana per\l"
	.string "le persone fragili e malate.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "La mia squadra di POKéMON ed io\n"
	.string "abbiamo una lunga serie di vittorie\l"
	.string "alle nostre spalle.\p"
	.string "Quindi ho deciso di farla debuttare\n"
	.string "al TENDONE LOTTA.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Hai visto la grotta vicino\n"
	.string "al POKéMON-MARKET?\p"
	.string "C’è un tizio che sta spostando dei massi\n"
	.string "perché vuole riuscire a passare\l"
	.string "dall’altra parte.\p"
	.string "Se potessimo passare di lì, andare a\n"
	.string "FERRUGIPOLI diventerebbe facile!$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "La grotta vicino al POKéMON-MARKET\n"
	.string "è ora un tunnel che porta dall’altra\l"
	.string "parte.\p"
	.string "È fantastico! Si possono andare \n"
	.string "a comprare i prodotti DEVON\l"
	.string "a FERRUGIPOLI.$"

VerdanturfTown_Text_TownSign:
	.string "MENTANIA\p"
	.string "“Un altopiano spazzato dal vento\n"
	.string "che profuma di erba fresca”.$"

VerdanturfTown_Text_WandasHouse:
	.string "CASA di LINDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "TENDONE LOTTA di MENTANIA\n"
	.string "“Il posto ideale per chi ama le lotte!”.$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TUNNEL MENFERRO\n"
	.string "“Collega FERRUGIPOLI e MENTANIA.\p"
	.string "Progetto per il tunnel sospeso”.$"

