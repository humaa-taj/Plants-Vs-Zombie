#pragma once
#include <SFML/Graphics.hpp>
#include"plant.h"
#include"S_zombie.h"

using namespace sf;
class cherry :public plant
{
	Sprite s;
	Texture t;


public:

	cherry();
	cherry(int px, int py, int l = 50, int p = 0, bool a = true);
	void draw(RenderWindow& w);

	void draw(RenderWindow& window, Event event) {};
	void moveup(RenderWindow& w) {}
	void diagnal_down(RenderWindow& w) {}
	void diagnal_up(RenderWindow& w) {}
	void updatecherry(RenderWindow& w);

};
