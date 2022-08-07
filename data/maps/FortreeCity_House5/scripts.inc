FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Le case sugli alberi di FORESTOPOLI\n"
	.string "sono fantastiche!\p"
	.string "Credo che sia la città più adatta\n"
	.string "per vivere insieme ai POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "I POKéMON e la gente vivono in armonia\n"
	.string "con la natura.\p"
	.string "Non c’è bisogno di plasmare la natura\n"
	.string "al nostro stile di vita.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: ZigzagZigzag…!$"

