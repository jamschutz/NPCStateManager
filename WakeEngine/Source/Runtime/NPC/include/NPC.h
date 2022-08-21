#pragma once

#include <string>

namespace NPCManager
{
	class NPC
	{
	public:
		NPC();
		NPC(std::string _name);
		~NPC();

	private:
		std::string name;
	};
}