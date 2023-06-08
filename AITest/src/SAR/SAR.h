#pragma once

#include "../Network/Network.h"

class SAR
{
public:
	SAR();
	void	DecideSit(Network net, Vector sit);
	Vector	situation;
	DIR		action;
	float	reward;
};

