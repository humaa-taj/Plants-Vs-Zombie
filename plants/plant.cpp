#include"plant.h"
#include"iostream"
using namespace std;
plant::plant()
{

	positionx = 0;
	positiony = 0;
	life = 50;///////////////
	price = 0;
	moving = true;

}
void plant::setpx(int px)
{
	positionx = px;
}
void plant::setpy(int py)
{
	positiony = py;
}
void plant::setlife(int l)
{
	life = l;
}
void plant::setprice(int p)
{
	price = p;
}
plant::plant(int px, int py, int l, int p, bool a)
{
	positionx = px;
	positiony = py;
	life = l;
	price = p;
	alive = a;
	moving = true;
	b = NULL;
}
int plant::getpx()
{
	return positionx;
}
int plant::getpy()
{
	return positiony;
}
int plant::getlife()
{
	return life;
}
int plant::getprice()
{
	return price;
}
void plant::setalive(bool b)
{
	alive = b;
}
bool  plant::getalive()
{
	return alive;
}

void plant::startdeath()/////////////////
{

	life--;
}
//++++++++++++++++++++++++++++++++
bool  plant::getcherry()
{
	return ischerry;
}
void plant::setcherry(bool b)
{
	ischerry = b;
}
bool  plant::getnut()
{
	return iswallnut;
}
void plant::setnut(bool b)
{
	iswallnut = b;
}

bool  plant::getmove()
{
	return moving;
}
void plant::setmove(bool a)
{
	moving = a;
}
