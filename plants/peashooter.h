#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "plant.h"
using namespace sf;
using namespace std;

class peashooter :public plant
{

	Sprite s;
	Texture t;
	Sprite bulletsp;
	Texture bullettext;
	Clock c;
public:

	peashooter();
	peashooter(RenderWindow& window, int px, int py, int l = 50, int p = 0, bool a = true, int c = 2, bool e = true, float d = 5);
	void draw(RenderWindow& window);
	void updatecherry(RenderWindow& w) {};
	void draw(RenderWindow& window, Event event) {}
	void moveup(RenderWindow& w) {}
	void diagnal_down(RenderWindow& w) {}
	void diagnal_up(RenderWindow& w) {}
	~peashooter();
	//void shoot();

};
