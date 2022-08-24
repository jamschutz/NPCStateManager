#pragma once

#include <string>

#include "NPCEmotion.h"
#include "../../Utils/include/Guid.h"

namespace NPCManager
{
	class NPC
	{
	public:
		// constructors
		NPC();
		NPC(char* _name);
		NPC(const char* _name);
		~NPC();

		// get methods
		std::string get_id();

		// set methods

		char name[64];
		Emotion emotion;

		static const int MAX_NAME_LENGTH = 64;
	private:
		Utils::Guid id;
		
	};
}