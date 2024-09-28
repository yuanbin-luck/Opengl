#pragma once

namespace GL {

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

		void use(GLCamera* camera, GLShader* global);

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