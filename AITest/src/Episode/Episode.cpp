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

	i = 0;
	while (i < episode.size() && isAlive)
	{
		if (map.GetMap()[bug.GetY()][bug.GetX()] == '0')
		{
			episode[i].DecideSit(net, bug.Look(map.GetMap()));
			bug.Move(episode[i].action);
		}
		if (map.GetMap()[bug.GetY()][bug.GetX()] == '0' - 1)
			isAlive = false;
		else if (map.GetMap()[bug.GetY()][bug.GetX()] == '1')
		{
			map.GenerateFood();
			AddLifetime(25);
			point += 100;
		}
		point += episode[i].reward;
		if (show)
		{
			Show(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		i++;
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

bool Episode::GetLife()
{
	return isAlive;
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

std::vector<std::vector<char>> Episode::GetMap()
{
	return this->map.GetMap();
}
