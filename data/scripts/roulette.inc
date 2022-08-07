Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end
	
Roulette_Text_PlayMinimumWagerIsX::
	.string "La puntata minima a questo\n"
	.string "tavolo è {STR_VAR_1}. Vuoi giocare?$"

Roulette_Text_NotEnoughCoins::
	.string "Non hai abbastanza GETTONI.$"

Roulette_Text_SpecialRateTable::
	.string "È il momento del tavolo\n"
	.string "con puntata speciale!$"

Roulette_Text_ControlsInstruction::
	.string "Fai la tua puntata con la pulsan-\n"
	.string "tiera + e premi il pulsante A.$"

Roulette_Text_ItsAHit::
	.string "Hai vinto!$"

Roulette_Text_Jackpot::
	.string "Jackpot!$"

Roulette_Text_NothingDoing::
	.string "Niente di fatto!$"

Roulette_Text_YouveWonXCoins::
	.string "Hai vinto {STR_VAR_1} GETTONI!$"

Roulette_Text_NoCoinsLeft::
	.string "Non hai abbastanza GETTONI…$"

Roulette_Text_KeepPlaying::
	.string "Vuoi giocare ancora?$"

Roulette_Text_BoardWillBeCleared::
	.string "La ROULETTE sarà liberata.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "You don’t have a COIN CASE.$"

Roulette_Text_CoinCaseIsFull::
	.string "Il tuo SALVADANAIO è pieno!\n"
	.string "I gettoni si cambiano in premi.$"
