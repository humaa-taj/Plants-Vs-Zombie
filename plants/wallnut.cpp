#include"wallnut.h"
wallnut::wallnut()
{
	wall_speed = 0;
	wall_time = 0.2f;
	frame = 0;
	b = NULL;
}

void wallnut::setspeed(int s)
{

	wall_speed = s;

}
float wallnut::getspeed()
{
	return wall_speed;
}
wallnut::wallnut(int px, int py, float s, int l, int p, bool a) :plant(px, py, l, p, a)
{

	wall_time = 0.2f;
	wall_speed = s;
	frame = 0;
	setmove(true);
	//+++++++++++
	setcherry(false);
	setnut(true);
	for (int i = 0; i < 4; i++)
	{
		path = "Images/wallnut" + std::to_string(i + 1) + ".png";
		wal[i].loadFromFile(path);
	}
	wall.setTexture(wal[0]);
	wall.setPosition(px, py);
	b = NULL;

}

void wallnut::draw(RenderWindow& w)
{
	w.draw(wall);
}


void wallnut::rolling()
{
	if (nutclock.getElapsedTime().asSeconds() >= wall_time)
	{
		frame = (frame + 1) % 4;       //changes frame by incrementing one and then mod with 4 to ensure the cycle starts again
		//nut = wal[frame];
		wall.setTexture(wal[frame]);
		nutclock.restart();
	}
}
void wallnut::diagnal_down(RenderWindow& w)
{
	rolling();
	setpx((getpx()) + wall_speed);
	setpy((getpy()) + wall_speed);
	wall.setPosition(getpx(), getpy());
	draw(w);
}
void wallnut::diagnal_up(RenderWindow& w)
{
	rolling();
	setpx((getpx()) + wall_speed);
	setpy((getpy()) - wall_speed);
	wall.setPosition(getpx(), getpy());
	draw(w);
}
void wallnut::moveup(RenderWindow& w)
{
	rolling();
	setpx((getpx()) + wall_speed);
	wall.setPosition(getpx(), getpy());
	draw(w);
}

