#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class bullet
{

	Texture bt;
	int positionx;
	int positiony;
	int cooldown;
	bool exist;
	float damage;
	int speed;
	Sprite bs;
	bool drawb;

	int generate;



public:
	int temp, tempy;
	/*Sprite bs;
	bool drawb;
	int temp;
	int generate;*/
	bullet();
	void setpx(int px);
	void setpy(int py);
	void setcool(int c);
	void setexist(bool b);
	void setdamage(int b);
	bullet(Sprite& s, Texture& t, int px, int py, int c, bool b, int d, RenderWindow& window, int ss);
	void setbullet(Sprite& s, Texture& t, int px, int py, int c, bool b, int d, RenderWindow& window, int ss);
	void draw(RenderWindow& window);
	int getpx();
	int getpy();
	int getcool();
	int getdamage();

	bool getexist();
	void movebullet();


};