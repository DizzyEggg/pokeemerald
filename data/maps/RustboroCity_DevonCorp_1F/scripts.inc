.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Ti do il benvenuto alla DEVON SpA.\p"
	.string "Siamo orgogliosi di produrre strumenti\n"
	.string "e medicine utili per la vita.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Hanno rubato un pacchetto importante\n"
	.string "alla nostra équipe di ricerca.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Ehi, quelle SCARPE da CORSA!\n"
	.string "Sono uno dei nostri prodotti!\p"
	.string "Sono felice quando vedo qualcuno\n"
	.string "usare i nostri prodotti.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Quel pacchetto rubato…\p"
	.string "Beh, di sicuro è importante, ma non\n"
	.string "contiene niente che si possa usare.\p"
	.string "Credo che chiunque abbia commesso\n"
	.string "il misfatto non brilli per intelligenza.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Pare che abbiano recuperato\n"
	.string "la MERCE DEVON sottratta.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Spiacente, può entrare solo\n"
	.string "il personale autorizzato.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "È inverosimile.\n"
	.string "Come è potuto accadere un tale furto?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Salve!\n"
	.string "La tua presenza è sempre cosa gradita!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "In questa vetrina ci sono campioni\n"
	.string "di rocce e metalli.\p"
	.string "C’è un cartello con una scritta…\p"
	.string "“La DEVON SpA ha cominciato la sua\n"
	.string "attività ricavando pietre dalle cave e \l"
	.string "limatura di ferro dalla sabbia.\p"
	.string "Dopo questo umile inizio come\n"
	.string "produttore di materiali grezzi, la DEVON\l"
	.string "si è sviluppata ulteriormente…\p"
	.string "Oggi la DEVON SpA produce\n"
	.string "una vastissima gamma di\l"
	.string "prodotti industriali”.$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "La vetrina contiene prototipi\n"
	.string "e campioni.\p"
	.string "C’è un cartello con una scritta…\p"
	.string "“Oltre ai prodotti industriali, la\n"
	.string "DEVON commercializza prodotti\l"
	.string "farmaceutici e di altro genere che\l"
	.string "migliorano la qualità della vita.\p"
	.string "Di recente la DEVON ha messo sul\n"
	.string "mercato anche prodotti per gli\l"
	.string "ALLENATORI di POKéMON, fra cui\l"
	.string "le POKé BALL e i sistemi POKéNAV”.$"

