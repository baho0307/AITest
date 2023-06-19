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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-2, 2);
	int x = dis(gen);
	if (moveDir == LEFT || moveDir == RIGHT)
		m_X += moveDir;
	else if (moveDir == RANDOM)
		Move(DIR(x));
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
	foodFlag = false;
	std::vector<float>	lookData;
	float	f;
	int		i;
	// FRONT BARRIER
	i = m_Y - 1;
	f = 0;
	while (map[i][m_X] != '0' - 1)
	{
		f++;
		i--;
	}
	lookData.push_back(-1 / (f + 1));
	i = m_Y - 1;
	// FRONT FOOD
	while ((map[i][m_X] == '0'))
		i--;
	if (map[i][m_X] == '1')
	{
		lookData.push_back(1);
		foodFlag = true;
	}
	else
		lookData.push_back(0);
	// RIGHT BARRIER
	i = m_X + 1;
	f = 0;
	while (map[m_Y][i] != '0' - 1)
	{
		f++;
		i++;
	}
	lookData.push_back(-1 / (f + 1));
	// RIGHT FOOD
	i = m_X + 1;
	while (map[m_Y][i] == '0')
		i++;
	if (map[m_Y][i] == '1')
	{
		lookData.push_back(1);
		foodFlag = true;
	}
	else
		lookData.push_back(0);
	// LEFT BARRIER
	i = m_X - 1;
	f = 0;
	while (map[m_Y][i] != '0' - 1)
	{
		f++;
		i--;
	}
	lookData.push_back(-1 / (f + 1));
	// LEFT FOOD
	i = m_X - 1;
	while (map[m_Y][i] == '0')
		i--;
	if (map[m_Y][i] == '1')
	{
		lookData.push_back(1);
		foodFlag = true;
	}
	else
		lookData.push_back(0);
	// DOWN BARRIER
	i = m_Y - 1;
	f = 0;
	while ((map[i][m_X] != '0' - 1))
	{
		f++;
		i++;
	}
	lookData.push_back(-1 / (f + 1));
	// DOWN FOOD
	i = m_Y - 1;
	while (map[i][m_X] == '0')
		i++;
	if (map[i][m_X] == '1')
	{
		lookData.push_back(1);
		foodFlag = true;
	}
	else
		lookData.push_back(0);

	return lookData;
}

