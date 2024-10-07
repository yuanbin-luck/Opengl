#pragma once
#include "GLLight.h"

//距离	    常数项	一次项	二次项
//7			1.0	    0.7	    1.8
//13	    1.0	    0.35	0.44
//20	    1.0	    0.22	0.20
//32	    1.0	    0.14	0.07
//50	    1.0	    0.09	0.032
//65	    1.0	    0.07	0.017
//100	    1.0	    0.045	0.0075
//160	    1.0	    0.027	0.0028
//200	    1.0	    0.022	0.0019
//325	    1.0	    0.014	0.0007
//600	    1.0	    0.007	0.0002
//3250	    1.0	    0.0014	0.000007

//点光源光照强度算法 f(dt) = 1.0 / (K + K1∗d + K2∗d^2);

namespace GL {
	class GLPointLight :public GLLight
	{
	public:
		GLPointLight(const glm::vec3& lightPos = glm::vec3(1,1,1), const glm::vec4& lightColor = glm::vec4(1, 1, 1, 1), GLObject* parent = nullptr);

		~GLPointLight();

		void getLightK(float& k, float& k1, float& k2);

		void setEffectRange(float distence = 7.0);

	private:
		float m_k, m_k1, m_k2;

		glm::vec3 m_lightPos;

	};

}
