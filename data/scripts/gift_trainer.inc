MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "La SCHEDA SEGRETA ti\n"
	.string "permette di partecipare ad\l"
	.string "un sondaggio al POKéMON-MARKET.\p"
	.string "Così, potrai invitare gli\n"
	.string "ALLENATORI a CENERIDE.\p"
	.string "Ora ti do la password che ti serve\n"
	.string "per partecipare a un sondaggio:\p"
	.string "BATTI CINQUE ACUTI\n"
	.string "ALLENATORE.\p"
	.string "Scrivi questa password su\n"
	.string "un sondaggio e invialo al\l"
	.string "SISTEMA COMUNICAZIONE\l"
	.string "WIRELESS.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "Un ALLENATORE è appena\n"
	.string "arrivato a CENERIDE per cercarti.\p"
	.string "Buon divertimento nella lotta\n"
	.string "contro questo ALLENATORE!\p"
	.string "Inserendo altre password,\n"
	.string "potrai invitare altri ALLENATORI!\p"
	.string "Cerca altre password valide!$"
