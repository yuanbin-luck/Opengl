#pragma once

namespace GL {

	class GLRender;
	class GLShader;
	class GLTexture;
	class GLMaterial
	{
	public:
		GLMaterial(GLShader* shader = nullptr, GLTexture* texture = nullptr );

		~GLMaterial();

		void use();

		void setShader(GLShader* shader);

		void setTexture(GLTexture* texture);

	private:
		friend class GLRender;
		GLShader* m_shader; 
		GLTexture* m_texture;

	};

}