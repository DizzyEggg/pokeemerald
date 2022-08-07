Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Il TUNNEL MENFERRO…\p"
	.string "All’inizio eravamo un’enorme squadra\n"
	.string "che scavava con macchinari moderni.\l"
	.string "Ma, poi, ci siamo dovuti fermare.\p"
	.string "Ci siamo accorti che avremmo arrecato\n"
	.string "danno ai POKéMON selvatici della zona.\p"
	.string "E adesso non abbiamo nulla da fare\n"
	.string "se non girarci i pollici…$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "C’è un tizio che sta scavando per\n"
	.string "raggiungere MENTANIA… tutto da \l"
	.string "solo… è disperato…\p"
	.string "Dice che scava un po’ per volta senza\n"
	.string "macchine, per non disturbare i POKéMON\l"
	.string "e per non danneggiare l’ambiente.\p"
	.string "Mi chiedo se ce l’abbia fatta.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Per arrivare a MENTANIA senza\n"
	.string "passare di qua, devi raggiungere\l"
	.string "BLURUVIA, di lì salpare per SELCEPOLI\l"
	.string "ed attraversare CICLAMIPOLI.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Sentito? È stato ultimato il TUNNEL\n"
	.string "per MENTANIA!\p"
	.string "Talvolta se speri intensamente,\n"
	.string "i sogni diventano realtà.$"

