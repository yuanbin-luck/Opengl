#pragma once
#include "GLObject.h"

namespace GL {

	class GLLight;
	class GLShader;
	class GLRender;
	class GLScense :public GLObject
	{
	public:
		GLScense(GLObject* parent = nullptr);

		~GLScense();

		const list<GLLight*>& getLights();

		void addLight(GLLight* light);

		void removeLight(GLLight* light);

	private:
		friend class GLRender;
		
		GLShader* m_global;
		
		list<GLLight*> m_lights;

	};
}
