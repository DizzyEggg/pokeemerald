OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Lottando i POKéMON crescono di\n"
	.string "livello e si rinforzano.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Quando i tuoi POKéMON saranno più\n"
	.string "forti, riuscirai a viaggiare lontano.$"

