#include"repeater.h"
repeater::repeater()
{
	b = NULL;

}
repeater::repeater(RenderWindow& window, int px, int py, int l, int p, bool a, int c, bool e, float d) :plant(px, py, l, p, a)
{

	t.loadFromFile("Images/repeater.png");
	s.setTexture(t);
	s.setPosition(px, py);
	//+++++++++++
	setcherry(false);
	setnut(false);
	bullettext.loadFromFile("Images/pear.png");
	bulletsp.setTexture(bullettext);
	b = new bullet(bulletsp, bullettext, px, py, c, e, d, window, 9);


}
void repeater::draw(RenderWindow& window)
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
repeater::~repeater()
{
	delete b;
}