#pragma once

#include "../Bug/Bug.h"
#include "../SAR/SAR.h"
#include "../Map/Map.h"

class Episode
{
public:
	Episode(int lifetime, std::vector<int> netLayer, int mapSize);
	std::vector<std::vector<char>>	GetMap();
	void				AddLifetime(int count);
	void				Start();
	float				GetPoint();
	int					GetBugX();
	int					GetBugY();
	DIR					GetBugDIR();
	void				Reset(MUTATE_OPT opt, int lifetime, int mapSize);
	bool				GetLife();
	
private:
	Map					map;
	std::vector<SAR>	episode;
	Bug					bug;
	Network				net;
	float				point;
	bool				isAlive;

};

