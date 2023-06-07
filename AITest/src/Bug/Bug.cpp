#include "Bug.h"

Bug::Bug(int x, int y, DIR dir)
{
	m_X = x;
	m_Y = y;
	m_Dir = dir;
}

void Bug::Move(DIR moveDir)
{
	if (moveDir == m_Dir)
	{
		if (moveDir == LEFT || moveDir == RIGHT)
			m_X += moveDir;
		else
			m_Y += moveDir / 2;
	}
	else
		m_Dir = moveDir;
}

void Bug::DebugLOG()
{
	//Logging the data of bug (its temp) : 
	std::cout << std::setw(6) << "X: " << m_X << std::endl;
	std::cout << std::setw(6) << "Y: " << m_Y << std::endl;
	std::cout << std::setw(6) << "DIR: " << DIR(m_Dir) << std::endl;
}

