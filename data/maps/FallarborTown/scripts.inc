FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Che cosa succede?\p"
	.string "Ho visto dei tipi loschi entrare e uscire\n"
	.string "dalla casa del PROF. COSMI.$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Questa regione è conosciuta fin dai\n"
	.string "tempi antichi per i meteoriti.\p"
	.string "Si dice che le CASCATE METEORA siano\n"
	.string "sorte dalla caduta di un meteorite.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Ehi, guarda!\n"
	.string "Questo è il mio prezioso AZURILL!\p"
	.string "È dolce e tanto coccolone!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Azuriiiiill!$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Hai già sfidato FIAMMETTA,\n"
	.string "CAPOPALESTRA di CUORDILAVA?\p"
	.string "Suo nonno era molto famoso.\n"
	.string "È stato uno dei SUPERQUATTRO della\l"
	.string "LEGA POKéMON per un po’.\p"
	.string "Non mi sorprenderebbe vedere\n"
	.string "FIAMMETTA diventare un grandissimo\l"
	.string "ALLENATORE.$"

FallarborTown_Text_BattleTentSign:
	.string "TENDONE LOTTA di BRUNIFOGLIA\n"
	.string "“Dove si incontrano i migliori!”.$"

FallarborTown_Text_TownSign:
	.string "BRUNIFOGLIA\n"
	.string "“Comunità rurale ricca di piccoli\l"
	.string "giardini”.$"

FallarborTown_Text_MoveTutorSign:
	.string "CASA della GUIDA MOSSE\n"
	.string "“Si insegnano nuove mosse ai POKéMON”.$"

