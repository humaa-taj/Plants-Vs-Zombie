
#include <SFML/Graphics.hpp>
#include"partner.h"
#include<iostream>

using namespace std;
using namespace sf;


partner::partner()
{

}
void partner::drawsprite(RenderWindow& w)
{
	//cout << "drawdrawdraw";
	w.draw(simple_zoom);
}
partner::partner(float l, double s, int x, int y) :Zombie(l, s, x, y) 
{
	frame = 0;
	set_time = 0.5f;
	for (int i = 0; i < 3; i++)
	{
		path = "Images/p" + std::to_string(i + 1) + ".png";
		simple_z[i].loadFromFile(path);


	}
	for (int i = 0; i < 4; i++)
	{
		path1 = "Images/part" + std::to_string(i + 1) + ".png";
		eatp[i].loadFromFile(path1);
	}
	name = "partner";
	deathcounter = 50;///////////

}


void partner::movement(RenderWindow& w)
{
	if (getlife() <= 0)
	{
		dead(w);
	}
	else
	{
		if (getlife() > 0 && !geteating())
		{
			//cout << "not eating" << endl;
			if (time.getElapsedTime().asSeconds() >= set_time)
			{
				frame = (frame + 1) % 3;
				simple_zoom.setTexture(simple_z[frame]);
				time.restart();
			}
			setx((getx()) - getspeed());

		/*	if(gety()>=163)
			{
				sety(gety() - getspeed());
			}*/
			simple_zoom.setPosition(getx(), gety());
			drawsprite(w);
		}
	}


}

void partner::initial(float l, double s, int x, int y) {
	setlife(l);
	setspeed(s);
	setx(x);
	sety(y);
	set_time = 0.5f;
	frame = 0;
	for (int i = 0; i < 3; i++)
	{
		path = "Images/p" + std::to_string(i + 1) + ".png";
		simple_z[i].loadFromFile(path);


	}
	for (int i = 0; i < 4; i++)
	{
		path1 = "Images/part" + std::to_string(i + 1) + ".png";
		eatp[i].loadFromFile(path1);
	}
}
void partner::eating(RenderWindow& w)
{

	//cout << "eating " << endl;
	if (time.getElapsedTime().asSeconds() >= set_time) {
		frame = (frame + 1) % 4;
		simple_zoom.setTexture(eatp[frame]);
		time.restart();

	}
	simple_zoom.setPosition(getx(), gety());
	drawsprite(w);


}

bool partner::dead(RenderWindow& w)
{

	if (getkiller())
	{
		deathcounter--;
		diep.loadFromFile("Images/boom3.png");
		simple_zoom.setTexture(diep);
	
		if (deathcounter<=0)
		{

			simple_zoom.setPosition(-900, -900);
			w.draw(simple_zoom);
			
		}
		else
		{
			simple_zoom.setPosition(getx(), gety());
			w.draw(simple_zoom);
		}
	}
	else
	{
		deathcounter--;
		diep.loadFromFile("Images/partdie.png");
		s.setTexture(diep);
		
		if (deathcounter <= 0)
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
void partner::summon()
{

}