#pragma once

namespace GL {

	class GLCamera;
	class GLShader;
	class GLMaterial;
	class GLCallBack
	{
	public:
		virtual void callback(GLCamera* camera, GLMaterial* material, GLShader* global);

	};

}

