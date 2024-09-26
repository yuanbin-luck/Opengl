#pragma once

#include <coreOpengl.h>

namespace GL {

	class GLObject
	{
	public:
		GLObject( GLObject* parent = nullptr );

		~GLObject();

		GLObject* parent();

		glm::vec3 location();

		glm::vec3 rotate();

		float rotateX();

		float rotateY();

		float rotateZ();

		glm::vec3 scale();

		void setParent(GLObject* parent);

		void setLocation(const glm::vec3& loca);

		void setRotate(const glm::vec3& rotate);

		void setRotateX(float angle);

		void setRotateY(float angle);

		void setRotateZ(float angle);

		void setScale(const glm::vec3& scale);

	private:
		glm::vec3 m_scale;
		glm::vec3 m_rotate;
		glm::vec3 m_location;

		GLObject* m_parent;
	};

}
