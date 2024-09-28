#include "GLRender.h"
#include "GLGeometry.h"
#include "GLScense.h"
#include "GLShader.h"
#include "GLTexture.h"
#include "GLNode.h"
#include "GLMaterial.h"

GL::GLRender::GLRender()
{
}

GL::GLRender::~GLRender()
{

}

void GL::GLRender::setClearColor(float r, float g, float b, float a)
{
	glClearColor(r,g,b,a);
}

void GL::GLRender::render(GLuint frame, GLScense* scense)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	if (scense->m_global)
	{
		scense->m_global->use();
	}

	renderChilds(scense);

}

void GL::GLRender::renderChilds(GLObject* child)
{
	GLGeometry* geometry = child->getGeometry();
	if (!geometry) return;
	
	if (GLMaterial* material = child->getMaterial())
	{
		material->use();
		//float t = glfwGetTime();
		//glm::mat4 p = glm::perspective(45.0f, 1.0f, 0.01f, 1000.0f);
		//glm::mat4 v = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		//glm::mat4 m = glm::rotate(glm::mat4(1.0f), t, glm::vec3(0, 1, 0));
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//material->m_shader->setInt("sampler", 0);
		//material->m_shader->setMat4("projection", p);
		//material->m_shader->setMat4("view", v);
		//material->m_shader->setMat4("model", m);
	}

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glDrawElements(GL_TRIANGLES, geometry->m_number, GL_UNSIGNED_INT, 0);
}
