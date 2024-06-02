
#include <SFML/Graphics.hpp>
#include"dancing.h"
#include<iostream>

using namespace std;
using namespace sf;

dancing::dancing() 
{


}

dancing::dancing(float l, double s, int x, int y) :Zombie(l, s, x, y)
{
	frame1 = 0;
	interval = 0.5f;
	for (int i = 0; i < 4; i++)
	{
		path = "Images/dance" + std::to_string(i + 1) + ".png";
		D[i].loadFromFile(path);
		path1 = "Images/disco" + std::to_string(i + 1) + ".png";
		eatdisc[i].loadFromFile(path1);
	}
	sum = false;
	deathcounter = 30;
	name = "dancing";
	for (int i = 0; i < 4; i++)
	{
		pt[i] = NULL;
	}

}

void dancing::drawsprite(RenderWindow& w) {

	//w.draw(dance);



}
void dancing::summon()
{

	
	pt[0] = new partner(6, getspeed(), getx() + 80, gety());
	pt[1] = new partner(6, getspeed(), getx() - 80, gety());
	pt[2] = new partner(6, getspeed(), getx(), gety() + 98);
	pt[3] = new partner(6, getspeed(), getx(), gety() - 98);

}

void dancing::initial(float l, double s, int x, int y) {
	setlife(l);
	setspeed(s);
	setx(x);
	sety(y);
	interval = 0.5f;
	for (int i = 0; i < 4; i++)
	{
		path = "Images/dance" + std::to_string(i + 1) + ".png";
		D[i].loadFromFile(path);
		path1 = "Images/disco" + std::to_string(i + 1) + ".png";
		eatdisc[i].loadFromFile(path1);
	}
	sum = false;
}

void dancing::movement(RenderWindow& w)
{

	if (getlife() > 0)
	{
		
		if (getx() > 940 && getlife() > 0)
		{
			if (clk1.getElapsedTime().asSeconds() >= interval)
			{
				frame1 = (frame1 + 1) % 4;
				dance.setTexture(D[frame1]);

				clk1.restart();
			}
			setx((getx()) - getspeed());
			dance.setPosition(getx(), gety());
			w.draw(dance);

		}
		else if (getx() <= 940 && getlife() > 0)
		{
			if (!sum)
			{
				
				summon();
				sum = true;
			}
			if (!geteating() && !pt[0]->geteating() && !pt[1]->geteating() && !pt[2]->geteating() && !pt[3]->geteating())
			{
				if (clk1.getElapsedTime().asSeconds() >= interval)
				{
					frame1 = (frame1 + 1) % 4;
					dance.setTexture(D[frame1]);

					clk1.restart();
				}
				setx((getx()) - getspeed());
				/*if (gety() >= 163)
				{
					sety(gety() - getspeed());
				}*/
				dance.setPosition(getx(), gety());
				w.draw(dance);

				if (sum)
				{
					if (getback())
					{
						pt[0]->movement(w);

					}
					if (getup())
					{
						pt[3]->movement(w);
					}
					if (getdown())
					{
						pt[2]->movement(w);
					}
					if (getfront())
					{
						pt[1]->movement(w);
					}
				}
			}
			else
			{
				eating(w);
				for (int i = 0; i < 4; i++)
				{
					if(pt[i]->getlife()>0)
					{
						pt[i]->eating(w);
					}
				}
			}


		}
	}
	else if (getlife() <= 0)
	{
		setx((getx()) - getspeed());
		/*if (gety() >= 163)
		{
			sety(gety() - getspeed());
		}*/
		dead(w);
		if (getback() && pt[0] != NULL)
		{
			pt[0]->movement(w);
			
		}
		if (getup() && pt[3] != NULL)
		{
			pt[3]->movement(w);
			
		}
		if (getdown() && pt[2] != NULL)
		{
			pt[2]->movement(w);
			
		}
		if (getfront() && pt[1] != NULL)
		{
			pt[1]->movement(w);
			
		}
	}



}

void dancing::eating(RenderWindow& w)
{
	if (getlife() > 0 && geteating())
	{
		
		//cout << "dancing" << endl;
		if (clk1.getElapsedTime().asSeconds() >= interval)
		{
			frame1 = (frame1 + 1) % 4;
			dance.setTexture(eatdisc[frame1]);
			clk1.restart();

		}
		dance.setPosition(getx(), gety());
		w.draw(dance);
		/*for (int i = 0; i < 4; i++)
		{

			pt[i]->eating(w);
			pt[i]->drawsprite(w);

		}*/

	}

}

bool dancing::dead(RenderWindow& w)
{

	if (getkiller())
	{
		deathcounter--;
		deadisc.loadFromFile("Images/boom3.png");
		dance.setTexture(deadisc);

		if (deathcounter<=0)
		{

			dance.setPosition(-900, -900);
			w.draw(dance);
		}
		else
		{

			dance.setPosition(getx(), gety());
			w.draw(dance);
		}
	}
	else
	{
		deathcounter--;
		deadisc.loadFromFile("Images/disc.png");
		
		if (deathcounter <= 0)
		{
			s.setPosition(-900, -900);
			w.draw(s);
		}
		else
		{
			s.setTexture(deadisc);
			s.setPosition(getx(), gety());
			w.draw(s);
		}
	}

	return true;
}
void dancing::checkpartner(RenderWindow& w, int i)
{
	/*if (getx() <= 940)
	{*/
		if (getback() && i == 2 && pt[0] != NULL)
		{
            
			pt[0]->setlife(0);
			pt[0]->dead(w);
			setback(false);

		}
		if (getfront() && i == 1 && pt[1] != NULL)
		{
			pt[1]->setlife(0);
			pt[1]->dead(w);
			setfront(false);
		}
		if (getdown() && i == 4 && pt[2] != NULL)
		{

			pt[2]->setlife(0);
			pt[2]->dead(w);
			setdown(false);
		}
		if (getup() && i == 3 && pt[3] != NULL)
		{

			pt[3]->setlife(0);
			pt[3]->dead(w);
			setup(false);
		}

	//}
}

dancing::~dancing()
{
	for (int i = 0; i < 4; i++) {
		delete pt[i];
	}
	delete[]pt;
}