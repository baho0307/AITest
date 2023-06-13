#include "Map.h"

Map::Map(int x, int y)
{
	int	i;
	int	j;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disx(1, x - 2);
	std::uniform_int_distribution<> disy(1, y - 2);
	fX = disx(gen);
	fY = disy(gen);

	i = 0;
	while (i < y)
	{
		j = 0;
		map.push_back(std::vector<char>());
		while (j < x)
		{
			if (!(i * j) || i == y - 1 || j == x - 1)
				map[i].push_back('0' - 1);
			else if (i == fY && j == fX)
				map[i].push_back('1');
			else
				map[i].push_back('0');
			j++;
		}
		i++;
	}
	this->x = x;
	this->y = y;
}

Map::Map()
{

}

void Map::GenerateFood()
{
	map[fY][fX] = '0';
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disx(1, x - 2);
	std::uniform_int_distribution<> disy(1, y - 2);
	fX = disx(gen);
	fY = disy(gen);
	map[fY][fX] = '1';
}

std::vector<std::vector<char>> Map::GetMap()
{
	return map;
}
