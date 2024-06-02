#include <SFML/Graphics.hpp>
#include"zombiefactory.h"
#include<ctime>
#include<iostream>
using namespace std;
using namespace sf;
zombiefactory::zombiefactory(int l)
{
	interval1 = 500;
	interval2 = 300;
	interval3 = 100;
	//srand(time(0));
	//x_range = 940;
	//y_range = 80;

	switch (l)
	{
	case 1:   z = new Zombie * [13];
		z[0] = new simplezoombie(20, 1, 1180, 65);
		z[1] = new simplezoombie(20, 1, 1180, 65);
		z[2] = new simplezoombie(20, 1, 1180, 261);
		z[3] = new simplezoombie(20, 1, 1180, 359);
		z[4] = new simplezoombie(20, 1, 1180, 457);
		z[5] = new simplezoombie(20, 1, 1180, 65);
		z[6] = new simplezoombie(20, 1, 1180, 163);
		z[7] = new simplezoombie(20, 1, 1180, 65);
		z[8] = new simplezoombie(20, 1, 1180, 457);
		z[9] = new simplezoombie(20, 1, 1180, 359);
		z[10] = new simplezoombie(20, 1, 1180, 163);
		z[11] = new simplezoombie(20, 1, 1180, 261);
		z[12] = new simplezoombie(20, 1, 1180, 457);
		break;
	case 2:   z = new Zombie * [13];

		z[6] = new simplezoombie(20, 1, 1180, 65);
		z[9] = new simplezoombie(20, 1, 1180, 163);
		z[2] = new flying(100, 1, 1180, 65);
		z[3] = new dancing(40, 1, 1180, 261);
		z[4] = new simplezoombie(20, 1, 1180, 359);
		z[5] = new flying(100, 1, 1180, 163);
		z[11] = new footballzombie(30, 1, 1180, 261);
		z[7] = new dancing(40, 1, 1180, 163);
		z[8] = new simplezoombie(20, 1, 1180, 261);
		z[1] = new footballzombie(30, 1, 1180, 359);
		z[10] = new flying(100, 1, 1180, 65);
		z[0] = new dancing(40, 1, 1180, 359);
		z[12] = new footballzombie(20, 1, 1180, 65);


		break;
	case 3:   z = new Zombie * [13];

		z[5] = new simplezoombie(20, 1, 1180, 65);
		z[1] = new simplezoombie(20, 1, 1180, 163);
		z[2] = new flying(100, 1, 1180, 65);
		z[3] = new dancing(40, 1, 1180, 261);
		z[4] = new simplezoombie(20, 1, 1180, 359);
		z[0] = new flying(100, 1, 1180, 163);
		z[6] = new footballzombie(30, 1, 1180, 261);
		z[7] = new dancing(40, 1, 1180, 163);
		z[8] = new footballzombie(20, 1, 1180, 261);
		z[9] = new simplezoombie(20, 1, 1180, 359);
		z[10] = new flying(100, 1, 1180, 65);
		z[11] = new dancing(40, 1, 1180, 359);
		z[12] = new flying(20, 1, 1180, 65);

		break;

	}

}

void zombiefactory::setlevel(int l)
{
	levelnum = l;
}

int zombiefactory::getlevel()
{
	return levelnum;
}

void zombiefactory::waves(RenderWindow& w, int levelno)
{
	setI1(getI1() - 1);
	if (z[0]->getlife() >= 0)
	{
		z[0]->eating(w);
		z[0]->movement(w);
	}
	if (getI1() < 0)
	{

		if (z[1]->getlife() >= 0)
		{
			z[1]->eating(w);
			z[1]->movement(w);
		}

	}
	if (getI1() < -500)
	{
		if (z[2]->getlife() >= 0)
		{
			z[2]->eating(w);
			z[2]->movement(w);
		}
	}

	if (getI1() < -750)
	{
		setI2(getI2() - 1);
		if (z[3]->getlife() >= 0)
		{
			z[3]->eating(w);
			z[3]->movement(w);
		}
		if (getI2() < 0)
		{
			if (z[4]->getlife() >= 0)
			{
				z[4]->eating(w);
				z[4]->movement(w);
			}
		}
		if (getI2() < -300)
		{
			if (z[5]->getlife() >= 0)
			{
				z[5]->eating(w);
				z[5]->movement(w);
			}
		}
		if (getI2() < -600)
		{
			if (z[6]->getlife() >= 0)
			{
				z[6]->eating(w);
				z[6]->movement(w);
			}

		}
		if (getI2() < -900)
		{
			if (z[7]->getlife() >= 0)
			{
				z[7]->eating(w);
				z[7]->movement(w);
			}

		}

	}
	if (getI2() < -1050)
	{
		setI3(getI3() - 1);
		if (z[8]->getlife() >= 0)
		{
			z[8]->eating(w);
			z[8]->movement(w);
		}
		if (getI3() < 0)
		{
			if (z[9]->getlife() >= 0)
			{
				z[8]->eating(w);
				z[9]->movement(w);
			}

		}
		if (getI3() < -100)
		{
			if (z[10]->getlife() >= 0)
			{
				z[10]->eating(w);
				z[10]->movement(w);
			}

		}
		if (getI3() < -200)
		{
			if (z[11]->getlife() >= 0)
			{
				z[11]->eating(w);
				z[11]->movement(w);
			}

		}
		if (getI3() < -300)
		{
			if (z[12]->getlife() >= 0)
			{
				z[12]->eating(w);
				z[12]->movement(w);
			}

		}

	}



}

int zombiefactory::getI1() {
	return interval1;
}
int zombiefactory::getI2() {
	return interval2;
}
int zombiefactory::getI3() {
	return interval3;
}
void zombiefactory::setI1(int i) {
	interval1 = i;
}
void zombiefactory::setI2(int i) {
	interval2 = i;
}
void zombiefactory::setI3(int i) {
	interval3 = i;
}

zombiefactory::~zombiefactory()
{
	for (int i = 0; i < 13; i++)
	{
		delete z[i];
	}
	delete[] z;
}
void zombiefactory::RemoveZombie(int i) {
	z[i] = nullptr;
}