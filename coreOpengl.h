#pragma once


#include "./glad/include/glad.h"
#include "./glfw3.4/include/glfw3.h"
#include "./glm/include/glm.hpp"

#include "./glm/include/gtc/matrix_transform.hpp"
#include "./glm/include/ext/matrix_clip_space.hpp"
#include "./glm/include/gtc/type_ptr.hpp"

#include <string>
#include <vector>
#include <list>
#include <iostream>
using namespace std;


#if _DEBUG


#pragma comment(lib,  "./../../../glad/lib/gladd.lib")
#pragma comment(lib,  "./../../../glfw3.4/lib/glfw3d.lib")
#pragma comment(lib,  "./../../../glm/lib/glmd.lib")
#else

#pragma comment(lib,  "./../../../glad/lib/glad.lib")
#pragma comment(lib,  "./../../../glfw3.4/lib/glfw3.lib")
#pragma comment(lib,  "./../../../glm/lib/glm.lib")


#endif

//stbi头文件使用是直接在cpp文件中定义宏，包含.h
