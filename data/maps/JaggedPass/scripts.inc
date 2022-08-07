.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "PASSO SELVAGGIO del MONTE CAMINO…\p"
	.string "È tutto quello che ho sempre desiderato\n"
	.string "in montagna.\p"
	.string "Queste irregolarità selvagge…\n"
	.string "scuotono la mia anima!$"

JaggedPass_Text_EricDefeat:
	.string "Perdere mi lascia l’amaro in bocca!$"

JaggedPass_Text_EricPostBattle:
	.string "Sì, ho perso con i POKéMON…\p"
	.string "Ma in quanto ad amore per la montagna,\n"
	.string "non mi batte nessuno!$"

JaggedPass_Text_DianaIntro:
	.string "Questo posto non è adatto a scalatori\n"
	.string "improvvisati.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, no!\n"
	.string "Il terreno è troppo accidentato…$"

JaggedPass_Text_DianaPostBattle:
	.string "Lo sapevi?\p"
	.string "Alcune persone vanno in bicicletta\n"
	.string "per questo passo tanto sconnesso.$"

JaggedPass_Text_DianaRegister:
	.string "Tornerai ancora da queste parti?\n"
	.string "Mi piacerebbe sfidarti di nuovo.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Adoro fare i picnic… e con i POKéMON la\n"
	.string "scampagnata è ancora più divertente!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Ho perso perché il terreno\n"
	.string "è troppo accidentato!$"

JaggedPass_Text_DianaPostRematch:
	.string "Dimentico la sconfitta e mi godo\n"
	.string "questa bella escursione.$"

JaggedPass_Text_EthanIntro:
	.string "Il PASSO SELVAGGIO non è adatto per\n"
	.string "camminare, ma è ottimo per allenarsi.$"

JaggedPass_Text_EthanDefeat:
	.string "È finito tutto prima che riuscissimo\n"
	.string "a rompere il ghiaccio…$"

JaggedPass_Text_EthanPostBattle:
	.string "Se avessi una BICI da CROSS, potrei\n"
	.string "discendere o risalire questi salti.$"

JaggedPass_Text_EthanRegister:
	.string "Se riesco ad abituarmi a questo terreno\n"
	.string "accidentato, vincerò di sicuro!\p"
	.string "Vuoi registrarmi nel tuo POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Ormai il terreno sconnesso non mi fa più\n"
	.string "paura! Ora canto mentre mi arrampico.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Non è facile lottare su questo\n"
	.string "terreno così accidentato…$"

JaggedPass_Text_EthanPostRematch:
	.string "Dovrei andare a prendere una BICI da\n"
	.string "CROSS da CLELIO a CICLAMIPOLI…$"

JaggedPass_Text_GruntIntro:
	.string "Ah!\n"
	.string "Che cosa ci fai tu qui?\p"
	.string "Che ci faccio io in un posto così?\p"
	.string "Sono affari tuoi?$"

JaggedPass_Text_GruntDefeat:
	.string "Rrrr…\p"
	.string "Avrei dovuto scomparire nel nostro\n"
	.string "RIFUGIO immediatamente…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Sì, lo ammetto!\n"
	.string "Sei forte!\p"
	.string "Non pensare a me.\n"
	.string "Vai dove vuoi!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Il masso si muove grazie allo\n"
	.string "STEMMA MAGMA!$"

JaggedPass_Text_JulioIntro:
	.string "Wow! Che paura precipitarsi giù per la\n"
	.string "montagna tutto d’un fiato!$"

JaggedPass_Text_JulioDefeat:
	.string "Sento che sto andando a pezzi…$"

JaggedPass_Text_JulioPostBattle:
	.string "Ho fatto tanti di quei salti con la\n"
	.string "bicicletta che mi fa male il didietro…$"

JaggedPass_Text_AutumnIntro:
	.string "Scalo questa montagna ogni giorno.\n"
	.string "Confido nella mia forza.$"

JaggedPass_Text_AutumnDefeat:
	.string "Mmm… cos’è successo?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Cos’è quello strano spuntone di roccia\n"
	.string "lì su?$"

