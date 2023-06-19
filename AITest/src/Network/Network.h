#pragma once

#include "../Neuron/Neuron.h"
#include <vector>

class Network
{
public:
	Network();
	Network(std::vector<int> layers);
	void	CalcOut(std::vector<float> in);
	void	Mutate(Network parent, Network parent2);
	std::vector<float>	GetDecision();
	std::vector<std::vector<Neuron>> neurons;
private:
	std::vector<float>	decision;

};
