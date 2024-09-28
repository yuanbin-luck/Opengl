
#version 460 core

layout ( location =0 ) in vec3 pos;
layout ( location =1 ) in vec3 normal;
layout ( location =2 ) in vec2 iuv;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

out vec3 color;
out vec2 uv;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 1.0);
	color = abs(pos);
	uv = iuv;
}
