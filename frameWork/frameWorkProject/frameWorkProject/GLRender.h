#pragma once

#include <coreOpengl.h>

namespace GL {
	
	class GLShader;
	class GLObject;
	class GLScense;
	class GLRender
	{
	public:
		GLRender();

		~GLRender();

		void setClearColor(float r, float g, float b, float a = 1.0f);

		void render(GLuint frame, GLScense* scense);

	private:
		void renderChilds(GLObject* child, GLShader* global);

	};
}

