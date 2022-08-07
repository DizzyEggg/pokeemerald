PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Gira voce di un POKéMON che vola\n"
	.string "nei cieli della regione di HOENN.\p"
	.string "Chissà se vola senza sosta!\n"
	.string "Chissà se non si riposa mai!$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Un POKéMON in cielo!\n"
	.string "Un POKéMON in cielo!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Puoi dirmi da dove vieni?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Vieni da SÌ?\n"
	.string "È una città?\p"
	.string "Mai sentito di una città con quel nome.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Non me lo dici?\n"
	.string "Verrai pure da qualche posto.\p"
	.string "Oh! Un momento… non vorrai darmi\n"
	.string "a bere che vieni dagli abissi marini?!$"

