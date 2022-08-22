#pragma once

#include "../include/Window.h"
#include "../../Utils/include/Debug.h"


/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


NPCManager::Render::Window::Window() {
	init(800, 600);
}


NPCManager::Render::Window::Window(int32_t width, int32_t height) {
	init(width, height);
}


NPCManager::Render::Window::~Window() {
	glfwTerminate();
}

void NPCManager::Render::Window::init(int32_t width, int32_t height) {
	/* Init GLFW */
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if ___APPLE___ && TARGET_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(width, height, "Wake Engine", NULL, NULL);
	if (window == NULL) {
		Wake::Debug::log_error("Failed to create GLFW window! TERMINATING");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	/* Init GLAD */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		Wake::Debug::log_error("Failed to initialize GLAD");
		return;
	}

	// set viewport info -- note that these dimensions can be smaller than GLFW's, it'd just be a nested window
	// could use that for drawing UI stuff, etc around the borders
	glViewport(0, 0, width, height);

	// set up callback method for window resizing
	glfwSetFramebufferSizeCallback(window, this->on_resize);
}



/* =======================================================================  /
/  =======	   Callback Methods				==============================  /
/  ======================================================================= */


void NPCManager::Render::Window::on_resize(GLFWwindow* resized_window, int width, int height) {
	glViewport(0, 0, width, height);
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */


void NPCManager::Render::Window::process_input() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


void NPCManager::Render::Window::clear_buffers() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}


void NPCManager::Render::Window::swap_buffers() {
	glfwSwapBuffers(window);
}


void NPCManager::Render::Window::poll_events() {
	glfwPollEvents();
}


bool NPCManager::Render::Window::should_close() {
	return glfwWindowShouldClose(window);
}


int32_t NPCManager::Render::Window::get_width() {
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	return width;
}


int32_t NPCManager::Render::Window::get_height() {
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	return height;
}


GLFWwindow* NPCManager::Render::Window::get_glfw_window() {
	return window;
}