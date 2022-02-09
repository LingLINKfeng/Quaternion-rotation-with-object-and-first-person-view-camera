#pragma once
#include <GL/glew.h>
class VertexBuffer {
private:
	GLuint m_RendererID;
	GLuint numVertices;
public:
	VertexBuffer(GLfloat vertices[], GLfloat colors[], GLfloat coords[], GLint numVertices);
	VertexBuffer(GLfloat vertices[], GLfloat colors[], GLint numVertices);
	VertexBuffer(GLfloat vertices[], GLint size);
	~VertexBuffer();

	void Bind()const;
	void Unbind()const;
};