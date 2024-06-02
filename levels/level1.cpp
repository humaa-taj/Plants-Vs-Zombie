
#include"level1.h"



level1::level1(RenderWindow& window, int level) :level(window, level)
{
	setlevel(1);
}
void level1::startgame(RenderWindow& window, Event event)
{


	//carzombie(window);

	font.loadFromFile("font.ttf");
	//string n = to_string(getsuns() + indsun);

	returned = getsuns() + indsun;
	string n = to_string(returned);

	textt.setString(n);
	textt.setFont(font);
	textt.setCharacterSize(30);
	textt.setFillColor(Color::Black);
	textt.setPosition(10, 55);
	pf.draw(window, 1);
	pf.handleinput(event, window, 1, gri.gr, indsun, getsuns());


	s.movement();
	if (s.handleinput(window))
	{

		indsun += 100;
	}
	s.draw(window);
	zf.waves(window, 1);
	plantzombie(window);
	for (int i = 0; i < 5; i++)
	{
		c[i].movecar();
		c[i].draw(window);
	}

	carzombie(window);
	zombie_bullet_collision(window);
	setsuns();
	changelevel();
	window.draw(textt);

}



