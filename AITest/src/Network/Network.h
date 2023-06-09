#pragma once

#include "../Neuron/Neuron.h"
#include <vector>

enum MUTATE_OPT {
	RANDOM_NEURON = 101,
	ALL_NEURONS = 111
};

class Network
{
public:
	Network();
	Network(std::vector<int> layers);
	void	CalcOut(std::vector<float> in);
	void	Mutate(MUTATE_OPT option);
	std::vector<float>	GetDecision();
	std::vector<std::vector<Neuron>> neurons;
private:
	std::vector<float>	decision;

};

