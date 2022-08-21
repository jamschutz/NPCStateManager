#version 330 core
out vec4 FragColor;

in vec4 vertex_color;
in vec3 vertex_position;
in vec2 uv;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
	vec4 main_color = texture(texture1, uv);
	vec4 secondary_color = texture(texture2, uv);

	vec4 color = mix(main_color, secondary_color, 0.2);

	FragColor = color;
}