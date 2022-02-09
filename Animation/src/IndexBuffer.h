#pragma once
#include<GL/glew.h>
class IndexBuffer
{
public:
	IndexBuffer(GLuint* data, GLuint count);
	~IndexBuffer();
	void Bind() const;
	void Unbind();
	unsigned int GetCount()const;
private:
	GLuint m_RendererID;
	GLuint m_Count;
};

