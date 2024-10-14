#pragma once
#include "GLNode.h"

namespace GL {
	class GLLight :public GLNode
	{
	public:
		enum LightType
		{
			LT_None,           //��Ч
			LT_Point,          //���Դ
			LT_Direct,		   //�����
			LT_Spot,		   //�۹�
		};

		GLLight(const glm::vec4& lightColor = glm::vec4(1,1,1,1), GLObject* parent = nullptr);

		~GLLight();

		glm::vec4 lightColor();

		void setLightColor(const glm::vec4& lightColor);

	protected:
		LightType m_lightType;

	private:
		glm::vec4 m_lightColor;
	};
}

