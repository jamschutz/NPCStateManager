#version 330 core
layout(location = 0) in vec3 a_pos; // this position var has attribute position 0
layout(location = 1) in vec3 a_col; // vertex color
layout(location = 2) in vec2 a_uv;

out vec4 vertex_color;
out vec3 vertex_position;
out vec2 uv;

void main() {
	gl_Position = vec4(a_pos.x, a_pos.y, a_pos.z, 1.0);

	vertex_position = a_pos;
	vertex_color = vec4(a_col, 1.0);
	uv = a_uv;
}