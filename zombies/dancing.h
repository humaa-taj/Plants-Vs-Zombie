#pragma once

#include <SFML/Graphics.hpp>
#include"zombie.h"
#include"partner.h"

using namespace std;
using namespace sf;

class dancing : public Zombie
{
	Texture D[4];
	Texture deadisc;
	Texture eatdisc[4];
	Sprite dance;
	Clock clk1;
	int frame1;
	float interval;
	bool sum;
	string path, path1;

public:
	partner* pt[4];
	dancing();
	dancing(float l, double s, int x, int y);
	void initial(float l, double s, int x, int y);
	void drawsprite(RenderWindow& w);
	void movement(RenderWindow& w);
	void summon();
	void checkpartner(RenderWindow& w, int i);
	void eating(RenderWindow& w);
	bool dead(RenderWindow& w);
	~dancing();
};
