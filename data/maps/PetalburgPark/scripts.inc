PetalburgPark_MapScripts::
	.byte 0

PetalburgPark_EventScript_Red::
	lock
	faceplayer
	msgbox PetalburgPark_Text_Red, MSGBOX_NPC
	giveitem ITEM_POKE_BALL, 5
	msgbox PetalburgPark_Text_Red2, MSGBOX_NPC
	pokemart Pokemart_Red
	msgbox PetalburgPark_Text_Red3, MSGBOX_NPC
	end

	.align 2
Pokemart_Red:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE

PetalburgPark_Text_Red:
	.string "...\n"
	.string "Whatever$"

PetalburgPark_Text_Red2:
	.string "Kopen!$"

PetalburgPark_Text_Red3:
	.string "Vooruit dan maar$"