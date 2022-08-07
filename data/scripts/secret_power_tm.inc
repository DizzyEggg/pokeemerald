Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Che c’è?\n"
	.string "Cosa sto facendo?\p"
	.string "Pensavo di stabilire qui il mio ritrovo\n"
	.string "usando una mossa POKéMON.\p"
	.string "Sì! Ti darò questa MT.\n"
	.string "La userai per creare il tuo ritrovo?$"

Route111_Text_ExplainSecretPower:
	.string "Cerca un grosso albero dal quale\n"
	.string "ti sembra possano cadere dei tralci.\p"
	.string "Usa FORZASEGRETA di fronte all’albero.\n"
	.string "In questo modo scenderanno dei tralci\l"
	.string "con cui ti potrai arrampicare.\p"
	.string "Ci sarà un sacco di spazio e potrai\n"
	.string "metterci tutte le tue cose.\p"
	.string "Questo sarà il tuo ritrovo segreto.\n"
	.string "La tua BASE SEGRETA!\p"
	.string "Dai, fanne una anche tu!\p"
	.string "Ricordati, la BASE SEGRETA non deve\n"
	.string "essere necessariamente su un albero.\p"
	.string "Prova ad usare FORZASEGRETA\n"
	.string "su pareti rocciose con piccole \l"
	.string "rientranze.\p"
	.string "Anch’io cercherò degli altri posti.\n"
	.string "Ok, ciao!$"

Route111_Text_DontWantThis:
	.string "Non vuoi averla?\n"
	.string "Fammi sapere se cambi idea, ok?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, non hai più spazio.\p"
	.string "La conserverò per te, puoi venire\n"
	.string "a prenderla un’altra volta, ok?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM43
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
