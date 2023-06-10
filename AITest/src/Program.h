#pragma once

#include "Episode/Episode.h"
#include "Map/Map.h"

class Program
{
public:
	Program(std::vector<int> neuronCount, int genExCount, int mapSize);
	void	GenReset();
	void	Start();
private:
	std::vector<Episode>	gen;
	int						mapSize;
	int						genCounter;

};

