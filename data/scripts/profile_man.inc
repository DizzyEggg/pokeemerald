ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Ciao, ALLENATORE!\n"
	.string "Hai un sorriso fantastico, lo sai?\p"
	.string "Il mio hobby è collezionare i profili\n"
	.string "degli ALLENATORI di POKéMON.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Allora, che ne dici?\n"
	.string "Mi mostri il tuo profilo?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Per creare il tuo profilo, devi mettere\n"
	.string "insieme quattro parole o espressioni.\p"
	.string "Ti spiegherò come creare un profilo\n"
	.string "usando quattro espressioni diverse.\p"
	.string "Le quattro espressioni si possono\n"
	.string "combinare fra di loro.\p"
	.string "Ce ne sono moltissime disponibili.\p"
	.string "Sono organizzate in categorie, ad\n"
	.string "esempio POKéMON, quotidianità, hobby…\l"
	.string "così sarà più facile trovarle!\p"
	.string "Prima bisogna scegliere una categoria e\n"
	.string "visualizzare le espressioni disponibili.\p"
	.string "Poi si sceglie l’espressione desiderata.\p"
	.string "Così facendo… creerai il tuo profilo!$"

ProfileMan_Text_LetsSeeItThen:
	.string "Sì! Grazie!\n"
	.string "Allora, mi mostri il tuo profilo?$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "No, veramente?\p"
	.string "Pensavo che una persona come te\n"
	.string "avesse un profilo favoloso…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Oh, non te la senti in questo momento?\p"
	.string "Torna, ogni momento è buono per me!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Ciao, ALLENATORE!\n"
	.string "Hai un sorriso fantastico, lo sai?$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Posso vedere il tuo nuovo profilo?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Sì! Grazie!\p"
	.string "Spero che sia persino migliore del\n"
	.string "profilo che mi avevi fatto vedere prima.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Oh, il tuo profilo ti piace così com’è.\p"
	.string "Ti capisco, è già un profilo fantastico\n"
	.string "anche così.$"

ProfileMan_Text_FantasticProfile:
	.string "Favolosoooo!\p"
	.string "Il tuo profilo è super!\n"
	.string "Esprime perfettamente la tua natura.\p"
	.string "Chiunque lo senta, sarà affascinato\n"
	.string "da te.\p"
	.string "Grazie!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you’re now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
