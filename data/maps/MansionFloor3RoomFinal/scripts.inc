MansionFloor3RoomFinal_MapScripts::
	.byte 0




MansionFloor3RoomFinal_EventScript_Trigger1::
	lockall
	setvar VAR_TEMP_0, 1
	msgbox_portrait MansionFloor3RoomFinal_Text_Craftily1, FIELD_PIC_CRADILY_DARK
	closemessage
	delay 100
	releaseall
	end


sText_CradilyNickname:
	.string "CRAFTILY$"

MansionFloor3RoomFinal_Text_Craftily1:
	.string "I cannot bear to look at you. Everyone\n"
	.string "else has forgotten.\p"
	.string "Just go back the way you came, jump\n"
	.string "into the Fountain, and try to forget.\p"
	.string "Please.$"


MansionFloor3RoomFinal_EventScript_Trigger2::
	lockall
	setvar VAR_TEMP_0, 1
	msgbox_portrait MansionFloor3RoomFinal_Text_Craftily2, FIELD_PIC_CRADILY_DARK
	closemessage
	delay 100
	msgbox_portrait MansionFloor3RoomFinal_Text_Craftily3, FIELD_PIC_CRADILY_DARK
	applymovement LOCALID_CRADILY, MansionFloor1RoomBoss_LookLeft
	delay 80
	applymovement LOCALID_CRADILY, MansionFloor1RoomBoss_LookDown
	delay 100
	msgbox_portrait MansionFloor3RoomFinal_Text_Craftily4, FIELD_PIC_CRADILY_DETERMINED

	setflag FLAG_BATTLE_START_LEECH_SEED
	@settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 0, 0, 1
	setwildbattle SPECIES_CRADILY, 96, ITEM_LEFTOVERS
    setenemymonnick 0, sText_CradilyNickname
	setenemymonmoves 0, MOVE_ROCK_SMASH, MOVE_STOCKPILE, MOVE_PROTECT, 0
    setenemymonshiny 0, TRUE
    setenemymonhp 0, 75
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
    tryforcedoublebattle
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, MansionFloor1RoomBoss_EventScript_End
	@setflag FLAG_BOSS3_CLEAR

	@@@CUTSCENE here
	msgbox MansionFloor3RoomFinal_Text_CraftilyLose01, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MansionFloor3RoomFinal_EventScript_DontRelive
	goto_if_eq VAR_RESULT, YES, MansionFloor3RoomFinal_EventScript_Relive
	end

MansionFloor3RoomFinal_EventScript_Relive::
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyRelive, FIELD_PIC_CRADILY_DETERMINED
	goto MansionFloor3RoomFinal_EventScript_FinalScene
	end

MansionFloor3RoomFinal_EventScript_DontRelive::
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyDontRelive, FIELD_PIC_CRADILY_DETERMINED
	goto MansionFloor3RoomFinal_EventScript_FinalScene
	end

@placeholder, until cutscene done TOFOLD
MansionFloor3RoomFinal_EventScript_FinalScene::
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose02, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose03, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose04, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose05, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose06, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose07, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose08, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose09, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose10, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose11, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose12, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose13, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose14, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose15, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose16, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose17, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose18, FIELD_PIC_CRADILY_DETERMINED
	msgbox_portrait MansionFloor3RoomFinal_Text_CraftilyLose19, FIELD_PIC_CRADILY_DETERMINED
	@add a fade to black, warp to end, etc.
	end


MansionFloor3RoomFinal_Text_Craftily2:
	.string "You won’t leave, will you?\p"
	.string "You want answers.\p"
	.string "Despite my best efforts, despite all\n"
	.string "those who protected me… \p"
	.string "You were driven to defeat them all.\p"
	.string "You couldn’t forget. \p"
	.string "And if you can’t forget, I can't forget.$"


MansionFloor3RoomFinal_Text_Craftily3:
	.string "Come. Perhaps it is time.$"


MansionFloor3RoomFinal_Text_Craftily4:
	.string "Look at me.\p"
	.string "Look at your old friend, Craftily.\p"
	.string "Look at my dead eyes, my cursed body.\p"
	.string "I am at death’s door.\p"
	.string "I cannot move, and I can barely speak.\p"
	.string "And I am likely too old to survive a\n"
	.string "battle with you.\p"
	.string "If you defeat me, I will die.\p"
	.string "…\p"
	.string "But. I wronged you.\p"
	.string "I erased your memories, incompetently,\n"
	.string "by forcing you into the Fountain.\p"
	.string "You deserve your revenge.\p"
	.string "So.\p"
	.string "Let’s end this.$"


