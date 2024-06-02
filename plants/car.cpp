#include"car.h"
#include"iostream"
using namespace std;
car::car()
{
	mover.loadFromFile("Images/lawnmover.png");
	lawn.setTexture(mover);
	exist = true;
	moving = false;
	px = 220;
	//py = y;

}

car::car(RenderWindow& w, int level)
{
	//x = 0, y = 1, exist = 2; px = 220; py = 100;
	mover.loadFromFile("Images/lawnmover.png");
	lawn.setTexture(mover);
	exist = true;
	moving = false;
	/*if (level == 1)
	{
		size = 1;
	}
	else if (level == 2)
	{
		size = 3;
	}
	else if (level == 3)
	{
		size = 5;
	}

	gari = new float* [size];
	for (int i = 0; i < size; i++)
	{

		gari[i] = new float[3];
		gari[i][x] = px;
		gari[i][y] = py;
		gari[i][exist] = true;
		py += 103;

	}
	*/



}
void car::setcar(int y)
{

	mover.loadFromFile("Images/lawnmover.png");
	lawn.setTexture(mover);
	exist = true;
	moving = false;
	px = 220;
	py = y;
	lawn.setPosition(px, py);
	/*x = 0, y = 1, exist = 2; px = 220; py = 80;
	mover.loadFromFile("Images/lawnmover.png");
	lawn.setTexture(mover);
	if (level == 1)
	{
		size = 1;
	}
	else if (level == 2)
	{
		size = 3;
	}
	else if (level == 3)
	{
		size = 5;
	}
	gari[size][3];
	for (int i = 0; i < size; i++)
	{

		gari[i][x] = px;
		gari[i][y] = py;
		gari[i][exist] = true;
		py += 98;
		lawn.setPosition(gari[i][0], gari[i][1]);

	}*/




}

void car::movecar()
{

	if (moving)
	{

		px += 6;
		lawn.setPosition(px, py);
		if (px > 940)
		{
			moving = false;
		}
		if (px > 220)

		{
			exist = false;
		}
	}
	


}

bool car::getmoving()
{
	return moving;
}
void car::setmoving(bool b)
{
	moving = b;
}
void car::draw(RenderWindow& w)
{

	if (px < 940)
	{
		w.draw(lawn);
	}

}
bool car::gete()
{
	return exist;
}


//car::~car()
//{
//	
//	// Deallocate memory for the 2D array
//	for (int i = 0; i < size ; i++)
//	{
//		
//		delete gari[i];
//	}
//	delete[] gari;
//}