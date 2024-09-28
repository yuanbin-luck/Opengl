#include "GLScense.h"
#include "GLShader.h"

GL::GLScense::GLScense(GLObject* parent):GLObject(parent), m_global(nullptr)
{
	m_global = new GLShader("./assert/vs.glsl", "./assert/fs.glsl");
}

GL::GLScense::~GLScense()
{
}
