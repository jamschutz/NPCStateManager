#pragma once

#include "../../../../../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../../../../../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../../../../../ExternalLibraries/imgui/imgui_impl_opengl3.h"

#include "../../../glfw-3.3.3.bin.WIN64/glfw-3.3.3.bin.WIN64/include/GLFW/glfw3.h"

namespace NPCManager
{
	namespace UI
	{
		class Grid
		{
		public:
			// constructors
			Grid(GLFWwindow* window);
			~Grid();

			// render methods
			void render();

			// get methods

			// set methods

		private:
		};
	}
	
}