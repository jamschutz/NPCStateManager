#pragma once

#include "../include/MenuBar.h"
#include <iostream>



/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


NPCManager::UI::MenuBar::MenuBar() {

}


NPCManager::UI::MenuBar::~MenuBar() {

}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


void NPCManager::UI::MenuBar::render(bool& opt_fullscreen, bool& opt_padding, ImGuiDockNodeFlags dockspace_flags) {
	// You can pass in a reference ImGuiStyle structure to compare to, revert to and save to
	// (without a reference style pointer, we will use one compared locally as a reference)
	ImGuiStyle& style = ImGui::GetStyle();
	static ImGuiStyle ref_saved_style;

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Options"))
		{
			ImGui::MenuItem("Padding", NULL, &opt_padding);
			ImGui::Separator();

			if (ImGui::ShowStyleSelector("UI Theme##Selector"))
				ref_saved_style = style;

			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}
}



/* =======================================================================  /
/  =======	   Private Methods				==============================  /
/  ======================================================================= */


// Demo helper function to select among default colors. See ShowStyleEditor() for more advanced options.
// Here we use the simplified Combo() api that packs items into a single literal string.
// Useful for quick combo boxes where the choices are known locally.
bool NPCManager::UI::MenuBar::show_style_selector(const char* label)
{
	static int style_idx = -1;
	if (ImGui::Combo(label, &style_idx, "Dark\0Light\0Classic\0"))
	{
		switch (style_idx)
		{
		case 0: ImGui::StyleColorsDark(); break;
		case 1: ImGui::StyleColorsLight(); break;
		case 2: ImGui::StyleColorsClassic(); break;
		}
		return true;
	}
	return false;
}
