#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

enum DIR
{
	LEFT	= -1,
	RIGHT	= 1,
	UP		= 2,
	DOWN	= -2
};

class Bug
{
public:
	Bug();
	Bug(int x, int y, DIR dir = UP);
	void	Move(DIR moveDir);
	void	DebugLOG();
	std::vector<float>	Look(std::vector< std::vector<char>> map);

private:
	int		m_X;
	int		m_Y;
	DIR		m_Dir;
};

