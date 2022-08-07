SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MONTE PIRA…\p"
	.string "Sapevi che sulla sua cima ci sono due\n"
	.string "SFERE l’una accanto all’altra?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Sì, due sfere l’una accanto\n"
	.string "all’altra…\p"
	.string "La loro vista in qualche modo…\n"
	.string "infonde tranquillità…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Davvero?\n"
	.string "Varrebbe la pena andare a vedere…$"

