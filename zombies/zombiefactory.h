#pragma once
#include"zombie.h"
#include"S_zombie.h"
#include"dancing.h"
#include"partner.h"
#include"flying.h"
#include"football.h"

class zombiefactory 
{
	int levelnum, interval1, interval2, interval3;
	int x_range, y_range;
	
public:

	Zombie** z;
	zombiefactory() {};
	zombiefactory(int l);
	void setlevel(int l);
	void setI1(int i);
	void setI2(int i);
	void setI3(int i);
	int getI1();
	int getI2();
	int getI3();
	int getlevel();
	void waves(RenderWindow& w, int i);
	void RemoveZombie(int i);
	~zombiefactory();
};
