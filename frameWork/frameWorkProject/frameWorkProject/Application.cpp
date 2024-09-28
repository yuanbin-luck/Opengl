#include "Application.h"
#include <coreOpengl.h>
#include "GLShader.h"
#include "GLGeometry.h"
#include "GLTexture.h"


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
	glViewport(0,0,width,height);
	glClearColor(0, 0, 0,1);
	//bool isOk = InitVSync();
	//if (isOk) {
	//	SetVSyncState(false);
	//}

	shader = new GLShader("./assert/vs.glsl", "./assert/fs.glsl");
	geo = GLGeometry::createSphere(1,60);
	texture = new GLTexture("./assert/1.jpg",0);
}

GL::Application::~Application()
{

}

void GL::Application::exec()
{
	while (!glfwWindowShouldClose(m_window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		shader->use();
		texture->bind();
		float t =  glfwGetTime();
		glm::mat4 p = glm::perspective(45.0f, 1.0f,0.01f,1000.0f);
		glm::mat4 v = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0),glm::vec3(0,1,0));
		glm::mat4 m = glm::rotate(glm::mat4(1.0f), t, glm::vec3(0, 1, 0));
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		shader->setInt("sampler", 0);
		shader->setMat4("projection", p);
		shader->setMat4("view", v );
		shader->setMat4("model", m);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glDrawElements(GL_TRIANGLES, geo->m_number, GL_UNSIGNED_INT, 0);

		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}
	glfwTerminate();

}
