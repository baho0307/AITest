#pragma once

#include "Episode/Episode.h"
#include "Map/Map.h"

class Program
{
public:
	Program(std::vector<int> neuronCount, int genExCount, int mapSize);
	Program();
	int		GetGenCount();
	Episode FindParent();
	void	GenReset();
	void	Start();
private:
	std::vector<Episode>	gen;
	std::vector<int>		neuronCount;
	int						genExCount;
	int						mapSize;
	int						best;
	int						genCounter;

};

