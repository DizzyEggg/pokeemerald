PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN è diventato il nuovo\n"
	.string "CAPOPALESTRA della città.\p"
	.string "Credo che abbia fatto venire la\n"
	.string "famiglia da una regione lontana.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "Ho sfidato NORMAN una volta,\n"
	.string "ma è troppo forte per me.\p"
	.string "Come posso spiegarmi?\p"
	.string "Ho l’impressione che viva\n"
	.string "per i POKéMON.$"

