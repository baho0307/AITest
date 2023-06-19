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
	this->neuronCount = neuronCount;
	this->genExCount = genExCount;
	this->mapSize = mapSize;
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

Episode Program::FindParent()
{
	int	i;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disx(0, this->gen.size() - 1);
	i = disx(gen);
	this->gen[i].Reset();
	return this->gen[i];
}

void Program::GenReset()
{
	int		i;
	int		max_i;
	float	max_f;
	std::vector<Episode>	newGen;

	i = 0;
	max_i = 0;
	max_f = 0;
	while (i < gen.size())
	{
		if (max_f < gen[i].GetPoint())
		{
			max_f = gen[i].GetPoint();
			max_i = i;
		}
		i++;
	}
	i = 1;
	gen[max_i].Reset();
	newGen.push_back(gen[max_i]);
	while (i < gen.size())
	{
		newGen.push_back(FindParent().Crossover(FindParent(), 50, neuronCount, mapSize));
		i++;
	}
	gen = newGen;
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

