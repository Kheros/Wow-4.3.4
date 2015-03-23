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
#include "Language.h"

class Professions_NPC : public CreatureScript
{
public:
	Professions_NPC() : CreatureScript("Professions_NPC") {}

	void CreatureWhisperBasedOnBool(const char *text, Creature *_creature, Player *pPlayer, bool value)
	{
		if (value)
			_creature->MonsterWhisper(text, pPlayer->GetGUID());
	}

	uint32 PlayerMaxLevel() const
	{
		return sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
	}

	bool PlayerHasItemOrSpell(const Player *plr, uint32 itemId, uint32 spellId) const
	{
		return plr->HasItemCount(itemId, 1, true) || plr->HasSpell(spellId);
	}

	bool OnGossipHello(Player *pPlayer, Creature* _creature)
	{
		pPlayer->ADD_GOSSIP_ITEM(9, "[Profesiones] ->", GOSSIP_SENDER_MAIN, 196);
		pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
		return true;
	}

	bool PlayerAlreadyHasTwoProfessions(const Player *pPlayer) const
	{
		uint32 skillCount = 0;

		if (pPlayer->HasSkill(SKILL_MINING))
			skillCount++;
		if (pPlayer->HasSkill(SKILL_SKINNING))
			skillCount++;
		if (pPlayer->HasSkill(SKILL_HERBALISM))
			skillCount++;

		if (skillCount >= 2)
			return true;

		for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
		{
			SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(i);
			if (!SkillInfo)
				continue;

			if (SkillInfo->categoryId == SKILL_CATEGORY_SECONDARY)
				continue;

			if ((SkillInfo->categoryId != SKILL_CATEGORY_PROFESSION) || !SkillInfo->canLink)
				continue;

			const uint32 skillID = SkillInfo->id;
			if (pPlayer->HasSkill(skillID))
				skillCount++;

			if (skillCount >= 2)
				return true;
		}
		return false;
	}

	bool LearnAllRecipesInProfession(Player *pPlayer, SkillType skill)
	{
		ChatHandler handler(pPlayer->GetSession());
		char* skill_name;

		SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill);

		if (!SkillInfo)
		{
			sLog->outError(LOG_FILTER_PLAYER_SKILLS, "Profesion Master: ERROR POR FAVOR REPORTALO");
			return false;
		}

		LearnSkillRecipesHelper(pPlayer, SkillInfo->id);

