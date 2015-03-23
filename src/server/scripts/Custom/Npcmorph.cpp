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
 
class Morph_npc : public CreatureScript
{
public:
    Morph_npc() : CreatureScript("Morph_npc") { }
 
 
    bool OnGossipHello(Player* player, Creature* creature)
    {
                if (player->isInCombat())
                {
                                        player->GetSession()->SendNotification("Estas en Combate!");
                                        player->CLOSE_GOSSIP_MENU();
                                        return false;
                }
 
                player->ADD_GOSSIP_ITEM(6, "Broken", GOSSIP_SENDER_MAIN, 1);
                                player->ADD_GOSSIP_ITEM(6, "Fel Orc", GOSSIP_SENDER_MAIN, 2);
                                player->ADD_GOSSIP_ITEM(6, "Goblin", GOSSIP_SENDER_MAIN, 3);
                                player->ADD_GOSSIP_ITEM(6, "Pandaren", GOSSIP_SENDER_MAIN, 4);
                                player->ADD_GOSSIP_ITEM(6, "Worgen", GOSSIP_SENDER_MAIN, 5);
								player->ADD_GOSSIP_ITEM(6, "Worgen 1", GOSSIP_SENDER_MAIN, 6);
								player->ADD_GOSSIP_ITEM(6, "Velen The Prophet", GOSSIP_SENDER_MAIN, 7);
								player->ADD_GOSSIP_ITEM(6, "Illidan", GOSSIP_SENDER_MAIN, 8);
								player->ADD_GOSSIP_ITEM(6, "Exanime", GOSSIP_SENDER_MAIN, 9);
								player->ADD_GOSSIP_ITEM(6, "Felguar", GOSSIP_SENDER_MAIN, 10);
								player->ADD_GOSSIP_ITEM(6, "Elemental de Sangre", GOSSIP_SENDER_MAIN, 11);
								player->ADD_GOSSIP_ITEM(6, "Tigerman", GOSSIP_SENDER_MAIN, 12);
								player->ADD_GOSSIP_ITEM(6, "Babosa de Cloaca", GOSSIP_SENDER_MAIN, 13);
								player->ADD_GOSSIP_ITEM(6, "Sucubo", GOSSIP_SENDER_MAIN, 14);
								player->ADD_GOSSIP_ITEM(6, "Necrofago", GOSSIP_SENDER_MAIN, 15);
								player->ADD_GOSSIP_ITEM(6, "Fantasma", GOSSIP_SENDER_MAIN, 16);
								player->ADD_GOSSIP_ITEM(6, "Fantasma 1", GOSSIP_SENDER_MAIN, 17);
                                player->ADD_GOSSIP_ITEM(6, "Eliminar Transformacion", GOSSIP_SENDER_MAIN, 18);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                return true;
        }
       
        bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 action)
        {
 
                switch (action)
        {
            case 1:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(21105);
                break;
            case 2:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(21267);
                break;
            case 3:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(20582);
                break;
            case 4:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(30414);
                break;
            case 5:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(26788);
                break;
			case 6:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(657);
                break;
			case 7:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(17822);
                break;
			case 8:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(21137);
                break;
			case 9:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(24191);
                break;
			case 10:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(5048);
                break;
			case 11:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(20030);
                break;
			case 12:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(15214);
                break;
			case 13:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(12349);
                break;
			case 14:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(4162);
                break;
			case 15:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(414);
                break;
			case 16:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(16162);
                break;
			case 17:
                player->CLOSE_GOSSIP_MENU();
                player->SetDisplayId(16168);
                break;
            case 18:
                player->CLOSE_GOSSIP_MENU();
                player->DeMorph();
                break;
                }
                return true;
        }
};
 
void AddSC_Morph_npc()
{
        new Morph_npc();
}