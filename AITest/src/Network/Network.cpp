#include "Network.h"

Network::Network()
{
}

Network::Network(std::vector<int> n)
{
	int	i;
	int	j;

	i = 0;
	//Random neuron initializing
	while (i < n.size())
	{
		j = 0;
		neurons.push_back(std::vector<Neuron>());
		while (j < n[i])
		{
			neurons[i].push_back(Neuron(!i ? 3 : n[i - 1]));
			j++;
		}
		i++;
	}
}

void				Network::CalcOut(std::vector<float> in)
{
	int	i;
	int	j;
	//updated hidden layers input
	std::vector<float>	sIn;
	std::vector<float>	sNext;

	sIn = in;
	i = 0;
	while (i < neurons.size())
	{
		j = 0;
		while (j < neurons[i].size())
		{
			neurons[i][j].Calc(sIn);
			sNext.push_back(neurons[i][j].GetOut());
			j++;
		}
		sIn = sNext;
		sNext.clear();
		i++;
	}

	decision = sIn;
}

void Network::Mutate(MUTATE_OPT option)
{
	if (option == RANDOM_NEURON)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, neurons.size() - 1);
		int	i = dis(gen);
		std::uniform_int_distribution<> adis(0, neurons[i].size() - 1);
		int	j = adis(gen);
		neurons[i][j].Mutate();
	}
	else if (option == ALL_NEURONS)
	{
		int	i;
		int	j;

		i = 0;
		while (i < neurons.size())
		{
			j = 0;
			while (j < neurons[i].size())
			{
				neurons[i][j].Mutate();
				j++;
			}
			i++;
		}
	}
}

std::vector<float>	 Network::GetDecision()
{
	return decision;
}
