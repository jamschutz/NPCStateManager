#include "Source/Runtime/Renderer/include/Window.h"
#include "Source/Runtime/Renderer/include/Shader.h"
#include "Source/Runtime/Renderer/include/RenderSystem.h"
#include <iostream>


// following tutorial here: https://learnopengl.com/Getting-started/Hello-Window
int main() {
	// init window and render system
	Wake::Render::Window window(800, 600);
	Wake::Render::RenderSystem render_system(&window);

	// load shader
	Wake::Shader shader("Source/Shaders/vert.glsl", "Source/Shaders/frag.glsl");

	// activate shader before setting uniforms
	shader.activate();
	// apply uniforms
	shader.set_int("texture1", 0);
	shader.set_int("texture2", 1);

	// render loop
	while (!window.should_close()) {
		// input
		window.process_input();

		// render
		render_system.render(shader);
		window.poll_events();
	}

	return 0;
}