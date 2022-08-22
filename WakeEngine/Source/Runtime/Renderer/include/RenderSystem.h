#pragma once

#include "../include/Window.h"
#include "../include/Inspector.h"
#include "../include/Grid.h"
#include "../include/MenuBar.h"

#include "../../../../../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../../../../../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../../../../../ExternalLibraries/imgui/imgui_impl_opengl3.h"

#include "../../../glfw-3.3.3.bin.WIN64/glfw-3.3.3.bin.WIN64/include/GLFW/glfw3.h"

namespace NPCManager
{
	class RenderSystem
	{
	public:
		// constructors
		RenderSystem(Render::Window* window);
		~RenderSystem();

		// render methods
		void render();

		// get methods

		// set methods

	private:
		Render::Window* window;
		UI::Grid grid;
		UI::Inspector inspector;
		UI::MenuBar menuBar;

		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	};

}