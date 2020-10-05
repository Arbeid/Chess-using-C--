#include "ChessApplication.h"

ChessApp::ChessApp()
{
	if (!InitWindow())
	{
		Log::Fatal("Failed to create window.");
	}

	if (GLenum e = glewInit() != GLEW_OK)
	{
		Log::GLFatal("Failed (glewInit)!.", e);
	}

	InitCallbacks();
}

ChessApp::~ChessApp()
{
	glfwDestroyWindow(m_Window);
}

void ChessApp::Run()
{
	while (m_IsRunning)
	{
		switch (m_IsPaused)
		{
		case false:
			Procedure();
			break;
		case true:
			break;
		}

		m_Mouse.Clear();
		glfwPollEvents();
	}
}

bool ChessApp::OnMousePress(int button)
{
	return m_Mouse.IsPress(button);
}

bool ChessApp::OnMouseRelease(int button)
{
	return m_Mouse.IsRelease(button);
}

bool ChessApp::OnMouseMove()
{
	return m_Mouse.IsMove();
}

std::pair<double, double> ChessApp::GetMousePos() noexcept
{
	return m_Mouse.GetPos();
}

bool ChessApp::InitWindow()
{
	m_Window = glfwCreateWindow(800, 600, "Chess", NULL, NULL);
	if (!m_Window)
	{
		return false;
	}

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	return true;
}

void CloseWindowCallback(GLFWwindow* window)
{
	auto app = reinterpret_cast<ChessApp*>(glfwGetWindowUserPointer(window));
	app->m_IsRunning = false;
}

void FocusWindowCallback(GLFWwindow* window, int state)
{
	auto app = reinterpret_cast<ChessApp*>(glfwGetWindowUserPointer(window));

	switch (state)
	{
	case GLFW_TRUE:
		app->m_IsPaused = false;
		break;
	case GLFW_FALSE:
		app->m_IsPaused = true;
		break;
	default:
		break;
	}
}

void MousePosCallback(GLFWwindow* window, double mx, double my)
{
	auto app = reinterpret_cast<ChessApp*>(glfwGetWindowUserPointer(window));

	app->m_Mouse.UpdatePos(mx, my);
}

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	auto app = reinterpret_cast<ChessApp*>(glfwGetWindowUserPointer(window));

	switch (action)
	{
	case GLFW_PRESS:
		app->m_Mouse.PushPress(button);
		break;
	case GLFW_RELEASE:
		app->m_Mouse.PushRelease(button);
		break;
	default:
		break;
	}
}

void ChessApp::InitCallbacks()
{
	glfwSetWindowCloseCallback(m_Window, CloseWindowCallback);
	glfwSetWindowFocusCallback(m_Window, FocusWindowCallback);

	glfwSetCursorPosCallback(m_Window, MousePosCallback);
	glfwSetMouseButtonCallback(m_Window, MouseButtonCallback);
}

///////////////////////////////////////////////////////////

void SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void SwapFrame(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}

void ClearFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
}