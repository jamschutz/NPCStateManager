#pragma once

#include <string>

namespace Wake {
	class Shader {
	public:
		Shader();
		Shader(std::string vertex_filename, std::string fragment_filename);
		~Shader();

		void set_int(std::string uniform_name, int value);
		void set_float(std::string uniform_name, float value);
		void set_vec4(std::string uniform_name, float f1, float f2, float f3, float f4);

		void load_vert_shader(std::string filename);
		void load_frag_shader(std::string filename);
		void compile();

		void activate();

	private:
		int get_uniform(const std::string& uniform_name);
		void load_shader(const std::string& filename, char shader_type);
		void load_shader_source(const std::string& filename, std::string& shader_contents);
		void check_success(unsigned int shader, std::string process_type, const std::string& filename);

		unsigned int vert_shader, frag_shader, shader_program;
		std::string vert_shader_filename, frag_shader_filename;

		const char VERT_SHADER_TYPE = 'v';
		const char FRAG_SHADER_TYPE = 'f';
		const int UNIFORM_NOT_FOUND = -1;
	};
}


