#pragma once

#include "../include/Inspector.h"
#include "../../NPC/include/NPC.h"
#include "../../NPC/include/NPCManager.h"
#include <iostream>
#include <string.h>


namespace NPCManager
{
	/* =======================================================================  /
	/  =======	   Constructor/Destructors		==============================  /
	/  ======================================================================= */


	UI::Inspector::Inspector() {

	}


	UI::Inspector::~Inspector() {

	}



	/* =======================================================================  /
	/  =======	   Public Methods				==============================  /
	/  ======================================================================= */


	void UI::Inspector::render() {
		ImGui::Begin("Inspector");

		std::vector<NPC> npcs = NPCManager::get_instance().get_npcs();
		
		for (NPC npc : NPCManager::get_instance().get_npcs()) {		
			if (ImGui::TreeNode(npc.get_imgui_label().c_str()))
			{
				// name
				ImGui::Text("Name: "); ImGui::SameLine();
				ImGui::InputText(".", npc.name, NPC::MAX_NAME_LENGTH);
		
				// emotion
				ImGui::Text(("Emotion: " + emotion_to_string(npc.emotion)).c_str());
		
				// update npc name
				NPCManager::get_instance().update_npc(npc);
		
				// close tree
				ImGui::TreePop();
				ImGui::Separator();
			}
		}

		ImGui::End();
	}

}
