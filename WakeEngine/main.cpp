#include <iostream>

#include "Source/Runtime/Renderer/include/Window.h"
#include "Source/Runtime/Renderer/include/Grid.h"
#include "Source/Runtime/NPC/include/NPC.h"

#include "../ExternalLibraries/imgui/imgui.h"
#include "../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../ExternalLibraries/imgui/imgui_impl_opengl3.h"


// following tutorial here: https://learnopengl.com/Getting-started/Hello-Window
int main() {
	// init window and render system
	Wake::Render::Window window(800, 600);
	NPCManager::UI::Grid grid(window.get_glfw_window());

	// create dummy character
	NPCManager::NPC joey("Joey");

	// imgui stuff
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	// render loop
	while (!window.should_close()) {

		// input
		window.process_input();

		// render
		window.clear_buffers();
		grid.render();
		window.swap_buffers();

		window.poll_events();
	}

	return 0;
}