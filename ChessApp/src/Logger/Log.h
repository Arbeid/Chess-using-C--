#pragma once
#include <iostream>
#include <string>
#include <GLEW\glew.h>

class Log
{
public:
	enum class LogLevel
	{
		None = -1,
		Fatal, Error, Warning
	};
	static void SetLoggingLevel(LogLevel logginglevel) noexcept;

	static void Fatal(const char* message);
	static void Error(const char* message);
	static void Warning(const char* message);

	static bool GLError(const char* message, GLenum outcome);
	static void GLFatal(const char* message, GLenum outcome);
private:
	static LogLevel	m_LogLevel;
};

