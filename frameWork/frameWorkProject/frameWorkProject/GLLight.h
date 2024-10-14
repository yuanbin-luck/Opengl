#pragma once
#include "GLNode.h"

namespace GL {
	class GLLight :public GLNode
	{
	public:
		enum LightType
		{
			LT_None,           //无效
			LT_Point,          //点光源
			LT_Direct,		   //定向光
			LT_Spot,		   //聚光
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

