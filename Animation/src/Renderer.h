#pragma once
#include<GL/glew.h>
#include"Shader.h"
#include"IndexBuffer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
class  Renderer
{
public:
	void Clear();
	void Draw(const IndexBuffer& ib, const Shader& shader);

};
