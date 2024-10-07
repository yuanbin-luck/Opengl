#pragma once
#include "GLCallBack.h"

namespace GL {
	class GLLightCallBack :public GLCallBack
	{
	public:
		virtual void callback(GLCamera* camera, GLObject* obj, GLMaterial* material, GLShader* global, const std::list<GLLight*>& lights);

	};
}

