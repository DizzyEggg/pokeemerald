PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "La corrente del mare che separa\n"
	.string "OROCEA e SELCEPOLI è molto forte.\p"
	.string "Se usi SURF, potrebbe trascinarti da\n"
	.string "qualche altra parte.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Hai visto che carine?\n"
	.string "Le casette sull’acqua!\p"
	.string "Io sono nato qui!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "La TORRE dei CIELI?\p"
	.string "Ah, sì, intendi quell’altissima torre\n"
	.string "che si trova da queste parti, vero?\p"
	.string "Io, non ci salirei.\n"
	.string "Ho paura ad andare così in alto.\p"
	.string "La vita sul livello del mare come a\n"
	.string "OROCEA è ciò che fa per me.$"

PacifidlogTown_Text_TownSign:
	.string "OROCEA\p"
	.string "“Dove il sole del mattino posa \n"
	.string "il suo sorriso sulle acque”.$"

