#include "Log.h"

#ifdef PR_DEBUG
Log::LogLevel	Log::m_LogLevel = Log::LogLevel::Warning;
#elif PR_RELEASE
Log::LogLevel	Log::m_LogLevel = Log::LogLevel::Error;
#endif // DEBUG

void Log::SetLoggingLevel(LogLevel logginglevel) noexcept
{
	m_LogLevel = logginglevel;
}

void Log::Fatal(const char* message)
{
	switch (m_LogLevel)
	{
	case LogLevel::Warning:
	case LogLevel::Error:
	case LogLevel::Fatal:
	{
		const char* msglevel = "|FATAL]: ";
		std::string loggedmessage('[' + std::string(__TIME__) + msglevel + message + '\n');
		std::cerr << loggedmessage;
		exit(1);
		break;
	}
	case LogLevel::None:
		return void(0);
	}
}

void Log::Error(const char* message)
{
	switch (m_LogLevel)
	{
	case LogLevel::Warning:
	case LogLevel::Error:
	{
		const char* msglevel = "|ERROR]: ";
		std::string loggedmessage('[' + std::string(__TIME__) + msglevel + message + '\n');
		std::cerr << loggedmessage;
		__debugbreak();
		break;
	}
	case LogLevel::Fatal:
		return void(0);
	case LogLevel::None:
		return void(0);
	}
}

void Log::Warning(const char* message)
{
	switch (m_LogLevel)
	{
	case LogLevel::Warning:
	{
		const char* msglevel = "|WARNING]: ";
		std::string loggedmessage('[' + std::string(__TIME__) + msglevel + message + '\n');
		std::cerr << loggedmessage;
		break;
	}
	case LogLevel::Error:
		return void(0);
	case LogLevel::Fatal:
		return void(0);
	case LogLevel::None:
		return void(0);
	}
}

bool Log::GLError(const char* message, GLenum outcome)
{
	if (outcome != GLEW_OK)
	{
		const char* msglevel = "|ERROR]: ";
		std::string loggedmessage('[' + std::string(__TIME__) + msglevel + message + "\nDetails: ");
		std::cerr << loggedmessage << glewGetErrorString(outcome) << '\n';
		__debugbreak();
		return true;
	}
	return false;
}

void Log::GLFatal(const char* message, GLenum outcome)
{
	if (outcome != GLEW_OK)
	{
		const char* msglevel = "|FATAL]: ";
		std::string loggedmessage('[' + std::string(__TIME__) + msglevel + message + "\nDetails: ");
		std::cerr << loggedmessage << glewGetErrorString(outcome) << '\n';
		exit(1);
	}
}
