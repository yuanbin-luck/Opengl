#pragma once
#include <list>

namespace GL {

	class GLObject;
	class GLLight;
	class GLCamera;
	class GLShader;
	class GLMaterial;
	class GLCallBack
	{
	public:
		virtual void callback(GLCamera* camera, GLObject* obj, GLMaterial* material, GLShader* global, const std::list<GLLight*>& lights);

	};

}

