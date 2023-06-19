#include "Neuron.h"

Neuron::Neuron(int n)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-1.0, 1.0);
	float	r = dis(gen);
	int		i;

	i = 0;
	while (i < n)
	{
		weights.push_back( r);
		r = dis(gen);
		i++;
	}
	r = dis(gen);
	bias = r;
}

void Neuron::Calc(std::vector<float> in)
{
	int	i;

	i = 0;
	//Reseting previous out:
	out = 0;
	while (i < in.size())
	{
		out += in[i] * weights[i];
		i++;
	}
	out += bias;
}

void Neuron::DebugLOG()
{
	int	i;

	i = 0;
	//Logging the data of neuron (its temp) :
	while (i < weights.size())
		std::cout << std::setw(6) << "W" << i << ": " << weights[i++] << std::endl;
	std::cout << std::setw(6) << "BIAS: " << bias << std::endl;
	std::cout << std::setw(6) << "OUT: " << out << std::endl;
}

float Neuron::GetOut()
{
	return out;
}

void Neuron::Mutate(Neuron a, Neuron b)
{
	int	i;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-1.0, 1.0);

	i = 0;
	while (this->weights.size() / 3 > i)
	{
		this->weights[i] = a.weights[i];
		i++;
	}
	while (this->weights.size() / 3  > i)
	{
		this->weights[i] = b.weights[i];
		i++;
	}
	while (this->weights.size() > i)
	{
		this->weights[i] = dis(gen);
		i++;
	}
	bias = (a.bias + b.bias) / 2 + dis(gen);
}
