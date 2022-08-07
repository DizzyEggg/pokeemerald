DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "C’è molto da dire sulla vita su\n"
	.string "un’isoletta come questa, in perfetta\l"
	.string "armonia con i POKéMON e la famiglia.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Prima abitavo nella grande città\n"
	.string "portuale di PORTO SELCEPOLI,\l"
	.string "poi mi sono sposata e sono venuta qui.\p"
	.string "La vita scorre lenta su quest’isoletta.\n"
	.string "Ma lo stupendo mare che la circonda\l"
	.string "infonde gioia e serenità.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: ZigzagZigzag!$"

