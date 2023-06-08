#pragma once

#include "../Neuron/Neuron.h"
#include <vector>

class Network
{
public:
	Network(std::vector<int> layers);
	void	CalcOut(std::vector<float> in);
	std::vector<float>	GetDecision();
	std::vector<std::vector<Neuron>> neurons;
private:
	std::vector<float>	decision;

};

