MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Se avessi una BICI, potrei fare la spesa\n"
	.string "a SELCEPOLI.\p"
	.string "Al POKéMON-MARKET di SELCEPOLI\n"
	.string "vendono il MESSAGGIO PORTO.$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! Hai il MESSAGGIO PORTO? Vorresti\n"
	.string "scambiarlo con un SALVADANAIO?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Oh, sono così felice!\n"
	.string "Ok, ti do in cambio un SALVADANAIO!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Il SALVADANAIO si usa al CASINÒ.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Oh, che delusione!\p"
	.string "Al CASINÒ ti serve un SALVADANAIO.$"

