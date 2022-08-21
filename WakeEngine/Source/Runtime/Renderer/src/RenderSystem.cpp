#include "../include/RenderSystem.h"
#include "../../Utils/include/Debug.h"



/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


Wake::Render::RenderSystem::RenderSystem() {
	window = nullptr;
	init();
}


Wake::Render::RenderSystem::RenderSystem(Wake::Render::Window* _window) {
	window = _window;
	init();
}


Wake::Render::RenderSystem::~RenderSystem() {
	// do nothing
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


void Wake::Render::RenderSystem::render(Wake::Shader shader) {
	// clear buffers
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// draw to screen
	shader.activate();
	// bind texture
	texture.activate(0);
	texture2.activate(1);
	// bind VAO
	glBindVertexArray(VAOs[0]);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	// swap window buffers
	window->swap_buffers();
}


void Wake::Render::RenderSystem::set_window(Wake::Render::Window* _window) {
	window = _window;
}


void Wake::Render::RenderSystem::flip_textures_vertically(bool flip) {
	stbi_set_flip_vertically_on_load(flip);
}



/* =======================================================================  /
/  =======	   Helper Methods				==============================  /
/  ======================================================================= */

void Wake::Render::RenderSystem::init() {
	flip_textures_vertically(true);

	// generate vertex and element objects
	glGenVertexArrays(num_vaos, VAOs);
	glGenBuffers(num_vbos, VBOs);
	glGenBuffers(num_ebos, EBOs);

	// bind VAOs with VBOs
	//bind_vao(VBOs[0], VAOs[0], sizeof(verts), verts);

	// set vertex array
	glBindVertexArray(VAOs[0]);

	// bind vbo and its data
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	// bind ebo and its data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// set vertex position attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// set vertex color attributes
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// set vertex coordinate attributes
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// load texture
	texture.set_id(1);
	texture.load(texture_filename);

	texture2.set_id(1);
	texture2.set_image_type(Wake::TextureImageType::RGBA);
	texture2.load(texture2_filename);
}


void Wake::Render::RenderSystem::bind_vao(unsigned int vbo, unsigned int vao, int buffer_bytes, float* vertices) {
	// set vertex array
	glBindVertexArray(vao);

	// bind vbo and its data
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, buffer_bytes, vertices, GL_STATIC_DRAW);

	// set vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}