#include "Application.h"
#include <coreOpengl.h>


// 包含windows的头文件
#include <windows.h>
// 包含 opengl需要用到的头文件(完整的vs编辑器中会自带这些文件)

#pragma comment(lib, "opengl32.lib")

typedef void (APIENTRY* PFNWGLEXTSWAPCONTROLPROC) (int);
typedef int (*PFNWGLEXTGETSWAPINTERVALPROC) (void);
PFNWGLEXTSWAPCONTROLPROC wglSwapIntervalEXT = NULL;
PFNWGLEXTGETSWAPINTERVALPROC wglGetSwapIntervalEXT = NULL;
// 初始化函数指针接口
bool InitVSync()
{
	char* extensions = (char*)glGetString(GL_EXTENSIONS);
	if (strstr(extensions, "WGL_EXT_swap_control")) {
		wglSwapIntervalEXT = (PFNWGLEXTSWAPCONTROLPROC)wglGetProcAddress("wglSwapIntervalEXT");
		wglGetSwapIntervalEXT = (PFNWGLEXTGETSWAPINTERVALPROC)wglGetProcAddress("wglGetSwapIntervalEXT");
		return true;
	}

	return false;
}

// 判断当前状态是否为 垂直同步
bool IsVSyncEnabled()
{
	return (wglGetSwapIntervalEXT() > 0);
}

// 开启和关闭 垂直同步
void SetVSyncState(bool enable)
{
	if (enable)
		wglSwapIntervalEXT(1);
	else
		wglSwapIntervalEXT(0);
}



GL::Application::Application(int width, int height, const char* title):m_window(nullptr)
{

	glfwInit();

	m_window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!m_window) {
		cout << "create window faild\n";
		return;
	}
	glfwWindowHint(GLFW_REFRESH_RATE, 200);
	glfwMakeContextCurrent(m_window);

	if (!gladLoadGL()) {

		cout << "glad initialize faild\n";
		return;
	}

	//bool isOk = InitVSync();
	//if (isOk) {
	//	SetVSyncState(false);
	//}
}

GL::Application::~Application()
{

}

#include "GLShader.h"
#include "GLGeometry.h"
void GL::Application::exec()
{
	GLShader* shader = new GLShader("./vs.glsl","./fs.glsl");
	GLGeometry* geo = GLGeometry::createSurface(0);

	while (!glfwWindowShouldClose(m_window))
	{
		//glRectd(0, 0, 0.5, 0.5);
		shader->use();
		glDrawElements(GL_TRIANGLES, geo->m_number, GL_UNSIGNED_INT, 0);

		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}
	glfwTerminate();

}
