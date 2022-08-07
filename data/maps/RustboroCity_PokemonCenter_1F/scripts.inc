.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Il mio POKéMON ha una natura INGENUA.\n"
	.string "Quello del mio amico ha una natura\l"
	.string "ALLEGRA.\p"
	.string "È affascinante vedere come i POKéMON\n"
	.string "abbiano la loro personalità!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Come per gli esseri umani, ci sono\n"
	.string "POKéMON maschio e femmina.\p"
	.string "Ma nessuno ha mai capito che cosa\n"
	.string "li renda differenti.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "L’uomo che vive qui accanto\n"
	.string "mi ha dato una MN!\p"
	.string "È TAGLIO. L’ho usata per\n"
	.string "insegnare al mio POKéMON come\l"
	.string "tagliare alberi piccoli.$"

