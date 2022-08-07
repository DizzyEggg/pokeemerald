.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Uhmmm… non ce n’è neanche\n"
	.string "l’ombra…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Ciao, hai per caso visto un POKéMON\n"
	.string "chiamato SHROOMISH da queste parti?\p"
	.string "Quel POKéMON mi piace da matti.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Ti avevo teso una trappola, ma hai\n"
	.string "perso tempo a bighellonare per\l"
	.string "il BOSCO PETALO, vero?\p"
	.string "Mi sono stufato di aspettare,\n"
	.string "quindi eccomi qua!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Ehi, tu! RICERCATORE della DEVON!\p"
	.string "Dammi quegli appunti!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Ahhhhh!\p"
	.string "Sei un ALLENATORE di POKéMON, giusto?\n"
	.string "Ti prego, aiutami!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Uh? Che cosa credi di fare?\n"
	.string "Non vorrai mica proteggerlo!\p"
	.string "Non c’è alcuna pietà per chi si\n"
	.string "immischia negli affari del TEAM IDRO,\l"
	.string "nemmeno per chi è ancora in tenera età!\p"
	.string "Dai su, lottiamo!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Sei forte, mi sento preso in giro!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… certo che hai proprio del fegato\n"
	.string "ad intrometterti negli affari del \l"
	.string "TEAM IDRO! Forza, voglio la rivincita!\p"
	.string "Mi piacerebbe… purtroppo non ho più\n"
	.string "POKéMON…\p"
	.string "Noi del TEAM IDRO siamo sulle tracce\n"
	.string "di qualcosa a FERRUGIPOLI.\p"
	.string "Per oggi ti lascio andare!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Uffff… c’è mancato un pelo!\p"
	.string "Grazie a te non mi hanno rubato\n"
	.string "quegli appunti importanti.\p"
	.string "In segno di riconoscenza, ti do\n"
	.string "una MEGA BALL!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Quel teppistello del TEAM IDRO\n"
	.string "non ha anche detto che erano sulle\l"
	.string "tracce di qualcosa a FERRUGIPOLI?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Uh, oh! Un’emergenza!\n"
	.string "Non c’è tempo da perdere!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Hai troppi strumenti.\n"
	.string "Non ti posso dare questa MEGA BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Ho catturato un sacco di POKéMON!\p"
	.string "Forza! Fatevi valere POKéMON\n"
	.string "COLEOTTERO, compagni di squadra!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Anche con tutti questi POKéMON,\n"
	.string "non ho vinto…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Ho catturato un bel po’ di POKéMON.\n"
	.string "Adesso sono senza POKé BALL.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Se porti un POKéMON COLEOTTERO\n"
	.string "a scuola, fai un figurone!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Quando perdo faccio una brutta figura.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Se hai un POKéMON COLEOTTERO\n"
	.string "grande, te lo invidieranno tutti!$"

PetalburgWoods_Text_IWantRematch1:
	.string "Lotteremo ancora quando la mia\n"
	.string "squadra di POKéMON COLEOTTERO\l"
	.string "si sarà rafforzata!\p"
	.string "Ti registro nel mio POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Lotteremo ancora quando la mia\n"
	.string "squadra di POKéMON COLEOTTERO\l"
	.string "si sarà rafforzata!\p"
	.string "Ti registro nel mio POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "La mia squadra di POKéMON COLEOTTERO\n"
	.string "è cresciuta. Farò di nuovo un figurone.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Quando perdo faccio una brutta figura.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Se hai un POKéMON forte, fai una\n"
	.string "bella figura, giusto? Per questo ci\l"
	.string "ho dato dentro con gli allenamenti!$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Salve!\n"
	.string "I tuoi POKéMON stanno tutti bene?\p"
	.string "Se i tuoi POKéMON sono deboli e vuoi\n"
	.string "evitare le lotte, devi stare alla larga\l"
	.string "dall’erba alta.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "A volte, anche se non le vedi, ci sono\n"
	.string "delle cose sul terreno.\p"
	.string "Per questo guardo sempre dove metto\n"
	.string "i piedi.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, che bella! Questa è la MEDAGLIA\n"
	.string "della PALESTRA di FERRUGIPOLI!\p"
	.string "Devi essere un ALLENATORE.\n"
	.string "Prova ad usare questo strumento.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "È MIRACOLSEME. Se fai tenere\n"
	.string "ad un POKéMON questo strumento,\l"
	.string "le mosse di tipo ERBA saranno più forti.\p"
	.string "Oltre a MIRACOLSEME, ci sono altri utili\n"
	.string "strumenti da far tenere ai POKéMON.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "CONSIGLI UTILI\p"
	.string "Entrando nella lotta anche solo una\n"
	.string "volta, un POKéMON guadagna punti ESP.\p"
	.string "Per rafforzare un POKéMON debole,\n"
	.string "mandalo in campo per primo.\p"
	.string "Cambialo non appena inizia\n"
	.string "la lotta. Guadagnerà punti ESP.\l"
	.string "senza correre rischi.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "CONSIGLI UTILI\p"
	.string "Oltre che PUNTI SALUTE (PS), i POKéMON   \n"
	.string "hanno PUNTI POTENZA (PP), necessari\l"
	.string "per eseguire le mosse durante la lotta.\p"
	.string "Se un POKéMON esaurisce i PP, deve\n"
	.string "essere portato in un CENTRO POKéMON.$"

