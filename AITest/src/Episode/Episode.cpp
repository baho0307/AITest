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

Episode::Episode(int lifetime, std::vector<int> netLayer)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 32);
	int r = dis(gen);

	AddLifetime(lifetime);
	bug = Bug(r, r);
	net = Network(netLayer);
}
