.set LOCALID_OLD_WOMAN, 2

BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "Siamo venuti qui ad accompagnare\n"
	.string "nostro nipote.\p"
	.string "Ma visto che ci siamo, abbiamo\n"
	.string "pensato di comprare dei souvenir.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Caro, cosa ne pensi? Non sarebbe\n"
	.string "proprio un bel pensierino?\p"
	.string "…PRO …TE …INA?\n"
	.string "Ha un aspetto squisito, non trovi?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "In molti edifici del PARCO LOTTA non\n"
	.string "è permesso utilizzare strumenti\l"
	.string "durante le lotte.\p"
	.string "Questa regola rende le cose ancora più\n"
	.string "complicate!$"

