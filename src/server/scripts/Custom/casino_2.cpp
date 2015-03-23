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
class casino_km : public CreatureScript
{
public:
    casino_km() : CreatureScript("casino_km") { }
 
    bool OnGossipHello(Player * player, Creature * creature)
    {
 
        player->ADD_GOSSIP_ITEM_EXTENDED(3, "Quieres jugar con el juego de los dados", GOSSIP_SENDER_MAIN, 1337, "¿Cuánto oro va a apostar?", 0, true);
        player->ADD_GOSSIP_ITEM(3, "¿Cómo funciona este juego?", GOSSIP_SENDER_MAIN, 1);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }
 
    bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 uiAction) 
    {
        player->PlayerTalkClass->ClearMenus();
 
        if(uiAction == 1)
        {
            player->ADD_GOSSIP_ITEM(7, "Las reglas son simples, Si sacas superior a 50, su apuesta se duplica. De lo contrario, se pierde la cantidad apostada.", GOSSIP_SENDER_MAIN, 1);
            player->SEND_GOSSIP_MENU(123432, creature->GetGUID());
        }
        else if(uiAction == 0)
        {   
            OnGossipHello(player, creature);
        }
        return true;
    }
 
    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 uiAction, const char* code) // happens when an extended gossip item is selected and the code is set to true for the gossip item.
    {
        player->PlayerTalkClass->ClearMenus();
 
        uint32 amount = 0;
    uint32 gold = 0;
        amount = uint32(atol(code)); 
		gold = amount * 10000;
 
		std::ostringstream message;
 
        if(amount < 50) 
        {
            player->GetSession()->SendNotification("Usted no tiene suficiente oro!");
        }
        else
        {
			
 
            if(urand(1,2) == 1) 
            {
				player->ModifyMoney(player->GetMoney() + gold);
				player->PlayDirectSound(3337);
                player->CastSpell(player, 47292);
				player->CastSpell(player, 44940);
				message << "¡Felicidades " << player->GetName() << " Has ganado!";
				player->MonsterWhisper(message.str().c_str(), player->GetGUID());
				
            }
            else
            {
				player->ModifyMoney(player->GetMoney() - gold);
				message << "Así que lo siento, " << player->GetName() << " que ha perdido.";
				player->MonsterWhisper(message.str().c_str(), player->GetGUID());
            }
        }
        OnGossipSelect(player, creature, sender, 0);
        return true;
    }
 
struct gambler_passivesAI : public ScriptedAI
{
                   gambler_passivesAI(Creature * c) : ScriptedAI(c){ }
 
                   uint32 uiAdATimer;
                   uint32 uiAdBTimer;
				   uint32 uiAdCTimer;
 
                   void Reset()
                   {
                           uiAdATimer = 1000;
                           uiAdBTimer = 23000;
						   uiAdCTimer = 11000;
                   }
 
 
                   void UpdateAI(const uint32 diff)
                   {
 
                           if(uiAdATimer <= diff)
                           {
                                  me->MonsterSay("¡Venga uno, vengan todos! Un paso al frente a Crown Casino! hagan sus apuestas, hagan sus apuestas!", LANG_UNIVERSAL, NULL);
                                  me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
								  me->CastSpell(me, 44940);
                                  uiAdATimer = 61000;
                           }
                           else
                                   uiAdATimer -= diff;
 
                           if(uiAdBTimer <= diff)
                           {
                                   me->MonsterSay("Vamos chicos! Hagan sus apuestas, No seas un pollo!", LANG_UNIVERSAL, NULL);
                                   me->HandleEmoteCommand(EMOTE_ONESHOT_CHICKEN);
                                   uiAdBTimer = 61000;
                           }
                           else
                                   uiAdBTimer -= diff;
 
						   if(uiAdCTimer <= diff)
                           {
                                   me->MonsterSay("No me hagas triste, Ven a apostar! Un paso al frente y a ganar hoy!", LANG_UNIVERSAL, NULL);
                                   me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
                                   uiAdCTimer = 61000;
                           }
                           else
                                   uiAdCTimer -= diff;
                   }
};
 
			CreatureAI * GetAI(Creature * pCreature) const
           {
                   return new gambler_passivesAI(pCreature);
           }
};
 
void AddSC_casino_km()
{
    new casino_km();
}