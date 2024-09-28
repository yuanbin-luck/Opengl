#include "GLMaterial.h"
#include "GLShader.h"
#include "GLTexture.h"
#include "GLCallBack.h"

GL::GLMaterial::GLMaterial(GLShader* shader, GLTexture* texture):m_shader(shader)
	,m_texture(texture), m_callback(new GLCallBack())
{

}

GL::GLMaterial::~GLMaterial()
{
}

void GL::GLMaterial::use(GLCamera* camera, GLShader* global)
{
	if (m_shader)
	{
		m_shader->use();
	}
	if (m_texture)
	{
		m_texture->bind();
	}

	if (m_callback)
	{
		m_callback->callback(camera,this, global);
	}
}

void GL::GLMaterial::setShader(GLShader* shader)
{
	m_shader = shader;
}

void GL::GLMaterial::setTexture(GLTexture* texture)
{
	m_texture = texture;
}

void GL::GLMaterial::setRenderCallBack(GLCallBack* callback)
{
	if (m_callback) {
		delete m_callback;
		m_callback = nullptr;
	}
	m_callback = callback;
}

GL::GLShader* GL::GLMaterial::getShader()
{
	return m_shader;
}

unsigned int  GL::GLMaterial::getTextureUnit()
{
	if(m_texture)
	return GLuint();
}
