#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "../../../../../ExternalLibraries/json/json.hpp"

#include "../../NPC/include/NPC.h"

using json = nlohmann::json;

namespace NPCManager
{
	namespace Utils
	{
		namespace FileManager
		{
			std::vector<NPC> get_npcs_from_file(std::string filepath) {
				// read file
				std::ifstream file(filepath);
				json data = json::parse(file);
				
				std::vector<NPC> npcs;
				for (auto& element : data) {
					NPC npc;

					// parse name
					std::string name = element["name"].get<std::string>();
					strcpy_s(npc.name, NPC::MAX_NAME_LENGTH, name.c_str());

					// parse emotion
					int emotionId = element["emotion"].get<int>();
					npc.emotion = static_cast<Emotion>(emotionId);

					// add npc to list
					npcs.push_back(npc);
				}

				return npcs;
			}


			// taken from: https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
			std::string get_file_contents(std::string filepath) {
				std::ifstream t(filepath);
				std::stringstream buffer;
				buffer << t.rdbuf();
				return buffer.str();
			}
		}
	}
	
}