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
				ImGui::Text("Name: "); ImGui::SameLine(0, 29);
				ImGui::InputText("###name", npc.name, NPC::MAX_NAME_LENGTH);
		
				// emotion
				int selected_emotion = static_cast<int>(npc.emotion);
				ImGui::Text(("Emotion: ")); ImGui::SameLine();
				ImGui::Combo("###emotion", &selected_emotion, EMOTIONS_AVAILABLE, IM_ARRAYSIZE(EMOTIONS_AVAILABLE));
		
				// update npc name
				npc.emotion = static_cast<Emotion>(selected_emotion);
				NPCManager::get_instance().update_npc(npc);
		
				// close tree
				ImGui::TreePop();
				ImGui::Separator();
			}
		}

		static int clicked_add_npc = 0;
		if (ImGui::Button("+New NPC###AddNPC"))
			clicked_add_npc++;
		if (clicked_add_npc & 1)
		{
			NPC new_npc("New NPC");
			NPCManager::get_instance().register_npc(new_npc);

			clicked_add_npc = 0;
		}

		ImGui::End();
	}

}
