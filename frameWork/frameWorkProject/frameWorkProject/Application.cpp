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
#include "GLSpotLight.h"

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


GL::Application* GL::Application::m_self = nullptr;
GL::Application::Application(int width, int height, const char* title):m_window(nullptr)
{
	m_self = this;
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
	
	glfwSetMouseButtonCallback(m_window, mousebuttonfun);
	
	glDebugMessageCallback(errorCalback, NULL);
	glDebugMessageControl(GL_TRUE, GL_TRUE, GL_TRUE,1,NULL,GL_TRUE);


	m_render = new GLRender();
	m_scense = new GLScense(nullptr);
	m_scense->addLight(new GLSpotLight(glm::vec3(0, 0, 10)));
	//addRoot(new GLNode(GLGeometry::createSphere(1,60) \
		, new GLMaterial(new GLShader("./assert/vs.glsl", "./assert/fs.glsl"),new GLTexture("./assert/1.jpg",0))));
	///addRoot(new GLNode(GLGeometry::createCube(1), new GLMaterial()));

	{
		GLNode* root = new GLNode(GLGeometry::createSphere(1, 60) \
			, new GLMaterial(new GLShader("./assert/vs.glsl", "./assert/fs.glsl"), new GLTexture("./assert/1.jpg", 0)));

		vector<glm::vec3> locas{ 
			glm::vec3(0,10,0),
			glm::vec3(5,0,0),
			glm::vec3(0,3,0),
			glm::vec3(0,7,0),
			glm::vec3(0,0,9),
			glm::vec3(4,10,4),
			glm::vec3(10,2,0),
			glm::vec3(4,4,5),
			glm::vec3(3,4,7),
			glm::vec3(-5,1,-4),
			glm::vec3(1,8,3),
		};

		for (int i = 0; i < 10; i++)
		{
			GLNode* node = new GLNode(GLGeometry::createSphere(1, 60) \
				, new GLMaterial(new GLShader("./assert/vs.glsl", "./assert/fs.glsl"), new GLTexture("./assert/1.jpg", 0)));

			node->setLocation(locas[i]);
			root->addChild(node);
		}
		addRoot(root);
	}
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

void GL::Application::mousebuttonfun(GLFWwindow* window, int button, int action, int mods)
{
	if (button == 0 && action == GLFW_PRESS)
	{
		double xpos = 0, ypos = 0;
		glfwGetCursorPos(m_self->m_window, &xpos, &ypos);
		glm::mat4 p = glm::perspective(45.0f, 1.0f, 0.01f, 1000.0f);
		glm::mat4 v = glm::lookAt(glm::vec3(0, 0, 60), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		glm::mat4 m = glm::mat4(1.0f);

		double x = ((xpos / 800.0) * 2.0 ) - 1.0;
		double y = (((600.0 - ypos) / 600.0) * 2.0 ) - 1.0;

		glm::vec3 nds = glm::vec3(x, y, 1.0f);
		glm::vec4 clip = glm::vec4(nds, 1.0f);
		glm::vec4 eye = glm::inverse(p) * clip;
		glm::vec4 word = glm::inverse(v) * eye;
		if (word.w != 0)
		{
			word.x /= word.w;
			word.y /= word.w;
			word.z /= word.w;
		}
		cout << glm::to_string(p) << "\n";

		cout << "X: " << x << "  Y:" << y 
			<<"   Word Loca: (" << word.x  <<"," << word.y<< ")\n";
		int a = 0;
	}

}

void GL::Application::errorCalback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	cout << "source: " << source << "  type:" << type
		<< "   id:" << id << "     severity:" << severity << "     length:"<< length<<"   message:"<<string(message)<<"\n";
}
