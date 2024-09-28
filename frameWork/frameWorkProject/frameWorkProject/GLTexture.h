#pragma once

#include <coreOpengl.h>

namespace GL {

	class GLTexture
	{
	public:
		GLTexture(const char* textureName, unsigned int unit);

		~GLTexture();

		void bind();

	private:
		void loadTexture(const char* textureName);

	private:
		GLuint m_texture;
		GLuint m_unit;
		GLuint m_tTarget;
	};
}