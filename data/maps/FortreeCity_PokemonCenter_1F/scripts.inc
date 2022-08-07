.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Ehi, come va con il tuo POKéDEX?\p"
	.string "Uhmm… vai alla ZONA SAFARI sul\n"
	.string "PERCORSO 121. Te lo consiglio.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Hai visitato il BANCO REGISTRO?\p"
	.string "È troppo forte. Puoi scambiare e\n"
	.string "confrontare i tuoi dati ALLENATORE.\p"
	.string "Non so esattamente come funzioni,\n"
	.string "ma è esaltante!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Ehi, anche tu hai un POKéNAV!\n"
	.string "È proprio come il mio.\p"
	.string "Vorresti sapere qualcosa sulla fun-\n"
	.string "zione SFIDAFONINO del POKéNAV?\p"
	.string "Grazie a questa funzione puoi fare\n"
	.string "due chiacchiere con gli ALLENATORI\l"
	.string "registrati ogni volta che lo desideri.\p"
	.string "Inoltre, ti permette di vedere quali\n"
	.string "ALLENATORI vogliono combattere\l"
	.string "ancora con te.\p"
	.string "È davvero eccezionale! Quelli\n"
	.string "della DEVON sanno il fatto loro!$"

