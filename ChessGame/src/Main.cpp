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
		std::cerr << "[FATAL]: GLFW Failed to initialize.\n";
		return 1;
	}

	ChessApp* app = new ChessGame;
	app->Run();
	delete app;

	glfwTerminate();
}