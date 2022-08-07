.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, ogni giorno è così difficile…\p"
	.string "Che cos’è difficile?\n"
	.string "C’è bisogno di chiederlo?\p"
	.string "Decidere quale pietanza preparare…\p"
	.string "Non è affatto facile fare da\n"
	.string "mangiare tutti i giorni.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Ehi, ciao! Ti trovi nella casa\n"
	.string "della famiglia DE SFONDIS.\p"
	.string "Ho una domanda.\n"
	.string "Hai mai lavorato come baby-sitter?\p"
	.string "Vedi, io sono appena diventato padre\n"
	.string "e non ho molta esperienza con i bambini.\p"
	.string "Il problema è che mia figlia NINA\n"
	.string "non ride a sufficienza.\p"
	.string "Credo che se le dicessi qualcosa di\n"
	.string "divertente forse riderebbe un po’.\p"
	.string "Tu hai una parola o una frase da\n"
	.string "suggerirmi?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Ultimamente ho provato a dirle\n"
	.string "“{STR_VAR_1}”\l"
	.string "per farla divertire.\p"
	.string "Conosci una parola o una frase\n"
	.string "più divertente?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, benissimo!\n"
	.string "Sentiamo il tuo suggerimento.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Davvero?\p"
	.string "Vabbè, se ti viene in mente qualcosa\n"
	.string "di carino, io sono qui.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ho capito.\n"
	.string "Proviamo allora.$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "“{STR_VAR_1}”…\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Sììì! Sta ridendo!\n"
	.string "Sono felice almeno quanto lei!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ho capito.\n"
	.string "Proviamo allora.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "“{STR_VAR_1}”…\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Mmm… non ride affatto.\n"
	.string "Forse NINA è semplicemente\l"
	.string "una bambina seria…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Così non conosci nessuna espressione\n"
	.string "divertente. Ci penserò io allora.\p"
	.string "Mmm… che ne dici di\n"
	.string "“{STR_VAR_1}”?\l"
	.string "Vediamo se funziona.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "“{STR_VAR_1}”…\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Mmm… non ride affatto.\n"
	.string "Forse NINA è semplicemente\l"
	.string "una bambina seria…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Così non conosci nessuna espressione\n"
	.string "divertente. Proverò a farla divertire\l"
	.string "con la stessa espressione di prima.\p"
	.string "Comunque, se ti viene in mente qualcosa,\n"
	.string "fammelo sapere, ok?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Grazie!\p"
	.string "Grazie a te, la mia carissima NINA ha\n"
	.string "riso per me!\p"
	.string "So che dall’aspetto non si direbbe, ma\n"
	.string "io sono uno dei più brillanti scienziati\l"
	.string "della DEVON SpA.\p"
	.string "Come posso sdebitarmi con te?\p"
	.string "Ci sono, aggiungerò qualche sfondo\n"
	.string "nuovo per i BOX nel Sistema Memoria\l"
	.string "POKéMON del PC.\p"
	.string "Per accedere ai nuovi sfondi, devi\n"
	.string "scegliere “AMICI”\l"
	.string "nel menu SFONDO.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "È una BAMBOLA di pezza POKéMON!$"

