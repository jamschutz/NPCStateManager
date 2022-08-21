#pragma once

#include "../include/Grid.h"



/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


NPCManager::UI::Grid::Grid(GLFWwindow* window) {
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
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}


NPCManager::UI::Grid::~Grid() {
	// shut down ImGui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


void NPCManager::UI::Grid::render() {

	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// Draw the grid
	ImGui::Begin("Grid");

	ImGui::Button("Hello");
	static float value = 0.0f;
	ImGui::DragFloat("Value", &value);

	ImGui::End();

	// Render ImGui
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
