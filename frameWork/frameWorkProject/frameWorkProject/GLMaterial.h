#pragma once

#include <coreOpengl.h>

namespace GL {

	class GLObject;
	class GLLight;
	class GLCamera;
	class GLRender;
	class GLShader;
	class GLTexture;
	class GLCallBack;
	class GLMaterial
	{
	public:
		GLMaterial(GLShader* shader = nullptr, GLTexture* texture = nullptr );

		~GLMaterial();

		void use(GLCamera* camera, GLObject* obj, GLShader* global, const std::list<GLLight*>& lights);

		void setShader(GLShader* shader);

		void setTexture(GLTexture* texture);

		void setRenderCallBack(GLCallBack* callback);

		GLShader* getShader();

		unsigned int getTextureUnit();

	private:
		friend class GLRender;
		GLShader* m_shader; 
		GLTexture* m_texture;
		GLCallBack* m_callback;
	};

}