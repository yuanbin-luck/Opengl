#pragma once

#include "GLObject.h"
namespace GL {

	class GLGeometry;
	class GLMaterial;
	class GLNode :public GLObject
	{
	public:
		GLNode(GLObject* parent = nullptr);

		GLNode(GLGeometry* geometry , GLMaterial* material, GLObject* parent = nullptr);

		~GLNode();

	protected:
		virtual GLGeometry* getGeometry() override;

		virtual GLMaterial* getMaterial() override;

	private:
		GLGeometry* m_geometry;
		GLMaterial* m_material;

	};

}
