#pragma once

#include <cstdint>
#include "../include/Window.h"
#include "../include/Shader.h"
#include "../include/Texture.h"

namespace Wake {
	namespace Render {
		class RenderSystem
		{
		public:
			RenderSystem();
			RenderSystem(Wake::Render::Window* _window);
			~RenderSystem();

			void render(Wake::Shader shader);
			void flip_textures_vertically(bool flip);
			void set_window(Wake::Render::Window* _window);

			static const int8_t opengl_major = 3;
			static const int8_t opengl_minor = 3;

		private:
			void init();
			void bind_vao(unsigned int vbo, unsigned int vao, int buffer_bytes, float* vertices);

			// window render system draws to
			Wake::Render::Window* window;

			// vertex buffer obj, vertex array object, element buffer obj
			unsigned int VBOs[1], VAOs[1], EBOs[1];
			const int num_vbos = sizeof(VBOs) / sizeof(unsigned int);
			const int num_vaos = sizeof(VAOs) / sizeof(unsigned int);
			const int num_ebos = sizeof(EBOs) / sizeof(unsigned int);

			// vertices and indices
			float verts[32] = {
				// positions          // colors           // texture coords
			    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
			   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
			};
			unsigned int indices[6] = {
				0, 1, 3, // first triangle
				1, 2, 3  // second triangle
			};

			const char* texture_filename  = "./Resources/Textures/container.JPG";
			const char* texture2_filename = "./Resources/Textures/awesomeface.PNG";
			Wake::Texture texture;
			Wake::Texture texture2;

			//unsigned int texture1, texture2;
		};
	}
}

