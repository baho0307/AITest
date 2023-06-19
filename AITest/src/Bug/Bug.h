#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

enum DIR
{
	LEFT = -1,
	RIGHT = 1,
	UP = 2,
	DOWN = -2,
	RANDOM = 3
};

class Bug
{
public:
	Bug();
	Bug(int x, int y, DIR dir = UP);
	void	Move(DIR moveDir);
	void	DebugLOG();
	int		GetX();
	int		GetY();
	DIR		GetDIR();
	std::vector<float>	Look(std::vector< std::vector<char>> map);	
	bool	foodFlag;

private:
	int		m_X;
	int		m_Y;
	DIR		m_Dir;
};