MansionFloor3RoomFinal_Text_CraftilyLose01:
	.string "Craftily: Well… well fought. This cursed\n"
	.string "body of mine… is truly broken.\p"
	.string "…what?\p"
	.string "You still want to hear about the past?\p"
	.string "In my final moments, you want me to \n"
	.string "relive the worst memories of my life?$"


MansionFloor3RoomFinal_Text_CraftilyRelive:
	.string "I suppose it’s what you deserve.\n"
	.string "And it may be what I deserve as well.\p"
	.string "Listen.$"

MansionFloor3RoomFinal_Text_CraftilyDontRelive:
	.string "…\p"
	.string "Such kindness.\p"
	.string "For the creature who destroyed you.\p"
	.string "It reminds me of… better days.\p"
	.string "Days we spent together working hard\n"
	.string "to achieve our impossible dream.\p"
	.string "…\p"
	.string "I will relive those moments for you.\n"
	.string "The good and the bad.\p"
	.string "Listen well.$"

@lab choosing squirtle
MansionFloor3RoomFinal_Text_CraftilyLose02:
	.string "Once, long ago, we were the friends and\n"
	.string "companions of a strong woman named Ada.\p"
	.string "Ada was a human who had formed a\n"
	.string "sacred bond with each of us.\p"
	.string "She trained us, raised us, and took\n"
	.string "care of us like her children. \p"
	.string "There are many such humans in the\n"
	.string "civilized parts of the world.$"

@catching shiny Venipede
MansionFloor3RoomFinal_Text_CraftilyLose03:
	.string "Ada was uniquely single-minded in her\n"
	.string "obsessions.\p"
	.string "She was a perfectionist in everything,\n"
	.string "even her choice of Pokémon.\p"
	.string "That’s why she carefully, meticulously\n"
	.string "chose us; all shiny, and perfect stats.$"

@brawly gym?
MansionFloor3RoomFinal_Text_CraftilyLose04:
	.string "Ada spent the first twenty years of\n"
	.string "her life perfecting her physical and\l"
	.string "mental fitness, her team of Pokémon,\l"
	.string "us, and her items and resources.\p"
	.string "Then, a grander goal took hold of her.\n"
	.string "She wished to live forever.\p"
	.string "She took us, her six most trusted and\n"
	.string "most powerful companions, on a journey\l"
	.string "to find a mythical artifact said to\l"
	.string "grant eternal life.\p"
	.string "It was called… The Fountain of Youth.$"

@adventuring
MansionFloor3RoomFinal_Text_CraftilyLose05:
	.string "It was an impossible, arduous journey.\n"
	.string "But our pure bonds made the work light.\p"
	.string "We were a single team, seven creatures\n"
	.string "united by our goal.$"

@Fountain shot
MansionFloor3RoomFinal_Text_CraftilyLose06:
	.string "It took our team fifty long years of\n"
	.string "searching to find it, but in the end\l"
	.string "we did find it.\p"
	.string "The same Fountain you refer to as the\n"
	.string "Inkwell; that is the one and only\l"
	.string "Fountain of Youth of legend.$"

@old ada walking to the well
MansionFloor3RoomFinal_Text_CraftilyLose07:
	.string "By that time, we were all old and feeble.\p"
	.string "Ada herself could barely walk, but as\n"
	.string "she sipped the Fountain's dark water,\l"
	.string "we could see her youth return.\p"
	.string "She drank a little at a time, and became\n"
	.string "a healthy young woman, before our eyes.\p"
	.string "Her memories had not fared so well, \n"
	.string "perhaps linked inextricably to age,\l"
	.string "but it was a small price to pay.$"

@other Pokemon shift
MansionFloor3RoomFinal_Text_CraftilyLose08:
	.string "Our joy knew no bounds.\p"
	.string "Eternal life was be our ultimate reward\n"
	.string "for the decades of fruitless search.\p"
	.string "We all gathered around the Fountain to\n"
	.string "drink and be restored. \p"
	.string "I watched as your bodies shifted and\n"
	.string "changed into your earlier forms,\l"
	.string "and we laughed and danced and cried.$"

