#include "SAR.h"

SAR::SAR()
{
	reward = 10;
}

void SAR::DecideSit(Network net, Vector sit)
{
	net.CalcOut(sit);
	Vector	dec= net.GetDecision();
	if (dec.x > dec.y && dec.x > dec.z)
		action = LEFT;
	else if (dec.y > dec.x && dec.y > dec.z)
		action = UP;
	else
		action = RIGHT;
}

