.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM36, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM36
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM36
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Cosa va di moda? Beh, dev’essere\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Non riesco a immaginare come farei\n"
	.string "senza “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Cosa va di moda? Beh, dev’essere\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Ma mi sta già annoiando…\p"
	.string "Potrei cercare la prossima novità!$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Cerco di insegnare ai miei POKéMON\n"
	.string "“{STR_VAR_1}”,\l"
	.string "ma non sta andando molto bene.\p"
	.string "È davvero troppo, suppongo.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Sto studiando il detto più “in”…\n"
	.string "“{STR_VAR_1}”!\p"
	.string "È vero che c’è un legame profondo\n"
	.string "tra “{STR_VAR_1}”\l"
	.string "e “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh!\n"
	.string "Allora ho avuto intuito!\p"
	.string "Sono davvero alla moda!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Cosa?!\n"
	.string "È la verità?!\p"
	.string "Non è facile per una persona non\n"
	.string "più giovane tenersi al passo coi tempi!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Tutto questo parlare di\n"
	.string "“{STR_VAR_1}”… non c’è\l"
	.string "uno show televisivo in merito?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Al di là del mare…\p"
	.string "“{STR_VAR_1}”\n"
	.string "è persino più in voga?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Io faccio collezione di oggetti\n"
	.string "ufficiali certificati\l"
	.string "“{STR_VAR_1}”.\p"
	.string "Ho anche BAMBOLE ufficiali\n"
	.string "“{STR_VAR_1}”…\p"
	.string "vestiti firmati ufficiali\n"
	.string "“{STR_VAR_1}”…\p"
	.string "e libri illustrati ufficiali\n"
	.string "“{STR_VAR_1}”.\p"
	.string "Eheheheh, tutta roba mia!\n"
	.string "Non la dividerò con nessuno!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "IDENTIFICAZIONE DI\n"
	.string "“{STR_VAR_1}”\l"
	.string "EFFICACI E\l"
	.string "“{STR_VAR_1}” INUTILI\p"
	.string "IL LEGAME TRA POKéMON E\n"
	.string "“{STR_VAR_1}”…\p"
	.string "“{STR_VAR_1}” UTILI…\p"
	.string "È pieno zeppo di libri su\n"
	.string "“{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "S’intitola “L’IMMAGINE DI\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "S’intitola “IL RICORDO DI\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_LastTrend:
	.string "S’intitola “L’IMPRONTA DI\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "S’intitola “LA NASCITA DI \n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "“{STR_VAR_1}”!\n"
	.string "Forte, vero?\p"
	.string "È la cosa più forte al momento!\p"
	.string "È affascinante!\n"
	.string "Davvero incredibile, lo giuro!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh, no, no, no.\p"
	.string "Quel “{STR_VAR_1}” che\n"
	.string "dici di aver sentito, non è quello vero.\p"
	.string "Quello autentico è molto più… come\n"
	.string "posso dire? Vivido, ma anche delicato!\p"
	.string "Ah, ma che importa… è impressionante!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ehi, ho scritto una canzone. Si intitola\n"
	.string "“{STR_VAR_1}”.\p"
	.string "“{STR_VAR_1}”\n"
	.string "è davvero in voga al momento.\p"
	.string "Bene, ascolta!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Mi fa impazzire\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Senti, ti farebbe bene fare esercizio\n"
	.string "prima di cantare a squarciagola\l"
	.string "“{STR_VAR_1}”.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Pensavo che dovremmo metterci\n"
	.string "d’accordo e organizzare una festa\l"
	.string "a tema “{STR_VAR_1}”\l"
	.string "sull’isola.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, che idea grandiosa!\p"
	.string "Così stabiliremo una volta per tutte\n"
	.string "chi è il migliore nel pronunciare\l"
	.string "“{STR_VAR_1}”.\l"
	.string "Proprio un’idea fantastica!\p"
	.string "Da oggi “{STR_VAR_1}”\n"
	.string "sarà il nostro motto!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Comunque stavo pensando…\p"
	.string "“{STR_VAR_1}” prima\n"
	.string "era una novità, mentre ora fa parte\l"
	.string "del nostro parlare quotidiano!\l"
	.string "Non sei d’accordo?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Scusa?\n"
	.string "Di cosa stai parlando?\p"
	.string "Sì, “{STR_VAR_1}”\n"
	.string "è sulla bocca di tutti!\p"
	.string "Assolutamente sì, PROFESSOR\n"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Se tu e io lottassimo nella stessa\n"
	.string "squadra, il nostro motto sarebbe\l"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Esattamente!\p"
	.string "Ti immagini il DUETTO\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Che bel quadro!\n"
	.string "Ahahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Per me FANGOBOMBA gode\n"
	.string "della massima fama. È insuperabile.\p"
	.string "Eh? Mi stai dicendo che non\n"
	.string "conosci FANGOBOMBA?\p"
	.string "Ma è una cosa disdicevole!\n"
	.string "Te ne darò una.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Adoro FANGOBOMBA.\p"
	.string "Ma anche i POKéMON che usano la mossa\n"
	.string "“{STR_VAR_1}” sono ok.$"

