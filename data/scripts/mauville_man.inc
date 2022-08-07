MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_SYS_HIPSTER_MEET
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special GetHipsterSpokenFlag
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
	special SetHipsterSpokenFlag
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Salve! Sono il MERCANTE.\n"
	.string "Vuoi scambiare decorazioni con me?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh… sento che la mia presenza\n"
	.string "non è gradita.$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Io e te abbiamo già scambiato\n"
	.string "decorazioni.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Se vedi qualche oggetto che ti piace,\n"
	.string "dimmelo.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Non vuoi niente?\n"
	.string "La mia presenza non è gradita…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Quella decorazione apparteneva a\n"
	.string "{STR_VAR_1} prima.\p"
	.string "La vuoi?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Eh? Aspetta un attimo. Non hai niente\n"
	.string "da darmi in cambio!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Va bene, scegli la decorazione che\n"
	.string "vorresti darmi in cambio.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Non vuoi scambiare niente con me?\n"
	.string "La mia presenza non è gradita…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "La tua collezione di questi oggetti è\n"
	.string "completa. Non c’è più spazio.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Va bene, vuoi darmi {STR_VAR_2}\n"
	.string "in cambio di {STR_VAR_3}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Quella decorazione è in uso.\n"
	.string "Non puoi scambiarla.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Allora facciamo lo scambio!\n"
	.string "Mando la decorazione al tuo PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oh, mi dispiace.\n"
	.string "È una decorazione molto rara.\l"
	.string "Non posso darla via!\p"
	.string "Ti potrebbe interessare qualcos’altro?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Sono il NARRATORE.\n"
	.string "Racconto storie di ALLENATORI\l"
	.string "leggendari.\p"
	.string "Vuoi sentire la mia storia?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh… mi sento avvilito…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Questa è la lista delle leggende che\n"
	.string "conosco. Quale storia vorresti sentire?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Veramente, non conosco né ALLENATORI\n"
	.string "leggendari né storie.\p"
	.string "Dove si potrebbe trovare un ALLENATORE\n"
	.string "degno di un racconto leggendario?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Cosa?\n"
	.string "Tu… tu…\p"
	.string "{STR_VAR_2} \n"
	.string "per un numero di volte pari a {STR_VAR_1}?!\p"
	.string "Ma è eccezionale! Assistiamo alla\n"
	.string "nascita di una leggenda!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Mi viene da pensare che ci potrebbero\n"
	.string "essere altri ALLENATORI con altre \l"
	.string "leggende avvincenti tutte da scoprire!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Sei un ALLENATORE?\p"
	.string "Allora dimmi, non hai delle storie che\n"
	.string "possano suonare un po’ leggendarie?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Uhm… non sono soddisfatto…\p"
	.string "Vorrei che mi raccontassi aneddoti\n"
	.string "degni di essere chiamati leggenda.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Vorrei che più persone fossero\n"
	.string "interessate ai miei racconti epici sugli\l"
	.string "ALLENATORI leggendari.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "L’ALLENATORE salvatutto$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "hai salvato il gioco$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha salvato il gioco? {STR_VAR_1}!\p"
	.string "Di ALLENATORI prudenti come \n"
	.string "{STR_VAR_3} non ne troverai a frotte.$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "L’ALLENATORE modaiolo$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "hai lanciato una moda$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha lanciato nuove mode? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} detta le mode per tutta\n"
	.string "la regione di HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "L’ALLENATORE piantabacche$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "hai piantato BACCHE$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha piantato BACCHE? {STR_VAR_1}!\p"
	.string "La passione per le BACCHE di {STR_VAR_3}\n"
	.string "è veramente leggendaria!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "L’ALLENATORE scambiabici$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "hai scambiato BICI$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha scambiato BICI? {STR_VAR_1}!\p"
	.string "La passione di {STR_VAR_3} per le BICI\n"
	.string "deve essere profonda e sincera!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "L’ALLENATORE intervistato$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "hai concesso interviste$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte è stato intervistato\n"
	.string "questo ALLENATORE? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} deve essere un ALLENATORE\n"
	.string "che attira l’attenzione di tutti!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "L’ALLENATORE in lotta$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "hai sostenuto lotte$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte ha lottato\n"
	.string "questo ALLENATORE? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} deve essere un ALLENATORE\n"
	.string "che non rifiuta mai una lotta!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "L’ALLENATORE acchiappa-POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "hai catturato POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha catturato\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3}, acchiappa-POKéMON di fama\n"
	.string "leggendaria!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "L’ALLENATORE pescatore$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "hai catturato POKéMON con l’AMO$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha pescato\n"
	.string "{STR_VAR_1} POKéMON.\p"
	.string "L’amore per la pesca di {STR_VAR_3}\n"
	.string "è leggendario!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "L’ALLENATORE covauova$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "hai fatto schiudere UOVA$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha fatto nascere\n"
	.string "{STR_VAR_1} POKéMON dalle UOVA!\p"
	.string "{STR_VAR_3}, covauova di fama\n"
	.string "internazionale!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "L’ALLENATORE evolvi-POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "hai fatto evolvere POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Questo ALLENATORE ha fatto evolvere\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} è il “non plus ultra” degli\n"
	.string "evolvi-POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "L’ALLENATORE dei CENTRI POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "hai visitato CENTRI POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha fatto riposare la sua squadra di\l"
	.string "POKéMON nei CENTRI POKéMON? {STR_VAR_1}!\p"
	.string "Non esiste nessuno che ami i CENTRI\n"
	.string "POKéMON più di {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "L’ALLENATORE casalingo$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "hai rimesso in sesto i POKéMON a casa$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha rimesso in sesto la sua squadra di\l"
	.string "POKéMON a casa? {STR_VAR_1}!\p"
	.string "Non esiste ALLENATORE più casalingo\n"
	.string "di {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "L’ALLENATORE safarista$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "hai visitato la ZONA SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "è entrato nella ZONA SAFARI? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE il cui \n"
	.string "spirito selvaggio si risveglia nella \l"
	.string "ZONA SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "L’ALLENATORE dal TAGLIO facile$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "hai usato TAGLIO$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato TAGLIO? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che adora\n"
	.string "TAGLIO!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "L’ALLENATORE SPACCAROCCIA$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "hai spaccato rocce$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato SPACCAROCCIA? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che\n"
	.string "spacca tutte le rocce che trova!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "L’ALLENATORE traslocatore$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "hai traslocato dalla BASE SEGRETA$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha traslocato dalla sua BASE SEGRETA?\l"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che ama\n"
	.string "traslocare spesso!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "L’ALLENATORE con la SPLASH-mania$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "hai usato SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato SPLASH? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE con\n"
	.string "la mania per gli SPLASH!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "L’ALLENATORE tenace$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "hai usato SCONTRO$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato SCONTRO? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE tenace che\n"
	.string "mai si arrende di fronte alle avversità!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Il campione di SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "hai vinto il jackpot alle SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE ha\n"
	.string "vinto il jackpot alle SLOT? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE\n"
	.string "fortunatissimo alle SLOT!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Il campione della ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "hai vinto di seguito alla ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte di seguito questo\n"
	.string "ALLENATORE ha vinto alla ROULETTE?\l"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_3} ha una gran fortuna quando\n"
	.string "la pallina rimbalza nella ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "L’asso della TORRE LOTTA$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "hai sfidato la TORRE LOTTA$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha sfidato la TORRE LOTTA? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che aspira\n"
	.string "alla perfezione nella TORRE LOTTA!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "L’ALLENATORE mixa-tutto$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "hai fatto {POKEMELLE}$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha fatto {POKEMELLE}? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è veramente impareggiabile\n"
	.string "nell’uso del MIXER BACCHE!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "L’ALLENATORE sempre in GARA$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "hai partecipato alle GARE$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha partecipato alle GARE? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} adora mostrare i propri\n"
	.string "POKéMON agli altri!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Il fuoriclasse delle GARE$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "hai vinto GARE$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha vinto GARE? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è veramente imbattibile\n"
	.string "nelle GARE!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "L’amante degli acquisti$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "hai fatto acquisti$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE ha\n"
	.string "fatto acquisti nei negozi? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è una persona che non può\n"
	.string "fare a meno di entrare in un negozio.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "Il professionista del DETECTOR$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "hai usato il DETECTOR$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha usato il DETECTOR? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} adora sondare il terreno\n"
	.string "per cercare strumenti nascosti!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "L’ALLENATORE fradicio$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "hai fatto docce d’acqua piovana$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha fatto docce d’acqua piovana?\l"
	.string "{STR_VAR_1}!\p"
	.string "Deve essere il carisma di {STR_VAR_3}\n"
	.string "ad attirare la pioggia!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Il vorace lettore di POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "hai controllato il POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha controllato il POKéDEX? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} adora studiare i POKéMON\n"
	.string "sul POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Il collezionista di FIOCCHI$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "hai ricevuto FIOCCHI$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha ricevuto FIOCCHI? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE che\n"
	.string "ama far collezione di FIOCCHI!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "L’ALLENATORE salta-salti$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "hai disceso salti$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha disceso salti? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} non si fa sfuggire neppure\n"
	.string "un salto da discendere!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Il telespettatore leggendario$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "hai guardato la TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha guardato la TV? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} adora guardare la TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "L’ALLENATORE puntuale$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "hai controllato l’ora$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha controllato l’ora? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE puntuale e\n"
	.string "con uno spiccato senso del tempo.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Il mago della LOTTERIA POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "hai vinto alle LOTTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE ha\n"
	.string "vinto alla LOTTERIA POKéMON? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} deve avere molti amici \n"
	.string "con cui scambiare i POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "L’ALLENATORE utente della PENSIONE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "hai lasciato POKéMON alla PENSIONE$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha lasciato i POKéMON nella PENSIONE?\l"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE intrapren-\n"
	.string "dente che allena i POKéMON con abilità.$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "L’ALLENATORE in FUNIVIA$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "hai viaggiato in FUNIVIA$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha viaggiato in FUNIVIA? {STR_VAR_1}!\p"
	.string "{STR_VAR_3} è un ALLENATORE molto\n"
	.string "impegnato che va sempre su e giù!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "L’habitué delle sorgenti termali$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "hai lambito le sorgenti termali$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Questa è la storia di un ALLENATORE\n"
	.string "di nome {STR_VAR_3}.\p"
	.string "Sai quante volte questo ALLENATORE\n"
	.string "ha fatto bagni nelle sorgenti termali?\l"
	.string "{STR_VAR_1}! \p"
	.string "{STR_VAR_3} è un ALLENATORE con una\n"
	.string "pelle liscia come quella di un bambino!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Sono STRAMBY!\n"
	.string "Ho una storia magnifica da raccontarti!\p"
	.string "Vuoi sentirla?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh… mi sento demotivato…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Stavo anche pensando…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "È tutto, mi pare…\p"
	.string "Speriamo di rivederci!\n"
	.string "Ciao, ciao!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Ciao, sono il CANTAUTORE.\n"
	.string "Vuoi sentire la mia canzone?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh… mi hai fatto intristire…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, che canzone commovente…\n"
	.string "Vorrei cantarla ad altri…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Mhmm?\n"
	.string "Ti piace la canzone?\p"
	.string "Non sono molto soddisfatto del testo.\p"
	.string "Mi aiuteresti a scrivere delle nuove\n"
	.string "parole per la canzone?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh… mi hai fatto intristire…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Grazie infinite!\n"
	.string "Adesso canterò per te!$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Erano queste le parole della canzone\n"
	.string "che volevi?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Va bene allora.\n"
	.string "Canterò questa canzone per un po’.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Ehi! Tutti mi chiamano DANDY.\n"
	.string "Ti insegnerò cos’è all’ultimo grido.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Ma, aspetta, ti ho già insegnato cos’è\n"
	.string "all’ultimo grido.\p"
	.string "Mi piacerebbe poterlo insegnare\n"
	.string "ad altri.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Ehi, tu hai già un’idea molto chiara di\n"
	.string "che cosa sia all’ultimo grido.\p"
	.string "Non ho niente di nuovo da insegnarti.$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase:
	.string "Ehi, hai sentito parlare di\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Che cosa significa? Beh, chiedi alla\n"
	.string "mamma o al papà, va bene?$"
