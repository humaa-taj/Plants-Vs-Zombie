#include <SFML/Graphics.hpp>
#include"flying.h"
using namespace std;
using namespace sf;


flying::flying() {

}
flying::flying(float l, double s, int x, int y) :Zombie(l, s, x, y) {

	frame = 0;
	set_time = 0.5f;
	for (int i = 0; i < 3; i++)
	{
		path = "Images/baloon" + std::to_string(i + 1) + ".png";
		fly[i].loadFromFile(path);

	}
	name = "flying";
	deathcounter = 50;
}

void flying::drawsprite(RenderWindow& w) {

	w.draw(flew);
}

void flying::initial(float l, double s, int x, int y) {
	setlife(l);
	setspeed(s);
	setx(x);
	sety(y);
	set_time = 0.5f;
	frame = 0;
	for (int i = 0; i < 3; i++)
	{
		path = "Images/baloon" + std::to_string(i + 1) + ".png";
		fly[i].loadFromFile(path);

	}
}

void flying::movement(RenderWindow& w) {
	//setlife(getlife()-1);
	if (getlife() <= 0) {
		dead(w);
	}
	else {
		if (getlife() > 0 && !geteating())
		{
			if (time.getElapsedTime().asSeconds() >= set_time) {
				frame = (frame + 1) % 3;
				flew.setTexture(fly[frame]);
				time.restart();
			}
			setx((getx()) - getspeed());
			flew.setPosition(getx(), gety());
			drawsprite(w);
		}
	}


}
void flying::eating(RenderWindow& w)
{

}
bool flying::dead(RenderWindow& w)
{

	deathcounter--;
	flydead.loadFromFile("Images/boom3.png");
	flew.setTexture(flydead);
	if (deathcounter > 0)
	{
		flew.setPosition(getx(), gety());
		drawsprite(w);
	}


	if (deathcounter<=0)
	{

		flew.setPosition(-900, -900);
		drawsprite(w);
	}
	return true;
}
void flying::summon()
{

}