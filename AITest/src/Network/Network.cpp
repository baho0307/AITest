#include "Network.h"

Network::Network(std::vector<int> n)
{
	int	i;
	int	j;

	i = 0;
	//Random neuron initializing
	while (i < n.size())
	{
		j = 0;
		while (j < n[i])
		{
			neurons[i].push_back(Neuron(i ? 3 : n[i - 1]));
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
	std::vector<float>	sTemp;
	std::vector<float>	sNext;

	sIn = in;
	i = 0;
	while (i < neurons.size())
	{
		j = 0;
		while (j < neurons[i].size())
		{
			sNext.push_back(neurons[i][j].GetOut());
		}
		sTemp = sNext;
		sNext = sIn;
		sIn = sTemp;
	}

	decision = sIn;
}

std::vector<float>	 Network::GetDecision()
{
	return decision;
}
