#pragma once
#include"level.h"

class level3: public level
{
public:
	level3(RenderWindow& window, int level);
	void startgame(RenderWindow& window, Event event);
	
};
