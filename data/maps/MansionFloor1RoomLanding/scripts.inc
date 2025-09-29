MansionFloor1RoomLanding_MapScripts::
	.byte 0



MansionFloor1RoomLanding_EventScript_Abra::
	lockall
	goto_if_set FLAG_ABRATALK_LANDING_1, MansionFloor1RoomLanding_EventScript_TalkAgain
	goto_if_set FLAG_VISITED_LANDING_1, MansionFloor1RoomLanding_EventScript_Revisit
	msgbox_portrait MansionFloor1RoomLanding_Text_FirstTime1, FIELD_PIC_ABRA_HAPPY
	msgbox_portrait MansionFloor1RoomLanding_Text_FirstTime2, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait MansionFloor1RoomLanding_Text_FirstTime3, FIELD_PIC_ABRA_THINKING
	msgbox_portrait MansionFloor1RoomLanding_Text_FirstTime4, FIELD_PIC_ABRA_HAPPY

	@look for empty vials

	checkitem ITEM_LATIASITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstTimeVials
	checkitem ITEM_SALAMENCITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstTimeVials
	checkitem ITEM_METAGROSSITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstTimeVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstTimeVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstTimeVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstTimeVials

	
	@fulls?
	checkitem ITEM_LATIOSITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstFullVials
	checkitem ITEM_LOPUNNITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstFullVials
	checkitem ITEM_GARCHOMPITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_1, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_2, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_3, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FirstFullVials


	@player didn't pick up any vials, even the free one

	msgbox_portrait MansionFloor1RoomLanding_Text_FirstTime5NoVial, FIELD_PIC_ABRA_CONCERNED
	setflag FLAG_VISITED_LANDING_1
	setflag FLAG_ABRATALK_LANDING_1
	clearflag FLAG_ABRA_IN_PARTY_2
	releaseall
	end



MansionFloor1RoomLanding_EventScript_FirstFullVials::
	msgbox_portrait MansionFloor1RoomLanding_Text_FirstFullVials, FIELD_PIC_ABRA_JOY
	closemessage
	setflag FLAG_VISITED_LANDING_1
	setflag FLAG_ABRATALK_LANDING_1
	clearflag FLAG_ABRA_IN_PARTY_2
	releaseall
	end

MansionFloor1RoomLanding_Text_FirstFullVials:
	.string "Oh wait, you made it through\n"
	.string "without using vials! Nice$"




MansionFloor1RoomLanding_EventScript_FirstTimeVials::
	msgbox_portrait MansionFloor1RoomLanding_Text_FirstTime5Vial, FIELD_PIC_ABRA_SERIOUS
	msgbox_portrait MansionFloor1RoomLanding_Text_FirstTime6, FIELD_PIC_ABRA_JOY
	closemessage
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	end
	


MansionFloor1RoomLanding_Text_FirstTime1:
	.string "Dali: Whoa, you made it through the\n"
	.string "first floor!\p"
	.string "I knew you could do it!\p"
	.string "Craftily must be higher up…$"

MansionFloor1RoomLanding_Text_FirstTime2:
	.string "I can Teleport to these little green\n"
	.string "pads anytime.$"

MansionFloor1RoomLanding_Text_FirstTime3:
	.string "Why are there so many around here?\n"
	.string "Did I set them up?$"

MansionFloor1RoomLanding_Text_FirstTime4:
	.string "Anyways, I can't fight, but maybe I\n"
	.string "can help you from these spots!$"


MansionFloor1RoomLanding_Text_FirstTime5NoVial:
	.string "Umm…\p"
	.string "I… can't think of a way to help.\p"
	.string "Maybe I could bring something from\n"
	.string "outside? If you had the right item?$"

MansionFloor1RoomLanding_Text_FirstTime5Vial:
	.string "Hmm…\p"
	.string "Is that a glass vial? I have an idea.\p"
	.string "Can I see it?$"

