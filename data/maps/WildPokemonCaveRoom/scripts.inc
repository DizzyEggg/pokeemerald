WildPokemonCaveRoom_MapScripts::
# 2 "data/maps/WildPokemonCaveRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WildPokemonCaveRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

WildPokemonCaveRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/WildPokemonCaveRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, VAR_VALUE_GOT_KOED, Script_BidoofHeal_Underwater_GotKOedByWild
	.2byte 0


WildPokemonCaveRoom_Sign::
# 8 "data/maps/WildPokemonCaveRoom/scripts.pory"
	msgbox WildPokemonCaveRoom_Sign_Text_0, MSGBOX_SIGN
	end


WildPokemonCaveRoom_Sign_Text_0:
# 8 "data/maps/WildPokemonCaveRoom/scripts.pory"
	.string "Wild Pokemon can be found here.$"
