
#version 460 core

in vec3 normal;
in vec3 color;
in vec2 uv;
in vec3 pos;

out vec4 fcolor;

uniform vec3 k;
uniform vec3 lightpos;
uniform vec4 lightColor;
//点光源相关

uniform vec3 viewPos;
uniform sampler2D sampler;

vec4 pointColor()
{
	vec3 ttlightpos = vec3(-1,-1,-1);
	vec4 tcolor = texture(sampler,uv);
	
	float dis = distance(pos, lightpos);
	float effect = 1.0 / (k.x + k.y * dis + k.z * pow(dis,2));

	float diff = clamp(dot(normal, normalize(lightpos - pos)),0,1);
	vec3 diffuse = lightColor.xyz * diff;

	vec3 lightDir = normalize(lightpos - pos);
	vec3 halfDir = normalize(lightDir + viewPos);
	float spec = pow(max(0,dot(halfDir, normal)),32) *3;
	vec3 specualr = lightColor.xyz * spec;

	vec3 color = (diffuse + specualr) *effect ;

	return tcolor * vec4(color, 1);
	return vec4((normal),1);
	return tcolor;
}


void main()
{
	fcolor = pointColor();
}