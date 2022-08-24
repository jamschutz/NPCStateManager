#pragma once

#include "../include/Grid.h"
#include "../../NPC/include/NPC.h"
#include "../../NPC/include/NPCManager.h"

#include <iostream>



/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


NPCManager::UI::Grid::Grid() {
	
}


NPCManager::UI::Grid::~Grid() {
	
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


void NPCManager::UI::Grid::render() {
	ImGui::Begin("Grid");

	for (NPC npc : NPCManager::get_instance().get_npcs()) {
		ImGui::Button(npc.get_imgui_label().c_str());
	}

	ImGui::End();
}
