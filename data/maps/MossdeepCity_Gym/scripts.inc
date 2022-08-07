MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM04, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Ehi, come va CAMPIONE esordiente,\n"
	.string "{PLAYER}?\p"
	.string "I CAPIPALESTRA di qui usano POKéMON\n"
	.string "di tipo PSICO.\p"
	.string "Se utilizzi contro di loro POKéMON\n"
	.string "di tipo LOTTA o VELENO, subirai\l"
	.string "notevoli danni!\p"
	.string "Inoltre, ti sfideranno con attacchi\n"
	.string "in accoppiata formidabili.\p"
	.string "Se vuoi vincere, devi dimostrare\n"
	.string "il controllo che eserciti sui tuoi\l"
	.string "POKéMON. Forza!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, sei incredibile!\n"
	.string "Sei un ALLENATORE fantastico!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "La lotta dipende dalla presenza\n"
	.string "di spirito: senza non si vince!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Ho perso! Devo ritemprare il mio spirito!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Chi tentenna, perde.\n"
	.string "È un avvertimento.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Mostra il tuo talento!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Il tuo talento è fuori del comune!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "I nostri CAPIPALESTRA sono\n"
	.string "indubbiamente un portento!\p"
	.string "Ciò non toglie che tu possa avere più\n"
	.string "talento di loro…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… faccio levitare una POKé\n"
	.string "BALL telecineticamente!\p"
	.string "Rooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "A volte mi manca la sincronizzazione…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Devo sincronizzare meglio le mie\n"
	.string "tecniche di lotta con i POKéMON!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "La POKé BALL è troppo pesante da far\n"
	.string "levitare con la psiche…\p"
	.string "Ma i riccioli di polvere…\n"
	.string "Ooooooooooooooooh!\p"
	.string "No, non sto barando!\n"
	.string "Non ci ho soffiato sopra, giuro!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Se perdi con me, non prendertela\n"
	.string "troppo.\p"
	.string "Non è che tu sia debole… è che io sono\n"
	.string "troppo forte!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Sei troppo forte!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Non porterò rancore… devo solo\n"
	.string "allenarmi di più.\p"
	.string "Penso positivo: questa è la mia forza!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Vedo…\n"
	.string "vedo il tuo futuro…\p"
	.string "Se riesci a battermi, predirò\n"
	.string "il tuo avvenire!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Mi arrendo!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "La lotta con i nostri CAPIPALESTRA\n"
	.string "sarà molto intensa…\p"
	.string "Il risultato…\n"
	.string "non sarò certo io a raccontartelo!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Le strade che hai percorso…\n"
	.string "il tuo ricco bagaglio di esperienze…\p"
	.string "Fammi vedere tutto quello che\n"
	.string "sai fare!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Hai percorso un cammino grandioso!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Chi ha lavorato diligentemente ha\n"
	.string "un futuro brillante davanti a sé.\p"
	.string "Per chi ha poltrito, la strada è\n"
	.string "più in salita.\p"
	.string "Ognuno di noi raccoglie ciò che\n"
	.string "ha seminato…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Vincerò anche a costo della mia stessa\n"
	.string "vita!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Hai fatto…\n"
	.string "una cosa orribile…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Come osi battermi?\p"
	.string "Se ti succede qualcosa di brutto,\n"
	.string "sappi che non è colpa mia…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Ohohoh.\p"
	.string "Vuoi vedere quanto tenaci sono i\n"
	.string "POKéMON di tipo PSICO?$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Non posso crederci!\n"
	.string "Il tuo stile di lotta è eccezionale!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Per quanto dura sia la sconfitta…\n"
	.string "non mi lascerò abbattere.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Preparati a sperimentare\n"
	.string "l’orrore nudo e crudo!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "Noooooooo!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "La tua vitalità è contagiosa!\n"
	.string "Allontanati da me immediatamente!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Io non sono più nel fiore degli anni,\n"
	.string "ma tu non fare l’arrogante.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, sprizzi giovinezza da tutti i pori!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Non sono riuscito ad avere il\n"
	.string "sopravvento sulla tua vitalità.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Non arriverai fino alla fine!\n"
	.string "Sarò io ad impedirtelo!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "È assurdo, non puoi essere così forte!$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Sei forte, ma il tipo PSICO non fa al\n"
	.string "caso tuo.\p"
	.string "Il tuo stile di lotta è… aggressivo!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Rooooar! Vuoi un assaggio della forza\n"
	.string "dei miei POKéMON in lotta?$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh!\n"
	.string "Sono esausto!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Dovrò fare in modo che i miei POKéMON\n"
	.string "diventino invincibili.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TELL: Eheheheh… non te l’aspettavi?\p"
	.string "PAT: Fufufu… non te l’aspettavi?\p"
	.string "TELL: Di trovare due CAPIPALESTRA?\n"
	.string "PAT: Di trovare due CAPIPALESTRA?\p"
	.string "TELL: Siamo gemelli!\n"
	.string "PAT: Siamo gemelli!\p"
	.string "TELL: Non abbiamo bisogno di parlarci…\n"
	.string "PAT: Perché ognuno di noi…\p"
	.string "TELL: Legge nel pensiero dell’altro…\n"
	.string "PAT: È tutto nelle nostre menti!\p"
	.string "TELL: Siamo molto affiatati…\n"
	.string "PAT: Vediamo se riesci a batterci!$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TELL: Che cosa?! La nostra accoppiata…\n"
	.string "PAT: È stata sconfitta!\p"
	.string "TELL: Hai vinto, così stanno le cose…\n"
	.string "PAT: In riconoscimento, prendi questo.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} riceve la MEDAGLIA MENTE\n"
	.string "da TELL e PAT.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TELL: La MEDAGLIA MENTE potenzia\n"
	.string "l’ATT. SP. e la DIF. SP. dei POKéMON.\p"
	.string "PAT: Ti permette anche di usare\n"
	.string "la mossa MN SUB fuori dalla lotta.\p"
	.string "TELL: Prendi anche questo.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TELL: Questa MT04 contiene…\n"
	.string "PAT: CALMAMENTE!\p"
	.string "TELL: Aumenta l’ATT. SP. e…\n"
	.string "PAT: La DIF. SP.!\p"
	.string "TELL: È una mossa perfetta…\n"
	.string "PAT: Per i POKéMON di tipo PSICO!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Registrazione dei CAPIPALESTRA TELL e\n"
	.string "PAT nel POKéNAV avvenuta.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TELL: Credo che il legame che ti unisce\n"
	.string "ai tuoi POKéMON sia molto più forte del\l"
	.string "nostro.\p"
	.string "PAT: Sarai sempre più forte! Ti abbiamo\n"
	.string "sfidato, parliamo con cognizione.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TELL: Eheheh… non te l’aspettavi…\p"
	.string "PAT: Di trovare due CAPIPALESTRA?\p"
	.string "TELL: Oops, hai soltanto…\n"
	.string "PAT: Un POKéMON che può lottare.\p"
	.string "TELL: Non possiamo sfidarti così!\p"
	.string "PAT: Se vuoi lottare con noi,\n"
	.string "rimpingua la tua squadra POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "PALESTRA POKéMON di VERDEAZZUPOLI$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "PALESTRA POKéMON di VERDEAZZUPOLI\p"
	.string "ALLENATORE CERTIFICATO da TELL e PAT:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TELL: POKéMON…\n"
	.string "PAT: POKéMON…\p"
	.string "TELL: Cambiando la composizione\n"
	.string "della squadra…\l"
	.string "PAT: Cambia lo stile di lotta.\p"
	.string "TELL: Io…\n"
	.string "PAT: Io…\p"
	.string "TELL: Sarò sempre con PAT!\n"
	.string "PAT: Sarò sempre con TELL!\p"
	.string "TELL: La nostra accoppiata…\n"
	.string "PAT: Esisterà sempre!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TELL: Tu e i tuoi POKéMON…\n"
	.string "PAT: Sembra esserci un legame di sangue.$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TELL: Ci hai mandato a tappeto,\n"
	.string "ma noi ci rimetteremo in piedi!\p"
	.string "PAT: Perché noi due siamo \n"
	.string "sempre qui l’uno per l’altra!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TELL: Eccoci ancora qui…\n"
	.string "PAT: Eccoci ancora qui…\p"
	.string "TELL: Per una nuova sfida.\n"
	.string "PAT: Per una nuova sfida.\p"
	.string "TELL: Ma…\n"
	.string "PAT: Per la sfida…\p"
	.string "TELL: Tu hai portato solo un POKéMON!\n"
	.string "PAT: Tu hai portato solo un POKéMON!\p"
	.string "TELL: Ci vorranno almeno…\n"
	.string "PAT: Due POKéMON la prossima volta.$"
