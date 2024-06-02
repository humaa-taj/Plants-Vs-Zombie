#pragma once
#include <SFML/Graphics.hpp>
#include"bullet.h"
using namespace sf;
class plant
{

	int positionx;
	int positiony;
	int life;
	int price;
	bool alive;
	bool ischerry;
	bool iswallnut;
	bool moving;

public:
	bullet* b;
	plant();
	//~plant();
	void setpx(int px);
	void setpy(int py);
	void setlife(int l);
	void setprice(int p);
	void setalive(bool b);
	void setcherry(bool c);
	void setnut(bool c);
	plant(int px, int py, int l, int p, bool a);
	bool getalive();
	bool getnut();
	bool getcherry();
	int getpx();
	int getpy();
	int getlife();
	int getprice();
	void setmove(bool a);
	bool getmove();
	void startdeath();/////////////////////////////////
	virtual void draw(RenderWindow& window) = 0;
	virtual void updatecherry(RenderWindow& w) = 0;
	virtual void draw(RenderWindow& window, Event event) = 0;
	virtual void moveup(RenderWindow& w) = 0;
	virtual void diagnal_down(RenderWindow& w) = 0;
	virtual void diagnal_up(RenderWindow& w) = 0;

	virtual ~plant() {}
};

