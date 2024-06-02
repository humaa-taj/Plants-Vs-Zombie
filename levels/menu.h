
#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class menu
{
	Sprite bgs;
	Texture bgt;
	Sprite plays;
	Texture playt;
	Sprite inssp;
	Texture inst;
	Sprite pros;
	Texture prot;
	Font font;


public:
	bool men;
	bool ins;
	bool profile;
	string iS;
	Text   text;
	menu();
	//menu(RenderWindow& window);
	bool handleInput(RenderWindow& window, Event event);
	void display(RenderWindow& window, Event event);

};