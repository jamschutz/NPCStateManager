#include "Source/Runtime/Renderer/include/Window.h"
#include "Source/Runtime/Renderer/include/Shader.h"
#include "Source/Runtime/Renderer/include/RenderSystem.h"
#include <iostream>

#include "../ExternalLibraries/imgui/imgui.h"
#include "../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../ExternalLibraries/imgui/imgui_impl_opengl3.h"


// following tutorial here: https://learnopengl.com/Getting-started/Hello-Window
int main() {
	// init window and render system
	Wake::Render::Window window(800, 600);
	Wake::Render::RenderSystem render_system(&window);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window.get_glfw_window(), true);
	ImGui_ImplOpenGL3_Init("#version 330");

	// render loop
	while (!window.should_close()) {
		// input
		window.process_input();

		// render
		//render_system.render(shader);
		window.poll_events();
	}

	return 0;
}