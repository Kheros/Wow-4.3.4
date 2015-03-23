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
     
    enum SkillSpells
    {
            SPELL_SWORDS = 201,
			SPELL_AXES = 196,
			SPELL_BOWS = 264,
			SPELL_GUNS = 266,
			SPELL_MACES = 198,
			SPELL_DEFENSE = 204,
			SPELL_STAVES = 227,
			SPELL_TWO_HANDED_SWORDS = 202,
			SPELL_TWO_HANDED_MACES = 199,
			SPELL_TWO_HANDED_AXES = 197,
			SPELL_UNARMED = 203,
			SPELL_DAGGERS = 1180,
			SPELL_THROWN = 2567,
			SPELL_CROSSBOW = 5011,
			SPELL_WANDS = 5009,
			SPELL_POLEARMS = 200,
			SPELL_FIST_WEAPON = 15590,
			SPELL_LOCKPICKING = 6460,
			
    };
     
    class skills_on_login : public PlayerScript
    {
        public:
                    skills_on_login() : PlayerScript("skills_on_login") { }
     
                    void OnLogin(Player * player)
                    {
                            if(player->HasAtLoginFlag(AT_LOGIN_FIRST))
                            {
                                    switch(player->getClass())
                                    {
                                       case CLASS_PALADIN:
                                               {
                                                       player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);


                                               }break;
     
                                       case CLASS_SHAMAN:
                                               {
												       player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);
                                                       
                                               }break;
     
                                       case CLASS_WARRIOR:
                                               {
												   	   player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);
                                                     
                                               }break;
     
                                       case CLASS_HUNTER:
                                               {
                                                   	   player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);    
                                               }break;
     
                                       case CLASS_ROGUE:
                                               {
												   	   player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);
													   player->learnSpell(SPELL_LOCKPICKING, true);
                                                   
                                               }break;
     
                                       case CLASS_DRUID:
                                               {
												       player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);
                                                      
                                               }break;
     
                                       case CLASS_MAGE:
                                               {
												       player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);
                                                       
                                               }break;
     
                                       case CLASS_WARLOCK:
                                               {
												       player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);
                                                      
                                               }break;
     
                                       case CLASS_PRIEST:
                                               {
												       player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);
                                                       
                                               }break;
     
                                       case CLASS_DEATH_KNIGHT:
                                               {
												       player->learnSpell(SPELL_SWORDS, true);
                                                       player->learnSpell(SPELL_AXES, true);
                                                       player->learnSpell(SPELL_BOWS, true);
                                                       player->learnSpell(SPELL_GUNS, true);
                                                       player->learnSpell(SPELL_MACES, true);
                                                       player->learnSpell(SPELL_DEFENSE, true);
                                                       player->learnSpell(SPELL_STAVES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_SWORDS, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_MACES, true);
                                                       player->learnSpell(SPELL_TWO_HANDED_AXES, true);
													   player->learnSpell(SPELL_UNARMED, true);
													   player->learnSpell(SPELL_DAGGERS, true);
													   player->learnSpell(SPELL_THROWN, true);
													   player->learnSpell(SPELL_CROSSBOW, true);
													   player->learnSpell(SPELL_WANDS, true);
													   player->learnSpell(SPELL_POLEARMS, true);
													   player->learnSpell(SPELL_FIST_WEAPON, true);
                                                    
                                               }break;
                                    }
                                player->MonsterWhisper("You now have All Weaponskills and maxed!", player->GetGUID());
                                player->UpdateSkillsToMaxSkillsForLevel();
                            }
                    }
    };
     
    void AddSC_skills_on_first_login()
    {
            new skills_on_login;
    }