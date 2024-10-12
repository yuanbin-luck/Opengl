#include "GLRender.h"
#include "GLGeometry.h"
#include "GLScense.h"
#include "GLShader.h"
#include "GLTexture.h"
#include "GLNode.h"
#include "GLMaterial.h"
#include "GLCallBack.h"
#include "GLLight.h"


#include <functional>

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

	renderLights(scense->getLights());

	renderChilds(scense, scense->m_global, scense->getLights());
}

void GL::GLRender::renderLights(const list<GLLight*>& lights)
{
	for (auto& node : lights)
	{
		renderLight(node);
	}

}

void GL::GLRender::renderChilds(GLObject* child, GLShader* globalShader, const list<GLLight*>& lights)
{
	GLGeometry* geometry = child->getGeometry();
	if (geometry)
	{
		if (GLMaterial* material = child->getMaterial())
		{
			material->use(NULL, child, globalShader, lights);
		}

		glBindVertexArray(geometry->m_vao);
		glFrontFace(GL_CW);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//glDisable(GL_CULL_FACE);
		glDrawElements(GL_TRIANGLES, geometry->m_number, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	for (auto& node : child->m_childs)
	{
		renderChilds(node, globalShader, lights);
	}
}

void GL::GLRender::renderLight(GLObject* light)
{
	GLGeometry* geometry = light->getGeometry();
	if (geometry)
	{
		if (GLMaterial* material = light->getMaterial())
		{
			material->use(NULL, light, NULL, { static_cast<GLLight*>(light)});
		}
		glBindVertexArray(geometry->m_vao);
		glFrontFace(GL_CW);
		glEnable(GL_CULL_FACE);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glCullFace(GL_BACK);
		glDrawElements(GL_TRIANGLES, geometry->m_number, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	for (auto& child : light->getChilds())
	{
		renderLight(child);
	}
}

