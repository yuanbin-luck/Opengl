#pragma once

#include "GLObject.h"
namespace GL {

	class GLNode :public GLObject
	{
	public:
		GLNode(GLObject* parent = nullptr);

		~GLNode();



	};

}
