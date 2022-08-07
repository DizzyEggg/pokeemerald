.set LOCALID_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Qualche suggerimento per la lotta?\p"
	.string "Beh, allevare tipi diversi di POKéMON\n"
	.string "in modo equilibrato.\p"
	.string "Non è consigliabile rafforzare solo\n"
	.string "un POKéMON.\p"
	.string "Se ha qualche punto debole, potrebbe\n"
	.string "trovarsi in difficoltà.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Io scambio POKéMON con i miei amici.\p"
	.string "Se un POKéMON scambiato tiene uno\n"
	.string "strumento, la mia felicità raddoppia!$"

