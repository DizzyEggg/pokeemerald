.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHM03Surf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHM03Surf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM03
	setflag FLAG_RECEIVED_HM03
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM03, PetalburgCity_WallysHouse_EventScript_ReceievedHM03Surf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHM03Surf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM03, PetalburgCity_WallysHouse_EventScript_ReceivedHM03Surf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHM03Surf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Tu sei…\n"
	.string "Ah, devi essere {PLAYER}{KUN}, giusto?\p"
	.string "Grazie per aver aiutato LINO\n"
	.string "qualche tempo fa.\p"
	.string "Sin da quando era ancora in fasce\n"
	.string "è sempre stato debole e malaticcio.\p"
	.string "Gli abbiamo organizzato un soggiorno\n"
	.string "a MENTANIA dai miei parenti.\p"
	.string "Lì l’aria è molto più pulita.\p"
	.string "Che cosa? Dov’è LINO?\n"
	.string "Già partito?! Il nostro LINO?\p"
	.string "Mi chiedo se abbia fatto molta strada…$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Come starà il nostro LINO?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "Ciao, {PLAYER}{KUN}! Scusa se ti abbiamo\n"
	.string "fatto venire qui in questo modo.\p"
	.string "Il soggiorno a MENTANIA ha giovato\n"
	.string "molto alla salute di LINO.\p"
	.string "E solo grazie a te!\p"
	.string "È vero che quando ha lasciato la città,\n"
	.string "l’hai aiutato a catturare un POKéMON?\p"
	.string "Credo che tu abbia fatto la felicità\n"
	.string "di LINO.\p"
	.string "A dir il vero non solo quella di LINO, \n"
	.string "ma anche quella di un padre!\p"
	.string "Sono contento che possa contare\n"
	.string "sul tuo valido aiuto.\p"
	.string "Ecco un segno del mio apprezzamento.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Se il tuo POKéMON può fare SURF,\n"
	.string "potrai visitare tanti posti diversi.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "LINO tornerà a casa presto.\n"
	.string "Non sto nella pelle!$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh? Hai incontrato LINO a IRIDOPOLI?\p"
	.string "Oh, {PLAYER}{KUN}, non è possibile.\p"
	.string "Godrà anche di migliore salute,\n"
	.string "ma non può essersi spinto così\l"
	.string "lontano da solo.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "Mentre ci descriveva la cattura del\n"
	.string "POKéMON, LINO sprizzava gioia.\p"
	.string "Era da tanto tempo che non lo\n"
	.string "vedevo sorridere in quel modo.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Mi raccomando, non lo dire a mio marito…\p"
	.string "LINO ha lasciato MENTANIA senza dire\n"
	.string "nulla a nessuno.\p"
	.string "Sai, LINO è un ragazzo fragile,\n"
	.string "ma estremamente determinato.\p"
	.string "Sono sicura che un giorno tornerà\n"
	.string "sano e salvo!$"

