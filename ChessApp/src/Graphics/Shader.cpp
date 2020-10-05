#include "Shader.h"

Shader::Shader(const char* vssource, const char* fssource)
{
	m_ShaderID = glCreateProgram();
	CreateShaders(vssource, fssource);

	int link_status = 0;
	glGetProgramiv(m_ShaderID, GL_LINK_STATUS, &link_status);

	if (link_status != GL_TRUE)
	{
		int length = 0;
		char message[1024];
		glGetProgramInfoLog(m_ShaderID, 1024, &length, message);
		Log::Error(std::string((char*)message).c_str());
		glDeleteProgram(m_ShaderID);
	}
	else
	{
		Bind();
	}
}

Shader::~Shader()
{
	UnbindShader();
	glDeleteProgram(m_ShaderID);
}

void Shader::Bind()
{
	glUseProgram(m_ShaderID);
}

void Shader::CreateShaders(const char* vs, const char* fs)
{
	unsigned int vshader = CompileShader(vs, GL_VERTEX_SHADER);
	unsigned int fshader = CompileShader(fs, GL_FRAGMENT_SHADER);

	glAttachShader(m_ShaderID, vshader);
	glAttachShader(m_ShaderID, fshader);

	glLinkProgram(m_ShaderID);
	glValidateProgram(m_ShaderID);

	glDeleteShader(vshader);
	glDeleteShader(fshader);
}

unsigned int Shader::CompileShader(const char* shader, GLenum type)
{
	unsigned int id = glCreateShader(type);
	glShaderSource(id, 1, &shader, nullptr);
	glCompileShader(id);

	int compile_status = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &compile_status);

	if (compile_status != GL_TRUE)
	{
		int length = 0;
		char message[1024];
		glGetShaderInfoLog(id, 1024, &length, message);
		Log::Error(std::string((char*)message).c_str());
		glDeleteShader(id);

		return 0;
	}
	else
	{
		return id;
	}
}

///////////////////////////////////////////////////////////

void UnbindShader()
{
	glUseProgram(0);
}
