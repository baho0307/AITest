#include "src/Program.h"

// CROSSOVER SHOULD BE ADDED
// GENS AFTER THE FIRST GEN SHOULD HAVE PARENTS AND BE EMPTY IN BEGINNING  

int main()
{
	std::vector<int>	neuron = { 8, 4, 8, 4, 4};
	Program				prg = Program(neuron, 1000, 15);

	prg.Start();
}
