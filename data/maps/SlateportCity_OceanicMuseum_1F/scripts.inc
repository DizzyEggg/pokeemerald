.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM46
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM46
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Ti trovi nel MUSEO OCEANOGRAFICO.\p"
	.string "L’ingresso costa ¥50.\n"
	.string "Vuoi entrare?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Buon divertimento.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh… mi dispiace, ma non hai abbastanza\n"
	.string "soldi.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh… sei con quel gruppo che è entrato\n"
	.string "prima?\p"
	.string "Sei in ritardo…\n"
	.string "Affrettati per raggiungerli!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Noi, TEAM IDRO, esistiamo per il bene\n"
	.string "di tutti!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Ci hanno detto di riunirci tutti\n"
	.string "qui, ma…\p"
	.string "il nostro CAPO, l’asse portante\n"
	.string "del gruppo, non c’è.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Diventerò ricco se rubacchio \n"
	.string "delle cose qui?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Posso mettere in pratica quello che\n"
	.string "imparo qui per fare qualche cattiveria…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Se i nostri scagnozzi non avessero\n"
	.string "fatto pasticci a FERRUGIPOLI,\l"
	.string "non saremmo certamente qui!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Non avevo ¥50… È stato difficile farla\n"
	.string "franca con la ragazza all’ingresso.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Voglio saperne di più sul mare per\n"
	.string "usare le mie conoscenze nella lotta.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "La vista del mare mi emoziona!\p"
	.string "Per me il CAP. REMO è il modello\n"
	.string "di vita più importante!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "Il mare è sconfinato ed immensamente\n"
	.string "profondo…\p"
	.string "Ci devono essere tanti POKéMON ancora\n"
	.string "sconosciuti.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Voglio un POKéMON d’acqua di mare.\p"
	.string "Devono essere molto teneri da\n"
	.string "abbracciare.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Ehi!\n"
	.string "Che ci fai tu qui?\p"
	.string "Io? Sono quello del TEAM IDRO\n"
	.string "che hai battuto prima.\l"
	.string "Nel TUNNEL MENFERRO, ricordi?\p"
	.string "Prendi questo!\n"
	.string "Devi perdonarmi!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Quella MT è più adatta a te che a me.\p"
	.string "Spero di non rivederti mai più!\n"
	.string "Eheheh!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Ma dai! Devi prendere questo\n"
	.string "e lasciarmi andare!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Un liquido blu viene fatto girare a\n"
	.string "mulinello in un contenitore di vetro.\p"
	.string "“Un esperimento per creare MULINELLO\n"
	.string "artificialmente usando il vento”.$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Una palla rossa viene fatta ballonzo-\n"
	.string "lare su e giù in un contenitore di vetro.\p"
	.string "“Un esperimento che simula CASCATA\n"
	.string "con la spinta idrostatica sulla palla”.$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Un campione di terreno prelevato dal\n"
	.string "fondo dell’oceano.\p"
	.string "“Molti anni fa, resti di forme di vita\n"
	.string "si sono depositati sul fondo del mare\l"
	.string "creando strati sedimentari.\p"
	.string "Analizzando questi strati, è possibile\n"
	.string "studiarne l’evoluzione”.$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Un campione di sabbia.\p"
	.string "“Le rocce delle montagne vengono\n"
	.string "trasportate dai fiumi e ridotte in tanti\l"
	.string "piccoli frammenti.\p"
	.string "I granelli di roccia diventano\n"
	.string "sabbia sulle spiagge”.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“CURIOSITÀ SULL’OCEANO 1”\n"
	.string "Perché l’acqua del mare è blu?\p"
	.string "“La luce è composta da molti colori.\p"
	.string "Quando attraversano l’acqua, quasi\n"
	.string "tutti i tipi di luce perdono colore.\p"
	.string "Tuttavia, la luce blu mantiene\n"
	.string "il colore diffondendolo nel mare”.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“CURIOSITÀ SULL’OCEANO 2”\n"
	.string "Perché il mare è salato?\p"
	.string "“Il mare contiene sale disciolto\n"
	.string "in forma di ioni di sodio e cloro.\p"
	.string "Questi ioni filtrano dalle rocce e\n"
	.string "raggiungono il mare con le piogge.\p"
	.string "La concentrazione del sale disciolto\n"
	.string "rende il mare salato”.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“CURIOSITÀ SULL’OCEANO 3”\n"
	.string "È più grande il mare o la terra?\p"
	.string "“Il mare copre il 70% del pianeta,\n"
	.string "il resto è terra.\p"
	.string "Il mare pertanto è il doppio della\n"
	.string "terra”.$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Un fossile con la superficie increspata.\p"
	.string "“Le correnti segnano il fondale\n"
	.string "marino.\p"
	.string "Il movimento dell’acqua crea piccole\n"
	.string "ondulazioni sul fondale.\p"
	.string "Quando il fondale si fossilizza, si\n"
	.string "formano le increspature”.$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Una strana macchina ruota sotto\n"
	.string "una cupola di vetro.\p"
	.string "Forse serve per misurare\n"
	.string "la profondità di qualcosa…$"

