LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Ti do il benvenuto all’ERBORISTERIA per\n"
	.string "rimedi naturali, efficaci e convenienti!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Sei qui per saperne di più sui rimedi\n"
	.string "naturali di CUORDILAVA?\p"
	.string "È lodevole da parte tua.\p"
	.string "Mi piaci! Prendi questo!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "Questa CARBONELLA che ti ho dato\n"
	.string "serve per creare rimedi naturali.\p"
	.string "Inoltre, se la tiene un POKéMON,\n"
	.string "fa miracoli.\p"
	.string "Intensifica la potenza delle mosse\n"
	.string "di tipo FUOCO.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "I rimedi naturali hanno un effetto\n"
	.string "straordinario. Ma i tuoi POKéMON\l"
	.string "ti odieranno per questo.\l"
	.string "Hanno un gustaccio molto amaro!$"

