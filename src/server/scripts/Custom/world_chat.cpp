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
 
#define FACTION_SPECIFIC 0
 
std::string GetNameLink(Player* player)
{
        std::string name = player->GetName();
        std::string color;
        switch(player->getClass())
        {
        case CLASS_DEATH_KNIGHT:
                color = "|cffC41F3B";
                break;
        case CLASS_DRUID:
                color = "|cffFF7D0A";
                break;
        case CLASS_HUNTER:
                color = "|cffABD473";
                break;
        case CLASS_MAGE:
                color = "|cff69CCF0";
                break;
        case CLASS_PALADIN:
                color = "|cffF58CBA";
                break;
        case CLASS_PRIEST:
                color = "|cffFFFFFF";
                break;
        case CLASS_ROGUE:
                color = "|cffFFF569";
                break;
        case CLASS_SHAMAN:
                color = "|cff0070DE";
                break;
        case CLASS_WARLOCK:
                color = "|cff9482C9";
                break;
        case CLASS_WARRIOR:
                color = "|cffC79C6E";
                break;
        }
        return "|Hplayer:"+name+"|h|cffFFFFFF["+color+name+"|cffFFFFFF]|h|r";
}
 
class cs_world_chat : public CommandScript
{
        public:
                cs_world_chat() : CommandScript("cs_world_chat"){}
 
        ChatCommand * GetCommands() const
        {
                static ChatCommand WorldChatCommandTable[] =
                {
                        {"chat",        SEC_PLAYER,             true,           &HandleWorldChatCommand,        "", NULL},
                        {NULL,          0,                      false,          NULL,                           "", NULL}
                };
 
                return WorldChatCommandTable;
        }
 
        static bool HandleWorldChatCommand(ChatHandler * handler, const char * args)
        {
                if (!handler->GetSession()->GetPlayer()->CanSpeak())
                        return false;
                std::string temp = args;
 
                if (!args || temp.find_first_not_of(' ') == std::string::npos)
                        return false;
 
                std::string msg = "";
                Player * player = handler->GetSession()->GetPlayer();
 
                switch(player->GetSession()->GetSecurity())
                {
                        // Player
                        case SEC_PLAYER:
                                if (player->GetTeam() == ALLIANCE)
                                {
                                        msg += "|cff0000ff[Alianza] ";
                                        msg += GetNameLink(player);
                                        msg += " |cfffaeb00";
                                }
 
                                else
                                {
                                        msg += "|cffff0000[Horda] ";
                                        msg += GetNameLink(player);
                                        msg += " |cfffaeb00";
                                }
                                break;
                        // VIP
                        case 1:
                                msg += "|cffC400C4[Gm-R1] ";
                                msg += GetNameLink(player);
                                msg += " |cfffaeb00";
                                break;
                        // Trial GM - 2
                        case 2:
                                msg += "|cff800000[Gm-R2] ";
                                msg += GetNameLink(player);
                                msg += " |cfffaeb00";
                                break;
                        // GM - 3
                        case 3:
                                msg += "|cff0000FF[GM-R3] ";
                                msg += GetNameLink(player);
                                msg += " |cfffaeb00";
                                break;
                        // GM-4
                        case 4:
                                msg += "|CFF800080[GM-R4] ";
                                msg += GetNameLink(player);
                                msg += " |cfffaeb00";
								break;
                         // Developer - 5
                        case 5:
                                msg += "|cff000000[Administrador] ";
                                msg += GetNameLink(player);
                                msg += " |cfffaeb00";
								break;
                        // Admin - 6
                        case 6:
                                msg += "|cffFF0000[ADMIN] ";
                                msg += GetNameLink(player);
                                msg += " |cfffaeb00";
								break;
                        // CONSOLA
                        case 7:
                                msg += "|cffFF0000[SERVIDOR] ";
                                msg += GetNameLink(player);
                                msg += " |cfffaeb00";
								break;

                }
                       
                msg += args;
                if (FACTION_SPECIFIC)
                {
                        SessionMap sessions = sWorld->GetAllSessions();
                        for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr)
                                if (Player* plr = itr->second->GetPlayer())
                                        if (plr->GetTeam() == player->GetTeam())
                                                sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), plr);
                }
                else
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), 0);  
 
                return true;
        }
};
 
void AddSC_cs_world_chat()
{
        new cs_world_chat();
}