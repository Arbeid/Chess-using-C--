#pragma once
#include <GLEW\glew.h>

class StaticVertexBuffer
{
public:
	StaticVertexBuffer(void* data, size_t bytesize);
	~StaticVertexBuffer();

	void Bind();
private:
	unsigned int m_BufferID = 0;
};

class DynamicVertexBuffer
{
public:
	DynamicVertexBuffer(void* data, size_t bytesize);
	~DynamicVertexBuffer();

	void Bind();
private:
	unsigned int m_BufferID = 0;
};

void UnbindVertexBuffer();