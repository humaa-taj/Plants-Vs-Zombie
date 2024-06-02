#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class sun
{
	int positionx;
	int positiony;
	Sprite s;
	Texture t;
	bool sfalive;
	bool salive;
	int fallingspeed;
	bool spawnedFromSunflower;

public:
	//sun();
	Clock despawnClock;
	int collected;
	sun(int fs = 2, int px = 700, int py = 0, int coll = 0);
	void setsprite();
	void settexture();
	void selected(int coin);
	void set(int x, int y, bool fromSunflower);
	void draw(RenderWindow& window);
	void movement();
	void updatesun();

	bool handleinput(RenderWindow& window);
	int getx();
	int gety();
	void setalive(bool a);
	bool getalive();
	void setcollected(int c);
	int getcollected();
};
