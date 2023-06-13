#include "Program.h"

Program::Program(std::vector<int> neuronCount, int genExCount, int mapSize)
{
	int	i;

	i = 0;
	this->mapSize = mapSize;
	while (i < genExCount)
	{
		gen.push_back(Episode(50, neuronCount, mapSize));
		i++;
	}
	genCounter = 0;
	best = 0;
}

Program::Program()
{

}

int Program::GetGenCount()
{
	return genCounter;
}

void Program::GenReset()
{
	int		i;
	int		max_i;
	int		sec_i;
	float	max_f;

	i = 0;
	sec_i = 0;
	max_i = 1;
	max_f = 0;
	while (i < gen.size())
	{
		if (max_f < gen[i].GetPoint())
		{
			max_f = gen[i].GetPoint();
			sec_i = max_i;
			max_i = i;
		}
		i++;
	}
	i = 0;
	while (i < gen.size())
	{
		if (i == max_i)
			gen[i].Reset(NONE, 50, mapSize);
		else if (i == sec_i)
			gen[i].Reset(RANDOM_NEURON, 50, mapSize);
		else
			gen[i].Reset(ALL_NEURONS, 50, mapSize);
		i++;
	}
	best = max_i;
}

bool Program::IsFinished()
{
	int		i;

	i = 0;
	while (i < gen.size())
	{
		if (gen[i].GetLife())
			return true;
		i++;
	}
	return false;
}

void Program::Start()
{
	int	i;

	while (true)
	{
		i = 0;
		while (i < gen.size())
		{
			gen[i].Start(i == best);
			i++;
		}
		GenReset();
		genCounter++;
	}
}

