#pragma once

#include "../include/NPC.h"

#include <string>
#include <cstring>

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


NPCManager::NPC::NPC(nlohmann::json json_data) {
	// parse name
	std::string name_str = json_data["name"].get<std::string>();
	strcpy_s(name, NPC::MAX_NAME_LENGTH, name_str.c_str());

	// parse emotion
	int emotionId = json_data["emotion"].get<int>();
	emotion = static_cast<Emotion>(emotionId);
}


NPCManager::NPC::~NPC() {
	// do nothing for now...
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


std::string NPCManager::NPC::get_id() {
	return id.id;
}


std::string NPCManager::NPC::get_imgui_label() {
	std::string label = name;
	label += "###" + get_id();
	return label;
}