.set LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Sono l’ESPERTO FOSSILI, un tipo\n"
	.string "simpatico che ama i FOSSILI.\p"
	.string "Vorresti un FOSSILE?\p"
	.string "Spiacente, ma questi FOSSILI sono\n"
	.string "tutti miei… non ce ne sono per te…\p"
	.string "Se proprio ne vuoi uno, guarda nel\n"
	.string "deserto dove i massi e la sabbia\l"
	.string "potrebbero celare dei FOSSILI…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Hai trovato un FOSSILE, vero?\n"
	.string "Che bello… è una cosa straordinaria…\p"
	.string "Cosa ne farai adesso?\p"
	.string "Da quanto ne so, la DEVON conduce\n"
	.string "una ricerca per far rigenerare\l"
	.string "i POKéMON dai FOSSILI…\p"
	.string "Io amo i miei FOSSILI e non farei\n"
	.string "mai una cosa del genere…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "I FOSSILI sono… meravigliosi… sono\n"
	.string "una cosa straordinaria…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh!\n"
	.string "Non è sicuro avventurarsi lì dentro…\p"
	.string "Stavo scavando e all’improvviso la\n"
	.string "parete è crollata…\p"
	.string "Credo che al di sotto ci sia\n"
	.string "una grotta gigante…\p"
	.string "Ma non mi ci sono addentrato perché\n"
	.string "non credo che ci siano dei FOSSILI…$"

