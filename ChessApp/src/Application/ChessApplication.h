#pragma once

class ChessApp
{
public:
	ChessApp();
	virtual ~ChessApp();

	void Run();
	virtual void Procedure() = 0;
private:
	bool m_IsRunning = true;
	bool m_IsPaused	 = false;
};