#pragma once

#include "../include/Inspector.h"
#include <iostream>



/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


NPCManager::UI::Inspector::Inspector() {

}


NPCManager::UI::Inspector::~Inspector() {

}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


void NPCManager::UI::Inspector::render() {
	ImGui::Begin("Inspector");

	ImGui::Button("Hello");
	static float value = 0.0f;
	ImGui::DragFloat("Value", &value);

	ImGui::End();
}
