#pragma once

#include "../include/NPC.h"

#include <string>

/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


NPCManager::NPC::NPC() {
	name = "";
}


NPCManager::NPC::NPC(std::string _name) {
	name = _name;
}


NPCManager::NPC::~NPC() {
	// do nothing for now...
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


