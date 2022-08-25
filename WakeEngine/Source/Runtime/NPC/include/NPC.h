#pragma once

#include <string>

#include "NPCEmotion.h"
#include "../../Utils/include/Guid.h"

#include "../../../../../ExternalLibraries/json/json.hpp"

namespace NPCManager
{
	class NPC
	{
	public:
		// constructors
		NPC();
		NPC(char* _name);
		NPC(const char* _name);
		NPC(nlohmann::json json_data);
		
		~NPC();

		// get methods
		std::string get_id();
		std::string get_imgui_label();
		nlohmann::json to_json();

		// set methods

		char name[64];
		Emotion emotion;

		static const int MAX_NAME_LENGTH = 64;
	private:
		Utils::Guid id;
		
	};
}