#pragma once

#include <iostream>
#include <iomanip>
#include <random>

typedef struct Vector
{
	float	x;
	float	y;
	float	z;
} Verctor;

class Neuron
{
public:
	Neuron();
	void	Calc(Vector in);
	void	DebugLOG();
	float	GetOut();

private:
	Vector	weight;
	float	bias;
	float	out;
};

