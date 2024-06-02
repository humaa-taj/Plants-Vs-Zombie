
#include <SFML/Graphics.hpp>
#include"zombie.h"
//#include<iostream>
using namespace std;
using namespace sf;

Zombie::Zombie()
{
	life = 0;
	speed = 0;
	x_pos = 0;   
	y_pos = 0;  
	cherrykiller = false;
	eat = false;
	zombiealive = true;
	front = true;
	back = true;
	up = true;
	down = true;
	name = "";

	
}

Zombie::Zombie(float l, double s, int x, int y) {
	life = l;
	speed = s;
	x_pos = x;
	y_pos = y;
	cherrykiller = false;
	eat = false;
	front = true;
	back = true;
	up = true;
	down = true;
	name = "";
	zombiealive = true;
}

void Zombie::setlife(float l)
{
	life = l;
}


void Zombie::setspeed(double s) {
	speed = s;
}

void Zombie::setx(int x) {
	x_pos = x;
}

void Zombie::sety(int y) {
	y_pos = y;
}

int Zombie::getx() {
	return x_pos;
}

int Zombie::gety() {
	return y_pos;
}

float Zombie::getlife() {
	return life;
}

double Zombie::getspeed()
{
	return speed;
}

void Zombie::setkiller(bool a)
{
	cherrykiller = a;
	//cherrykiller = false;
}

bool Zombie::getkiller()
{
	return cherrykiller;
}

bool Zombie::geteating()
{
	return eat;
}

void Zombie::seteating(bool a)/////////////
{
	eat = a;

}
void Zombie::setalive(bool a)/////////////
{
	zombiealive = a;

}
bool Zombie::getalive()/////////////
{
	return zombiealive;

}
void Zombie::setfront(bool r)
{
	front = r;
}
void Zombie::setback(bool r)
{
	back = r;
}
void Zombie::setup(bool r)
{
	up = r;
}
void Zombie::setdown(bool r)
{
	down = r;
}
bool Zombie::getdown() {
	return down;
}
bool   Zombie::getup() {
	return up;
}
bool Zombie::getfront() {
	return front;
}
bool  Zombie::getback() {
	return back;
}