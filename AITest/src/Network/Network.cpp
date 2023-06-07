#include "Network.h"

Network::Network( int n)
{
	int	i;

	i = 0;
	//Random neuron initializing
	while (i < 2 * n)
	{
		neurons.push_back(Neuron());
		i++;
	}
}

void Network::CalcOut(Vector in)
{
	int		i;
	//other hidden layers input
	Vector	sIn;

	i = 0;
	while (i < neurons.size() / 2)
		neurons[i++].Calc(in);
	sIn.x = neurons[0].GetOut();
	sIn.y = neurons[1].GetOut();
	sIn.z = neurons[2].GetOut();
	while (i < neurons.size())
		neurons[i++].Calc(sIn);
	decision.x = neurons[3].GetOut();
	decision.y = neurons[4].GetOut();
	decision.z = neurons[5].GetOut();
}

Vector Network::GetDecision()
{
	return decision;
}
