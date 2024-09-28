#include "GLCallBack.h"
#include <coreOpengl.h>
#include "GLCamera.h"
#include "GLMaterial.h"
#include "GLShader.h"

void GL::GLCallBack::callback(GLCamera* camera, GLMaterial* material, GLShader* global)
{
	float t = glfwGetTime();
	glm::mat4 p = glm::perspective(45.0f, 1.0f, 0.01f, 1000.0f);
	glm::mat4 v = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 m = glm::rotate(glm::mat4(1.0f), t, glm::vec3(0, 1, 0));
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLShader* shader = global;
	if (material->getShader())
	{
		shader = material->getShader();
	}
	if (!shader) return;
	shader->setInt("sampler", 0);
	shader->setMat4("projection", p);
	shader->setMat4("view", v);
	shader->setMat4("model", m);
}