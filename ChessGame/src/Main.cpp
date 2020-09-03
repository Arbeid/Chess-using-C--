#include "ChessApp.h"

class ChessGame : public ChessApp
{
public:
	ChessGame()
	{

	}

	~ChessGame()
	{

	}

	void Procedure() override
	{

	}
private:
};


int main()
{
	if (!glfwInit())
	{
		Log::Fatal("GLFW Failed to initialize.");
		return 1;
	}

	ChessApp* app = new ChessGame;
	app->Run();
	delete app;

	glfwTerminate();
}