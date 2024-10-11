#include "GLLightCallBack.h"
#include <coreOpengl.h>
#include "GLCamera.h"
#include "GLMaterial.h"
#include "GLShader.h"
#include "GLPointLight.h"
#include "GLObject.h"

void GL::GLLightCallBack::callback(GLCamera* camera, GLObject* obj, GLMaterial* material, GLShader* global, const std::list<GLLight*>& lights)
{
	float t = glfwGetTime();
	glm::mat4 p = glm::perspective(45.0f, 1.0f, 0.01f, 1000.0f);
	glm::mat4 v = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 m = glm::mat4(1.0f);
	m = glm::translate(glm::mat4(1.0f), obj->location());
	//m = glm::rotate(glm::mat4(1.0f), t*0.4f , glm::vec3(0, 1, 0)) * m;

	glm::vec3 scale, trans, skew;
	glm::vec4 persp;
	glm::quat qua;
	glm::decompose(m, scale, qua, trans, skew, persp);
	glm::mat4 r = glm::toMat4(qua);
	glm::vec3 rotate;
	glm::extractEulerAngleXYX(r, rotate.x, rotate.y, rotate.z);
	rotate.x = glm::degrees(rotate.x);
	rotate.y = glm::degrees(rotate.y);
	rotate.z = glm::degrees(rotate.z);
	//lights.front()->setLocation(trans);


	GLShader* shader = NULL;
	if (material->getShader())
	{
		shader = material->getShader();
	}
	if (!shader) return;
	shader->setMat4("projection", p);
	shader->setMat4("view", v);
	shader->setMat4("model", m);
}
