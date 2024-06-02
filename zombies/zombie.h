#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Zombie
{
	int life;
	double speed;
	int x_pos;
	int y_pos;
	bool cherrykiller;
	bool eat;
	bool zombiealive,front,back,up,down;

	
public:

	Zombie();
	Zombie(float l, double s, int x, int y);
	void setspeed(double sp);
	void setlife(float l);
	void setx(int x);
	void sety(int y);
	int getx();
	int gety();
	void setalive(bool a);
	bool getalive();
	void seteating(bool a);
	bool geteating();
	void setkiller(bool a);
	bool getkiller();
	double getspeed();
	float getlife();
	string name;
	int deathcounter;
	Sprite s;
	virtual void checkpartner(RenderWindow& w, int i) = 0;
    void setfront(bool r);
	void setback(bool l);
	void setup(bool u);
	void setdown(bool d);
	bool getfront();
	bool getback();
	bool getup();
	bool getdown();
	//void dead(RenderWindow& w,Sprite& s, Texture& t);
	virtual void drawsprite(RenderWindow& w) = 0;
	virtual void movement(RenderWindow& w) = 0;
	virtual void eating(RenderWindow& w) = 0;
	virtual void summon() = 0;
	virtual bool dead(RenderWindow& w) = 0;
	virtual void initial(float l, double s, int x, int y) = 0;
};
