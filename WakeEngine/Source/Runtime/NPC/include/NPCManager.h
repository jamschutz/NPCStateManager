#pragma once

#include <string>
#include <vector>

#include "NPC.h"

// singleton design pattern taken from: https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
namespace NPCManager
{
	class NPCManager
	{
	public:
		// singleton get
		static NPCManager& get_instance() {
			// the only instance
			// guaranteed to be lazy initialized
			// guaranteed that it will be destroyed correctly
			static NPCManager instance;
			return instance;
		}

		// get methods
		std::vector<NPC> get_npcs();
		void load_from_file(std::string filepath);

		// set methods
		void register_npc(NPC npc);
		void delete_npc(NPC npc);

	private:
		// private constructor
		NPCManager();


		// variables
		std::vector<NPC> npcs;

	public:
		// stop the compiler from generating copy methods
		// i guess compiler warnings work better if we delete these publicly
		NPCManager(NPCManager const&)     = delete;
		void operator=(NPCManager const&) = delete;
	};
}