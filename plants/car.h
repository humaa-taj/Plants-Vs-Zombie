

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class car
{
	Texture mover;
	Sprite lawn;
	//float** gari;

	bool exist, moving;


public:
	int px, py;
	car();
	//car(int y);
	car(RenderWindow& w, int level);
	void setcar(int y);
	void draw(RenderWindow& w);
	void movecar();
	bool getmoving();
	void setmoving(bool b);
	bool gete();
	//~car();
};
