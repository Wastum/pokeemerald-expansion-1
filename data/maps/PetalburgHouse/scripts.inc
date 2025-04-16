.set LOCALID_MOVE_RELEARNER, 1

PetalburgHouse_MapScripts::
	.byte 0

PetalburgHouse_EventScript_AbilityGuy::
	lockall
	faceplayer
	msgbox PetalburgHouse_Text_AbilityGuy1, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE, 2
	giveitem ITEM_ABILITY_PATCH, 2
	msgbox PetalburgHouse_Text_AbilityGuy2, MSGBOX_DEFAULT
	releaseall
	end

PetalburgHouse_Text_AbilityGuy1:
	.string "Hi there, I'm the ability guy!$"

PetalburgHouse_Text_AbilityGuy2:
	.string "Ain't I a nice guy?$"

PetalburgHouse_EventScript_SootheBellGirl::
	lockall
	faceplayer
	msgbox PetalburgHouse_Text_SootheBellGirl1, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	msgbox PetalburgHouse_Text_SootheBellGirl2, MSGBOX_DEFAULT
	releaseall
	end

PetalburgHouse_Text_SootheBellGirl1:
	.string "Hi, please take this!$"

PetalburgHouse_Text_SootheBellGirl2:
	.string "Your Pokémon will love it!$"

PetalburgHouse_EventScript_CashGirl::
	lockall
	faceplayer
	msgbox PetalburgHouse_Text_CashGirl1, MSGBOX_DEFAULT
	giveitem ITEM_AMULET_COIN
	msgbox PetalburgHouse_Text_CashGirl2, MSGBOX_DEFAULT
	releaseall
	end

PetalburgHouse_Text_CashGirl1:
	.string "Hi, please take this!$"

PetalburgHouse_Text_CashGirl2:
	.string "Your Pokémon will love it!$"

PetalburgHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, PetalburgHouse_EventScript_AskTeachMove
	msgbox PetalburgHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto PetalburgHouse_EventScript_AskTeachMove
	end

PetalburgHouse_EventScript_AskTeachMove::
	msgbox PetalburgHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, PetalburgHouse_EventScript_ComeBackWithHeartScale
	goto PetalburgHouse_EventScript_ChooseMon
	end

PetalburgHouse_EventScript_ChooseMon::
	msgbox PetalburgHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PetalburgHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, PetalburgHouse_EventScript_NoMoveToTeachMon
	goto PetalburgHouse_EventScript_ChooseMove
	end

PetalburgHouse_EventScript_ChooseMove::
	msgbox PetalburgHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, PetalburgHouse_EventScript_ChooseMon
	msgbox PetalburgHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto PetalburgHouse_EventScript_ComeBackWithHeartScale
	end

PetalburgHouse_EventScript_NoMoveToTeachMon::
	msgbox PetalburgHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto PetalburgHouse_EventScript_ChooseMon
	end

PetalburgHouse_EventScript_CantTeachEgg::
	msgbox PetalburgHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto PetalburgHouse_EventScript_ChooseMon
	end

PetalburgHouse_EventScript_ComeBackWithHeartScale::
	msgbox PetalburgHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

PetalburgHouse_Text_ImTheMoveTutor:
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"

PetalburgHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness HEART SCALE!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

PetalburgHouse_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

PetalburgHouse_Text_TeachWhichMove:
	.string "Which move should I teach?$"

PetalburgHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

PetalburgHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

PetalburgHouse_Text_ComeBackWithHeartScale:
	.string "If your POKéMON need to learn a move,\n"
	.string "come back with a HEART SCALE.$"

PetalburgHouse_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"

