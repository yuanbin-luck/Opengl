#pragma once

struct GLFWwindow;
namespace GL {

	class GLShader;
	class GLGeometry;
	class GLTexture;
	class Application
	{
	public:
		Application(int width, int height, const char* title);

		~Application();

		void exec();

	private:
		GLFWwindow* m_window;

		GLTexture* texture = nullptr;
		GLShader* shader = nullptr;
		GLGeometry* geo = nullptr;
	};

}
