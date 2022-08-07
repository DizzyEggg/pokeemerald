BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Chissà se oggi mandano in onda\n"
	.string "interviste con ALLENATORI forti…$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Aprendo un ristorante qui, si\n"
	.string "farebbero soldi a palate.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Eheh…\p"
	.string "Dopo aver lottato così intensamente\n"
	.string "ho bisogno di una pausa…\p"
	.string "Ma anche quando mi riposo, non\n"
	.string "smetto mai di inventare nuove\l"
	.string "strategie e combo.$"

