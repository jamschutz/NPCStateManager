#pragma once

#include "../include/NPCManager.h"
#include "../../Utils/include/FileManager.h"

#include <string>
#include <vector>
#include <iostream>

namespace NPCManager
{
	/* =======================================================================  /
	/  =======	   Constructor/Destructors		==============================  /
	/  ======================================================================= */


	NPCManager::NPCManager::NPCManager() {
		
	}



	/* =======================================================================  /
	/  =======	   Public Methods				==============================  /
	/  ======================================================================= */


	void NPCManager::load_from_file(std::string filepath) {
		npcs = Utils::FileManager::get_npcs_from_file(filepath);
	}


	std::vector<NPC> NPCManager::get_npcs() {
		return npcs;
	}


	void NPCManager::register_npc(NPC npc) {
		npcs.push_back(npc);
	}


	void NPCManager::delete_npc(NPC npc) {
		int npc_index = get_npc_index(npc);

		// npc not found
		if (npc_index < 0) {
			std::cout << "\n*****ERROR: NPC with id " << npc.get_id() << " was not found.";
		}
		// otherwise, delete npc
		else {
			npcs.erase(npcs.begin() + npc_index);		
		}
	}


	void NPCManager::update_npc(NPC npc) {
		int npc_index = get_npc_index(npc);

		// npc not found
		if (npc_index < 0) {
			std::cout << "\n*****ERROR: NPC with id " << npc.get_id() << " was not found.";
		}
		// otherwise, i[date npc
		else {
			npcs[npc_index] = npc;
		}
	}



	/* =======================================================================  /
	/  =======	   Private Methods				==============================  /
	/  ======================================================================= */

	int NPCManager::get_npc_index(NPC npc) {
		// find matching npc...
		for (int i = 0; i < npcs.size(); i++) {
			if (npcs[i].get_id() == npc.get_id()) {
				return i;
			}
		}

		return -1;
	}
}

