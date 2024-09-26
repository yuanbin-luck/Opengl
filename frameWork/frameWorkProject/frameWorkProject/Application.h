#pragma once

struct GLFWwindow;
namespace GL {

	class Application
	{
	public:
		Application(int width, int height, const char* title);

		~Application();

		void exec();

	private:

		GLFWwindow* m_window;
	};

}
