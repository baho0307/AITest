#pragma once

#include "../Bug/Bug.h"
#include "../SAR/SAR.h"

class Episode
{
public:
	void				AddLifetime(int count);
	Episode(int lifetime, std::vector<int> netLayer);
	std::vector<SAR>	episode;
	Bug					bug;
	Network				net;
	float				point;

};

