#pragma once

#include "../include/Grid.h"
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

	ImGui::Button("Hello");
	static float value = 0.0f;
	ImGui::DragFloat("Value", &value);

	ImGui::End();
}
