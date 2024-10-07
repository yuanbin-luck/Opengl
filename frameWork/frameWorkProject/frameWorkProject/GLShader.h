#pragma once

#include <coreOpengl.h>

namespace GL {

	class GLShader
	{
	public:
		GLShader(const string& vs, const string& fs);

		~GLShader();

		void use();

		void setInt(const char* name, int val);

		void setFloat(const char* name, float val);

		void setVec3(const char* name, const glm::vec3& val);

		void setVec4(const char* name, const glm::vec4& val);

		void setMat4(const char* name, const glm::mat4& mat);

	private:
		void createShaderProgram(const string& vs, const string& fs);

		bool checkState(GLuint handle, bool isShader = true);

	private:
		GLuint m_program;

	};
}
