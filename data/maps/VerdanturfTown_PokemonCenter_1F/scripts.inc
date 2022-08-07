.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Chi non ha fiducia nei propri POKéMON,\n"
	.string "non può considerarsi un vero\l"
	.string "ALLENATORE.\p"
	.string "Solo coloro che credono nei POKéMON\n"
	.string "che mandano in campo possono \l"
	.string "sperare di uscirne vittoriosi.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "Il motivo che spinge chiunque a\n"
	.string "venire a MENTANIA…\p"
	.string "è il TENDONE LOTTA. Non ci piove.\p"
	.string "O sei qui per far visita a qualcuno?$"

