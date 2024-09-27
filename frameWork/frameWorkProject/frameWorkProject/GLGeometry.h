#pragma once

#include <coreOpengl.h>

namespace GL {

	class GLGeometry
	{
	public:
		GLGeometry(const std::vector<float>& vertexs
			, const std::vector<float>& normals
			, const std::vector<float>& uvs
			, const std::vector<int>& indexs);

		static GLGeometry* createCube(float radius);

		static GLGeometry* createSphere(float radius, int precision);

		static GLGeometry* createSurface(float radius);

	private:
		void createVao(const std::vector<float>& vertexs
			, const std::vector<float>& normals
			, const std::vector<float>& uvs
			, const std::vector<int>& indexs);

	public:
		GLuint m_vao;
		GLuint m_number;

	};
}
