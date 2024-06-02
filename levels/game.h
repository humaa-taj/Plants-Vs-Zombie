#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include <SFML/Graphics.hpp>
#include"level.h"
#include"level1.h"
#include"level2.h"
#include"level3.h"
#include"sstream"

using namespace std;
using namespace sf;

class game
{
	int lifeoflevel1;
	int lifeoflevel3;
	int lifeoflevel2;
	bool l1;
	bool l2;
	bool l3;
	level** l;
	menu m;
	bool b, isPaused;
	Image map_image;
	Texture map;
	Sprite s_map;
	Image icon;
	RenderWindow window;
	//+++++++
	int highscore;
	string top[3];
	int topscore[3];
	string reading;
	ofstream writing;
	ifstream f;
	bool gamewon;

public:

	game();

	void createBack(RenderWindow& window);

	bool creategame();
	
	void setter(int level, int num);
	
	~game();
};
class hs
{
public:
	string na;
	int sc;
	hs()
	{
		na = "";
		sc = 0;
	}
};

