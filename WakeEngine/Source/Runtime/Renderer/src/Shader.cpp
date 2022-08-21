#pragma once

#include "../include/Shader.h"
#include "../../Utils/include/Debug.h"
#include <string>
#include <fstream>
#include <glad.h>


/* =======================================================================  /
/  =======	   Constructor/Destructors		==============================  /
/  ======================================================================= */


Wake::Shader::Shader() {
	// do nothing
}


Wake::Shader::Shader(std::string vertex_filename, std::string fragment_filename) {
	load_vert_shader(vertex_filename);
	load_frag_shader(fragment_filename);
	compile();
}


Wake::Shader::~Shader() {
	// do nothing, currently
}



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */

void Wake::Shader::set_int(std::string uniform_name, int value) {
	int uniform_location = get_uniform(uniform_name);
	if (uniform_location == UNIFORM_NOT_FOUND)
		return;

	glUniform1i(uniform_location, value);
}

void Wake::Shader::set_float(std::string uniform_name, float value) {
	int uniform_location = get_uniform(uniform_name);
	if (uniform_location == UNIFORM_NOT_FOUND)
		return;

	glUniform1f(uniform_location, value);
}

void Wake::Shader::set_vec4(std::string uniform_name, float f1, float f2, float f3, float f4) {
	int uniform_location = get_uniform(uniform_name);
	if (uniform_location == UNIFORM_NOT_FOUND)
		return;

	glUniform4f(uniform_location, f1, f2, f3, f4);
}


void Wake::Shader::load_vert_shader(std::string filename) {
	vert_shader_filename = filename;
	load_shader(filename, VERT_SHADER_TYPE);
}


void Wake::Shader::load_frag_shader(std::string filename) {
	frag_shader_filename = filename;
	load_shader(filename, FRAG_SHADER_TYPE);
}


void Wake::Shader::compile() {
	// compile vert and frag shaders
	glCompileShader(vert_shader);
	glCompileShader(frag_shader);

	check_success(vert_shader, "COMPILE", vert_shader_filename);
	check_success(frag_shader, "COMPILE", frag_shader_filename);

	// create shader program, and link vert and frag
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vert_shader);
	glAttachShader(shader_program, frag_shader);
	glLinkProgram(shader_program);

	check_success(shader_program, "LINK", vert_shader_filename);

	// delete shader objects (we no longer need them)
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
}


void Wake::Shader::activate() {
	glUseProgram(shader_program);
}



/* =======================================================================  /
/  =======	   Helper Methods				==============================  /
/  ======================================================================= */


void Wake::Shader::load_shader(const std::string& filename, char shader_type) {
	// read file contents
	std::string shader_source;
	load_shader_source(filename, shader_source);
	const char* shader_source_cstr = shader_source.c_str();

	// store in shader var, attach, and compile
	switch (shader_type) {
	case 'v':
		vert_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert_shader, 1, &shader_source_cstr, NULL);
		break;
	case 'f':
		frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(frag_shader, 1, &shader_source_cstr, NULL);
		break;
	default:
		std::string error_message = "ERROR: Bad shader type passed to Wake::Shader::load_shader method: " + shader_type;
		Wake::Debug::log_error(error_message);
		return;
	}
}



void Wake::Shader::load_shader_source(const std::string& filename, std::string& shader_contents) {
	std::ifstream shader(filename);
	std::string str((std::istreambuf_iterator<char>(shader)),
		std::istreambuf_iterator<char>());

	shader_contents = str;
}



void Wake::Shader::check_success(unsigned int shader, std::string process_type, const std::string& filename) {
	int success;
	char info_log[512];

	if (process_type == "COMPILE") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	}
	else {
		glGetShaderiv(shader, GL_LINK_STATUS, &success);
	}

	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, info_log);
		std::string error_message = "ERROR::SHADER::" + process_type + "_FAILED   file: " + filename + "\n" + info_log;
		Wake::Debug::log_error(error_message);
	}
}


int Wake::Shader::get_uniform(const std::string& uniform_name) {
	int uniform_location = glGetUniformLocation(shader_program, uniform_name.c_str());
	if (uniform_location == UNIFORM_NOT_FOUND) {
		std::string error_message = "ERROR: Failed to find uniform " + uniform_name + " in shader program with vertex shader: " + vert_shader_filename;
		Wake::Debug::log_error(error_message);
	}

	return uniform_location;
}