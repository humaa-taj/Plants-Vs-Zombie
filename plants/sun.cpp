#include "sun.h"
#include<ctime>
#include"iostream"
using namespace std;

sun::sun(int fs, int px, int py, int coll)////////////
{

	positionx = px;
	positiony = py;
	if (!t.loadFromFile("Images/sun.png"))
	{
		cout << "image not loaded" << endl;
	}
	s.setTexture(t);
	s.setPosition(px, py);
	fallingspeed = fs;
	collected = coll;
	spawnedFromSunflower = false;
	sfalive = false;
	salive = true;
}
void sun::setsprite()
{

}
void sun::settexture()
{

}
void sun::selected(int coin)
{

}
void sun::set(int x, int y, bool fromSunflower)
{
	positionx = x;
	positiony = y;
	s.setPosition(x, y);
	sfalive = true;
	spawnedFromSunflower = fromSunflower;
	if (spawnedFromSunflower)
	{

		despawnClock.restart();
	}
}
void sun::draw(RenderWindow& window)
{
	if (sfalive && spawnedFromSunflower)
	{
		window.draw(s);
		//movement();


		if (despawnClock.getElapsedTime().asSeconds() >= 10)
		{

			sfalive = false; // Set alive to false to make it vanish
			despawnClock.restart(); // Restart the clock for the next appearance
		}
	}
	if (salive && !spawnedFromSunflower)
	{

		window.draw(s);
		//movement();
	}

}
void sun::movement()
{
	if (salive && !spawnedFromSunflower)
	{
		positiony += fallingspeed;
		s.setPosition(positionx, positiony);
		if (positiony > 600)
		{
			updatesun();

		}
	}
}
void sun::updatesun()
{
	positionx = rand() % 860 + 220;
	positiony = -600 * 2.5;
	s.setPosition(positionx, positiony);
}

int  sun::getx() { return positionx; }
int  sun::gety() { return positiony; }


bool sun::handleinput(RenderWindow& window) //////////////
{

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		int mouseX = Mouse::getPosition(window).x;
		int mouseY = Mouse::getPosition(window).y;

		if (s.getGlobalBounds().contains(static_cast<float>(mouseX), static_cast<float>(mouseY)))
		{


			despawnClock.restart();///////
			updatesun();
			collected += 100;
			sfalive = false;
			return true;////////////

		}
		return false;
	}
}
void sun::setalive(bool a)
{
	sfalive = a;
}
bool sun::getalive()
{
	return sfalive;
}

void  sun::setcollected(int c)
{
	collected = c;
}
int   sun::getcollected()
{

	return collected;
}