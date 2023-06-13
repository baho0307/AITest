#pragma once

#include "Episode/Episode.h"
#include "Map/Map.h"

class Program
{
public:
	Program(std::vector<int> neuronCount, int genExCount, int mapSize);
	Program();
	int		GetGenCount();
	void	GenReset();
	void	Start();
	bool	IsFinished();
private:
	std::vector<Episode>	gen;
	int						best;
	int						mapSize;
	int						genCounter;

};

