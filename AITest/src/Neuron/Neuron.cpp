#include "Neuron.h"

Neuron::Neuron()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);
	float r = dis(gen);
	weight.x = r;
	r = dis(gen);
	weight.y = r; 
	r = dis(gen);
	weight.z = r;
	r = dis(gen);
	bias = r;
}

void Neuron::Calc(Vector in)
{
	out = (weight.x * in.x + weight.y * in.y + weight.z * in.z + bias);
}

void Neuron::DebugLOG()
{
	//Logging the data of neuron (its temp) : 
	std::cout << std::setw(6) << "X: " << weight.x << std::endl;
	std::cout << std::setw(6) << "Y: " << weight.y << std::endl;
	std::cout << std::setw(6) << "Z: " << weight.z << std::endl;
	std::cout << std::setw(6) << "BIAS: " << bias << std::endl;
	std::cout << std::setw(6) << "OUT: " << out << std::endl;

}

float Neuron::GetOut()
{
	return out;
}
