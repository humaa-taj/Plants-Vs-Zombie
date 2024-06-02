#pragma once
#include <SFML/Graphics.hpp>
#include "plant.h"
#include"bullet.h"
#include"peashooter.h"
#include"snowpea.h"
#include"repeater.h"
#include"sunflower.h"
#include"wallnut.h"
#include "cherry.h"
#include"grid.h"
using namespace sf;
using namespace std;

class plantfactory
{
    int size;
	Sprite s;
	Texture t;
	Sprite pss; Texture pst;
	Sprite sps; Texture spt;
	Sprite ws; Texture wt;
	Sprite rs; Texture rt;
	Sprite cs; Texture ct;
	Sprite sfs; Texture sft;
	int currency;
	bool pea, sunf, ch, wa, r, sp, placed;
	Vector2f offset;



public:
	plant** p;
	plantfactory();
	int handleinput(Event event, RenderWindow& window, int level, float gr[5][9][5], int& total, int y);///////////////////////
	void draw(RenderWindow& window, int level);
	void setcurrency(sun* s);
	int row, column;
	int getcurrency();
	int getsize()
	{
		return size;
	}
	~plantfactory();
};
