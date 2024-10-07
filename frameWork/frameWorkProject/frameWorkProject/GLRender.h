#pragma once

#include <coreOpengl.h>

namespace GL {

	class GLLight;
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
		void renderLights(const list<GLLight*>& lights);

		void renderChilds(GLObject* child, GLShader* globalShader, const list<GLLight*>& lights);
		
		void renderLight(GLObject* light);
	
	
	};
}

