.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string " la prima volta che vedo un ALLENATORE\n"
	.string "usare i POKéMON con tanta maestria.\p"
	.string "Ma lasciamelo dire: mio figlio è più forte\n"
	.string "di te.\p"
	.string "Devi sapere che ha persino sfidato\n"
	.string "la LEGA POKéMON!$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Usiamo CRESCICAPPA per rafforzare i\n"
	.string "nostri POKéMON durante l’allenamento.\p"
	.string "Avendo battuto tutta la nostra\n"
	.string "famiglia, vorrei darti CRESCICAPPA!\l"
	.string "Magari ti può essere utile…$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Sulle lotte di POKéMON non si scherza!\n"
	.string "Le prendiamo molto seriamente.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mamma è più forte di papà.\p"
	.string "Io sono più forte di mamma!\p"
	.string "E la nonna è più forte di me!\p"
	.string "Ma il mio fratellone è addirittura più\n"
	.string "forte della nonna!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Certo che sei forte!\p"
	.string "Ma se ti confrontassi con mio nipote,\n"
	.string "finiresti per versare lacrime amare.\p"
	.string "È molto più forte di qualsiasi\n"
	.string "ALLENATORE che conosciamo.\p"
	.string "Ora starà già affrontando il CAMPIONE\n"
	.string "della LEGA POKéMON.\p"
	.string "Conoscendo mio nipote,\n"
	.string "magari è già il CAMPIONE!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Ora mio nipote starà già affrontando\n"
	.string "il CAMPIONE della LEGA POKéMON.\p"
	.string "Conoscendolo, magari è già\n"
	.string "il CAMPIONE!$"

