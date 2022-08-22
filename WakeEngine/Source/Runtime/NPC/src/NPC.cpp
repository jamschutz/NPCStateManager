#pragma once

#include "../include/NPC.h"

#include <cstring>

/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


NPCManager::NPC::NPC() {
	strcpy_s(name, "");
}


NPCManager::NPC::NPC(char* _name) {
	strcpy_s(name, _name);
}


NPCManager::NPC::NPC(const char* _name) {
	strcpy_s(name, _name);
}


NPCManager::NPC::~NPC() {
	// do nothing for now...
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


