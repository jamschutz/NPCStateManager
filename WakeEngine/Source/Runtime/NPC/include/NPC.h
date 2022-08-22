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
		NPC(char* _name);
		NPC(const char* _name);
		~NPC();

		// get methods

		// set methods

		char name[64];
		Emotion emotion;

		static const int MAX_NAME_LENGTH = 64;
	private:
		int id;
	};
}