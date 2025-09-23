MansionFloor3RoomBoss_MapScripts::
	.byte 0


MansionFloor3RoomBoss_Eventscript_BrokenGlass::
	msgbox MansionFloor3RoomBoss_Text_BrokenGlass, MSGBOX_NPC
	end

MansionFloor3RoomBoss_Text_BrokenGlass:
	.string "There's a lot of broken glass here.\p"
	.string "Wait, this is it… This is the window that\n"
	.string "Craftily's goons throw you out of.\p"
	.string "You can see the Inkwell down there.$"


MansionFloor3RoomBoss_Eventscript_Window::
	msgbox MansionFloor3RoomBoss_Text_Window, MSGBOX_NPC
	end

@TOFOLD
MansionFloor3RoomBoss_Text_Window:
	.string "You've been through this window before.$"
