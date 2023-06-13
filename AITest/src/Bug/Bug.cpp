#include "Bug.h"

Bug::Bug()
{
}

Bug::Bug(int x, int y, DIR dir)
{
	m_X = x;
	m_Y = y;
	m_Dir = dir;
	foodFlag = false;
}

void Bug::Move(DIR moveDir)
{
	if (moveDir == LEFT || moveDir == RIGHT)
		m_X += moveDir;
	else
		m_Y += moveDir / 2;
	m_Dir = moveDir;
}

void Bug::DebugLOG()
{
	//Logging the data of bug (its temp) : 
	std::cout << std::setw(10) << "X: " << m_X << std::endl;
	std::cout << std::setw(10) << "Y: " << m_Y << std::endl;
	std::cout << std::setw(10) << "DIR: " << DIR(m_Dir) << std::endl;
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
	// FRONT BARRIER
	i = m_Y;
	f = 0;
	while (map[i][m_X] != '0' - 1)
	{
		f++;
		i += -1;
	}
	lookData.push_back(-1 / f);
	i = m_Y;
	f = 0;
	// FRONT FOOD
	while ((map[i][m_X] == '0'))
	{
		f++;
		i += -1;
	}
	if (map[i][m_X] == '1')
	{
		lookData.push_back(1);
		foodFlag = true;
	}
	// RIGHT BARRIER
	i = m_X;
	f = 0;
	while (map[m_Y][i] != '0' - 1)
	{
		f++;
		i += 1;
	}
	lookData.push_back(-1 / f);
	// RIGHT FOOD
	i = m_X;
	f = 0;
	while (map[m_Y][i] == '0')
	{
		f++;
		i += 1;
	}
	if (map[m_Y][i] == '1')
	{
		lookData.push_back(1);
		foodFlag = true;
	}
	// LEFT BARRIER
	i = m_X;
	f = 0;
	while (map[m_Y][i] != '0' - 1)
	{
		f++;
		i += -1;
	}
	lookData.push_back(-1 / f);
	// LEFT FOOD
	i = m_X;
	f = 0;
	while (map[m_Y][i] == '0')
	{
		f++;
		i += -1;
	}
	if (map[m_Y][i] == '1')
	{
		lookData.push_back(1);
		foodFlag = true;
	}
	// DOWN BARRIER
	i = m_Y;
	f = 0;
	while ((map[i][m_X] != '0' - 1))
	{
		f++;
		i += 1;
	}
	lookData.push_back(-1 / f);
	// DOWN FOOD
	i = m_Y;
	f = 0;
	while (map[i][m_X] == '0')
	{
		f++;
		i += 1;
	}
	if (map[i][m_X] == '1')
	{
		lookData.push_back(1);
		foodFlag = true;
	}

	//f = 0;
	//if (m_Dir == LEFT || m_Dir == RIGHT)
	//{
	//	// FRONT
	//	i = m_X;
	//	while ((map[m_Y][i] == '0') && i >= 0)
	//	{
	//		f++;
	//		i += m_Dir;
	//	}
	//	lookData.push_back((map[m_Y][i] - '0') / f);
	//	f = 0;
	//	i = m_Y;
	//	// LEFT
	//	while ((map[i][m_X] == '0') && i >= 0)
	//	{
	//		f++;
	//		i -= m_Dir;
	//	}
	//	lookData.push_back((map[i][m_X] - '0') / f);
	//	f = 0;
	//	i = m_Y;
	//	// RIGHT
	//	while ((map[i][m_X] == '0') && i >= 0)
	//	{
	//		f++;
	//		i += m_Dir;
	//	}
	//	lookData.push_back((map[i][m_X] - '0') / f);
	//}
	//else
	//{
	//	// FRONT
	//	i = m_Y;
	//	while ((map[i][m_X] == '0') && i >= 0)
	//	{
	//		f++;
	//		i -= m_Dir / 2;
	//	}
	//	lookData.push_back((map[i][m_X] - '0') / f);
	//	f = 0;
	//	i = m_X;
	//	// LEFT
	//	while ((map[m_Y][i] == '0') && i >= 0)
	//	{
	//		f++;
	//		i -= m_Dir / 2;
	//	}
	//	lookData.push_back((map[m_Y][i] - '0') / f);
	//	f = 0;
	//	i = m_X;
	//	// RIGHT
	//	while ((map[m_Y][i] == '0') && i >= 0)
	//	{
	//		f++;
	//		i += m_Dir / 2;
	//	}
	//	lookData.push_back((map[m_Y][i] - '0') / f);
	//}
	return lookData;
}

