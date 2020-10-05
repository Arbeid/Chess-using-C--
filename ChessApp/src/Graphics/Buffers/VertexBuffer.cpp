#include "VertexBuffer.h"

StaticVertexBuffer::StaticVertexBuffer(void* data, size_t bytesize)
{
	glGenBuffers(1, &m_BufferID);
	Bind();

	glBufferData(GL_ARRAY_BUFFER, bytesize, data, GL_STATIC_DRAW);
}

StaticVertexBuffer::~StaticVertexBuffer()
{
	UnbindVertexBuffer();
	glDeleteBuffers(1, &m_BufferID);
}

void StaticVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

///////////////////////////////////////////////////////////

DynamicVertexBuffer::DynamicVertexBuffer(void* data, size_t bytesize)
{
	glGenBuffers(1, &m_BufferID);
	Bind();

	glBufferData(GL_ARRAY_BUFFER, bytesize, data, GL_DYNAMIC_DRAW);
}

DynamicVertexBuffer::~DynamicVertexBuffer()
{
	UnbindVertexBuffer();
	glDeleteBuffers(1, &m_BufferID);
}

void DynamicVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

///////////////////////////////////////////////////////////

void UnbindVertexBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
