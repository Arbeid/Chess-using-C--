#include "ChessApplication.h"

ChessApp::ChessApp()
{
	if (!glewInit())
	{

	}
}

ChessApp::~ChessApp()
{

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
	}
}
