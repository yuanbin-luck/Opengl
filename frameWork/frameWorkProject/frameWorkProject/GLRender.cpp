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
	renderChilds(scense, scense->m_global);
}

void GL::GLRender::renderChilds(GLObject* child, GLShader* global)
{
	GLGeometry* geometry = child->getGeometry();
	if (geometry)
	{
		if (GLMaterial* material = child->getMaterial())
		{
			material->use(NULL, global);
		}

		glBindVertexArray(geometry->m_vao);
		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_BACK);
		glDrawElements(GL_TRIANGLES, geometry->m_number, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	for (auto& node : child->m_childs)
	{
		renderChilds(node, global);
	}
}
