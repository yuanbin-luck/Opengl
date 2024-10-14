#include "GLCallBack.h"
#include <coreOpengl.h>
#include "GLCamera.h"
#include "GLMaterial.h"
#include "GLShader.h"
#include "GLPointLight.h"
#include "GLObject.h"
#include "GLSpotLight.h"

void GL::GLCallBack::callback(GLCamera* camera, GLObject* obj, GLMaterial* material, GLShader* global, const list<GLLight*>& lights)
{
	float t = glfwGetTime();
	glm::mat4 p = glm::perspective(45.0f, 1.0f, 0.01f, 1000.0f);
	glm::mat4 v = glm::lookAt(glm::vec3(0, 0, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	//glm::mat4 m = glm::mat4(1.0f);
	glm::mat4 m = glm::translate(glm::mat4(1.0f), obj->location());//glm::vec3(10,10,0) 
	//m = glm::rotate(m, t*0.5f, glm::vec3(0,1 ,0));
	//m = glm::rotate(m, glm::radians(45.0f), glm::vec3(1, 0, 0));

	GLShader* shader = global;
	if (material->getShader())
	{
		shader = material->getShader();
	}
	if (!shader) return;
	shader->setMat4("projection", p);
	shader->setMat4("view", v);
	shader->setMat4("model", m);
	
	if (GLPointLight* plight = static_cast<GLPointLight*>(lights.front()))
	{
		glm::vec3 k;
		plight->getLightK(k.x, k.y, k.z);
		shader->setVec3("k", k);
		shader->setVec3("lightpos", plight->location());
		shader->setVec4("lightColor", plight->lightColor());
		shader->setVec3("viewPos", glm::vec3(0, 0, 20));
	}	
	else if (GLSpotLight* plight = static_cast<GLSpotLight*>(lights.front()))
	{
		shader->setFloat("spot.inAngle", glm::radians(plight->m_inTha));
		shader->setFloat("spot.outAngle", glm::radians(plight->m_outTha));
		shader->setVec3("spot.lightDir", plight->m_direct);
		shader->setVec3("spot.lightPos", plight->m_lightPos);
		shader->setVec3("spot.lightColor", plight->lightColor());
		//glm::vec3 k;
		//shader->setVec3("k", k);
		//shader->setVec3("lightpos", plight->location());
		//shader->setVec4("lightColor", plight->lightColor());
		//shader->setVec3("viewPos", glm::vec3(0, 0, 20));
	}
}