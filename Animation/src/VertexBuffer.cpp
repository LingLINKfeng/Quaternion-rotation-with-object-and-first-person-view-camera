#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(GLfloat vertices[], GLfloat colors[], GLfloat coords[], GLint numVertices) :numVertices(numVertices), m_RendererID(0)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, numVertices * 9 * sizeof(GLfloat), nullptr, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, numVertices * 3 * sizeof(GLfloat), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, numVertices * 3 * sizeof(GLfloat), numVertices * 4 * sizeof(GLfloat), colors);
	glBufferSubData(GL_ARRAY_BUFFER, numVertices * 7 * sizeof(GLfloat), numVertices * 2 * sizeof(GLfloat), coords);
}

VertexBuffer::VertexBuffer(GLfloat vertices[], GLfloat coords[], GLint numVertices)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, numVertices * 5 * sizeof(GLfloat), nullptr, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, numVertices * 3 * sizeof(GLfloat), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, numVertices * 3 * sizeof(GLfloat), numVertices * 2 * sizeof(GLfloat), coords);
}

VertexBuffer::VertexBuffer(GLfloat vertices[], GLint size)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{

}

void VertexBuffer::Bind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::Unbind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
