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
		std::string npc_to_delete;
		
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
				
				// delete npc button
				std::string delete_npc_id = "Delete###delete" + npc.get_id();
				std::string delete_npc_popup_id = "deletepopup" + npc.get_id();

				ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0, 0.6f, 0.6f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0, 0.7f, 0.7f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0, 0.8f, 0.8f));
				if (ImGui::Button(delete_npc_id.c_str()))
					ImGui::OpenPopup(delete_npc_popup_id.c_str());
				ImGui::PopStyleColor(3);

				// Always center this window when appearing
				ImVec2 center = ImGui::GetMainViewport()->GetCenter();
				ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

				if (ImGui::BeginPopupModal(delete_npc_popup_id.c_str(), NULL, ImGuiWindowFlags_AlwaysAutoResize))
				{
					std::string warning_text = "Delete ";
					warning_text += npc.name;
					warning_text += "? \nThis operation cannot be undone!\n\n";
					ImGui::Text(warning_text.c_str());
					ImGui::Separator();

					if (ImGui::Button("OK", ImVec2(120, 0))) { 
						NPCManager::get_instance().delete_npc(npc);
						ImGui::CloseCurrentPopup(); 
					}
					ImGui::SetItemDefaultFocus();
					ImGui::SameLine();
					if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
					ImGui::EndPopup();
				}

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
