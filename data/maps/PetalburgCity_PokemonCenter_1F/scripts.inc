.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Quel Sistema Memoria POKéMON del PC…\p"
	.string "Chiunque l’abbia inventato dev’essere\n"
	.string "un mago dell’informatica!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Mangiando una BACCARANCIA\n"
	.string "il mio POKéMON ha ripreso PS!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Ci sono molti tipi di POKéMON.\p"
	.string "Tutti i tipi hanno punti di forza e\n"
	.string "punti deboli contro gli altri tipi.\p"
	.string "In base ai tipi di POKéMON, una lotta\n"
	.string "può essere facile o difficile.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Ad esempio, il tuo TREECKO è\n"
	.string "di tipo ERBA.\p"
	.string "È forte contro i tipi ACQUA e\n"
	.string "TERRA.\p"
	.string "Ma è debole contro i POKéMON\n"
	.string "di tipo FUOCO.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Ad esempio, il tuo TORCHIC è\n"
	.string "di tipo FUOCO.\p"
	.string "È forte contro i tipi ERBA e\n"
	.string "COLEOTTERO.\p"
	.string "Ma è debole contro i POKéMON\n"
	.string "di tipo ACQUA.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Ad esempio, il tuo MUDKIP è\n"
	.string "di tipo ACQUA.\p"
	.string "È forte contro il tipo FUOCO.\p"
	.string "Ma è debole contro i POKéMON\n"
	.string "di tipo ERBA ed ELETTRO.$"

