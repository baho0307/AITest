#include "src/Program.h"

//OUTPUT SHOULD BE 4 

int main()
{
	std::vector<int>	neuron = { 3, 4 };
	Program				prg = Program(neuron, 1000, 16);

	prg.Start();
}
