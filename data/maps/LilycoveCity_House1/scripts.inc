LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
	.string "I POKéMON sono compagni dell’uomo.\n"
	.string "Non sono semplici strumenti.\p"
	.string "Sfortunatamente, ci sono persone\n"
	.string "che non lo capiscono…$"

LilycoveCity_House1_Text_Kecleon:
	.string "KECLEON: Keecleeoon?$"

