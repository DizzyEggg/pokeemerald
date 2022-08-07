LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Mia moglie sta facendo schiudere\n"
	.string "un UOVO alle sorgenti termali.\l"
	.string "Almeno così mi ha detto…\p"
	.string "Ha lasciato due POKéMON alla PENSIONE\n"
	.string "POKéMON e le hanno dato un UOVO!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON: ZigzagZigzag!$"

