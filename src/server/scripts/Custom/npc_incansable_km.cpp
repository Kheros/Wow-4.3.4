/*
*==============================================*  
*	   _/_/_/  _/_/_/                          *
*     _/        _/   _/   _/                   *
*    _/_/_/    _/     _/_/                     *
*   _/        _/      _/_/                     *
*  _/      _/_/_/   _/   _/                    *
*==============================================*
*           _/_/_/  _/_/_/  _/_/_/   _/_/_/    *
*          _/      _/  _/  _/  _/   _/         *
*         _/      _/  _/  _/_/_/   _/_/_/      *
*        _/_/_/  _/_/_/  _/   _/  _/           *
*    2015 Dev-KM             _/ _/_/_/_/       *
* -------------------------------------------- * 
* - Developer(s): KM                           *
* - Contacto: krizttian@live.com               *
* - Copyright (C) 2014 - 2015 FixCore.         *                                                
*==============================================*
*/
#include "ScriptPCH.h"
enum defines
{
// Guerrero Dps
	  warr_dps_cabeza       = 70256 ,
	  warr_dps_manos        = 70255,
	  warr_dps_piernas      = 70257,
	  warr_dps_pecho        = 70254,
	  warr_dps_hombros    = 70258,
// Paladin Heal
	paladin_heal_cabeza       = 70355,
	paladin_heal_manos        = 70354,
	paladin_heal_piernas      = 70356,
	paladin_heal_pecho        = 70353,
	paladin_heal_hombros    = 70357,
// Paladin Dps
	paladin_dps_cabeza       = 70251,
	paladin_dps_manos        = 70250,
	paladin_dps_piernas      = 70252,
	paladin_dps_pecho        = 70249,
	paladin_dps_hombros    = 70253,
// Dk Dps
	dk_dps_cabeza       = 70246,
	dk_dps_manos        = 70245,
	dk_dps_piernas      = 70247,
	dk_dps_pecho        = 70244,
	dk_dps_hombros    = 70248,
// Chaman Heal
	chaman_heal_cabeza       = 70266,
	chaman_heal_manos        = 70265,
	chaman_heal_piernas      = 70267,
	chaman_heal_pecho        = 70264,
	chaman_heal_hombros    = 70268,
// Chaman Elemental
	chaman_dps_melee_cabeza       = 70271,
	chaman_dps_melee_manos        = 70270,
	chaman_dps_melee_piernas      = 70272,
	chaman_dps_melee_pecho        = 70269,
	chaman_dps_melee_hombros    = 70273,
// Chaman Dps Spell
	chaman_dps_spell_cabeza       = 70276,
	chaman_dps_spell_manos        = 70275,
	chaman_dps_spell_piernas      = 70277,
	chaman_dps_spell_pecho        = 70274,
	chaman_dps_spell_hombros    = 70278,
// Brujo  Dps
	brujo_dps_cabeza       = 70315,
	brujo_dps_manos        = 70314,
	brujo_dps_piernas      = 70316,
	brujo_dps_pecho        = 70317,
	brujo_dps_hombros    = 70318,
// Mago
	mago_dps_cabeza       = 70300,
	mago_dps_manos        = 70299,
	mago_dps_piernas      = 70301,
	mago_dps_pecho        = 70302,
	mago_dps_hombros    = 70303,
// Picaro
	picaro_dps_cabeza       = 70444,
	picaro_dps_manos        = 70295,
	picaro_dps_piernas      = 70297,
	picaro_dps_pecho        = 70294,
	picaro_dps_hombros    = 70298,
// Cazador
	cazador_dps_cabeza       = 70261,
	cazador_dps_manos        = 70260,
	cazador_dps_piernas      = 70262,
	cazador_dps_pecho        = 70259,
	cazador_dps_hombros    = 70263,
// Druida Heal
	druida_heal_cabeza       = 70285,
	druida_heal_manos        = 70284,
	druida_heal_piernas      = 70286,
	druida_heal_pecho        = 70287,
	druida_heal_hombros    = 70288,
// Druida Dps Spell
	druida_dps_spell_cabeza       = 70290,
	druida_dps_spell_manos        = 70289,
	druida_dps_spell_piernas      = 70291,
	druida_dps_spell_pecho        = 70292,
	druida_dps_spell_hombros    = 70293,
// Druida Dps
	druida_dps_cabeza       = 70280,
	druida_dps_manos        = 70279,
	druida_dps_piernas      = 70281,
	druida_dps_pecho        = 70282,
	druida_dps_hombros    = 70283,
// Sacerdote Dps
	sacerdote_dps_cabeza       = 70310,
	sacerdote_dps_manos        = 70309,
	sacerdote_dps_piernas      = 70311,
	sacerdote_dps_pecho        = 70312,
	sacerdote_dps_hombros    = 70313,
// Sacerdote Heal
	sacerdote_heal_cabeza       = 70305,
	sacerdote_heal_manos        = 70304,
	sacerdote_heal_piernas      = 70306,
	sacerdote_heal_pecho        = 70307,
	sacerdote_heal_hombros    = 70308,
};
class npc_incansable_km : public CreatureScript
{
    public:
	   npc_incansable_km() : CreatureScript("npc_incansable_km"){}
		   bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		   {
			   pPlayer->ADD_GOSSIP_ITEM(4, "Guerrero Dps", GOSSIP_SENDER_MAIN, 0);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Paladin Heal", GOSSIP_SENDER_MAIN, 1);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Paladin Dps", GOSSIP_SENDER_MAIN, 2);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Dk Dps", GOSSIP_SENDER_MAIN, 3);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Chaman Heal", GOSSIP_SENDER_MAIN, 4);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Chaman Dps Melee", GOSSIP_SENDER_MAIN, 5);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Chaman Dps Spell", GOSSIP_SENDER_MAIN, 6);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Brujo Dps", GOSSIP_SENDER_MAIN, 7);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Mago Dps", GOSSIP_SENDER_MAIN, 8);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Picaro Dps", GOSSIP_SENDER_MAIN, 9);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Cazador Dps", GOSSIP_SENDER_MAIN, 10);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Druida Heal", GOSSIP_SENDER_MAIN, 11);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Druida Dps", GOSSIP_SENDER_MAIN, 12);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Druida Spell", GOSSIP_SENDER_MAIN, 13);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Sacerdote Dps", GOSSIP_SENDER_MAIN, 14);
			   pPlayer->ADD_GOSSIP_ITEM(4, "Sacerdote Heal", GOSSIP_SENDER_MAIN, 15);
			   pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			   return true;
		   }
		   bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 Action)
		   {
			   if (Action == 0)
			   {
				   pPlayer->AddItem(warr_dps_cabeza, 1);
				   pPlayer->AddItem(warr_dps_manos ,1);
				   pPlayer->AddItem(warr_dps_piernas ,1);
				   pPlayer->AddItem(warr_dps_pecho, 1);
				   pPlayer->AddItem(warr_dps_hombros, 1);
			   }
			   else if (Action == 1)
			   {
				   pPlayer->AddItem(paladin_heal_cabeza, 1);
				   pPlayer->AddItem(paladin_heal_manos ,1);
				   pPlayer->AddItem(paladin_heal_piernas ,1);
				   pPlayer->AddItem(paladin_heal_pecho, 1);
				   pPlayer->AddItem(paladin_heal_hombros, 1);
			   }
			   else if (Action == 2)
			   {
				   pPlayer->AddItem(paladin_dps_cabeza, 1);
				   pPlayer->AddItem(paladin_dps_manos ,1);
				   pPlayer->AddItem(paladin_dps_piernas ,1);
				   pPlayer->AddItem(paladin_dps_pecho, 1);
				   pPlayer->AddItem(paladin_dps_hombros, 1);
			   }
			   else if (Action == 3)
			   {
				   pPlayer->AddItem(dk_dps_cabeza, 1);
				   pPlayer->AddItem(dk_dps_manos ,1);
				   pPlayer->AddItem(dk_dps_piernas ,1);
				   pPlayer->AddItem(dk_dps_pecho, 1);
				   pPlayer->AddItem(dk_dps_hombros, 1);
			   }
			   else if (Action == 4)
			   {
				   pPlayer->AddItem(chaman_heal_cabeza, 1);
				   pPlayer->AddItem(chaman_heal_manos ,1);
				   pPlayer->AddItem(chaman_heal_piernas ,1);
				   pPlayer->AddItem(chaman_heal_pecho, 1);
				   pPlayer->AddItem(chaman_heal_hombros, 1);
			   }
			   else if (Action == 5)
			   {
				   pPlayer->AddItem(chaman_dps_melee_cabeza, 1);
				   pPlayer->AddItem(chaman_dps_melee_manos ,1);
				   pPlayer->AddItem(chaman_dps_melee_piernas ,1);
				   pPlayer->AddItem(chaman_dps_melee_pecho, 1);
				   pPlayer->AddItem(chaman_dps_melee_hombros, 1);
			   }
			   else if (Action == 6)
			   {
				  pPlayer->AddItem(chaman_dps_spell_cabeza, 1);
				   pPlayer->AddItem(chaman_dps_spell_manos ,1);
				   pPlayer->AddItem(chaman_dps_spell_piernas ,1);
				   pPlayer->AddItem(chaman_dps_spell_pecho, 1);
				   pPlayer->AddItem(chaman_dps_spell_hombros, 1);
			   }
			   else if (Action == 7)
			   {
				   pPlayer->AddItem(brujo_dps_cabeza, 1);
				   pPlayer->AddItem(brujo_dps_manos ,1);
				   pPlayer->AddItem(brujo_dps_piernas ,1);
				   pPlayer->AddItem(brujo_dps_pecho, 1);
				   pPlayer->AddItem(brujo_dps_hombros, 1);
			   }
			   else if (Action == 8)
			   {
				   pPlayer->AddItem(mago_dps_cabeza, 1);
				   pPlayer->AddItem(mago_dps_manos ,1);
				   pPlayer->AddItem(mago_dps_piernas ,1);
				   pPlayer->AddItem(mago_dps_pecho, 1);
				   pPlayer->AddItem(mago_dps_hombros, 1);
			   }
			   else if (Action == 9)
			   {
				   pPlayer->AddItem(picaro_dps_cabeza, 1);
				   pPlayer->AddItem(picaro_dps_manos ,1);
				   pPlayer->AddItem(picaro_dps_piernas ,1);
				   pPlayer->AddItem(picaro_dps_pecho, 1);
				   pPlayer->AddItem(picaro_dps_hombros, 1);
			   }
			   else if (Action == 10)
			   {
				   pPlayer->AddItem(cazador_dps_cabeza, 1);
				   pPlayer->AddItem(cazador_dps_manos ,1);
				   pPlayer->AddItem(cazador_dps_piernas ,1);
				   pPlayer->AddItem(cazador_dps_pecho, 1);
				   pPlayer->AddItem(cazador_dps_hombros, 1);
			   }
			   else if (Action == 11)
			   {
				   pPlayer->AddItem(druida_heal_cabeza, 1);
				   pPlayer->AddItem(druida_heal_manos ,1);
				   pPlayer->AddItem(druida_heal_piernas ,1);
				   pPlayer->AddItem(druida_heal_pecho, 1);
				   pPlayer->AddItem(druida_heal_hombros, 1);
			   }
			   else if (Action == 12)
			   {
				   pPlayer->AddItem(druida_dps_cabeza, 1);
				   pPlayer->AddItem(druida_dps_manos ,1);
				   pPlayer->AddItem(druida_dps_piernas ,1);
				   pPlayer->AddItem(druida_dps_pecho, 1);
				   pPlayer->AddItem(druida_dps_hombros, 1);
			   }
			   else if (Action == 13)
			   {
				   pPlayer->AddItem(druida_dps_spell_cabeza, 1);
				   pPlayer->AddItem(druida_dps_spell_manos ,1);
				   pPlayer->AddItem(druida_dps_spell_piernas ,1);
				   pPlayer->AddItem(druida_dps_spell_pecho, 1);
				   pPlayer->AddItem(druida_dps_spell_hombros, 1);
			   }
			   
			   else if (Action == 14)
			   {
				   pPlayer->AddItem(sacerdote_dps_cabeza, 1);
				   pPlayer->AddItem(sacerdote_dps_manos ,1);
				   pPlayer->AddItem(sacerdote_dps_piernas ,1);
				   pPlayer->AddItem(sacerdote_dps_pecho, 1);
				   pPlayer->AddItem(sacerdote_dps_hombros, 1);
			   }
			   else if (Action == 15)
			   {
				   pPlayer->AddItem(sacerdote_heal_cabeza, 1);
				   pPlayer->AddItem(sacerdote_heal_manos ,1);
				   pPlayer->AddItem(sacerdote_heal_piernas ,1);
				   pPlayer->AddItem(sacerdote_heal_pecho, 1);
				   pPlayer->AddItem(sacerdote_heal_hombros, 1);
			   }
			   return true;
		   }
};
void AddSC_npc_incansable_km()
{
new npc_incansable_km();
}