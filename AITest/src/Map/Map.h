#pragma once

#include <vector>
#include <random>

class Map
{
public:
	Map(int x, int y);
	Map();
	void							GenerateFood();
	std::vector<std::vector<char>>	GetMap();
private:
	std::vector<std::vector<char>> map;
	int	fX;
	int	fY;
	int	x;
	int	y;
};

