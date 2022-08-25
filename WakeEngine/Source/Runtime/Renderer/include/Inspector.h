#pragma once

#include "../../NPC/include/NPC.h"

#include "../../../../../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../../../../../ExternalLibraries/imgui/imgui_impl_glfw.h"
#include "../../../../../ExternalLibraries/imgui/imgui_impl_opengl3.h"

#include <vector>

namespace NPCManager
{
	namespace UI
	{
		class Inspector
		{
		public:
			// constructors
			Inspector();
			~Inspector();

			// render methods
			void render();

			// get methods

			// set methods

		private:
			void show_delete_npc_button(NPC npc);
			void show_delete_npc_popup(NPC npc);
			void show_add_npc_button();
		};
	}

}