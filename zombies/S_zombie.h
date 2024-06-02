#pragma once
#include <SFML/Graphics.hpp>
#include"zombie.h"
#include"dancing.h"
using namespace std;
using namespace sf;


class simplezoombie : public Zombie
{

	Sprite simple_zoom;
	Texture simple_z[4];
	Texture die;
	Texture eat[4];
	Clock time;
	float set_time;
	int frame, f;
	string path, path1;
public:
	simplezoombie();
	simplezoombie(float l, double s, int x, int y);
	void initial(float l, double s, int x, int y);
	void drawsprite(RenderWindow& w);
	void movement(RenderWindow& w);
	void eating(RenderWindow& w);
	bool dead(RenderWindow& w);
	void checkpartner(RenderWindow& w, int i) {};
	void summon();
};
