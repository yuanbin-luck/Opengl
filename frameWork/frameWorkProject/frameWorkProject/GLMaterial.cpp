#include "GLMaterial.h"

GL::GLMaterial::GLMaterial(GLShader* shader, GLTexture* texture):m_shader(shader)
	,m_texture(texture)
{

}

GL::GLMaterial::~GLMaterial()
{
}

void GL::GLMaterial::use()
{
}

void GL::GLMaterial::setShader(GLShader* shader)
{
	m_shader = shader;
}

void GL::GLMaterial::setTexture(GLTexture* texture)
{
	m_texture = texture;
}
