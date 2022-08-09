MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Grazie per usare il Sistema\n"
	.string "DONO SEGRETO.\p"
	.string "Recentemente sono stati visti\n"
	.string "POKéMON rari nella GROTTA\l"
	.string "MUTEVOLE sul PERCORSO 103.\p"
	.string "Perché non vai a vedere\n"
	.string "di persona?$"
