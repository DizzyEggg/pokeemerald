VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case 0, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case 1, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case 2, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case 3, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case 4, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case 5, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case 6, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Mostrami un tuo POKéMON. Voglio vedere\n"
	.string "quanto ti è affezionato.\p"
	.string "Ohooo!\n"
	.string "Questo POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "ti adora… non potrebbe esserti più\n"
	.string "affezionato di così.\l"
	.string "Fa piacere vederlo!$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "sembra molto felice.\n"
	.string "Evidentemente ti è affezionatissimo.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "ti è molto affezionato.\n"
	.string "Vuole un po’ di coccole.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "si sta abituando a te.\n"
	.string "Pare che abbia fiducia in te.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "non è molto abituato a te.\n"
	.string "Non ti adora, ma nemmeno ti detesta.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "è molto cauto. Ti guarda con occhi\n"
	.string "minacciosi.\l"
	.string "Non gli piaci proprio!$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "È un po’ difficile… come dire…\p"
	.string "Questo POKéMON ti detesta e basta!\n"
	.string "Non è imbarazzante?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

