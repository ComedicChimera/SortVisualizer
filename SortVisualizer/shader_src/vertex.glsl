layout(location = 0) in vec4 position;
layout(location = 0) in vec3 color;

uniform mat4 proj_mat;

out vec3 v_Color;

void main() {
	gl_Position = proj_mat * position;
	v_Color = color;
}