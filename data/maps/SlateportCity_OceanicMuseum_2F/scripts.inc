.set LOCALID_CAPT_STERN, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_GRUNT_1, 3
.set LOCALID_GRUNT_2, 4

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_GRUNT_1
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "? Se stai cercando il CAP. REMO,\n"
	.string "sono io in persona!\p"
	.string "Ah! Devono essere i pezzi che ho\n"
	.string "ordinato dal SIG. PETRI della DEVON.\p"
	.string "Perfetto! Grazie! Adesso possiamo\n"
	.string "prepararci per la spedizione.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Eheheh, aspetta!\n"
	.string "Il pacchetto è nostro!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAP. REMO: Che cosa?!\n"
	.string "Chi sono queste persone?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Siamo il TEAM IDRO!\p"
	.string "Il nostro CAPO vuole quei pezzi!\n"
	.string "Dammeli senza tante storie!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Aaaaah!\n"
	.string "Sono stato battuto!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh, che disastro… il CAPO andrà\n"
	.string "su tutte le furie…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Largo, frignone!\n"
	.string "Ci penso io!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Che cosa?!\n"
	.string "Ho perso anch’io!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Se torniamo a mani vuote, ne sentiremo\n"
	.string "delle belle!\p"
	.string "Arrgh, non pensavo che i nostri piani\n"
	.string "sarebbero andati all’aria!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Sono venuto a vedere perché è tanto\n"
	.string "complicato portare via alcuni pezzi,\l"
	.string "ma vedo davanti a me solo una ciurma di\l"
	.string "pappamolle!$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Noi siamo il TEAM IDRO e\n"
	.string "adoriamo il mare!\p"
	.string "E io sono IVAN, il CAPO del\n"
	.string "TEAM IDRO.\p"
	.string "Cosa ti spinge ad interferire con\n"
	.string "i nostri piani?\p"
	.string "No! Non può essere! Non sarai\n"
	.string "un membro del TEAM MAGMA?\p"
	.string "Non posso crederci. Non hai l’aspetto\n"
	.string "di uno di quelli.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I POKéMON, le persone… tutta\n"
	.string "la vita dipende dal mare.\p"
	.string "Lo scopo del TEAM IDRO è\n"
	.string "l’espansione del mare.\p"
	.string "Non trovi che il nostro sia un obiettivo\n"
	.string "magnifico?\p"
	.string "Ma perché sto parlando con te?\n"
	.string "Sei ancora troppo giovane per\l"
	.string "comprendere la nostra nobile causa!\p"
	.string "Se oserai interferire con i nostri piani\n"
	.string "un’altra volta…\p"
	.string "la pagherai cara!\n"
	.string "Non dimenticarlo!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAP. REMO: Come ti chiami?\n"
	.string "Ah, sì, me l’hai già detto, sei {PLAYER}{KUN}…\p"
	.string "Una situazione davvero tesa!\n"
	.string "Ti ringrazio per l’aiuto!\p"
	.string "Oh, sì, per poco dimenticavo che i pezzi\n"
	.string "dalla DEVON sono arrivati grazie a te!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAP. REMO: Oops!\n"
	.string "Non c’è tempo da perdere!\p"
	.string "Dobbiamo partire al più presto alla\n"
	.string "scoperta dei fondali marini.\p"
	.string "Mille grazie ancora, ma ora\n"
	.string "devo proprio andare!\p"
	.string "Tu puoi restare e dare un’occhiata alle\n"
	.string "nostre sale, se ti va.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Qui ho visto un modello di nave.\p"
	.string "Assomigliava alla VECCHIA NAVE\n"
	.string "vicino a BLURUVIA…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Dentro al MUSEO non si corre!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Wow, il sottomarino è splendido!\n"
	.string "Voglio farci un giro!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "Sull’etichetta c’è scritto:\n"
	.string "“CAMPIONE d’ACQUA 1”.\p"
	.string "Il mare è un’unica distesa, ma l’acqua\n"
	.string "differisce da regione a regione.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "Sull’etichetta c’è scritto:\n"
	.string "“CAMPIONE d’ACQUA 2”.\p"
	.string "Forse la salinità dell’acqua differisce\n"
	.string "da regione a regione…$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Una palla di gomma si restringe e \n"
	.string "si allarga.\p"
	.string "“Nel mare, il peso dell’acqua esercita\n"
	.string "una pressione.\p"
	.string "Nelle acque poco profonde,\n"
	.string "la pressione non è molto forte.\p"
	.string "In acque molto profonde, su di un’area\n"
	.string "piccola, si concentra una pressione di\l"
	.string "decine di migliaia di tonnellate”.$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MODELLO della REGIONE di HOENN”\p"
	.string "Rappresentazione in miniatura della\n"
	.string "regione di HOENN.\p"
	.string "Dove si trova ALBANOVA?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "Rappresentazione del flusso del mare.\p"
	.string "“In prossimità dei fondali, l’acqua\n"
	.string "scorre a causa delle differenze tra\l"
	.string "fattori come temperatura e salinità”.$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "Rappresentazione del flusso del mare.\p"
	.string "“In superficie, l’acqua scorre come\n"
	.string "la corrente sospinta dal vento”.$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“TRAGHETTO M/N MAREA”\p"
	.string "“Riproduzione in scala della nave in\n"
	.string "costruzione al CANTIERE del CAP. REMO”.$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“SOTTOMARINO EXPLORER 1”\p"
	.string "“Riproduzione del sottomarino per\n"
	.string "l’esplorazione dei fondali oceanici”.$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“CAPSULA SOMMERGIBILE”\p"
	.string "“Riproduzione di una capsula compatta\n"
	.string "ed automatizzata per l’esplorazione\l"
	.string "dei fondali marini”.$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“M/N ANNA”\p"
	.string "“Riproduzione della nave da crociera\n"
	.string "che fa il giro del mondo”.$"

