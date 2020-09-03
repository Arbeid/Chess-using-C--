#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

#include "Logger\Log.h"

class ChessApp
{
public:
	ChessApp();
	virtual ~ChessApp();

	void Run();
	virtual void Procedure() = 0;

	GLFWwindow* GetWindow() { return m_Window; }
private:
	GLFWwindow* m_Window	= nullptr;
	bool m_IsPaused			= false;

	bool InitWindow();
};