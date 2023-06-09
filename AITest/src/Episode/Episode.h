#pragma once

#include "../Bug/Bug.h"
#include "../SAR/SAR.h"

class Episode
{
public:
	Episode(int lifetime, std::vector<int> netLayer, std::vector<std::vector<char>> map);
	void				AddLifetime(int count);
	void				Start();
private:
	std::vector<std::vector<char>> map;
	std::vector<SAR>	episode;
	Bug					bug;
	Network				net;
	float				point;

};

