#pragma once

#include"plant.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace sf;
class wallnut :public plant
{
	Sprite wall;
	Texture wal[4];

	float wall_speed;
	Clock nutclock;
	float wall_time;
	int frame;
	string path;
public:
	wallnut();
	wallnut(int px, int py, float speed = 3, int l = 100, int p = 0, bool a = true);
	void draw(RenderWindow& w);
	void rolling();
	void moveup(RenderWindow& w);

	void updatecherry(RenderWindow& w) {}
	void diagnal_down(RenderWindow& w);
	void draw(RenderWindow& window, Event event) {}
	void diagnal_up(RenderWindow& w);
	void setspeed(int a);
	float getspeed();
};
