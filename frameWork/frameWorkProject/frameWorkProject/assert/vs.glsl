
#version 460 core

layout ( location =0 ) in vec3 ipos;
layout ( location =1 ) in vec3 inormal;
layout ( location =2 ) in vec2 iuv;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

out vec3 normal;
out vec3 color;
out vec2 uv;
out vec3 pos;

void main()
{
	gl_Position = projection * view * model * vec4(ipos, 1.0);
	uv = iuv;
	normal  = normalize(inormal);
	pos = ipos;
}
