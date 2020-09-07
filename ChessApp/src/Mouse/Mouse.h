#pragma once
#include <vector>

class MouseButtonInput
{
public:
	MouseButtonInput(int button) noexcept
		:m_Button(button) {}

	int GetKey() const noexcept { return m_Button; }
private:
	int m_Button;
};

class Mouse
{
public:
	Mouse()
	{
		m_PressList.reserve(1024);
		m_ReleaseList.reserve(1024);
	}

	void PushPress(int button);
	void PushRelease(int button);
	void UpdatePos(double x, double y);

	bool	IsPress(int button);
	bool	IsRelease(int button);
	bool	IsMove();

	std::pair<double, double> GetPos();

	void Clear() noexcept;
private:
	std::vector<MouseButtonInput>	m_PressList;
	std::vector<MouseButtonInput>	m_ReleaseList;

	bool  m_MouseMoved = false;
	double m_MousePosX = 0.0;
	double m_MousePosY = 0.0;
};
