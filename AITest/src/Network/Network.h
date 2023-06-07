#pragma once

#include "../Neuron/Neuron.h"
#include <vector>

class Network
{
public:
	Network(int n = 3);
	void	CalcOut(Vector in);
	Vector	GetDecision();
	std::vector<Neuron> neurons;
private:
	Vector	decision;
};

