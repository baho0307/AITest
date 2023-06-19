#include "SAR.h"

SAR::SAR()
{
	reward = 0;
}

void SAR::DecideSit(Network net, std::vector<float> sit)
{
	int		i;
	int		max_i;
	float	f;
	std::vector<DIR>	d = {UP, RIGHT, LEFT, DOWN};

	i = 0;
	
	max_i = 0;
	net.CalcOut(sit);
	f = net.GetDecision()[0];
	while (net.GetDecision().size() > i)
	{
		if (net.GetDecision()[i] > f)
		{
			f = net.GetDecision()[i];
			max_i = i;
		}
		i++;
	}
	action = d[max_i];
	reward = 10;
}

