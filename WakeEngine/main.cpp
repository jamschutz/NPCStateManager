#include <iostream>
#include <string>
#include <vector>

#include "Source/Runtime/Renderer/include/Window.h"
#include "Source/Runtime/Renderer/include/RenderSystem.h"
#include "Source/Runtime/Renderer/include/Grid.h"
#include "Source/Runtime/NPC/include/NPC.h"
#include "Source/Runtime/NPC/include/NPCManager.h"

#include "../ExternalLibraries/imgui/imgui.h"
#include "../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../ExternalLibraries/imgui/imgui_impl_opengl3.h"


// following tutorial here: https://learnopengl.com/Getting-started/Hello-Window
int main() {
	// init window and render system
	NPCManager::Render::Window window(800, 600);
	NPCManager::RenderSystem renderer(&window);

	// init NPC Manager
	std::string npc_filepath = "D:\\dev\\Code\\NPCStateManager\\sandbox\\NPCs.json";
	NPCManager::NPCManager::get_instance().load_from_file(npc_filepath);

	// render loop
	while (!window.should_close()) {

		// input
		window.process_input();

		// render
		renderer.render();

		// poll events
		window.poll_events();
	}

	return 0;
}