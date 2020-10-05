#pragma once
#include <vector>

#include <GLEW\glew.h>

class IndexBuffer
{
public:
	IndexBuffer(void* data, size_t bytesize);
	~IndexBuffer();

	void Bind();
private:
	unsigned int m_BufferID = 0;
};

void UnbindIndexBuffer();