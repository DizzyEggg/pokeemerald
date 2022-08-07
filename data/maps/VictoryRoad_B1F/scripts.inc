VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Al pensiero di avvicinarmi alla\n"
	.string "LEGA POKéMON…\p"
	.string "mi trema la voce come ad un artista\n"
	.string "nel giorno della prima…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Ho scordato le battute…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "La LEGA POKéMON è ancora\n"
	.string "un miraggio… Che amarezza…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Per vincere alla LEGA POKéMON,\n"
	.string "è necessaria la piena fiducia da parte\l"
	.string "dei tuoi POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Si vede che c’è fiducia reciproca.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Passando tempo insieme, cresce la\n"
	.string "fiducia tra i POKéMON e gli ALLENATORI.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Questo non è il traguardo. È solo una\n"
	.string "tappa verso la LEGA POKéMON.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Sei sulla buona strada!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Ce la farai di sicuro! I tuoi POKéMON\n"
	.string "sono proiettati verso la vittoria!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "I miei POKéMON sono talmente forti\n"
	.string "che incutono timore!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Non ho mai incontrato nessuno come te.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Percepisco una forza incredibile\n"
	.string "provenire da te e dalla tua squadra\l"
	.string "di POKéMON anche fuori dalla lotta.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Non innervosirti!\n"
	.string "Rilassati e fai con calma!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Wow!\n"
	.string "Favoloso!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Certo, questa è la VIA VITTORIA.\p"
	.string "Ma non è poi così diversa dalle strade\n"
	.string "che hai percorso finora.\p"
	.string "Cerca di divertiti per il resto\n"
	.string "del cammino!$"

