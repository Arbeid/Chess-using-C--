#include "ChessApp.h"

static const char* s_VertexShader = R"(
#version 330 core

layout (location = 0) in vec4 Position;
layout (location = 1) in vec3 Color;

void main()
{
	gl_Position = Position;
}
)";

static const char* s_FragmentShader = R"(
#version 330 core

layout(location = 0) out vec4 FragColor;

void main()
{
	FragColor = vec4(1.0f,0.0f,0.0f,1.0f);
}
)";

class ChessGame : public ChessApp
{
public:
	Shader ShaderProgram;

	ChessGame()
		:ShaderProgram(s_VertexShader, s_FragmentShader)
	{
		SetClearColor(0.2f, 0.2f, 0.2f, 1.0f);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
	}

	~ChessGame()
	{
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}

	void Procedure() override
	{
		ClearFrame();

		SwapFrame(GetWindow());
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