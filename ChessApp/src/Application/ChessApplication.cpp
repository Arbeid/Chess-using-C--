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
}

ChessApp::~ChessApp()
{
	glfwDestroyWindow(m_Window);
}

void ChessApp::Run()
{
	while (!glfwWindowShouldClose(m_Window))
	{
		switch (m_IsPaused)
		{
		case false:
			Procedure();
			break;
		case true:
			break;
		}

		glfwPollEvents();
	}
}

bool ChessApp::InitWindow()
{
	m_Window = glfwCreateWindow(800, 600, "Chess", NULL, NULL);
	if (!m_Window)
	{
		return false;
	}

	glfwMakeContextCurrent(m_Window);
	return true;
}
