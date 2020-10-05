#pragma once
#include <iostream>

#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include "Logger\Log.h"

#include "Graphics\Shader.h"
#include "Graphics\Buffers\VertexBuffer.h"
#include "Graphics\Buffers\IndexBuffer.h"
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

	std::pair<double, double> GetMousePos() noexcept;

	GLFWwindow* GetWindow() noexcept { return m_Window; }
private:
	GLFWwindow* m_Window	= nullptr;
	Mouse		m_Mouse;

	bool m_IsRunning		= true;
	bool m_IsPaused			= false;

	bool InitWindow();

	void InitCallbacks();

	friend void CloseWindowCallback(GLFWwindow* window);
	friend void FocusWindowCallback(GLFWwindow* window, int state);

	friend void MousePosCallback(GLFWwindow* window, double mx, double my);
	friend void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
};

void SetClearColor(float r, float g, float b, float a);

void SwapFrame(GLFWwindow* window);
void ClearFrame();