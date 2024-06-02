#include"p_options.h"

p_options::p_options()
{
	t.loadFromFile("Images/options.png");
	s.setTexture(t);
	s.setPosition(0, 0);

	pst.loadFromFile("Images/peacard.png");
	pss.setTexture(pst);
	pss.setPosition(0 + 66, -5);

	sft.loadFromFile("Images/sunflowercard.png");
	sfs.setTexture(sft);
	sfs.setPosition(0 + 66 + 66, -5);

	ct.loadFromFile("Images/cherrycard.png");
	cs.setTexture(ct);
	cs.setPosition(0 + 66 + 66 + 66, -5);

	wt.loadFromFile("Images/card_wallnut.png");
	ws.setTexture(wt);
	ws.setPosition(0 + 66 + 66 + 66 + 66, -5);

	rt.loadFromFile("Images/repeatercard.png");
	rs.setTexture(rt);
	rs.setPosition(0 + 66 + 66 + 66 + 66, -5);

	spt.loadFromFile("Images/snowcard.png");
	sps.setTexture(spt);
	sps.setPosition(0 + 66 + 66 + 66 + 66 + 66, -5);

	isdragging = false;
	ispeadragging = false;

}
void p_options::handleinput(Event event, RenderWindow& window)
{


	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			if (pss.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isdragging = true;
				offset = pss.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
			}
			else if (sfs.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				ispeadragging = true;
				peaoffset = sfs.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
			}
		}
	}
	else if (event.type == Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			isdragging = false;
			ispeadragging = false;
		}
	}


	if (isdragging)
	{
		pss.setPosition(static_cast<float>(Mouse::getPosition(window).x) + offset.x, static_cast<float>(Mouse::getPosition(window).y) + offset.y);
	}

	if (ispeadragging)
	{
		sfs.setPosition(static_cast<float>(Mouse::getPosition(window).x) + peaoffset.x, static_cast<float>(Mouse::getPosition(window).y) + peaoffset.y);
	}
}
void  p_options::draw(RenderWindow& window, int level)
{
    
	window.draw(s);
	window.draw(pss);
	window.draw(sfs);
	window.draw(cs);
	window.draw(ws);
	window.draw(rs);
	window.draw(sps);
	


}
