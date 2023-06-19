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

void Episode::Show(int SAR)
{
	int	i;
	int	j;

	i = 0;
	system("cls");
	while (i < GetMap().size())
	{
		j = 0;
		while (j < GetMap()[i].size())
		{
			if (i == GetBugY() && j == GetBugX())
				std::cout << 'O';
			//TAIL WILL BE ADDED
			else
			{
				if (GetMap()[i][j] == '0' - 1)
					std::cout << '#';
				else if (GetMap()[i][j] == '0')
					std::cout << ' ';
				else
					std::cout << 'F';
			}
			j++;
		}
		i++;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::setw(10) << "MOVE: " << SAR + 1<< std::endl;
	std::cout << std::setw(10) << "POINT: " << point << std::endl;
	std::cout << std::setw(10) << "FOOD: " << bug.foodFlag << std::endl;

	bug.DebugLOG();
}

void Episode::Start(bool show)
{
	int	i;
	int	x;
	int	y;

	x = bug.GetX();
	y = bug.GetY();
	i = 0;
	while (i < episode.size() && isAlive)
	{
		if (map.GetMap()[bug.GetY()][bug.GetX()] != '0' - 1)
		{
			episode[i].DecideSit(net, bug.Look(map.GetMap()));
			bug.Move(episode[i].action);
		}
		else if (map.GetMap()[bug.GetY()][bug.GetX()] == '0' - 1)
			isAlive = false;
		if (map.GetMap()[bug.GetY()][bug.GetX()] == '1')
		{
			map.GenerateFood();
			AddLifetime(25);
			point += 100;
		}
		point += episode[i].reward / (i + 1);
		if (show)
		{
			Show(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		i++;
	}
	point += 2 * sqrt(pow(bug.GetX() - x, 2) + pow(bug.GetY() - y, 2));
	if (show)
	{
		Show(i - 1);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	isAlive = false;
}

float Episode::GetPoint()
{
	return point;
}

int Episode::GetBugX()
{
	return bug.GetX();
}

int Episode::GetBugY()
{
	return bug.GetY();
}

DIR Episode::GetBugDIR()
{
	return bug.GetDIR();
}

Network Episode::GetNet()
{
	return net;
}

bool Episode::GetLife()
{
	return isAlive;
}

void Episode::Reset()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, map.GetMap().size() - 2);
	int x = dis(gen);
	point = 0;
	isAlive = true;
	episode.clear();
	map.GenerateFood();
	bug = Bug(x,x);
	this->AddLifetime(50);
}

Episode Episode::Crossover(Episode parent, int lifetime, std::vector<int> netLayer, int mapSize)
{
	Episode r(lifetime, netLayer, mapSize);

	r.net.Mutate(this->net, parent.net);
	return r;
}

Episode::Episode(int lifetime, std::vector<int> netLayer, int mapSize)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, mapSize - 2);
	int x = dis(gen);
	int y = dis(gen);

	AddLifetime(lifetime);
	bug = Bug(x, y);
	net = Network(netLayer);
	map = Map(mapSize, mapSize);
	isAlive = true;
	point = 0;
}

std::vector<std::vector<char>> Episode::GetMap()
{
	return this->map.GetMap();
}
