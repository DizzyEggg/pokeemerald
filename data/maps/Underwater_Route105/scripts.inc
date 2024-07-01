# 1 "data/maps/Underwater_Route105/scripts.pory"

# 2 "data/maps/Underwater_Route105/scripts.pory"
Underwater_Route105_MapScripts::
# 3 "data/maps/Underwater_Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route105_OnResume
# 4 "data/maps/Underwater_Route105/scripts.pory"
	.byte 0
# 5 "data/maps/Underwater_Route105/scripts.pory"

# 6 "data/maps/Underwater_Route105/scripts.pory"
Underwater_Route105_OnResume:
# 7 "data/maps/Underwater_Route105/scripts.pory"
	call AbnormalWeather_Underwater_SetupEscapeWarp
# 8 "data/maps/Underwater_Route105/scripts.pory"
	end

Underwater_Route105_Sign1::
# 13 "data/maps/Underwater_Route105/scripts.pory"
	random 5
# 14 "data/maps/Underwater_Route105/scripts.pory"
	switch VAR_RESULT
# 15 "data/maps/Underwater_Route105/scripts.pory"
	case 0, Underwater_Route105_Sign1_2
# 16 "data/maps/Underwater_Route105/scripts.pory"
	case 1, Underwater_Route105_Sign1_3
# 17 "data/maps/Underwater_Route105/scripts.pory"
	case 2, Underwater_Route105_Sign1_4
# 18 "data/maps/Underwater_Route105/scripts.pory"
	case 3, Underwater_Route105_Sign1_5
# 19 "data/maps/Underwater_Route105/scripts.pory"
	case 4, Underwater_Route105_Sign1_6
	return

Underwater_Route105_Sign1_2:
# 15 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_0, MSGBOX_SIGN
	return

Underwater_Route105_Sign1_3:
# 16 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_1, MSGBOX_SIGN
	return

Underwater_Route105_Sign1_4:
# 17 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_2, MSGBOX_SIGN
	return

Underwater_Route105_Sign1_5:
# 18 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_3, MSGBOX_SIGN
	return

Underwater_Route105_Sign1_6:
# 19 "data/maps/Underwater_Route105/scripts.pory"
	msgbox Underwater_Route105_Sign1_Text_4, MSGBOX_SIGN
	return


Underwater_Route105_Sign1_Text_0:
# 15 "data/maps/Underwater_Route105/scripts.pory"
	.string "Panneau.$"

Underwater_Route105_Sign1_Text_1:
# 16 "data/maps/Underwater_Route105/scripts.pory"
	.string "Questo è un cartello.$"

Underwater_Route105_Sign1_Text_2:
# 17 "data/maps/Underwater_Route105/scripts.pory"
	.string "Esto es una señal.$"

Underwater_Route105_Sign1_Text_3:
# 18 "data/maps/Underwater_Route105/scripts.pory"
	.string "This is a signpost.$"

Underwater_Route105_Sign1_Text_4:
# 19 "data/maps/Underwater_Route105/scripts.pory"
	.string "German: TODO.$"
