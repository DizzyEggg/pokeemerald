BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Ho allevato POKéMON per settant’anni!\n"
	.string "Sono l’uomo che tutti chiamano\l"
	.string "l’ALLEVA{PKMN} leggendario!\p"
	.string "Alla mia veneranda età, le abilità\n"
	.string "dei POKéMON si vedono a colpo\l"
	.string "d’occhio.\p"
	.string "Penso che a un ALLENATORE come te\n"
	.string "interessi conoscere le abilità dei\l"
	.string "propri POKéMON, o no?\p"
	.string "Fammi dare un’occhiata ai tuoi\n"
	.string "POKéMON!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "Ehm…\p"
	.string "L’abilità di questo POKéMON mi\n"
	.string "sembra nella media.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "Ehm…\p"
	.string "L’abilità di questo POKéMON mi\n"
	.string "sembra superiore alla media.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "Ehm…\p"
	.string "L’abilità di questo POKéMON mi\n"
	.string "sembra notevole.$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "Ehm…\p"
	.string "L’abilità di questo POKéMON mi\n"
	.string "sembra straordinaria.$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Il suo punto di forza\n"
	.string "sono i PS…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Il suo punto di forza\n"
	.string "è l’ATTACCO…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Il suo punto di forza\n"
	.string "è la DIFESA…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Il suo punto di forza\n"
	.string "è l’ATTACCO SPECIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Il suo punto di forza\n"
	.string "è la DIFESA SPECIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Il suo punto di forza\n"
	.string "è la VELOCITÀ…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Questa statistica non è niente male.\n"
	.string "Non c’è che dire…$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Questa statistica è notevole.\n"
	.string "Non c’è che dire…$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Questa statistica è straordinaria.\n"
	.string "Non c’è che dire…$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "Non ha un difetto!\n"
	.string "Non c’è che dire…$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Cosa? Vai troppo di fretta per\n"
	.string "ascoltare il mio consiglio?\p"
	.string "Dovresti sempre ascoltare quello che\n"
	.string "gli anziani hanno da dire!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Yes, what is it now?\p"
	.string "I have business that needs tending!\n"
	.string "Save it for next time!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Salve, giovane! Vuoi saperne di più sulle\n"
	.string "abilità dei tuoi POKéMON?\p"
	.string "Forza! Fammi dare un’occhiata a uno\n"
	.string "dei tuoi POKéMON!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Per quanto sia un esperto, non posso\n"
	.string "esprimermi su un POKéMON non\l"
	.string "ancora nato!\p"
	.string "Mostrami un POKéMON!\n"
	.string "Voglio vedere un POKéMON!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Mi ha detto che ho un POKéMON\n"
	.string "straordinario! L’ho allevato con cura!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Mi ha detto che ho un POKéMON\n"
	.string "straordinario, anche se non ho fatto\l"
	.string "nulla di speciale per allevarlo…$"

