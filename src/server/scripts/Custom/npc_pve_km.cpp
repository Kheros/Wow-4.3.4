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
	warr_dps_cabeza = 71070,
	warr_dps_manos = 71069,
	warr_dps_piernas = 71071,
	warr_dps_pecho = 71068,
	warr_dps_hombros = 71072,
	// Guerrero Tank
	warr_tank_cabeza = 70944,
	warr_tank_manos = 70943,
	warr_tank_piernas = 70942,
	warr_tank_pecho = 70945,
	warr_tank_hombros = 70941,
	// Paladin Heal
	paladin_heal_cabeza = 71093,
	paladin_heal_manos = 71092,
	paladin_heal_piernas = 71094,
	paladin_heal_pecho = 71091,
	paladin_heal_hombros = 71095,
	// Paladin Dps
	paladin_dps_cabeza = 71065,
	paladin_dps_manos = 71064,
	paladin_dps_piernas = 71066,
	paladin_dps_pecho = 71063,
	paladin_dps_hombros = 71067,
	// Paladin Tank
	paladin_tank_cabeza = 70948,
	paladin_tank_manos = 70949,
	paladin_tank_piernas = 70947,
	paladin_tank_pecho = 70950,
	paladin_tank_hombros = 70946,
	// Dk Dps
	dk_dps_cabeza = 71060,
	dk_dps_manos = 71059,
	dk_dps_piernas = 71061,
	dk_dps_pecho = 71058,
	dk_dps_hombros = 71062,
	// Chaman Heal
	chaman_heal_cabeza = 71298,
	chaman_heal_manos = 71297,
	chaman_heal_piernas = 71299,
	chaman_heal_pecho = 71296,
	chaman_heal_hombros = 71300,
	// Chaman Elemental
	chaman_dps_melee_cabeza = 71303,
	chaman_dps_melee_manos = 71302,
	chaman_dps_melee_piernas = 71304,
	chaman_dps_melee_pecho = 71301,
	chaman_dps_melee_hombros = 71305,
	// Chaman Dps Spell
	chaman_dps_spell_cabeza = 71293,
	chaman_dps_spell_manos = 71292,
	chaman_dps_spell_piernas = 71294,
	chaman_dps_spell_pecho = 71291,
	chaman_dps_spell_hombros = 71295,
	// Brujo  Dps
	brujo_dps_cabeza = 71282,
	brujo_dps_manos = 71281,
	brujo_dps_piernas = 71283,
	brujo_dps_pecho = 71284,
	brujo_dps_hombros = 71285,
	// Mago
	mago_dps_cabeza = 71287,
	mago_dps_manos = 71286,
	mago_dps_piernas = 71288,
	mago_dps_pecho = 71289,
	mago_dps_hombros = 71290,
	// Picaro
	picaro_dps_cabeza = 71047,
	picaro_dps_manos = 71046,
	picaro_dps_piernas = 710487,
	picaro_dps_pecho = 71045,
	picaro_dps_hombros = 71049,
	// Cazador
	cazador_dps_cabeza = 71051,
	cazador_dps_manos = 71050,
	cazador_dps_piernas = 71052,
	cazador_dps_pecho = 71054,
	cazador_dps_hombros = 71053,
	// Druida Heal
	druida_heal_cabeza = 71103,
	druida_heal_manos = 71102,
	druida_heal_piernas = 71104,
	druida_heal_pecho = 71105,
	druida_heal_hombros = 71105,
	// Druida Dps Spell
	druida_dps_spell_cabeza = 71108,
	druida_dps_spell_manos = 71107,
	druida_dps_spell_piernas = 71109,
	druida_dps_spell_pecho = 91110,
	druida_dps_spell_hombros = 71111,
	// Druida Dps
	druida_dps_cabeza = 71098,
	druida_dps_manos = 71097,
	druida_dps_piernas = 71099,
	druida_dps_pecho = 71100,
	druida_dps_hombros = 71101,
	// Sacerdote Dps
	sacerdote_dps_cabeza = 71277,
	sacerdote_dps_manos = 71276,
	sacerdote_dps_piernas = 71278,
	sacerdote_dps_pecho = 71279,
	sacerdote_dps_hombros = 71280,
	// Sacerdote Heal
	sacerdote_heal_cabeza = 71272,
	sacerdote_heal_manos = 71271,
	sacerdote_heal_piernas = 71273,
	sacerdote_heal_pecho = 71274,
	sacerdote_heal_hombros = 71275,
};
class npc_pve_km : public CreatureScript
{
public:
	npc_pve_km() : CreatureScript("npc_pve_km"){}
	bool OnGossipHello(Player * pPlayer, Creature * pCreature)
	{
		pPlayer->ADD_GOSSIP_ITEM(4, "Guerrero Dps", GOSSIP_SENDER_MAIN, 0);
		pPlayer->ADD_GOSSIP_ITEM(4, "Guerrero Tank", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(4, "Paladin Heal", GOSSIP_SENDER_MAIN, 2);
		pPlayer->ADD_GOSSIP_ITEM(4, "Paladin Dps", GOSSIP_SENDER_MAIN, 3);
		pPlayer->ADD_GOSSIP_ITEM(4, "Paladin Tank", GOSSIP_SENDER_MAIN, 4);
		pPlayer->ADD_GOSSIP_ITEM(4, "Dk Dps", GOSSIP_SENDER_MAIN, 5);
		pPlayer->ADD_GOSSIP_ITEM(4, "Chaman Heal", GOSSIP_SENDER_MAIN, 6);
		pPlayer->ADD_GOSSIP_ITEM(4, "Chaman Dps Melee", GOSSIP_SENDER_MAIN, 7);
		pPlayer->ADD_GOSSIP_ITEM(4, "Chaman Dps Spell", GOSSIP_SENDER_MAIN, 8);
		pPlayer->ADD_GOSSIP_ITEM(4, "Brujo Dps", GOSSIP_SENDER_MAIN, 9);
		pPlayer->ADD_GOSSIP_ITEM(4, "Mago Dps", GOSSIP_SENDER_MAIN, 10);
		pPlayer->ADD_GOSSIP_ITEM(4, "Picaro Dps", GOSSIP_SENDER_MAIN, 11);
		pPlayer->ADD_GOSSIP_ITEM(4, "Cazador Dps", GOSSIP_SENDER_MAIN, 12);
		pPlayer->ADD_GOSSIP_ITEM(4, "Druida Heal", GOSSIP_SENDER_MAIN, 13);
		pPlayer->ADD_GOSSIP_ITEM(4, "Druida Dps", GOSSIP_SENDER_MAIN, 14);
		pPlayer->ADD_GOSSIP_ITEM(4, "Druida Spell", GOSSIP_SENDER_MAIN, 15);
		pPlayer->ADD_GOSSIP_ITEM(4, "Sacerdote Dps", GOSSIP_SENDER_MAIN, 16);
		pPlayer->ADD_GOSSIP_ITEM(4, "Sacerdote Heal", GOSSIP_SENDER_MAIN, 17);
		pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
		return true;
	}
	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 Action)
	{
		if (Action == 0)
		{
			pPlayer->AddItem(warr_dps_cabeza, 1);
			pPlayer->AddItem(warr_dps_manos, 1);
			pPlayer->AddItem(warr_dps_piernas, 1);
			pPlayer->AddItem(warr_dps_pecho, 1);
			pPlayer->AddItem(warr_dps_hombros, 1);
		}
		else if (Action == 1)
		{
			pPlayer->AddItem(warr_tank_cabeza, 1);
			pPlayer->AddItem(warr_tank_manos, 1);
			pPlayer->AddItem(warr_tank_piernas, 1);
			pPlayer->AddItem(warr_tank_pecho, 1);
			pPlayer->AddItem(warr_tank_hombros, 1);
		}
		else if (Action == 2)
		{
			pPlayer->AddItem(paladin_heal_cabeza, 1);
			pPlayer->AddItem(paladin_heal_manos, 1);
			pPlayer->AddItem(paladin_heal_piernas, 1);
			pPlayer->AddItem(paladin_heal_pecho, 1);
			pPlayer->AddItem(paladin_heal_hombros, 1);
		}
		else if (Action == 3)
		{
			pPlayer->AddItem(paladin_dps_cabeza, 1);
			pPlayer->AddItem(paladin_dps_manos, 1);
			pPlayer->AddItem(paladin_dps_piernas, 1);
			pPlayer->AddItem(paladin_dps_pecho, 1);
			pPlayer->AddItem(paladin_dps_hombros, 1);
		}
		else if (Action == 4)
		{
			pPlayer->AddItem(paladin_tank_cabeza, 1);
			pPlayer->AddItem(paladin_tank_manos, 1);
			pPlayer->AddItem(paladin_tank_piernas, 1);
			pPlayer->AddItem(paladin_tank_pecho, 1);
			pPlayer->AddItem(paladin_tank_hombros, 1);
		}
		else if (Action == 5)
		{
			pPlayer->AddItem(dk_dps_cabeza, 1);
			pPlayer->AddItem(dk_dps_manos, 1);
			pPlayer->AddItem(dk_dps_piernas, 1);
			pPlayer->AddItem(dk_dps_pecho, 1);
			pPlayer->AddItem(dk_dps_hombros, 1);
		}
		else if (Action == 6)
		{
			pPlayer->AddItem(chaman_heal_cabeza, 1);
			pPlayer->AddItem(chaman_heal_manos, 1);
			pPlayer->AddItem(chaman_heal_piernas, 1);
			pPlayer->AddItem(chaman_heal_pecho, 1);
			pPlayer->AddItem(chaman_heal_hombros, 1);
		}
		else if (Action == 7)
		{
			pPlayer->AddItem(chaman_dps_melee_cabeza, 1);
			pPlayer->AddItem(chaman_dps_melee_manos, 1);
			pPlayer->AddItem(chaman_dps_melee_piernas, 1);
			pPlayer->AddItem(chaman_dps_melee_pecho, 1);
			pPlayer->AddItem(chaman_dps_melee_hombros, 1);
		}
		else if (Action == 8)
		{
			pPlayer->AddItem(chaman_dps_spell_cabeza, 1);
			pPlayer->AddItem(chaman_dps_spell_manos, 1);
			pPlayer->AddItem(chaman_dps_spell_piernas, 1);
			pPlayer->AddItem(chaman_dps_spell_pecho, 1);
			pPlayer->AddItem(chaman_dps_spell_hombros, 1);
		}
		else if (Action == 9)
		{
			pPlayer->AddItem(brujo_dps_cabeza, 1);
			pPlayer->AddItem(brujo_dps_manos, 1);
			pPlayer->AddItem(brujo_dps_piernas, 1);
			pPlayer->AddItem(brujo_dps_pecho, 1);
			pPlayer->AddItem(brujo_dps_hombros, 1);
		}
		else if (Action == 10)
		{
			pPlayer->AddItem(mago_dps_cabeza, 1);
			pPlayer->AddItem(mago_dps_manos, 1);
			pPlayer->AddItem(mago_dps_piernas, 1);
			pPlayer->AddItem(mago_dps_pecho, 1);
			pPlayer->AddItem(mago_dps_hombros, 1);
		}
		else if (Action == 11)
		{
			pPlayer->AddItem(picaro_dps_cabeza, 1);
			pPlayer->AddItem(picaro_dps_manos, 1);
			pPlayer->AddItem(picaro_dps_piernas, 1);
			pPlayer->AddItem(picaro_dps_pecho, 1);
			pPlayer->AddItem(picaro_dps_hombros, 1);
		}
		else if (Action == 12)
		{
			pPlayer->AddItem(cazador_dps_cabeza, 1);
			pPlayer->AddItem(cazador_dps_manos, 1);
			pPlayer->AddItem(cazador_dps_piernas, 1);
			pPlayer->AddItem(cazador_dps_pecho, 1);
			pPlayer->AddItem(cazador_dps_hombros, 1);
		}
		else if (Action == 13)
		{
			pPlayer->AddItem(druida_heal_cabeza, 1);
			pPlayer->AddItem(druida_heal_manos, 1);
			pPlayer->AddItem(druida_heal_piernas, 1);
			pPlayer->AddItem(druida_heal_pecho, 1);
			pPlayer->AddItem(druida_heal_hombros, 1);
		}
		else if (Action == 14)
		{
			pPlayer->AddItem(druida_dps_cabeza, 1);
			pPlayer->AddItem(druida_dps_manos, 1);
			pPlayer->AddItem(druida_dps_piernas, 1);
			pPlayer->AddItem(druida_dps_pecho, 1);
			pPlayer->AddItem(druida_dps_hombros, 1);
		}
		else if (Action == 15)
		{
			pPlayer->AddItem(druida_dps_spell_cabeza, 1);
			pPlayer->AddItem(druida_dps_spell_manos, 1);
			pPlayer->AddItem(druida_dps_spell_piernas, 1);
			pPlayer->AddItem(druida_dps_spell_pecho, 1);
			pPlayer->AddItem(druida_dps_spell_hombros, 1);
		}

		else if (Action == 16)
		{
			pPlayer->AddItem(sacerdote_dps_cabeza, 1);
			pPlayer->AddItem(sacerdote_dps_manos, 1);
			pPlayer->AddItem(sacerdote_dps_piernas, 1);
			pPlayer->AddItem(sacerdote_dps_pecho, 1);
			pPlayer->AddItem(sacerdote_dps_hombros, 1);
		}
		else if (Action == 17)
		{
			pPlayer->AddItem(sacerdote_heal_cabeza, 1);
			pPlayer->AddItem(sacerdote_heal_manos, 1);
			pPlayer->AddItem(sacerdote_heal_piernas, 1);
			pPlayer->AddItem(sacerdote_heal_pecho, 1);
			pPlayer->AddItem(sacerdote_heal_hombros, 1);
		}
		return true;
	}
};
void AddSC_npc_pve_km()
{
	new npc_pve_km();
}