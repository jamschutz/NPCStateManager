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
					NPC npc(element);
					npcs.push_back(npc);
				}

				return npcs;
			}


			void save_npcs_to_file(std::vector<NPC> npcs, std::string filepath) {
				json json_data = json::array();
				for (NPC npc : npcs) {
					json_data.push_back(npc.to_json());
				}

				std::ofstream out(filepath);
				out << json_data.dump();
				out.close();
			}


			// taken from: https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
			std::string get_file_contents(std::string filepath) {
				std::ifstream t(filepath);
				std::stringstream buffer;
				buffer << t.rdbuf();
				return buffer.str();
			}


			// taken from: https://stackoverflow.com/questions/15388041/how-to-write-stdstring-to-file
			void write_to_file(std::string data, std::string filepath) {
				std::ofstream out(filepath);
				out << data;
				out.close();
			}
		}
	}
	
}