#pragma once

#include "glad.h"
#include "../../../glfw-3.3.3.bin.WIN64/glfw-3.3.3.bin.WIN64/include/GLFW/glfw3.h"

namespace Wake {
	namespace Render {
		class Window
		{
		public:
			Window();
			Window(int32_t w, int32_t h);
			~Window();

			bool should_close();
			void process_input();
			void clear_buffers();
			void swap_buffers();
			void poll_events();

			int32_t get_width();
			int32_t get_height();
			GLFWwindow* get_glfw_window();

		private:
			void init(int32_t width, int32_t height);
			static void on_resize(GLFWwindow* resized_window, int width, int height);

			GLFWwindow* window;
		};
	}
}


