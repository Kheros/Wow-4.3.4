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

/*Class E_Menu*/
#define E_Warrior "Ver top 5 Guerrero Muertes"
#define E_Paladin "Ver top 5 Paladin Muertes"
#define E_Hunter "Ver top 5 Cazador Muertes"
#define E_Rogue "Ver top 5 Picaro Muertes"
#define E_Priest "Ver top 5 Sacerdote Muertes"
#define E_Shaman "Ver top 5 Chaman Muertes"
#define E_Mage "Ver top 5 Mago Muertes"
#define E_Warlock "Ver top 5 Brujo Muertes"
#define E_Druid "Ver top 5 Druida Muertes"
#define E_Death_knight "Ver top 5 Dk Muertes"
/*Top 5 Message*/
#define M_Warrior "Este es el top 5 Guerrero Muertes"
#define M_Paladin "Este es el top 5 Paladin Muertes"
#define M_Hunter "Este es el top 5 Cazador Muertes"
#define M_Rogue "Este es el top 5 Picaro Muertes"
#define M_Priest "Este es el top 5 Sacerdote Muertes"
#define M_Shaman "Este es el top 5 Chaman Muertes"
#define M_Mage "Este es el top 5 Mago Muertes"
#define M_Warlock "Este es el top 5 Brujo Muertes"
#define M_Druid "Este es el top 5 Druida Muertes"
#define M_Death_knight "Este es el top 5 Dk Muertes"

class Top5_Killers : public CreatureScript
{
public:
    Top5_Killers() : CreatureScript("Top5_Killers") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(1, E_Warrior, GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(1, E_Paladin, GOSSIP_SENDER_MAIN, 2);
        player->ADD_GOSSIP_ITEM(1, E_Hunter, GOSSIP_SENDER_MAIN, 3);
        player->ADD_GOSSIP_ITEM(1, E_Rogue, GOSSIP_SENDER_MAIN, 4);
        player->ADD_GOSSIP_ITEM(1, E_Priest, GOSSIP_SENDER_MAIN, 5);
        player->ADD_GOSSIP_ITEM(1, E_Shaman, GOSSIP_SENDER_MAIN, 7);
        player->ADD_GOSSIP_ITEM(1, E_Mage, GOSSIP_SENDER_MAIN, 8);
        player->ADD_GOSSIP_ITEM(1, E_Warlock, GOSSIP_SENDER_MAIN, 9);
        player->ADD_GOSSIP_ITEM(1, E_Druid, GOSSIP_SENDER_MAIN, 11);
        player->ADD_GOSSIP_ITEM(1, E_Death_knight, GOSSIP_SENDER_MAIN, 6);
        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return true; // wrong sender, something fisy

        switch(action)
        {
        case 1: ChatHandler(player->GetSession()).PSendSysMessage(M_Warrior);       break;
        case 2: ChatHandler(player->GetSession()).PSendSysMessage(M_Paladin);       break;
        case 3: ChatHandler(player->GetSession()).PSendSysMessage(M_Hunter);        break;
        case 4: ChatHandler(player->GetSession()).PSendSysMessage(M_Rogue);         break;
        case 5: ChatHandler(player->GetSession()).PSendSysMessage(M_Priest);        break;
        case 6: ChatHandler(player->GetSession()).PSendSysMessage(M_Death_knight);  break;
        case 7: ChatHandler(player->GetSession()).PSendSysMessage(M_Shaman);        break;
        case 8: ChatHandler(player->GetSession()).PSendSysMessage(M_Mage);          break;
        case 9: ChatHandler(player->GetSession()).PSendSysMessage(M_Warlock);       break;
        case 11: ChatHandler(player->GetSession()).PSendSysMessage(M_Druid);        break;
        default: return true; // invalid class, something fishy
        }

        QueryResult result = CharacterDatabase.PQuery("SELECT name, totalKills FROM characters WHERE class = %u ORDER BY totalKills DESC LIMIT 5", action);
        if(result)
        {
            do
            {
                Field * fields = result->Fetch();
                std::string name = fields[0].GetString();
                uint32 totalKills = fields[1].GetUInt32();
                ChatHandler(player->GetSession()).PSendSysMessage("Nombre: %s, Total de muertes : %u", name.c_str(), totalKills);
            } 
            while(result->NextRow());
        }
        OnGossipHello(player, creature); // return to main menu
        return true;
    }
};


void AddSC_Top5_Killers()
{
    new Top5_Killers();
}