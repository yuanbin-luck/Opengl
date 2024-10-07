#include "GLScense.h"
#include "GLShader.h"

GL::GLScense::GLScense(GLObject* parent):GLObject(parent), m_global(nullptr)
{
	m_global = new GLShader("./assert/vs.glsl", "./assert/fs.glsl");
}

GL::GLScense::~GLScense()
{
}

const list<GL::GLLight*>& GL::GLScense::getLights()
{
	return m_lights;
}

void GL::GLScense::addLight(GLLight* light)
{
	m_lights.push_back(light);
}

void GL::GLScense::removeLight(GLLight* light)
{
	auto node = std::find(m_lights.begin(), m_lights.end(), light);
	if (node != m_lights.end())
	{
		m_lights.remove(light);
	}
}
