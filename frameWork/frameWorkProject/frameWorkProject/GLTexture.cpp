#include "GLTexture.h"

#define STB_IMAGE_IMPLEMENTATION

#include "./stb/stb_image.h"
GL::GLTexture::GLTexture(const char* textureName, unsigned int unit)
 : m_unit(0), m_tTarget(GL_TEXTURE_2D)
{
	loadTexture(textureName);
}

GL::GLTexture::~GLTexture()
{
}

void GL::GLTexture::bind()
{
	glActiveTexture(GL_TEXTURE0 + m_unit);
	glBindTexture(m_tTarget, m_texture);
}

void GL::GLTexture::loadTexture(const char* textureName)
{
	int w = 0, h=0, ch=0;
	const unsigned char* data = stbi_load(textureName,&w,&h,&ch,STBI_rgb_alpha);

	glGenTextures(1, &m_texture);
	glBindTexture(m_tTarget, m_texture);

	glTexImage2D(m_tTarget, 0, GL_RGBA, w,h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glTexParameteri(m_tTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(m_tTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri(m_tTarget, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(m_tTarget, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
