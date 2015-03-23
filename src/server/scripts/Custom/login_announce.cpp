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

class login_announce : public PlayerScript
{
   public:
	   login_announce() : PlayerScript("login_announce") 
	   {
	   }
	    void OnLogin(Player *player) 
	   {
	       if( !player || !player->GetSession() )
		       return;

		   char msg[41] = { NULL };
		   switch(player->GetSession()->GetSecurity())
		   {
		       case SEC_PLAYER:
				   snprintf(msg, 40, "[|cffff6060Player]: %s ha conectado!", player->GetName());
				   break;

			   }
		   sWorld->SendGlobalText(msg, NULL);
	   }



};

void AddSC_login_announce()
{
	new login_announce;
}