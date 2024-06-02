#include"cherry.h"
cherry::cherry()
{

}
cherry::cherry(int px, int py, int l, int p, bool a) :plant(px, py, l, p, a)
{

	t.loadFromFile("Images/cherry.png");
	s.setTexture(t);
	s.setPosition(px, py);
	b = NULL;
	//+++++++++++
	setcherry(true);
	setnut(false);
}

void cherry::draw(RenderWindow& w)
{
	w.draw(s);
}

void cherry::updatecherry(RenderWindow& w)
{
	setlife((getlife()) - 1);
	if (getlife() <= 0 && getlife() > -100)
	{
		t.loadFromFile("Images/explode.png");
		s.setTexture(t);
		s.setScale(2.5, 2.5);
		s.setPosition(getpx() - 80, getpy() - 80);
		w.draw(s);

	}
	if (getlife() <= -100)
	{
		s.setPosition(-900, -900);
		setpx(-900);
		setpy(-900);
	}

}

