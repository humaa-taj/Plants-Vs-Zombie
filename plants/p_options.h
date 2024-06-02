#pragma once
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class p_options
{
	Sprite s;
	Texture t;
	Sprite pss; Texture pst;
	Sprite sps; Texture spt;
	Sprite ws; Texture wt;
	Sprite rs; Texture rt;
	Sprite cs; Texture ct;
	Sprite sfs; Texture sft;
	bool isdragging;
	Vector2f offset, peaoffset;
	bool ispeadragging;
public:
	p_options();
	void handleinput(Event event, RenderWindow& window);
	void draw(RenderWindow& window, int level);


};
