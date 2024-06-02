#include"bullet.h"
#include<iostream>
using namespace std;
bullet::bullet()
{
	positionx = 0;
	positiony = 0;
	cooldown = 0;
	exist = true;
	damage = 0;
	speed = 0;
	temp = 0;
	generate = 250;

}
void bullet::setpx(int px)
{
	positionx = px;
}
void bullet::setpy(int py)
{
	positiony = py;
}
void bullet::setcool(int c)
{
	cooldown = c;
}
void bullet::setexist(bool b)
{
	exist = b;
	if (!exist)
	{
		generate = 250;
	}
}
void bullet::setdamage(int b)
{
	damage = b;
}
bullet::bullet(Sprite& s, Texture& t, int px, int py, int c, bool b, int d, RenderWindow& window, int ss)
{

	bs = s;
	bt = t;
	speed = ss;
	positionx = px;
	positiony = py;
	//bs.setPosition(px, py);
	cooldown = c;
	exist = b;
	damage = d;
	temp = px;
	generate = 250;
	tempy = py;
	drawb = true;
}
void bullet::setbullet(Sprite& s, Texture& t, int px, int py, int c, bool b, int d, RenderWindow& window, int ss)
{

	bs = s;
	bt = t;
	speed = ss;
	positionx = px;
	positiony = py;
	bs.setPosition(px, py);
	//cout << "bullet " << px << py << endl;
	cooldown = c;
	exist = false;
	damage = d;
	temp = px;

}
void bullet::draw(RenderWindow& window)
{
	if (drawb == true)
	{
		window.draw(bs);
	}
}
int bullet::getpx()
{
	return positionx;
}
int bullet::getpy()
{
	return positiony;
}
int bullet::getcool()
{
	return cooldown;
}
int bullet::getdamage()
{
	return damage;
}
bool bullet::getexist()
{
	return exist;
}
void bullet::movebullet()
{
	if (temp < 940 && exist == true)
	{
		temp += speed;
		bs.setPosition(temp, positiony);

	}
	else if (temp >= 940 || exist == false)
	{
		
		temp = -7;
		bs.setPosition(7, -7);

		positiony = -7;
		exist = false;
		drawb = false;
		generate--;

		if (generate == 0)
		{
			temp = positionx;
			positiony = tempy;
			bs.setPosition(positionx, positiony);
			exist = true;
			drawb = true;
			generate = 250;
		}
	}



}