		pPlayer->SetSkill(SkillInfo->id, pPlayer->GetSkillStep(SkillInfo->id), 550, 550);
		handler.PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, skill_name);

		return true;
	}

	void LearnSkillRecipesHelper(Player *player, uint32 skill_id)
	{
		uint32 classmask = player->getClassMask();

		for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
		{
			SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j);
			if (!skillLine)
				continue;

			// wrong skill
			if (skillLine->skillId != skill_id)
				continue;

			// not high rank
			if (skillLine->forward_spellid)
				continue;

			// skip racial skills
			if (skillLine->racemask != 0)
				continue;

			// skip wrong class skills
			if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
				continue;

			SpellInfo const * spellInfo = sSpellMgr->GetSpellInfo(skillLine->spellId);
			if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
				continue;

			player->learnSpell(skillLine->spellId, false);
		}
	}

	bool IsSecondarySkill(SkillType skill) const
	{
		return skill == SKILL_COOKING || skill == SKILL_FIRST_AID;
	}

	void CompleteLearnProfession(Player *pPlayer, Creature *pCreature, SkillType skill)
	{
		if (PlayerAlreadyHasTwoProfessions(pPlayer) && !IsSecondarySkill(skill))
			pCreature->MonsterWhisper("Ya tienes 2 Profesiones!", pPlayer->GetGUID());
		else
		{
			if (!LearnAllRecipesInProfession(pPlayer, skill))
				pCreature->MonsterWhisper("ERROR POR FAVOR REPORTALO", pPlayer->GetGUID());
		}
	}

	bool OnGossipSelect(Player* pPlayer, Creature* _creature, uint32 uiSender, uint32 uiAction)
	{
		pPlayer->PlayerTalkClass->ClearMenus();

		if (uiSender == GOSSIP_SENDER_MAIN)
		{

			switch (uiAction)
			{
			case 196:
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\trade_alchemy:30|t ALQUIMIA.", GOSSIP_SENDER_MAIN, 1);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\INV_Ingot_05:30|t HERRERIA.", GOSSIP_SENDER_MAIN, 2);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\INV_Misc_LeatherScrap_02:30|t PELETERIA.", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\INV_Fabric_Felcloth_Ebon:30|t SASTRERIA.", GOSSIP_SENDER_MAIN, 4);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\inv_misc_wrench_01:30|t INGENIERIA.", GOSSIP_SENDER_MAIN, 5);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\trade_engraving:30|t ENCANTAMIENTO.", GOSSIP_SENDER_MAIN, 6);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\inv_misc_gem_01:30|t JOYERIA.", GOSSIP_SENDER_MAIN, 7);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\INV_Scroll_08:30|t INSCRIPCION.", GOSSIP_SENDER_MAIN, 8);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\INV_Misc_Herb_07:30|t HERBOISTERIA.", GOSSIP_SENDER_MAIN, 11);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\inv_misc_pelt_wolf_01:30|t DESUELLO.", GOSSIP_SENDER_MAIN, 12);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\trade_mining:30|t MINERIA.", GOSSIP_SENDER_MAIN, 13);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\INV_Misc_Food_17:30|t COCINA", GOSSIP_SENDER_MAIN, 9);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\Achievement_BG_winSOA_underXminutes:30|t PRIMEROS AUXILIOS", GOSSIP_SENDER_MAIN, 10);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t Adios...", GOSSIP_SENDER_MAIN, 14);
				pPlayer->PlayerTalkClass->SendGossipMenu(80000, _creature->GetGUID());
				break;
			case 1:
				if (pPlayer->HasSkill(SKILL_ALCHEMY))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}


												{
													CompleteLearnProfession(pPlayer, _creature, SKILL_ALCHEMY);
													pPlayer->PlayerTalkClass->SendCloseGossip();
												}break;

			case 2:
				if (pPlayer->HasSkill(SKILL_BLACKSMITHING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_BLACKSMITHING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 3:
				if (pPlayer->HasSkill(SKILL_LEATHERWORKING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_LEATHERWORKING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 4:
				if (pPlayer->HasSkill(SKILL_TAILORING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_TAILORING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 5:
				if (pPlayer->HasSkill(SKILL_ENGINEERING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_ENGINEERING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;

			case 6:
				if (pPlayer->HasSkill(SKILL_ENCHANTING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_ENCHANTING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 7:
				if (pPlayer->HasSkill(SKILL_JEWELCRAFTING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_JEWELCRAFTING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 8:
				if (pPlayer->HasSkill(SKILL_INSCRIPTION))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_INSCRIPTION);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 9:
				if (pPlayer->HasSkill(SKILL_COOKING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_COOKING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 10:
				if (pPlayer->HasSkill(SKILL_FIRST_AID))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_FIRST_AID);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 11:
				if (pPlayer->HasSkill(SKILL_HERBALISM))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_HERBALISM);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 12:
				if (pPlayer->HasSkill(SKILL_SKINNING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_SKINNING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
			case 13:
				if (pPlayer->HasSkill(SKILL_MINING))
				{
					pPlayer->PlayerTalkClass->SendCloseGossip();
					break;
				}
				else
				{
					CompleteLearnProfession(pPlayer, _creature, SKILL_MINING);
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}break;
				case 14:
                     pPlayer->PlayerTalkClass->SendCloseGossip();
                     break;
			}


		}
		return true;
	}
};

void AddSC_Professions_NPC()
{
	new Professions_NPC();
}