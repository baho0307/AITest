#pragma once

#include <iostream>
#include <iomanip>

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
	Bug(int x, int y, DIR dir = UP);
	void	Move(DIR moveDir);
	void	DebugLOG();

private:
	int	m_X;
	int	m_Y;
	DIR	m_Dir;
};

