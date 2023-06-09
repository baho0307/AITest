#include "Episode.h"


void Episode::AddLifetime(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		episode.push_back(SAR());
		i++;
	}
}

void Episode::Start()
{
	//START FUNCTION WILL BE WRITTEN
	int	i;

	i = 0;
	while (i < map.size())
	{

	}
}

Episode::Episode(int lifetime, std::vector<int> netLayer, std::vector<std::vector<char>> map)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 32);
	int r = dis(gen);

	AddLifetime(lifetime);
	bug = Bug(r, r);
	net = Network(netLayer);
	this->map = map;
}
