.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Uhm, quindi hanno raddoppiato i clienti\n"
	.string "usando i POKéMON come attrazioni?\p"
	.string "Uhm, se un POKéMON carino diventasse\n"
	.string "la mascotte della nostra locanda…\p"
	.string "chissà, magari potremmo aumentare\n"
	.string "la nostra clientela.$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, scusa, scusa!\n"
	.string "Ero troppo preso a guardare la TV!\p"
	.string "Da quando il TEAM IDRO è giunto in\n"
	.string "città, non abbiamo più visto un turista!$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Ehi, libera il campo!\n"
	.string "Non riesco a vedere la TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Wow! Mi stai dicendo che un POKéMON\n"
	.string "ha ritrovato uno strumento smarrito?\p"
	.string "Mica male… se avessimo un POKéMON\n"
	.string "così acuto…\p"
	.string "potremmo ritrovare tutto quello che\n"
	.string "i nostri clienti hanno dimenticato…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, scusa, scusa!\n"
	.string "A volte la TV mi prende troppo!\p"
	.string "Ho sentito che qualcuno ha scovato\n"
	.string "il RIFUGIO del TEAM IDRO.\p"
	.string "Grazie a questo, mi è appena arrivata\n"
	.string "una prenotazione per un gruppone.\p"
	.string "È un’azienda che si chiama… uhm…\n"
	.string "GAME qualcosa…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Incredibile! Un POKéMON domestico\n"
	.string "ha preso un ladro?\p"
	.string "Mica male! Se avessimo un POKéMON\n"
	.string "grintoso come guardiano…\p"
	.string "i nostri clienti si sentirebbero più\n"
	.string "sicuri.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, scusa, scusa!\n"
	.string "La TV è come una calamita per me.\p"
	.string "Oh, sì, è appena arrivato un gruppone.\p"
	.string "Hanno prenotato a nome GAME FREAK,\n"
	.string "quindi immagino che facciano giochi.\p"
	.string "Uh, devo affrettarmi a preparare\n"
	.string "la cena!$"

