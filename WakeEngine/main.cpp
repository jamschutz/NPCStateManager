#include <iostream>

#include "Source/Runtime/Renderer/include/Window.h"
#include "Source/Runtime/Renderer/include/RenderSystem.h"
#include "Source/Runtime/Renderer/include/Grid.h"
#include "Source/Runtime/NPC/include/NPC.h"

#include "../ExternalLibraries/imgui/imgui.h"
#include "../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../ExternalLibraries/imgui/imgui_impl_opengl3.h"


// following tutorial here: https://learnopengl.com/Getting-started/Hello-Window
int main() {
	// init window and render system
	NPCManager::Render::Window window(800, 600);
	NPCManager::RenderSystem renderer(&window);

	// create dummy character
	NPCManager::NPC joey("Joey");

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