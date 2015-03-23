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
#include "Channel.h"
#include "Language.h"
#include <string>
 
class System_Censure : public PlayerScript
{
public:
        System_Censure() : PlayerScript("System_Censure") {}
 
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg)
        {
                CheckMessage(player, msg, lang, NULL, NULL, NULL, NULL);
        }
 
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver)
        {
                CheckMessage(player, msg, lang, receiver, NULL, NULL, NULL);
        }
 
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Group* group)
        {
                CheckMessage(player, msg, lang, NULL, group, NULL, NULL);
        }
 
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Guild* guild)
        {
                CheckMessage(player, msg, lang, NULL, NULL, guild, NULL);
        }
 
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* channel)
        {
                CheckMessage(player, msg, lang, NULL, NULL, NULL, channel);
        }
 
void CheckMessage(Player* player, std::string& msg, uint32 lang, Player* /*receiver*/, Group* /*group*/, Guild* /*guild*/, Channel* channel)
{
    if (player->isGameMaster() || lang == LANG_ADDON)
            return;
 
    //transform to lowercase (for simpler checking)
    std::string lower = msg;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
 
        const uint8 cheksSize = 74;
        std::string checks[cheksSize];
        checks[0] ="http://";
        checks[1] =".com";
        checks[2] =".net";
        checks[3] =".org";
        checks[4] =".ru";
        checks[5] ="rondor";
        checks[6] ="www.";
            checks[7] ="terragolfa";
            checks[8] ="server de mierda";
            checks[9] ="nuevo servidor";
            checks[10] ="wowmagic";
            checks[11] ="circle";
            checks[12] ="www.wowtiberian.com";
            checks[13] ="wow-core";
            checks[14] ="wowcool";
            checks[15] ="wowysera";
            checks[16] ="wowlatinoamerica";
            checks[17] ="wowlatinos";
            checks[18] ="wowtiberian";
            checks[19] ="wowsulvus";
            checks[20] ="s u l v u s";
            checks[21] ="l a t i n o s";
            checks[22] ="3.3.5a";
            checks[23] ="eternallife.es";
            checks[24] ="reinosiberos";
            checks[25] ="lost";
            checks[26] ="fumetas";
            checks[27] ="otro server";
            checks[28] ="otro servidor";
            checks[29] ="sulvus";
            checks[30] ="latinos";
            checks[31] ="templars";
            checks[32] ="core";
            checks[33] ="tiberian";
            checks[34] ="mewet";
			checks[35] ="kbotcostarica";
			checks[36] ="wowpilas";
			checks[37] ="wowcolombia";
			checks[38] ="wow-colombia";
			checks[39] = "area 51";
			checks[40] = "arena-51";
			checks[41] = "vgaming";
			checks[42] = "sytes.net";
			checks[43] = "ddns.net";
			checks[44] = "zaptop.org";
			checks[45] = "wowmortal";
		    checks[46] = "wow-mortal";
			checks[47] = "adverse wow";
			checks[48] = "adverse";
            checks[49] = "wowadverse";
		    checks[50] = "wow ";
		    checks[51] = "lanrun";
		    checks[52] = "lan-run";
			checks[53] = "wow-lanrun";
			checks[54] = "lan-run";
			checks[55] = "lanrun";
			checks[56] = "skyfire";
			checks[57] = "logon.lanrunteam.com:3725";
			checks[58] = "http://lich.lanrunteam.com/";
			checks[59] = "set realmlist logon.lanrunteam.com";
			checks[60] = "logon.lanrunteam.com";
			checks[61] = "http://cata.lanrunteam.com/";
			checks[62] = "http://lanrunteam.com/";
			checks[63] = "lanrunteam.com";
			checks[64] = "http://wow-legends.tk/";
			checks[65] = "wow-legends.tk";
			checks[66] = "set realmlist logon.wow-legends.tk";
			checks[67] = "wow-legends";
			checks[68] = "http://wow-platinum.sytes.net/";
			checks[69] = "wow-platinum.sytes.net";
			checks[70] = "set realmlist wowplatinum.com";
			checks[71] = "wowplatinum.com";
			checks[72] = "http://wowplatinum.com/";
			checks[73] = "wow-platinum";


        for (int i = 0; i < cheksSize; ++i)
            if (lower.find(checks[i]) != std::string::npos)
            {
                msg = "No se tolera el Spam!";
			    msg = lang == LANG_GM_SILENCE;
				ChatHandler(player->GetSession()).PSendSysMessage("No se tolera el Spam!");
				std::string plr = player->GetName();
            std::string gender = player->getGender() == GENDER_FEMALE ? "esta" : "esta";
            bool ingroup = player->GetGroup();
            std::string tag_colour = "7bbef7";
            std::string plr_colour = "ff0000";
            std::string boss_colour = "18be00";
            std::ostringstream stream;
            stream << "|CFF" << tag_colour << 
                      "[Anuncio de Spam]|r:|cff" << plr_colour << " " << plr << 
                      (ingroup ? " el " : " haciendo ") << gender << (ingroup ? " Spameando " : " Spameando ") << "!";
			sWorld->SendGMText(LANG_GM_BROADCAST, stream.str().c_str());
                return;
            }
    
	}  
    };

void AddSC_System_Censure()
{
    new System_Censure();
}
