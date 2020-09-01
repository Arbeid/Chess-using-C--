#include "ChessApplication.h"

ChessApp::ChessApp()
{
	if (!InitWindow())
	{
		std::cerr << "[FATAL]: Failed to create window.\n";
	}

	if (GLenum e = glewInit() != GLEW_OK)
	{
		std::cerr << "[FATAL]: " << glewGetErrorString(e) << ".\n";
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
		glClear(GL_COLOR_BUFFER_BIT);

		switch (m_IsPaused)
		{
		case false:
			Procedure();
			break;
		case true:
			break;
		}

		glfwSwapBuffers(m_Window);
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