MansionFloor1RoomLanding_Text_FirstTime6:
	.string "Dali: This is perfect!\p"
	.string "I can go back to the Inkwell and get\n"
	.string "some of the dark water for you!\p"
	.string "One vial should be enough to heal you\n"
	.string "completely, even if you're knocked out!\p"
	.string "And you should only get a little\n"
	.string "younger! Be right back!$"





@Not first time on the landing

MansionFloor1RoomLanding_EventScript_Revisit::
	
	@look for empty vials
	checkitem ITEM_LATIASITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitVials
	checkitem ITEM_SALAMENCITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitVials
	checkitem ITEM_METAGROSSITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitVials

	@now make sure they have full vials - if they don't have any, they don't have vials period
	checkitem ITEM_LATIOSITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitFullVials
	checkitem ITEM_LOPUNNITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitFullVials
	checkitem ITEM_GARCHOMPITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_1, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_2, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_3, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_RevisitFullVials

	msgbox_portrait MansionFloor1RoomLanding_Text_StillNoVials1, FIELD_PIC_ABRA_CONCERNED
	msgbox_portrait MansionFloor1RoomLanding_Text_StillNoVials2, FIELD_PIC_ABRA_THINKING
	msgbox_portrait MansionFloor1RoomLanding_Text_StillNoVials3, FIELD_PIC_ABRA_JOY
	setflag FLAG_ABRATALK_LANDING_1
	clearflag FLAG_ABRA_IN_PARTY_2
	releaseall
	end



MansionFloor1RoomLanding_EventScript_RevisitVials::
	msgbox_portrait MansionFloor1RoomLanding_Text_RevisitVials1, FIELD_PIC_ABRA_HAPPY
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	@msgbox_portrait MansionFloor1RoomLanding_Text_RevisitVials2, FIELD_PIC_ABRA_JOY
	@setflag FLAG_ABRATALK_LANDING_1
	clearflag FLAG_ABRA_IN_PARTY_2
	releaseall
	end



MansionFloor1RoomLanding_Text_RevisitVials1:
	.string "Dali: Welcome back! I can refill your\n"
	.string "vials, one sec!$"

@MansionFloor1RoomLanding_Text_RevisitVials2:
@	.string "You're all set!\n"
@	.string "Good luck!$"



MansionFloor1RoomLanding_EventScript_RevisitFullVials::
	msgbox_portrait MansionFloor1RoomLanding_Text_RevisitFullVials1, FIELD_PIC_ABRA_HAPPY
	msgbox_portrait MansionFloor1RoomLanding_Text_RevisitFullVials2, FIELD_PIC_ABRA_JOY
	closemessage
	setflag FLAG_ABRATALK_LANDING_1
	clearflag FLAG_ABRA_IN_PARTY_2
	releaseall
	end



MansionFloor1RoomLanding_Text_RevisitFullVials1:
	.string "Dali: Welcome back! I can refill…\p"
	.string "Wait, you made it through without\n"
	.string "drinking from the Inkwell?!$"

MansionFloor1RoomLanding_Text_RevisitFullVials2:
	.string "That's awesome! You'll get Craftily\n"
	.string "in no time!$"


MansionFloor1RoomLanding_Text_StillNoVials1:
	.string "Dali: You still don't have any vials?\p"
	.string "B-but there's one right in the middle\n"
	.string "of the first room!$"

MansionFloor1RoomLanding_Text_StillNoVials2:
	.string "…wait a minute.\p"
	.string "Are you… doing a challenge run?$"

MansionFloor1RoomLanding_Text_StillNoVials3:
	.string "That's so cool!\p"
	.string "You're probably not winning, but wow,\n"
	.string "what a neat idea!$"







