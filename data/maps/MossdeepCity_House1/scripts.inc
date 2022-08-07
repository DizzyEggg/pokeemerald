MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Mhmm!\n"
	.string "Il tuo {STR_VAR_1}…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Va matto per la {STR_VAR_1},\n"
	.string "giusto?\p"
	.string "Anzi, non ho dubbi! Sicuramente sarà\n"
	.string "un patito della {STR_VAR_1}!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Non sembra prediligere nessuna\n"
	.string "{POKEMELLA}.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Mio marito con uno sguardo capisce\n"
	.string "quale {POKEMELLA} prediliga un POKéMON.$"

