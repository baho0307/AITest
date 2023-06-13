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

DIR Bug::GetDIR()
{
	return m_Dir;
}

std::vector<float> Bug::Look(std::vector< std::vector<char>> map)
{
	std::vector<float>	lookData;
	float	f;
	int		i;

	/*i = m_Y;
	f = 0;
	while ((map[i][m_X] == '0') && i >= 0)
	{
		f++;
		i += -1;
	}
	lookData.push_back((map[i][m_X] - '0') / f);
	i = m_X;
	f = 0;
	while ((map[m_Y][i] == '0') && i >= 0)
	{
		f++;
		i += 1;
	}
	lookData.push_back((map[i][m_X] - '0') / f);
	i = m_X;
	f = 0;
	while ((map[m_Y][i] == '0') && i >= 0)
	{
		f++;
		i += -1;
	}
	lookData.push_back((map[i][m_X] - '0') / f);
	i = m_Y;
	f = 0;
	while ((map[i][m_X] == '0') && i >= 0)
	{
		f++;
		i += -1;
	}
	lookData.push_back((map[i][m_X] - '0') / f);*/

	f = 0;
	if (m_Dir == LEFT || m_Dir == RIGHT)
	{
		i = m_X;
		while ((map[m_Y][i] == '0') && i >= 0)
		{
			f++;
			i += m_Dir;
		}
		lookData.push_back((map[m_Y][i] - '0') / f);
		f = 0;
		i = m_Y;
		while ((map[i][m_X] == '0') && i >= 0)
		{
			f++;
			i -= m_Dir;
		}
		lookData.push_back((map[i][m_X] - '0') / f);
		f = 0;
		i = m_Y;
		while ((map[i][m_X] == '0') && i >= 0)
		{
			f++;
			i += m_Dir;
		}
		lookData.push_back((map[i][m_X] - '0') / f);
	}
	else
	{
		i = m_Y;
		while ((map[i][m_X] == '0') && i >= 0)
		{
			f++;
			i -= m_Dir / 2;
		}
		lookData.push_back((map[i][m_X] - '0') / f);
		f = 0;
		i = m_X;
		while ((map[m_Y][i] == '0') && i >= 0)
		{
			f++;
			i -= m_Dir / 2;
		}
		lookData.push_back((map[m_Y][i] - '0') / f);
		f = 0;
		i = m_X;
		while ((map[m_Y][i] == '0') && i >= 0)
		{
			f++;
			i += m_Dir / 2;
		}
		lookData.push_back((map[m_Y][i] - '0') / f);
	}

	return lookData;
}

