#include "Draw.h"

Draw::Draw()
{

}

void Draw::Show(int genCount, Episode episode)
{
	int	i;
	int	j;

	i = 0;
	system("cls");
	while (i < episode.GetMap().size())
	{
		j = 0;
		while (j < episode.GetMap()[i].size())
		{
			if (i == episode.GetBugY() && j == episode.GetBugX())
				std::cout << 'O';
			//TAIL WILL BE ADDED
			else
			{
				if (episode.GetMap()[i][j] == '0' - 1)
					std::cout << '#';
				else if (episode.GetMap()[i][j] == '0')
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
	std::cout << std::setw(10) << "GEN: " << genCount;
}
