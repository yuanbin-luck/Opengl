#include "Application.h"
#include <coreOpengl.h>
#include "GLShader.h"
#include "GLGeometry.h"
#include "GLTexture.h"
#include "GLRender.h"
#include "GLScense.h"
#include "GLNode.h"
#include "GLMaterial.h"
#include "GLPointLight.h"

// ����windows��ͷ�ļ�
#include <windows.h>
// ���� opengl��Ҫ�õ���ͷ�ļ�(������vs�༭���л��Դ���Щ�ļ�)

#pragma comment(lib, "opengl32.lib")

typedef void (APIENTRY* PFNWGLEXTSWAPCONTROLPROC) (int);
typedef int (*PFNWGLEXTGETSWAPINTERVALPROC) (void);
PFNWGLEXTSWAPCONTROLPROC wglSwapIntervalEXT = NULL;
PFNWGLEXTGETSWAPINTERVALPROC wglGetSwapIntervalEXT = NULL;
// ��ʼ������ָ��ӿ�
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

// �жϵ�ǰ״̬�Ƿ�Ϊ ��ֱͬ��
bool IsVSyncEnabled()
{
	return (wglGetSwapIntervalEXT() > 0);
}

// �����͹ر� ��ֱͬ��
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
	glViewport(0,0,width,height);
	glClearColor(0, 0, 0,1);
	//bool isOk = InitVSync();
	//if (isOk) {
	//	SetVSyncState(false);
	//}

	glfwSetWindowSizeCallback(m_window, windowsizefun);


	m_render = new GLRender();
	m_scense = new GLScense(nullptr);
	m_scense->addLight(new GLPointLight);
	addRoot(new GLNode(GLGeometry::createCube(1)
		, new GLMaterial(new GLShader("./assert/vs.glsl", "./assert/fs.glsl"),new GLTexture("./assert/1.jpg",0))));
}

GL::Application::~Application()
{

}

void GL::Application::exec()
{
	while (!glfwWindowShouldClose(m_window))
	{
		if (m_render)
		{
			m_render->render(0, m_scense);
		}
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}
	glfwTerminate();

}

void GL::Application::addScense(GLScense* scense)
{
	if (m_scense)
	{
		delete m_scense;
		m_scense = nullptr;
	}
	m_scense = scense;
}

void GL::Application::addRoot(GLObject* root)
{
	if (m_scense)
	{
		m_scense->addChild(root);
	}
}

void GL::Application::windowsizefun(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
