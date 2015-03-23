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
     
    class clear_combat : public CreatureScript
    {
     public:
      clear_combat() : CreatureScript("clear_combat")
      {
      }
     
      bool OnGossipHello(Player * pPlayer, Creature * pCreature)
      {
pPlayer->ADD_GOSSIP_ITEM(4, "Limpiar mi combate", GOSSIP_SENDER_MAIN, 0);
pPlayer->ADD_GOSSIP_ITEM(0, "No Importa...", GOSSIP_SENDER_MAIN, 3);
pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
return true;
      }
     
      bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
      {
if(!Player)
 return true;
      
switch(uiAction)
{
	case 0: if(!Player->duel) // Comprueba si un jugador está en un duelo o no.// Checks if a player is in a duel or not.
  {
 Player->ClearInCombat();
				   ChatHandler(Player->GetSession()).SendSysMessage("Tu combate esta limpio!");
  }
			else
			{
				ChatHandler(Player->GetSession()).SendSysMessage("Estás en un duelo! Usted no puede usar esto!!");
     Player->PlayerTalkClass->SendCloseGossip();
			};
}
return true;
      }
     
};
     
void AddSC_clear_combat()
{
     new clear_combat();
}