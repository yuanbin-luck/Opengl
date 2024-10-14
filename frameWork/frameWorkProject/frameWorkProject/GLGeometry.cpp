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

	float vertices[] = {
		// positions        
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
	};

	float nor[] = {
		// normals         
		0.0f,  0.0f, -1.0f,
		0.0f,  0.0f, -1.0f,
		0.0f,  0.0f, -1.0f,
		0.0f,  0.0f, -1.0f,
		0.0f,  0.0f, -1.0f,
		0.0f,  0.0f, -1.0f,

		0.0f,  0.0f,  1.0f,
		0.0f,  0.0f,  1.0f,
		0.0f,  0.0f,  1.0f,
		0.0f,  0.0f,  1.0f,
		0.0f,  0.0f,  1.0f,
		0.0f,  0.0f,  1.0f,

		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,

		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,

		0.0f, -1.0f,  0.0f,
		0.0f, -1.0f,  0.0f,
		0.0f, -1.0f,  0.0f,
		0.0f, -1.0f,  0.0f,
		0.0f, -1.0f,  0.0f,
		0.0f, -1.0f,  0.0f,

		0.0f,  1.0f,  0.0f,
		0.0f,  1.0f,  0.0f,
		0.0f,  1.0f,  0.0f,
		0.0f,  1.0f,  0.0f,
		0.0f,  1.0f,  0.0f,
		0.0f,  1.0f,  0.0f,
	};

	float tex[] = {
		// texture coords
		0.0f,  0.0f,
		1.0f,  0.0f,
		1.0f,  1.0f,
		1.0f,  1.0f,
		0.0f,  1.0f,
		0.0f,  0.0f,

		0.0f,  0.0f,
		1.0f,  0.0f,
		1.0f,  1.0f,
		1.0f,  1.0f,
		0.0f,  1.0f,
		0.0f,  0.0f,

		1.0f,  0.0f,
		1.0f,  1.0f,
		0.0f,  1.0f,
		0.0f,  1.0f,
		0.0f,  0.0f,
		1.0f,  0.0f,

		1.0f,  0.0f,
		1.0f,  1.0f,
		0.0f,  1.0f,
		0.0f,  1.0f,
		0.0f,  0.0f,
		1.0f,  0.0f,

		0.0f,  1.0f,
		1.0f,  1.0f,
		1.0f,  0.0f,
		1.0f,  0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f,

		0.0f,  1.0f,
		1.0f,  1.0f,
		1.0f,  0.0f,
		1.0f,  0.0f,
		0.0f,  0.0f,
		0.0f,  1.0f
	};


	std::vector<float> vertexs;
	std::vector<float> normals;
	std::vector<float> uvs;
	std::vector<int> indexs;

	for (int i = 0; i < sizeof(vertices); i++)
	{
		vertexs.push_back(vertices[i]);
	}
	for (int i = 0; i < sizeof(nor); i++)
	{
		normals.push_back(nor[i]);
	}	
	for (int i = 0; i < sizeof(tex); i++)
	{
		uvs.push_back(tex[i]);
	}
	indexs.push_back(2);
	indexs.push_back(1);
	indexs.push_back(0);
	indexs.push_back(3);
	indexs.push_back(5);
	indexs.push_back(4);

	indexs.push_back(6);
	indexs.push_back(7);
	indexs.push_back(8);
	indexs.push_back(11);
	indexs.push_back(9);
	indexs.push_back(10);


	//indexs.push_back(12);
	//indexs.push_back(13);
	//indexs.push_back(14);
	//indexs.push_back(17);
	//indexs.push_back(16);
	//indexs.push_back(15);

	//indexs.push_back(20);
	//indexs.push_back(19);
	//indexs.push_back(18);
	//indexs.push_back(21);
	//indexs.push_back(22);
	//indexs.push_back(23);


	//indexs.push_back(24);
	//indexs.push_back(25);
	//indexs.push_back(26);
	//indexs.push_back(29);
	//indexs.push_back(28);
	//indexs.push_back(27);

	//indexs.push_back(32);
	//indexs.push_back(31);
	//indexs.push_back(30);
	//indexs.push_back(33);
	//indexs.push_back(34);
	//indexs.push_back(35);

	GLGeometry* geometry = new GLGeometry(vertexs, normals, uvs, indexs);
	return geometry;
}

GLGeometry* GL::GLGeometry::createSphere(float radius, int precision)
{
	std::vector<float> vertexs;
	std::vector<float> normals;
	std::vector<float> uvs;
	std::vector<int> indexs;

	int Lat = precision;
	int Long = precision;
	for (int i = 0; i <= Lat; i++)
	{
		float phi = glm::pi<float>() / float(Lat) * float(i);
		for (int j = 0; j <= Long; j++)
		{
			float theta = 2.0f * glm::pi<float>() / float(Long) * float(j);

			float x = radius * sin(phi) * cos(theta);
			float y = radius * cos(phi);
			float z = radius * sin(phi) * sin(theta);

			vertexs.push_back(x);
			vertexs.push_back(y);
			vertexs.push_back(z);

			normals.push_back(x);
			normals.push_back(y);
			normals.push_back(z);

			float u =  float(j) / float(Long);
			float v = float(i) / float(Lat);
			uvs.push_back(u);
			uvs.push_back(v);
		}
	}

	for (int i = 0; i < Lat; i++)
	{
		for (int j = 0; j < Long; j++)
		{
			int p1 = i * (Long + 1) + j;
			int p2 = p1 + Long + 1;
			int p3 = p1 + 1;
			int p4 = p2 + 1;

			indexs.push_back(p1);
			indexs.push_back(p2);
			indexs.push_back(p4);

			indexs.push_back(p4);
			indexs.push_back(p3);
			indexs.push_back(p1);
		}
	}

	GLGeometry* geometry = new GLGeometry(vertexs, normals, uvs, indexs);
	return geometry;
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
	indexs.push_back(0);

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
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), 0);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), 0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[3]);
	glBindVertexArray(0);
	m_number = indexs.size();
}
