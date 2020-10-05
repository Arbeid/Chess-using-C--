#pragma once
#include <GLEW\glew.h>

#include "Logger\Log.h"

class Shader
{
public:
	Shader(const char* vssource, const char* pssource);
	~Shader();

	void Bind();
private:
	unsigned int m_ShaderID = 0;

	void CreateShaders(const char* vs, const char* fs);
	unsigned int CompileShader(const char* shader, GLenum type);
};

void UnbindShader();
