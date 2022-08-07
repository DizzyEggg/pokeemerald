PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Oggi l’ISOLA MIRAGGIO non si vede…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh! Incredibile!\n"
	.string "Oggi l’ISOLA MIRAGGIO si vede!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "ISOLA MIRAGGIO…\p"
	.string "Si vede e non si vede, a seconda delle\n"
	.string "condizioni meteo che creano il miraggio.\p"
	.string "O magari appare e scompare?$"

