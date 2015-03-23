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

class travel_to_the_deck_of_the_skyfire_km : public CreatureScript
{
public:
    travel_to_the_deck_of_the_skyfire_km() : CreatureScript("travel_to_the_deck_of_the_skyfire_km") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->isInCombat())
        {
            pPlayer->GetSession()->SendNotification("¡ESTAS EN COMBATE!");
            return false;
        }
		pPlayer->ADD_GOSSIP_ITEM(1, "Warmaster Blackhorn", GOSSIP_SENDER_MAIN, 1);
		pPlayer->SEND_GOSSIP_MENU(80001, pCreature->GetGUID());        
        return true;
    }

	bool OnGossipSelect(Player* pPlayer, Creature* pCreature,uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        switch (uiAction)
        {
		  case 1:
              {
                  pCreature->CastSpell(pPlayer,35517,false);
                  pPlayer->TeleportTo(967, 13397.298f, -12131.405f, 153.8732f, 3.152f);
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

void AddSC_travel_to_the_deck_of_the_skyfire_km()
{
    new travel_to_the_deck_of_the_skyfire_km();
}
