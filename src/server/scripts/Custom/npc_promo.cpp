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

#define MSG_PLACE "Bienvenido a SkyLegions: Promocion Nivel 85 + 15k de Oro"

class npc_shop : public CreatureScript
{
public:
    npc_shop() : CreatureScript("npc_shop") { }
  
	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
{
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_PLACE, GOSSIP_SENDER_MAIN,1);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "No mejor no..", GOSSIP_SENDER_MAIN,2);
            pPlayer->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
            return true;
}
	
	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 Sender, uint32 Action)
        {
				if (Sender != GOSSIP_SENDER_MAIN)
					return false;
		
				pPlayer->PlayerTalkClass->ClearMenus();
								if (Action == 1)
									{
                        	   // QueryResult pResult = LoginDatabase.PQuery("select last_ip from account where id = %u", pPlayer->GetSession()->GetAccountId()); 																
								//Field * pFields = pResult->Fetch();
								//pFields[0].GetString();
								QueryResult Result = LoginDatabase.PQuery("select count(*) from account where last_ip = %u", pPlayer->GetSession()->GetRemoteAddress()); 	
								Field * rFields = Result->Fetch();
								int64 ip2 = rFields[0].GetInt64();
								if (ip2 > 1)
								{
										ChatHandler(pPlayer->GetSession()).PSendSysMessage("Para obtener la promoción debe ser tu primera cuenta, no puedes tener dos o mas cuentas");
										pPlayer->PlayerTalkClass->SendCloseGossip();
										return true;
								}
										QueryResult result = CharacterDatabase.PQuery("SELECT COUNT(*) FROM characters WHERE account = %u AND LEVEL = 85",pPlayer->GetSession()->GetAccountId());
										Field* field = result->Fetch();
										int8 chars = field[0].GetInt8();
									 if (chars > 0 && pPlayer->getLevel() != 85 )
										{
										ChatHandler(pPlayer->GetSession()).PSendSysMessage("Ya tienes un pj 85 en esta cuenta no abuses de la promocion.");
										pPlayer->PlayerTalkClass->SendCloseGossip();
										return true;
										}
										
									
										
								
								
								else if (pPlayer->getLevel() == 85)
									{
							 ChatHandler(pPlayer->GetSession()).PSendSysMessage("Ya eres Nivel 85");
                                   pPlayer->PlayerTalkClass->SendCloseGossip();
								   return true;
								   
								   }
								   }
								   //else if(Sender == GOSSIP_SENDER_MAIN)
								   
								
											switch(Action)
												{
														case 1:
                
														pPlayer->SetMoney(150000000);
														pPlayer->GiveLevel(85);
														pPlayer->UpdateSkillsToMaxSkillsForLevel();
				
														if(pPlayer->GetTeam() == ALLIANCE){ //ID DEL SPELL QUE LLEVE A SHOP ALIANZA
															pPlayer->TeleportTo(37, 49.945271f, -412.212799f, 410.581818f, 1.106602f);
														//pPlayer->CastSpell(pPlayer,61420,true,NULL,NULL,pPlayer->GetGUID());
																							}
														else { //ID DEL SPELL QUE LLEVE A SHOP HORDA
															pPlayer->TeleportTo(37, 49.945271f, -412.212799f, 410.581818f, 1.106602f);
														//pPlayer->CastSpell(pPlayer,34673,true,NULL,NULL,pPlayer->GetGUID());
																}
														pPlayer->PlayerTalkClass->SendCloseGossip();
														pPlayer->SaveToDB();
														break;
														case 2:
														pPlayer->PlayerTalkClass->SendCloseGossip();
														break;
												}
				
													
			return true;
		
		}
};
	
	
void AddSC_npc_shop()
{
    new npc_shop();
}