#include"snowpea.h"
snowpea::snowpea()
{
	b = NULL;

}
snowpea::snowpea(RenderWindow& window, int px, int py, int l, int p, bool a, int c, bool e, float d) :plant(px, py, l, p, a)
{
	t.loadFromFile("Images/snow.png");
	s.setTexture(t);
	s.setPosition(px, py);
	//+++++++++++
	setcherry(false);
	setnut(false);
	bullettext.loadFromFile("Images/spea.png");
	bulletsp.setTexture(bullettext);
	b = new bullet(bulletsp, bullettext, px, py, c, e, d, window, 9);

}
void snowpea::draw(RenderWindow& window)
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
snowpea::~snowpea()
{
	delete b;
}