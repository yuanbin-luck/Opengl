
#version 460 core


in vec3 normal;
in vec3 color;
in vec2 uv;

out vec4 fcolor;

uniform sampler2D sampler;



void main()
{
	vec4 tcolor = texture(sampler,uv);

	vec4 viewPos = vec4(0,0,1,1);
	vec4 lightDir = vec4(-1,-1,-1,0);
	vec4 ambientColor = vec4(1,1,1,1);
	vec4 diffuseColor = vec4(1,1,1,1);
	vec4 specularColor = vec4(1,1,1,1);


	vec4 ambient = ambientColor * 0.1;


	vec3 reLightDir = reflect(lightDir.xyz,normal);
	float diff = max(0, dot(reLightDir,normal));
	vec4 diffuse = diffuseColor * diff;


	vec3 halfDir = -lightDir.xyz + viewPos.xyz;
	float spec = pow(max(0, dot(normalize(halfDir),normal)),128) *0.2; 
	vec4 specular = specularColor * spec;

	fcolor = tcolor *( ambient + diffuse + specular);


	//fcolor = vec4(1,0,0,1);
}