MansionFloor1RoomLanding_EventScript_TalkAgain::
	
	@look for empty vials

	checkitem ITEM_LATIASITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainVials
	checkitem ITEM_SALAMENCITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainVials
	checkitem ITEM_METAGROSSITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainVials
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainVials

	@now make sure they have full vials - if they don't have any, they don't have vials period

	checkitem ITEM_LATIOSITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainFullVials
	checkitem ITEM_LOPUNNITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainFullVials
	checkitem ITEM_GARCHOMPITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_1, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_2, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainFullVials
	checkitem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_3, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_TalkAgainFullVials


	msgbox_portrait MansionFloor1RoomLanding_Text_TalkAgainNoVials, FIELD_PIC_ABRA_CONCERNED
	closemessage
	clearflag FLAG_ABRA_IN_PARTY_2
	release
	end








MansionFloor1RoomLanding_EventScript_TalkAgainVials::
	msgbox_portrait MansionFloor1RoomLanding_Text_TalkAgainVials, FIELD_PIC_ABRA_HAPPY
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	end

MansionFloor1RoomLanding_Text_TalkAgainVials:
	.string "Wow, you look better already!\n"
	.string "Let me refill that for you.$"




MansionFloor1RoomLanding_EventScript_TalkAgainFullVials::
	msgbox_portrait MansionFloor1RoomLanding_Text_TalkAgainFullVials, FIELD_PIC_ABRA_HAPPY
	clearflag FLAG_ABRA_IN_PARTY_2
	closemessage
	releaseall
	end

MansionFloor1RoomLanding_Text_TalkAgainFullVials:
	.string "I'll fill up your vials whenever you\n"
	.string "need it!\p"
	.string "Good luck up there!$"


MansionFloor1RoomLanding_Text_TalkAgainNoVials:
	.string "Not sure what I can do to help.$"











MansionFloor1RoomLanding_EventScript_FillUpVials::

	@check for empty vials, recursively fill each one

	checkitem ITEM_LATIASITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FillLatias
	checkitem ITEM_SALAMENCITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FillSalamence
	checkitem ITEM_METAGROSSITE, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_FillMetagross
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_Fill1
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_Fill2
	checkitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3, 1
	goto_if_eq VAR_RESULT, YES, MansionFloor1RoomLanding_EventScript_Fill3
	
	setflag FLAG_EXPLAINED_VIALS
	removeobject LOCALID_ABRA
	playse SE_WARP_OUT
	delay 150
	addobject LOCALID_ABRA
	playse SE_WARP_IN
	waitse
	delay 20
	goto MansionFloor1RoomLanding_EventScript_VialsFilled
	end


MansionFloor1RoomLanding_EventScript_FillLatias::
	removeitem ITEM_LATIASITE, 1
	additem ITEM_LATIOSITE, 1
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	end

MansionFloor1RoomLanding_EventScript_FillSalamence::
	removeitem ITEM_SALAMENCITE, 1
	additem ITEM_LOPUNNITE, 1
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	end

MansionFloor1RoomLanding_EventScript_FillMetagross::
	removeitem ITEM_METAGROSSITE, 1
	additem ITEM_GARCHOMPITE, 1
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	end

MansionFloor1RoomLanding_EventScript_Fill1::
	removeitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1, 1
	additem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_1, 1
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	end

MansionFloor1RoomLanding_EventScript_Fill2::
	removeitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2, 1
	additem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_2, 1
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	end

MansionFloor1RoomLanding_EventScript_Fill3::
	removeitem UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3, 1
	additem UNIQUE_ITEM_INKWELL_FULL_BOTTLE_3, 1
	goto MansionFloor1RoomLanding_EventScript_FillUpVials
	end




MansionFloor1RoomLanding_EventScript_VialsFilled::
	msgbox_portrait MansionFloor1RoomLanding_Text_AllSet, FIELD_PIC_ABRA_JOY
	closemessage
	setflag FLAG_VISITED_LANDING_1
	setflag FLAG_ABRATALK_LANDING_1
	setflag FLAG_EXPLAINED_VIALS
	clearflag FLAG_ABRA_IN_PARTY_2
	releaseall
	end


MansionFloor1RoomLanding_Text_AllSet:
	.string "You're all set!\n"
	.string "Good luck!$"