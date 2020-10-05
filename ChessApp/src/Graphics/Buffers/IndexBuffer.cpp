#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(void* data, size_t size)
{
	glGenBuffers(1, &m_BufferID);
	Bind();

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(sizeof(unsigned int)), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
}

///////////////////////////////////////////////////////////

void UnbindIndexBuffer()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
