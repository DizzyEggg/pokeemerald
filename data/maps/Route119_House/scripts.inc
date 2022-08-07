Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "Ho sentito parlare di una grotta\n"
	.string "chiamata GROTTA dei TEMPI.\p"
	.string "Si dice che lì sia possibile resuscitare\n"
	.string "gli spiriti dei POKéMON. Ma sarà vero?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Wiinngguull!$"

