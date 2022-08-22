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
		
		for (NPC npc : NPCManager::get_instance().get_npcs()) {
			if (ImGui::TreeNode(npc.name))
			{
				// name
				char name_value[npc.MAX_NAME_LENGTH + 6] = "Name: ";
				strcat_s(name_value, npc.MAX_NAME_LENGTH + 6, npc.name);
				ImGui::Text(name_value);
				static char buf1[64] = ""; ImGui::InputText("default", buf1, 64);
				// emotion
				ImGui::Text(("Emotion: " + emotion_to_string(npc.emotion)).c_str());

				// close tree
				ImGui::TreePop();
			}
		}

		ImGui::End();
	}

}
