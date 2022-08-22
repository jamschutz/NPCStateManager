#pragma once

#include "../include/NPCManager.h"

#include <string>
#include <vector>

namespace NPCManager
{
	/* =======================================================================  /
	/  =======	   Constructor/Destructors		==============================  /
	/  ======================================================================= */


	NPCManager::NPCManager::NPCManager() {
		NPC joey("Joey");
		NPC hao("Hao");

		npcs.push_back(joey);
		npcs.push_back(hao);
	}



	/* =======================================================================  /
	/  =======	   Public Methods				==============================  /
	/  ======================================================================= */


	void NPCManager::load_from_file(std::string filepath) {
		// do nothing for now...
	}


	std::vector<NPC> NPCManager::get_npcs() {
		return npcs;
	}


	void NPCManager::register_npc(NPC npc) {
		npcs.push_back(npc);
	}


	void NPCManager::delete_npc(NPC npc) {
		// do nothing for now...
	}
}

