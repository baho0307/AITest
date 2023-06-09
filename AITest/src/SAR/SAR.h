#pragma once

#include "../Network/Network.h"

class SAR
{
public:
	SAR();
	std::vector<float>	situation;
	void				DecideSit(Network net, std::vector<float> sit);
	DIR					action;
	float				reward;
};

