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
	int	i;

	i = 0;
	while (i < episode.size() && isAlive)
	{
		episode[i].DecideSit(net, bug.Look(map.GetMap()));
		bug.Move(episode[i].action);
		if (map.GetMap()[bug.GetY()][bug.GetX()] == '0' - 1)
			isAlive = false;
		else if (map.GetMap()[bug.GetY()][bug.GetX()] == '1')
			AddLifetime(25);
		point += episode[i].reward;
		i++;
	}
	isAlive = false;
}

float Episode::GetPoint()
{
	return point;
}

void Episode::Reset(MUTATE_OPT opt, int lifetime, int mapSize)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, mapSize - 1);
	int x = dis(gen);
	int y = dis(gen);

	bug = Bug(x, y);
	net.Mutate(opt);
	episode.clear();
	map = Map(mapSize, mapSize);
	AddLifetime(lifetime);
	isAlive = true;
	point = 0;
}

Episode::Episode(int lifetime, std::vector<int> netLayer, int mapSize)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, mapSize - 1);
	int x = dis(gen);
	int y = dis(gen);

	AddLifetime(lifetime);
	bug = Bug(x, y);
	net = Network(netLayer);
	map = Map(mapSize, mapSize);
	isAlive = true;
	point = 0;
}
