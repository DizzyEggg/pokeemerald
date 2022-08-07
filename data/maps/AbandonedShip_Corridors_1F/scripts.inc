AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Con la mia ciambella a bordo\n"
	.string "sono imbattibile…$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Colpito e affondato!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Non è facile tirare le POKé BALL mentre\n"
	.string "sei aggrappato a una ciambella!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Non trovi che sia bello qui?\n"
	.string "Io non sto nella pelle!$"
