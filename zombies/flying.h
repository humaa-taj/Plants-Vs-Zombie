#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include"zombie.h"
using namespace std;
using namespace sf;


class flying : public Zombie {
	Texture fly[4];
	Texture flydead;
	Sprite flew;
	Clock time;
	float set_time;
	int frame;
	string path;
public:
	flying();
	flying(float l, double s, int x, int y);
	void initial(float l, double s, int x, int y);
	void drawsprite(RenderWindow& w);
	void checkpartner(RenderWindow& w, int i) {};
	void movement(RenderWindow& w);
	void eating(RenderWindow& w);
	bool dead(RenderWindow& w);
	void summon();
};



