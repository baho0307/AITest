#pragma once

#include "Episode/Episode.h"
#include "Map/Map.h"
#include "Draw/Draw.h"

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
	Draw					scr;
	int						best;
	int						mapSize;
	int						genCounter;

};

