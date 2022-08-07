LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Sono il GAME DESIGNER.\p"
	.string "Oh, sul serio?\n"
	.string "Ti stai dando da fare col POKéDEX?\p"
	.string "So che è difficile completarlo,\n"
	.string "ma non devi desistere.\p"
	.string "Quando l’hai completato, vieni a\n"
	.string "farmelo vedere.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! Non credo ai miei occhi!\n"
	.string "È strabiliante!\p"
	.string "Questo POKéDEX è completo!\n"
	.string "Devi amare veramente i POKéMON!\p"
	.string "Non trovo parole per esprimere\n"
	.string "la mia ammirazione!\p"
	.string "Hai compiuto una grande impresa,\n"
	.string "ti meriti questo!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Stai parlando con me?\n"
	.string "Io sono il PROGRAMMATORE.\p"
	.string "Mi chiedo come siano le SLOT\n"
	.string "da queste parti.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Sono il GRAFICO! Non trovi che i POKéMON\n"
	.string "della regione di HOENN siano molto\l"
	.string "interessanti?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Carine le CIAMBELLINE, eh?\n"
	.string "Lottare contro una bella CIAMBELLINA…\p"
	.string "mi piacerebbe da morire!\p"
	.string "E le GEMELLE! Non le trovi deliziose?\n"
	.string "Una lotta 2 contro 2 con le GEMELLE…\p"
	.string "Mi divertirei un sacco!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brezza del mare mi coccola.\n"
	.string "È una sensazione stupenda!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Non sai mai quando ti possa\n"
	.string "capitare una sfida.\p"
	.string "Per questo non esco mai di casa senza\n"
	.string "il mio GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Eh?!\n"
	.string "Oh, scusa! Mi ero appisolato!\p"
	.string "Sono qui per informarmi sulle\n"
	.string "GARE POKéMON.\p"
	.string "Devo ammettere che sembra trattarsi di\n"
	.string "una cosa interessante…\p"
	.string "Sarò un tradizionalista, ma preferisco\n"
	.string "le lotte e gli ALLENATORI forti.\p"
	.string "Almeno così la penso io…\p"
	.string "{PLAYER}{KUN}, spero che ti divertirai\n"
	.string "con le PALESTRE, le GARE,\l"
	.string "i TENDONI LOTTA e il resto!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: La strategia è tutto se si\n"
	.string "vuole vincere una GARA.\p"
	.string "Inoltre, ideare strategie serve anche\n"
	.string "per migliorare la propria tecnica\l"
	.string "di ALLENATORE.$"

