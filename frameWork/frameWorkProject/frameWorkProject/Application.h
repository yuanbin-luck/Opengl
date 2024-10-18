#pragma once

#include <coreOpengl.h>
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

		static void mousebuttonfun(GLFWwindow* window, int button, int action, int mods);

		static void errorCalback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

	private:
		GLFWwindow* m_window;
		GLRender* m_render;
		GLScense* m_scense;
		static Application* m_self;

		GLTexture* texture = nullptr;
		GLShader* shader = nullptr;
		GLGeometry* geo = nullptr;
	};

}
