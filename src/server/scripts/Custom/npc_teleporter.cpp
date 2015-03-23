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
#include "Chat.h"

const int PLAYER_QUEUE = 4;
static const Position playerSpawnPoint[PLAYER_QUEUE] = 
{
	{-7473.95f, -1088.11f, 896.78f, 4.38455f},
    {-6379.22f, 1256.77f, 7.18803f, 2.9329f},
    {-775.036f, 1511.92f, 137.398f, 4.71829f},
    {-6414.02f, -3507.6f, 402.778f, 2.03819f},
};

class global_teleporter : public CreatureScript
{
public:
    global_teleporter() : CreatureScript("global_teleporter") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->isInCombat())
        {
            pPlayer->GetSession()->SendNotification("ESTAS EN COMBATE!");
            return false;
        }
		pPlayer->ADD_GOSSIP_ITEM(1, "|cff00ff00|TInterface\\icons\\Achievement_Boss_Mimiron_01:24|t|r MERCADO", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(1, "|cff00ff00|TInterface\\icons\\Spell_Arcane_PortalDalaran:24|t|r Dalaran", GOSSIP_SENDER_MAIN, 3);
		pPlayer->ADD_GOSSIP_ITEM(1, "|cff00ff00|TInterface\\icons\\Achievement_Arena_2v2_4:24|t|r Gurubashi Arena", GOSSIP_SENDER_MAIN, 2);
		pPlayer->SEND_GOSSIP_MENU(80001, pCreature->GetGUID());        
        return true;
    }

	bool OnGossipSelect(Player* pPlayer, Creature* pCreature,uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        switch (uiAction)
        {
		  case 1: // Mercado Global
              {
                  pCreature->CastSpell(pPlayer,35517,false);
                  pPlayer->TeleportTo(37, 49.945271f, -412.212799f, 410.581818f, 1.106602f);
				  ChatHandler(pPlayer->GetSession()).PSendSysMessage("|cffff6060[SkyLegions]:|r Estas Siendo telestransportado hacia: |cFFFF4500Global Mercado|r!", pPlayer->GetName());
			 }break;
		
			  case 2: // Gurubashi Arena
              {
                  pCreature->CastSpell(pPlayer,35517,false);
                  pPlayer->TeleportTo(0, -13226.437500f, 232.104935f, 33.287682f, 1.133178f); 
                  ChatHandler(pPlayer->GetSession()).PSendSysMessage("|cffff6060[SkyLegions]:|r Estas Siendo telestransportado hacia: |cFFFF4500Gurubashi Arena - (ZONA PVP)|r!", pPlayer->GetName());
			  }break;
		
		       case 3: // Dalaran
			  {
				  pCreature->CastSpell(pPlayer,35517,false);
                  pPlayer->TeleportTo(571, 5804.149902f, 624.770996f, 647.767029f, 1.640000f);
                  ChatHandler(pPlayer->GetSession()).PSendSysMessage("|cffff6060[SkyLegions]:|r Estas Siendo telestransportado hacia: |cFFFF4500Dalaran - (SANTUARIO)|r!", pPlayer->GetName());
			  }break;      	    
			  {
                  OnGossipHello(pPlayer, pCreature);
                return true;
              }break;
		}
		pPlayer->CLOSE_GOSSIP_MENU();
        return true;
	}

};

void AddSC_global_teleporter()
{
    new global_teleporter();
}
