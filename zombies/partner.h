#pragma once
#include <SFML/Graphics.hpp>
#include"zombie.h"
using namespace std;
using namespace sf;


class partner : public Zombie {

	Sprite simple_zoom;
	Texture simple_z[3];
	Texture diep;
	Texture eatp[4];
	Clock time;
	float set_time;
	int frame;
	string path, path1;
public:
	partner();
	partner(float l, double s, int x, int y);
	void drawsprite(RenderWindow& w);
	void movement(RenderWindow& w);
	void eating(RenderWindow& w);
	bool dead(RenderWindow& w);
	void checkpartner(RenderWindow& w, int i) {};
	void initial(float l, double s, int x, int y);
	void summon();
};
