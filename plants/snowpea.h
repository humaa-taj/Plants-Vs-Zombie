#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "plant.h"
using namespace sf;
using namespace std;

class snowpea :public plant
{

	Sprite s;
	Texture t;
	Sprite bulletsp;
	Texture bullettext;

public:

	snowpea();
	snowpea(RenderWindow& window, int px, int py, int l = 80, int p = 0, bool a = true, int c = 2, bool e = true, float d = 7);
	void draw(RenderWindow& window);
	void updatecherry(RenderWindow& w) {}
	void draw(RenderWindow& window, Event event) {}
	void moveup(RenderWindow& w) {}

	void diagnal_down(RenderWindow& w) {}
	void diagnal_up(RenderWindow& w) {}
	~snowpea();

	//void shoot();

};

