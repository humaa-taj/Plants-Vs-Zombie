#include <SFML/Graphics.hpp>
#include"football.h"
#include<iostream>
using namespace std;
using namespace sf;


footballzombie::footballzombie()
{

}
footballzombie::footballzombie(float l, double s, int x, int y) :Zombie(l, s, x, y) {


	set_time = 0.5f;
	frame = 0;
	time_interval = 2.0f;
	for (int i = 0; i < 4; i++)
	{
		path = "Images/r" + std::to_string(i + 1) + ".png";
		foot[i].loadFromFile(path);
		path1 = "Images/fe" + std::to_string(i + 1) + ".png";
		foot1[i].loadFromFile(path1);
	}
	name = "football";
	deathcounter = 50;///////////////
}

void footballzombie::drawsprite(RenderWindow& w) {

	w.draw(football);
}

void footballzombie::movement(RenderWindow& w) 
{

	
	if (getlife() <= 0)
	{
		
		dead(w);

	}
	else
	{
		if (getlife() > 0 && !geteating())
		{
			if (time.getElapsedTime().asSeconds() >= set_time)
			{
				frame = (frame + 1) % 3;
				football.setTexture(foot[frame]);
				time.restart();
			}
			setx((getx()) - getspeed());
			/*cout << gety() << endl;
			if (gety() > 163 && getx()<=940)
			{
				sety(gety() - getspeed());
			}
			if (getx() < 200 && gety() <= 65)
			{
				setx(2000);
				sety(2000);
			}*/
			football.setPosition(getx(), gety());
			drawsprite(w);
		}
	}

}

void footballzombie::eating(RenderWindow& w)
{
	if (getlife() > 0 && geteating())
	{
		if (time.getElapsedTime().asSeconds() >= set_time) {
			frame = (frame + 1) % 3;
			football.setTexture(foot1[frame]);
			time.restart();
		}
		football.setPosition(getx(), gety());
		drawsprite(w);
	}


}

bool footballzombie::dead(RenderWindow& w)
{

	
	if (getkiller())
	{
		deathcounter--;
		footdead.loadFromFile("Images/boom3.png");
		football.setTexture(footdead);
		if (deathcounter<=0)
		{

			football.setPosition(-900, -900);
			w.draw(football);
		
		}
		else
		{
			football.setPosition(getx(), gety());
            w.draw(football);
		}
	}
	else
	{
		deathcounter--;
	
		footdead.loadFromFile("Images/footdie.png");
		s.setTexture(footdead);
		
		if (deathcounter<=0)
		{
			
			s.setPosition(-900, -900);
			w.draw(s);
			
		}
		else
		{
			s.setPosition(getx(), gety());
			w.draw(s);
		}
	}

	return true;
}

void footballzombie::initial(float l, double s, int x, int y) {
	setlife(l);
	setspeed(s);
	setx(x);
	sety(y);
	frame = 0;
	set_time = 0.5f;
	time_interval = 2.0f;
	for (int i = 0; i < 4; i++)
	{
		path = "Images/r" + std::to_string(i + 1) + ".png";
		foot[i].loadFromFile(path);
		path1 = "Images/fe" + std::to_string(i + 1) + ".png";
		foot1[i].loadFromFile(path1);
	}
}
void footballzombie::summon() {

}