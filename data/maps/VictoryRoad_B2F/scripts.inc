VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Mi sono allenato con tutti i componenti\n"
	.string "della mia famiglia!\l"
	.string "Sono imbattibile!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Meglio della mia famiglia?!\n"
	.string "Com’è possibile?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Ero il più bravo di tutta la mia famiglia.\n"
	.string "Non avevo mai perso prima…\p"
	.string "Non ho più fiducia in me stesso…\n"
	.string "Credo che andrò a casa…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Corre voce che ci sia una giovane\n"
	.string "promessa in giro. Non sarai mica tu?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Hai grinta da vendere!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Le voci dicono che la giovane promessa\n"
	.string "venga da PETALIPOLI.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Comincerai a battere la fiacca…$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Non dai segni di cedimento!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "La VIA VITTORIA e la LEGA POKéMON\n"
	.string "sono sfide lunghe e faticose.\l"
	.string "Attenzione alla stanchezza!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Non devi riposare sugli allori solo\n"
	.string "perché hai tante MEDAGLIE.\p"
	.string "Ci sarà sempre qualcuno più forte di te!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Sei più forte di me, non c’è che dire!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Le tue MEDAGLIE sono un ricordo\n"
	.string "degli ALLENATORI che hai sfidato.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Sono arrivato fin qui, ma ho il mal di\n"
	.string "stomaco per la tensione…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Oh… che male…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Non posso fare a meno di essere\n"
	.string "in tensione sapendo che la LEGA\l"
	.string "POKéMON si avvicina.\p"
	.string "L’unica cosa che posso fare è fingere\n"
	.string "di essere calmo.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "Il meglio del meglio si riunisce in\n"
	.string "questa grotta.\p"
	.string "Che te ne pare?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Non hai preso neppure uno spavento!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Ne hai di coraggio! Mi piace!\n"
	.string "Continua così!$"

