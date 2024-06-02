#include"peashooter.h"
peashooter::peashooter()
{
	b = NULL;

}
peashooter::peashooter(RenderWindow& window, int px, int py, int l, int p, bool a, int c, bool e, float d) :plant(px, py, l, p, a)
{

	t.loadFromFile("Images/peashooter.png");
	s.setTexture(t);
	s.setPosition(px, py);
	//+++++++++++
	setcherry(false);
	setnut(false);
	bullettext.loadFromFile("Images/pea.png");
	bulletsp.setTexture(bullettext);
	b = new bullet(bulletsp, bullettext, px, py, c, e, d, window, 7);

}
void peashooter::draw(RenderWindow& window)
{
	if (getlife() > 0)//////////
	{
		window.draw(s);
	}
	else if (getlife() <= 0)
	{
		setalive(false);
	}
}
peashooter::~peashooter()
{
	delete b;
}