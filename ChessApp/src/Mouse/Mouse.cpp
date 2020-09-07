#include "Mouse.h"

void Mouse::PushPress(int button)
{
	m_PressList.push_back(button);
}

void Mouse::PushRelease(int button)
{
	m_ReleaseList.push_back(button);
}

void Mouse::UpdatePos(double x, double y)
{
	m_MousePosX = x; m_MousePosY = y; m_MouseMoved = true;
}

bool Mouse::IsPress(int button)
{
	for (auto b : m_ReleaseList)
	{
		if (button == b.GetKey())
		{
			return true;
		}
	}
	return false;
}

bool Mouse::IsRelease(int button)
{
	for (auto b : m_ReleaseList)
	{
		if (button == b.GetKey())
		{
			return true;
		}
	}
	return false;
}

bool Mouse::IsMove()
{
	return m_MouseMoved;
}

std::pair<double, double> Mouse::GetPos()
{
	return { m_MousePosX, m_MousePosY };
}

void Mouse::Clear() noexcept
{
	m_PressList.clear();
	m_ReleaseList.clear();

	m_MouseMoved = false;
}