@cradily failure
MansionFloor3RoomFinal_Text_CraftilyLose09:
	.string "But when I went to drink from the\n"
	.string "Fountain, the dark waters simply\l"
	.string "drained away around me.\p"
	.string "The water couldn’t touch me.\n"
	.string "I had been born with a cursed body.\p"
	.string "STORM DRAIN, a rare mutation that Ada\n"
	.string "had searched for among many Lileep.\p"
	.string "Just because of that mutation, I would\n"
	.string "not be able to claim my immortality.$"

@running around, slow cradily
MansionFloor3RoomFinal_Text_CraftilyLose10:
	.string "In just a few days, my curse and my pain\n"
	.string "were forgotten by Ada and the team in\l"
	.string "the joy of new youth.\p"
	.string "Life continued on, for a long period.\p"
	.string "We built the house, and Ada made\n"
	.string "herself a simple, fulfilling life.\p"
	.string "I grew older and closer to death, while\n"
	.string "my closest friends were having the time\l"
	.string "of their lives.\p"
	.string "I had become uncomfortable to see,\n"
	.string "uncomfortable to think about.\p"
	.string "It might have continued in this way,\n"
	.string "with my death a brief moment of regret\l"
	.string "in your immortal lives… \p"
	.string "but one day I glimpsed a new… sparkle.$"

@shiny phanpy among others
MansionFloor3RoomFinal_Text_CraftilyLose11:
	.string "From the wild Pokémon around the house,\n"
	.string "Ada had found a shiny Phanpy.\p"
	.string "I knew then and there that I would be\n"
	.string "left to die, and this Pokémon would be\l"
	.string "my replacement on her perfect team.$"

@confrontation
MansionFloor3RoomFinal_Text_CraftilyLose12:
	.string "My emotions wild, I confronted Ada.\p"
	.string "In the ensuing struggle, I did\n"
	.string "something that will haunt me for the\l"
	.string "rest of my pathetic existence.$"

@push
MansionFloor3RoomFinal_Text_CraftilyLose13:
	.string "I pushed Ada into the Fountain.$"

@black
MansionFloor3RoomFinal_Text_CraftilyLose14:
	.string "I panicked as soon as she fell in,\n"
	.string "pulling her out with my vines.\p"
	.string "But the damage was done.\p"
	.string "Humans don’t have eggs.\p"
	.string "What was left of Ada was a shriveled\n"
	.string "pink thing that wasn’t moving.\p"
	.string "It couldn’t survive on its own.\p"
	.string "I… I had killed her.$"

@grave
MansionFloor3RoomFinal_Text_CraftilyLose15:
	.string "I couldn’t live with my shame. None of\n"
	.string "you blamed me, but I couldn’t bear it.\p"
	.string "So I did another cowardly thing.\p"
	.string "I was dying, but I still had terrible\n"
	.string "strength compared to your young forms.$"

@black
MansionFloor3RoomFinal_Text_CraftilyLose16:
	.string "I pushed you all into the Fountain too.\p"
	.string "…\p"
	.string "If no one remembered her… maybe it\n"
	.string "never happened.\p"
	.string "…$"

@cradily with eggs
MansionFloor3RoomFinal_Text_CraftilyLose17:
	.string "I stayed with your eggs. I took care\n"
	.string "of you as children. Some of you called\l"
	.string "me Father, and I let you.\p"
	.string "But no matter how many times I erased\n"
	.string "your memories, some would always rise\l"
	.string "to the surface.\p"
	.string "Questions I couldn’t answer, feelings\n"
	.string "I couldn’t suppress.\p"
	.string "And there was my own cursed mind, full\n"
	.string "of memories of my crimes, and my cursed\l"
	.string "body, which refused the Fountain.$"

@cradily walks slowly back to room
MansionFloor3RoomFinal_Text_CraftilyLose18:
	.string "And so I gave in, and retreated here,\n"
	.string "waiting for death.\p"
	.string "A wish that you’ve just granted.$"


@back to present
MansionFloor3RoomFinal_Text_CraftilyLose19:
	.string "…\p"
	.string "I don’t regret talking about the past.\p"
	.string "It… felt like it was a long time coming.\p"
	.string "And now I’ve given you the choice,\n"
	.string "rather than make it for you. \p"
	.string "You don’t have to carry the burdens\n"
	.string "I’ve given you.\p"
	.string "You can remember, or you can choose to\n"
	.string "jump into the Fountain.\p"
	.string "But, that’s enough from me.\n"
	.string "Leave me, so I may die in peace.\p"
	.string "I’m sorry for the pain I’ve caused.\n"
	.string "Goodbye, old friends.$"








