#include "GLGeometry.h"

using namespace GL;
GL::GLGeometry::GLGeometry(const std::vector<float>& vertexs
	, const std::vector<float>& normals
	, const std::vector<float>& uvs
	, const std::vector<int>& indexs)
{
	createVao(vertexs, normals, uvs, indexs);
}

GLGeometry* GL::GLGeometry::createCube(float radius)
{
	return nullptr;
}

GLGeometry* GL::GLGeometry::createSphere(float radius, int precision)
{
	return nullptr;
}

GLGeometry* GL::GLGeometry::createSurface(float radius)
{
	std::vector<float> vertexs;
	std::vector<float> normals;
	std::vector<float> uvs;
	std::vector<int> indexs;

	vertexs.push_back(-0.5);
	vertexs.push_back(-0.5);
	vertexs.push_back(0);

	vertexs.push_back(0.5);
	vertexs.push_back(-0.5);
	vertexs.push_back(0);

	vertexs.push_back(0.5);
	vertexs.push_back(0.5);
	vertexs.push_back(0);

	vertexs.push_back(-0.5);
	vertexs.push_back(0.5);
	vertexs.push_back(0);

	normals.push_back(0);
	normals.push_back(0);
	normals.push_back(1);

	normals.push_back(0);
	normals.push_back(0);
	normals.push_back(1);

	normals.push_back(0);
	normals.push_back(0);
	normals.push_back(1);

	normals.push_back(0);
	normals.push_back(0);
	normals.push_back(1);

	uvs.push_back(0);
	uvs.push_back(0);

	uvs.push_back(1);
	uvs.push_back(0);

	uvs.push_back(1);
	uvs.push_back(1);

	uvs.push_back(0);
	uvs.push_back(1);

	indexs.push_back(0);
	indexs.push_back(1);
	indexs.push_back(2);

	indexs.push_back(2);
	indexs.push_back(3);
	indexs.push_back(1);

	GLGeometry* geometry = new GLGeometry(vertexs, normals, uvs, indexs);
	return geometry;
}

void GL::GLGeometry::createVao(const std::vector<float>& vertexs
	, const std::vector<float>& normals
	, const std::vector<float>& uvs
	, const std::vector<int>& indexs)
{
	GLuint vbo[4];
	glGenBuffers(4, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, vertexs.size() * sizeof(float), vertexs.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float), normals.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(float), uvs.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexs.size() * sizeof(GLuint), indexs.data(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), 0);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), 0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[3]);
	m_number = indexs.size();
}
