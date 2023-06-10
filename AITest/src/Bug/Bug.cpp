#include "Bug.h"

Bug::Bug()
{
}

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

int Bug::GetX()
{
	return m_X;
}

int Bug::GetY()
{
	return m_Y;
}

std::vector<float> Bug::Look(std::vector< std::vector<char>> map)
{
	std::vector<float>	lookData;
	float	f;
	int		i;

	i = 0;
	f = 0;
	if (m_Dir == LEFT || m_Dir == RIGHT)
	{
		while ((map[m_Y][i] != '0' - 1 || map[m_Y][i] != '1') && i >= 0)
		{
			f++;
			i += m_Dir;
		}
		lookData.push_back(f * (map[m_Y][i] - '0'));
		f = 0;
		while ((map[i][m_X] != '0' - 1 || map[i][m_X] != '1') && i >= 0)
		{
			f++;
			i -= m_Dir;
		}
		lookData.push_back(f * (map[i][m_X] - '0'));
		f = 0;
		while ((map[i][m_X] != '0' - 1 || map[i][m_X] != '1') && i >= 0)
		{
			f++;
			i += m_Dir;
		}
		lookData.push_back(f * (map[i][m_X] - '0'));
	}
	else
	{
		while ((map[i][m_X] != '0' - 1 || map[i][m_X] != '1') && i >= 0)
		{
			f++;
			i += m_Dir / 2;
		}
		lookData.push_back(f * (map[i][m_X] - '0'));
		f = 0;
		while ((map[m_Y][i] != '0' - 1 || map[m_Y][i] != '1') && i >= 0)
		{
			f++;
			i -= m_Dir / 2;
		}
		lookData.push_back(f * (map[m_Y][i] - '0'));
		f = 0;
		while ((map[m_Y][i] != '0' - 1 || map[m_Y][i] != '1') && i >= 0)
		{
			f++;
			i += m_Dir / 2;
		}
		lookData.push_back(f * (map[m_Y][i] - '0'));
	}

	return lookData;
}

