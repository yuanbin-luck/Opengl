#pragma once

struct GLFWwindow;
namespace GL {

	class GLScense;
	class GLRender;
	class GLShader;
	class GLGeometry;
	class GLTexture;
	class GLObject;
	class Application
	{
	public:
		Application(int width, int height, const char* title);

		~Application();

		void exec();

		void addScense(GLScense* scense);

		void addRoot(GLObject* root);

	private:
		static void windowsizefun(GLFWwindow* window, int width, int height);

	private:
		GLFWwindow* m_window;
		GLRender* m_render;
		GLScense* m_scense;

		GLTexture* texture = nullptr;
		GLShader* shader = nullptr;
		GLGeometry* geo = nullptr;
	};

}
