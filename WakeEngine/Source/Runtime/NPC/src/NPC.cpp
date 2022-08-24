#pragma once

#include "../include/NPC.h"

#include <string>
#include <cstring>
#include <iostream>

/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


NPCManager::NPC::NPC() {
	strcpy_s(name, "");
	emotion = Emotion::Happy;
}


NPCManager::NPC::NPC(char* _name) {
	strcpy_s(name, _name);
	emotion = Emotion::Happy;
}


NPCManager::NPC::NPC(const char* _name) {
	strcpy_s(name, _name);
	emotion = Emotion::Happy;
}


NPCManager::NPC::~NPC() {
	// do nothing for now...
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


std::string NPCManager::NPC::get_id() {
	std::cout << "\nnpc with name '" << "name" << "' has id: " << id.id;
	return id.id;
}


std::string NPCManager::NPC::get_imgui_label() {
	std::string label = name;
	label += "###" + get_id();
	return label;
}