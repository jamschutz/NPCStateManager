#pragma once

#include <string>

#include "NPCEmotion.h"

namespace NPCManager
{
	class NPC
	{
	public:
		// constructors
		NPC();
		NPC(std::string _name);
		~NPC();

		// get methods

		// set methods

		std::string name;
	private:
		int id;
		Emotion emotion;
	};
}