#pragma once

#include <coreOpengl.h>

namespace GL {

	class GLShader
	{
	public:
		GLShader(const string& vs, const string& fs);

		~GLShader();

		void use();

	private:
		void createShaderProgram(const string& vs, const string& fs);

		bool checkState(GLuint handle, bool isShader = true);

	private:
		GLuint m_program;

	};
}
