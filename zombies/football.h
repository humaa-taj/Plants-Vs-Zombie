#pragma once
#include <SFML/Graphics.hpp>
#include"zombie.h"
using namespace std;
using namespace sf;


class footballzombie : public Zombie {
	Texture foot[4];
	Texture foot1[4];
	Texture footdead;
	Sprite football;
	Clock time;
	float set_time;
	int frame;
	string path, path1;
	float time_interval;
public:
	footballzombie();
	footballzombie(float l, double s, int x, int y);
	void initial(float l, double s, int x, int y);
	void checkpartner(RenderWindow& w, int i) {};
	void drawsprite(RenderWindow& w);
	void movement(RenderWindow& w);
	void eating(RenderWindow& w);
	bool dead(RenderWindow& w);
	void summon();
};

