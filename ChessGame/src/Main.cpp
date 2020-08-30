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
	ChessApp* app = new ChessGame;
	app->Run();
	delete app;
}