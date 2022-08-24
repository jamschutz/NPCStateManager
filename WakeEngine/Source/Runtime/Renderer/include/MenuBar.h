#pragma once

#include "../../../../../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../../../../../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../../../../../ExternalLibraries/imgui/imgui_impl_opengl3.h"

namespace NPCManager
{
	namespace UI
	{
		class MenuBar
		{
		public:
			// constructors
			MenuBar();
			~MenuBar();

			// render methods
			void render(bool& opt_fullscreen, bool& opt_padding, ImGuiDockNodeFlags dockspace_flags);

			// get methods

			// set methods

		private:

			bool show_style_selector(const char* label);
		};
	}

}