#pragma once

#include "./glad/include/glad.h"
#include "./glfw3.4/include/glfw3.h"
#include "./glm/include/glm.hpp"

#include "./glm/include/gtc/matrix_transform.hpp"
#include "./glm/include/ext/matrix_clip_space.hpp"
#include "./glm/include/gtc/type_ptr.hpp"


#include <iostream>
using namespace std;

#if _DEBUG

#pragma comment(lib, "C:/Tools/Opengl/glad/lib/gladd.lib")
#pragma comment(lib,  "C:/Tools/Opengl/glfw3.4/lib/glfw3d.lib")
#pragma comment(lib,  "C:/Tools/Opengl/glm/lib/glmd.lib")
#else

#pragma comment(lib, "C:/Tools/Opengl/glad/lib/glad.lib")
#pragma comment(lib,  "C:/Tools/Opengl/glfw3.4/lib/glfw3.lib")
#pragma comment(lib,  "C:/Tools/Opengl/glm/lib/glm.lib")


#endif