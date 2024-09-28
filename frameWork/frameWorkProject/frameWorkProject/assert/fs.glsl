
#version 460 core
in vec3 color;
in vec2 uv;
out vec4 fcolor;

uniform sampler2D sampler;

void main()
{
	fcolor = texture(sampler,uv);
}