Underwater_MarineCave_MapScripts::
# 2 "data/maps/Underwater_MarineCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_MarineCave_OnResume
# 3 "data/maps/Underwater_MarineCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_MarineCave_OnTransition
	.byte 0


Underwater_MarineCave_TriggerScript::
# 7 "data/maps/Underwater_MarineCave/scripts.pory"
	lock
# 8 "data/maps/Underwater_MarineCave/scripts.pory"
	msgbox Underwater_MarineCave_TriggerScript_Text_0, MSGBOX_YESNO
# 9 "data/maps/Underwater_MarineCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Underwater_MarineCave_TriggerScript_2
Underwater_MarineCave_TriggerScript_1:
# 24 "data/maps/Underwater_MarineCave/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_GoDown
# 25 "data/maps/Underwater_MarineCave/scripts.pory"
	waitmovement 0
# 26 "data/maps/Underwater_MarineCave/scripts.pory"
	release
	end

Underwater_MarineCave_TriggerScript_2:
# 10 "data/maps/Underwater_MarineCave/scripts.pory"
	msgbox Underwater_MarineCave_TriggerScript_Text_1, MSGBOX_YESNO
# 11 "data/maps/Underwater_MarineCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Underwater_MarineCave_TriggerScript_4
	goto Underwater_MarineCave_TriggerScript_1

Underwater_MarineCave_TriggerScript_4:
# 12 "data/maps/Underwater_MarineCave/scripts.pory"
	msgbox Underwater_MarineCave_TriggerScript_Text_2, MSGBOX_YESNO
# 13 "data/maps/Underwater_MarineCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Underwater_MarineCave_TriggerScript_6
	goto Underwater_MarineCave_TriggerScript_1

Underwater_MarineCave_TriggerScript_6:
# 14 "data/maps/Underwater_MarineCave/scripts.pory"
	msgbox Underwater_MarineCave_TriggerScript_Text_3
# 15 "data/maps/Underwater_MarineCave/scripts.pory"
	fadeoutbgm 5
# 16 "data/maps/Underwater_MarineCave/scripts.pory"
	delay 30
# 17 "data/maps/Underwater_MarineCave/scripts.pory"
	msgbox Underwater_MarineCave_TriggerScript_Text_4
# 18 "data/maps/Underwater_MarineCave/scripts.pory"
	setvar VAR_HACK_GAME_STATE, 16
# 19 "data/maps/Underwater_MarineCave/scripts.pory"
	release
	end


# 30 "data/maps/Underwater_MarineCave/scripts.pory"
Movement_GoDown:
# 31 "data/maps/Underwater_MarineCave/scripts.pory"
	walk_down
# 32 "data/maps/Underwater_MarineCave/scripts.pory"
	step_end

# 35 "data/maps/Underwater_MarineCave/scripts.pory"

# 36 "data/maps/Underwater_MarineCave/scripts.pory"
Underwater_MarineCave_OnTransition:
# 37 "data/maps/Underwater_MarineCave/scripts.pory"
	setflag FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT
# 38 "data/maps/Underwater_MarineCave/scripts.pory"
	end
# 39 "data/maps/Underwater_MarineCave/scripts.pory"

# 40 "data/maps/Underwater_MarineCave/scripts.pory"
Underwater_MarineCave_OnResume:
# 41 "data/maps/Underwater_MarineCave/scripts.pory"
	setdivewarp MAP_MARINE_CAVE_ENTRANCE, 10, 17
# 42 "data/maps/Underwater_MarineCave/scripts.pory"
	end

Underwater_MarineCave_TriggerScript_Text_0:
# 8 "data/maps/Underwater_MarineCave/scripts.pory"
	.string "Would you like to emerge?$"

Underwater_MarineCave_TriggerScript_Text_1:
# 10 "data/maps/Underwater_MarineCave/scripts.pory"
	.string "That means leaving the Underwater. Do\n"
	.string "you really want to leave?$"

Underwater_MarineCave_TriggerScript_Text_2:
# 12 "data/maps/Underwater_MarineCave/scripts.pory"
	.string "Are you sure???$"

Underwater_MarineCave_TriggerScript_Text_3:
# 14 "data/maps/Underwater_MarineCave/scripts.pory"
	.string "{PLAYER} is about to emerge!$"

Underwater_MarineCave_TriggerScript_Text_4:
# 17 "data/maps/Underwater_MarineCave/scripts.pory"
	.string "But it failed!\pT{PAUSE 30}-H{PAUSE 30}-E{PAUSE 30}-R{PAUSE 30}-E I{PAUSE 30}-S N{PAUSE 30}-O E{PAUSE 30}-S{PAUSE 30}-C{PAUSE 30}-A{PAUSE 30}-P-{PAUSE 30}I-N{PAUSE 30}-G\n{COLOR BLUE}UNDERWATER{COLOR DARK_GRAY}$"
