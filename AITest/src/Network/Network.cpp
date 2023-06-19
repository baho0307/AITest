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
			neurons[i].push_back(Neuron(!i ? 8 : n[i - 1]));
			j++;
		}
		i++;
	}
}

void Network::CalcOut(std::vector<float> in)
{
	int	i;
	int	j;
	//updated hidden layers input
	std::vector<float>	sIn;
	std::vector<float>	sNext;

	decision.clear();
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

void Network::Mutate(Network parent, Network parent2)
{
	int	i;
	int	j;
	std::vector<Network> p = { parent, parent2 };

	i = 0;
	while (i < this->neurons.size())
	{
		j = 0;
		while (j < this->neurons[i].size())
		{
			this->neurons[i][j].Mutate(parent.neurons[i][j], parent2.neurons[i][j]);
			j++;
		}
		i++;
	}
}

std::vector<float>	 Network::GetDecision()
{
	return decision;
}
