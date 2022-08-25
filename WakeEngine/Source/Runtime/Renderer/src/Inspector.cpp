#pragma once

#include "../include/Inspector.h"
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

		// build inspector for each NPC
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
				
				// delete npc button
				show_delete_npc_button(npc);
				show_delete_npc_popup(npc);

				// close tree
				ImGui::TreePop();
				ImGui::Separator();
			}	
		}	
		// show add NPC button
		show_add_npc_button();

		ImGui::End();
	}


	void UI::Inspector::show_delete_npc_button(NPC npc) {
		// build unique ids
		std::string delete_npc_id = "Delete###delete" + npc.get_id();
		std::string delete_npc_popup_id = "deletepopup" + npc.get_id();

		// color button red
		ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0, 0.6f, 0.6f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0, 0.7f, 0.7f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0, 0.8f, 0.8f));

		// show button
		if (ImGui::Button(delete_npc_id.c_str()))
			ImGui::OpenPopup(delete_npc_popup_id.c_str());

		// reset button color settings
		ImGui::PopStyleColor(3);
	}


	void UI::Inspector::show_delete_npc_popup(NPC npc) {
		// build unique id
		std::string delete_npc_popup_id = "deletepopup" + npc.get_id();

		// set warning text
		std::string warning_text = "Delete ";
		warning_text += npc.name;
		warning_text += "? \nThis operation cannot be undone!\n\n";

		// Always center this window when appearing
		ImVec2 center = ImGui::GetMainViewport()->GetCenter();
		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

		// show popup window
		if (ImGui::BeginPopupModal(delete_npc_popup_id.c_str(), NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
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
	}


	void UI::Inspector::show_add_npc_button() {
		if (ImGui::Button("+New NPC###AddNPC")) {
			NPC new_npc("New NPC");
			NPCManager::get_instance().register_npc(new_npc);
		}
	}

}
