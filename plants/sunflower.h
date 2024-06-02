#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "sun.h"
#include "plant.h"

using namespace sf;

class sunflower : public plant
{
public:

	sun su;
	Sprite s;
	Texture t;
	sunflower(int px, int py, int l = 50, int p = 0, bool a = true, int c = 2, bool e = true);
	void draw(RenderWindow& window, Event event);
	void draw(RenderWindow& window);
	void moveup(RenderWindow& w) {}
	void diagnal_down(RenderWindow& w) {}
	void diagnal_up(RenderWindow& w) {}
	void updatecherry(RenderWindow& w) {}
	sf::Clock spawnClock; // Timer for spawning suns
};
