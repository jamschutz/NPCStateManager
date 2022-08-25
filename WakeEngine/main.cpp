#include <iostream>
#include <string>
#include <vector>

#include "Source/Runtime/Renderer/include/Window.h"
#include "Source/Runtime/Renderer/include/RenderSystem.h"
#include "Source/Runtime/Renderer/include/Grid.h"
#include "Source/Runtime/NPC/include/NPC.h"
#include "Source/Runtime/Utils/include/FileManager.h"

#include "../ExternalLibraries/imgui/imgui.h"
#include "../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../ExternalLibraries/imgui/imgui_impl_opengl3.h"


// following tutorial here: https://learnopengl.com/Getting-started/Hello-Window
int main() {
	// init window and render system
	//NPCManager::Render::Window window(800, 600);
	//NPCManager::RenderSystem renderer(&window);
	//
	//// create dummy character
	//NPCManager::NPC joey("Joey");

	// render loop
	//while (!window.should_close()) {
	//
	//	// input
	//	window.process_input();
	//
	//	// render
	//	renderer.render();
	//
	//	// poll events
	//	window.poll_events();
	//}

	std::string json_filepath = "D:\\dev\\Code\\NPCStateManager\\sandbox\\NPCs.json";
	std::string file_contents = NPCManager::Utils::FileManager::get_file_contents(json_filepath);

	std::cout << file_contents;

	std::vector<NPCManager::NPC> npc_data = NPCManager::Utils::FileManager::get_npcs_from_file(json_filepath);


	std::string input;

	return 0;
}