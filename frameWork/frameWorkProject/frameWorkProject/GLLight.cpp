#include "GLLight.h"
#include "GLGeometry.h"
#include "GLMaterial.h"
#include "GLShader.h"
#include "GLLightCallBack.h"

GL::GLLight::GLLight(const glm::vec4& lightColor,GLObject* parent)
	:GLNode(GLGeometry::createSphere(0.1), new GLMaterial(new GLShader("./assert/light-vs.glsl", "./assert/light-fs.glsl")), parent)
	, m_lightColor(lightColor), m_type(LT_None)
{
	getMaterial()->setRenderCallBack(new GLLightCallBack);
}

GL::GLLight::~GLLight()
{

}

glm::vec4 GL::GLLight::lightColor()
{
	return m_lightColor;
}

void GL::GLLight::setLightColor(const glm::vec4& lightColor)
{
	m_lightColor = lightColor;
}
