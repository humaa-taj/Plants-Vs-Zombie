
#include <SFML/Graphics.hpp>
#include"S_zombie.h"
#include<iostream>
using namespace std;
using namespace sf;


simplezoombie::simplezoombie()
{

}
simplezoombie::simplezoombie(float l, double s, int x, int y) :Zombie(l, s, x, y) {

	set_time = 0.5f;
	frame = 0;
	for (int i = 0; i < 4; i++)
	{
		path = "Images/simple" + std::to_string(i + 1) + ".png";
		simple_z[i].loadFromFile(path);
		path1 = "Images/eat" + std::to_string(i + 1) + ".png";
		eat[i].loadFromFile(path1);
	}
	name = "simple";
	deathcounter = 50;
}

void simplezoombie::drawsprite(RenderWindow& w)
{
	//cout <<simple_zoom.getPosition() << endl;

	w.draw(simple_zoom);
}


void simplezoombie::movement(RenderWindow& w)

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
				simple_zoom.setTexture(simple_z[frame]);
				time.restart();
			}
			setx((getx()) - getspeed());
			simple_zoom.setPosition(getx(), gety());
			drawsprite(w);
		}

	}



}

void simplezoombie::eating(RenderWindow& w)
{
	if (getlife() > 0 && geteating())
	{

		if (time.getElapsedTime().asSeconds() >= set_time)
		{

			frame = (frame + 1) % 4;
			simple_zoom.setTexture(eat[frame]);
			time.restart();

		}

		simple_zoom.setPosition(getx(), gety());
		drawsprite(w);
	}

}

bool simplezoombie::dead(RenderWindow& w)
{
	setx(2000);
	sety(-2000);
	if (getkiller())
	{
		deathcounter--;
		die.loadFromFile("Images/boom3.png");
		simple_zoom.setTexture(die);

		
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
		die.loadFromFile("Images/d4.png");
		s.setTexture(die);
		
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

void simplezoombie::summon() {

}

void simplezoombie::initial(float l, double s, int x, int y) {
	setlife(l);
	setspeed(s);
	setx(x);
	sety(y);
	set_time = 0.5f;
	for (int i = 0; i < 4; i++)
	{
		path = "Images/simple" + std::to_string(i + 1) + ".png";
		simple_z[i].loadFromFile(path);
		path1 = "Images/eat" + std::to_string(i + 1) + ".png";
		eat[i].loadFromFile(path1);
	}

}