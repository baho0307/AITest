#include "src/Program.h"

//OUTPUT SHOULD BE 4 

int main()
{
	std::vector<int>	neuron = { 8, 6, 4 };
	Program				prg = Program(neuron, 1000, 15);

	prg.Start();
}
