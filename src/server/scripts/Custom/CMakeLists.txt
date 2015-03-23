# Copyright (C) 2015 DevKM <http://facebook.com/krizttianmoreno>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE scripts_Custom Custom/*.cpp Custom/*.h)
source_group(Custom FILES ${scripts_Custom})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Custom}
  Custom/chat_censure.cpp
  Custom/duel_reset.cpp
  Custom/npc_profesiones.cpp
  Custom/npc_teleporter.cpp
  Custom/world_chat.cpp
  Custom/npc_promo.cpp
  Custom/npc_incansable_km.cpp
  Custom/killstreak.cpp
  Custom/npc_pve_km.cpp
  Custom/Trainer.cpp
  Custom/VisualWeapon.cpp
  Custom/top_class_killers.cpp
  Custom/tokenconverter.cpp
  Custom/npc_top10_arena.cpp
  Custom/npc_enchant.cpp
  Custom/gurubashi_theme.cpp
  Custom/clear_combat_bug.cpp
  Custom/learn_all_spells.cpp
  Custom/learn_spells_on_login.cpp
  Custom/login_announce.cpp
  Custom/casino_1.cpp
  Custom/casino_2.cpp
  Custom/simple_pvp_title_system.cpp
  Custom/Npcmorph.cpp
  Custom/dragon_soul/npc_eiendormi_km.cpp
  Custom/dragon_soul/npc_nethestrasz_km.cpp
  Custom/dragon_soul/npc_valeera_km.cpp
  Custom/dragon_soul/travel_to_the_deck_of_the_skyfire_km.cpp
  Custom/dragon_soul/travel_to_the_eye_of_eternity_km.cpp
  Custom/dragon_soul/travel_to_wyrmrest_base_km.cpp
  Custom/1v1.cpp
)

message("  -> Prepared: Custom")
