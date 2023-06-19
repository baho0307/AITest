#pragma once

#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include "../Bug/Bug.h"

class Neuron
{
public:
	Neuron(int n);
	void	Calc(std::vector<float> in);
	void	DebugLOG();
	float	GetOut();
	void	Mutate(Neuron a, Neuron b);
	void	SetWeight(int layer, int index, float val);


private:
	std::vector<float>	weights;
	float				bias;
	float				out;
};

