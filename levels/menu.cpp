#include"menu.h"
#include<iostream>
using namespace std;
//include audios 
menu::menu() : text("", font, 30)//////
{

	font.loadFromFile("font.ttf");

	men = true;
	ins = false;
	profile = false;
	iS = "";

}


void menu::display(RenderWindow& window, Event event)
{
	if (men == true && ins == false && profile == false)
	{

		bgt.loadFromFile("Images/wll.jpg");
		bgs.setTexture(bgt);
		bgs.setPosition(0, 0);

		playt.loadFromFile("Images/play.png");
		plays.setTexture(playt);
		plays.setPosition(450, 400);
		plays.setScale(1, 1);

		inst.loadFromFile("Images/insb.png");
		inssp.setTexture(inst);
		inssp.setPosition(450, 250);

		prot.loadFromFile("Images/PROFILE.png");
		pros.setTexture(prot);
		pros.setPosition(450, 100);


		window.draw(bgs);
		window.draw(plays);
		window.draw(pros);
		window.draw(inssp);


	}
	else if (men == false && ins == false && profile == true)
	{

		bgt.loadFromFile("Images/menu.jpg");
		bgs.setTexture(bgt);
		bgs.setPosition(0, 0);
		playt.loadFromFile("Images/tick.png");
		plays.setTexture(playt);
		plays.setPosition(0, 440);
		plays.setScale(0.5f, 0.5f);
		Text textt("Enter Name:", font, 60);
		textt.setFillColor(Color::White);
		textt.setPosition(800, 100);



		text.setFillColor(Color::White);
		text.setPosition(800, 200);

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == Event::TextEntered)
		{
			if (event.text.unicode < 128)
			{
				if (event.text.unicode == '\b' && !iS.empty())
				{
					iS.pop_back();
				}
				else if (event.text.unicode != '\b')
				{
					iS += (char)(event.text.unicode);
				}

				text.setString(iS);

			}

		}

		window.draw(bgs);
		window.draw(textt);
		window.draw(text);
		window.draw(plays);
	}
	else if (ins == true && men == false && profile == false)
	{
		bgt.loadFromFile("Images/ins.jpg");
		bgs.setTexture(bgt);
		bgs.setPosition(0, 0);
		playt.loadFromFile("Images/tick.png");
		plays.setTexture(playt);
		plays.setPosition(1000, 440);
		plays.setScale(0.5f, 0.5f);

		Text text("     Hey  Player!\n"  " Strategically plant defensive plants in your\n"" garden to fend off waves of incoming zombies. \n"
			"Choose your plants wisely, considering factors\n like sunlight availability and zombie attack\n patterns. Manage resources effectively and use\n special plant abilities to survive increasingly\n challenging levels. Earn upgrades to enhance\n your defenses and protect your home\n from the zombie invasion. ", font, 25);
		text.setFillColor(Color::White);
		text.setPosition(430, 160);

		window.draw(bgs);
		window.draw(text);
		window.draw(plays);

	}

}
bool menu::handleInput(RenderWindow& window, Event event)
{



	if (event.type == Event::MouseButtonPressed)
	{
		int mouseX = event.mouseButton.x;
		int mouseY = event.mouseButton.y;


		if (mouseX >= 450 && mouseX <= 800 &&
			mouseY >= 350 && mouseY <= 450 && men == true && ins == false && profile == false)
		{

			men = false;
			ins = true;
			profile = false;
			return false;
		}
		if (mouseX >= 450 && mouseX <= 800 &&
			mouseY >= 500 && mouseY <= 600 && men == true && ins == false && profile == false)
		{
			return true;
		}
		if (mouseX >= 450 && mouseX <= 800 &&
			mouseY >= 200 && mouseY <= 300 && men == true && ins == false && profile == false)
		{

			men = false;
			ins = false;
			profile = true;
			return false;
		}
		else if (mouseX >= 1000 && mouseX <= 1180 &&
			mouseY >= 400 && mouseY <= 580 && men == false && ins == true && profile == false)
		{


			men = true;
			ins = false;
			profile = false;
			return false;

		}
		else if (mouseX >= 0 && mouseX <= 180 &&
			mouseY >= 400 && mouseY <= 580 && men == false && ins == false && profile == true)

		{

			profile = false;
			ins = false;
			men = true;
			return false;

		}
	}
	return false;



}