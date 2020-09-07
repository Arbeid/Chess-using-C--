#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

#include "Logger\Log.h"
#include "Mouse\Mouse.h"

class ChessApp
{
public:
	ChessApp();
	virtual ~ChessApp();

	void Run();
	virtual void Procedure() = 0;

	bool OnMousePress(int button);
	bool OnMouseRelease(int button);
	bool OnMouseMove();

	std::pair<double, double> GetMousePos();

	GLFWwindow* GetWindow() { return m_Window; }
private:
	GLFWwindow* m_Window	= nullptr;

	bool m_IsRunning		= true;
	bool m_IsPaused			= false;

	Mouse m_Mouse;

	bool InitWindow();

	void InitCallbacks();

	friend void CloseWindowCallback(GLFWwindow* window);
	friend void FocusWindowCallback(GLFWwindow* window, int state);

	friend void MousePosCallback(GLFWwindow* window, double mx, double my);
	friend void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
};