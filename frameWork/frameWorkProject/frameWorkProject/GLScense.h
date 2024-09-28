#pragma once
#include "GLObject.h"

namespace GL {

	class GLShader;
	class GLRender;
	class GLScense :public GLObject
	{
	public:
		GLScense(GLObject* parent = nullptr);

		~GLScense();

	private:
		friend class GLRender;
		GLShader* m_global;
	};
}
