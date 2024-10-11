#include "GLPointLight.h"

GL::GLPointLight::GLPointLight(const glm::vec3& lightPos, const glm::vec4& lightColor, GLObject* parent):GLLight(lightColor, parent)
,m_lightPos(lightPos)
{
	m_type = LT_Point;
	setEffectRange(600);
	setLocation(0,0,2);
}

GL::GLPointLight::~GLPointLight()
{
}

void GL::GLPointLight::getLightK(float& k, float& k1, float& k2)
{
	k = m_k;
	k1 = m_k1;
	k2 = m_k2;
}

void GL::GLPointLight::setEffectRange(float distence)
{
	if (0 <= distence && distence <= 7)
	{
		m_k = 1.0;
		m_k1 = 0.7;
		m_k2 = 1.8;
	}
	else if (7 < distence && distence <= 13)
	{
		m_k = 1.0;
		m_k1 = 0.35;
		m_k2 = 0.44;
	}
	else if (13 < distence && distence <= 20)
	{
		m_k = 1.0;
		m_k1 = 0.22;
		m_k2 = 0.20;
	}
	else if (20 < distence && distence <= 32)
	{
		m_k = 1.0;
		m_k1 = 0.14;
		m_k2 = 0.07;
	}
	else if (32 < distence && distence <= 50)
	{
		m_k = 1.0;
		m_k1 = 0.09;
		m_k2 = 0.032;
	}
	else if (50 < distence && distence <= 65)
	{
		m_k = 1.0;
		m_k1 = 0.07;
		m_k2 = 0.017;
	}
	else if (65 < distence && distence <= 100)
	{
		m_k = 1.0;
		m_k1 = 0.045;
		m_k2 = 0.0075;
	}
	else if (100 < distence && distence <= 160)
	{
		m_k = 1.0;
		m_k1 = 0.027;
		m_k2 = 0.0028;
	}
	else if (160 < distence && distence <= 200)
	{
		m_k = 1.0;
		m_k1 = 0.022;
		m_k2 = 0.0019;
	}
	else if (200 < distence && distence <= 325)
	{
		m_k = 1.0;
		m_k1 = 0.014;
		m_k2 = 0.0007;
	}
	else if (325 < distence && distence <= 600)
	{
		m_k = 1.0;
		m_k1 = 0.007;
		m_k2 = 0.0002;
	}
	else if (600 < distence && distence <= 3250)
	{
		m_k = 1.0;
		m_k1 = 0.0014;
		m_k2 = 0.000007;
	}
}
